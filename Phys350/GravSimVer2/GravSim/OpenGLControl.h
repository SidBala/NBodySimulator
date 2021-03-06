#pragma once
#include "afxwin.h"

#include "Include/gl/glew.h"
#include <gl/glu.h>

#include "planetdefs.h"
#include "Scene.h"

#include <vector>
#include "CImg.h"

using namespace cimg_library;

class COpenGLControl : public CWnd
{
	public:
		/******************/
		/* Public Members */
		/******************/
		UINT_PTR m_unpTimer;
		// View information variables
		float	 m_fLastX;
		float	 m_fLastY;
		float	 m_fPosX;
		float	 m_fPosY;
		float	 m_fZoom;
		float	 m_fRotX;
		float	 m_fRotY;
		bool	 m_bIsMaximized;

	private:
		/*******************/
		/* Private Members */
		/*******************/
		// Window information
		CWnd  *hWnd;
		HDC   hdc;			
		HGLRC hrc;			
		int   m_nPixelFormat;
		CRect m_rect;
		CRect m_oldWindow;
		CRect m_originalRect;

		//SkyBox Textures
		GLuint SkyTex;

	public:
		COpenGLControl(void);
		virtual ~COpenGLControl(void);

		void oglCreate(CRect rect, CWnd *parent);
		void oglInitialize(void);
		void oglDrawScene(CScene *Scene);
		void oglLoadSkyBoxTextures();
		void oglRenderSkybox(CVec3 position,CVec3 size);

		// Added message classes:
		afx_msg void OnPaint();
		afx_msg void OnSize(UINT nType, int cx, int cy);
		afx_msg	void OnDraw(CDC *pDC);
		afx_msg int  OnCreate(LPCREATESTRUCT lpCreateStruct);
		afx_msg void OnTimer(UINT nIDEvent);
		afx_msg void OnMouseMove(UINT nFlags, CPoint point);

		DECLARE_MESSAGE_MAP()
};