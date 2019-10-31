#include "BubbleSort.h"

void BubbleSort::Begin(int * mass, unsigned int nElements)
{
	for (unsigned int i = 0; i < nElements; i++)
	{
		for (unsigned int j = 0; j < nElements - i - 1; j++)
		{
			if (mass[j] > mass[j + 1])
			{
				int temp = mass[j];
				mass[j] = mass[j + 1];
				mass[j + 1] = temp;
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}
	}
	LOG_INFO("I am sorted !");
}
