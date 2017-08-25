#pragma once

#include <iostream>
#include <SDL.h>

namespace exw
{
    namespace graphics
    {

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

        class Window
        {
        private:
            int m_X, m_Y;
            int m_Width, m_Height;
            const char* m_Title;
            SDL_Window* m_Window;
            SDL_Surface* m_Surface;
            bool m_Keys[MAX_KEYS];
            bool m_Buttons[MAX_BUTTONS];
            double m_MouseX, m_MouseY;
        public:
            static Window* INSTANCE;

        private:
            bool init();
        public:
            /* Create a default 800x450 no titled window at default location. */
            Window();
            /* Create a titled window at default location with customized size. */
            Window(const char* title, int width, int height);
            /* Create a titled window at a specific location with customized size. */
            Window(const char* title, int x, int y, int width, int height);
            ~Window();
        };

    }
}