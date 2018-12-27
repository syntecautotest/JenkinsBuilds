// XComponent.h: interface for the CXComponent class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_XCOMPONENT_H__7CD9DC07_AEE4_4B81_B894_C22D803D9BC6__INCLUDED_)
#define AFX_XCOMPONENT_H__7CD9DC07_AEE4_4B81_B894_C22D803D9BC6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "nstdlib.h"
#include "IXPaintable.h"

#if !defined(UNDER_CE)
class CObList;
#endif
class IGraphicsPeer;
class CGraphics3d;
class CRectangle;

class SWINGAPI CXComponent : public IXPaintable
{
public:
	CXComponent();
	// default constructor

	virtual ~CXComponent();
	// destructor

	void addComponent( CXComponent *pComponent );
	// add child component

	void removeComponent( CXComponent *pComponent );
	// remove child component

	void requestRepaint( CXComponent *pChild );
	// request to repaint specified child

	void setGraphicsPeer( IGraphicsPeer *pGraphicsPeer );
	// set graphics peer

	// to implement IXPaintable interface
	void processPaint( void );
	// process paint event

public:
// implement interface for component framework provider
	void repaint( void );
	// request to update client area

	void getClientRect( CRectangle *pRect );
	// get client rectangle

	BOOL notifyParent( UINT code );
	// Places a message in the window¡¦s message queue and then returns
	// without waiting for the corresponding window to process the message.
	// return nonzero if the message is posted; otherwise 0.

	BOOL isPaintable( void );
	// query whether window paintable

	CGraphics3d *getGraphics( void );
	// get graphics

	void flush( void );
	// flush graphics cache

// implement interface for component service provider
	virtual void paint( CGraphics3d *g );
	// paint children

	virtual void notifyAttachPeer( void );
	// notify this component has been attach a new graphics peer

private:
	CXComponent *m_pContainer;	// pointer to parent container

	BOOL m_bPaintDirty;			// paint dirty flag

	CObList *m_pChildList;		// child component list

	CGraphics3d *m_pGraphics;		// graphic context

	IGraphicsPeer *m_pGraphicsPeer;	// associated graphic peer

	BOOL m_bPeerAttached;			// whether this object has peer attached
};

#endif // !defined(AFX_XCOMPONENT_H__7CD9DC07_AEE4_4B81_B894_C22D803D9BC6__INCLUDED_)
