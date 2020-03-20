#pragma once

#if _WIN32 || _WIN64
	#define DEBUG_BRK __debugbreak()
#elif __GNUC__
	#include <signal.h>
	#define DEBUG_BRK raise(SIGTRAP)
#else
	#define DEBUG_BRK 
#endif

#define ASSERT(x) if(!(x)) DEBUG_BRK;
#define GLCall(x) GLClearErrors();\
	x;\
	ASSERT(GLLogCall(#x, __FILE__, __LINE__))

#include "Graphics/VertexArray.h"
#include "Graphics/IndexBuffer.h"
#include "Graphics/Shader.h"

#include "GL/glew.h"
#include "GLFW/glfw3.h"

void GLClearErrors();

bool GLLogCall(const char * function, const char * file, int line);

class Renderer
{
public:
	Renderer();

	void Clear() const;

	void Draw(const VertexArray& va, const Shader& shader) const;
	// TODO: Batch renderer
	void Draw(const VertexArray& va, const Shader& shader, unsigned int count) const;
};
