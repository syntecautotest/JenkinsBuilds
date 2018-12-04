// Win32GraphicsPeer.h: interface for the CWin32GraphicsPeer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WIN32GRAPHICSPEER_H__55F1EDD6_F469_40D4_947D_4E3896C661A9__INCLUDED_)
#define AFX_WIN32GRAPHICSPEER_H__55F1EDD6_F469_40D4_947D_4E3896C661A9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class COCImage;
class CPenPool;
class CBrushPool;
class CFontPool;

#include "IGraphicsPeer.h"

class CWin32GraphicsPeer : public IGraphicsPeer  
{
public:
	static long m_nLocaleID;
	static void set_LocaleID( long nLocaleID );

public:
	CWin32GraphicsPeer();
	virtual ~CWin32GraphicsPeer();

	void OnCreate( HWND hWnd );
	// on create event

	void OnDestroy( HWND hWnd );
	// on destroy event

	void OnSize( HWND hWnd, UINT nType, int cx, int cy );
	// on size event

	void OnPaint( HDC hPaintDC, const RECTL *r );
	// update device content

	void setFont( LPLOGFONT lplogFont );
	// set logic font specification

	int setFontSize( int nSize );
	// to set font size, in points

	HJFONT getFontHandle( void );
	// to get font handle with specified size

	HDC getDC( void );
	// to get device context

	void CWin32GraphicsPeer::setDC( HDC mhdc );
	// to set device context

	COLORREF setTextColor( COLORREF crColor );
	// This function sets the text color of the specified device context to the
	// specified color.
	// A color reference for the previous text color indicates success.
	// CLR_INVALID indicates failure.

	COLORREF getTextColor( void );
	// This function gets the text color of the specified device context to the
	// specified color.
	// A color reference for the previous text color indicates success.
	// CLR_INVALID indicates failure.

	int setBkMode( int iBkMode );
	// This function sets the background mix mode of the specified device context.
	// If the function succeeds, the return value specifies the previous background mode.
	// If the function fails, the return value is zero.

	BOOL getTextExtentPoint( LPCTSTR lpString, int cbString, LPSIZE lpSize );
	// computes the width and height of the specified string of text.
	// If the function succeeds, the return value is nonzero.

	void drawImage( LPCTSTR lpszFilename, LPJRECT lpRect, int Alignment, BOOL bEnableState, float HStretch, float VStretch );
	void drawImage( LPCTSTR lpszFilename, LPJRECT lpRect, int Alignment, BOOL bEnableState );
	// to draw image picture at specified position

	BOOL getImageSize( LPCTSTR lpszFilename, SIZE* );
	int drawText( LPCTSTR lpString, int nCount, CRectangle &Rect, UINT uFormat );
	// This function draws formatted text in the specified rectangle.
	// It formats the text according to the specified format method.

	int drawText( LPCTSTR lpString, int nCount, LPJRECT lpRect, UINT uFormat );
	// This function draws formatted text in the specified rectangle.
	// It formats the text according to the specified format method.
	// The height of the text indicates success. Zero indicates failure

	int drawEngraveText( LPCTSTR lpString, int nCount, CRectangle &Rect, UINT uFormat );
	// This function draws disable formatted text in the specified rectangle.
	// It formats the text according to the specified format method.

	int drawEngraveText( LPCTSTR lpString, int nCount, LPJRECT lpRect, UINT uFormat );
	// This function draws disable formatted text in the specified rectangle.
	// It formats the text according to the specified format method.
	// The height of the text indicates success. Zero indicates failure

	void drawFrameControl( LPJRECT rc, UINT uType, UINT uState );
	// This function draws frame control.

	void Stretch( LPJRECT rcSource, LPJRECT rcDestnation );
	// stretch from rcSource to rcDestnation

	void fillRect( LONG x, LONG y, LONG width, LONG height );
	// Draws the outline of the specified rectangle. The left and right
	// edges of the rectangle are at x and x + width. The top and bottom
	// edges are at y and y + height. The rectangle is drawn using the
	// graphics context's current color.

	void eraseBackground( void );
	// erase background

	BOOL Polyline( const POINT *lpPoints, int nCount );
	// This function draws a series of line segments by connecting the points
	// in the specified array.
	// Return: Nonzero indicates success. Zero indicates failure.

	BOOL Polygon( const POINT *lpPoints, int nCount );
	// This function draws a polygon consisting of two or more vertices connected
	// by straight lines. Outlines the polygon using current line color, and fills
	// it using the specified polygon fill mode.
	// Return: Nonzero indicates success. Zero indicates failure.

	int setLineStyle( int style );
	// Sets this graphics context's line style to the specified line style.
	// All subsequent line-drawings operations using this graphics context use
	// this specified linestyle.

