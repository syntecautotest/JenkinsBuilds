// Graphics3d.h: interface for the CGraphics3d class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GRAPHICS3D_H__83719FF4_F51D_4345_9C56_13E3EB900FDB__INCLUDED_)
#define AFX_GRAPHICS3D_H__83719FF4_F51D_4345_9C56_13E3EB900FDB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Cube3d.h"
#include "Rectangle.h"

class CLine3d;
class CArc3d;
class CPoint3d;
class CPoint2d;
class IGraphicsPeer;

#if !defined(STRUCT_POINT_W)
#define STRUCT_POINT_W

typedef struct tagPOINT_W {
   double x;
   double y;
   double z;
} POINT_W;

#endif // STRUCT_POINT_W

class CGraphics3d
{
public:
	CGraphics3d();
	// construtcor

	virtual ~CGraphics3d();
	// destructor

	void setGraphicsPeer( IGraphicsPeer *pGraphicsPeer );
	// set associated graphics peer

	IGraphicsPeer *getGraphicsPeer( void );
	// get associated graphics peer

	COLORREF setTextColor( COLORREF crColor );
	// This function sets the text color of the specified device context to the
	// specified color.
	// A color reference for the previous text color indicates success.
	// CLR_INVALID indicates failure.

	COLORREF getTextColor( void );
	// This function sets the text color of the specified device context to the
	// specified color.
	// A color reference for the previous text color indicates success.
	// CLR_INVALID indicates failure.

	int setBkMode( int iBkMode );
	// This function sets the background mix mode of the specified device context.
	// If the function succeeds, the return value specifies the previous background mode.
	// If the function fails, the return value is zero.

	void drawLine( LONG x1, LONG y1, LONG x2, LONG y2 );
	// Draws a line, using the current color, between the points
	// (x1, y1) and (x2, y2) in this graphics context's coordinate system. 

	void fillRect( LONG x, LONG y, LONG width, LONG height );
	// Draws the outline of the specified rectangle. The left and right
	// edges of the rectangle are at x and x + width. The top and bottom
	// edges are at y and y + height. The rectangle is drawn using the
	// graphics context's current color.

	void fillRect( CRectangle &r );
	// Draws the outline of the specified rectangle. The rectangle is drawn
	// using the graphics context's current color.

	void eraseBackground( void );
	// erase background

	int setLineStyle( int style );
	// Sets this graphics context's line style to the specified line style.
	// All subsequent line-drawings operations using this graphics context use
	// this specified linestyle.

	int getLineStyle( void );
	// Gets this graphics context's line style.

	LONG setLineWidth( LONG nWidth );
	// Sets this graphics context's line style to the specified line style.
	// All subsequent line-drawings operations using this graphics context use
	// this specified linestyle.

	LONG getLineWidth( void );
	// Gets this graphics context's line style.

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

	void drawRect( LONG x, LONG y, LONG width, LONG height );
	// Draws the outline of the specified rectangle. The left and right edges
	// of the rectangle are at x and x + width. The top and bottom edges are
	// at y and y + height. The rectangle is drawn using the graphics context's
	// current color.

	void drawRect( CRectangle &r );
	// Draws the outline of the specified rectangle. The rectangle is drawn using
	// the graphics context's current color.

	COLORREF ScaleColor( COLORREF color, int Multiplier, int Divider );
	// scale color

	int getViewpointMode( void );
	// get view point mode

	double getHorzontalAngle( void );
	// get rotation angle along horzontal line.

	double getVerticalAngle( void );
	// get rotation angle along vertical line.

	void getMargin( CCube3d &c );
	// get current margin size

	void setMargin( CCube3d &c );
	// set object margin
	// return TRUE when the cubes is modified, otherwise FALSE.

	void getVisibleWindow( CRectangle::CDouble &w );
	// to get visible window

	int putViewOrientation( int orientation );
	// set view orientation

	int getViewOrientation( void );
	// get view orientation

	void setViewPort( CRectangle &v );
	// set 2d viewport

	void getViewPort( CRectangle &v );
	// get 2d viewport

	void setZoomPort( CRectangle &zp );
	// set zoom port, the zoom port is relative current view port.

	BOOL cancelZoom( void );
	// cancel zoom function

	BOOL zoomBack( void );
	// zoom back function

	void setViewpointMode( int mode );
	// set view point mode

	void setHorzontalAngle( double angle );
	// rotation angle along horzontal line, the
	// ( 1.0/sqrt(2.0), -1.0/sqrt(2.0), 0.0 ) axis.
	// this angle only take effect under VPMODE_XYZ mode

	void setVerticalAngle( double angle );
	// rotation angle along vertical line, the ( 0.0, 0.0, 1.0 ) axis
	// this angle only take effect under VPMODE_XYZ mode

	void getObjectTranform( double a[] );
	// to get current object transform matrix into specified matrix
	// the data sequence is a11, a12, a13, a14, a21, a22, .., a41, a42, a43, a44.
	// the translation vector is (a14,a24,a34)

	void setObjectTransform( double a[] );
	// to set current object transform matrix from specified matrix
	// the data sequence is a11, a12, a13, a14, a21, a22, .., a41, a42, a43, a44.
	// the translation vector is (a14,a24,a34)

	double drawText( LPCTSTR lpString, int nCount, CRectangle::CDouble &w, UINT uFormat );
	// This function draws formatted text in the specified rectangle.
	// It formats the text according to the specified format method.
	// The height of the text indicates success. Zero indicates failure

