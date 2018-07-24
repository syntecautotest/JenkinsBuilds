// OCUSER.h : Declaration of the OCUSER

#ifndef __OCUSER_H_
#define __OCUSER_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef TOCVARIANT_STRUCT_
#define TOCVARIANT_STRUCT_

typedef struct tagTOcVariant {
	short		m_type;
	union {
		long	m_long;
		double	m_double;
	};
} TOcVariant;

#endif // TOCVARIANT_STRUCT_

#ifndef TOCHOLE_STRUCT_
#define TOCHOLE_STRUCT_

typedef struct tagTOcHole {
	double		Position[3];
	double		Radius;
	long		LineNo;
} TOCHole;

#endif // TOCHOLE_STRUCT_

#if !defined(STRUCT_POINT_W)
#define STRUCT_POINT_W

typedef struct tagPOINT_W {
   double x;
   double y;
   double z;
} POINT_W;

#endif // STRUCT_POINT_W

//====== Ranges for control message IDs =======================================
#define OCM_FIRST						(WM_USER)		// OpenCNC common message code
#define OCPSM_FIRST						(WM_USER+100)	// OCPathSimu message code
#define OCTXM_FIRST						(WM_USER+200)	// OCText message code
#define OCBRM_FIRST						(WM_USER+300)	// OCBrowser message code
#define OCFBM_FIRST						(WM_USER+400)	// OCFenu message code
#define OCLBM_FIRST						(WM_USER+500)	// OCLabel message code
#define OCLDM_FIRST						(WM_USER+600)	// OCLadderView message code
#define OCCVSM_FIRST					(WM_USER+700)	// OCCanvas message code
#define OC3DM_FIRST						(WM_USER+800)

//====== WM_NOTIFY codes (NMHDR.code values) ==================================
#define OCPSNM_FIRST					(0U-2000U)		// OCPathSimu
#define OCPSNM_LAST						(0U-2099U)
#define OCBRNM_FIRST					(0U-2100U)		// OCBrowser
#define OCBRNM_LAST						(0U-2199U)
#define OCFBNM_FIRST					(0U-2200U)		// OCFenu
#define OCFBNM_LAST						(0U-2299U)
#define OCTXNM_FIRST					(0U-2300U)		// OCText
#define OCTXNM_LAST						(0U-2399U)
#define OCCVNM_FIRST					(0U-2400U)		// OCCanvas
#define OCCVNM_LAST						(0U-2499U)
#define OCLDNM_FIRST					(0U-2500U)		// OCLadder
#define OCLDNM_LAST						(0U-2599U)

// OC common message code
#define OCM_RAISEEVENT					(OCM_FIRST)
#define OCM_REGEVENTLISTENER			(OCM_FIRST + 1)

#define OCM_PUTBACKCOLOR				(OCM_FIRST + 2)
#define OCUser_PutBackColor(hwnd, Val) \
        (BOOL)SendMessage((hwnd), OCM_PUTBACKCOLOR, 0, (LPARAM)(COLORREF)(Val))

#define OCM_PUTFORECOLOR				(OCM_FIRST + 3)
#define OCUser_PutForeColor(hwnd, Val) \
        (BOOL)SendMessage((hwnd), OCM_PUTFORECOLOR, 0, (LPARAM)(COLORREF)(Val))

#define OCM_PUTFONT						(OCM_FIRST + 4)
#define OCUser_PutFont(hwnd, Val) \
        (BOOL)SendMessage((hwnd), OCM_PUTFONT, 0, (LPARAM)(LPLOGFONT)(Val))

#define OCM_GETGRAPHICS					(OCM_FIRST + 5)
#define OCUser_GetGraphics(hwnd) \
        SendMessage((hwnd), OCM_GETGRAPHICS, 0, 0)

// OCPathSimu message
#define OCPSM_GETVERTICALANGLE			(OCPSM_FIRST + 0)
#define OCPathSimu_GetVerticalAngle(hwnd, lpVal) \
        (BOOL)SendMessage((hwnd), OCPSM_GETVERTICALANGLE, 0, (LPARAM)(double *)(lpVal))

#define OCPSM_PUTVERTICALANGLE			(OCPSM_FIRST + 1)
#define OCPathSimu_PutVerticalAngle(hwnd, lpVal) \
        (BOOL)SendMessage((hwnd), OCPSM_PUTVERTICALANGLE, 0, (LPARAM)(double *)(lpVal))

#define OCPSM_GETHORZONTALANGLE			(OCPSM_FIRST + 2)
#define OCPathSimu_GetHorzontalAngle(hwnd, lpVal) \
        (BOOL)SendMessage((hwnd), OCPSM_GETHORZONTALANGLE, 0, (LPARAM)(double *)(lpVal))

#define OCPSM_PUTHORZONTALANGLE			(OCPSM_FIRST + 3)
#define OCPathSimu_PutHorzontalAngle(hwnd, lpVal) \
        (BOOL)SendMessage((hwnd), OCPSM_PUTHORZONTALANGLE, 0, (LPARAM)(double *)(lpVal))

#define OCPSM_GETCACHELEN				(OCPSM_FIRST + 4)
#define OCPathSimu_GetCacheLen(hwnd) \
        (ULONG)SendMessage((hwnd), OCPSM_GETCACHELEN, 0, 0)

#define OCPSM_PUTCACHELEN				(OCPSM_FIRST + 5)
#define OCPathSimu_PutCacheLen(hwnd, Val) \
        (BOOL)SendMessage((hwnd), OCPSM_PUTCACHELEN, 0, (LPARAM)(ULONG)(Val))

#define OCPSM_GETQUADRANT				(OCPSM_FIRST + 6)
#define OCPathSimu_GetQuadrant(hwnd) \
        (UINT)SendMessage((hwnd), OCPSM_GETQUADRANT, 0, 0)

#define OCPSM_PUTQUADRANT				(OCPSM_FIRST + 7)
#define OCPathSimu_PutQuadrant(hwnd, Val) \
        (BOOL)SendMessage((hwnd), OCPSM_PUTQUADRANT, 0, (LPARAM)(UINT)(Val))

#define OCPSM_GETOPMODE					(OCPSM_FIRST + 8)
#define OCPathSimu_GetOpMode(hwnd) \
        (UINT)SendMessage((hwnd), OCPSM_GETOPMODE, 0, 0)

#define OCPSM_PUTOPMODE					(OCPSM_FIRST + 9)
#define OCPathSimu_PutOpMode(hwnd, Val) \
        (BOOL)SendMessage((hwnd), OCPSM_PUTOPMODE, 0, (LPARAM)(UINT)(Val))

#define OCPSM_GETVIEWPOINTMODE			(OCPSM_FIRST + 10)
#define OCPathSimu_GetViewpointMode(hwnd) \
        (UINT)SendMessage((hwnd), OCPSM_GETVIEWPOINTMODE, 0, 0)

#define OCPSM_PUTVIEWPOINTMODE			(OCPSM_FIRST + 11)
#define OCPathSimu_PutViewpointMode(hwnd, Val) \
        (BOOL)SendMessage((hwnd), OCPSM_PUTVIEWPOINTMODE, 0, (LPARAM)(UINT)(Val))

#define OCPSM_GETRAPIDLINESTYLE			(OCPSM_FIRST + 12)
#define OCPathSimu_GetRapidLineStyle(hwnd) \
        (UINT)SendMessage((hwnd), OCPSM_GETRAPIDLINESTYLE, 0, 0)

#define OCPSM_PUTRAPIDLINESTYLE			(OCPSM_FIRST + 13)
#define OCPathSimu_PutRapidLineStyle(hwnd, Val) \
        (BOOL)SendMessage((hwnd), OCPSM_PUTRAPIDLINESTYLE, 0, (LPARAM)(UINT)(Val))

#define OCPSM_GETLINENO					(OCPSM_FIRST + 14)

#define OCPSM_PUTLINENO					(OCPSM_FIRST + 15)
#define OCPathSimu_PutLineNo(hwnd, Val) \
        (BOOL)SendMessage((hwnd), OCPSM_PUTLINENO, 0, (LPARAM)(ULONG)(Val))

#define OCPSM_GETFRAMECOLOR				(OCPSM_FIRST + 16)
#define OCPathSimu_GetFrameColor(hwnd) \
        (COLORREF)SendMessage((hwnd), OCPSM_GETFRAMECOLOR, 0, 0)

#define OCPSM_PUTFRAMECOLOR				(OCPSM_FIRST + 17)
#define OCPathSimu_PutFrameColor(hwnd, Val) \
        (BOOL)SendMessage((hwnd), OCPSM_PUTFRAMECOLOR, 0, (LPARAM)(COLORREF)(Val))

#define OCPSM_GETGRIDCOLOR				(OCPSM_FIRST + 18)
#define OCPathSimu_GetGridColor(hwnd) \
        (COLORREF)SendMessage((hwnd), OCPSM_GETGRIDCOLOR, 0, 0)

#define OCPSM_PUTGRIDCOLOR				(OCPSM_FIRST + 19)
#define OCPathSimu_PutGridColor(hwnd, Val) \
        (BOOL)SendMessage((hwnd), OCPSM_PUTGRIDCOLOR, 0, (LPARAM)(COLORREF)(Val))

#define OCPSM_PUTFORECOLOR				(OCPSM_FIRST + 20)
#define OCPathSimu_PutForeColor(hwnd, Val) \
        (BOOL)SendMessage((hwnd), OCPSM_PUTFORECOLOR, 0, (LPARAM)(COLORREF)(Val))

#define OCPSM_PUTBACKCOLOR				(OCPSM_FIRST + 22)
#define OCPathSimu_PutBackColor(hwnd, Val) \
        (BOOL)SendMessage((hwnd), OCPSM_PUTBACKCOLOR, 0, (LPARAM)(COLORREF)(Val))

#define OCPSM_PUTFONT					(OCPSM_FIRST + 24)
#define OCPathSimu_PutFont(hwnd, Val) \
        (BOOL)SendMessage((hwnd), OCPSM_PUTFONT, 0, (LPARAM)(LPLOGFONT)(Val))

