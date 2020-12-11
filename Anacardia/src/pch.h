#pragma once

#include "Core.h"
#include "Anacardia/Log.h"

#ifdef ANACARDIA_PLATFORM_WINDOWS
	#include <Windows.h>
#endif

#ifdef ACAR_DEBUG
#define ANACARDIA_ENABLE_ASSERTS
#endif

// C++ STL
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <exception>

