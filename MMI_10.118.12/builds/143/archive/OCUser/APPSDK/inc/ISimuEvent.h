// ISimuEvent.h: interface for the ISimuEvent class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ISIMUEVENT_H__FE5DE85B_F281_4FF5_B038_530BADCED40F__INCLUDED_)
#define AFX_ISIMUEVENT_H__FE5DE85B_F281_4FF5_B038_530BADCED40F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "nstdlib.h"
#include "EventCPBase.h"

class SWINGAPI ISimuEvent  
{
public:
	virtual void CNCAPI OnComplete( void ) = 0;
	// to notify simulation task has complete

	virtual void CNCAPI OnAlarm( void ) = 0;
	// to notify there are alarm occur

	virtual void CNCAPI OnDrawBegin( void ) = 0;
	// to notify draw begin

	virtual void CNCAPI OnDrawEnd( void ) = 0;
	// to notify draw end

	virtual void CNCAPI OnSelectAutoMargin( void ) = 0;
	// to notify auto margin calculation selection

	virtual void CNCAPI OnZoomAccept( void ) = 0;
	// to notify zoom operation has accepts
};

class SWINGAPI CSimuEventAdapter:
public ISimuEvent
{
public:
	CSimuEventAdapter();
	virtual ~CSimuEventAdapter();

	void CNCAPI OnComplete( void );
	// to notify simulation task has complete

	void CNCAPI OnAlarm( void );
	// to notify there are alarm occur

	void CNCAPI OnDrawBegin( void );
	// to notify draw begin

	void CNCAPI OnDrawEnd( void );
	// to notify draw end

	void CNCAPI OnSelectAutoMargin( void );
	// to notify auto margin selection

	void CNCAPI OnZoomAccept( void );
	// to notify zoom operation has accepts
};

class CSimuEventCP:
public CEventCPBase
{
public:
	CSimuEventCP( int capacity = 1 );
	~CSimuEventCP();

	DWORD advise( ISimuEvent *pListener );

protected:
	void Fire_OnComplete( void );
	void Fire_OnAlarm( void );
	void Fire_OnDrawBegin( void );
	void Fire_OnDrawEnd( void );
	void Fire_OnSelectAutoMargin( void );
	void Fire_OnZoomAccept( void );

private:
	void processEvent( int EventID, void *pListener, void *pParam );
	// process event
};

#endif // !defined(AFX_ISIMUEVENT_H__FE5DE85B_F281_4FF5_B038_530BADCED40F__INCLUDED_)
