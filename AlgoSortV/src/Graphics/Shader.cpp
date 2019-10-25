#include "Shader.h"
#include "Renderer.h"

#include "Log.h"

Shader::Shader() :
	m_FilePath(""),
	m_RendererID(0)

{
}

Shader::Shader(const std::string & filepath) :
	m_FilePath(filepath),
	m_RendererID(0)
{
	ShaderProgram shaderProgram = ParseShader(filepath);
	m_RendererID = CreateShader(shaderProgram.VertexShader, shaderProgram.GeometryShader, shaderProgram.FragmentShader);
}

Shader::Shader(const Shader & shader)
{
	m_FilePath = shader.m_FilePath;
	ShaderProgram shaderProgram = ParseShader(m_FilePath);
	m_RendererID = CreateShader(shaderProgram.VertexShader, shaderProgram.GeometryShader, shaderProgram.FragmentShader);
}

Shader::~Shader()
{
	GLCall(glDeleteProgram(m_RendererID));
}

Shader & Shader::operator=(const Shader & rhs)
{
	return Shader(rhs);
}

void Shader::SetFilePath(const std::string & filepath)
{
	m_FilePath = filepath;
	ShaderProgram shaderProgram = ParseShader(filepath);
	m_RendererID = CreateShader(shaderProgram.VertexShader, shaderProgram.GeometryShader, shaderProgram.FragmentShader);
}

void Shader::Bind() const
{
	GLCall(glUseProgram(m_RendererID));
}

void Shader::Unbind() const
{
	GLCall(glUseProgram(0));
}

void Shader::setUniform1f(const std::string & name, float v0)
{
	GLCall(glUniform1f(GetUniformLocation(name), v0));
}

void Shader::setUniform2f(const std::string & name, float v0, float v1)
{
	GLCall(glUniform2f(GetUniformLocation(name), v0, v1));
}

void Shader::setUniform4f(const std::string & name, float v0, float v1, float v2, float v3)
{
	GLCall(glUniform4f(GetUniformLocation(name), v0, v1, v2, v3));
}

void Shader::setUniform1ui(const std::string & name, unsigned int v0)
{
	GLCall(glUniform1ui(GetUniformLocation(name), v0));
}

void Shader::setUniform1i(const std::string & name, int v0)
{
	GLCall(glUniform1i(GetUniformLocation(name), v0));
}

bool Shader::Loaded() const
{
	return m_RendererID;
}

unsigned int Shader::GetUniformLocation(const std::string & name)
{
	if (m_LocationCache.find(name) != m_LocationCache.end()) {
		return m_LocationCache[name];
	}

	int location = glGetUniformLocation(m_RendererID, name.c_str());
	if (location == -1) {
		LOG_CRITICAL("Uniform {0} doesn't exist", name);
	}
	m_LocationCache[name] = location;
	return location;
}

ShaderProgram Shader::ParseShader(const std::string& filepath)
{
	enum class ShaderType
	{
		None = -1,
		Vertex = 0,
		Geometry = 1,
		Fragment = 2
	} type;
	std::stringstream ss[3];
	std::ifstream file(filepath);
	std::string line;
	while (std::getline(file, line)) {
		if (line.find("#shader") != std::string::npos)
		{
			if (line.find("vertex") != std::string::npos)
			{
				type = ShaderType::Vertex;
			}
			else if (line.find("geometry") != std::string::npos)
			{
				type = ShaderType::Geometry;
			}
			else if (line.find("fragment") != std::string::npos)
			{
				type = ShaderType::Fragment;
			}
		}
		else
		{
			ss[(int)type] << line << '\n';
		}
	}
	file.close();
	return{ ss[0].str(), ss[1].str(), ss[2].str() };
}

unsigned int Shader::CompileShader(unsigned int type, const std::string& source)
{
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	GLCall(glShaderSource(id, 1, &src, nullptr));
	GLCall(glCompileShader(id));

	int result;
	GLCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result));
	if (result == GL_FALSE) {
		int length;
		GLCall(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));
		char* message = (char*)alloca(length * sizeof(char));
		GLCall(glGetShaderInfoLog(id, length, &length, message));
		std::string log = "Failed to compile ";
		switch (type)
		{
		case GL_VERTEX_SHADER: log += "vertex shader.";
			break;
		case GL_GEOMETRY_SHADER: log += "geometry shader.";
			break;
		case GL_FRAGMENT_SHADER: log += "fragment shader.";
			break;
		default:
			break;
		}
		LOG_CRITICAL(log);
		LOG_CRITICAL(message);

		GLCall(glDeleteShader(id));
		return 0;
	}

	return id;
}

unsigned int Shader::CreateShader(const std::string & vertexShader, const std::string& geometryShader, const std::string& fragmentShader)
{
	unsigned int program = glCreateProgram();

	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int gs = CompileShader(GL_GEOMETRY_SHADER, geometryShader);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

	GLCall(glAttachShader(program, vs));
	GLCall(glAttachShader(program, gs));
	GLCall(glAttachShader(program, fs));
	GLCall(glLinkProgram(program));
	GLCall(glValidateProgram(program));

	GLCall(glDeleteShader(vs));
	GLCall(glDeleteShader(gs));
	GLCall(glDeleteShader(fs));

	return program;
}