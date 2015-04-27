#ifndef _FONT_H
#define _FONT_H

#include "zt.h"

extern unsigned char font[256*8];

#define row(x) ((int)((int)x)<<3)
#define col(x) ((int)((int)x)<<3)

int font_load(char *filename);
int font_load(std::istream *is);

int textcenter(char *str, int local=-1);

void print(int x, int y, char *str, TColor col, ZTDrawable *S);
void printBG(int x, int y, char *str, TColor col, TColor bg, ZTDrawable *S);
void printBGu(int x, int y, unsigned char *str, TColor col, TColor bg, ZTDrawable *S);
void printshadow(int x, int y, char *str, TColor col, ZTDrawable *S);
void printline(int xi, int y, unsigned char ch, int len, TColor col, ZTDrawable *S);
void printchar(int x, int y, unsigned char ch, TColor col, ZTDrawable *S);
void printcharBG(int x, int y, unsigned char ch, TColor col, TColor bg, ZTDrawable *S);

int printtitle(int y, char *str, TColor col,TColor bg,ZTDrawable *S);
void fillline(int y, char c, TColor col, TColor bg, ZTDrawable *S);
void printlineBG(int xi, int y, unsigned char ch, int len, TColor col, TColor bg, ZTDrawable *S);

void printLCD(int x,int y,char *str, ZTDrawable *S);

int hex2dec(char c);
void printBGCC(int x, int y, char *str, TColor col, TColor bg, ZTDrawable *S);

#endif