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
#include <map>

// TODO: SetShader function
class IDataRenderer : public Renderer
{
public:
  IDataRenderer(Array *data, unsigned int delay_ms);
    virtual ~IDataRenderer() = default;

    virtual void SetData(Array * data);

    virtual void SetDelay(unsigned int ms);

    virtual void RenderIterator(std::string name, unsigned int index, unsigned int color);

    virtual void RemoveIterator(std::string name);

    virtual void MarkColor(unsigned int index, unsigned int color);

    virtual void MarkColorArea(unsigned int lhs_index, unsigned int rhs_index, unsigned int color);
  
    virtual void Draw();

    virtual void Reset();

    virtual void DisplaySorted( );
    
protected:
    void SleepFor(unsigned int ms);
    void Init();

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