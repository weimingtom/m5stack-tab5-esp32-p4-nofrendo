//FIXME:
//search if (tick % (3 * 1000 * 1000) == 0)

//#include <SDL.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <noftypes.h>
#include <bitmap.h>
#include <nofconfig.h>
#include <event.h>
#include <gui.h>
#include <log.h>
#include <nes.h>
#include <nes_pal.h>
#include <nesinput.h>
#include <osd.h>
#include "sdl_api.h"

#define  DEFAULT_SAMPLERATE   22050
#define  DEFAULT_BPS          8
#define  DEFAULT_FRAGSIZE     1024

#define  DEFAULT_WIDTH        256
#define  DEFAULT_HEIGHT       NES_VISIBLE_HEIGHT

/*
** Timer
*/

/*
** Audio
*/
static int sound_bps = DEFAULT_BPS;
static int sound_samplerate = DEFAULT_SAMPLERATE;

void osd_setsound(void (*playfunc)(void *buffer, int length))
{
}

static void osd_stopsound(void)
{

}

static int osd_init_sound(void)
{
   return 0;
}

void osd_getsoundinfo(sndinfo_t *info)
{
   info->sample_rate = sound_samplerate;
   info->bps = sound_bps;
}

/*
** Video
*/

static int init(int width, int height);
static void shutdown(void);
static int set_mode(int width, int height);
static void set_palette(rgb_t *pal);
static void clear(uint8 color);
static bitmap_t *lock_write(void);
static void free_write(int num_dirties, rect_t *dirty_rects);

viddriver_t sdlDriver =
{
   "Simple DirectMedia Layer",         /* name */
   init,          /* init */
   shutdown,      /* shutdown */
   set_mode,      /* set_mode */
   set_palette,   /* set_palette */
   clear,         /* clear */
   lock_write,    /* lock_write */
   free_write,    /* free_write */
   NULL,          /* custom_blit */
   false          /* invalidate flag */
};

void osd_getvideoinfo(vidinfo_t *info)
{
   info->default_width = DEFAULT_WIDTH;
   info->default_height = DEFAULT_HEIGHT;
   info->driver = &sdlDriver;
}

/* Now that the driver declaration is out of the way, on to the SDL stuff */
//static SDL_Surface *mySurface = NULL;
//static SDL_Color myPalette[256];
static unsigned char mySurface_pixels_array[256*224*1] = {0};
static unsigned char *mySurface_pixels;
static int mySurface_w = 256;
static int mySurface_h = 224;
static int mySurface_pitch = 256;
static bitmap_t *myBitmap = NULL;
static unsigned int myPalette[256];

/* flip between full screen and windowed */
void osd_togglefullscreen(int code)
{

}

/* initialise SDL video */
static int init(int width, int height)
{
   return set_mode(width, height);
}

/* squash memory leaks */
static void shutdown(void)
{
//   if (NULL != mySurface)
//   {
//      SDL_FreeSurface(mySurface);
//      mySurface = NULL;
//   }

   if (NULL != myBitmap)
      bmp_destroy(&myBitmap);
}

/* set a video mode */
static int set_mode(int width, int height)
{
//   int flags;

//   if (NULL != mySurface)
//   {
//      SDL_FreeSurface(mySurface);
//      mySurface = NULL;
//   }

//   if (NULL == mySurface)
//   {
//      flags = SDL_HWSURFACE | SDL_HWPALETTE;
//      mySurface = SDL_SetVideoMode(width, height, 8, flags);
//   }

//   if (NULL == mySurface)
//   {
//      log_printf("SDL Video failed: %s\n", SDL_GetError());
//      return -1;
//   }
	mySurface_pixels = mySurface_pixels_array;
	mySurface_w = 256;
	mySurface_h = 224;
	mySurface_pitch = 256;

   return 0;
}

/* copy nes palette over to hardware */
static void set_palette(rgb_t *pal)
{
//	int i;

//   for (i = 0; i < 256; i++)
//   {
//      myPalette[i].r = pal[i].r;
//      myPalette[i].g = pal[i].g;
//      myPalette[i].b = pal[i].b;
//   }

//   SDL_SetColors(mySurface, myPalette, 0, 256);

	int i;

   for (i = 0; i < 256; i++)
   {
      myPalette[i] = (pal[i].r) | (pal[i].g << 8) | (pal[i].b << 16);
   }
}

/* clear all frames to a particular color */
static void clear(uint8 color)
{
//   SDL_FillRect(mySurface, 0, color);
  int x, y;
  for(y=0; y<mySurface_h; y++){
	for(x=0; x<mySurface_w; x++){  
	  unsigned char byte = mySurface_pixels[y * mySurface_w + x];
	  CanvasDrawPixel(x, y, myPalette[color], 0xff);
	}
  }
}

