#shader vertex
#version 330 core

layout (location = 0) in int value;

uniform uint arr_size;
uniform int max_value;

out uint size;
out float height;

void main()
{
	gl_Position = vec4(0.0, 0.0, 1.0, 1.0);
	size = arr_size;
	height = float(value) / float(max_value);
};

#shader geometry
#version 330 core

layout ( points ) in ;
layout ( triangle_strip, max_vertices = 6) out;

uniform uint i;
uniform vec3 u_color_marker;

in uint size[];
in float height[];
out vec3 out_color;


float width = 2.0f / float(size[0]);

void createVertex(vec2 offset)
{
	gl_Position = gl_in[0].gl_Position + vec4(offset, 0.f, 0.f) + vec4(float(i) * width - 1.f, 0.f, 0.f, 0.f);
	EmitVertex();
}

void main()
{
	out_color = u_color_marker;
	
	createVertex(vec2(0.f, 0.f));
	createVertex(vec2(width, 0.f));
	createVertex(vec2(width, height[0]));

	createVertex(vec2(0.f, 0.0f));
	createVertex(vec2(0.f, height[0]));
	createVertex(vec2(width, height[0]));
	EndPrimitive();
};

#shader fragment
#version 330 core

in vec3 out_color;
out vec4 color;

void main()
{
	color = vec4(out_color, 1.0);
};