	BOOL Polyline( const POINT_W *lpPoints, int nCount );
	// This function draws a series of line segments by connecting the points
	// in the specified array.
	// Return: Nonzero indicates success. Zero indicates failure.

	BOOL Polygon( const POINT_W *lpPoints, int nCount );
	// This function draws a polygon consisting of two or more vertices connected
	// by straight lines. Outlines the polygon using current line color, and fills
	// it using the specified polygon fill mode.
	// Return: Nonzero indicates success. Zero indicates failure.

	void drawShape( CLine3d &l );
	// Draws a line, using the current color, which defined in line object with object transform
	// draw on 3d canvas

	void drawShape( CArc3d &a );
	// Draw a arc, using the current color, which defined in arc object with object transform
	// draw on 3d canvas

	void fillShape( CArc3d &a );
	// Fill a arc, using the current color, which defined in arc object with object transform
	// draw on 3d canvas

	void drawShape3d( CLine3d &l );
	// Draws a line, using the current color, which defined in line object without object transform
	// draw on 3d canvas

	void drawShape2d( CLine3d &l );
	// Draws a line, using the current color, which defined in line object
	// draw on 2d canvas

	LONG LPtoDP2d( double length );
	// The LPtoDP2d function converts logical coordinates into device coordinates

	void LPtoDP3d( CPoint3d &p );
	// The LPtoDP3d function converts logical coordinates into device coordinates without object transform

	void LPtoDP( CPoint3d &p );
	// The LPtoDP3d function converts logical coordinates into device coordinates with object transform

	HBITMAP GetBitmapData( JRECT *lpRect );
	// get screen bitmap data, associated to assign Rect

	void DrawBitmapData( JRECT *lpRect, HBITMAP bitmap );
	// draw bitmap, associated to assign Rect

	enum EMaxZoomScale {
		MAX_ZOOMSCALE = 5000,
		SIZE_ShapeSegment = 5120		// unit: # of points
	};

private:
	CCube3d m_margin;
	// geometry object margin

	CRectangle m_viewport;
	// 2-dimensional viewport size in device coordinate

	int m_ViewpointMode;
	// current viewpoint mode

	int m_nViewOrientation;
	// view orientation

	double m_VerticalAngle;
	double m_HorzontalAngle;
	// horzontal angle is rotate along
	// ( 1.0/sqrt(2.0), -1.0/sqrt(2.0), 0.0 ) axis
	// vertical angle is rotate along ( 0.0, 0.0, 1.0) axis

	CRectangle::CDouble m_ObjectWindow;
	// 2-dimensional object window size in world coordinate(before zoom)

	CRectangle::CDouble m_VisibleWindow;
	// 2-dimensional visible window size in world coordinate(after zoom)

	double m_flatness;
	// the flatness, this should be update when window-to-viewport changed

	CMatrix4d m_Tobj;		// object transformation
	CMatrix4d m_Tvp;		// viewpoint transformation matrix
	CMatrix4d m_Tw2v;		// window to viewport transformation matrix
	CMatrix4d m_Tzoom;		// zoom function matrix

	CMatrix4d m_Tsum;		// the whole effect of above three matrix
	CMatrix4d m_Tsum3d;		// the whole effect of above three matrix
	CMatrix4d m_Tsum2d;		// the effect of Tw2v and Tzoom

	CMatrix4d m_TInvSum2d;	// inverse of m_Tsum2d

	POINT *m_pShapeBuf;		// shape segment buffer

	IGraphicsPeer *m_pGraphicsPeer;
	// associate graphics peer

	void syncObjectState( void );
	// synchronize object state

	void updateTvp( void );
	// re-calculate viewpoint matrix, Tvp, the method should be called
	// when viewpoint mode, view angle changed.

	void updateObjectWindow( void );
	// re-calculte object windows size, the method should be called when
	// object margin change or viewport change.

	void updateVisibleWindow( void );
	// re-calculte visible windows size, the method should be called when
	// object margin change or viewport change.

	void updateFlatness( void );
	// re-calculte flatness, the method should be called when object margin
	// change, viewport change, or zoom port change.

	void updateTw2v( void );
	// re-calculate window-to-viewport matrix, Tw2v, the method should be
	// called when visible window or viewport changed.

	void updateTsum( void );
	// re-calculate Tsum matrix, Tsum, the method should be called when
	// any sub-transformation matrix changed.

	void updateIsoviewTvp( void );
	// re-calculate isomorphic viewpoint transformation matrix

	void drawShape( IPathIterator *pPathIterator );
	// Draws a shape, using the current color, which defined in path iterator

	void fillShape( IPathIterator *pPathIterator );
	// Fills a shape, using the current line/fill color, which defined in path iterator

private:
	class CTxHistory
	{
	public:
		CTxHistory();
		virtual ~CTxHistory();

		void clear( void );
		BOOL push( CMatrix4d *lpTx );
		BOOL pop( CMatrix4d *lpTx );
		BOOL isEmpty( void );
	private:
		struct TTxNode {
			CMatrix4d *lpTx;
			TTxNode *lpNext;
		};

		TTxNode *m_TxHistory;
	};

private:
	CTxHistory m_objZoomHistory;

};

#endif // !defined(AFX_GRAPHICS3D_H__83719FF4_F51D_4345_9C56_13E3EB900FDB__INCLUDED_)
