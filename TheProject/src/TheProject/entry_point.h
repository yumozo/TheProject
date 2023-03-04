#pragma once

#ifdef TP_PLATFORM_WINDOWS

extern TheProject::Application *TheProject::CreateApplication();

int main( int argc, char **argv ) {
    TheProject::Log::Init();
    TP_CORE_WARN("TheProject has init'ed");
    int ver = 1;
    TP_INFO( "Client using TheProject has init'ed. Version {0}", ver );

    auto app = TheProject::CreateApplication();
    app->Run();
    delete app;
}

#endif