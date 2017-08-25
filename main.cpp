//
#include <iostream>
#include <SDL.h>

#include "src\graphics\Window.h"

/*
    This type of main:

    int main(int, char*) {}

    should be used so that the application is compatible on many platform.
*/
int main(int argc, char* args[])
{

    using namespace std;
    using namespace exw;
    using namespace graphics;

    Window wnd;





    // first create window;
    SDL_Window* window = NULL;

    // then create surface;
    SDL_Surface* surface = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "main(int, char*) -> SDL_Init() failed: " << SDL_GetError() << endl;
        return 0;
    }
    //cout << "main(int, char*) -> SDL Initialize done." << endl;

    const char* title = "Chessu";
    int x = 100;
    int y = 100;
    int width = 800;
    int height = 450;


    window = SDL_CreateWindow(title, x, y, width, height, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        cout << "main(int, char*) -> SDL_CreateWindow() failed: " << SDL_GetError() << endl;
        return 0;
    }

    surface = SDL_GetWindowSurface(window);

    SDL_FillRect(surface, NULL, SDL_MapRGBA(surface->format, 120, 200, 100, 255));
    


    SDL_UpdateWindowSurface(window);
    SDL_Delay(2000);

    bool quit = true;
    while (!quit)
    {
        //SDL_UpdateWindowSurface(window);
    }


    SDL_DestroyWindow(window);
    SDL_Quit();

    //system("PAUSE");
    return 0;
}