#define OCPSM_GETGRIDVISIBLE			(OCPSM_FIRST + 26)
#define OCPathSimu_GetGridVisible(hwnd) \
        (BOOL)SendMessage((hwnd), OCPSM_GETGRIDVISIBLE, 0, 0)

#define OCPSM_PUTGRIDVISIBLE			(OCPSM_FIRST + 27)
#define OCPathSimu_PutGridVisible(hwnd, Val) \
        (BOOL)SendMessage((hwnd), OCPSM_PUTGRIDVISIBLE, 0, (LPARAM)(BOOL)(Val))

#define OCPSM_GETAUTOMARGIN				(OCPSM_FIRST + 28)
#define OCPathSimu_GetAutoMargin(hwnd) \
        (BOOL)SendMessage((hwnd), OCPSM_GETAUTOMARGIN, 0, 0)

#define OCPSM_PUTAUTOMARGIN				(OCPSM_FIRST + 29)
#define OCPathSimu_PutAutoMargin(hwnd, Val) \
        (BOOL)SendMessage((hwnd), OCPSM_PUTAUTOMARGIN, 0, (LPARAM)(BOOL)(Val))

#define OCPSM_GETMAINPROGRAM			(OCPSM_FIRST + 30)
#define OCPathSimu_GetMainProgram(hwnd, lpVal, count) \
        (UINT)SendMessage((hwnd), OCPSM_GETMAINPROGRAM, (WPARAM)(UINT)count, (LPARAM)(LPTSTR)lpVal)

#define OCPSM_PUTMAINPROGRAM			(OCPSM_FIRST + 31)
#define OCPathSimu_PutMainProgram(hwnd, lpVal) \
        (BOOL)SendMessage((hwnd), OCPSM_PUTMAINPROGRAM, 0, (LPARAM)(LPCTSTR)lpVal)

#define OCPSM_GETMARGIN					(OCPSM_FIRST + 32)
#define OCPathSimu_GetMargin(hwnd, lpVal) \
        (BOOL)SendMessage((hwnd), OCPSM_GETMARGIN, 0, (LPARAM)(POCPSMARGIN)lpVal)

#define OCPSM_PUTMARGIN					(OCPSM_FIRST + 33)
#define OCPathSimu_PutMargin(hwnd, lpVal) \
        (BOOL)SendMessage((hwnd), OCPSM_PUTMARGIN, 0, (LPARAM)(POCPSMARGIN)lpVal)

#define OCPSM_GETALARMLIST				(OCPSM_FIRST + 34)
#define OCPathSimu_GetAlarmList(hwnd, lpVal, count) \
        (UINT)SendMessage((hwnd), OCPSM_GETALARMLIST, (WPARAM)(UINT)count, (LPARAM)(TOcAlarmInfo *)lpVal)

#define OCPSM_GETGLOBALVAR				(OCPSM_FIRST + 35)

#define OCPSM_PUTMDIBLOCKS				(OCPSM_FIRST + 36)
#define OCPathSimu_PutMDIBlocks(hwnd, lpVal) \
        (BOOL)SendMessage((hwnd), OCPSM_PUTMDIBLOCKS, 0, (LPARAM)(LPCSTR)lpVal)

#define OCPSM_GETSEQUENCENO				(OCPSM_FIRST + 37)

#define OCPSM_GETPROGRAMNAME			(OCPSM_FIRST + 38)

#define OCPSM_GETPOSITION				(OCPSM_FIRST + 39)

#define OCPSM_CANCELZOOM				(OCPSM_FIRST + 40)
#define OCPathSimu_CancelZoom(hwnd) \
        (BOOL)SendMessage((hwnd), OCPSM_CANCELZOOM, 0, 0 )

#define OCPSM_TOGGLEZOOMFRAME			(OCPSM_FIRST + 41)
#define OCPathSimu_ToggleZoomFrame(hwnd) \
        (BOOL)SendMessage((hwnd), OCPSM_TOGGLEZOOMFRAME, 0, 0 )

#define OCPSM_ABORT						(OCPSM_FIRST + 42)
#define OCPathSimu_Abort(hwnd) \
        (BOOL)SendMessage((hwnd), OCPSM_ABORT, 0, 0 )

#define OCPSM_STEP						(OCPSM_FIRST + 43)
#define OCPathSimu_Step(hwnd) \
        (BOOL)SendMessage((hwnd), OCPSM_STEP, 0, 0)

#define OCPSM_PLAY						(OCPSM_FIRST + 44)
#define OCPathSimu_Play(hwnd) \
        (BOOL)SendMessage((hwnd), OCPSM_PLAY, 0, 0)

#define OCPSM_GETHOLECOUNT				(OCPSM_FIRST + 45)
#define OCPathSimu_GetHoleCount(hwnd) \
        (LONG)SendMessage((hwnd), OCPSM_GETHOLECOUNT, 0, 0)
// return the total number of hole

#define OCPSM_GETHOLELIST				(OCPSM_FIRST + 46)
#define OCPathSimu_GetHoleList(hwnd,lpList,CountToRead) \
        (LONG)SendMessage((hwnd), OCPSM_GETHOLELIST, (WPARAM)(LONG)CountToRead, (LPARAM)(TOCHole *)lpList)
// return hole count read

//#define OCPSM_GETOBJECTMATRIX			(OCPSM_FIRST + 47)
//#define OCPathSimu_GetObjectMatrix(hwnd, lpVal) \
//        (BOOL)SendMessage((hwnd), OCPSM_GETOBJECTMATRIX, 0, (LPARAM)(double *)(lpVal))
// a[] the data sequence is a11, a12, a13, a14, a21, a22, .., a41, a42, a43, a44.
// the translation vector is (a14,a24,a34)

//#define OCPSM_PUTOBJECTMATRIX			(OCPSM_FIRST + 48)
//#define OCPathSimu_PutObjectMatrix(hwnd, lpVal) \
//        (BOOL)SendMessage((hwnd), OCPSM_PUTOBJECTMATRIX, 0, (LPARAM)(double *)(lpVal))
// a[] the data sequence is a11, a12, a13, a14, a21, a22, .., a41, a42, a43, a44.
// the translation vector is (a14,a24,a34)

//#define OCPSM_LPTODP					(OCPSM_FIRST + 49)
//#define OCPathSimu_LPtoDP(hwnd,lpPoint3d) \
//        (BOOL)SendMessage((hwnd), OCPSM_LPTODP, 0, (LPARAM)(double *)(lpPoint3d))
// lpPoint3d[] is 3-dimension point double value. you should fill 0 for don't care dimension.

#define OCPSM_GETGRIDUNITMODE			(OCPSM_FIRST + 50)
#define OCPathSimu_GetGridUnitMode(hwnd) \
        (LONG)SendMessage((hwnd), OCPSM_GETGRIDUNITMODE, 0, 0)

#define OCPSM_PUTGRIDUNITMODE			(OCPSM_FIRST + 51)
#define OCPathSimu_PutGridUnitMode(hwnd, Val) \
        (BOOL)SendMessage((hwnd), OCPSM_PUTGRIDUNITMODE, 0, (LPARAM)(LONG)(Val) )

#define OCPSM_GETCARETCOLOR				(OCPSM_FIRST + 52)
#define OCPathSimu_GetCaretColor(hwnd) \
        (COLORREF)SendMessage((hwnd), OCPSM_GETCARETCOLOR, 0, 0)

#define OCPSM_PUTCARETCOLOR				(OCPSM_FIRST + 53)
#define OCPathSimu_PutCaretColor(hwnd, Val) \
        (BOOL)SendMessage((hwnd), OCPSM_PUTCARETCOLOR, 0, (LPARAM)(COLORREF)(Val))

#define OCPSM_GETTEXTCOLOR				(OCPSM_FIRST + 54)
#define OCPathSimu_GetTextColor(hwnd) \
        (COLORREF)SendMessage((hwnd), OCPSM_GETTEXTCOLOR, 0, 0)

#define OCPSM_PUTTEXTCOLOR				(OCPSM_FIRST + 55)
#define OCPathSimu_PutTextColor(hwnd, Val) \
        (BOOL)SendMessage((hwnd), OCPSM_PUTTEXTCOLOR, 0, (LPARAM)(COLORREF)(Val))

#define OCPSM_REPLAY					(OCPSM_FIRST + 56)
#define OCPathSimu_Replay(hwnd) \
        (BOOL)SendMessage((hwnd), OCPSM_REPLAY, 0, 0)

#define OCPSM_ZOOMBACK				(OCPSM_FIRST + 57)
#define OCPathSimu_ZoomBack(hwnd) \
        (BOOL)SendMessage((hwnd), OCPSM_ZOOMBACK, 0, 0 )

#define OCPSM_GETDRAWMODE			(OCPSM_FIRST + 58)
#define OCPathSimu_GetDrawMode(hwnd) \
        (UINT)SendMessage((hwnd), OCPSM_GETDRAWMODE, 0, 0)

#define OCPSM_PUTDRAWMODE			(OCPSM_FIRST + 59)
#define OCPathSimu_PutDrawMode(hwnd, Val) \
        (BOOL)SendMessage((hwnd), OCPSM_PUTDRAWMODE, 0, (LPARAM)(UINT)(Val))

#define OCPSM_PUTREFRESHENABLED		(OCPSM_FIRST + 60)
#define OCPathSimu_PutRefreshEnabled(hwnd) \
		SendMessage((hwnd), OCPSM_PUTREFRESHENABLED, 0, (LPARAM)(BOOL)(RefreshEnabled))

#define OCPSM_PLAYWITHMARGIN		(OCPSM_FIRST + 61)
#define OCPathSimu_PlayWithMargin(hwnd) \
		SendMessage((hwnd), OCPSM_PLAYWITHMARGIN, 0, (LPARAM)(POCPSMARGIN)lpVal)

#define OCPSM_PUTGROUPID			(OCPSM_FIRST + 62)
#define OCPathSimu_PutGroupID(hwnd) \
		SendMessage((hwnd), OCPSM_PUTGROUPID, 0, (LPARAM)(LONG)lpVal)

