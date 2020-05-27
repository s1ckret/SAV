#include "VertexBuffer.h"
#include "Renderer.h"

VertexBuffer::VertexBuffer() :
	m_RendererID(0)
{
}

VertexBuffer::VertexBuffer(const void * data, unsigned int size)
{
	SetData(data, size);
}

VertexBuffer::~VertexBuffer()
{
	GLCall(glDeleteBuffers(1, &m_RendererID));
}

void VertexBuffer::SetData(const void * data, unsigned int size)
{
	GLCall(glGenBuffers(1, &m_RendererID));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
	GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW));
}

void VertexBuffer::UpdateData(const void * data, unsigned int size)
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
	GLCall(glBufferSubData(GL_ARRAY_BUFFER, 0, size, data));
}

void VertexBuffer::ClearData() {
  GLCall(glDeleteBuffers(1, &m_RendererID));
}

void VertexBuffer::Bind() const
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
}

void VertexBuffer::Unbind() const
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}