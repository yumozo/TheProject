#pragma once

#include "core.h"

namespace TheProject {
// class __declspec(dllexport) Application {
class THEPROJECT_API Application {
   public:
    Application();
    virtual ~Application();

    void Run();
};
// To be defined in ClIENT
Application *CreateApplication();
}  // namespace TheProject