#include "stdafx.h"
#include "my_resource.h"
//NPC̹����
int NPC_Tank::AIM_RANGE =  58 - 2 * DIFFICULTY;   //��׼�ٽ�ֵ  ԽСԽ׼  ����̫С���޷�����  40 ���
int NPC_Tank::CLOSE_RANGE = 146 - 4 * DIFFICULTY;   //  ǿ׷���ٽ�ֵ   ԽСԽ�Ѱ��Ѳ���Խ�ѷ��ݵ��ǲ����׶��� Խ��Խ���׶��� �������ױ�����     
int NPC_Tank::ALERT_RANGE =  280 - 10 * DIFFICULTY;  //  ������ ���ƶ� Сһ��ȽϺ� ��������90
int NPC_Tank::TRIGGER_RANGE = 2800;  // ����AIֵ  Խ��Խ��

//��ʼ������ -- ��Ϊ NPC̹�˲���������仯̫�� ���� ֻ��Ϊһ�� ���㺯����ʹ��
NPC_Tank::NPC_Tank()
{
	precision = 93;
	orient = Orient(rand()%4);
	pos_x = rand() % (FIELD_WIDTH - 100) + 51;
	pos_y = rand() % (FIELD_HEIGHT - 100) + 51;
	//orient = UP;

	//������Ϣ
	fire_command = 0;
	command = Orient(rand()%4);

	penertrate_level = 7;
	ammor_level = 6;
	behind_ammor_level = 0;
	side_ammor_level = 2;

	//״̬��Ϣ
	is_hit = 0;
//	last_hit = 0;
	t_last_hit = -9900;
	last_hit_orient = FRONT;
	t_last_effect_penertrated = -9900;
	t_last_penertrated = -9900;

	is_engine_damage = 0;
	is_gun_damage = 0;

	//������Ϣ
	route_interval = 420;
	last_route = -420;
	Max_Speed = 13;
	Current_Speed = 0;
	Accelerate_Power = 3;

	fire_speed = E_FIRE_SPEED;

	//������Ϣ
	damage = 1600;
	fire_range = 1200;
	fire_interval = 770;
	last_fire = -770;
	shell_on_field = 0;

	//������Ϣ
	max_hitpoint = 9000;
	restore_per_update = 30;
	current_hitpoint = max_hitpoint;
	current_max_hitpoint = max_hitpoint;
	die_time = - 9999;
	is_explose = 0;

	//ʶ����Ϣ 
	rc = NORMAL;
	strcpy(name, "Ĭ������NPC");
	is_on_field = 1; 
	protect_index = 0;
	target_index = 0;

	//���ӷ�����Ϣ
	penertrated_detonation_rate = 12;
	effective_penertrated_detonation_rate = 20;
	engine_damage_rate = 100;
	gun_damage_rate = 20;

	//ͼ��
	icon = G_T1;
	gold = 10;
	Vp_range = 800;
	pretend_range = 300;

	//���ر�����Ϣ
	dmg_recv = 0;
	kill = 0;
	dmg_cause = 0;
	icon = UK_T1;
	is_engine_damage = 0;
	is_gun_damage = 0;
}

//��������ֵ����Ϣ�ĳ�ʼ������
NPC_Tank::NPC_Tank(int hp, int damage, int fire_interval, int Maxspeed, int accerelerate)
{
	max_hitpoint = hp;
	current_max_hitpoint = hp;
	current_hitpoint = hp;
	this->damage = damage;
	this->fire_interval = fire_interval;
	this->Max_Speed = Maxspeed;
	this->Current_Speed = 0;
	this->Accelerate_Power = accerelerate;
}

//��ͨAI ֻ��������ں��ƶ�
void NPC_Tank::Tank_Control_Normal(void)
{
	//�ƶ����� �� �������
	if(STOP == command || Current_Speed == 0)
		command = Orient(rand() % 5);
	fire_command = 1;

	if(Current_Speed >= 0.7 * Max_Speed || Current_Speed == 0)
		command = Orient(rand() % 5);

	if(current_hitpoint) //���廹��
	{
		//�ָ�
		current_hitpoint += restore_per_update;
		if(current_hitpoint > current_max_hitpoint)
			current_hitpoint = current_max_hitpoint;

		//�ƶ����� �� �������
		Tank_Move();
		//��ײ���
		Check_Block_By_River();jam_process();
	}

	//����Ƿ������µ��ڵ�
	if(1 == fire_command)
		try_fire();

	//��տ�����Ϣ
	fire_command = 0;
}


