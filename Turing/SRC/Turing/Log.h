#pragma once

#include<memory>

#include"Core.h"
#include"spdlog/spdlog.h"
#include"spdlog/fmt/ostr.h"

namespace Turing {

	class TURING_API Log {
	public:

		/* Initialization function(��ʼ������) */
		static void Init();

		/* ������̬����ָ�� */
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() {
			return s_CoreLogger;
		}
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() {
			return s_ClientLogger;
		}

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

/* Core log macros (������־��) */
#define TR_CORE_TRACE(...)	::Turing::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TR_CORE_INFO(...)	::Turing::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TR_CORE_WARN(...)	::Turing::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TR_CORE_ERROR(...)	::Turing::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TR_CORE_FATAL(...)	::Turing::Log::GetCoreLogger()->fatal(__VA_ARGS__)

/* Client log macros (�ͻ�����־��) */
#define TR_TRACE(...)	::Turing::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TR_INFO(...)	::Turing::Log::GetClientLogger()->info(__VA_ARGS__)
#define TR_WARN(...)	::Turing::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TR_ERROR(...)	::Turing::Log::GetClientLogger()->error(__VA_ARGS__)
#define TR_FATAL(...)	::Turing::Log::GetClientLogger()->fatal(__VA_ARGS__)