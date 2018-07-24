// XPathSimuBase.h: interface for the CXPathSimuBase class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_XPATHSIMUBASE_H__A6AC7D7F_B359_45DD_9D2F_C47514DD4D53__INCLUDED_)
#define AFX_XPATHSIMUBASE_H__A6AC7D7F_B359_45DD_9D2F_C47514DD4D53__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "nstdlib.h"
#include "XComponent.h"
#include "ISimuEvent.h"
#include "IAlarmStore.h"
#include "swing.h"
#include "CommonStruct.h"

class CSimuStorage;
class CXSmDrawer;
class CXSmCursor;
class CXSmZoom;
class ISimulator;
class CGraphics3d;
class IWndSite;

class SWINGAPI CXPathSimuBase : 
	public CXComponent,
	public CSimuEventAdapter
{
public:
	// constant for system type
	enum ESysType {
		SYSTYPE_LATHE,				// lathe system
		SYSTYPE_MILL,				// mill system
		SYSTYPE_WCUT				// wcut system
	};

	enum EDrawMode {
		DRAWMODE_Simulation,		// by graphics simulation
		DRAWMODE_DirectDraw,		// by direct drawing at run time
		DRAWMODE_NoSimulation		// do nothing
	};
	// draw mode

	enum ENotifyCode {

		// start of simulation drawing
#if defined(WIN32) || defined(_WIN32_WCE)
		PSN_DRAWBEGIN = 0,
#else // defined(WIN32) || defined(_WIN32_WCE)
		PSN_DRAWBEGIN = 0x0400,	// WN_USER == 0x0400 defined in mmibase.h
#endif // defined(WIN32) || defined(_WIN32_WCE)

		PSN_DRAWEND,					// end of simulation drawing
		PSN_ZOOMENTER,					// enter zoom mode
		PSN_ZOOMLEAVE					// leave zoom mode
	};
	// notify code

	enum EOpMode {
		OPMODE_Simulation,
		OPMODE_Monitor,
		OPMODE_Browsing,
		OPMODE_DirectDraw,
		OPMODE_NoSimulation
	};
	// operation mode constant

public:
	CXPathSimuBase();
	// constructor

	virtual ~CXPathSimuBase();
	// destructor

	void setISimulator( ISimulator *pSimulator );
	// set simulator

	void setSearchPath( char *pPath );
	// assign search path for simulation

	void getSearchPath( char *pBuffer );
	// get search path for simulation

	void startZoom( void );
	// start zoom function

	void setProgramName( char *filename );
	// set program name

	void getProgramName( char *buffer, int count );
	// get program name

	void SetDrawRange( long nStart_N, long nEnd_N, long nStart_L, long nEnd_L );
	// set draw range

	void invalidateMargin( void );
	// invalidate margin

	void play( void );
	// start to simulate new program

	void playWithMargin(
		double xmin,
		double ymin,
		double zmin,
		double xmax,
		double ymax,
		double zmax
	);

	void pause( void );
	// remume simulator

	void step( void );
	// single step one block

	void undostep( void );
	// single undostep one block

	void resume( void );
	// resume drawing for zoom

	void replay( void );
	// update graphic after some setting has been changed

	void abort( void );
	// abort current function, zoom or angle adjustment

	void moveto( double x, double y, double z );
	// move cursor to specified position

	void moveto( long position[] );
	// move cursor to specified position, by LIU

	int putOpMode( int mode );
	// put operation mode

	int getOpMode( void );
	// get operation mode

	int putQuadrant( int quadrant );
	// put quadrant

	int getQuadrant( void );
	// get quadrant

	COLORREF putLineColor( COLORREF crColor );
	// set line color

	COLORREF putGridColor( COLORREF crColor );
	// set grid color

	COLORREF putTextColor( COLORREF crColor );
	// set text color

	COLORREF putRapidColor( COLORREF crColor );
	// set rapid(G00) color

	COLORREF putFrameColor( COLORREF crColor );
	// set frame(caret) color

	COLORREF putCaretColor( COLORREF crColor );
	// set caret color

	COLORREF getLineColor( void );
	// set line color

	COLORREF getGridColor( void );
	// set grid color

	COLORREF getTextColor( void );
	// set text color

	COLORREF getRapidColor( void );
	// set Rapid(G00) color

	COLORREF getFrameColor( void );
	// set frame(caret) color

	COLORREF getCaretColor( void );
	// set caret color

	BOOL putGridVisible( BOOL bVisible );
	// put grid visible flag

	BOOL getGridVisible( void );
	// get grid visible flag

	int putRapidLineStyle( int linestyle );
	// set rapid travel line style

	int getRapidLineStyle( void );
	// get rapid travel line style

	long put_GridUnitMode( long nMode );
	// to set grid unit mode: 0 for metric, 1 for inch

	long get_GridUnitMode( void );
	// to get grid unit mode: 0 for metric, 1 for inch

	void setViewpointMode( int mode );
	// set view point mode

	DWORD advise( ISimuEvent *pListener );
	// to advise event listener

	void unadvise( DWORD dwCookie );
	// to unadvise event listener

	void setMargin(
		double xmin,
		double ymin,
		double zmin,
		double xmax,
		double ymax,
		double zmax
	);
	// set object margin

	void setHorzontalAngle( double angle );
	// rotation angle along horzontal line, the
	// ( 1.0/sqrt(2.0), -1.0/sqrt(2.0), 0.0 ) axis.
	// this angle only take effect under VPMODE_XYZ mode

	double getHorzontalAngle( void );
	// rotation angle along horzontal line, the
	// ( 1.0/sqrt(2.0), -1.0/sqrt(2.0), 0.0 ) axis.
	// this angle only take effect under VPMODE_XYZ mode

	void setVerticalAngle( double angle );
	// rotation angle along vertical line, the ( 0.0, 0.0, 1.0 ) axis
	// this angle only take effect under VPMODE_XYZ mode

	double getVerticalAngle( void );
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

	void LPtoDP( double ptPoint3d[] );
	// to do 3d point logic coordinate to device coordinate transformation.

	int getViewpointMode( void );
	// get current view point mode

	void getMargin(
		double &xmin,
		double &ymin,
		double &zmin,
		double &xmax,
		double &ymax,
		double &zmax
	);
	// get object margin

	void cancelZoom( void );
	// reset all zoom factor

	void ZoomBack( void );
	// reset all zoom factor

	void toggleZoomFrame( void );
	// toggle zoom frame

	void offZoomFrame( void );
	// off zoom operation frame

	void getProgramPosition( double position[] );
	// get program position
	// position		an array of size NUMOF_AXIS

	void getProgramAxisName( int AxisName[] );
	// get program axis name
	// axis		an array of size NUMOF_AXIS

	void getAlarmList( TOcAlarmInfo *pAlarmList, long SizeToRead, long *plSizeRead );
	// to get alarm list of simulation

	void getBlockInfo( char *pProgramName, long *pLineNo, long *pSequenceNo );
	// get current block information
	// ProgramName		program name, should be at least 128 chars.

	long putLineNo( long lineno );
	// put line number

	ULONG isUndoEnable( void );
	// undo step enable or not

	void setAutoMargin( int bAutoMargin );
	// set auto margin state

	int getAutoMargin( void );
	// get auto margin state

	void setDrawMode( int DrawMode );
	// set draw mode

	int getDrawMode( void );
	// get draw mode

	int getCoordID( void );
	// get CoordID

	void putCacheSize( LONG size );
	// set cache size, in bytes

	LONG getCacheSize( void );
	// get cache size, in bytes

	long  getHoleList( TOCHole *pList, long CountToRead );
	// to get hole list, return count read

	long getHoleCount(void);
	// to get hole list count

	void setGroupID( long groupID );
	// set group id

	void setStartLineNo( long startLineno );
	// set start line number

	int getTotalBlockData( TNcBlockData *pBuffer );
	// get block data

	int get_CacheState( void );
	// get cache data state

// implement CXWnd interface
	void OnShowWindow( BOOL bShow );
	// bShow	Specifies whether a window is being shown.
	//			It is TRUE if the window is being shown;
	//			it is FALSE if the window is being hidden.

	void OnSize( void );
	// on window size change

	void OnTimer( void );
	// timer event handler

// zoom frame operation
	void ZoomStepUp( void );
	// zoom frame step up

	void ZoomStepDown( void );
	// zoom frame step down

	void ZoomStepRight( void );
	// zoom frame step right

	void ZoomStepLeft( void );
	// zoom frame step down

	void ZoomEnlarge( void );
	// zoom frame enlarge

	void ZoomShrink( void );
	// zoom frame shrink

	void accept( void );
	// accept current selection, the zoom port, the vertical
	// rotation angle, the horzontal angle

// override CXComponert
	void paint( CGraphics3d *g );
	// update screen

	void notifyAttachPeer( void );
	// notify this component has been attach a new graphics peer
public:		// implement CSmDraw::INotify interface
	void CNCAPI OnDrawBegin( void );
	void CNCAPI OnDrawEnd( void );

private:
	enum EState {
		STATE_IDLE,
		STATE_ZOOM
	};

	enum EMaxBounds {
		MARGIN_ViewPort = 4
	};

	int m_fCursorEnabled;
	// the run-time cursor is enabled

	int m_State;
	// object state

	int m_DrawMode;
	// draw mode

	BOOL m_bPause;
	// pause state variable

	BOOL m_bDrawBackground;
	// draw back ground request

	int m_DrawBackState;
	// draw background state machine variable

	DWORD m_SmEventCookie;
	// simulation event cookie

	BOOL m_bPlay;
	// is this object has been play

	CXSmDrawer *m_pSmDrawer;
	CXSmCursor *m_pSmCursor;

	CSimuStorage *m_pSimuStorage;
	// pointer to associated NC program simulator interface

	CXSmZoom *m_pSmZoom;
	// associated child component

	// drawer cache property
	COLORREF m_crLineColor;
	COLORREF m_crRapidColor;
	COLORREF m_crFrameColor;
	COLORREF m_crCaretColor;
	COLORREF m_crGridColor;
	COLORREF m_crTextColor;
	int m_nOpMode;
	int m_bAutoMargin;
	char m_MainProgramName[128];
	BOOL m_bInDrawing;

	CGraphics3d *m_pGraphics3d;
	// graphics context cache
};

#endif // !defined(AFX_XPATHSIMUBASE_H__A6AC7D7F_B359_45DD_9D2F_C47514DD4D53__INCLUDED_)
