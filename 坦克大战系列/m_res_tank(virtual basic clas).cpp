#include "stdafx.h"
#include "my_resource.h"


//坦克 --- 抽象基类 成员函数
//坦克转向处理函数
void Tank::Tank_Route(void)
{
	if(1 == abs(command - orient) && command + orient != 3) //是转向反向
		Current_Speed = 0;
	else
		Current_Speed /=2;
	orient = command;
}

//坦克碰撞边界处理函数 -- 以后可以扩展成坦克有实体不能互相交叠 但是 时间不够 所以没做
void Tank::jam_process(void)
{
	if(UP == orient) //  y <= 50
	{
		if(pos_y <= TANK_WIDTH / 2)
		{
			Current_Speed = 0;
			pos_y = TANK_WIDTH / 2;
		}
	}
	else if(DOWN == orient) // y >= field
	{
		if(pos_y >= FIELD_HEIGHT - TANK_WIDTH / 2)
		{
			Current_Speed = 0;
			pos_y = FIELD_HEIGHT - TANK_WIDTH / 2;
		}
	}
	else if(LEFT == orient)
	{
		if(pos_x <= TANK_WIDTH / 2)
		{
			Current_Speed = 0;
			pos_x = TANK_WIDTH / 2;
		}
	}
	else if(RIGHT == orient)
	{
		if(pos_x >= FIELD_WIDTH - TANK_WIDTH / 2)
		{
			Current_Speed = 0;
			pos_x = FIELD_WIDTH - TANK_WIDTH / 2;
		}
	}
}

//（针对一个坦克）炮弹飞行函数
//v1.6 增加了特定射程 并且 优化了 飞出射程临界帧情况 使 炮弹一定能稳定打到最远射程

void Tank::shells_move(void)
{
	//炮弹速度衰减 
	shell_infor.speed *= 95;
	shell_infor.speed /= 100;

	//炮弹距离计算
	shell_infor.distance += shell_infor.speed;
	shell_infor.d_cut = 0;

	//int d_cut = 0; //超出距离修剪补正

	if(shell_infor.distance >= fire_range)
	{
		if(shell_infor.distance < fire_range + shell_infor.speed)
		{
			shell_infor.d_cut = shell_infor.distance - fire_range;
			shell_infor.distance = fire_range;
		}
		else
		{
			shell_on_field = 0;
		}
	}
	//速度太低也会消解
	if(shell_infor.speed < 13)
		shell_on_field = 0;


	if(UP == shell_infor.orient) // 向上  y -
	{
		shell_infor.pos_y -= shell_infor.speed - shell_infor.d_cut;

		shell_infor.pos_x -= shell_infor.disprecision / (fire_speed / (shell_infor.speed * 1.0));
	}
	else if(DOWN == shell_infor.orient) //向下 y+
	{
		shell_infor.pos_y += shell_infor.speed - shell_infor.d_cut;
		shell_infor.pos_x += shell_infor.disprecision / (fire_speed / (shell_infor.speed * 1.0));
	}
	else if(LEFT == shell_infor.orient) //向左 x-
	{
		shell_infor.pos_x -= shell_infor.speed - shell_infor.d_cut;
		shell_infor.pos_y -= shell_infor.disprecision / (fire_speed / (shell_infor.speed * 1.0));
	}
	else if(RIGHT == shell_infor.orient) //向右 x+
	{
		shell_infor.pos_x += shell_infor.speed - shell_infor.d_cut;
		shell_infor.pos_y += shell_infor.disprecision / (fire_speed / (shell_infor.speed * 1.0));
	}


}

// （针对一个坦克） 炮弹飞出边界的处理函数
void Tank::out_process(void)
{
	if(UP == shell_infor.orient) //  y <= 50
	{
		if(shell_infor.pos_y <= SHELL_WIDTH / 2 - shell_infor.speed)
		{
			shell_on_field = 0;
		}
	}
	else if(DOWN == shell_infor.orient) // y >= field
	{
		if(shell_infor.pos_y >= FIELD_HEIGHT - SHELL_WIDTH / 2 + shell_infor.speed)
		{
			shell_on_field = 0;
		}
	}
	else if(LEFT == shell_infor.orient)
	{
		if(shell_infor.pos_x <= SHELL_WIDTH / 2 - shell_infor.speed)
		{
			shell_on_field = 0;
		}
	}
	else if(RIGHT == shell_infor.orient)
	{
		if(shell_infor.pos_x >= FIELD_WIDTH - SHELL_WIDTH / 2 + shell_infor.speed)
		{
			shell_on_field = 0;
		}
	}
}

//坦克移动处理函数
void Tank::Tank_Move(void)
{
	if(STOP == command)
	{
		Current_Speed -= Accelerate_Power;
		if(Current_Speed < 0)
			Current_Speed = 0;
	}
	else if(command != orient && clock() - last_route >= route_interval * ROUTE_NERF) //转向成功
	{
		last_route = clock();
		Tank_Route();
	}
	else
	{
		Current_Speed += Accelerate_Power  * MOVE_NERF;
		if(Current_Speed > Max_Speed)
			Current_Speed = Max_Speed;
	}

	if(UP == orient) // 向上  y -
	{
		pos_y -= Current_Speed * MOVE_NERF;
	}
	else if(DOWN == orient) //向下 y+
	{
		pos_y += Current_Speed * MOVE_NERF;
	}
	else if(LEFT == orient) //向左 x-
	{
		pos_x -= Current_Speed * MOVE_NERF;
	}
	else if(RIGHT == orient) //向右 x+
	{
		pos_x += Current_Speed * MOVE_NERF;
	}
}

void Tank::Check_Block_By_River(void)
{
	int is_block = 0;
	for(int i = 0; i < river_box_number && !is_block; i++)
	{
		if(orient == UP)
		{
			//碰撞
			if(abs(pos_x - river_infor[i].x) < 80 && abs(pos_y - river_infor[i].y) < 80)
			{
				Current_Speed = 0;
				pos_y = river_infor[i].y + 80;
				is_block = 1;
			}
		}
		else if(orient == DOWN)
		{
			//碰撞
			if(abs(pos_x - river_infor[i].x) < 80 && abs(pos_y - river_infor[i].y) < 80)
			{
				Current_Speed = 0;
				pos_y = river_infor[i].y - 80;
				is_block = 1;
			}

		}
		else if(orient == LEFT)
		{
			//碰撞
			if(abs(pos_x - river_infor[i].x) < 80 && abs(pos_y - river_infor[i].y) < 80)
			{
				Current_Speed = 0;
				pos_x = river_infor[i].x + 80;
				is_block = 1;
			}
		}
		else if(orient == RIGHT)
		{
			//碰撞
			if(abs(pos_x - river_infor[i].x) < 80 && abs(pos_y - river_infor[i].y) < 80)
			{
				Current_Speed = 0;
				pos_x = river_infor[i].x - 80;
				is_block = 1;
			}

		}
	}
}

//112行