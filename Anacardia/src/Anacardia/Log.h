#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include <memory>

namespace Anacardia
{
	class ANACARDIA_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger(){ return s_ClientLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;  }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core Log Macros
#define ANACARDIA_CORE_TRACE(...)    ::Anacardia::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ANACARDIA_CORE_INFO(...)     ::Anacardia::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ANACARDIA_CORE_WARN(...)     ::Anacardia::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ANACARDIA_CORE_ERROR(...)    ::Anacardia::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ANACARDIA_CORE_FATAL(...)    ::Anacardia::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log Macros
#define ANACARDIA_TRACE(...)    ::Anacardia::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ANACARDIA_INFO(...)     ::Anacardia::Log::GetClientLogger()->info(__VA_ARGS__)
#define ANACARDIA_WARN(...)     ::Anacardia::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ANACARDIA_ERROR(...)    ::Anacardia::Log::GetClientLogger()->error(__VA_ARGS__)
#define ANACARDIA_FATAL(...)    ::Anacardia::Log::GetClientLogger()->fatal(__VA_ARGS__)