#define OCPSM_PUTSTARTLINENUMBER	(OCPSM_FIRST + 63)
#define OCPathSimu_PutStartLineNumber(hwnd) \
		SendMessage((hwnd), OCPSM_PUTSTARTLINENUMBER, 0, (LPARAM)(LONG)lpVal)

#define OCPSM_GETRAPIDCOLOR				(OCPSM_FIRST + 64)
#define OCPathSimu_GetRapidColor(hwnd) \
        (COLORREF)SendMessage((hwnd), OCPSM_GETRAPIDCOLOR, 0, 0)

#define OCPSM_PUTRAPIDCOLOR				(OCPSM_FIRST + 65)
#define OCPathSimu_PutRapidColor(hwnd, Val) \
        (BOOL)SendMessage((hwnd), OCPSM_PUTRAPIDCOLOR, 0, (LPARAM)(COLORREF)(Val))

#define OCPSM_GETBLOCKDATA				(OCPSM_FIRST + 66)
#define OCPSM_GETCACHEDATASTATE			(OCPSM_FIRST + 67)

#define OCPSM_UNDOSTEP						(OCPSM_FIRST + 68)
#define OCPathSimu_UndoStep(hwnd) \
        (BOOL)SendMessage((hwnd), OCPSM_UNDOSTEP, 0, 0)

typedef struct tagTOCPSMARGIN {
	double	Xmin;
	double	Xmax;
	double	Ymin;
	double	Ymax;
	double	Zmin;
	double	Zmax;
} OCPSMARGIN, *POCPSMARGIN;

typedef struct LoadPageArguments{
	LPCTSTR lpszFileName;
	LPCTSTR lpszFileSection;
} LOADPAGEDATA, *LOADPAGESTRUCT;

// OCPathSimu event code
#define OCPSEV_COMPLETE					1
#define OCPSEV_ALARM					2
#define OCPSEV_DRAWBEGIN				3
#define OCPSEV_DRAWEND					4
#define OCPSEV_SELECTAUTOMARGIN			5
#define OCPSEV_ZOOMACCEPT				6
#define OCPSEV_MOUSEMOVE				7

// OCCanvas message
#define OCCVSM_GETVERTICALANGLE			(OCCVSM_FIRST + 0)
#define OCCanvas_GetVerticalAngle(hwnd, lpVal) \
        (BOOL)SendMessage((hwnd), OCCVSM_GETVERTICALANGLE, 0, (LPARAM)(double *)(lpVal))

#define OCCVSM_PUTVERTICALANGLE			(OCCVSM_FIRST + 1)
#define OCCanvas_PutVerticalAngle(hwnd, lpVal) \
        (BOOL)SendMessage((hwnd), OCCVSM_PUTVERTICALANGLE, 0, (LPARAM)(double *)(lpVal))

#define OCCVSM_GETHORZONTALANGLE			(OCCVSM_FIRST + 2)
#define OCCanvas_GetHorzontalAngle(hwnd, lpVal) \
        (BOOL)SendMessage((hwnd), OCCVSM_GETHORZONTALANGLE, 0, (LPARAM)(double *)(lpVal))

#define OCCVSM_PUTHORZONTALANGLE			(OCCVSM_FIRST + 3)
#define OCCanvas_PutHorzontalAngle(hwnd, lpVal) \
        (BOOL)SendMessage((hwnd), OCCVSM_PUTHORZONTALANGLE, 0, (LPARAM)(double *)(lpVal))

#define OCCVSM_GETQUADRANT				(OCCVSM_FIRST + 4)
#define OCCanvas_GetQuadrant(hwnd) \
        (UINT)SendMessage((hwnd), OCCVSM_GETQUADRANT, 0, 0)

#define OCCVSM_PUTQUADRANT				(OCCVSM_FIRST + 5)
#define OCCanvas_PutQuadrant(hwnd, Val) \
        (BOOL)SendMessage((hwnd), OCCVSM_PUTQUADRANT, 0, (LPARAM)(UINT)(Val))

#define OCCVSM_GETVIEWPOINTMODE			(OCCVSM_FIRST + 6)
#define OCCanvas_GetViewpointMode(hwnd) \
        (UINT)SendMessage((hwnd), OCCVSM_GETVIEWPOINTMODE, 0, 0)

#define OCCVSM_PUTVIEWPOINTMODE			(OCCVSM_FIRST + 7)
#define OCCanvas_PutViewpointMode(hwnd, Val) \
        (BOOL)SendMessage((hwnd), OCCVSM_PUTVIEWPOINTMODE, 0, (LPARAM)(UINT)(Val))

#define OCCVSM_GETLINESTYLE				(OCCVSM_FIRST + 8)
#define OCCanvas_GetLineStyle(hwnd) \
        (UINT)SendMessage((hwnd), OCCVSM_GETLINESTYLE, 0, 0)

#define OCCVSM_PUTLINESTYLE				(OCCVSM_FIRST + 9)
#define OCCanvas_PutLineStyle(hwnd, Val) \
        (BOOL)SendMessage((hwnd), OCCVSM_PUTLINESTYLE, 0, (LPARAM)(UINT)(Val))

#define OCCVSM_GETFRAMECOLOR				(OCCVSM_FIRST + 10)
#define OCCanvas_GetFrameColor(hwnd) \
        (COLORREF)SendMessage((hwnd), OCCVSM_GETFRAMECOLOR, 0, 0)

#define OCCVSM_PUTFRAMECOLOR				(OCCVSM_FIRST + 11)
#define OCCanvas_PutFrameColor(hwnd, Val) \
        (BOOL)SendMessage((hwnd), OCCVSM_PUTFRAMECOLOR, 0, (LPARAM)(COLORREF)(Val))

#define OCCVSM_GETGRIDCOLOR				(OCCVSM_FIRST + 12)
#define OCCanvas_GetGridColor(hwnd) \
        (COLORREF)SendMessage((hwnd), OCCVSM_GETGRIDCOLOR, 0, 0)

#define OCCVSM_PUTGRIDCOLOR				(OCCVSM_FIRST + 13)
#define OCCanvas_PutGridColor(hwnd, Val) \
        (BOOL)SendMessage((hwnd), OCCVSM_PUTGRIDCOLOR, 0, (LPARAM)(COLORREF)(Val))

#define OCCVSM_GETMARGIN					(OCCVSM_FIRST + 14)
#define OCCanvas_GetMargin(hwnd, lpVal) \
        (BOOL)SendMessage((hwnd), OCCVSM_GETMARGIN, 0, (LPARAM)(POCPSMARGIN)lpVal)

#define OCCVSM_PUTMARGIN					(OCCVSM_FIRST + 15)
#define OCCanvas_PutMargin(hwnd, lpVal) \
        (BOOL)SendMessage((hwnd), OCCVSM_PUTMARGIN, 0, (LPARAM)(POCPSMARGIN)lpVal)

#define OCCVSM_CANCELZOOM				(OCCVSM_FIRST + 16)
#define OCCanvas_CancelZoom(hwnd) \
        (BOOL)SendMessage((hwnd), OCCVSM_CANCELZOOM, 0, 0 )

#define OCCVSM_TOGGLEZOOMFRAME			(OCCVSM_FIRST + 17)
#define OCCanvas_ToggleZoomFrame(hwnd) \
        (BOOL)SendMessage((hwnd), OCCVSM_TOGGLEZOOMFRAME, 0, 0 )

#define OCCVSM_GETCARETCOLOR				(OCCVSM_FIRST + 21)
#define OCCanvas_GetCaretColor(hwnd) \
        (COLORREF)SendMessage((hwnd), OCCVSM_GETCARETCOLOR, 0, 0)

#define OCCVSM_PUTCARETCOLOR				(OCCVSM_FIRST + 22)
#define OCCanvas_PutCaretColor(hwnd, Val) \
        (BOOL)SendMessage((hwnd), OCCVSM_PUTCARETCOLOR, 0, (LPARAM)(COLORREF)(Val))

#define OCCVSM_GETTEXTCOLOR				(OCCVSM_FIRST + 23)
#define OCCanvas_GetTextColor(hwnd) \
        (COLORREF)SendMessage((hwnd), OCCVSM_GETTEXTCOLOR, 0, 0)

#define OCCVSM_PUTTEXTCOLOR				(OCCVSM_FIRST + 24)
#define OCCanvas_PutTextColor(hwnd, Val) \
        (BOOL)SendMessage((hwnd), OCCVSM_PUTTEXTCOLOR, 0, (LPARAM)(COLORREF)(Val))

#define OCCVSM_GETFILLCOLOR				(OCCVSM_FIRST + 25)
#define OCCanvas_GetFillColor(hwnd) \
        (COLORREF)SendMessage((hwnd), OCCVSM_GETFILLCOLOR, 0, 0)

#define OCCVSM_PUTFILLCOLOR				(OCCVSM_FIRST + 26)
#define OCCanvas_PutFillColor(hwnd, Val) \
        (BOOL)SendMessage((hwnd), OCCVSM_PUTFILLCOLOR, 0, (LPARAM)(COLORREF)(Val))

#define OCCVSM_ZOOMBACK					(OCCVSM_FIRST + 27)
#define OCCanvas_ZoomBack(hwnd) \
        (BOOL)SendMessage((hwnd), OCCVSM_ZOOMBACK, 0, 0 )

// OCText message
#define OCTXM_PUTBARCOLOR				(OCTXM_FIRST+0)
#define OCText_PutBarColor(hwnd,clrColor) \
        (BOOL)SendMessage((hwnd), OCTXM_PUTBARCOLOR, 0, (LPARAM)(COLORREF)clrColor)

#define OCTXM_SAVEFILE					(OCTXM_FIRST+1)
#define OCText_SaveFile(hwnd, lpFileName) \
		(BOOL)SendMessage((hwnd), OCTXM_SAVEFILE, 0, (LPARAM)(TCHAR *)lpFileName)

#define OCTXM_LOADFILE					(OCTXM_FIRST+2)
#define OCText_LoadFile(hwnd, lpFileName) \
		(BOOL)SendMessage((hwnd), OCTXM_LOADFILE, 0, (LPARAM)(TCHAR *)lpFileName)

