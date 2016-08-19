#version 330

out vec4 fragColour;

vec3 colour = vec3(1.0f, 0.3f, 0.6f);

void main()
{
	fragColour = vec4(colour, 1.0);
}