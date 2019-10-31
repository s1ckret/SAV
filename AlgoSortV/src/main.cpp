#include <iostream>

// GLEW
#include "GL/glew.h"

// GLFW
#include "GLFW/glfw3.h"

#include "Log.h"

#include "vendor/imgui/imgui.h"
#include "vendor/imgui/imgui_impl_glfw.h"
#include "vendor/imgui/imgui_impl_opengl3.h"

#include "Graphics\IndexBuffer.h"
#include "Graphics\Renderer.h"
#include "Graphics\Shader.h"
#include "Graphics\VertexArray.h"
#include "Graphics\VertexBuffer.h"
#include "Graphics\VertexBufferLayout.h"

#include "Sorts\SortProgram.h"

// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

// Window dimensions
const GLuint WIDTH = 1200, HEIGHT = 800;

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
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);    
	if (window == nullptr)
	{
		LOG_CRITICAL("Failed to create GLFW window");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	// Set the required callback functions
	glfwSetKeyCallback(window, key_callback);

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
	glViewport(0, 0, width, height);

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();

	ImGui::StyleColorsDark();

	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");

	Shader shader;
	shader.SetFilePath("res/shaders/Basic.shader");

	Renderer renderer;	
	
	const unsigned int size = 200;
	SortProgram& sortProgram = SortProgram::Get();
	sortProgram.GenerateMassive(size, 500);
	sortProgram.SetMethod(SortType::MERGE);

	// Game loop
	while (!glfwWindowShouldClose(window))
	{
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();
		renderer.Clear();
		sortProgram.Render(renderer);


		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		{
			static int sortChooser = INT_MAX;
			ImGui::Begin("Control panel");                          

			if (ImGui::Button("Shuffle Massive"))
			{
				sortProgram.ShuffleMassive();
			}
			ImGui::SameLine();
			if (ImGui::Button("Sort"))
			{
				LOG_INFO("Sort started!");
				sortProgram.Begin();
			}

			if (ImGui::TreeNode("Select sort algorithm:"))
			{
				if (ImGui::RadioButton("Bubble Sort", &sortChooser, 0))
				{
					sortProgram.SetMethod(SortType::BUBBLE);
					LOG_INFO("Bubble sort is choosed!");
				}
				ImGui::SameLine();
				if (ImGui::RadioButton("Merge Sort", &sortChooser, 1))
				{
					sortProgram.SetMethod(SortType::MERGE);
					LOG_INFO("Merge sort is choosed!");
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

// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	std::cout << key << std::endl;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}