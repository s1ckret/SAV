#shader vertex
#version 330 core

layout (location = 0) in int a_height;
layout (location = 1) in vec3 a_color;

uniform uint u_arr_size;
uniform uint u_arr_max_value;

out float v_height;
out vec3 v_color;

void main() {
    float width = 4.0 / float(u_arr_size);
	gl_Position = vec4(gl_VertexID * width - 2.0, 0.0, 1.0, 1.0);
    v_height = 2.0 * float(a_height) / float(u_arr_max_value);
    v_color = a_color;
}

#shader geometry
#version 330 core

layout (points) in;
layout (triangle_strip, max_vertices = 4) out;

uniform uint u_arr_size;

in float v_height[];
in vec3 v_color[];

out vec3 p_color;

void createVertex(vec4 offset) {
    gl_Position = offset + gl_in[0].gl_Position;
    p_color = v_color[0];
    EmitVertex();
}

void createColumn() {
    float width = 4.0 / float(u_arr_size);
    createVertex(vec4(0.0, v_height[0], 0.0, 1.0));
    createVertex(vec4(0.0, 0.0, 0.0, 1.0));
    createVertex(vec4(width, v_height[0], 0.0, 1.0));
    createVertex(vec4(width, 0.0, 0.0, 1.0));
    EndPrimitive();
}

void main() {
    createColumn();
}

#shader fragment
#version 330 core

in vec3 p_color;
out vec4 f_color;

void main() {
    f_color = vec4(p_color, 1.0);
}