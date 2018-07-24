// GraphicsDef.h: interface for the CGraphicsDef class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GRAPHICSDEF_H__6D56B7E4_3456_4506_A509_A020A3E65D8C__INCLUDED_)
#define AFX_GRAPHICSDEF_H__6D56B7E4_3456_4506_A509_A020A3E65D8C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CGraphicsDef  
{
public:
	// constant for color
#if defined(WIN32) || defined(_WIN32_WCE)
	enum EColor {
		COLOR_BLACK			= 0x00000000,
		COLOR_BLUE			= 0x00800000,
		COLOR_GREEN			= 0x00008000,
		COLOR_CYAN			= 0x00808000,
		COLOR_RED			= 0x00000080,
		COLOR_MAGENTA		= 0x00800080,
		COLOR_BROWN			= 0x00008080,
		COLOR_WHITE			= 0x00C0C0C0,
		COLOR_GRAY			= 0x00808080,
		COLOR_LIGHTBLUE		= 0x00FF0000,
		COLOR_LIGHTGREEN	= 0x0000FF00,
		COLOR_LIGHTCYAN		= 0x00FFFF00,
		COLOR_LIGHTRED		= 0x000000FF,
		COLOR_LIGHTMAGENTA	= 0x00FF00FF,
		COLOR_YELLOW		= 0x0000FFFF,
		COLOR_BRIGHTWHITE	= 0x00FFFFFF
	};
#else // defined(WIN32) || defined(_WIN32_WCE)
	enum EColor {
		COLOR_BLACK = 0,		// 0
		COLOR_BLUE,				// 1
		COLOR_GREEN,			// 2
		COLOR_CYAN,				// 3
		COLOR_RED,				// 4
		COLOR_MAGENTA,			// 5
		COLOR_BROWN,			// 6
		COLOR_WHITE,			// 7
		COLOR_GRAY,				// 8
		COLOR_LIGHTBLUE,		// 9
		COLOR_LIGHTGREEN,		// 10
		COLOR_LIGHTCYAN,		// 11
		COLOR_LIGHTRED,			// 12
		COLOR_LIGHTMAGENTA,		// 13
		COLOR_YELLOW,			// 14
		COLOR_BRIGHTWHITE		// 15
	};
#endif // defined(WIN32) || defined(_WIN32_WCE)

	// constant for line style
	enum ELineStyle {
		LINESTYLE_SOLID = PS_SOLID,
		LINESTYLE_DASH = PS_DASH,
#if defined(UNDER_CE)
		LINESTYLE_DOT = PS_DASH,
#else
		LINESTYLE_DOT = PS_DOT,
#endif // defined(UNDER_CE)
		LINESTYLE_NULL = PS_NULL,
	};

	// constant definition for viewpoint mode
	enum EViewpointMode {
		VPMODE_XYZ = 0,
		VPMODE_XY,
		VPMODE_YZ,
		VPMODE_ZX,
		VPMODE_YX,
		VPMODE_ZY,
		VPMODE_XZ
	};

	// constant definition for view orientation mode
	enum EViewOrientation {
		VORIENT_Normal = 0,
		VORIENT_XMirror,
		VORIENT_XYMirror,
		VORIENT_YMirror
	};
};

#endif // !defined(AFX_GRAPHICSDEF_H__6D56B7E4_3456_4506_A509_A020A3E65D8C__INCLUDED_)
