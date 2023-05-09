#include "draw_kun.h"
#include <math.h>

#define PI acos(-1)
#define kun_beidai_y 5*tan(PI/3)

/**************
传入坤的坐标和方向
***************/
void DrawKUN(double x, double y, int fps)
{
	SetPenColor("Black");
	SetPenSize(2);
	
	//画坤脸
	MovePen(x+10,y);    //坤头半径为10像素
	DrawArc(10,0,360);
	
	//画左坤头
	MovePen(x,y+10);
	DrawLine(0,5);
	DrawLine(-15,-15);
	DrawLine(5,-5);
	DrawLine(10,10);
	DrawLine(0,5);
	
	//画右坤头
	MovePen(x,y+10);
	DrawLine(0,5);
	DrawLine(15,-15);
	DrawLine(-5,-5);
	DrawLine(-10,10);
	DrawLine(0,5);

	//填充左坤头
	SetPenColor("Gray");
	double px = x-15, py = y;
	int i = 1;
	while(i < 5){
		MovePen(px + 1, py - 1);
		DrawLine(15 - i, 15 - i);
		px = px + 1;
		py = py - 1;
		i += 1;
	}
	
	//填充右坤头
	px = x+15; py = y;
	i=1;
	while(i < 5){
		MovePen(px - 1, py - 1);
		DrawLine(-(15 - i), 15 - i);
		px = px - 1;
		py = py - 1;
		i += 1;
	}

	//画背带裤
	SetPenColor("Yellow");
	SetPenSize(2);
	MovePen(x - 5, y - kun_beidai_y);
	DrawLine(0,-15);

	MovePen(x + 5, y - kun_beidai_y);
	DrawLine(0,-15);
	
}

/********************
用白色矩形清除坤
*********************/
void CleanKUN(double x, double y)
{
	SetPenSize(1);
	SetPenColor("White");
	MovePen(x-15,y+15);
	int i=0;
	for(i = 0;i < 48;i++){
		DrawLine(32,0);
		MovePen(x - 15, y + 15 - i);
	}
}