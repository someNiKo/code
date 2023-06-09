#include "include/graphics.h"
#include "include/extgraph.h"
#include "include/genlib.h"
#include "include/simpio.h"
#include "include/draw_kun.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include <windows.h>
#include <olectl.h>
#include <mmsystem.h>
#include <wingdi.h>
#include <ole2.h>
#include <ocidl.h>
#include <winuser.h>



#define   VK_A	0x41 
#define   VK_B	0x42 
#define   VK_C	0x43 
#define   VK_D	0x44 
#define   VK_E	0x45 
#define   VK_F	0x46 
#define   VK_G	0x47 
#define   VK_H	0x48 
#define   VK_I	0x49 
#define   VK_J	0x4A 
#define   VK_K	0x4B 
#define   VK_L	0x4C 
#define   VK_M	0x4D 
#define   VK_N	0x4E 
#define   VK_O	0x4F 
#define   VK_P	0x50 
#define   VK_Q	0x51 
#define   VK_R	0x52 
#define   VK_S	0x53 
#define   VK_T	0x54 
#define   VK_U	0x55 
#define   VK_V	0x56 
#define   VK_W	0x57 
#define   VK_X	0x58 
#define   VK_Y	0x59 
#define   VK_Z	0x5A  

#define   VK_a	0x61 
#define   VK_b	0x62 
#define   VK_c	0x63 
#define   VK_d	0x64 
#define   VK_e	0x65 
#define   VK_f	0x66 
#define   VK_g	0x67 
#define   VK_h	0x68 
#define   VK_i	0x69 
#define   VK_j	0x6A 
#define   VK_k	0x6B 
#define   VK_l	0x6C 
#define   VK_m	0x6D 
#define   VK_n	0x6E 
#define   VK_o	0x6F 
#define   VK_p	0x70 
#define   VK_q	0x71 
#define   VK_r	0x72 
#define   VK_s	0x73 
#define   VK_t	0x74 
#define   VK_u	0x75 
#define   VK_v	0x76 
#define   VK_w	0x77 
#define   VK_x	0x78 
#define   VK_y	0x79 
#define   VK_z	0x7A
static HWND graphicsWindow;

//定义坤移动的速度
static double KUN_MOVE = 1;  
static double screen_x,screen_y;
static double KUN_x,KUN_y;
static int fps = 0;  //坤动画全局变量
static bool isDown = 0;


typedef enum{
	FPS,
	KUN_a,
} Mytimer;   

void KeyboardEventProcess(int key,int event);
void CharEventProcess(char c);
void MouseEventProcess(int x, int y, int button, int event);
void TimerEventProcess(int timerID);

void Main()
{
	SetWindowTitle("CXK finding way");
	SetWindowSize(1920,1080);
	InitGraphics();
	InitConsole();
	
	screen_x = GetWindowWidth();
	screen_y = GetWindowHeight();

	registerKeyboardEvent(KeyboardEventProcess);
	registerCharEvent(CharEventProcess);
	registerMouseEvent(MouseEventProcess);
	registerTimerEvent(TimerEventProcess);

	startTimer(FPS,100);  //启动10fps/s计时器

	//初始化坤的坐标
	KUN_x = screen_x/2;
	KUN_y = screen_y/2;
	DrawKUN(KUN_x, KUN_y, fps);

}


/**********
键盘信息回调函数
*************/
void KeyboardEventProcess(int key,int event)
{
	switch(event){
		case KEY_DOWN:
			isDown = 1;
			switch(key){
				case VK_w:
				case VK_W:
				case VK_UP:
					CleanKUN(KUN_x, KUN_y);
					DrawKUN(KUN_x, KUN_y+KUN_MOVE, fps);
					KUN_x = KUN_x;
					KUN_y = KUN_y + KUN_MOVE;
					break;
				case VK_a:
				case VK_A:
				case VK_LEFT:
					CleanKUN(KUN_x, KUN_y);
					DrawKUN(KUN_x-KUN_MOVE, KUN_y, fps);
					KUN_x = KUN_x - KUN_MOVE;
					KUN_y = KUN_y;
					break;
				case VK_s:
				case VK_S:
				case VK_DOWN:
					CleanKUN(KUN_x, KUN_y);
					DrawKUN(KUN_x, KUN_y-KUN_MOVE, fps);
					KUN_x = KUN_x;
					KUN_y = KUN_y - KUN_MOVE;
					break;
				case VK_d:
				case VK_D:
				case VK_RIGHT:
					CleanKUN(KUN_x, KUN_y);
					DrawKUN(KUN_x+KUN_MOVE, KUN_y, fps);
					KUN_x = KUN_x + KUN_MOVE;
					KUN_y = KUN_y;
					break;				
			}
			break;
		case KEY_UP:
			isDown = 0;
			KUN_MOVE = 1;
			cancelTimer(KUN_a);
			break;
	}

	if(isDown){
		switch (event){
			case KEY_DOWN:
				switch (key){
					case VK_f:
					case VK_F:
					startTimer(KUN_a, 300);
					isDown = 0;
					break;
				break;
				}
			break;
			case KEY_UP:
				KUN_MOVE = 1;
				isDown = 0;
				cancelTimer(KUN_a);
				break;		
		break;
		}		
	}
}


/************
字符信息回调函数
************/
void CharEventProcess(char c)
{

}


/*************
鼠标信息回调函数
*************/
void MouseEventProcess(int x, int y, int button, int event)
{

}


/***************
时间回调函数
***************/
void TimerEventProcess(int timerID)
{
	switch(timerID){
		case FPS:
			if(fps < 9){
				fps += 1;
			}else{
				fps = 0;
			}
			CleanKUN(KUN_x, KUN_y);
			DrawKUN(KUN_x, KUN_y, fps);			
			break;
		case KUN_a:
			if(isDown){
				if(KUN_MOVE <= 10){
					KUN_MOVE += 1;
				}else{
					cancelTimer(KUN_a);
				}				
			}
			printf("%lf\n", KUN_MOVE);
			break;
		break;
	}
}
