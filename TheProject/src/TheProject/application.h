#pragma once

#include "core.h"
#include "Events/event.h"
#include "Events/application_event.h"
#include "window.h"

namespace TheProject {
// class __declspec(dllexport) Application {
class THEPROJECT_API Application {
   public:
    Application();
    virtual ~Application();

    void Run();

    void OnEvent(Event &e);

   private:
    std::unique_ptr<Window> m_Window;
    bool m_IsRunning = true;

    bool OnWindowClose( WindowCloseEvent &e);
};
// To be defined in ClIENT
Application *CreateApplication();
}  // namespace TheProject