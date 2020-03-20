#include <iostream>

// GLEW
#include "GL/glew.h"

// GLFW
#include "GLFW/glfw3.h"

#include "Log.h"

#include "imgui/imgui.h"
#include "imgui/examples/imgui_impl_glfw.h"
#include "imgui/examples/imgui_impl_opengl3.h"

#include "Graphics/IndexBuffer.h"
#include "Graphics/Renderer.h"
#include "Graphics/Shader.h"
#include "Graphics/VertexArray.h"
#include "Graphics/VertexBuffer.h"
#include "Graphics/VertexBufferLayout.h"

#include "DataController/IDataController.h"
#include "DataController/BasicDataController.h"

#include "Graphics/DataRenderer/IDataRenderer.h"
#include "Graphics/DataRenderer/BasicDataRenderer.h"

#include "SortsController/SortsController.h"

#include "Sorts/BubbleSort.h"

// Window dimensions
const GLuint WIDTH = 1200, HEIGHT = 800;
GLFWwindow* window;
// The MAIN function, from here we start the application and run the game loop
int main()
{
	Log::Init();
	LOG_INFO("Starting GLFW context, OpenGL 3.3");
	// Init GLFW
	glfwInit();
	// Set all the required options for GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	// Create a GLFWwindow object that we can use for GLFW's functions
	window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);    
	if (window == nullptr)
	{
		LOG_CRITICAL("Failed to create GLFW window");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
	glewExperimental = GL_TRUE;
	// Initialize GLEW to setup the OpenGL Function pointers
	if (glewInit() != GLEW_OK)
	{
		LOG_CRITICAL("Failed to initialize GLEW");
		return -1;
	}    

	// Define the viewport dimensions
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);  
	GLCall(glViewport(0, -height, width, 2 * height));
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();

	ImGui::StyleColorsDark();

	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");

	Renderer renderer;	
	
	const unsigned int size = 10000;
	// SortProgram& sortProgram = SortProgram::Get();
	// sortProgram.GenerateMassive(size, 500);

	BasicDataController dataCtrl;
	dataCtrl.Generate(size, 500);
	dataCtrl.Shuffle();

	std::shared_ptr<IDataRenderer> dataRndr = std::make_shared<BasicDataRenderer>();
	dataRndr->SetData(&dataCtrl.GetData());
	dataRndr->SetDelay(1);

	SortsController& SortsController = SortsController::Get();

	SortsController.AddSort(std::make_shared<BubbleSort>(dataCtrl.GetData(), dataRndr));

	// Game loop
	while (!glfwWindowShouldClose(window))
	{
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();
		renderer.Clear();
		//sortProgram.Render(renderer);
		dataRndr->Draw();

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		{
			static int sortChooser = -1;
			ImGui::Begin("Control panel");                          

			if (ImGui::Button("Shuffle Massive"))
			{
				dataCtrl.Shuffle();
			}
			ImGui::SameLine();
			if (ImGui::Button("Sort"))
			{
				LOG_INFO("Sort started!");
				SortsController.BeginSort();
			}

			if (ImGui::TreeNode("Select sort algorithm:"))
			{
				const auto& collection = SortsController.GetSortCollection();
				for (unsigned int i = 0; i < collection.size(); i++)
				{
					if (ImGui::RadioButton(collection[i]->GetName().c_str(), &sortChooser, i))
					{
						SortsController.SetSort(collection[i]);
						LOG_INFO("{0} is choosed!", collection[i]->GetName().c_str());
						break;
					}
				}
				ImGui::TreePop();
			}

			ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
			ImGui::End();
		}
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		// Swap the screen buffers
		glfwSwapBuffers(window);
	}
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	// Terminate GLFW, clearing any resources allocated by GLFW.
	glfwTerminate();
	return 0;
}
