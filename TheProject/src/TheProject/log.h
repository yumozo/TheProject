#pragma once

#include "core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace TheProject {
class THEPROJECT_API Log {
   public:
    static void Init();

    inline static std::shared_ptr<spdlog::logger> &GetCoreLogger() {
        return s_CoreLogger;
    }
    inline static std::shared_ptr<spdlog::logger> &GetClientLogger() {
        return s_ClientLogger;
    }

   private:
    static std::shared_ptr<spdlog::logger> s_CoreLogger;
    static std::shared_ptr<spdlog::logger> s_ClientLogger;
};
}  // namespace TheProject

/* LOG MACROS */

#define TP_CORE_TRACE(...)      ::TheProject::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TP_CORE_INFO(...)       ::TheProject::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TP_CORE_WARN(...)       ::TheProject::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TP_CORE_ERROR(...)      ::TheProject::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TP_CORE_CRITICAL(...)   ::TheProject::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define TP_TRACE(...)           ::TheProject::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TP_INFO(...)            ::TheProject::Log::GetClientLogger()->info(__VA_ARGS__)
#define TP_WARN(...)            ::TheProject::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TP_ERROR(...)           ::TheProject::Log::GetClientLogger()->error(__VA_ARGS__)
#define TP_CRITICAL(...)        ::TheProject::Log::GetClientLogger()->critical(__VA_ARGS__)