#include "draw_kun.h"
#include <math.h>

#define PI acos(-1)
#define kun_beidai_y 5*tan(PI/3)

/**************
������������ͷ�����
***************/
void DrawKUN(double x, double y, int direction)
{
	SetPenColor("Blue");
	SetPenSize(2);
	
	//������
	MovePen(x+10,y);    //0.1Ϊ�����뾶
	DrawArc(10,0,360);
	
	//����ͷ
	MovePen(x,y+10);
	DrawLine(0,5);
	DrawLine(-15,-15);
	DrawLine(5,-5);
	DrawLine(10,10);
	DrawLine(0,5);
	
	//����ͷ
	MovePen(x,y+10);
	DrawLine(0,5);
	DrawLine(15,-15);
	DrawLine(-5,-5);
	DrawLine(-10,10);
	DrawLine(0,5);

	//�������ͷ
	double px = x-15, py = y;
	int i = 1;
	while(i < 5){
		MovePen(px + 1, py - 1);
		DrawLine(15 - i, 15 - i);
		px = px + 1;
		py = py - 1;
		i += 1;
	}
	
	//�������ͷ
	px = x+15; py = y;
	i=1;
	while(i < 5){
		MovePen(px - 1, py - 1);
		DrawLine(-(15 - i), 15 - i);
		px = px - 1;
		py = py - 1;
		i += 1;
	}

	SetPenColor("Brown");
	SetPenSize(2);
	//�󱳴���
	//px = x - 0.05;
	//py = y - kun_beidai_y;
	MovePen(x - 5,y - kun_beidai_y);
	DrawLine(0,-15);

	//�ұ�����
	//px = x + 0.05;
	//py = y - kun_beidai_y;
	MovePen(x + 5,y - kun_beidai_y);
	DrawLine(0,-15);
	
}

void CleanKUN(double x, double y, int direction)
{
	SetPenSize(1);
	SetPenColor("White");
	MovePen(x-15,y+15);
	int i=0;
	for(i=0;i<48;i++){
		DrawLine(32,0);
		MovePen(x-15,y+15-i);
	}
}