//��AI 
void NPC_Tank::Tank_Control_Ambush(int x, int y)
{
	if(current_hitpoint) //���廹��
	{
		//����ģʽ�»��ܻ�Ѫ
		current_hitpoint += restore_per_update;
		if(current_hitpoint > current_max_hitpoint)
			current_hitpoint = current_max_hitpoint;


		fire_command = 0;
		//���¿�������


		//������
		//Զ�� -- �ƽ�

		int dis = abs(x - pos_x) + abs(y - pos_y);
		int dis_x = abs(x - pos_x);
		int dis_y = abs(y - pos_y);


		//��д���߼�
		//����Ŀ���Զ ֻҪ������ �Ϳ���
		if(abs(pos_x - x) <= AIM_RANGE && abs(pos_y - y) < fire_range) // ������һ�� (��������)
		{
			fire_command = 1;
			if(pos_y >= y) // ������
			{
				fire_command = 0;
				if(orient == UP)
				{
					fire_command = 1;
				}

				if(orient == UP && abs(pos_y - y) <= pretend_range)
					command = STOP;
				else
					command = UP;
			}
			else
			{
				fire_command = 0;
				if(orient == DOWN)
				{
					fire_command = 1;
				}

				if(orient == DOWN && abs(pos_y - y) <= pretend_range)
					command = STOP;
				else
					command = DOWN;
			}
		}
		else if(abs(pos_y - y) <= AIM_RANGE && abs(pos_x - x) < fire_range) //������һ��
		{
			if(pos_x >= x) // ������
			{
				fire_command = 0;
				if(orient == LEFT)
				{
					fire_command = 1;
				}
				if(orient == LEFT && abs(pos_x - x) <= pretend_range)
					command = STOP;
				else // ������Ч��
					command = LEFT;

			}
			else
			{
				fire_command = 0;
				if(orient == RIGHT)
				{
					fire_command = 1;
				}

				if(orient == RIGHT && abs(pos_x - x) <= pretend_range)
					command = STOP;
				else
					command = RIGHT;
			}
		}

		//û���� ��������


		else if(dis > Vp_range)
		{
			//�ƶ����� �� �������
			if(STOP == command || Current_Speed == 0)
				command = Orient(rand() % 5);
			fire_command = 1;

			if(Current_Speed >= 0.7 * Max_Speed || Current_Speed == 0)
				command = Orient(rand() % 5);
		}



		else if(abs(pos_x - x) > ALERT_RANGE && abs(pos_x - x) <= TRIGGER_RANGE)
		{
			if(pretend_range >= 550)
			{
				if(dis_x < dis_y)
				{
					if(pos_x < x ) // 
						command = RIGHT;
					else
						command = LEFT;
				}
				else
				{
					if(pos_y < y)
						command = DOWN;
					else
						command = UP;
				}
			}
			else
			{
				if(dis_x > dis_y)
				{
					if(pos_x < x ) // 
						command = RIGHT;
					else
						command = LEFT;
				}
				else
				{
					if(pos_y < y)
						command = DOWN;
					else
						command = UP;
				}
			}
		}

		//׷�� 
		/*
		else if(abs(pos_x - x) <= ALERT_RANGE && abs(pos_x - x) > AIM_RANGE)
		{
			if(pos_x < x ) // 
				command = RIGHT;
			else
				command = LEFT;
		}
		//��׼ �� ���� -- �ڷ����ʱ�� ͣ��
		*/


		//������
		//Զ��
		else if(abs(pos_y - y) > ALERT_RANGE && abs(pos_y - y) <= TRIGGER_RANGE)
		{
		
			if(pretend_range >= 550)
			{
				if(dis_x < dis_y)
				{
					if(pos_x < x ) // 
						command = RIGHT;
					else
						command = LEFT;
				}
				else
				{
					if(pos_y < y)
						command = DOWN;
					else
						command = UP;
				}
			}
			else
			{
				if(dis_x > dis_y)
				{
					if(pos_x < x ) // 
						command = RIGHT;
					else
						command = LEFT;
				}
				else
				{
					if(pos_y < y)
						command = DOWN;
					else
						command = UP;
				}
			}
		}

		else if(abs(pos_y - y) <= ALERT_RANGE && abs(pos_y - y) > AIM_RANGE || (abs(pos_x - x) <= ALERT_RANGE && abs(pos_x - x) > AIM_RANGE))
		{
			if(pretend_range >= 550)
			{
				if(dis_x < dis_y)
				{
					if(pos_x < x ) // 
						command = RIGHT;
					else
						command = LEFT;
				}
				else
				{
					if(pos_y < y)
						command = DOWN;
					else
						command = UP;
				}
			}
			else
			{
				if(dis_x > dis_y)
				{
					if(pos_x < x ) // 
						command = RIGHT;
					else
						command = LEFT;
				}
				else
				{
					if(pos_y < y)
						command = DOWN;
					else
						command = UP;
				}
			}
		}
		//��׼���� -- ������ͣ��


		

		//�ƶ�����
		else
		{
			fire_command = 1;
			command = orient;
			if(Current_Speed >= 0.9 * Max_Speed || Current_Speed == 0)
				command = Orient(rand() % 5);
		}

		//�ƶ��������ײ����
		Tank_Move();
		Check_Block_By_River();
		jam_process();
	}
	//���Եо����޸Ĳ���ͬ��



	//����Ƿ������µ��ڵ�
	if(1 == fire_command)
		try_fire();

	//��տ�����Ϣ
	fire_command = 0;
}

