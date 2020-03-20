#include "IDataRenderer.h"

#include <algorithm>
#include <thread>
#include "Log.h"
#include "glm/glm.hpp"

#include "Utility.h"

extern GLFWwindow* window;

IDataRenderer::IDataRenderer()
    : Renderer()
{
}

void IDataRenderer::SetData(Array * data) {
    // TODO: Reload data when function is called second ... n-th time.
    m_array = std::shared_ptr<Array>(data);

    m_default_color.resize(m_array->size());
    for (auto it = m_default_color.begin(); it != m_default_color.end(); it++) {
        *it = 0xffffff;
    }

    auto max_value_it = std::max_element(m_array->begin(), m_array->end());
    m_max_value = max_value_it->Data();

    // Position
    m_vbl.Push<float>(1);
    // Color
    m_vbl.Push<float>(3);
    
	m_vb.SetData(m_array->begin(), m_array->size() * sizeof(Column));
	m_va.AddBuffer(m_vb, m_vbl);

	m_shader.SetFilePath("res/shaders/New.shader");
	m_shader.Bind();

    LOG_WARN("Array size: {0}", m_array->size());
    LOG_WARN("Max value: {0}", m_max_value);

	m_shader.setUniform1ui("u_arr_size", m_array->size());
	m_shader.setUniform1ui("u_arr_max_value", m_max_value);
}

void IDataRenderer::SetDelay(unsigned int delay) {
    m_delay = delay;
}

unsigned int IDataRenderer::Increment(unsigned int & index) {
    if (index != 0) {
        MarkColor(index - 1, m_default_color[index - 1]);
    }
    MarkColor(index, 0xff0000);
    SleepFor(m_delay);
    return ++index;
}

void IDataRenderer::SetDefaultColor(unsigned int index, unsigned int color) {
    m_default_color[index] = color;
}

void IDataRenderer::SetDefaultColorArea(unsigned int lhs_index, unsigned int rhs_index, unsigned int color) {
    // TODO: Debug flag
    assert(lhs_index < rhs_index);

    for (unsigned int i = lhs_index; i < rhs_index + 1; i++) {
        SetDefaultColor(i, color);
    }
}

void IDataRenderer::MarkColor(unsigned int index, unsigned int color) {
    (*m_array)[index] = ToRGB(color);
}

void IDataRenderer::MarkColorArea(unsigned int lhs_index, unsigned int rhs_index, unsigned int color) {
    // TODO: Debug flag
    assert(lhs_index < rhs_index);

    for (unsigned int i = lhs_index; i < rhs_index + 1; i++) {
        MarkColor(i, color);
    }    
}

void IDataRenderer::Draw() {
	m_vb.UpdateData(m_array->begin(), m_array->size() * sizeof(Column));
    Renderer::Draw(m_va, m_shader, m_array->size());
}

void IDataRenderer::SleepFor(unsigned int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}
