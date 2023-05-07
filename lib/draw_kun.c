#include "draw_kun.h"
#include <math.h>

#define PI acos(-1)
#define kun_beidai_y 0.05*tan(PI/3)

/**************
������������ͷ�����
***************/
void DrawKUN(double x, double y, int direction)
{
	SetPenColor("Blue");
	SetPenSize(2);
	
	//������
	MovePen(x+0.1,y);    //0.1Ϊ�����뾶
	DrawArc(0.1,0,360);
	
	//����ͷ
	MovePen(x,y+0.1);
	DrawLine(0,0.05);
	DrawLine(-0.15,-0.15);
	DrawLine(0.05,-0.05);
	DrawLine(0.1,0.1);
	DrawLine(0,0.05);
	
	//����ͷ
	MovePen(x,y+0.1);
	DrawLine(0,0.05);
	DrawLine(0.15,-0.15);
	DrawLine(-0.05,-0.05);
	DrawLine(-0.1,0.1);
	DrawLine(0,0.05);

	//�������ͷ
	double px = x-0.15, py = y;
	int i = 1;
	while(i < 10){
		MovePen(px + 0.005, py - 0.005);
		DrawLine(0.15 - i*0.005, 0.15 - i*0.005);
		px = px + 0.005;
		py = py - 0.005;
		i += 1;
	}
	
	//�������ͷ
	px = x+0.15; py = y;
	i=1;
	while(i < 10){
		MovePen(px - 0.005, py - 0.005);
		DrawLine(-(0.15 - i*0.005), 0.15 - i*0.005);
		px = px - 0.005;
		py = py - 0.005;
		i += 1;
	}

	SetPenColor("Brown");
	SetPenSize(2);
	//�󱳴���
	//px = x - 0.05;
	//py = y - kun_beidai_y;
	MovePen(x - 0.05,y - kun_beidai_y);
	DrawLine(0,-0.15);

	//�ұ�����
	//px = x + 0.05;
	//py = y - kun_beidai_y;
	MovePen(x + 0.05,y - kun_beidai_y);
	DrawLine(0,-0.15);
	
}

void CleanKUN(double x, double y, int direction)
{
	SetPenSize(1);
	SetPenColor("White");
	MovePen(x-0.15,y+0.15);
	int i=0;
	for(i=0;i<48;i++){
		DrawLine(0.31,0);
		MovePen(x-0.15,y+0.15-0.01*i);
	}
}