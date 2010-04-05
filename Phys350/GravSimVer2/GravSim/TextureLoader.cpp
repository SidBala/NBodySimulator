#include "StdAfx.h"
#include "TextureLoader.h"

CTextureLoader::CTextureLoader(void)
{
}

CTextureLoader::~CTextureLoader(void)
{
}

void CTextureLoader::BindTexture(std::string TextureName)
{
	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//LOG("\nTexture Number: %d",TexMap[TextureName]);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D ,TexMap[TextureName]);
	glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
    glTexParameteri( GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
    glTexParameteri( GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR );
}

void CTextureLoader::UnBindTexture()
{
	glBindTexture(GL_TEXTURE_2D ,NULL);
}
void CTextureLoader::LoadTextures(std::string FolderName)
{
	glEnable(GL_TEXTURE_2D);
	//	Scan the folder for all the files first
	CString dirName(FolderName.c_str());

	std::string filepath;
	std::string	mapkey;

	// Check input parameters
	ASSERT( dirName != NULL );

	// Clear filename list
	filepath.clear();

	// Object to enumerate files
	CFileFind finder;

	// Build a string using wildcards *.*,
	// to enumerate content of a directory
	CString wildcard( dirName );

	//Scan only png
	wildcard += "\\*.*";

	// Init the file finding job
	BOOL working = finder.FindFile( wildcard );

	// For each file that is found:
	while ( working )
	{
		// Update finder status with new file
		working = finder.FindNextFile();

		// Skip '.' and '..'
		if ( finder.IsDots() )
		{
			continue;
		}

		// Skip sub-directories
		if ( finder.IsDirectory() )
		{
			continue;
		}

		// Add file path to container
		filepath = std::string((LPCTSTR)finder.GetFilePath());
		mapkey = std::string((LPCTSTR)finder.GetFileTitle());

		LOG("\nLoading Texture:%-15s",mapkey.data());

		glEnable(GL_TEXTURE_2D);

		int textureid = SOIL_load_OGL_texture
		(
			filepath.data(),
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_MIPMAPS
		);


		LOG("..%s, ",SOIL_last_result());

		TexMap[mapkey] = textureid;
	}

	// Cleanup file finder
	finder.Close();
}