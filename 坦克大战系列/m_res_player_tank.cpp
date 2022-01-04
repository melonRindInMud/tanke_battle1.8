#include "stdafx.h"
#include "my_resource.h"
#include "resource.h"
//派生类 -- 玩家坦克的信息 
//这个类中有很多静态成员 -- 用于记录贯穿整个游戏的坦克信息
int Player_Tank::difficulty = 0;  // 难度设置
int Player_Tank::use_shell = 0;   // 当前关卡炮弹使用情况
int Player_Tank::is_choice = 0;   //   
int Player_Tank::upgrade_generation = 0;  //生命恢复是否升级 -- 本来计划在20关升级这个系统 但是 现在才编了十三关
int Player_Tank::upgrade_engine = 0;   // 引擎是否升级了 -- 第七关以后升级引擎
int Player_Tank::upgrade_command = 0;   // 是否开启了小队指令  第十二关以后开启
int Player_Tank::upgrade_gun = 0; //主炮升级 -- 主炮再装填系统特殊关卡可用
int Player_Tank::energy =  0; //能量 -- 用于主炮再装填 
int Player_Tank::kill_stack = 0;
clock_t Player_Tank::last_kill = 0;

//构造函数 -- 初始参数 根据 静态变量 难度 来设定 -- 这也是为什么难度没有设定在对话框类中 那样的话 相当于是外界 反嵌套 不开全局或者传递参数的情况下无法访问 -- 比较麻烦
Player_Tank::Player_Tank()
{
	  //方向位置信息
	orient = Orient(rand()%4);
	pos_x = rand() % (FIELD_WIDTH - 100) + 51;
	pos_y = rand() % (FIELD_HEIGHT - 100) + 51;

	//控制信息
	fire_command = 0;
	command = STOP;
	//last_command = 0;

	//穿深与防护
	penertrate_level = 5;
	ammor_level = 2;

	//图标
	icon = G_T1;

	is_hit = 0;
//	last_hit = 0;
	t_last_hit = -9900;
	t_last_effect_hit = -9900;
	t_last_fital_hit = -9900;
	t_last_effect_penertrated = -9900;
	t_last_penertrated = -9900;
	last_hit_orient = FRONT;


	//机动信息
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

	if(difficulty == 0) //简单难度
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


		//生命信息
		max_hitpoint = 9800;
		current_max_hitpoint = max_hitpoint;
		current_hitpoint = max_hitpoint;
		engine_damage_rate = 55;
		gun_damage_rate = 7;

	}
	else if(difficulty == 1) //普通难度
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

		//生命信息
		max_hitpoint = 6200;
		current_max_hitpoint = max_hitpoint;
		current_hitpoint = max_hitpoint;
		engine_damage_rate = 75;
		gun_damage_rate = 15;

	}
	else if(difficulty == 2)
	{
		//主炮再装填过于bug现在只能在特殊关卡里用
		//困难难度送主炮再装填
		//upgrade_gun = 1;
		damage = 600;
		max_damage = damage;
		fire_interval = 770;
		fastest_fire_interval = fire_interval;
		last_fire = -770;
		shell_on_field = 0;
		fire_speed = FIRE_SPEED;

		//生命信息
		max_hitpoint = 2300;
		current_max_hitpoint = max_hitpoint;
		current_hitpoint = max_hitpoint;
		engine_damage_rate = 100;
		gun_damage_rate = 25;

	}

	//作弊难度
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

		//生命信息
		max_hitpoint = 1050000;
		current_max_hitpoint = max_hitpoint;
		current_hitpoint = max_hitpoint;
		engine_damage_rate = 0;
		gun_damage_rate = 0;

	}
	//火力信息

	die_time = -9999;

	//识别信息
	rc = PLAYER;
	strcpy(name, "奥托 卡尔乌斯");

	//积分信息
	total_kill = 0;
	gold = 0;

	//附加防护信息
	penertrated_detonation_rate = 0;
	effective_penertrated_detonation_rate = 0;


	dmg_cause = 0;
	dmg_recv = 0;
	kill = 0;
	is_on_field = 1;

}

//处理玩家坦克控制信息的函数 -- 名字有点不太准确
void Player_Tank::Tank_Control_Normal(void)
{
	//加速系统

	//自动修复系统
	int r_time = RECOVER_TIME;
	int current_clock = clock();

	bool g = (current_clock - t_last_fital_hit >= ENGINE_REPAIR_TIME);

	if(upgrade_engine && current_clock - last_route >= 1050 / ((float)MOVE_NERF) && g) // 并且引擎不损坏
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
		if(upgrade_generation) // 上限可修复 -- 复苏之风
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


	if(GetKeyState(VK_UP) & 0x8000) //方向键上 被按下
		command = UP; //枚举真香
	else if(GetKeyState(VK_DOWN) & 0x8000)
		command = DOWN;
	else if(GetKeyState(VK_LEFT) & 0x8000)
		command = LEFT;
	else if(GetKeyState(VK_RIGHT) & 0x8000)
		command = RIGHT;
	else
		command = STOP;//我就不用switch

	Tank_Move();

	Check_Block_By_River();
	jam_process();

	//检测是否生成新的炮弹
	if(1 == fire_command)
		try_fire();

	//画完以后要清空方向信息
	command = STOP;
	//清空开炮信息
	fire_command = 0;
}


//是否可以发射炮弹 以及发射的炮弹的信息
void Player_Tank::try_fire(void)
{
	if(clock() - last_fire <= fire_interval * FIRE_NERF || shell_on_field) //如果 场上还有炮弹或者 炮弹没装好 就不能发射
		return ;

	my_sound_player(FIRE_SOUND);
	Player_Tank::use_shell += 1;

	shell_on_field = 1;
	last_fire = clock();

	if(LEFT == orient) //左  x - 51
		shell_infor = Shell(pos_x - 51, pos_y, LEFT, fire_speed);
	else if(RIGHT == orient) // 右  x + 51
		shell_infor = Shell(pos_x + 51, pos_y, RIGHT, fire_speed);
	else if(UP == orient ) //上 y -51
		shell_infor = Shell(pos_x, pos_y - 51, UP, fire_speed);
	else if(DOWN == orient)
		shell_infor = Shell(pos_x, pos_y + 51, DOWN, fire_speed);

	//shell_infor.disprecision = (rand() % ((100 - precision) * 2)) + 1 - (100 - precision);

}
//行数 324行