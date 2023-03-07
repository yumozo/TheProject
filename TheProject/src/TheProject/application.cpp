#include "../tppch.h"
#include "application.h"

#include <GLFW/glfw3.h>

#include "Events/application_event.h"
#include "log.h"

namespace TheProject {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

Application::Application() {
    m_Window = std::unique_ptr<Window>( Window::Create() );
    m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
}
Application::~Application() {}

void Application::OnEvent( Event& e ) {
    EventDispatcher dispatcher( e );
    dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

    TP_CORE_TRACE("{0}", e);
}

void Application::Run() {
    while ( m_IsRunning ) {
        glClearColor(.5, .9, .7, 1.);
        glClear( GL_COLOR_BUFFER_BIT );
        m_Window->OnUpdate();
    }
}

bool Application::OnWindowClose( WindowCloseEvent& e ) {
    m_IsRunning = false;
    return true;
}
}  // namespace TheProject