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
    std::vector<unsigned int>().swap(m_colors);
    m_colors.resize(m_array->size());

    for (auto it = m_colors.begin(); it != m_colors.end(); it++) {
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

	m_shader.SetFilePath("res/shaders/Basic.shader");
	m_shader.Bind();
	m_shader.setUniform1ui("arr_size", m_array->size());
    LOG_WARN("Max value {0}", m_max_value);
	m_shader.setUniform1i("max_value", m_max_value);
}

void IDataRenderer::SetDelay(unsigned int delay) {
    m_delay = delay;
}

// TODO: Mark color
unsigned int IDataRenderer::Increment(unsigned int & i) {
    if ((i - 1) != static_cast<unsigned int>(-1)) {
        m_colors.at(i - 1) = 0xffffff;
    }
    m_colors.at(i) = 0xff0000;
    SleepFor(m_delay);
    return ++i;
}

void IDataRenderer::MarkColor(unsigned int index, unsigned int color) {
    m_colors[index] = color;
}

// TODO: Batch Rendering
void IDataRenderer::Draw() {
	m_vb.SetNewData(m_array->begin(), m_array->size() * sizeof(Column));
	for (unsigned int i = 0; i < m_array->size(); i++)
	{
		m_shader.Bind();
		m_shader.setUniform1ui("i", i);

        glm::vec3 color = ToRGB(m_colors[i]);
		m_shader.setUniform3f("u_color_marker", color.x, color.y, color.z);

		Renderer::Draw(m_va, m_shader, i);
	}
}

void IDataRenderer::SleepFor(unsigned int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}
