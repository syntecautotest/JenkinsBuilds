// Cube3d.h: interface for the CCube3d class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CUBE3D_H__A56513B3_C3B9_43D2_B1FF_C8454AD4508F__INCLUDED_)
#define AFX_CUBE3D_H__A56513B3_C3B9_43D2_B1FF_C8454AD4508F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IPathIterator.h"
#include "Matrix4d.h"
#include "Point3d.h"

class CCube3d  
{
public:

	class CPathIterator : public IPathIterator
	{
	public:
		CPathIterator();
		virtual ~CPathIterator();
		// constructor/destructor

		void setOwner( CCube3d *pOwner );
		// set owner

		void init( CMatrix4d &Tx );
		// init for a new arc path iteration

		int getSegment( double coords[] );
		// query segment data.
		// return the type of segment

		int isMore( void );
		// query whether path has finished

	private:
		CMatrix4d		m_Tx;
		// associate affine transform

		CCube3d *m_pOwner;
		// my owner

		// working variable
		int m_State;

		// cahce cube data
		CPoint3d m_minPoint;
		CPoint3d m_maxPoint;
	};

public:
	CCube3d();
	// constructor

	virtual ~CCube3d();
	// destructor

	void set( CCube3d &cube );
	// set this cube from specified cube

	void setMinPoint( double x, double y, double z );
	// set minimum point

	void setMinPoint( CTuple3d &pt );
	// set minimum point

	void setMaxPoint( double x, double y, double z );
	// set maximum point

	void setMaxPoint( CTuple3d &pt );
	// set maximum point

	void getMinPoint( CTuple3d &pt );
	// get minimum point

	void getMaxPoint( CTuple3d &pt );
	// get maximum point

	IPathIterator *getPathIterator( CMatrix4d &Tx );
	// return path iterator

private:
	CPathIterator m_PathIterator;

	CPoint3d m_minPoint;
	CPoint3d m_maxPoint;
};

#endif // !defined(AFX_CUBE3D_H__A56513B3_C3B9_43D2_B1FF_C8454AD4508F__INCLUDED_)
