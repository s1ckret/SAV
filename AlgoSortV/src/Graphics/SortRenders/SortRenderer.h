#pragma once
#include "Graphics\VertexBufferLayout.h"
#include "Graphics\VertexBuffer.h"
#include "Graphics\VertexArray.h"
#include "Graphics\Shader.h"
#include "Graphics\Renderer.h"

#include "Sorts\ISort.h"
#include "Sorts\DataTypes.h"

class SortRenderer
{
public:
	SortRenderer(ArrayInfo& arr_info);

	void Draw(const Renderer & renderer);

protected:
	ArrayInfo& arr_info_;

	VertexBufferLayout vbl_;
	VertexBuffer vb_;
	VertexArray va_;
	Shader shader_;

};