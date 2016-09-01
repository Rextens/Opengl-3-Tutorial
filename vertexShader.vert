#version 330

layout(location = 0) in vec3 vp;

uniform mat4 transforms;
uniform mat4 view;
uniform mat4 perspective;

void main()
{
	gl_Position = perspective * view * transforms * vec4(vp.x, vp.y, vp.z,  1.0);
}