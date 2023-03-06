#include "../tppch.h"
#include "application.h"

#include <GLFW/glfw3.h>

#include "Events/application_event.h"
#include "log.h"

namespace TheProject {
Application::Application() {
    m_Window = std::unique_ptr<Window>( Window::Create() );
}
Application::~Application() {}

void Application::Run() {
    while ( m_IsRunning ) {
        glClearColor(.5, .9, .7, 1.);
        glClear( GL_COLOR_BUFFER_BIT );
        m_Window->OnUpdate();
    }
}
}  // namespace TheProject