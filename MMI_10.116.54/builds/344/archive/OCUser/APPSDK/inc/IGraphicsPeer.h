// IGraphicsPeer.h: interface for the IGraphicsPeer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IGRAPHICSPEER_H__4433C05D_5D31_4AD1_B16C_F251B0F20ECE__INCLUDED_)
#define AFX_IGRAPHICSPEER_H__4433C05D_5D31_4AD1_B16C_F251B0F20ECE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "nstdlib.h"

class IXPaintable;
class CRectangle;

class SWINGAPI IGraphicsPeer  
{
public:
	enum EImageAlignment {
		IMAGEALIGN_TopLeft = 1,
		IMAGEALIGN_TopCenter,
		IMAGEALIGN_TopRight,
		IMAGEALIGN_Left,
		IMAGEALIGN_Center,
		IMAGEALIGN_Right,
		IMAGEALIGN_BottomLeft,
		IMAGEALIGN_BottomCenter,
		IMAGEALIGN_BottomRight
	};

	virtual int setFontSize( int nSize ) = 0;
	// to set font size

	virtual HJFONT getFontHandle( void ) = 0;
	// to get font handle with specified size

	virtual COLORREF setTextColor( COLORREF crColor ) = 0;
	// This function sets the text color of the specified device context to the
	// specified color.
	// A color reference for the previous text color indicates success.
	// CLR_INVALID indicates failure.

	virtual COLORREF getTextColor( void ) = 0;
	// This function gets the text color of the specified device context to the
	// specified color.
	// A color reference for the previous text color indicates success.
	// CLR_INVALID indicates failure.

	virtual int setBkMode( int iBkMode ) = 0;
	// This function sets the background mix mode of the specified device context.
	// If the function succeeds, the return value specifies the previous background mode.
	// If the function fails, the return value is zero.

	virtual BOOL getTextExtentPoint( LPCTSTR lpString, int cbString, LPSIZE lpSize ) = 0;
	// computes the width and height of the specified string of text.
	// If the function succeeds, the return value is nonzero.

	virtual BOOL getImageSize( LPCTSTR lpszFilename, SIZE* ) = 0;

	virtual void drawImage( LPCTSTR lpszFilename, LPJRECT lpRect, int Alignment, BOOL bEnableState ) = 0;
	virtual void drawImage( LPCTSTR lpszFilename, LPJRECT lpRect, int Alignment, BOOL bEnableState, float HStretch, float VStretch ) = 0;
	// to draw image picture at specified position

	virtual int drawText( LPCTSTR lpString, int nCount, CRectangle &Rect, UINT uFormat ) = 0;
	// This function draws formatted text in the specified rectangle.
	// It formats the text according to the specified format method.
	// The height of the text indicates success. Zero indicates failure

	virtual int drawText( LPCTSTR lpString, int nCount, LPJRECT lpRect, UINT uFormat ) = 0;
	// This function draws formatted text in the specified rectangle.
	// It formats the text according to the specified format method.
	// The height of the text indicates success. Zero indicates failure

	virtual int drawEngraveText( LPCTSTR lpString, int nCount, CRectangle &Rect, UINT uFormat ) = 0;
	// This function draws disable formatted text in the specified rectangle.
	// It formats the text according to the specified format method.

	virtual int drawEngraveText( LPCTSTR lpString, int nCount, LPJRECT lpRect, UINT uFormat ) = 0;
	// This function draws disable formatted text in the specified rectangle.
	// It formats the text according to the specified format method.
	// The height of the text indicates success. Zero indicates failure

	virtual void drawFrameControl( LPJRECT rc, UINT uType, UINT uState ) = 0;
	// This function draws frame control.

	virtual void Stretch( LPJRECT rcSource, LPJRECT rcDestnation ) = 0;
	// stretch from rcSource to rcDestnation

	virtual void fillRect( LONG x, LONG y, LONG width, LONG height ) = 0;
	// Draws the outline of the specified rectangle. The left and right
	// edges of the rectangle are at x and x + width. The top and bottom
	// edges are at y and y + height. The rectangle is drawn using the
	// graphics context's current color.

