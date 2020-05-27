#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "imgui/imgui.h"
#include "imgui/examples/imgui_impl_glfw.h"
#include "imgui/examples/imgui_impl_opengl3.h"

#include "Log.h"

#include "DataController/IDataController.h"
#include "DataController/BasicDataController.h"

#include "Graphics/DataRenderer/IDataRenderer.h"
#include "Graphics/DataRenderer/BasicDataRenderer.h"

#include "SortsController/SortsController.h"

#include "Sorts/BubbleSort.h"
#include "Sorts/CountingSort.h"
#include "Sorts/QuickLSort.h"
#include "Sorts/MergeSort.h"

bool dirtyFlag = 1;

int main()
{
	const GLuint WIDTH = 1200, HEIGHT = 800;
	GLFWwindow* window;

	Log::Init();
	LOG_INFO("Starting GLFW context, OpenGL 3.3");

	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	window = glfwCreateWindow(WIDTH, HEIGHT, "SAV", nullptr, nullptr);    
	if (window == nullptr)
	{
		LOG_CRITICAL("Failed to create GLFW window");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval( 1 );
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		LOG_CRITICAL("Failed to initialize GLEW");
		return -1;
	}    

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);  
	GLCall(glViewport(0, -height, width, 2 * height));

	// imgui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");

	int size = 100;

	BasicDataController dataCtrl;
	dataCtrl.Generate(size);

	int delay = 3;
	std::shared_ptr<IDataRenderer> dataRndr =
            std::make_shared<BasicDataRenderer>(&dataCtrl.GetData(), delay);

	SortsController& SortsController = SortsController::Get();

	SortsController.AddSort( std::make_shared<BubbleSort>( dataCtrl.GetData( ), dataRndr ) );
	SortsController.AddSort( std::make_shared<CountingSort>( dataCtrl.GetData( ), dataRndr ) );
	SortsController.AddSort( std::make_shared<QuickLSort>( dataCtrl.GetData( ), dataRndr ) );
	SortsController.AddSort( std::make_shared<MergeSort>( dataCtrl.GetData( ), dataRndr ) );

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		dataRndr->Clear();
		dataRndr->Draw();

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		{
			static int sortChooser = -1;
			ImGui::Begin("Control panel");                          

			if (ImGui::Button("Shuffle Massive") && dirtyFlag)
			{
				dataRndr->Reset();
				dataCtrl.Shuffle();
			}
			if (ImGui::Button("Sort") && dirtyFlag )
			{
				LOG_INFO("Sort started!");
				SortsController.BeginSort();
			}

			ImGui::Text( "Delay:      " ); ImGui::SameLine( );
			ImGui::PushItemWidth( 100 );
			ImGui::InputInt( "  ", &delay );
			ImGui::PopItemWidth( );
			ImGui::SameLine( );
			if ( ImGui::Button( "Set" ) && dirtyFlag ) {
				dataRndr->SetDelay( delay );
				LOG_INFO( "New Delay has set!" );
			}

			ImGui::Text( "Array size: " ); ImGui::SameLine( );
			ImGui::PushItemWidth( 100 );
			ImGui::InputInt( "", &size );
			ImGui::PopItemWidth( );
			ImGui::SameLine( );
			if ( ImGui::Button( "Generate" ) && dirtyFlag ) {
				dataCtrl.Generate( size );
				dataRndr->SetData( &dataCtrl.GetData( ) );
				LOG_INFO( "New Array has generated!" );
			}

			const auto& collection = SortsController.GetSortCollection();
			for (unsigned int i = 0; i < collection.size(); i++)
			{
				if (ImGui::RadioButton(collection[i]->GetName().c_str(), &sortChooser, i) && dirtyFlag )
				{
					SortsController.SetSort(collection[i]);
					LOG_INFO("{0} is choosed!", collection[i]->GetName().c_str());
					break;
				}
			}
			

			ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
			ImGui::End();
		}
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(window);
	}
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwTerminate();
	return 0;
}
