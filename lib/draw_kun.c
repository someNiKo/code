#include "draw_kun.h"
#include <math.h>

#define PI acos(-1)
#define kun_beidai_y 5*tan(PI/3)

//坤动画的10帧
void fps0(double x, double y);
void fps1(double x, double y);
void fps2(double x, double y);
void fps3(double x, double y);
void fps4(double x, double y);
void fps5(double x, double y);
void fps6(double x, double y);
void fps7(double x, double y);
void fps8(double x, double y);
void fps9(double x, double y);


/**************
传入坤的坐标和方向
***************/
void DrawKUN(double x, double y, int fps)
{
	switch (fps)
	{
	case 0:
		fps0(x, y);
		break;
	case 1:
		fps1(x, y);
		break;
	case 2:
		fps2(x, y);
		break;		
	case 3:
		fps3(x, y);
		break;
	case 4:
		fps4(x, y);
		break;
	case 5:
		fps5(x, y);
		break;
	case 6:
		fps6(x, y);
		break;
	case 7:
		fps7(x, y);
		break;
	case 8:
		fps8(x, y);
		break;
	case 9:
		fps9(x, y);
		break;
	default:
		break;
	}	
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


void fps0(double x, double y)
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

void fps1(double x, double y)
{
	SetPenColor("Red");
	SetPenSize(2);
	MovePen(x, y);
	DrawLine(10,10);
}

void fps2(double x, double y)
{
	SetPenColor("Red");
	SetPenSize(2);
	MovePen(x, y);
	DrawLine(-10,10);
}

void fps3(double x, double y)
{
	SetPenColor("Red");
	SetPenSize(2);
	MovePen(x, y);
	DrawLine(-10,-10);
}

void fps4(double x, double y)
{
	SetPenColor("Red");
	SetPenSize(2);
	MovePen(x, y);
	DrawLine(10,-10);
}

void fps5(double x, double y)
{
	SetPenColor("Red");
	SetPenSize(2);
	MovePen(x, y);
	DrawLine(10,10);
}

void fps6(double x, double y)
{
	SetPenColor("Red");
	SetPenSize(2);
	MovePen(x, y);
	DrawLine(10,10);
}

void fps7(double x, double y)
{
	SetPenColor("Red");
	SetPenSize(2);
	MovePen(x, y);
	DrawLine(10,10);
}

void fps8(double x, double y)
{
	SetPenColor("Red");
	SetPenSize(2);
	MovePen(x, y);
	DrawLine(10,10);
}

void fps9(double x, double y)
{
	SetPenColor("Red");
	SetPenSize(2);
	MovePen(x, y);
	DrawLine(10,10);
}