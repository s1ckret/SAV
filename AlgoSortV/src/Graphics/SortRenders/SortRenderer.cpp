#include "SortRenderer.h"

SortRenderer::SortRenderer(int * mass, Vec3 * color_markers, unsigned int nElements, int max_value)
	: mass_(mass),
	color_markers_(color_markers),
	nElements_(nElements),
	max_value_(max_value)
{
	vbl_.Push<float>(1);
	vb_.SetData(mass_, nElements_ * sizeof(int));
	va_.AddBuffer(vb_, vbl_);

	shader_.SetFilePath("res/shaders/Basic.shader");
	shader_.Bind();
	shader_.setUniform1ui("arr_size", nElements_);
	shader_.setUniform1i("max_value", max_value_);
}


void SortRenderer::Draw(const Renderer & renderer)
{
	vb_.SetNewData(mass_, nElements_ * sizeof(int));
	for (unsigned int i = 0; i < nElements_; i++)
	{
		shader_.Bind();
		shader_.setUniform1ui("i", i);
		shader_.setUniform3f("u_color_marker", color_markers_[i].x, color_markers_[i].y, color_markers_[i].z);
		renderer.Draw(va_, shader_, i);
	}
}

