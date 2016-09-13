#version 330

out vec4 fragColour;

in vec2 textureCoordinates;
uniform sampler2D basicTexture;

uniform vec4 colour;

void main()
{
	vec4 texel = texture(basicTexture, textureCoordinates);
	fragColour = texel * colour;
}