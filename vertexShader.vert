#version 330

layout(location = 0) in vec3 vp;

uniform float position;

void main()
{
	gl_Position = vec4(vp.x + position, vp.y, vp.z,  1.0);
}