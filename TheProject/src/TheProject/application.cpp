#include "application.h"
#include "Events/application_event.h"
#include "log.h"

namespace TheProject {
Application::Application() {}
Application::~Application() {}

void Application::Run() {
    WindowResizeEvent e( 1280, 720 );
    TP_TRACE( e );

    while ( true ) {
    }
}
}  // namespace TheProject