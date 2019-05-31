#include "SDL.h"

int main(int argc, char* argv[]){

  SDL_Window *window;
  SDL_Event e;

  const char *titles[] = { // just for fun, let's make the title animate like a marquee and annoy users
    "t", "thi", "this w", "this win", "this windo", "this window's", "this window's ti", "this window's title",
    "chis window's title is", "chih window's title is ", "chih wandnw's title is ", "c  h wandnw'g title is ",
    "c  h  a  nw'g titln is ", "c  h  a  n  g  i  n ig ", "c  h  a  n  g  i  n  g!", "",
    "c  h  a  n  g  i  n  g!", "", "c  h  a  n  g  i  n  g!", "c  h  a  n  g  i  n  g!"
  };

  SDL_Init(SDL_INIT_VIDEO); // Init SDL2

  // Create a window.
  window = SDL_CreateWindow(
    "This will surely be overwritten", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 320, 240, SDL_WINDOW_RESIZABLE
  );

  // Enter the main loop. Press any key or hit the x to exit.
  for( ; e.type!=SDL_QUIT&&e.type!=SDL_KEYDOWN; SDL_PollEvent(&e)){
    static int i = 0, t = 0;

    if(!(++t%9)){ // every 9th frame...
      SDL_SetWindowTitle(window, titles[i]);            // loop through the
      if(++i >= sizeof(titles)/sizeof(titles[0])) i = 0; // array of titles
    }

    SDL_Delay(10);

  }

  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;

}

