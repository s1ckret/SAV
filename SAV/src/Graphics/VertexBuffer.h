#pragma once

class VertexBuffer {
public:
	VertexBuffer();
	VertexBuffer(const void * data, unsigned int size);
	~VertexBuffer();

	void SetData(const void * data, unsigned int size);
	void SetNewData(const void * data, unsigned int size);
	void Bind() const;
	void Unbind() const;

private:
	unsigned int m_RendererID;
};