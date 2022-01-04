#include "stdafx.h"
#include "my_resource.h"
Shell::Shell(int x, int y, Orient init_orient, int init_speed)
{
	pos_x = x;
	pos_y = y;
	orient = init_orient;
	speed = init_speed;
	distance = 0;
	disprecision = 0;
	d_cut = 0;
}
Shell::Shell()
{
	pos_x = 0;
	pos_y = 0;
	orient = STOP;
	speed = 0;
	distance = 0;
	d_cut = 0;
	disprecision = 0;
}
//19ÐÐ