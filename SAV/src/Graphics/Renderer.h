#pragma once

#define ASSERT(x) if(!(x)) __debugbreak();
#define GLCall(x) GLClearErrors();\
	x;\
	ASSERT(GLLogCall(#x, __FILE__, __LINE__))

#include "Graphics\VertexArray.h"
#include "Graphics\IndexBuffer.h"
#include "Graphics\Shader.h"

#include "GL/glew.h"
#include "GLFW/glfw3.h"

void GLClearErrors();

bool GLLogCall(const char * function, const char * file, int line);

class Renderer
{
public:
	Renderer();

	void Clear() const;

	void Draw(const VertexArray& va, const Shader& shader, unsigned int vertex_count) const;
};
