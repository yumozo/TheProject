#pragma once

#ifdef TP_PLATFORM_WINDOWS

extern TheProject::Application *TheProject::CreateApplication();

int main( int argc, char **argv ) {
    auto app = TheProject::CreateApplication();
    app->Run();
    delete app;
}

#endif