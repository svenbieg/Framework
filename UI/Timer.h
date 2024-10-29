//=========
// Timer.h
//=========

#pragma once


//===========
// Namespace
//===========

namespace UI {


//=======
// Timer
//=======

class Timer: public Object
{
public:
	// Con-/Destructors
	Timer();
	~Timer();

	// Common
	BOOL IsStarted()const { return m_Interval!=0; }
	VOID Reset();
	VOID StartOnce(UINT MilliSeconds);
	VOID StartPeriodic(UINT MilliSeconds);
	VOID Stop();
	Event<Timer> Triggered;

private:
	// Common
	VOID DoTrigger();
	VOID OnClockTick();
	INT m_Interval;
	UINT64 m_LastTime;
};

}
