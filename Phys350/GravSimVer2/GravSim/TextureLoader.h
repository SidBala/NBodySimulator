#pragma once

#include <map>
#include <string>
#include <vector>
#include "SOIL\SOIL.h"

class CTextureLoader
{
public:
	std::map<std::string,GLuint> TexMap;
	


	CTextureLoader(void);
	~CTextureLoader(void);

	void LoadTextures(std::string FolderName);
	void BindTexture(std::string TextureName);
	void UnBindTexture();
};
