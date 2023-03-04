#pragma once

#ifdef TP_PLATFORM_WINDOWS
  #ifdef TP_BUILD_DLL
    #define THEPROJECT_API __declspec(dllexport)
  #else
    #define THEPROJECT_API __declspec(dllimport)
  #endif
#else
  #error The application only supports Windows platform.
#endif