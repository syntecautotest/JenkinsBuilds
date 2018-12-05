// Swing.h: interface for the Swing classes.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SWING_H__F5AF6904_F662_11D2_B6AB_000000000000__INCLUDED_)
#define AFX_SWING_H__F5AF6904_F662_11D2_B6AB_000000000000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef __cplusplus
extern "C" {
#endif

#ifndef TOCHOLE_STRUCT_
#define TOCHOLE_STRUCT_

typedef struct tagTOcHole {
	double		Position[3];
	double		Radius;
	long		LineNo;
} TOCHole;

#endif // TOCHOLE_STRUCT_

#ifdef __cplusplus
}
#endif 

#endif // !defined(AFX_SWING_H__F5AF6904_F662_11D2_B6AB_000000000000__INCLUDED_)