	virtual void eraseBackground( void ) = 0;
	// erase background

	virtual BOOL Polyline( const POINT *lppt, int cPoints ) = 0;
	// This function draws a series of line segments by connecting the points
	// in the specified array.
	// Return: Nonzero indicates success. Zero indicates failure.

	virtual BOOL Polygon( const POINT *lpPoints, int nCount ) = 0;
	// This function draws a polygon consisting of two or more vertices connected
	// by straight lines. Outlines the polygon using current line color, and fills
	// it using the specified polygon fill mode.
	// Return: Nonzero indicates success. Zero indicates failure.

	virtual int setLineStyle( int style ) = 0;
	// Sets this graphics context's line style to the specified line style.
	// All subsequent line-drawings operations using this graphics context use
	// this specified linestyle.

	virtual int getLineStyle( void ) = 0;
	// Gets this graphics context's line style.

	virtual LONG setLineWidth( LONG nWidth ) = 0;
	// to set line width

	virtual LONG getLineWidth( void ) = 0;
	// to get line width

	virtual COLORREF setLineColor( COLORREF color ) = 0;
	// Sets this graphics context's current color to the specified color.
	// All subsequent graphics operations using this graphics context use
	// this specified color.

	virtual COLORREF getLineColor( void ) = 0;
	// Gets this graphics context's current color.

	virtual COLORREF setFillColor( COLORREF color ) = 0;
	// Sets this graphics context's current color to the specified color.
	// All subsequent graphics operations using this graphics context use
	// this specified color.

	virtual COLORREF getFillColor( void ) = 0;
	// Gets this graphics context's current color.

	virtual COLORREF setBackgroundColor( COLORREF color ) = 0;
	// Sets the current background color to the specified color.

	virtual COLORREF getBackgroundColor( void ) = 0;
	// get background color

	virtual void setPaintMode( void ) = 0;
	// Sets the paint mode of this graphics context to overwrite the
	// destination with this graphics context's current color. This sets
	// the logical pixel operation function to the paint or overwrite mode.
	// All subsequent rendering operations will overwrite the destination
	// with the current color.

	virtual void setXORMode( void ) = 0;
	// Sets the paint mode of this graphics context to alternate between
	// this graphics context's current color and the new specified color.
	// This specifies that logical pixel operations are performed in the XOR mode,
	// which alternates pixels between the current color and a specified XOR color.

	virtual void getClientRect( CRectangle *pRect ) = 0;
	// get client rectangle

	virtual void getClientRect( JRECT *lpRect ) = 0;
	// get client rectangle

	virtual void repaint( void ) = 0;
	// request to update client area

	virtual BOOL notifyParent( UINT code ) = 0;
	// Places a message in the window¡¦s message queue and then returns
	// without waiting for the corresponding window to process the message.
	// return nonzero if the message is posted; otherwise 0.

	virtual BOOL isPaintable( void ) = 0;
	// query whether window paintable

	virtual void setComponent( IXPaintable *pComponent ) = 0;
	// set associated component

	virtual void flush( void ) = 0;
	// flush cache

	virtual void invalidateRect( LPCJRECT lpRect ) = 0;
	// invalidate specified window

	virtual void eraseBackgroundRect( LPCJRECT lpRect ) = 0;
	// erase specified background rectangle


	virtual void SaveBitmap( JRECT *lpRect, TCHAR* pFileName) = 0;
	// draw a Chord

	virtual void drawBitmap( JRECT *lpRect, TCHAR* pFileName, int& iImageIndex ) = 0;

	virtual void drawEllipse(JRECT *lpRect) = 0;

	virtual HWND getWnd() = 0;

	virtual HBITMAP GetBitmapData( JRECT *lpRect ) = 0;
	// get screen bitmap data, associated to assign Rect

	virtual void DrawBitmapData( JRECT *lpRect, HBITMAP bitmap ) = 0;
	// draw bitmap, associated to assign Rect

};

#endif // !defined(AFX_IGRAPHICSPEER_H__4433C05D_5D31_4AD1_B16C_F251B0F20ECE__INCLUDED_)
