#if 1
#include "TextureLoader1.h"

CTextureLoader1::CTextureLoader1()
{
	iFilterType = txBilinear;
	bMipMapping = false;
	iOverBrightMagnitude = 1.0f;
	bOverBright = false;
}

CTextureLoader1::~CTextureLoader1()
{}


void CTextureLoader1::SetOverBright(float aBrightness, bool aBool)
{
	iOverBrightMagnitude = aBrightness;
	bOverBright = aBool;
}

void CTextureLoader1::ExtensionFromFilename(char *szFileName, char *szExtension)
{
	int len = strlen(szFileName);

	int begin=0;
	for (begin=len;begin>=0;begin--)
	{
		if (szFileName[begin] == '.')
		{
			begin++;
			break;
		}
	}

	if (begin <= 0)
	{
		szExtension[0] = '\0';
	}
	else
	{
		strcpy(szExtension, &szFileName[begin]);
	}
}

int CTextureLoader1::SetLoadData(stTexture* aTexture, char* aTexFileName)
{
	char szExtension[16];												// Extenstion of Picture

	if (strstr(aTexFileName, "http://"))									// If PathName Contains http:// Then...
	{
		strcpy(aTexture->szFullPath, aTexFileName);									// Append The PathName To FullPath
	}
	else																// Otherwise... We Are Loading From A File
	{
		//GetCurrentDirectory(MAX_PATH, aTexture->szFullPath);						// Get Our Working Directory
		//strcat(aTexture->szFullPath, "\\");										// Append "\" After The Working Directory
		strcpy(aTexture->szFullPath, aTexFileName);									// Append The PathName
	}

	ExtensionFromFilename(aTexFileName, szExtension);
	// if the file is a TGA then use the TGA file loader
	if (strcmpi(szExtension, "tga") == 0)
	{
		return(-1);				// Load TGA (Compressed/Uncompressed)
	}
	else
	{
		// else load BMP, JPG, GIF
		aTexture->TexType = txUnknown;
		if (strcmpi(szExtension, "bmp") == 0)
		{
			aTexture->TexType = txBmp;
		}
		else if ((strcmpi(szExtension, "jpg") == 0) ||
			(strcmpi(szExtension, "jpeg") == 0) )
		{
			aTexture->TexType = txJpg;
		}
		else if (strcmpi(szExtension, "gif") == 0)
		{
			aTexture->TexType = txGif;
		}
		else if (strcmpi(szExtension, "ico") == 0)
		{
			aTexture->TexType = txIco;
		}
		else if (strcmpi(szExtension, "emf") == 0)
		{
			aTexture->TexType = txEmf;
		}
		else if (strcmpi(szExtension, "wmf") == 0)
		{
			aTexture->TexType = txWmf;
		}

		return 0;
	}
}

void CTextureLoader1::ConvertToRGBA4444(stTexture* aSrcTexture, stTexture* aAlphaTexture)
{
	stBmp_RGBA4444 *destData;
	destData = new stBmp_RGBA4444[aSrcTexture->Width*aSrcTexture->Height];

	for(unsigned int i=0,j=0;i<aSrcTexture->Width*aSrcTexture->Height*RGB_BYTE_SIZE;i+=3,j++)
	{
		destData[j].r = aSrcTexture->data[i+0]>>4;
		destData[j].g = aSrcTexture->data[i+1]>>4;
		destData[j].b = aSrcTexture->data[i+2]>>4;		
		if(aAlphaTexture->data)
			destData[j].a = ((aAlphaTexture->data[i+0]+aAlphaTexture->data[i+1]+aAlphaTexture->data[i+2])/3)>>4;
		else
			destData[j].a = 0;
	}
	//data_format = GL_RGBA;
	//data_type = GL_UNSIGNED_SHORT_4_4_4_4;

	delete [] aSrcTexture->data;
	aSrcTexture->data = (byte*)destData;
}

void CTextureLoader1::ConvertToRGBA(stTexture* aSrcTexture, stTexture* aAlphaTexture)
{
	stBmp_RGBA *destData;
	destData = new stBmp_RGBA[aSrcTexture->Width*aSrcTexture->Height];

	for(unsigned int i=0,j=0;i<aSrcTexture->Width*aSrcTexture->Height*RGB_BYTE_SIZE;i+=3,j++)
	{
		destData[j].r = aSrcTexture->data[i+0];
		destData[j].g = aSrcTexture->data[i+1];
		destData[j].b = aSrcTexture->data[i+2];		
		if(aAlphaTexture->data)
			destData[j].a = ((aAlphaTexture->data[i+0]+aAlphaTexture->data[i+1]+aAlphaTexture->data[i+2])/3);
		else
			destData[j].a = 0;
	}
	//data_format = GL_RGBA;
	//data_type = GL_UNSIGNED_SHORT_4_4_4_4;

	delete [] aSrcTexture->data;
	aSrcTexture->data = (byte*)destData;
}

