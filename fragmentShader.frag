#version 330

out vec4 fragColour;

vec3 colour = vec3(1.0f, 1.0f, 1.0f);

void main()
{
	fragColour = vec4(colour, 1.0);
}