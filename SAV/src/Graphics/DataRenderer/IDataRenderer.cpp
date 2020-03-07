#include "IDataRenderer.h"

#include <algorithm>
#include <thread>
#include "Log.h"
#include "glm/glm.hpp"

extern GLFWwindow* window;

IDataRenderer::IDataRenderer()
    : Renderer()
{

}

void IDataRenderer::SetData(Data * data) {
    // TODO: Reload data when function is called second ... n-th time.
    m_array = std::shared_ptr<Data>(data);

    std::vector<unsigned int>().swap(m_colors);
    m_colors.resize(m_array->size());

    auto max_value_it = std::max_element(m_array->begin(), m_array->end());
    m_max_value = *max_value_it;

    m_vbl.Push<float>(1);
	m_vb.SetData(m_array.get(), m_array->size() * sizeof(int));
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
    Draw();
    SleepFor(m_delay);
    return ++i;
}

void IDataRenderer::MarkColor(unsigned int index, unsigned int color) {
    m_colors[index] = color;
}

// TODO: Batch Rendering
void IDataRenderer::Draw() {
    Renderer::Clear();
	m_vb.SetNewData(m_array.get(), m_array->size() * sizeof(int));
	for (unsigned int i = 0; i < m_array->size(); i++)
	{
		m_shader.Bind();
		m_shader.setUniform1ui("i", i);

        glm::vec3 color;

        color.r = ((m_colors[i] >> 16) & 0xFF) / 255.0;  // Extract the RR byte
        color.g = ((m_colors[i] >> 8) & 0xFF) / 255.0;   // Extract the GG byte
        color.b = (m_colors[i] & 0xFF) / 255.0;        // Extract the BB byte

		m_shader.setUniform3f("u_color_marker", color.x, color.y, color.z);
		Renderer::Draw(m_va, m_shader, i);
	}

    // Swap the screen buffers
    glfwSwapBuffers(window);
}

void IDataRenderer::SleepFor(unsigned int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}