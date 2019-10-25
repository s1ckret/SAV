#include <iostream>

// GLEW
#include "GL/glew.h"

// GLFW
#include "GLFW/glfw3.h"

#include "Log.h"

#include "Graphics\IndexBuffer.h"
#include "Graphics\Renderer.h"
#include "Graphics\Shader.h"
#include "Graphics\VertexArray.h"
#include "Graphics\VertexBuffer.h"
#include "Graphics\VertexBufferLayout.h"

// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;

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


	Shader shader;
	shader.SetFilePath("res/shaders/Basic.shader");

	float positions[] =
	{
		-0.5f, -0.5f,
		 0.5f, -0.5f,
		 0.0f,  0.5f
	};

	VertexBufferLayout vbl;
	vbl.Push<float>(2);
	VertexBuffer vb;
	vb.SetData(positions, 6 * sizeof(float));
	VertexArray va;
	va.AddBuffer(vb, vbl);

	Renderer renderer;
	// Game loop
	while (!glfwWindowShouldClose(window))
	{
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();
		renderer.Clear();
		renderer.Draw(va, shader, 3);
		// Swap the screen buffers
		glfwSwapBuffers(window);
	}

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