#pragma once
#include <windows.h>
#include <stdexcept>

class Timer
{
public:
	enum TimeFrequency
	{
		Seconds = 1,
		Milliseconds = 1000,
		Microseconds = 1000000
	};

private:
	TimeFrequency m_timeFrequency;

	INT64 m_frequency;
	double m_ticksPerMs;
	INT64 m_startTime;

	double m_updateTime;
	double m_deltaTime;
	double m_gameTime;
	double m_fps;

	//
	__int64 m_startClock;
	__int64 m_stopClock;
	__int64 m_timeDifference;

public:
	//Initialize with a time using: TimeFrequency::Seconds (for example), or have it to the default value of milliseconds.
	Timer(TimeFrequency time = TimeFrequency::Milliseconds)
	{
		QueryPerformanceFrequency((LARGE_INTEGER*)&m_frequency);

		if (m_frequency == 0)
			throw std::runtime_error("Timer");

		m_timeFrequency = time;
		switch (time)
		{
		case Timer::Seconds:
			m_ticksPerMs = (float)(m_frequency);
			break;
		case Timer::Milliseconds:
			m_ticksPerMs = (float)(m_frequency / 1000);
			break;
		case Timer::Microseconds:
			m_ticksPerMs = (float)(m_frequency / 1000000);
			break;
		default:
			m_ticksPerMs = (float)(m_frequency / 1000);
			break;	
		}
			
		QueryPerformanceCounter((LARGE_INTEGER*)&m_startTime);
	};
	~Timer(){};
	void Update()
	{
		INT64 currentTime;
		QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);
		double timeDifference = (double)(currentTime - m_startTime);
		m_updateTime = timeDifference / m_ticksPerMs;
		m_startTime = currentTime;

		m_deltaTime += m_updateTime;
		m_gameTime += m_updateTime;
		m_fps = (1 / (m_deltaTime / 1000));
	};

	void StartClock()
	{
		m_startClock = 0;
		QueryPerformanceCounter((LARGE_INTEGER*)&m_startClock);
	};
	double StopClock()
	{
		m_stopClock = 0;
		QueryPerformanceCounter((LARGE_INTEGER*)&m_stopClock);
		m_timeDifference = (m_stopClock - m_startClock);
		return (double)m_timeDifference;
	};
	double GetStopClock() { return ((double)m_timeDifference * ( 1.0/ m_frequency * m_timeFrequency)); };
	double GetDeltaTime()const { return m_deltaTime; };
	double GetFPS()const { return m_fps; };
	void Reset(){ m_deltaTime = 0;};
};