//AI ����ָ���
void NPC_Tank::try_fire(void)
{
	if(clock() - last_fire <= fire_interval * FIRE_NERF || shell_on_field) //��� ���ϻ����ڵ����� �ڵ�ûװ�� �Ͳ��ܷ���
		return ;


	shell_on_field = 1;
	last_fire = clock();
	if(LEFT == orient) //��  x - 51
		shell_infor = Shell(pos_x - 51, pos_y, LEFT, fire_speed);
	else if(RIGHT == orient) // ��  x + 51
		shell_infor = Shell(pos_x + 51, pos_y, RIGHT, fire_speed);
	else if(UP == orient ) //�� y -51
		shell_infor = Shell(pos_x, pos_y - 51, UP, fire_speed);
	else if(DOWN == orient)
		shell_infor = Shell(pos_x, pos_y + 51, DOWN, fire_speed);

	//shell_infor.disprecision = rand() % ((100 - precision) * 2) + 1 - (100 - precision);
}

//��ͨ׷�ٹ��� ����  
void NPC_Tank::Tank_Control_ELITE(int x, int y)
{
	if(current_hitpoint) //���廹��
	{
		//����ģʽ�»��ܻ�Ѫ
		current_hitpoint += restore_per_update;
		if(current_hitpoint > current_max_hitpoint)
			current_hitpoint = current_max_hitpoint;


		fire_command = 0;
		//���¿�������


		//������



		if(abs(pos_x - x) <= AIM_RANGE ) // ������һ�� (��������)
		{
			fire_command = 0;
			if(pos_y >= y) // ������
			{
				if(orient == UP)
				{
					fire_command = 1;
				}
				command = UP;
			}
			else
			{
				if(orient == DOWN)
				{
					fire_command = 1;
				}
				command = DOWN;
			}
		}
		else if(abs(pos_y - y) <= AIM_RANGE) //������һ��
		{
			fire_command = 0;
			if(pos_x >= x) // ������
			{
				if(orient == LEFT)
				{
					fire_command = 1;
				}
				command = LEFT;
			}
			else
			{
				if(orient == RIGHT)
				{
					fire_command = 1;
				}
				command = RIGHT;
			}
		}


		//Զ�� -- �ƽ�
		else
		{
			Orient command1 = STOP;
			Orient command2 = STOP;
			if(pos_x < x ) // 
				command1 = RIGHT;
			else
				command1 = LEFT;
			if(pos_y < y)
				command2 = DOWN;
			else
				command2 = UP;
			int c = rand() % 10;

			if(c < 6)
				command = command1;
			else
				command = command2;

		}


		Tank_Move();
		Check_Block_By_River();jam_process();
	}
	//���Եо����޸Ĳ���ͬ��



	//����Ƿ������µ��ڵ�
	if(1 == fire_command)
		try_fire();
	//��տ�����Ϣ
	fire_command = 0;
}

//���ز���
void NPC_Tank::Tank_Control_VP(int x, int y)
{
	if(current_hitpoint) //���廹��
	{
		//����ģʽ�»��ܻ�Ѫ
		current_hitpoint += restore_per_update;
		if(current_hitpoint > current_max_hitpoint)
			current_hitpoint = current_max_hitpoint;


		fire_command = 0;
		//������������


		//������
		int dis = abs(x - pos_x) + abs(y - pos_y);
		if(dis > Vp_range)
		{
			//�ƶ����� �� �������
			if(STOP == command || Current_Speed == 0)
				command = Orient(rand() % 5);
			fire_command = 1;

			if(Current_Speed >= 0.7 * Max_Speed || Current_Speed == 0)
				command = Orient(rand() % 5);
		}


		//������Ч

		else if(abs(pos_x - x) <= AIM_RANGE ) // ������һ�� (��������)
		{
			fire_command = 0;
			if(pos_y >= y) // ������
			{
				if(orient == UP)
				{
					fire_command = 1;
				}
				command = UP;
			}
			else
			{
				if(orient == DOWN)
				{
					fire_command = 1;
				}
				command = DOWN;
			}
		}
		else if(abs(pos_y - y) <= AIM_RANGE) //������һ��
		{
			fire_command = 0;
			if(pos_x >= x) // ������
			{
				if(orient == LEFT)
				{
					fire_command = 1;
				}
				command = LEFT;
			}
			else
			{
				if(orient == RIGHT)
				{
					fire_command = 1;
				}
				command = RIGHT;
			}
		}


		//Զ�� -- �ƽ�
		else
		{
			Orient command1 = STOP;
			Orient command2 = STOP;
			if(pos_x < x ) // 
				command1 = RIGHT;
			else
				command1 = LEFT;
			if(pos_y < y)
				command2 = DOWN;
			else
				command2 = UP;
			int c = rand() % 10;

			if(c < 6)
				command = command1;
			else
				command = command2;

		}

		Tank_Move();
		Check_Block_By_River();jam_process();
	}
	//���Եо����޸Ĳ���ͬ��

	//����Ƿ������µ��ڵ�
	if(1 == fire_command)
		try_fire();

	//��տ�����Ϣ
	fire_command = 0;
}

