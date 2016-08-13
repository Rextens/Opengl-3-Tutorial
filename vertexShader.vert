#version 330

layout(location = 0) in vec3 vp;

uniform mat4 transforms;

void main()
{
	gl_Position = transforms * vec4(vp.x, vp.y, vp.z,  1.0);
}