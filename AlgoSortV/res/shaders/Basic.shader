#shader vertex
#version 330 core

layout (location = 0) in vec2 position;

void main()
{
	gl_Position = vec4(position, 1.0, 1.0);
};

#shader fragment
#version 330 core

out vec4 color;

void main()
{
	color = vec4(1.0, 0.2, 0.2, 1.0);
};
