#pragma once

enum class SortType
{
	BUBBLE = 0,
	MERGE,
	COUNTING,
	SELECTION,
	SHELL,
	QUICKL,
	SORTS_COUNT
};

struct Vec3
{
	float x, y, z;
	void Set(float X, float Y, float Z)
	{
		x = X;
		y = Y;
		z = Z;
	}
};

enum class ColorName
{
	Red = 0,
	Green,
	Blue,
	White,
	Black,
	Magenta,
	Pink,
	LightBlue,
	Brown,
	Gray,
	ColorCount
};

struct Color
{
	void Set(ColorName color)
	{
		switch (color)
		{
		case ColorName::Red: color_ = {1.f, 0.f, 0.f};
			break;
		case ColorName::Green: color_ = {0.f, 1.f, 0.f};
			break;
		case ColorName::Blue: color_ = {0.f, 0.f, 1.f};
			break;
		case ColorName::White: color_ = {1.f, 1.f, 1.f};
			break;
		case ColorName::Black: color_ = {0.f, 0.f, 0.f};
			break;
		case ColorName::Magenta: color_ = {1.f, 0.f, 1.f};
			break;
		case ColorName::Pink: color_ = {1.f, 0.f, 0.5f};
			break;
		case ColorName::LightBlue: color_ = {0.1f, 0.1f, 0.5f};
			break;
		case ColorName::Brown: color_ = {0.f, 0.4f, 0.4f};
			break;
		case ColorName::Gray: color_ = {0.5f, 0.5f, 0.5f};
			break;
		default: color_ = {0.f, 0.f, 0.f};
			break;
		}
	}
	Vec3 color_;
};

struct ArrayInfo
{
	int* arr;
	int max_value;
	unsigned int nElements;
	Color * markers;
};