int CTextureLoader1::GenerateGLTexture(stTexture *aTexture, bool bMipMap, eglTexFilterType aFilterType)
{
	int result = 0;

	int	bmp_datatype=GL_UNSIGNED_BYTE;
	// set the data type
	if(aTexture->Type==GL_RGBA)
	{
		bmp_datatype= GL_UNSIGNED_BYTE;	//4-4-4-4
	}
	else
	{
		bmp_datatype= GL_UNSIGNED_BYTE;	//4-4-4-4
	}

	glGenTextures(1, &aTexture->TextureID);							// Create The Texture
	glBindTexture(GL_TEXTURE_2D, aTexture->TextureID);				// Bind To The Texture ID
	BOOL	Mipping;
	switch(aFilterType)
	{
		case txNoFilter:
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1 );
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			Mipping = false;
		break;

		case txBilinear:
			if (bMipMap == false)
			{
				glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
				// set the build type flag
				Mipping = false;
			}
			else
			{
				glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
				Mipping = true;
			}
		break;

		case txTrilinear:
			glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			// always mip mapping for trilinear
			Mipping = true;
		break;
		default:
			break;
	}

	if (Mipping == false)
	{
		glTexImage2D(GL_TEXTURE_2D,
			0,
			aTexture->Type,
			aTexture->Width,
			aTexture->Height,
			0,
			aTexture->Type,
			bmp_datatype,
			aTexture->data);
	}
	else
	{
		// Build Mipmaps (builds different versions of the picture for distances - looks better)
		result = gluBuild2DMipmaps(GL_TEXTURE_2D,
		aTexture->Type,
		aTexture->Width,
		aTexture->Height,
		aTexture->Type,
		bmp_datatype,
		aTexture->data);
	}

	return 0;
}

int CTextureLoader1::LoadTexture(stTexture* aTexture, char* aTexFileName, char* aOpTexFileName)
{
	//if(aOpTexFileName)
	//{
	//	stTexture aOpTexture;
	//	SetLoadData(&aOpTexture, aOpTexFileName);
	//	stBitmapPacket aBitmapPacket;
	//	int err1 = BuildBitmap(&aOpTexture, &aBitmapPacket, aOpTexture.szFullPath);
	//	if(err1==1)	//everything went fine for alpha
	//	{
	//		//diffuse texture
	//		SetLoadData(aTexture, aTexFileName);
	//		stBitmapPacket aBitmapPacket2;
	//		int err2 = BuildBitmap(aTexture, &aBitmapPacket2, aTexture->szFullPath);
	//		if(err2==1)	//everything went fine
	//		{
	//			ConvertToRGBA(aTexture, &aOpTexture);
	//			//GX_DELETE_ARY(aTexture->data);
	//			aTexture->Type=GL_RGBA;
	//			GenerateGLTexture(aTexture);
	//			GX_DELETE_ARY(aOpTexture.data);
	//			GX_DELETE_ARY(aTexture->data);
	//		}
	//	}

	//	return 0;
	//}
	//else
	//{
	//	SetLoadData(aTexture, aTexFileName);
	//	stBitmapPacket aBitmapPacket;
	//	int err= BuildBitmap(aTexture, &aBitmapPacket, aTexture->szFullPath);
	//	if(err==1)	//everything went fine
	//	{
	//		GenerateGLTexture(aTexture);
	//		GX_DELETE_ARY(aTexture->data);
	//	}
	//	return 0;
	//}
	
	if(aTexFileName && aOpTexFileName)
	{
		stTexture aOpTexture;
		SetLoadData(&aOpTexture, aOpTexFileName);
		stBitmapPacket aBitmapPacket;
		int err1 = BuildBitmap(&aOpTexture, &aBitmapPacket, aOpTexture.szFullPath);
		if(err1==1)	//everything went fine for alpha
		{
			//diffuse texture
			SetLoadData(aTexture, aTexFileName);
			stBitmapPacket aBitmapPacket2;
			int err2 = BuildBitmap(aTexture, &aBitmapPacket2, aTexture->szFullPath);
			if(err2==1)	//everything went fine
			{
				ConvertToRGBA(aTexture, &aOpTexture);
				//GX_DELETE_ARY(aTexture->data);
				aTexture->Type=GL_RGBA;
				GenerateGLTexture(aTexture, bMipMapping, iFilterType);
				delete [] (aOpTexture.data);
				delete [] (aTexture->data);
			}
		}

		return 0;
	}
	else
	{
		if(aTexFileName)
		{
			SetLoadData(aTexture, aTexFileName);
			stBitmapPacket aBitmapPacket;
			int err= BuildBitmap(aTexture, &aBitmapPacket, aTexture->szFullPath);
			if(err==1)	//everything went fine
			{
				GenerateGLTexture(aTexture, bMipMapping, iFilterType);
				delete [] (aTexture->data);
			}
			return 0;
		}
		else if(aOpTexFileName)
		{
			SetLoadData(aTexture, aOpTexFileName);
			stBitmapPacket aOpBitmapPacket;
			int err= BuildBitmap(aTexture, &aOpBitmapPacket, aTexture->szFullPath);
			if(err==1)	//everything went fine
			{
				GenerateGLTexture(aTexture, bMipMapping, iFilterType);
				delete [] (aTexture->data);
			}
			return 0;
		}
	}

	return(-1);
}