#define OCTXM_PUTOPMODE					(OCTXM_FIRST+3)
#define OCText_PutOpMode(hwnd,mode) \
        SendMessage((hwnd), OCTXM_PUTOPMODE, 0, (LPARAM)(LONG)mode)

#define OCTXM_GETOPMODE					(OCTXM_FIRST+4)
#define OCText_GetOpMode(hwnd) \
        (LONG)SendMessage((hwnd), OCTXM_GETOPMODE, 0, 0)

#define OCTXM_PUTLINENO					(OCTXM_FIRST+5)
#define OCText_PutLineNo(hwnd,lineno) \
        (LONG)SendMessage((hwnd), OCTXM_PUTLINENO, 0, (LPARAM)(LONG)lineno)

#define OCTXM_GETCOLUMN					(OCTXM_FIRST+6)
#define OCText_GetColumn(hwnd) \
        (LONG)SendMessage((hwnd), OCTXM_GETCOLUMN, 0, 0 )

#define OCTXM_GETLINENO					(OCTXM_FIRST+7)
#define OCText_GetLineNo(hwnd) \
        (LONG)SendMessage((hwnd), OCTXM_GETLINENO, 0, 0)

#define OCTXM_CLEAR						(OCTXM_FIRST+8)
#define OCText_Clear(hwn) \
		(LONG)SendMessage((hwnd), OCTXM_CLEAR, 0, 0)

#define OCTXM_GETSTARTLINE				(OCTXM_FIRST+9)
#define OCText_GetStartLine(hwn) \
		(LONG)SendMessage((hwnd), OCTXM_GETSTARTLINE, 0, 0)

#define OCTXM_RELOADFILE				(OCTXM_FIRST+10)
#define OCText_ReloadFile(hwnd) \
		(LONG)SendMessage((hwnd), OCTXM_RELOADFILE, 0, 0)

#define OCTXM_PUTMODIFYCOLOR				(OCTXM_FIRST+11)
#define OCText_PutModifyClr(hwnd,mode) \
        SendMessage((hwnd), OCTXM_PUTMODIFYCOLOR, 0, (LPARAM)(LONG)mode)

#define OCTXM_PUTERRCODECOLOR				(OCTXM_FIRST+12)
#define OCText_PutErrCodeClr(hwnd,mode) \
        SendMessage((hwnd), OCTXM_PUTERRCODECOLOR, 0, (LPARAM)(LONG)mode)

#define OCTXM_SAVEFILETO					(OCTXM_FIRST+13)
#define OCText_SaveFileTo(hwnd, lpFileName) \
		(BOOL)SendMessage((hwnd), OCTXM_SAVEFILETO, 0, (LPARAM)(TCHAR *)lpFileName)

#define OCTXM_SETROWCOLUMN					(OCTXM_FIRST+14)
#define OCText_SetRowColumn(hwnd, rowno, colno) \
		(LONG)SendMessage((hwnd), OCTXM_SETROWCOLUMN, (WPARAM)(LONG)rowno, (LPARAM)(LONG)colno)

#define OCTXM_SETHSCROLLBARVISIBLE			(OCTXM_FIRST+15)
#define OCText_SetHScrollbarVisible(hwnd, bVisible) \
		SendMessage((hwnd), OCTXM_SETHSCROLLBARVISIBLE, 0, (LPARAM)(BOOL)bVisible)

// OCText event code
#define OCTXNM_SELCHANGED				(OCTXNM_FIRST-0)
#define OCTXNM_MOUSEMOVE				(OCTXNM_FIRST-1)

// OCBrowser message
#define OCBRM_LOADPAGE					(OCBRM_FIRST+0)
#define OCBrowser_LoadPage(hwnd,lpszFileName,bShow) \
        SendMessage((hwnd), OCBRM_LOADPAGE, (WPARAM)(BOOL)bShow, (LPARAM)(LPCTSTR)lpszFileName)

#define OCBRM_GETOPMODE					(OCBRM_FIRST+1)
#define OCBrowser_GetOpMode(hwnd) \
        (UINT)SendMessage((hwnd), OCBRM_GETOPMODE, 0, 0)

#define OCBRM_PUTOPMODE					(OCBRM_FIRST+2)
#define OCBrowser_PutOpMode(hwnd, Val) \
        (BOOL)SendMessage((hwnd), OCBRM_PUTOPMODE, 0, (LPARAM)(UINT)(Val))

#define OCBRM_GETHINTTEXTBLOCK			(OCBRM_FIRST+3)
#define OCBrowser_GetHintTextBlock(hwnd,lpBuffer,count) \
        (UINT)SendMessage((hwnd), OCBRM_GETHINTTEXTBLOCK, (WPARAM)(UINT)count, (LPARAM)(TCHAR *)lpBuffer)

#define OCBRM_GETHINTPICTURE			(OCBRM_FIRST+4)
#define OCBrowser_GetHintPicture(hwnd,lpBuffer,count) \
        (UINT)SendMessage((hwnd), OCBRM_GETHINTPICTURE, (WPARAM)(UINT)count, (LPARAM)(TCHAR *)lpBuffer)

#define OCBRM_GETHINTLINE				(OCBRM_FIRST+5)
#define OCBrowser_GetHintLine(hwnd,lpBuffer,count) \
        (UINT)SendMessage((hwnd), OCBRM_GETHINTLINE, (WPARAM)(UINT)count, (LPARAM)(TCHAR *)lpBuffer)

#define OCBRM_PUTBACKCOLOR				(OCBRM_FIRST+6)
#define OCBrowser_PutBackColor(hwnd, Val) \
        SendMessage((hwnd), OCBRM_PUTBACKCOLOR, 0, (LPARAM)(COLORREF)(Val))

#define OCBRM_PUTFONT					(OCBRM_FIRST+7)
#define OCBrowser_PutFont(hwnd, Val) \
        SendMessage((hwnd), OCBRM_PUTFONT, 0, (LPARAM)(LPLOGFONT)(Val))

#define OCBRM_GETPAGEURL				(OCBRM_FIRST+8)
#define OCBrowser_GetPageUrl(hwnd,lpBuffer,count) \
        (UINT)SendMessage((hwnd), OCBRM_GETPAGEURL, (WPARAM)(UINT)count, (LPARAM)(TCHAR *)lpBuffer)

#define OCBRM_SETFOCUSTO				(OCBRM_FIRST+9)
#define OCBrowser_SetFocusTo(hwnd,lpszName) \
        SendMessage((hwnd), OCBRM_SETFOCUSTO, 0, (LPARAM)(LPCTSTR)lpszName)

#define OCBRM_SETFOCUSTOFIRST			(OCBRM_FIRST+10)
#define OCBrowser_SetFocusToFirst(hwnd) \
        SendMessage((hwnd), OCBRM_SETFOCUSTOFIRST, 0, 0)

#define OCBRM_SETFOCUSTOLAST			(OCBRM_FIRST+11)
#define OCBrowser_SetFocusToLast(hwnd) \
        SendMessage((hwnd), OCBRM_SETFOCUSTOLAST, 0, 0)

#define OCBRM_FORWARDFOCUS				(OCBRM_FIRST+12)
#define OCBrowser_ForwardFocus(hwnd) \
        SendMessage((hwnd), OCBRM_FORWARDFOCUS, 0, 0)

#define OCBRM_CLEARLOCAL				(OCBRM_FIRST+13)
#define OCBrowser_ClearLocal(hwnd,lpszPageName) \
        SendMessage((hwnd), OCBRM_CLEARLOCAL, 0, (LPARAM)(LPCTSTR)lpszPageName)

#define OCBRM_GETPAGENAME				(OCBRM_FIRST+14)
#define OCBrowser_GetPageName(hwnd,lpBuffer,count) \
        (UINT)SendMessage((hwnd), OCBRM_GETPAGENAME, (WPARAM)(UINT)count, (LPARAM)(TCHAR *)lpBuffer)

#define OCBRM_PUTSELXML					(OCBRM_FIRST+15)
#define OCBrowser_PutSelXML(hwnd,lpszNewVal) \
        SendMessage((hwnd), OCBRM_PUTSELXML, 0, (LPARAM)(LPCTSTR)lpszNewVal)

#define OCBRM_GETSELXML					(OCBRM_FIRST+16)
#define OCBrowser_GetSelXML(hwnd,lpBuffer,count) \
        (UINT)SendMessage((hwnd), OCBRM_GETSELXML, (WPARAM)(UINT)count, (LPARAM)(TCHAR *)lpBuffer)

#define OCBRM_PUTNAMESPACE				(OCBRM_FIRST+17)
#define OCBrowser_PutNamespace(hwnd,lpszNewVal) \
        SendMessage((hwnd), OCBRM_PUTNAMESPACE, 0, (LPARAM)(LPCTSTR)lpszNewVal)

#define OCBRM_GETNAMESPACE				(OCBRM_FIRST+18)
#define OCBrowser_GetNamespace(hwnd,lpBuffer,count) \
        (UINT)SendMessage((hwnd), OCBRM_GETNAMESPACE, (WPARAM)(UINT)count, (LPARAM)(TCHAR *)lpBuffer)

#define OCBRM_EXECUTEACTION				(OCBRM_FIRST+19)
#define OCBrowser_ExecuteAction(hwnd,lpszAction) \
        SendMessage((hwnd), OCBRM_EXECUTEACTION, 0, (LPARAM)(LPCTSTR)lpszAction)

#define OCBRM_GETCARETCOLOR				(OCBRM_FIRST+20)
#define OCBrowser_GetCaretColor(hwnd) \
        (COLORREF)SendMessage((hwnd), OCBRM_GETCARETCOLOR, 0, 0)

#define OCBRM_PUTCARETCOLOR				(OCBRM_FIRST+21)
#define OCBrowser_PutCaretColor(hwnd, Val) \
        (BOOL)SendMessage((hwnd), OCBRM_PUTCARETCOLOR, 0, (LPARAM)(COLORREF)(Val))

#define OCBRM_DELETESELECTION			(OCBRM_FIRST+23)
#define OCBrowser_DeleteSelection(hwnd) \
        SendMessage((hwnd), OCBRM_DELETESELECTION, 0, 0)

