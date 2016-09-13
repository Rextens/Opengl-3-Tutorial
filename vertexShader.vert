#version 330

layout(location = 0) in vec3 vp;
layout(location = 1) in vec2 vt;

uniform mat4 transforms;
uniform mat4 view;
uniform mat4 perspective;

out vec2 textureCoordinates;

void main()
{
	textureCoordinates = vt;
	gl_Position = perspective * view * transforms * vec4(vp.x, vp.y, vp.z,  1.0);
}