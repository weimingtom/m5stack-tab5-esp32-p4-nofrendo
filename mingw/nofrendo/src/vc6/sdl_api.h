#ifndef SDL_API_H
#define SDL_API_H

extern int MainFrameGetMsg(void);
extern void MainFrameRefresh(void);
extern void CanvasSetColor(int color);
extern void CanvasDrawPixel(int x1, int y1, int color, int alpha);

#endif