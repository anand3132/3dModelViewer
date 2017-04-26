#if 1
#ifndef _TEXTURE_LOADER_H_
#define _TEXTURE_LOADER_H_

#include <Windows.h>
//#include <gl/glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <string.h>
#include <math.h>

#include <ocidl.h> // LPPICTURE
#include <olectl.h> // OleLoadPicture()
#include <ole2.h> // CreateStreamOnHGlobal
// these are the needed libraries
#pragma comment(lib,"uuid.lib")
#pragma comment(lib,"ole32.lib")
#pragma comment(lib,"oleaut32.lib")

#define RGB_BYTE_SIZE		3

class CTextureLoader1
{
public:
	typedef enum {
		txUnknown	= 0,	// images
		txBmp		= 1,
		txJpg		= 2,
		txPng		= 3,
		txTga		= 4,
		txGif		= 5,
		txIco		= 6,
		txEmf		= 7,
		txWmf		= 8,
		// add new ones at the end
	} eglTexType;

	typedef enum {
		txNoFilter	= 0,
		txBilinear	= 1,
		txTrilinear	= 2,
		// add new ones at the end
	} eglTexFilterType;

	struct stTexture
	{
		stTexture()
		{
			TextureID	= 0;
			TexType		= txUnknown;
			Width		= 0;
			Height		= 0;
			Type		= GL_RGB;
			Bpp			= 0;
			data		= NULL;
		}

		unsigned int		TextureID;									// Texture ID Used To Select A Texture
		eglTexType	TexType;											// Texture Format
		unsigned int		Width;										// Image Width
		unsigned int		Height;										// Image Height
		unsigned int		Type;										// Image Type (GL_RGB, GL_RGBA)
		unsigned int		Bpp;										// Image Color Depth In Bits Per Pixel
		BYTE*		data;												//bitmap pointer
		char		szFullPath[MAX_PATH+1];								// Full Path To Picture
	};

	struct stBitmapPacket
	{
		stBitmapPacket()
		{
			pPicture = NULL;
		}

		HDC			bmp_hdc;												// The DC To Hold Our Bitmap
		HBITMAP		hbmp;												// Holds The Bitmap Temporarily
		IPicture	*pPicture;												// IPicture Interface
	};

	struct stBmp_RGBA4444
	{
		unsigned short
			a : 4,
			b : 4,
			g : 4,
			r : 4;
	};

	struct stBmp_RGBA
	{
		int
			r : 8,
			g : 8,
			b : 8,
			a : 8;
	};

	CTextureLoader1();
	~CTextureLoader1();

	int LoadTexture(stTexture* aTexture, char* aTexFileName, char* aOpTexFileName=NULL);
	void SetFilterType(eglTexFilterType aFilter) { iFilterType = aFilter; };
	void SetMipMapping(bool aBool) { bMipMapping = aBool; };
	void SetOverBright(float aBrightness, bool aBool);
	void ConvertToRGBA4444(stTexture* aSrcTexture, stTexture* aAlphaTexture);
	void ConvertToRGBA(stTexture* aSrcTexture, stTexture* aAlphaTexture);
	static int GenerateGLTexture(stTexture *aTexture, bool bMipMap=false, eglTexFilterType aFilterType=txBilinear);
protected:
private:
	void ExtensionFromFilename(char *szFileName, char *szExtension);
	int BuildBitmap(stTexture* aTexture, stBitmapPacket* aBitmapPacket, char* aTexAbsolutePath);
	int SetLoadData(stTexture* aTexture, char* aTexFileName);

	eglTexFilterType iFilterType;
	bool bMipMapping;
	bool bOverBright;
	float iOverBrightMagnitude;
};

#endif
#endif