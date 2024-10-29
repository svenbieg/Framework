//===========
// Timer.cpp
//===========

#include "pch.h"


//=======
// Using
//=======

#include "Core/Application.h"
#include "Devices/Clock.h"
#include "Timer.h"

using namespace Core;
using namespace Devices;


//===========
// Namespace
//===========

namespace UI {


//==================
// Con-/Destructors
//==================

Timer::Timer():
m_Interval(0),
m_LastTime(0)
{}

Timer::~Timer()
{
Stop();
}


//========
// Common
//========

VOID Timer::Reset()
{
m_LastTime=GetTickCount64();
}

VOID Timer::StartOnce(UINT ms)
{
if(m_Interval!=0)
	Stop();
if(ms==0)
	return;
m_Interval=ms;
m_LastTime=GetTickCount64();
auto clock=Clock::Get();
clock->Tick.Add(this, &Timer::OnClockTick);
}

VOID Timer::StartPeriodic(UINT ms)
{
if(m_Interval!=0)
	Stop();
if(ms==0)
	return;
m_Interval=-(INT)ms;
m_LastTime=GetTickCount64();
auto clock=Clock::Get();
clock->Tick.Add(this, &Timer::OnClockTick);
}

VOID Timer::Stop()
{
if(m_Interval==0)
	return;
auto clock=Clock::Get();
clock->Tick.Remove(this);
m_Interval=0;
m_LastTime=0;
}


//================
// Common Private
//=================

VOID Timer::DoTrigger()
{
Triggered(this);
}

VOID Timer::OnClockTick()
{
UINT64 time=GetTickCount64();
UINT dt=m_Interval>0? m_Interval: -m_Interval;
if(time<m_LastTime+dt)
	return;
m_LastTime=time;
auto app=Application::Current;
if(app)
	app->Dispatch(this, &Timer::DoTrigger);
if(m_Interval>0)
	Stop();
}

}
