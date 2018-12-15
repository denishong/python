#include <SDL/SDL.h>
int main(int argc, char** argv)
{

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Surface* screen = SDL_SetVideoMode(480,272,16,SDL_SWSURFACE);
	SDL_Surface* bmp=SDL_LoadBMP("charater.png");

	SDL_Rect dstrect;
	dstrect.x=100;
	dstrect.y=100;
	SDL_BlitSurface(bmp,NULL,screen,&dstrect);

	SDL_Flip(screen);
	SDL_Delay(5000);

	SDL_FreeSurface(bmp);
	SDL_FreeSurface(screen);
	SDL_Quit();

	return 0;
}