	int getLineStyle( void );
	// Gets this graphics context's line style.

	LONG setLineWidth( LONG nWidth );
	// to set line width

	LONG getLineWidth( void );
	// to get line width

	COLORREF setBackgroundColor( COLORREF color );
	// Sets the current background color to the specified color.

	COLORREF getBackgroundColor( void );
	// get background color

	COLORREF setLineColor( COLORREF color );
	// Sets this graphics context's current color to the specified color.
	// All subsequent graphics operations using this graphics context use
	// this specified color.

	COLORREF getLineColor( void );
	// Gets this graphics context's current color.

	COLORREF setFillColor( COLORREF color );
	// Sets this graphics context's current color to the specified color.
	// All subsequent graphics operations using this graphics context use
	// this specified color.

	COLORREF getFillColor( void );
	// Gets this graphics context's current color.

	void setPaintMode( void );
	// Sets the paint mode of this graphics context to overwrite the
	// destination with this graphics context's current color. This sets
	// the logical pixel operation function to the paint or overwrite mode.
	// All subsequent rendering operations will overwrite the destination
	// with the current color.

	void setXORMode( void );
	// Sets the paint mode of this graphics context to alternate between
	// this graphics context's current color and the new specified color.
	// This specifies that logical pixel operations are performed in the XOR mode,
	// which alternates pixels between the current color and a specified XOR color.

	void getClientRect( CRectangle *pRect );
	// get client rectangle

	void getClientRect( JRECT *lpRect );
	// get client rectangle

	void repaint( void );
	// request to update client area

	BOOL notifyParent( UINT code );
	// Places a message in the window¡¦s message queue and then returns
	// without waiting for the corresponding window to process the message.
	// return nonzero if the message is posted; otherwise 0.

	BOOL isPaintable( void );
	// query whether window paintable

	void setComponent( IXPaintable *pComponent );
	// set associated component

	void flush( void );
	// flush cache

	void invalidateRect( LPCJRECT lpRect );
	// invalidate specified window

	void eraseBackgroundRect( LPCJRECT lpRect );
	// erase specified background rectangle

	void SaveBitmap( JRECT *lpRect, TCHAR* pFileName );
	//save screen to a bitmap picture

	void drawBitmap( JRECT *lpRect, TCHAR* pFileName, int& iImageIndex );
	// load bitmap picture to screen

	void drawEllipse(JRECT *lpRect);
	// draw a Ellipse

	HBITMAP GetBitmapData( JRECT *lpRect );
	// get screen bitmap data, associated to assign Rect

	void DrawBitmapData( JRECT *lpRect, HBITMAP bitmap );
	// draw bitmap, associated to assign Rect

	HWND getWnd();

	void ExpandArraySize(HBITMAP* pHBitmap, UINT uiOld, UINT uiNew);

	HWND			m_hWnd;
	// associated window handle

	HDC				m_hMemDC;
	// associated in-memory device DC

	HBITMAP* m_hImage; 
	// keep Image Handle to memory

	int m_iImageCount;
	// record the gdi's Image picture 

private:
	HBITMAP			m_hBitmap;
	HBITMAP			m_hPrevBitmap;

	// background attribute
	COLORREF		m_crBack;

	// line attribute
	COLORREF		m_crLine;
	int				m_nPenStyle;
	LONG			m_nLineWidth;
	HPEN			m_hOldPen;
	HPEN			m_hPen;
	POINT			*m_lpPtBuffer;

	// fill attribute
	COLORREF		m_crFill;
	HBRUSH			m_hOldBrush;
	HBRUSH			m_hBrush;

	// font attribute
	int				m_nFontSize;	// font size, in points
	LOGFONT			m_logFont;
	HFONT			m_hOldFont;
	HFONT			m_hFont;

	BOOL			m_fXorMode;

	IXPaintable		*m_pComponent;

	RECT			m_rcCanvas;

	BOOL			m_bInvalidate;

	void preparePenTool( void );
	// perpare pen tool

	void prepareBrushTool( void );
	// perpare brush tool

	void prepareFontTool( void );
	// perpare font tool

	void releaseGDITool( void );
	// release GDI tool

	static COCImage m_ImageBrushPool;
	// global shared image pool

	static CPenPool	m_PenPool;
	// global shared pen pool

	static CBrushPool m_BrushPool;
	// global shared solid brush pool

	static CFontPool m_FontPool;
	// global shared font pool

	LONG calcFontHeight( LONG nPoint );
	// convert point into character height
};

#endif // !defined(AFX_WIN32GRAPHICSPEER_H__55F1EDD6_F469_40D4_947D_4E3896C661A9__INCLUDED_)
