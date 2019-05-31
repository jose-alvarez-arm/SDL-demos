#include <SDL.h>

void PrintEvent(const SDL_Event * event)
{
    if (event->type == SDL_WINDOWEVENT) {
        switch (event->window.event) {
        case SDL_WINDOWEVENT_SHOWN:
            dbgprintf("[sdlapp] Window %d shown\n", event->window.windowID);
            break;
        case SDL_WINDOWEVENT_HIDDEN:
            dbgprintf("[sdlapp] Window %d hidden\n", event->window.windowID);
            break;
        case SDL_WINDOWEVENT_EXPOSED:
            dbgprintf("[sdlapp] Window %d exposed\n", event->window.windowID);
            break;
        case SDL_WINDOWEVENT_MOVED:
            dbgprintf("[sdlapp] Window %d moved to %d,%d\n",
                    event->window.windowID, event->window.data1,
                    event->window.data2);
            break;
        case SDL_WINDOWEVENT_RESIZED:
            dbgprintf("[sdlapp] Window %d resized to %dx%d\n",
                    event->window.windowID, event->window.data1,
                    event->window.data2);
            break;
        case SDL_WINDOWEVENT_SIZE_CHANGED:
            dbgprintf("[sdlapp] Window %d size changed to %dx%d\n",
                    event->window.windowID, event->window.data1,
                    event->window.data2);
            break;
        case SDL_WINDOWEVENT_MINIMIZED:
            dbgprintf("[sdlapp] Window %d minimized\n", event->window.windowID);
            break;
        case SDL_WINDOWEVENT_MAXIMIZED:
            dbgprintf("[sdlapp] Window %d maximized\n", event->window.windowID);
            break;
        case SDL_WINDOWEVENT_RESTORED:
            dbgprintf("[sdlapp] Window %d restored\n", event->window.windowID);
            break;
        case SDL_WINDOWEVENT_ENTER:
            dbgprintf("[sdlapp] Mouse entered window %d\n", event->window.windowID);
            break;
        case SDL_WINDOWEVENT_LEAVE:
            dbgprintf("[sdlapp] Mouse left window %d\n", event->window.windowID);
            break;
        case SDL_WINDOWEVENT_FOCUS_GAINED:
            dbgprintf("[sdlapp] Window %d gained keyboard focus\n",
                    event->window.windowID);
            break;
        case SDL_WINDOWEVENT_FOCUS_LOST:
            dbgprintf("[sdlapp] Window %d lost keyboard focus\n",
                    event->window.windowID);
            break;
        case SDL_WINDOWEVENT_CLOSE:
            dbgprintf("[sdlapp] Window %d closed\n", event->window.windowID);
            break;
#if SDL_VERSION_ATLEAST(2, 0, 5)
        case SDL_WINDOWEVENT_TAKE_FOCUS:
            dbgprintf("[sdlapp] Window %d is offered a focus\n", event->window.windowID);
            break;
        case SDL_WINDOWEVENT_HIT_TEST:
            dbgprintf("[sdlapp] Window %d has a special hit test\n", event->window.windowID);
            break;
#endif
        default:
            dbgprintf("[sdlapp] Window %d got unknown event %d\n",
                    event->window.windowID, event->window.event);
            break;
        }
    } else if (event->type == SDL_MOUSEBUTTONDOWN) {
        dbgprintf("[sdlapp] Window %d button down %dx%d\n", event->button.windowID, event->button.x, event->button.y);
    } else if (event->type == SDL_MOUSEBUTTONUP) {
        dbgprintf("[sdlapp] Window %d button up %dx%d\n", event->button.windowID, event->button.x, event->button.y);
    }
}

void render(SDL_Renderer *renderer)
{
    static bool goingRight = true;
    static int x = 0;

    // Set render color to red ( background will be rendered in this color )
    SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );

    // Clear winow
    SDL_RenderClear( renderer );

    // Creat a rect at pos ( 50, 50 ) that's 50 pixels wide and 50 pixels high.
    SDL_Rect r;
    r.x = x;
    r.y = 50;
    r.w = 50;
    r.h = 50;

    if (goingRight) {
        x = x + 1;
        if (x >= 400) {
            goingRight = false;
        }
    } else {
        x = x - 1;
        if (x == 0) {
            goingRight = true;
        }
    }

    // Set render color to blue ( rect will be rendered in this color )
    SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );

    // Render rect
    SDL_RenderFillRect( renderer, &r );

    // Render the rect to the screen
    SDL_RenderPresent(renderer);
}

int main (int argc, char** argv)
{
    SDL_Window* window = NULL;
    dbgprintf("[sdlapp] CREATING window\n");
    window = SDL_CreateWindow
    (
        "A sdl window", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        800,
        600,
        SDL_WINDOW_SHOWN
    );

    dbgprintf("[sdlapp] Created window\n");

    // Setup renderer
    SDL_Renderer* renderer = NULL;
    renderer =  SDL_CreateRenderer( window, -1, SDL_RENDERER_SOFTWARE);
    dbgprintf("[sdlapp] Created renderer\n");

    SDL_Event event;
    for (;;) {
        while (SDL_WaitEventTimeout(&event, 0)) {
            PrintEvent(&event);
        }
        render(renderer);
        SDL_Delay(10);
    }

    SDL_DestroyWindow(window);
    dbgprintf("[sdlapp] SDL_DestroyWindow\n");
    SDL_Quit();
    dbgprintf("[sdlapp] SDL_Quit\n");
    return EXIT_SUCCESS;
}

