#ifndef PICTURE_H
#define PICTURE_H
#define p 6
#define q 15
#define qq 2
#include<iostream>
#include<curses.h>
void gameover()
{
	mvaddstr(p,qq, " ￭￭￭    ￭   ￭    ￭ ￭￭￭￭  ￭￭￭ ￭       ￭ ￭￭￭￭ ￭￭￭ ");
	mvaddstr(p+1,qq,"￭      ￭ ￭  ￭￭  ￭￭ ￭    ￭   ￭ ￭     ￭  ￭    ￭  ￭");
	mvaddstr(p+2,qq,"￭ ￭￭￭ ￭￭￭￭￭ ￭  ￭ ￭ ￭￭￭￭ ￭   ￭  ￭   ￭   ￭￭￭￭ ￭ ￭ ");
	mvaddstr(p+3,qq, "￭  ￭  ￭   ￭ ￭    ￭ ￭    ￭   ￭   ￭ ￭    ￭    ￭ ￭ ");
	mvaddstr(p+4,qq," ￭￭￭  ￭   ￭ ￭    ￭ ￭￭￭￭  ￭￭￭     ￭     ￭￭￭￭ ￭  ￭");
	scanw("\r");
}
void win()
{
	mvprintw(p ,q,"￭   ￭  ￭￭￭  ￭   ￭   ￭   ￭   ￭ ￭￭￭￭￭ ￭   ￭   ￭￭");
	mvprintw(p+1 ,q," ￭ ￭  ￭   ￭ ￭   ￭    ￭ ￭ ￭ ￭    ￭   ￭￭  ￭   ￭￭");
	mvprintw(p+2 ,q,"  ￭   ￭   ￭ ￭   ￭     ￭   ￭     ￭   ￭ ￭ ￭   ￭￭");
	mvprintw(p+3 ,q,"  ￭   ￭   ￭ ￭   ￭     ￭   ￭     ￭   ￭  ￭￭      ");
	mvprintw(p+4,q,"  ￭    ￭￭￭   ￭￭￭      ￭   ￭   ￭￭￭￭￭ ￭   ￭   ￭");
	scanw("\r");
}
void screen()
{
	clear();
	mvprintw(p,q,  "￭   ￭   ￭￭￭  ￭￭￭￭￭  ￭   ￭  ￭￭￭￭  ￭￭￭  ￭￭￭￭ ");
	mvprintw(p+1,q,"￭￭  ￭  ￭     ￭    ￭   ￭  ￭    ￭     ￭    ");
	mvprintw(p+2,q,"￭ ￭ ￭  ￭       ￭    ￭   ￭  ￭￭￭￭ ￭     ￭￭￭￭ ");
	mvprintw(p+3,q,"￭  ￭￭  ￭       ￭    ￭   ￭  ￭    ￭     ￭    ");
	mvprintw(p+4,q,"￭   ￭   ￭￭￭    ￭     ￭ ￭   ￭￭￭￭  ￭￭￭  ￭￭￭￭ ");
	mvprintw(x2+6,q,"Press Enter to start the game...\n");
	scanw("\r");
}
#endif