#define OCBRM_SAVEPAGE					(OCBRM_FIRST+24)
#define OCBrowser_SavePage(hwnd,lpszFilename) \
        SendMessage((hwnd), OCBRM_SAVEPAGE, 0, (LPARAM)(LPCTSTR)lpszFilename)

#define OCBRM_GETREGISTERED				(OCBRM_FIRST+25)
#define OCBrowser_GetRegistered(hwnd,lpBuffer,count) \
        (UINT)SendMessage((hwnd), OCBRM_GETREGISTERED, (WPARAM)(UINT)count, (LPARAM)(TCHAR *)lpBuffer)

#define OCBRM_LOADXML					(OCBRM_FIRST+26)
#define OCBrowser_LoadXML(hwnd,lpszPageXML) \
        SendMessage((hwnd), OCBRM_LOADXML, 0, (LPARAM)(LPCTSTR)lpszPageXML)

#define OCBRM_GETHSTRETCH				(OCBRM_FIRST+27)
#define OCBrowser_GetHStretch(hwnd) \
        (UINT)SendMessage((hwnd), OCBRM_GETHSTRETCH, 0, 0)

#define OCBRM_PUTHSTRETCH				(OCBRM_FIRST+28)
#define OCBrowser_PutHStretch(hwnd, Val) \
        (BOOL)SendMessage((hwnd), OCBRM_PUTHSTRETCH, 0, (LPARAM)(UINT)(Val))

#define OCBRM_GETVSTRETCH				(OCBRM_FIRST+29)
#define OCBrowser_GetVStretch(hwnd) \
        (UINT)SendMessage((hwnd), OCBRM_GETVSTRETCH, 0, 0)

#define OCBRM_PUTVSTRETCH				(OCBRM_FIRST+30)
#define OCBrowser_PutVStretch(hwnd, Val) \
        (BOOL)SendMessage((hwnd), OCBRM_PUTVSTRETCH, 0, (LPARAM)(UINT)(Val))

#define OCBRM_PUTREQUESTEDITMODE					(OCBRM_FIRST+31)
#define OCBrowser_PutRequestEditMode(hwnd,lpszNewVal) \
        SendMessage((hwnd), OCBRM_PUTREQUESTEDITMODE, 0, (LPARAM)(UINT)(Val))

#define OCBRM_GETREQUESTEDITMODE					(OCBRM_FIRST+32)
#define OCBrowser_GetRequestEditMode(hwnd) \
        (UINT)SendMessage((hwnd), OCBRM_GETREQUESTEDITMODE, 0, 0)

#define OCBRM_LOADXMLPAGE					(OCBRM_FIRST+33)
#define OCBrowser_LoadXMLPage(hwnd,lpszFileName,lpszPageXML) \
        SendMessage((hwnd), OCBRM_LOADXMLPAGE, (WPARAM)(LPCTSTR)lpszFileName, (LPARAM)(LPCTSTR)lpszPageXML)

#define OCBRM_PUTREFRESHENABLED				(OCBRM_FIRST+34)
#define OCBrowser_PutRefreshEnabled(hwnd, RefreshEnabled) \
        SendMessage((hwnd), OCBRM_PUTREFRESHENABLED, 0, (LPARAM)(BOOL)(RefreshEnabled))

#define OCBRM_PUTCOUNTREFRESH				(OCBRM_FIRST+35)
#define OCBrowser_PutCountRefresh(hwnd, CountRefresh) \
        SendMessage((hwnd), OCBRM_PUTCOUNTREFRESH, 0, (LPARAM)(BOOL)(CountRefresh))

#define OCBRM_PUTCOUNTSTORAGE				(OCBRM_FIRST+36)
#define OCBrowser_PutCountStorage(hwnd, CountStorage) \
        SendMessage((hwnd), OCBRM_PUTCOUNTSTORAGE, 0, (LPARAM)(int)(CountStorage))

#define OCBRM_GETFOCUSNAME				(OCBRM_FIRST+37)
#define OCBrowser_GetFocusName(hwnd,lpBuffer,count) \
        (UINT)SendMessage((hwnd), OCBRM_GETFOCUSNAME, (WPARAM)(UINT)count, (LPARAM)(TCHAR *)lpBuffer)

#define OCBRM_KEYINFINISH				(OCBRM_FIRST+38)
#define OCBrowser_KEYINFINISH(hwnd) \
        (UINT)SendMessage((hwnd), OCBRM_KEYINFINISH, 0, 0)

#define OCBRM_SETFAKEFOCUS			(OCBRM_FIRST+39)
#define OCBrowser_SETFAKEFOCUS(hwnd,lpszName) \
        SendMessage((hwnd), OCBRM_KEYBOARDSENDVALUE, (WPARAM)(LPCTSTR)lpszName, (LPARAM)(BOOL)isShow)

#define OCBRM_GETPAGEWIDTH				(OCBRM_FIRST+40)
#define OCBrowser_GetPageWidth(hwnd) \
        (UINT)SendMessage((hwnd), OCBRM_GETPAGEWIDTH, 0, 0)

#define OCBRM_GETPAGEHEIGHT				(OCBRM_FIRST+41)
#define OCBrowser_GetPageHeight(hwnd) \
        (UINT)SendMessage((hwnd), OCBRM_GETPAGEHEIGHT, 0, 0)

#define OCBRM_REGISTERPAGEINFO			(OCBRM_FIRST+42)

#define OCBRM_UNREGISTERPAGEINFO		(OCBRM_FIRST+43)

#define OCBRM_PUTSCROLLBAR				(OCBRM_FIRST+44)
#define OCBrowser_PutScrollBarEnabled(hwnd, RefreshEnabled) \
        SendMessage((hwnd), OCBRM_PUTSCROLLBAR, 0, (LPARAM)(BOOL)(ScrollBarEnabled))

#define OCBRM_CLEARCONTENT				(OCBRM_FIRST+46)
#define OCBrowser_ClearContent(hwnd,lpszName) \
        SendMessage((hwnd), OCBRM_CLEARCONTENT, 0, (LPARAM)(LPCTSTR)lpszName)

#define OCBRM_SETXMLSTRETCHTYPE			(OCBRM_FIRST+47)
#define OCBrowser_SetXmlStretchType(hwnd,nType) \
        SendMessage((hwnd), OCBRM_SETXMLSTRETCHTYPE, 0, (LPARAM)(UINT)nType)

#define OCBRM_SETXMLDEFAULTSIZE			(OCBRM_FIRST+48)
#define OCBrowser_SetXmlDefaultSize(hwnd,lpsize) \
        SendMessage((hwnd), OCBRM_SETXMLDEFAULTSIZE, 0, (LPARAM)(SIZE*)lpsize)


// OCBrowser notification
#define OCBRNM_REQUESTEDIT				(OCBRNM_FIRST-0)
#define OCBRNM_EDITORCLOSE				(OCBRNM_FIRST-1)
#define OCBRNM_EXTERNACTION				(OCBRNM_FIRST-2)
#define OCBRNM_PAGELOAD					(OCBRNM_FIRST-3)
#define OCBRNM_HINTCHANGED				(OCBRNM_FIRST-4)
#define OCBRNM_VALUECHANGED				(OCBRNM_FIRST-5)
#define OCBRNM_FOCUSCHANGED				(OCBRNM_FIRST-6)
#define OCBRNM_FOCUSRECYCLE				(OCBRNM_FIRST-7)
#define OCBRNM_PAGENOTFOUND				(OCBRNM_FIRST-8)
#define OCBRNM_ERRORMESSAGE				(OCBRNM_FIRST-9)
#define OCBRNM_DOACTION					(OCBRNM_FIRST-10)
#define OCBRNM_VSCROLLCHANGED 			(OCBRNM_FIRST-11)
#define OCBRNM_HSCROLLCHANGED 			(OCBRNM_FIRST-12)
#define OCBRNM_PAGECHANGED  			(OCBRNM_FIRST-13)
#define OCBRNM_BUTTONDOWN				(OCBRNM_FIRST-14)
#define OCBRNM_BUTTONUP					(OCBRNM_FIRST-15)
#define OCBRNM_MOUSEMOVE				(OCBRNM_FIRST-16)

#define OCBRNM_PAGESecurityErr_MakerID			(OCBRNM_FIRST-17)
#define OCBRNM_PAGESecurityErr_SerialNo			(OCBRNM_FIRST-18)
#define OCBRNM_PAGESecurityErr_MachineType		(OCBRNM_FIRST-19)
#define OCBRNM_PAGESecurityErr_ModelInfo		(OCBRNM_FIRST-20)
#define OCBRNM_CUSTOMCOMPONENTATTACHED			(OCBRNM_FIRST-21)
#define OCBRNM_CUSTOMCOMPONENTVISIBLECHANGED	(OCBRNM_FIRST-22)
#define OCBRNM_CUSTOMCOMPONENTDETACHED			(OCBRNM_FIRST-23)

#define OC3DM_SCALE					(OC3DM_FIRST + 1)
#define OC3DM_SHIFTX				(OC3DM_FIRST + 2)
#define OC3DM_SHIFTY				(OC3DM_FIRST + 3)
#define OC3DM_SHIFTZ				(OC3DM_FIRST + 4)
#define OC3DM_ROTATEVIEWX			(OC3DM_FIRST + 5)
#define OC3DM_ROTATEVIEWY			(OC3DM_FIRST + 6)
#define OC3DM_ROTATEVIEWZ			(OC3DM_FIRST + 7)
#define OC3DM_SETXYZLENGTH			(OC3DM_FIRST + 8)
#define OC3DM_RESETVIEW				(OC3DM_FIRST + 9)
#define OC3DM_DRAW					(OC3DM_FIRST + 10)

