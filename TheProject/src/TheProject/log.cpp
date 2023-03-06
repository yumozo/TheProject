#include "../tppch.h"
#include "log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace TheProject {

std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

void Log::Init() {
    spdlog::set_pattern( "%^[%T] %n: %v%$" );
    s_CoreLogger = spdlog::stdout_color_mt("TheProject");
    s_CoreLogger->set_level(spdlog::level::trace);

    s_ClientLogger = spdlog::stdout_color_mt("Client App");
    s_ClientLogger->set_level(spdlog::level::trace);
}

}  // namespace TheProject