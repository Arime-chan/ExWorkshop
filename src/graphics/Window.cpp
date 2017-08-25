//
#include "Window.h"

namespace exw
{
    namespace graphics
    {

        /*  */
        bool Window::init()
        {
            if (SDL_Init(SDL_INIT_VIDEO) < 0)
            {
                std::cout << "Window->init() -> SDL_Init() failed: " << SDL_GetError() << std::endl;
                return false;
            }
            m_Window = SDL_CreateWindow(m_Title, m_X, m_Y, m_Width, m_Height, SDL_WINDOW_SHOWN);
            if (m_Window == NULL)
            {
                std::cout << "Window->init() -> SDL_CreateWindow(const char* int, int, int, int, Uint32) failed: " << SDL_GetError() << std::endl;
                return false;
            }
            m_Surface = SDL_GetWindowSurface(m_Window);

            // continue init;




            return false;
        }

        Window::Window()
            : Window("", 800, 450)
        {
        }

        Window::Window(const char* title, int width, int height)
            : Window(title, 50, 50, width, height)
        {
        }

        Window::Window(const char * title, int x, int y, int width, int height)
            : m_Title(title), m_X(x), m_Y(y), m_Width(width), m_Height(height)
        {
            if (!init())
            {
                //SDL_Quit();
            }
            // INSTANCE = this;
            for (int i = 0; i < MAX_KEYS; m_Keys[i++] = false);
            for (int i = 0; i < MAX_BUTTONS; m_Buttons[i++] = false);
        }

        Window::~Window()
        {
            delete m_Title;
            SDL_DestroyWindow(m_Window);
        }

    }
}