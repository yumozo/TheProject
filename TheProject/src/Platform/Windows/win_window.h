#pragma once

#include "../../TheProject/window.h"

#include <GLFW/glfw3.h>

namespace TheProject {
class WindowsWindow : public Window {
   public:
    WindowsWindow( const WindowProps &props );
    virtual ~WindowsWindow();

    void OnUpdate() override;

    inline unsigned int GetWidth() const override {
        return m_Data.Width;
    }
    inline unsigned int GetHeight() const override {
        return m_Data.Height;
    }

    /* Attribs */
    inline void SetEventCallback( const EventCallbackFn &callback ) override {
        m_Data.EventCallback = callback;
    }
    void SetVSync( bool is_enabled ) override;
    bool IsVSync() const override;

   private:
    virtual void Init( const WindowProps &props );
    virtual void Shutdown();
    GLFWwindow *m_Window;
    struct WindowData {
        std::string Title;
        unsigned int Width, Height;
        bool VSync_IsOn;

        EventCallbackFn EventCallback;
    } m_Data;
};
}  // namespace TheProject