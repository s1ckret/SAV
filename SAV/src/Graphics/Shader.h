#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>

struct ShaderProgram {
	std::string VertexShader;
	std::string GeometryShader;
	std::string FragmentShader;
};

class Shader
{
public:
	Shader();
	Shader(const std::string& filepath);
	Shader(const Shader& shader);
	~Shader();
	Shader operator=(const Shader& rhs);

	void SetFilePath(const std::string& filepath);
	void Bind() const;
	void Unbind() const;

	void setUniform1f(const std::string& name, float v0);
	void setUniform2f(const std::string& name, float v0, float v1);
	void setUniform3f(const std::string& name, float v0, float v1, float v2);
	void setUniform4f(const std::string& name, float v0, float v1, float v2, float v3);

	void setUniform1ui(const std::string& name, unsigned int v0);
	void setUniform1i(const std::string& name, int v0);

	bool Loaded() const;
private:
	unsigned int GetUniformLocation(const std::string& name);

	ShaderProgram ParseShader(const std::string& filepath);
	unsigned int CompileShader(unsigned int type, const std::string& source);
	unsigned int CreateShader(const std::string & vertexShader, const std::string& geometryShader, const std::string& fragmentShader);

private:
	std::string m_FilePath;
	unsigned int m_RendererID;
	std::unordered_map<std::string, int> m_LocationCache;
};
