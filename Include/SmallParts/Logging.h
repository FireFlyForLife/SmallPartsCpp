#pragma once

#ifndef LOG

#ifdef LOGGER_USE_WINDOWS_OUTPUTSDEBUGSTRING
#include <Windows.h>
#define LOG(message) OutputDebugStringA(message)
#else
#include <iostream>
#define LOG(message) std::cout << message
#define LOGLN(message) std::cout << message << '\n'
#endif

#endif
