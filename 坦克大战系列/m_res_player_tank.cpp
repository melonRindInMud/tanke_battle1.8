#include "stdafx.h"
#include "my_resource.h"
#include "resource.h"
//������ -- ���̹�˵���Ϣ 
//��������кܶྲ̬��Ա -- ���ڼ�¼�ᴩ������Ϸ��̹����Ϣ
int Player_Tank::difficulty = 0;  // �Ѷ�����
int Player_Tank::use_shell = 0;   // ��ǰ�ؿ��ڵ�ʹ�����
int Player_Tank::is_choice = 0;   //   
int Player_Tank::upgrade_generation = 0;  //�����ָ��Ƿ����� -- �����ƻ���20���������ϵͳ ���� ���ڲű���ʮ����
int Player_Tank::upgrade_engine = 0;   // �����Ƿ������� -- ���߹��Ժ���������
int Player_Tank::upgrade_command = 0;   // �Ƿ�����С��ָ��  ��ʮ�����Ժ���
int Player_Tank::upgrade_gun = 0; //�������� -- ������װ��ϵͳ����ؿ�����
int Player_Tank::energy =  0; //���� -- ����������װ�� 
int Player_Tank::kill_stack = 0;
clock_t Player_Tank::last_kill = 0;

//���캯�� -- ��ʼ���� ���� ��̬���� �Ѷ� ���趨 -- ��Ҳ��Ϊʲô�Ѷ�û���趨�ڶԻ������� �����Ļ� �൱������� ��Ƕ�� ����ȫ�ֻ��ߴ��ݲ�����������޷����� -- �Ƚ��鷳
Player_Tank::Player_Tank()
{
	  //����λ����Ϣ
	orient = Orient(rand()%4);
	pos_x = rand() % (FIELD_WIDTH - 100) + 51;
	pos_y = rand() % (FIELD_HEIGHT - 100) + 51;

	//������Ϣ
	fire_command = 0;
	command = STOP;
	//last_command = 0;

	//���������
	penertrate_level = 5;
	ammor_level = 2;

	//ͼ��
	icon = G_T1;

	is_hit = 0;
//	last_hit = 0;
	t_last_hit = -9900;
	t_last_effect_hit = -9900;
	t_last_fital_hit = -9900;
	t_last_effect_penertrated = -9900;
	t_last_penertrated = -9900;
	last_hit_orient = FRONT;


	//������Ϣ
	route_interval = 95;
	last_route = -95;
	init_fastest_route_interval = 95;

	penertrate_level = 7;
	ammor_level = 6;
	side_ammor_level = 2;
	behind_ammor_level = 0;


	is_engine_damage = 0;
	is_gun_damage = 0;

	Max_Speed = 19;
	init_max_speed = Max_Speed;
	Current_Speed = 0;
	Accelerate_Power = 5;
	init_accelerate_power = 5;

	fire_range = 1200;
	precision = 99;

	if(difficulty == 0) //���Ѷ�
	{
		icon = G_T1;
		penertrate_level += 1;
		side_ammor_level += 1;
		behind_ammor_level += 1;

		damage = 1200;
		max_damage = damage;
		fire_interval = 660;
		fastest_fire_interval = fire_interval;
		last_fire = -660;
		shell_on_field = 0;
		fire_speed = FIRE_SPEED + 45;
		Max_Speed = 17;
		init_max_speed = Max_Speed;
		Accelerate_Power = 11;
		init_accelerate_power = 11;
		fire_range += 300;


		//������Ϣ
		max_hitpoint = 9800;
		current_max_hitpoint = max_hitpoint;
		current_hitpoint = max_hitpoint;
		engine_damage_rate = 55;
		gun_damage_rate = 7;

	}
	else if(difficulty == 1) //��ͨ�Ѷ�
	{

		behind_ammor_level += 1;

		damage = 900;
		max_damage = damage;
		fire_interval = 700;
		fastest_fire_interval = fire_interval;
		last_fire = -700;
		shell_on_field = 0;
		fire_speed = FIRE_SPEED + 25;
		Max_Speed = 18;
		init_max_speed = Max_Speed;
		Accelerate_Power = 10;
		init_accelerate_power = 10;
		fire_range += 100;

		//������Ϣ
		max_hitpoint = 6200;
		current_max_hitpoint = max_hitpoint;
		current_hitpoint = max_hitpoint;
		engine_damage_rate = 75;
		gun_damage_rate = 15;

	}
	else if(difficulty == 2)
	{
		//������װ�����bug����ֻ��������ؿ�����
		//�����Ѷ���������װ��
		//upgrade_gun = 1;
		damage = 600;
		max_damage = damage;
		fire_interval = 770;
		fastest_fire_interval = fire_interval;
		last_fire = -770;
		shell_on_field = 0;
		fire_speed = FIRE_SPEED;

		//������Ϣ
		max_hitpoint = 2300;
		current_max_hitpoint = max_hitpoint;
		current_hitpoint = max_hitpoint;
		engine_damage_rate = 100;
		gun_damage_rate = 25;

	}

	//�����Ѷ�
	else if(difficulty == -1)
	{
		icon = G_T2;
		penertrate_level += 100;
		ammor_level += 98;
		side_ammor_level += 80;
		behind_ammor_level += 80;

		damage =110000;
		max_damage = damage;
		fire_interval = 330;
		fastest_fire_interval = fire_interval;
		last_fire = -330;
		shell_on_field = 0;
		fire_speed = FIRE_SPEED + 125;
		Max_Speed = 30;
		init_max_speed = Max_Speed;
		Accelerate_Power = 20;
		init_accelerate_power = 20;

		//������Ϣ
		max_hitpoint = 1050000;
		current_max_hitpoint = max_hitpoint;
		current_hitpoint = max_hitpoint;
		engine_damage_rate = 0;
		gun_damage_rate = 0;

	}
	//������Ϣ

	die_time = -9999;

	//ʶ����Ϣ
	rc = PLAYER;
	strcpy(name, "���� ������˹");

	//������Ϣ
	total_kill = 0;
	gold = 0;

	//���ӷ�����Ϣ
	penertrated_detonation_rate = 0;
	effective_penertrated_detonation_rate = 0;


	dmg_cause = 0;
	dmg_recv = 0;
	kill = 0;
	is_on_field = 1;

}