#define OC3DM_ADDCURVEDTUBE			(OC3DM_FIRST + 11)
#define OC3DM_ADDCUBOID				(OC3DM_FIRST + 12)
#define OC3DM_ADDCIRCLETUBE			(OC3DM_FIRST + 13)
#define OC3DM_ADDELLIPSETUBE		(OC3DM_FIRST + 14)
#define OC3DM_ADDSQUARETUBE			(OC3DM_FIRST + 15)
#define OC3DM_ADDWORKINGPATH		(OC3DM_FIRST + 16)
#define OC3DM_CLEARPIPE				(OC3DM_FIRST + 20)

#define OC3DM_SETWORKINGPATHCOLOR	(OC3DM_FIRST + 21)
#define OC3DM_SETWORKINGPOINTPOS	(OC3DM_FIRST + 22)
#define OC3DM_SETWORKINGPOINTSIZE	(OC3DM_FIRST + 23)
#define OC3DM_SETWORKINGPOINTCOLOR	(OC3DM_FIRST + 24)
#define OC3DM_ROTATEMODELX			(OC3DM_FIRST + 25)
#define OC3DM_ROTATEMODELY			(OC3DM_FIRST + 26)
#define OC3DM_ROTATEMODELZ			(OC3DM_FIRST + 27)

struct TOCBRRequestEditParam {
	LPCTSTR		lpszName;
	LPCTSTR		lpszType;
	BOOL		bHandled;	
};

struct TOCBRErrorMessageParam {
	LPCTSTR		lpszErrorMessageID;
	BOOL		bHandled;	
};

struct TOCBRVisbleChangeParam {
	LPCTSTR		lpszName;
	BOOL		bVisible;
};

// OCFenu message
#define OCFBM_PUTNUMOFBUTTON			(OCFBM_FIRST+0)
#define OCFenu_PutNumOfButton(hwnd,nNumOfButton) \
        SendMessage((hwnd), OCFBM_PUTNUMOFBUTTON, 0, (LPARAM)(LONG)nNumOfButton)

#define OCFBM_GETNUMOFBUTTON			(OCFBM_FIRST+1)
#define OCFenu_GetNumOfButton(hwnd) \
        (LONG)SendMessage((hwnd), OCFBM_GETNUMOFBUTTON, 0, 0)

#define OCFBM_PUTFENUXML				(OCFBM_FIRST+2)
#define OCFenu_PutFenuXml(hwnd,lpszFenuXml) \
        SendMessage((hwnd), OCFBM_PUTFENUXML, 0, (LPARAM)(LPCTSTR)lpszFenuXml)

#define OCFBM_GETFENUXML				(OCFBM_FIRST+3)
#define OCFenu_GetFenuXml(hwnd,lpBuffer,nLength) \
        SendMessage((hwnd), OCFBM_GETFENUXML, (WPARAM)(UINT)nLength, (WPARAM)(TCHAR *)lpBuffer)

#define OCFBM_PUTGROUPNAME				(OCFBM_FIRST+4)
#define OCFenu_PutGroupName(hwnd,lpszGroupName) \
        SendMessage((hwnd), OCFBM_PUTGROUPNAME, 0, (LPARAM)(LPCTSTR)lpszGroupName)

#define OCFBM_GETGROUPNAME				(OCFBM_FIRST+5)
#define OCFenu_GetGroupName(hwnd,lpBuffer,nLength) \
        SendMessage((hwnd), OCFBM_GETGROUPNAME, (WPARAM)(UINT)nLength, (WPARAM)(TCHAR *)lpBuffer)

#define OCFBM_PUTROOTFENU				(OCFBM_FIRST+6)
#define OCFenu_PutRootFenu(hwnd,lpszRootFenu) \
        SendMessage((hwnd), OCFBM_PUTROOTFENU, 0, (LPARAM)(LPCTSTR)lpszRootFenu)

#define OCFBM_GETROOTFENU				(OCFBM_FIRST+7)
#define OCFenu_GetRootFenu(hwnd,lpBuffer,nLength) \
        SendMessage((hwnd), OCFBM_GETROOTFENU, (WPARAM)(UINT)nLength, (WPARAM)(TCHAR *)lpBuffer)

#define OCFBM_PUTKEYPREVIEW				(OCFBM_FIRST+8)
#define OCFenu_PutKeyPreview(hwnd,nKeyPreview) \
        SendMessage((hwnd), OCFBM_PUTKEYPREVIEW, 0, (LPARAM)(BOOL)nKeyPreview )

#define OCFBM_GETKEYPREVIEW				(OCFBM_FIRST+9)
#define OCFenu_GetKeyPreview(hwnd) \
        (BOOL)SendMessage((hwnd), OCFBM_GETKEYPREVIEW, 0, 0)

#define OCFBM_LINKTO					(OCFBM_FIRST+10)
#define OCFenu_LinkTo(hwnd,lpszFenuName) \
        (HRESULT)SendMessage((hwnd), OCFBM_LINKTO, 0, (LPARAM)(LPCTSTR)lpszFenuName)

#define OCFBM_TOUCH						(OCFBM_FIRST+11)
#define OCFenu_Touch(hwnd) \
        SendMessage((hwnd), OCFBM_TOUCH, 0, 0)

#define OCFBM_GETBUTTONSTATE			(OCFBM_FIRST+12)
#define OCFenu_GetButtonState(hwnd,lpszButtonName) \
        (BOOL)SendMessage((hwnd), OCFBM_GETBUTTONSTATE, 0, (WPARAM)(LPCTSTR)lpszButtonName)

#define OCFBM_PUTBUTTONSTATE			(OCFBM_FIRST+13)
#define OCFenu_PutButtonState(hwnd,lpszButtonName,bEnable) \
        SendMessage((hwnd), OCFBM_PUTBUTTONSTATE, (WPARAM)(BOOL)bEnable, (LPARAM)(LPCTSTR)lpszButtonName )

#define OCFBM_GETBUTTONVISIBLE			(OCFBM_FIRST+14)
#define OCFenu_GetButtonVisible(hwnd,lpszButtonName) \
        (BOOL)SendMessage((hwnd), OCFBM_GETBUTTONVISIBLE, 0, (WPARAM)(LPCTSTR)lpszButtonName)

#define OCFBM_PUTBUTTONVISIBLE			(OCFBM_FIRST+15)
#define OCFenu_PutButtonVisible(hwnd,lpszButtonName,bVisible) \
        SendMessage((hwnd), OCFBM_PUTBUTTONVISIBLE, (WPARAM)(BOOL)bVisible, (LPARAM)(LPCTSTR)lpszButtonName )

#define OCFBM_GETBUTTONTEXTOVERPIC			(OCFBM_FIRST+16)
#define OCFenu_GetButtonTextOverPic(hwnd,lpszButtonName) \
        (BOOL)SendMessage((hwnd), OCFBM_GETBUTTONTEXTOVERPIC, 0, (WPARAM)(LPCTSTR)lpszButtonName)

#define OCFBM_PUTBUTTONTEXTOVERPIC			(OCFBM_FIRST+17)
#define OCFenu_PutButtonTextOverPic(hwnd,lpszButtonName,bTextOverPic) \
        SendMessage((hwnd), OCFBM_PUTBUTTONTEXTOVERPIC, (WPARAM)(BOOL)bTextOverPic, (LPARAM)(LPCTSTR)lpszButtonName )

#define OCFBM_GETBUTTONBACKCOLOR			(OCFBM_FIRST+18)
#define OCFenu_GetButtonBackColor(hwnd,lpszButtonName) \
        (COLORREF)SendMessage((hwnd), OCFBM_GETBUTTONBACKCOLOR, 0, (WPARAM)(LPCTSTR)lpszButtonName)

#define OCFBM_PUTBUTTONBACKCOLOR			(OCFBM_FIRST+19)
#define OCFenu_PutButtonBackColor(hwnd,lpszButtonName,clrBackColor) \
        SendMessage((hwnd), OCFBM_PUTBUTTONBACKCOLOR, (WPARAM)(COLORREF)clrBackColor, (LPARAM)(LPCTSTR)lpszButtonName )

#define OCFBM_GETBUTTONHOLDDOWN			(OCFBM_FIRST+20)
#define OCFenu_GetButtonHoldDown(hwnd,lpszButtonName) \
        (BOOL)SendMessage((hwnd), OCFBM_GETBUTTONHOLDDOWN, 0, (WPARAM)(LPCTSTR)lpszButtonName)

#define OCFBM_PUTBUTTONHOLDDOWN			(OCFBM_FIRST+21)
#define OCFenu_PutButtonHoldDown(hwnd,lpszButtonName,bHoldDown) \
        SendMessage((hwnd), OCFBM_PUTBUTTONHOLDDOWN, (WPARAM)(BOOL)bHoldDown, (LPARAM)(LPCTSTR)lpszButtonName )

#define OCFBM_GETBUTTONPICTURE			(OCFBM_FIRST+22)
#define OCFenu_GetButtonPicture(hwnd,lpszButtonName) \
        (BOOL)SendMessage((hwnd), OCFBM_GETBUTTONPICTURE, 0, (WPARAM)(LPCTSTR)lpszButtonName)

#define OCFBM_PUTBUTTONPICTURE			(OCFBM_FIRST+23)
#define OCFenu_PutButtonPicture(hwnd,lpszButtonName,lpszPicture) \
        SendMessage((hwnd), OCFBM_PUTBUTTONPICTURE, (WPARAM)(LPCTSTR)lpszPicture, (LPARAM)(LPCTSTR)lpszButtonName )

#define OCFBM_GETBUTTONLIGHTON			(OCFBM_FIRST+24)
#define OCFenu_GetButtonLightOn(hwnd,lpszButtonName) \
        (BOOL)SendMessage((hwnd), OCFBM_GETBUTTONLIGHTON, 0, (WPARAM)(LPCTSTR)lpszButtonName)

#define OCFBM_PUTBUTTONLIGHTON			(OCFBM_FIRST+25)
#define OCFenu_PutButtonLightOn(hwnd,lpszButtonName,bLightOn) \
        SendMessage((hwnd), OCFBM_PUTBUTTONLIGHTON, (WPARAM)(BOOL)bLightOn, (LPARAM)(LPCTSTR)lpszButtonName )

