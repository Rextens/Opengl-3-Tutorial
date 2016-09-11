#include "Textures.h"



Textures::Textures(std::string wayToTexture, Vertices &texVertices)
{
	FREE_IMAGE_FORMAT imageFormat = FIF_UNKNOWN;
	FIBITMAP* imageBits = 0;
	BYTE* bits = 0;

	imageFormat = FreeImage_GetFileType(wayToTexture.c_str(), 0);
	if (imageFormat == FIF_UNKNOWN)
		imageFormat = FreeImage_GetFIFFromFilename(wayToTexture.c_str());

	if (FreeImage_FIFSupportsReading(imageFormat))
		imageBits = FreeImage_Load(imageFormat, wayToTexture.c_str());

	bits = FreeImage_GetBits(imageBits);

	int imageWidth = 0;
	int imageHeight = 0;
	imageWidth = FreeImage_GetWidth(imageBits);
	imageHeight = FreeImage_GetHeight(imageBits);
	if ((bits == 0) || (imageWidth == 0) || (imageHeight == 0))
		return;

	GLuint texture = 0;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageWidth, imageHeight, 0, GL_BGR, GL_UNSIGNED_BYTE, bits);
	glGenerateMipmap(GL_TEXTURE_2D);

	glGenBuffers(1, &textureCoordsVbo);
	glBindBuffer(GL_ARRAY_BUFFER, textureCoordsVbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * texVertices.vertices.size(), texVertices.vertices.data(), GL_STATIC_DRAW);
}


Textures::~Textures()
{
}
