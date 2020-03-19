#pragma once

#include "Graphics/IndexBuffer.h"
#include "Graphics/Renderer.h"
#include "Graphics/Shader.h"
#include "Graphics/VertexArray.h"
#include "Graphics/VertexBuffer.h"
#include "Graphics/VertexBufferLayout.h"

#include "Data/Array.h"
#include "DataController/IDataController.h"

#include <string>
#include <memory>

// TODO: classes with I prefix is interface only.
// TODO: Create basic classes that implements all these functions.

class IDataRenderer : public Renderer
{
public:
	IDataRenderer();
    virtual ~IDataRenderer() = default;

    // Data const ???
    virtual void SetData(Array * data);

    // Set delay in ms.
    virtual void SetDelay(unsigned int delay);
    // Redraw + Delay.
    virtual unsigned int Increment(unsigned int & i);

//void SetDefaultColor(unsigned int index, unsigned int color);

//void SetDefaultColorArea(unsigned int lhs_index, unsigned int rhs_index, unsigned int color);

// Remember previous index and redraw it to default color
//void MarkColor(std::string name, unsigned int index, unsigned int color);

    // Just mark color
    virtual void MarkColor(unsigned int index, unsigned int color);

//void MarkColorArea(std::string name, unsigned int lhs_index, unsigned int rhs_index, unsigned int color);

//void MarkColorArea(unsigned int lhs_index, unsigned int rhs_index, unsigned int color);
    
    virtual void Draw();
    
protected:
    void SleepFor(unsigned int ms);
protected:
    // Data const ???
    std::shared_ptr<Array> m_array;
    std::vector<unsigned int> m_colors;
    int m_max_value;

    
    unsigned int m_delay;


// TODO: Abstract with Drawable class
	VertexBufferLayout m_vbl;
	VertexBuffer m_vb;
	VertexArray m_va;
	Shader m_shader;

};