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
#include <vector>
#include <map>

// TODO: classes with I prefix is interface only.
// TODO: Create basic classes that implements all these functions.
// TODO: SetShader function
class IDataRenderer : public Renderer
{
public:
	IDataRenderer();
    virtual ~IDataRenderer() = default;

    void SetData(Array * data);

    // Set delay in ms.
    void SetDelay(unsigned int delay);

    void RenderIterator(std::string name, unsigned int index, unsigned int color);

    void RemoveIterator(std::string name);

    void MarkColor(unsigned int index, unsigned int color);

    void MarkColorArea(unsigned int lhs_index, unsigned int rhs_index, unsigned int color);
  
    virtual void Draw();
    
protected:
    void SleepFor(unsigned int ms);
protected:
    Array * m_array;

    struct ColumnInfo {
        unsigned int index;
        unsigned int color;
    };
    std::map<std::string, ColumnInfo> m_iterator_color;

    unsigned int m_max_value;
    unsigned int m_delay;

// TODO: Abstract with Drawable class
	VertexBufferLayout m_vbl;
	VertexBuffer m_vb;
	VertexArray m_va;
	Shader m_shader;

};