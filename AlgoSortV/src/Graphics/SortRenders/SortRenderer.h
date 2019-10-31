#pragma once
#include "Graphics\VertexBufferLayout.h"
#include "Graphics\VertexBuffer.h"
#include "Graphics\VertexArray.h"
#include "Graphics\Shader.h"
#include "Graphics\Renderer.h"

#include "Sorts\ISort.h"

class SortRenderer
{
public:
	SortRenderer(int * mass, Vec3 * color_markers, unsigned int nElements, int max_value);

	void Draw(const Renderer & renderer);

protected:
	int * mass_;
	Vec3 * color_markers_;
	int max_value_;
	unsigned int nElements_;

	VertexBufferLayout vbl_;
	VertexBuffer vb_;
	VertexArray va_;
	Shader shader_;

};