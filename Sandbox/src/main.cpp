#include <TheProject.h>

class Sandbox : public TheProject::Application {
   public:
    Sandbox() {}
    ~Sandbox() {}
};

TheProject::Application *TheProject::CreateApplication() { return new Sandbox(); }