//�������̹�˿�����Ϣ�ĺ��� -- �����е㲻̫׼ȷ
void Player_Tank::Tank_Control_Normal(void)
{
	//����ϵͳ

	//�Զ��޸�ϵͳ
	int r_time = RECOVER_TIME;
	int current_clock = clock();

	bool g = (current_clock - t_last_fital_hit >= ENGINE_REPAIR_TIME);

	if(upgrade_engine && current_clock - last_route >= 1050 / ((float)MOVE_NERF) && g) // �������治��
	{
		Max_Speed = init_max_speed * 1.5;
	}
	else if(g)
	{
		Max_Speed = init_max_speed;
	}

	if(upgrade_generation)
	{
		r_time /= 2;;
	}

	if(current_clock - t_last_effect_hit >= r_time)
	{
		if(upgrade_generation) // ���޿��޸� -- ����֮��
		{
			current_hitpoint += max_hitpoint/50;	
			current_max_hitpoint += (max_hitpoint - current_max_hitpoint) / 50;
		}
		else 
		{
			current_hitpoint += max_hitpoint/100;
		}
	}

	if(current_max_hitpoint >= max_hitpoint)
		current_max_hitpoint = max_hitpoint;
	if(current_hitpoint >= current_max_hitpoint)
		current_hitpoint = current_max_hitpoint;


	if(GetKeyState(VK_UP) & 0x8000) //������� ������
		command = UP; //ö������
	else if(GetKeyState(VK_DOWN) & 0x8000)
		command = DOWN;
	else if(GetKeyState(VK_LEFT) & 0x8000)
		command = LEFT;
	else if(GetKeyState(VK_RIGHT) & 0x8000)
		command = RIGHT;
	else
		command = STOP;//�ҾͲ���switch

	Tank_Move();

	Check_Block_By_River();
	jam_process();

	//����Ƿ������µ��ڵ�
	if(1 == fire_command)
		try_fire();

	//�����Ժ�Ҫ��շ�����Ϣ
	command = STOP;
	//��տ�����Ϣ
	fire_command = 0;
}


//�Ƿ���Է����ڵ� �Լ�������ڵ�����Ϣ
void Player_Tank::try_fire(void)
{
	if(clock() - last_fire <= fire_interval * FIRE_NERF || shell_on_field) //��� ���ϻ����ڵ����� �ڵ�ûװ�� �Ͳ��ܷ���
		return ;

	my_sound_player(FIRE_SOUND);
	Player_Tank::use_shell += 1;

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

	//shell_infor.disprecision = (rand() % ((100 - precision) * 2)) + 1 - (100 - precision);

}
//���� 324��