#pragma once
#include <SmallParts/Logging.h>
#include <string>

//Define the call to the debugger
#ifndef BREAK_DEBUGGER
#ifdef _MSC_VER
#include <Windows.h>
#define BREAK_DEBUGGER() __debugbreak()
#else
#prgma warn "Break debugger is currently only defined for MSVC on windows"
#endif
#endif

inline void SmallPart_PrintErrorOnLine(const char* message = nullptr, const char* file = nullptr, int line = -1, const char* expressionName = nullptr)
{
	using namespace std::string_literals;
	std::string s = "Assertion failed!\nAt: "s+ file +" : "+std::to_string(line)+" with the expression: \n'"+expressionName;
	if(message)
		s += "'\n message: '"s + message + "'";

	LOGLN(s);
}

#define ASSERT(expression) if(!(expression)) { SmallPart_PrintErrorOnLine(nullptr, __FILE__, __LINE__, #expression); BREAK_DEBUGGER(); }
#define ASSERT_M(expression, message) if(!(expression)) { SmallPart_PrintErrorOnLine(message, __FILE__, __LINE__, #expression); BREAK_DEBUGGER(); }