/* acquire the directbuffer for writing */
static bitmap_t *lock_write(void)
{
//   SDL_LockSurface(mySurface);
//   myBitmap = bmp_createhw(mySurface->pixels, mySurface->w, 
//                           mySurface->h, mySurface->pitch);
	myBitmap = bmp_createhw(mySurface_pixels, mySurface_w, 
                           mySurface_h, mySurface_pitch);
   return myBitmap;
}

/* release the resource */
static void free_write(int num_dirties, rect_t *dirty_rects)
{
#if 0
   bmp_destroy(&myBitmap);
//   SDL_UnlockSurface(mySurface);

   if (-1 == num_dirties)
   {
//      SDL_UpdateRect(mySurface, 0, 0, 0, 0);
   }
   else if (num_dirties > 0)
   {
      /* loop through and modify the rects to be in terms of the screen */
      if (NES_SCREEN_WIDTH < mySurface_w || NES_VISIBLE_HEIGHT < mySurface_h)
      {
         int i, x_offset, y_offset;

         x_offset = (mySurface_w - NES_SCREEN_WIDTH) >> 1;
         y_offset = (mySurface_h - NES_VISIBLE_HEIGHT) >> 1;

         for (i = 0; i < num_dirties; i++)
         {
            dirty_rects[i].x += x_offset;
            dirty_rects[i].y += y_offset;
         }
      }
         
//      SDL_UpdateRects(mySurface, num_dirties, (SDL_Rect *) dirty_rects);
   }
#else


/*
  int x, y;
  for(y=0; y<mySurface_h; y++){
    for(x=0; x<mySurface_w; x++){  
      unsigned char byte = mySurface_pixels[y * mySurface_w + x];
	  CanvasDrawPixel(x, y, byte, 0xff);
    }
  }
  MainFrameRefresh();
*/


   if (-1 == num_dirties)
   {
//      SDL_UpdateRect(mySurface, 0, 0, 0, 0);
	  int x, y;
	  for(y=0; y<mySurface_h; y++){
		for(x=0; x<mySurface_w; x++){  
		  unsigned char byte = mySurface_pixels[y * mySurface_w + x];
		  CanvasDrawPixel(x, y, myPalette[byte], 0xff);
		}
	  }
   }
   else if (num_dirties > 0)
   {
	   int i, x, y;
      /* loop through and modify the rects to be in terms of the screen */
      if (NES_SCREEN_WIDTH < mySurface_w || NES_VISIBLE_HEIGHT < mySurface_h)
      {
         int x_offset, y_offset;

         x_offset = (mySurface_w - NES_SCREEN_WIDTH) >> 1;
         y_offset = (mySurface_h - NES_VISIBLE_HEIGHT) >> 1;

         for (i = 0; i < num_dirties; i++)
         {
            dirty_rects[i].x += x_offset;
            dirty_rects[i].y += y_offset;
         }
      }

	  for (i = 0; i < num_dirties; i++)
      {
          for(y=dirty_rects[i].y; y<mySurface_h && y < dirty_rects[i].y + dirty_rects[i].h; y++){
			for(x=dirty_rects[i].x; x<mySurface_w && x < dirty_rects[i].x + dirty_rects[i].w; x++){  
			  unsigned char byte = mySurface_pixels[y * mySurface_w + x];
			  CanvasDrawPixel(x, y, myPalette[byte], 0xff);
			}
		  }
      }
         
//      SDL_UpdateRects(mySurface, num_dirties, (SDL_Rect *) dirty_rects);
   }
   MainFrameRefresh();

#endif
}

/*
** Input
*/

static void osd_initinput()
{

}

void osd_getinput(void)
{
//   SDL_Event myEvent;
//
//   while (SDL_PollEvent(&myEvent))
//   {
//      switch(myEvent.type)
//      {
//      case SDL_QUIT:
//         event_get(event_quit)(INP_STATE_MAKE);
//         break;
//
//      default:
//         break;
//      }
//   }
	CanvasSetColor(0x000000);
	if (MainFrameGetMsg() != 0) 
	{
#ifndef _MSC_VER
		while(1);
#else
		exit(0);
#endif
	}
}

static void osd_freeinput(void)
{
}

void osd_getmouse(int *x, int *y, int *button)
{

}

/*
** Shutdown
*/

/* this is at the bottom, to eliminate warnings */
void osd_shutdown()
{
   osd_stopsound();
   osd_freeinput();
//   SDL_Quit();
}

static int logprint(const char *string)
{
   return fprintf(stderr, "%s", string);
}

/*
** Startup
*/

int osd_init()
{
   log_chain_logfunc(logprint);

   /* Initialize the SDL library */
//   if (SDL_Init (SDL_INIT_TIMER | SDL_INIT_VIDEO) < 0)
//   {
//      printf("Couldn't initialize SDL: %s\n", SDL_GetError());
//      return -1;
//   }

   if (osd_init_sound())
      return -1;

   osd_initinput();

   return 0;
}

