#pragma once

#if !defined(__COMMON_H__)
#define __COMMON_H__

#ifndef _IOSTREAM_
#include <iostream>
#include <stdint.h>
#endif

#ifndef _THREAD_
#include <thread>
#endif

#ifndef _CHRONO_
#include <chrono>
#endif

#include "CRC16_MODBUS.h"

#define length(array) ((sizeof(array)) / (sizeof(array[0])))
using namespace std::literals::chrono_literals;

struct Timer
{
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;

	Timer()
	{
		start = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;

		float ms = duration.count() * 1000.0f;
		std::cout << "Time taken to execute: " << ms << " ms" << std::endl;
	}
};

#endif