//const IID IID_IPicture;

int CTextureLoader1::BuildBitmap(stTexture* aTexture, stBitmapPacket* aBitmapPacket, char* aTexAbsolutePath)
{
	//HDC			hdcTemp;												// The DC To Hold Our Bitmap
	//HBITMAP		hbmpTemp;												// Holds The Bitmap Temporarily
	//IPicture	*pPicture;												// IPicture Interface
	OLECHAR		wszPath[MAX_PATH+1];									// Full Path To Picture (WCHAR)
	long		lWidth;													// Width In Logical Units
	long		lHeight;												// Height In Logical Units
	long		lWidthPixels;											// Width In Pixels
	long		lHeightPixels;											// Height In Pixels
	GLint		glMaxTexDim;											// Holds Maximum Texture Size

	//"D://PROJECTS//arun//OBJViewer//DATA//OBJ//images//haycart_destroyed.jpg"
	MultiByteToWideChar(CP_ACP, 0, aTexAbsolutePath, -1, wszPath, MAX_PATH);	// Convert From ASCII To Unicode
	HRESULT hr = OleLoadPicturePath(wszPath,							// Path
		NULL,								// punkCaller
		0,									// Reserved
		0,									// Reserved Transparent Colour
		IID_IPicture,						// riid of Inertface to return
		(void**)&aBitmapPacket->pPicture);					// pointer to returned interface

	if(FAILED(hr))														// If Loading Failed
	{
		return false;													// Return False
	}

	aBitmapPacket->bmp_hdc = CreateCompatibleDC(GetDC(0));								// Create The Windows Compatible Device Context
	if(!aBitmapPacket->bmp_hdc)														// Did Creation Fail?
	{
		aBitmapPacket->pPicture->Release();											// Decrements IPicture Reference Count
		return -1;													// Return False (Failure)
	}

	glGetIntegerv(GL_MAX_TEXTURE_SIZE, &glMaxTexDim);					// Get Maximum Texture Size Supported

	aBitmapPacket->pPicture->get_Width(&lWidth);										// Get IPicture Width (Convert To Pixels)
	lWidthPixels	= MulDiv(lWidth, GetDeviceCaps(aBitmapPacket->bmp_hdc, LOGPIXELSX), 2540);
	aBitmapPacket->pPicture->get_Height(&lHeight);										// Get IPicture Height (Convert To Pixels)
	lHeightPixels	= MulDiv(lHeight, GetDeviceCaps(aBitmapPacket->bmp_hdc, LOGPIXELSY), 2540);

	// Resize Image To Closest Power Of Two
	if (lWidthPixels <= glMaxTexDim) // Is Image Width Less Than Or Equal To Cards Limit
	{
		lWidthPixels = 1 << (int)floor((log((double)lWidthPixels)/log(2.0f)) + 0.5f);
	}
	else  // Otherwise  Set Width To "Max Power Of Two" That The Card Can Handle
	{
		lWidthPixels = glMaxTexDim;
	}

	if (lHeightPixels <= glMaxTexDim) // Is Image Height Greater Than Cards Limit
	{
		lHeightPixels = 1 << (int)floor((log((double)lHeightPixels)/log(2.0f)) + 0.5f);
	}
	else  // Otherwise  Set Height To "Max Power Of Two" That The Card Can Handle
	{
		lHeightPixels = glMaxTexDim;
	}

	// if low quality textures then make them halve the size which saved 4 times the texture space
	if (/*(m_fHighQualityTextures == false) && */0 && (lWidthPixels > 64))
	{
		lWidthPixels *= 0.5f;
		lHeightPixels *= 0.5f;
	}

	//	Create A Temporary Bitmap
	BITMAPINFO	bi = {0};												// The Type Of Bitmap We Request
	DWORD		*pBits = 0;												// Pointer To The Bitmap Bits

	bi.bmiHeader.biSize			= sizeof(BITMAPINFOHEADER);				// Set Structure Size
	bi.bmiHeader.biBitCount		= 24;									// 32 Bit
	bi.bmiHeader.biWidth		= lWidthPixels;							// Power Of Two Width
	bi.bmiHeader.biHeight		= lHeightPixels;						// Make Image Top Up (Positive Y-Axis)
	bi.bmiHeader.biCompression	= BI_RGB;								// RGB Encoding
	bi.bmiHeader.biPlanes		= 1;									// 1 Bitplane

	//	Creating A Bitmap This Way Allows Us To Specify Color Depth And Gives Us Imediate Access To The Bits
	aBitmapPacket->hbmp = CreateDIBSection(aBitmapPacket->bmp_hdc,
		&bi,
		DIB_RGB_COLORS,
		(void**)&pBits,
		0,
		0);

	if(!aBitmapPacket->hbmp)														// Did Creation Fail?
	{
		DeleteDC(aBitmapPacket->bmp_hdc);												// Delete The Device Context
		aBitmapPacket->pPicture->Release();											// Decrements IPicture Reference Count
		return -2;													// Return False (Failure)
	}

	SelectObject(aBitmapPacket->bmp_hdc, aBitmapPacket->hbmp);									// Select Handle To Our Temp DC And Our Temp Bitmap Object

	// Render The IPicture On To The Bitmap
	aBitmapPacket->pPicture->Render(aBitmapPacket->bmp_hdc,
		0,
		0,
		lWidthPixels,
		lHeightPixels,
		0,
		lHeight,
		lWidth,
		-lHeight,
		0);

	//aTexture->data = (BYTE*)pBits;									// Grab The Current Pixel
	BYTE* bmp_data = (BYTE*)pBits;									// Grab The Current Pixel

	long NumPixels = lWidthPixels * lHeightPixels;
	while(NumPixels--)
	{

		BYTE  temp	= bmp_data[0];									// Store 1st Color In Temp Variable (Blue)
		bmp_data[0]	= bmp_data[2];									// Move Red Value To Correct Position (1st)
		bmp_data[2]	= temp;											// Move Temp Value To Correct Blue Position (3rd)
		if(bi.bmiHeader.biBitCount==32)
			bmp_data[3]	= 255;											// Set The Alpha Value To 255

		//--
		if(bOverBright)
		{
			float overbright	= iOverBrightMagnitude;
			float scale = 1.0f;
			float tmp_scale;

			float r = (float)bmp_data[0];
			float g = (float)bmp_data[1];
			float b = (float)bmp_data[2];
			r=r*overbright/255.0f; g=g*overbright/255.0f; b=b*overbright/255.0f;
			if(r>1.0f&&(tmp_scale=(1.0f/r))<scale) scale=tmp_scale;
			if(g>1.0f&&(tmp_scale=(1.0f/g))<scale) scale=tmp_scale;
			if(b>1.0f&&(tmp_scale=(1.0f/b))<scale) scale=tmp_scale;
			scale*=255.0f;
			r*=scale;	g*=scale;	b*=scale;
			bmp_data[0]=r; bmp_data[1]=g; bmp_data[2]=b;
		}
		//--

		if(bi.bmiHeader.biBitCount==32)
			bmp_data		+= 4;
		else if(bi.bmiHeader.biBitCount==24)
			bmp_data		+= 3;
	}

	int aRGB_NoOF_BYTE=bi.bmiHeader.biBitCount/8.0f;
	bmp_data = (BYTE*)pBits;									// Grab The Current Pixel
	aTexture->data = new BYTE[lWidthPixels * lHeightPixels*aRGB_NoOF_BYTE];
	memcpy(aTexture->data, bmp_data, sizeof(BYTE)*lWidthPixels * lHeightPixels*aRGB_NoOF_BYTE);

	aTexture->Width = bi.bmiHeader.biWidth;
	aTexture->Height = bi.bmiHeader.biHeight;
	aTexture->Bpp = bi.bmiHeader.biBitCount;							// Image Color Depth In Bits Per Pixel

	//glGenTextures(1, &pglTexture->TextureID);							// Create The Texture

	// generate the texture using the filtering model selected
	//(void)GenerateTexture(aTexture, (BYTE *)pBits, aMapType);

	DeleteObject(aBitmapPacket->hbmp);												// Delete The Object
	DeleteDC(aBitmapPacket->bmp_hdc);													// Delete The Device Context

	aBitmapPacket->pPicture->Release();												// Decrements IPicture Reference Count

	return 1;														// Return True (All Good)
}

#endif