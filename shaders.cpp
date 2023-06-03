#include"shaders.h"

// Reads a text file and outputs a string with everything in the text file
std::string get_file_contents(const char* filename)
{
	std::ifstream in(filename, std::ios::binary);
	if (in)
	{
		std::string contents;
		// Getting file length
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg()); // makes contents big enough to hold everything in the file
		in.seekg(0, std::ios::beg); // sends pointer back to thge beginning
		

		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
}

// Constructor that build the Shader Program from 2 different shaders
Shader::Shader(const char* vertex_file, const char* fragment_file)
{
	// Read vertexFile and fragmentFile and store the strings
	std::string vertex_code = get_file_contents(vertex_file);
	std::string fragment_code = get_file_contents(fragment_file);

	// Convert the shader source strings into character arrays
	const char* vertex_source = vertex_code.c_str();
	const char* fragment_source = fragment_code.c_str();

	// Create Vertex Shader Object and get its reference
	GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	// Attach Vertex Shader source to the Vertex Shader Object
	glShaderSource(vertex_shader, 1, &vertex_source, NULL);
	// Compile the Vertex Shader into machine code
	glCompileShader(vertex_shader);

	// Create Fragment Shader Object and get its reference
	GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	// Attach Fragment Shader source to the Fragment Shader Object
	glShaderSource(fragment_shader, 1, &fragment_source, NULL);
	// Compile the Vertex Shader into machine code
	glCompileShader(fragment_shader);

	// Create Shader Program Object and get its reference
	ID = glCreateProgram();
	// Attach the Vertex and Fragment Shaders to the Shader Program
	glAttachShader(ID, vertex_shader);
	glAttachShader(ID, fragment_shader);
	// Wrap-up/Link all the shaders together into the Shader Program
	glLinkProgram(ID);

	// Delete the now useless Vertex and Fragment Shader objects
	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);

}

// Activates the Shader Program
void Shader::Activate()
{
	glUseProgram(ID);
}

// Deletes the Shader Program
void Shader::Delete()
{
	glDeleteProgram(ID);
}