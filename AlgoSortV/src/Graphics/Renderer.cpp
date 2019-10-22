#include "Renderer.h"

void GLClearErrors()
{
	while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char * function, const char * file, int line)
{
	while (GLenum error = glGetError())
	{
		return false;
	}
	return true;
}

Renderer::Renderer()
{
}

void Renderer::Clear() const
{
	GLCall(glClearColor(0.2f, 0.3f, 0.3f, 1.0f));
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
}


void Renderer::Draw(const VertexArray & va, const Shader & shader, unsigned int vertex_count) const
{
	va.Bind();
	shader.Bind();
	GLCall(glDrawArrays(GL_TRIANGLES, 0, vertex_count));
}
