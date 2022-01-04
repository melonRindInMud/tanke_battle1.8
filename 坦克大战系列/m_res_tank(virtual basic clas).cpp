#include "stdafx.h"
#include "my_resource.h"


//̹�� --- ������� ��Ա����
//̹��ת������
void Tank::Tank_Route(void)
{
	if(1 == abs(command - orient) && command + orient != 3) //��ת����
		Current_Speed = 0;
	else
		Current_Speed /=2;
	orient = command;
}

//̹����ײ�߽紦���� -- �Ժ������չ��̹����ʵ�岻�ܻ��ཻ�� ���� ʱ�䲻�� ����û��
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

//�����һ��̹�ˣ��ڵ����к���
//v1.6 �������ض���� ���� �Ż��� �ɳ�����ٽ�֡��� ʹ �ڵ�һ�����ȶ�����Զ���

void Tank::shells_move(void)
{
	//�ڵ��ٶ�˥�� 
	shell_infor.speed *= 95;
	shell_infor.speed /= 100;

	//�ڵ��������
	shell_infor.distance += shell_infor.speed;
	shell_infor.d_cut = 0;

	//int d_cut = 0; //���������޼�����

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
	//�ٶ�̫��Ҳ������
	if(shell_infor.speed < 13)
		shell_on_field = 0;


	if(UP == shell_infor.orient) // ����  y -
	{
		shell_infor.pos_y -= shell_infor.speed - shell_infor.d_cut;

		shell_infor.pos_x -= shell_infor.disprecision / (fire_speed / (shell_infor.speed * 1.0));
	}
	else if(DOWN == shell_infor.orient) //���� y+
	{
		shell_infor.pos_y += shell_infor.speed - shell_infor.d_cut;
		shell_infor.pos_x += shell_infor.disprecision / (fire_speed / (shell_infor.speed * 1.0));
	}
	else if(LEFT == shell_infor.orient) //���� x-
	{
		shell_infor.pos_x -= shell_infor.speed - shell_infor.d_cut;
		shell_infor.pos_y -= shell_infor.disprecision / (fire_speed / (shell_infor.speed * 1.0));
	}
	else if(RIGHT == shell_infor.orient) //���� x+
	{
		shell_infor.pos_x += shell_infor.speed - shell_infor.d_cut;
		shell_infor.pos_y += shell_infor.disprecision / (fire_speed / (shell_infor.speed * 1.0));
	}


}

// �����һ��̹�ˣ� �ڵ��ɳ��߽�Ĵ�����
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

//̹���ƶ�������
void Tank::Tank_Move(void)
{
	if(STOP == command)
	{
		Current_Speed -= Accelerate_Power;
		if(Current_Speed < 0)
			Current_Speed = 0;
	}
	else if(command != orient && clock() - last_route >= route_interval * ROUTE_NERF) //ת��ɹ�
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

	if(UP == orient) // ����  y -
	{
		pos_y -= Current_Speed * MOVE_NERF;
	}
	else if(DOWN == orient) //���� y+
	{
		pos_y += Current_Speed * MOVE_NERF;
	}
	else if(LEFT == orient) //���� x-
	{
		pos_x -= Current_Speed * MOVE_NERF;
	}
	else if(RIGHT == orient) //���� x+
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
			//��ײ
			if(abs(pos_x - river_infor[i].x) < 80 && abs(pos_y - river_infor[i].y) < 80)
			{
				Current_Speed = 0;
				pos_y = river_infor[i].y + 80;
				is_block = 1;
			}
		}
		else if(orient == DOWN)
		{
			//��ײ
			if(abs(pos_x - river_infor[i].x) < 80 && abs(pos_y - river_infor[i].y) < 80)
			{
				Current_Speed = 0;
				pos_y = river_infor[i].y - 80;
				is_block = 1;
			}

		}
		else if(orient == LEFT)
		{
			//��ײ
			if(abs(pos_x - river_infor[i].x) < 80 && abs(pos_y - river_infor[i].y) < 80)
			{
				Current_Speed = 0;
				pos_x = river_infor[i].x + 80;
				is_block = 1;
			}
		}
		else if(orient == RIGHT)
		{
			//��ײ
			if(abs(pos_x - river_infor[i].x) < 80 && abs(pos_y - river_infor[i].y) < 80)
			{
				Current_Speed = 0;
				pos_x = river_infor[i].x - 80;
				is_block = 1;
			}

		}
	}
}

//112��