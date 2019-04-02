// IPathIterator.h: interface for the IPathIterator class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IPATHITERATOR_H__8910CF76_6F46_40AD_AB3E_242E7E269312__INCLUDED_)
#define AFX_IPATHITERATOR_H__8910CF76_6F46_40AD_AB3E_242E7E269312__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class IPathIterator  
{
public:
	// constant for segment type
	enum ESegType {
		SEG_LINETO,
		SEG_MOVETO
	};

	virtual int getSegment( double coords[] ) = 0;
	// query current segment data.
	// return the type of segment

	virtual int isMore( void ) = 0;
	// query whether path has finished
};

#endif // !defined(AFX_IPATHITERATOR_H__8910CF76_6F46_40AD_AB3E_242E7E269312__INCLUDED_)