#define OCFBM_GETACTIVEFENU				(OCFBM_FIRST+26)
#define OCFenu_GetActiveFenu(hwnd,lpBuffer,nLength) \
        SendMessage((hwnd), OCFBM_GETACTIVEFENU, (WPARAM)(UINT)nLength, (WPARAM)(TCHAR *)lpBuffer)

#define OCFBM_GETBUTTONCAPTION			(OCFBM_FIRST+27)
#define OCFenu_GetButtonCaption(hwnd,lpszButtonName) \
        (BOOL)SendMessage((hwnd), OCFBM_GETBUTTONCAPTION, 0, (WPARAM)(LPCTSTR)lpszButtonName)

#define OCFBM_PUTBUTTONCAPTION			(OCFBM_FIRST+28)
#define OCFenu_PutButtonCaption(hwnd,lpszButtonName,lpszCaption) \
        SendMessage((hwnd), OCFBM_PUTBUTTONCAPTION, (WPARAM)(LPCTSTR)lpszCaption, (LPARAM)(LPCTSTR)lpszButtonName )

#define OCFBM_GETBUTTONFORECOLOR		(OCFBM_FIRST+29)
#define OCFenu_GetButtonForeColor(hwnd,lpszButtonName) \
        (COLORREF)SendMessage((hwnd), OCFBM_GETBUTTONFORECOLOR, 0, (WPARAM)(LPCTSTR)lpszButtonName)

#define OCFBM_PUTBUTTONFORECOLOR		(OCFBM_FIRST+30)
#define OCFenu_PutButtonForeColor(hwnd,lpszButtonName,clrBackColor) \
        SendMessage((hwnd), OCFBM_PUTBUTTONFORECOLOR, (WPARAM)(COLORREF)clrForeColor, (LPARAM)(LPCTSTR)lpszButtonName )

#define OCFBM_PUTUSERLEVEL			(OCFBM_FIRST+31)
#define OCFenu_PutUserLevel(hwnd,nUserLevel) \
        SendMessage((hwnd), OCFBM_PUTUSERLEVEL, 0, (LPARAM)(INT)nUserLevel)

#define OCFBM_GETUSERLEVEL			(OCFBM_FIRST+32)
#define OCFenu_GetUserLevel(hwnd) \
        (INT)SendMessage((hwnd), OCFBM_GETUSERLEVEL, 0, 0)

#define OCFBM_PUTBUTTONUSERLEVEL			(OCFBM_FIRST+33)
#define OCFenu_PutButtonUserLevel(hwnd,nLevel) \
        SendMessage((hwnd), OCFBM_PUTBUTTONUSERLEVEL, 0, (LPARAM)(INT)nLevel)

#define OCFBM_GETBUTTONUSERLEVEL			(OCFBM_FIRST+34)
#define OCFenu_GetButtonUserLevel(hwnd) \
        (INT)SendMessage((hwnd), OCFBM_GETBUTTONUSERLEVEL, 0, 0)

#define OCFBM_GETTITLE			(OCFBM_FIRST+37)
#define OCFenu_GetTitle(hwnd,lpszXMLName) \
        (BOOL)SendMessage((hwnd), OCFBM_GETTITLE, 0, (WPARAM)(LPCTSTR)lpszXMLName)

#define OCFBM_ADDEXTENDXML					(OCFBM_FIRST+38)
#define OCFenu_addExtendXML(hwnd,lpszFileName, isModify) \
        (HRESULT)SendMessage((hwnd), OCFBM_ADDEXTENDXML, (WPARAM)(BOOL)isModify, (LPARAM)(LPCTSTR)lpszFileName)

#define OCFBM_PUTBUTTONACTIONS				(OCFBM_FIRST+39)
#define OCFenu_PutButtonActions(hwnd,lpszActions) \
        SendMessage((hwnd), OCFBM_PUTBUTTONACTIONS, 0, (LPARAM)(LPCTSTR)lpszActions)

#define OCFBM_GETBUTTONACTIONS				(OCFBM_FIRST+40)
#define OCFenu_GetButtonActions(hwnd,lpBuffer,nLength) \
        SendMessage((hwnd), OCFBM_GETBUTTONACTIONS, (WPARAM)(UINT)nLength, (WPARAM)(TCHAR *)lpBuffer)

#define OCFBM_PUTBUTTONLINK				(OCFBM_FIRST+41)
#define OCFenu_PutButtonLink(hwnd,lpszActions) \
        SendMessage((hwnd), OCFBM_PUTBUTTONLINK, 0, (LPARAM)(LPCTSTR)lpszActions)

#define OCFBM_GETBUTTONLINK				(OCFBM_FIRST+42)
#define OCFenu_GetButtonLink(hwnd,lpBuffer,nLength) \
        SendMessage((hwnd), OCFBM_GETBUTTONLINK, (WPARAM)(UINT)nLength, (WPARAM)(TCHAR *)lpBuffer)

#define OCFBM_PUTBUTTONACTION				(OCFBM_FIRST+43)
#define OCFenu_PutButtonAction(hwnd,lpszAction) \
        SendMessage((hwnd), OCFBM_PUTBUTTONACTION, 0, (LPARAM)(LPCTSTR)lpszAction)

#define OCFBM_GETBUTTONACTION				(OCFBM_FIRST+44)
#define OCFenu_GetButtonAction(hwnd,lpBuffer,nLength) \
        SendMessage((hwnd), OCFBM_GETBUTTONACTION, (WPARAM)(UINT)nLength, (WPARAM)(TCHAR *)lpBuffer)

#define OCFBM_PUTALIGNMENT					( OCFBM_FIRST + 45 )
#define OCFenu_PutAlignment( hwnd, nAlignment ) \
        SendMessage( (hwnd), OCFBM_PUTALIGNMENT, 0, (LPARAM)(INT)nAlignment )

#define OCFBM_PUTBUTTON3D					( OCFBM_FIRST + 46 )
#define OCFenu_PutButton3D( hwnd, bButton3D ) \
        SendMessage( (hwnd), OCFBM_PUTBUTTON3D, 0, (LPARAM)(BOOL)bButton3D )

#define OCFBM_PUTLEVEL3D					( OCFBM_FIRST + 47 )
#define OCFenu_PutLevel3D( hwnd, nLevel3D ) \
        SendMessage( (hwnd), OCFBM_PUTLEVEL3D, 0, (LPARAM)(INT)nLevel3D )

#define OCFBM_PUTNOFUNC						( OCFBM_FIRST + 48 )
#define OCFenu_PutNoFunc( hwnd, bNoFunc ) \
        SendMessage( (hwnd), OCFBM_PUTNOFUNC, 0, (LPARAM)(BOOL)bNoFunc )

#define OCFBM_PUTNOLR						( OCFBM_FIRST + 49 )
#define OCFenu_PutNoLR( hwnd, bNoLR ) \
        SendMessage( (hwnd), OCFBM_PUTNOLR, 0, (LPARAM)(BOOL)bNoLR )

#define OCFBM_PUTBIGLR						( OCFBM_FIRST + 50 )
#define OCFenu_PutBigLR( hwnd, bBigLR ) \
        SendMessage( (hwnd), OCFBM_PUTBIGLR, 0, (LPARAM)(BOOL)bBigLR )

#define OCFBM_PUTTEXTOVERPIC				( OCFBM_FIRST + 51 )
#define OCFenu_PutTextOverPic( hwnd, bTextOverPic ) \
        SendMessage( (hwnd), OCFBM_PUTTEXTOVERPIC, 0, (LPARAM)(BOOL)bTextOverPic )

#define OCFBM_REDRAW				( OCFBM_FIRST + 52 )
#define OCFenu_ReDraw( hwnd ) \
        SendMessage( (hwnd), OCFBM_REDRAW, 0, 0 )

#define OCFBM_PUTVERTICAL			( OCFBM_FIRST + 53 )
#define OCFenu_PutVertical( hwnd ) \
        SendMessage( (hwnd), OCFBM_PUTVERTICAL, 0, (LPARAM)(BOOL)bVertical )

struct TOCFBRequestExecuteParam {
	LPCTSTR		lpszActionXml;
	BOOL		bAck;	
};

// OCPathSimu event code
#define OCFBNM_DOACTION					1
#define OCFBNM_KEYDOWN					2
#define OCFBNM_KEYUP					3
#define OCFBNM_REQUESTEXECUTE			4
#define OCFBNM_SETFOCUS					5

// OCLabel message
#define OCLBM_PUTFORECOLOR				(OCLBM_FIRST + 0)
#define OCLabel_PutForeColor(hwnd, Val) \
        (BOOL)SendMessage((hwnd), OCLBM_PUTFORECOLOR, 0, (LPARAM)(COLORREF)(Val))

#define OCLBM_PUTBACKCOLOR				(OCLBM_FIRST + 1)
#define OCLabel_PutBackColor(hwnd, Val) \
        (BOOL)SendMessage((hwnd), OCLBM_PUTBACKCOLOR, 0, (LPARAM)(COLORREF)(Val))

#define OCLBM_PUTFONT					(OCLBM_FIRST + 2)
#define OCLabel_PutFont(hwnd, Val) \
        (BOOL)SendMessage((hwnd), OCLBM_PUTFONT, 0, (LPARAM)(LPLOGFONT)(Val))

#define OCLBM_PUTCAPTION				(OCLBM_FIRST + 4)
#define OCLabel_PutCaption(hwnd, lpVal) \
        (BOOL)SendMessage((hwnd), OCLBM_PUTCAPTION, 0, (LPARAM)(LPCTSTR)lpVal)

#define OCLBM_PUTALIGNMENT				(OCLBM_FIRST + 5)
#define OCLabel_PutAlignment(hwnd, nAlignment) \
        (BOOL)SendMessage((hwnd), OCLBM_PUTALIGNMENT, 0, (LPARAM)(LONG)(nAlignment))


// LadderView
#define OCLDM_GETCURROW					(OCLDM_FIRST+1)
#define OCLadder_GetCurrentRow(hwnd) \
        SendMessage((hwnd), OCLDM_GETCURROW, 0, 0)

#define OCLDM_GETCURCOL					(OCLDM_FIRST+2)
#define OCLadder_GetCurrentCol(hwnd) \
        SendMessage((hwnd), OCLDM_GETCURCOL, 0, 0)