//�������� -- Ŀ��ѡ�� ������Ȼ��������Ǹ�
void NPC_Tank::Tank_Control_Turret(int x, int y)
{
	if(current_hitpoint) //���廹��
	{
		//����ģʽ�»��ܻ�Ѫ
		current_hitpoint += restore_per_update;
		if(current_hitpoint > current_max_hitpoint)
			current_hitpoint = current_max_hitpoint;


		fire_command = 0;
		//������������
		command = STOP;


		//������
		int dis_x = abs(x - pos_x);
		int dis_y = abs(y - pos_y);

		if(abs(pos_x - x) <= AIM_RANGE + 25 ) // ������һ�� (��������)
		{
			fire_command = 0;
			if(pos_y >= y) // ������
			{
				if(orient == UP)
				{
					fire_command = 1;
				}
				else
					command = UP;
			}
			else
			{
				if(orient == DOWN)
				{
					fire_command = 1;
				}
				else
					command = DOWN;
			}
		}
		else if(abs(pos_y - y) <= AIM_RANGE + 25) //������һ��
		{
			fire_command = 0;
			if(pos_x >= x) // ������
			{
				if(orient == LEFT)
				{
					fire_command = 1;
				}
				else
					command = LEFT;
			}
			else
			{
				if(orient == RIGHT)
				{
					fire_command = 1;
				}
				else
					command = RIGHT;
			}
		}
		Tank_Move();
		Check_Block_By_River();jam_process();
	}
	//���Եо����޸Ĳ���ͬ��



	//����Ƿ������µ��ڵ�
	if(1 == fire_command)
		try_fire();

	//��տ�����Ϣ
	fire_command = 0;
}

//�����ؼ�Ŀ��Ĳ���
void NPC_Tank::Tank_Control_Protect(int p_x, int p_y, int x, int y)
{
	if(current_hitpoint) //���廹��
	{
		//����ģʽ�»��ܻ�Ѫ
		current_hitpoint += restore_per_update;
		if(current_hitpoint > current_max_hitpoint)
			current_hitpoint = current_max_hitpoint;


		fire_command = 0;
		//���¿�������


		//������
		//���� 
		if(abs(pos_x - p_x) >= 80)
		{
			if(pos_x > p_x) // �ұ� ������
			{
				command = LEFT;
			}
			else
			{
				command = RIGHT;
			}
		}
		else if(abs(pos_y - p_y) >= 80)
		{
			if(pos_y > p_y) 
			{
				command = UP;
			}
			else
			{
				command = DOWN;
			}
		}

		//����
		else if(abs(pos_x - x) <= AIM_RANGE ) // ������һ�� (��������)
		{
			fire_command = 0;
			if(pos_y >= y) // ������
			{
				if(orient == UP)
				{
					fire_command = 1;
				}
				command = UP;
			}
			else
			{
				if(orient == DOWN)
				{
					fire_command = 1;
				}
				command = DOWN;
			}
		}
		else if(abs(pos_y - y) <= AIM_RANGE) //������һ��
		{
			fire_command = 0;
			if(pos_x >= x) // ������
			{
				if(orient == LEFT)
				{
					fire_command = 1;
				}
				command = LEFT;
			}
			else
			{
				if(orient == RIGHT)
				{
					fire_command = 1;
				}
				command = RIGHT;
			}
		}


		//Զ�� -- ����
		else
		{
			/*
			Orient command1 = STOP;
			Orient command2 = STOP;
			if(pos_x < x ) // 
				command1 = RIGHT;
			else
				command1 = LEFT;
			if(pos_y < y)
				command2 = DOWN;
			else
				command2 = UP;
			int c = rand() % 10;

			if(c < 6)
				command = command1;
			else
				command = command2;
				*/
		}
		Tank_Move();
		Check_Block_By_River();jam_process();
	}

	//����Ƿ������µ��ڵ�
	if(1 == fire_command)
		try_fire();

	//��տ�����Ϣ
	fire_command = 0;
}
//���� 1076��