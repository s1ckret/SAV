#include "ISortRenderer.h"

ISortRenderer::ISortRenderer(int * mass, unsigned int nElements)
	: mass_(mass),
	nElements_(nElements)
{
	vbl_.Push<float>(1);
	vb_.SetData(mass_, nElements_ * sizeof(int));
	va_.AddBuffer(vb_, vbl_);

	shader_.SetFilePath("res/shaders/Basic.shader");
	shader_.Bind();
	shader_.setUniform1ui("arr_size", nElements_);
	shader_.setUniform1i("max_value", FindMax());

}

int ISortRenderer::FindMax()
{
	int max = mass_[0];
	for (unsigned int i = 0; i < nElements_; i++)
	{
		if (mass_[i] > max)
		{
			max = mass_[i];
		}
	}
	return max;
}
