#pragma once

#include "IDataController.h"

class BasicDataController : public IDataController {
public:
    BasicDataController() = default;
    ~BasicDataController() = default;

    void Generate(unsigned int size, unsigned int max_value) override;

    void Shuffle() override;

};