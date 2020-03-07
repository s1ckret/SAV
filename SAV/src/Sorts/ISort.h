#pragma once 

#include <memory>
#include <string>

#include "Graphics/DataRenderer/IDataRenderer.h"
#include "DataController/IDataController.h"

class ISort
{
public:
	ISort() = default;
	virtual ~ISort() = default;

	void Init(std::shared_ptr<IDataController> & dataController,
				std::shared_ptr<IDataRenderer> & dataRednderer);

	virtual void Begin() = 0;

	inline std::string GetName() const { return m_name; }
protected:
    std::shared_ptr<IDataController> m_dataController;
    std::shared_ptr<IDataRenderer> m_dataRenderer;
	std::string m_name;
};
