////
////  main.cpp
////  ZTrackerMacOsX
////
////  Created by Robert on 3/13/15.
////  Copyright (c) 2015 Aardbei. All rights reserved.
////
//
//#include <iostream>
//#include <SDL/SDL.h>
//
//static const uint RENDER_WIDTH = 320;
//static const uint RENDER_HEIGHT = 240;
//
//SDL_Surface *makeWindow(int desiredWidth, int desiredHeight)
//{
//    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
//    {
//        printf("Error initializing video.");
//    }
//    
//    const SDL_VideoInfo *videoInfo = SDL_GetVideoInfo();
//    
//    int screenWidth  = videoInfo->current_w;
//    int screenHeight = videoInfo->current_h;
//    
//    int bitsPerPixel = videoInfo->vfmt->BitsPerPixel;
//    
//    printf("%d x %d, %d bpp\n", screenWidth, screenHeight, bitsPerPixel);
//    
//    SDL_Surface *screen = SDL_SetVideoMode(desiredWidth, desiredHeight, bitsPerPixel, SDL_SWSURFACE);// | SDL_FULLSCREEN);
//    
//    if (screen == NULL)
//    {
//        printf("SDL_SetVideoMode failed.\n");
//    }
//    
//    return screen;
//}
//
//void handleKeyEvents(SDL_Event* event, int* quit)
//{
//    if (event->type == SDL_KEYDOWN)
//    {
//        if (event->key.keysym.sym == SDLK_ESCAPE)
//        {
//            *quit = 1;
//        }
//    }
//}
//
//int main(int argc, char * arg[])
//{
//    SDL_Surface *mainSurface = makeWindow(RENDER_WIDTH, RENDER_HEIGHT);
//    
//    SDL_Surface *backBuffer = SDL_CreateRGBSurface(SDL_HWSURFACE, RENDER_WIDTH, RENDER_HEIGHT, 32,
//                                                   0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
//    
//    SDL_SetAlpha(backBuffer, 0, 0);
//        
//    /* An SDL_Event */
//    SDL_Event event;
//    
//    /* A bool to check if the program has exited */
//    int quit = 0;
//    
//    /* While the program is running */
//    while (!quit)
//    {
//        /* Check for new events */
//        if (SDL_PollEvent(&event))
//        {
//            /* If a quit event has been sent */
//            if (event.type == SDL_QUIT)
//            {
//                /* Quit the application */
//                quit = 1;
//            }
//            
//            handleKeyEvents(&event, &quit);
//        }
//        
//        
//        SDL_BlitSurface(backBuffer, NULL, mainSurface, NULL);
//        
//        SDL_Flip(mainSurface);
//    }
//    
//    SDL_FreeSurface(mainSurface);
//    SDL_Quit();
//    
//    return 0;
//}
