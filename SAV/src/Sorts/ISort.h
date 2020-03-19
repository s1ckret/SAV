#pragma once 

#include <memory>
#include <string>

#include "Graphics/DataRenderer/IDataRenderer.h"
#include "Data/Array.h"
#include "DataController/IDataController.h"

class ISort
{
public:
	ISort(Array & array, std::shared_ptr<IDataRenderer>& dataRednderer);
	virtual ~ISort() = default;

	void SetDataRenderer(std::shared_ptr<IDataRenderer>& dataRednderer);

	virtual void Begin() = 0;

	inline std::string GetName() const { return m_name; }

	// temporary
	inline void Swap(Column & lhs, Column & rhs) {
		Column tmp = lhs;
		lhs = rhs;
		rhs = tmp;
	}
protected:
    std::shared_ptr<IDataRenderer> m_dataRenderer;
	Array & m_array;
	std::string m_name;
};
