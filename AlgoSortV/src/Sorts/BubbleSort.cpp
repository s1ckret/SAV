#include "BubbleSort.h"

void BubbleSort::Begin(int * mass, unsigned int nElements, Vec3 * color_markers)
{
	for (unsigned int i = 0; i < nElements; i++)
	{
		for (unsigned int j = 0; j < nElements - i - 1; j++)
		{
			color_markers[j].Set(1.f, 0.f, 0.f);
			color_markers[j + 1].Set(1.f, 0.f, 0.f);
			if (mass[j] > mass[j + 1])
			{
				int temp = mass[j];
				mass[j] = mass[j + 1];
				mass[j + 1] = temp;
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
			color_markers[j].Set(1.f, 1.f, 1.f);
		}
		color_markers[nElements - 1 - i].Set(0.f, 1.f, 0.f);
	}
	LOG_INFO("I am sorted !");
}


