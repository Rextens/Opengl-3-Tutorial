#version 330

out vec4 fragColour;

uniform vec3 bonusColour;

void main()
{
    fragColour = vec4(bonusColour.x, bonusColour.y, bonusColour.z, 1.0);
}
