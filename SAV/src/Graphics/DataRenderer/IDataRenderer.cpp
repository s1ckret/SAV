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

// TODO: Mark color
unsigned int IDataRenderer::Increment(unsigned int & index) {
    if (index != 0) {
    //    (*m_array)[index] = ToRGB(0xffffff);
    }
    //(*m_array)[index] = ToRGB(0xff0000);
    SleepFor(m_delay);
    return ++index;
}

void IDataRenderer::MarkColor(unsigned int index, unsigned int color) {
    (*m_array)[index] = ToRGB(color);
}

// TODO: Batch Rendering
void IDataRenderer::Draw() {
	m_vb.UpdateData(m_array->begin(), m_array->size() * sizeof(Column));
    Renderer::Draw(m_va, m_shader, m_array->size());
}

void IDataRenderer::SleepFor(unsigned int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}