#define OCLDM_SCROLLTO					(OCLDM_FIRST+3)
#define OCLadder_ScrollTo(hwnd, Val) \
        SendMessage((hwnd), OCLDM_SCROLLTO, 0, (LPARAM)(Val))

#define OCLDM_FIND						(OCLDM_FIRST+4)
#define OCLadder_Find(hwnd, lpBuffer) \
        SendMessage((hwnd), OCLDM_FIND, 0, (LPARAM)(TCHAR *)lpBuffer)

#define OCLDM_FINDNEXT					(OCLDM_FIRST+5)
#define OCLadder_FindNext(hwnd) \
        SendMessage((hwnd), OCLDM_FINDNEXT, 0, 0)

#define OCLDM_FINDPREV					(OCLDM_FIRST+6)
#define OCLadder_FindPrev(hwnd) \
        SendMessage((hwnd), OCLDM_FINDPREV, 0, 0)

#define OCLDM_GETTOTALROWS				(OCLDM_FIRST+7)
#define OCLadder_GetTotalRows(hwnd) \
        (UINT)SendMessage((hwnd), OCLDM_GETTOTALROWS, 0, 0)

#define OCLDM_PUTREFRESHENABLED			(OCLDM_FIRST+8)
#define OCLadder_PutRefreshEnabled(hwnd) \
		SendMessage((hwnd), OCLDM_PUTREFRESHENABLED, 0, (LPARAM)(BOOL)(RefreshEnabled))

#define OCLDM_RELOADLADDERFILE			(OCLDM_FIRST+9)
#define OCLadder_ReloadLadderFile(hwnd) \
		SendMessage((hwnd), OCLDM_RELOADLADDERFILE, 0, (LPARAM)(TCHAR *)(LadderFilePath))

#define OCLDM_GETCELLLONGCOMMENT		(OCLDM_FIRST+10)
#define OCLadder_GetCellLongComment(hwnd,lpszCellName) \
        SendMessage((hwnd), OCLDM_GETCELLLONGCOMMENT, 0, (WPARAM)(LPCTSTR)lpszCellName)

#define OCLDM_PUTLADDERXML				(OCLDM_FIRST+11)
#define OCLadder_PutLadderXml(hwnd,lpszCellName) \
        SendMessage((hwnd), OCLDM_PUTLADDERXML, 0, (WPARAM)(LPCTSTR)lpszCellName)

#define OCLDM_PUTSELECTCOLOR			(OCLDM_FIRST+12)
#define OCLadder_PutSelectColor(hwnd, Val) \
		SendMessage((hwnd), OCLDM_PUTSELECTCOLOR, 0, (LPARAM)(COLORREF)(Val))

#define OCLDM_ISCELL					(OCLDM_FIRST+13)
#define OCLadder_IsCell(hwnd, Val) \
		SendMessage((hwnd), OCLDM_ISCELL, 0, (LPARAM)(Val))

#define OCLDM_GETCELLKEY				(OCLDM_FIRST+14)
#define OCLadder_GetCellKey(hwnd, Val) \
		SendMessage((hwnd), OCLDM_GETCELLKEY, 0, (LPARAM)(Val))

#define OCLDM_GETCELLGROUP				(OCLDM_FIRST+15)
#define OCLadder_GetCellGroup(hwnd, Val) \
		SendMessage((hwnd), OCLDM_GETCELLGROUP, 0, (LPARAM)(Val))

#define OCLDM_GETCELLTYPE				(OCLDM_FIRST+16)
#define OCLadder_GetCellType(hwnd, Val) \
		SendMessage((hwnd), OCLDM_GETCELLTYPE, 0, (LPARAM)(Val))

#define OCLDM_GETCELLHINT				(OCLDM_FIRST+17)
#define OCLadder_GetCellHint(hwnd, Val) \
		SendMessage((hwnd), OCLDM_GETCELLHINT, 0, (LPARAM)(Val))

#define OCLDM_GETARGSNUM				(OCLDM_FIRST+18)
#define OCLadder_GetArgsNum(hwnd, Val) \
		SendMessage((hwnd), OCLDM_GETARGSNUM, 0, (LPARAM)(Val))

#define OCLDM_GETARGSTYPES				(OCLDM_FIRST+19)
#define OCLadder_GetArgsTypes(hwnd, Val) \
		SendMessage((hwnd), OCLDM_GETARGSTYPES, 0, (LPARAM)(Val))

#define OCLDM_GETARGSTITLES				(OCLDM_FIRST+20)
#define OCLadder_GetArgsTitles(hwnd, Val) \
		SendMessage((hwnd), OCLDM_GETARGSTITLES, 0, (LPARAM)(Val))

#define OCLDM_GETARGSVALS				(OCLDM_FIRST+21)
#define OCLadder_GetArgsVals(hwnd, Val) \
		SendMessage((hwnd), OCLDM_GETARGSVALS, 0, (LPARAM)(Val))

#define OCLDM_SETCELLARGS				(OCLDM_FIRST+22)
#define OCLadder_SetCellArgs(hwnd, lpszArgValues) \
		SendMessage((hwnd), OCLDM_SETCELLARGS, 0, (WPARAM)(LPCTSTR)lpszArgValues)

#define OCLDM_STORELADDERFILE			(OCLDM_FIRST+23)
#define OCLadder_StroreLadderFile(hwnd) \
		SendMessage((hwnd), OCLDM_STORELADDERFILE, 0, 0)

#define OCLDM_GETSYNTAXERRORLINE		(OCLDM_FIRST+24)
#define OCLadder_GetSyntaxErrorNO(hwnd) \
		SendMessage((hwnd), OCLDM_GETSYNTAXERRORLINE, 0, 0)


#define OCLDM_ISBICELL					(OCLDM_FIRST+25)
#define OCLadder_IsBiCell(hwnd)			\
		SendMessage((hwnd), OCLDM_ISBICELL, 0, (LPARAM)(Val))

#define OCLDM_ISCOMMENTLINE				(OCLDM_FIRST+26)
#define OCLadder_IsCommentLine(hwnd)	\
		SendMessage((hwnd), OCLDM_ISCOMMENTLINE, 0, (LPARAM)(Val))

#define OCLDM_ISLEGALFORINSERT			(OCLDM_FIRST+27)
#define OCLadder_IsLegalForInsert(hwnd)		\
		SendMessage((hwnd), OCLDM_ISLEGALFORINSERT, 0, (LPARAM)(Val))

#define OCLDM_PUTTEMPLATECELL			(OCLDM_FIRST+28)
#define OCLadder_PutTemplateCell(hwnd)	\
		SendMessage((hwnd), OCLDM_PUTTEMPLATECELL, 0, (LPARAM)(Val))

#define OCLDM_COPYCELLTOTEMP			(OCLDM_FIRST+29)
#define OCLadder_CopyCellToTemp(hwnd)	\
		SendMessage((hwnd), OCLDM_COPYCELLTOTEMP, 0, (LPARAM)(Val))

#define OCLDM_PASTECELLFROMTEMP			(OCLDM_FIRST+30)
#define OCLadder_PasteCellFromTemp(hwnd)\
		SendMessage((hwnd), OCLDM_PASTECELLFROMTEMP, 0, (LPARAM)(Val))

#define OCLDM_DELETECELLCONTENT			(OCLDM_FIRST+31)
#define OCLadder_DeleteCellContent(hwnd)\
		SendMessage((hwnd), OCLDM_DELETECELLCONTENT, 0, (LPARAM)(Val))

#define OCLDM_DELETEHORIZONTALLINE		(OCLDM_FIRST+32)
#define OCLadder_DeleteHorizontalLine(hwnd)	\
		SendMessage((hwnd), OCLDM_DELETEHORIZONTALLINE, 0, (LPARAM)(Val))

#define OCLDM_DELETEVERTICALLINE		(OCLDM_FIRST+33)
#define OCLadder_DeleteVerticalLine(hwnd)	\
		SendMessage((hwnd), OCLDM_DELETEVERTICALLINE, 0, (LPARAM)(Val))

#define OCLDM_INSERTEMPTYROW			(OCLDM_FIRST+34)
#define OCLadder_InsertEmptyRow(hwnd)		\
		SendMessage((hwnd), OCLDM_INSERTEMPTYROW, 0, (LPARAM)(Val))

#define OCLDM_INSERTHORIZONTALLINE		(OCLDM_FIRST+35)
#define OCLadder_InsertHorizontalLine(hwnd)	\
		SendMessage((hwnd), OCLDM_INSERTHORIZONTALLINE, 0, (LPARAM)(Val))

#define OCLDM_INSERTVERTICALLINE		(OCLDM_FIRST+36)
#define OCLadder_InsertVerticallLine(hwnd)	\
		SendMessage((hwnd), OCLDM_INSERTVERTICALLINE, 0, (LPARAM)(Val))

#define OCLDM_SETCELLSIZE		(OCLDM_FIRST+37)
#define OCLadder_SetCellSize(hwnd)	\
		SendMessage((hwnd), OCLDM_SETCELLSIZE, 0, (LPARAM)(Val))

// OCLadder notification
#define OCLDNM_ONFOCUSCHANGED		(OCLDNM_FIRST-0)
#define OCLDNM_MOUSEMOVE			(OCLDNM_FIRST-1)

// API initialization/de-initialization
HRESULT WINAPI OCUserInit( void );
void WINAPI OCUserUninit( void );

LONG WINAPI Imp_ResMgr_GetLocaleID( void );

TCHAR** WINAPI Imp_ResMgr_LookupPointer( LPCTSTR lpszKey );
void WINAPI ParserPreConfigValue( LPCTSTR XMLContent,  TCHAR* pPropertyName, TCHAR* pPropertyValue );
HRESULT WINAPI OCUser_MMIGetDirs( LPCTSTR lpszName, TCHAR *lpBuffer, LONG nLength );
BOOL WINAPI Imp_ResMgr_GetAxisName( LONG nAxidID, TCHAR* lpBuffer );

#ifdef __cplusplus
}
#endif 

#endif // __OCUSER_H_

