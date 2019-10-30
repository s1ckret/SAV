#include "BubbleSortRenderer.h"

BubbleSortRenderer::BubbleSortRenderer(int * mass, unsigned int nElements) : ISortRenderer(mass, nElements)
{
}

BubbleSortRenderer::~BubbleSortRenderer()
{
}

void BubbleSortRenderer::Draw(const Renderer & renderer)
{
	vb_.SetNewData(mass_, nElements_ * sizeof(int));
	for (unsigned int i = 0; i < nElements_; i++)
	{
		shader_.Bind();
		shader_.setUniform1ui("i", i);
		renderer.Draw(va_, shader_, i);
	}
}
