#version 330 core
out vec4 FragColour;

in vec2 TexCoords;

uniform sampler2D ScreenTexture;

void main()
{
	FragColour = texture(ScreenTexture, TexCoords);
}