#include "SortRenderer.h"

SortRenderer::SortRenderer(ArrayInfo& arr_info)
	: arr_info_(arr_info)
{
	vbl_.Push<float>(1);
	vb_.SetData(arr_info_.arr, arr_info_.nElements * sizeof(int));
	va_.AddBuffer(vb_, vbl_);

	shader_.SetFilePath("res/shaders/Basic.shader");
	shader_.Bind();
	shader_.setUniform1ui("arr_size", arr_info_.nElements);
	shader_.setUniform1i("max_value", arr_info_.max_value);
}

void SortRenderer::Draw(const Renderer & renderer)
{
	vb_.SetNewData(arr_info_.arr, arr_info_.nElements * sizeof(int));
	for (unsigned int i = 0; i < arr_info_.nElements; i++)
	{
		shader_.Bind();
		shader_.setUniform1ui("i", i);
		Vec3 color = arr_info_.markers[i].color_;
		shader_.setUniform3f("u_color_marker", color.x, color.y, color.z);
		renderer.Draw(va_, shader_, i);
	}
}

