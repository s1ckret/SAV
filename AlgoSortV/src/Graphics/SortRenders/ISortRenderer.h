#pragma once
#include "Graphics\VertexBufferLayout.h"
#include "Graphics\VertexBuffer.h"
#include "Graphics\VertexArray.h"
#include "Graphics\Shader.h"
#include "Graphics\Renderer.h"

class ISortRenderer
{
public:
	ISortRenderer(int * mass, unsigned int nElements);
	virtual~ISortRenderer() = default;

	virtual void Draw(const Renderer & renderer) = 0;
private:
	int FindMax();

protected:
	int * mass_;
	unsigned int nElements_;

	VertexBufferLayout vbl_;
	VertexBuffer vb_;
	VertexArray va_;
	Shader shader_;

};