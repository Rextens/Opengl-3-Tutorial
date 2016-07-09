#version 330
layout (location = 0) in vec3 vp;

uniform vec2 trans;

void main()
{
    gl_Position = vec4(vp.x + trans.x, vp.y + trans.y, vp.z, 1.0);
}
