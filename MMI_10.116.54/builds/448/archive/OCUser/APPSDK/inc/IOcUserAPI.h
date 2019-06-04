#pragma once

#include "nstdlib.h"

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

#if !defined(STRUCT_POINT_W)
#define STRUCT_POINT_W

typedef struct tagPOINT_W {
   double x;
   double y;
   double z;
} POINT_W;

#endif // STRUCT_POINT_W

class IOcUserAPI
{
public:

	// control access interface
	virtual BOOL OCUser_Polyline( HWND hwnd, const POINT *lppt, int cPoints ) = 0;
	virtual BOOL OCUser_Polygon( HWND hwnd, const POINT *lppt, int cPoints ) = 0;
	virtual int OCUser_DrawText( HWND hwnd, LPCTSTR lpString, int nCount, LPRECT lpRect, UINT uFormat ) = 0;
	virtual COLORREF OCUser_SetTextColor( HWND hwnd, COLORREF crColor ) = 0;
	virtual COLORREF OCUser_GetTextColor( HWND hwnd ) = 0;
	virtual COLORREF OCUser_SetFillColor( HWND hwnd, COLORREF crColor ) = 0;
	virtual COLORREF OCUser_GetFillColor( HWND hwnd ) = 0;
	virtual COLORREF OCUser_SetLineColor( HWND hwnd, COLORREF crColor ) = 0;
	virtual COLORREF OCUser_GetLineColor( HWND hwnd ) = 0;
	virtual void OCUser_EraseBackground( HWND hwnd ) = 0;
	virtual void OCUser_Flush( HWND hwnd ) = 0;
	virtual void OCCanvas_BeginDraw( HWND hwnd ) = 0;
	virtual void OCCanvas_EndDraw( HWND hwnd ) = 0;
	virtual void OCCanvas_DrawFrame( HWND hwnd ) = 0;
	virtual void OCCanvas_DrawGrid( HWND hwnd ) = 0;
	virtual BOOL OCCanvas_Polyline( HWND hwnd, const POINT_W *lpPoints, int nCount ) = 0;
	virtual BOOL OCCanvas_Polygon( HWND hwnd, const POINT_W *lpPoints, int nCount ) = 0;
	virtual BOOL OCCanvas_FillCircle( HWND hwnd, double cx, double cy, double cz, double radius ) = 0;

	virtual void OCCanvas_GetObjectMatrix( HWND hwnd, double *lpMatrix ) = 0;
	// a[] the data sequence is a11, a12, a13, a14, a21, a22, .., a41, a42, a43, a44.
	// the translation vector is (a14,a24,a34)

	virtual void OCCanvas_PutObjectMatrix( HWND hwnd, double *lpMatrix ) = 0;
	// a[] the data sequence is a11, a12, a13, a14, a21, a22, .., a41, a42, a43, a44.
	// the translation vector is (a14,a24,a34)

	virtual void OCCanvas_LPtoDP( HWND hwnd, double *lpPoint3d ) = 0;
	// lpPoint3d[] is 3-dimension point double value. you should fill 0 for don't care dimension.

	virtual LONG OCPathSimu_GetPosition(HWND hwnd, UINT index) = 0;
	virtual BOOL OCPathSimu_GetGlobalVar(HWND hwnd, UINT index, TOcVariant *pVal) = 0;
	virtual ULONG OCPathSimu_GetSequenceNo(HWND hwnd) = 0;
	virtual ULONG OCPathSimu_GetLineNo(HWND hwnd) = 0;
	virtual UINT OCPathSimu_GetProgramName(HWND hwnd, TCHAR *lpBuffer, UINT count) = 0;
	virtual void OCPathSimu_SetDrawRange(HWND hwnd, long nStart_N, long nEnd_N, long nStart_L, long nEnd_L) = 0;
	virtual ULONG OCPathSimu_isUndoEnable(HWND hwnd) = 0;
	virtual BOOL OCBrowser_PutProperty( HWND hwnd, LPCTSTR lpszName, LPCTSTR lpszValue ) = 0;
	virtual UINT OCBrowser_GetProperty( HWND hwnd, LPCTSTR lpszName, TCHAR *lpBuffer, UINT count ) = 0;
	virtual void OCBrowser_PutValue( HWND hwnd, LPCTSTR lpszName, LPVARIANT lpNewVal ) = 0;
	virtual void OCBrowser_GetValue( HWND hwnd, LPCTSTR lpszName, LPVARIANT lpVal ) = 0;
	virtual void OCBrowser_NewPage( HWND hwnd, LPCTSTR lpszPageName, LPCTSTR lpszPageType ) = 0;
	virtual void OCBrowser_NewComponent( HWND hwnd, LPCTSTR lpszName, LPCTSTR lpszComponentType ) = 0;

	// resource manager interface
	virtual void ResMgr_PutFilenameFilter( LPCTSTR lpszFilter ) = 0;
	virtual void ResMgr_GetFilenameFilter( TCHAR *lpBuffer, UINT count ) = 0;
	virtual void ResMgr_PutLocaleID( LONG NewID ) = 0;
	virtual LONG ResMgr_GetLocaleID( void ) = 0;
	virtual void ResMgr_GetCommonDirectory( TCHAR *lpBuffer, UINT count ) = 0;
	virtual void ResMgr_GetLocaleDirectory( TCHAR *lpBuffer, UINT count ) = 0;
	virtual TCHAR * ResMgr_Lookup( LPCTSTR lpszKey ) = 0;
	virtual void ResMgr_AddRes( LPCTSTR lpszDirectory ) = 0;
	virtual void ResMgr_ClearRes( void ) = 0;

	// export device access interface
	virtual HRESULT CncDevice_GetString( TCHAR *szDeviceName, TCHAR *szFormat, TCHAR *lpBuffer, UINT count ) = 0;
	virtual HRESULT CncDevice_PutString( TCHAR *szDeviceName, TCHAR *szFormat, LPCTSTR lpszValueIn ) = 0;
	
	// XMLPreConfig
	virtual HRESULT JXMLPreConfig_UpdateFileName( TCHAR *szFileName) = 0;

	// huge file editor interface
	virtual HRESULT HugeFile_Export( TCHAR *szSrc, TCHAR *szDst, PFNPROGRESS pFn ) = 0;
	// Get current block of current program
	virtual HRESULT MultiTCPGetCncCurBlock( HANDLE hClientLink, TCHAR *lpCurProgramName, LONG nNameLength, LONG *nCurLineNo, TCHAR *lpCurBlock, LONG nBlockLength ) = 0;

	// Decryption file interface
	virtual HRESULT DesFileToBuff( TCHAR *FileName, BYTE *buff, unsigned long *buffersize, TCHAR *key, TCHAR *DesKey ) = 0;
	virtual void OCBrowser_ClearListitem( HWND hwnd, LPCTSTR lpszName ) = 0;
	virtual void OCBrowser_PutItemToListitem( HWND hwnd, LPCTSTR lpszName, LPCTSTR lpszAttr, TCHAR* lpszVal, UINT nIndex ) = 0;

};
