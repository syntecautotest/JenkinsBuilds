// IXPaintable.h: interface for the IXPaintable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IXPAINTABLE_H__72498906_BEA6_413F_8D2F_ADAD5E708A0D__INCLUDED_)
#define AFX_IXPAINTABLE_H__72498906_BEA6_413F_8D2F_ADAD5E708A0D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class SWINGAPI IXPaintable  
{
public:
	// to implement IXPaintable interface
	virtual void processPaint( void ) = 0;
	// process paint event
};

#endif // !defined(AFX_IXPAINTABLE_H__72498906_BEA6_413F_8D2F_ADAD5E708A0D__INCLUDED_)
