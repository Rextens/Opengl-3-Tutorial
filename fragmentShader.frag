#version 330

out vec4 fragColour;

uniform vec3 colour;

void main()
{
	fragColour = vec4(colour, 1.0);
}