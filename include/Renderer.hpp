#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "gl_core.h"
#include "Scene.hpp"
#include "settings.h"

class Renderer
{
  private:
  public:
	Scene         scene;
	std::vector<float> OutputImage;
	// unsigned char output[SCR_WIDTH * SCR_HEIGHT * 3]; // RGB
	GLuint        textureID;

	Renderer();
	~Renderer();
	void setupTexture();
	void rayTrace();
};

#endif
