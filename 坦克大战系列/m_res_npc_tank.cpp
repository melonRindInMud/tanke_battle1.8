#include "stdafx.h"
#include "my_resource.h"
//NPC坦克类
int NPC_Tank::AIM_RANGE =  58 - 2 * DIFFICULTY;   //瞄准临界值  越小越准  但是太小则无法命中  40 最好
int NPC_Tank::CLOSE_RANGE = 146 - 4 * DIFFICULTY;   //  强追踪临界值   越小越难摆脱并且越难风筝但是不容易盯上 越大越容易盯上 但是容易被风筝     
int NPC_Tank::ALERT_RANGE =  280 - 10 * DIFFICULTY;  //  不开炮 不移动 小一点比较好 但不低于90
int NPC_Tank::TRIGGER_RANGE = 2800;  // 触发AI值  越大越难

//初始化函数 -- 因为 NPC坦克参数和种类变化太多 所以 只作为一个 置零函数来使用
NPC_Tank::NPC_Tank()
{
	precision = 93;
	orient = Orient(rand()%4);
	pos_x = rand() % (FIELD_WIDTH - 100) + 51;
	pos_y = rand() % (FIELD_HEIGHT - 100) + 51;
	//orient = UP;

	//控制信息
	fire_command = 0;
	command = Orient(rand()%4);

	penertrate_level = 7;
	ammor_level = 6;
	behind_ammor_level = 0;
	side_ammor_level = 2;

	//状态信息
	is_hit = 0;
//	last_hit = 0;
	t_last_hit = -9900;
	last_hit_orient = FRONT;
	t_last_effect_penertrated = -9900;
	t_last_penertrated = -9900;

	is_engine_damage = 0;
	is_gun_damage = 0;

	//机动信息
	route_interval = 420;
	last_route = -420;
	Max_Speed = 13;
	Current_Speed = 0;
	Accelerate_Power = 3;

	fire_speed = E_FIRE_SPEED;

	//火力信息
	damage = 1600;
	fire_range = 1200;
	fire_interval = 770;
	last_fire = -770;
	shell_on_field = 0;

	//生命信息
	max_hitpoint = 9000;
	restore_per_update = 30;
	current_hitpoint = max_hitpoint;
	current_max_hitpoint = max_hitpoint;
	die_time = - 9999;
	is_explose = 0;

	//识别信息 
	rc = NORMAL;
	strcpy(name, "默认名称NPC");
	is_on_field = 1; 
	protect_index = 0;
	target_index = 0;

	//附加防护信息
	penertrated_detonation_rate = 12;
	effective_penertrated_detonation_rate = 20;
	engine_damage_rate = 100;
	gun_damage_rate = 20;

	//图标
	icon = G_T1;
	gold = 10;
	Vp_range = 800;
	pretend_range = 300;

	//本关表现信息
	dmg_recv = 0;
	kill = 0;
	dmg_cause = 0;
	icon = UK_T1;
	is_engine_damage = 0;
	is_gun_damage = 0;
}

//含有生命值等信息的初始化函数
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

//普通AI 只能随机开炮和移动
void NPC_Tank::Tank_Control_Normal(void)
{
	//移动策略 和 开火策略
	if(STOP == command || Current_Speed == 0)
		command = Orient(rand() % 5);
	fire_command = 1;

	if(Current_Speed >= 0.7 * Max_Speed || Current_Speed == 0)
		command = Orient(rand() % 5);

	if(current_hitpoint) //本体还在
	{
		//恢复
		current_hitpoint += restore_per_update;
		if(current_hitpoint > current_max_hitpoint)
			current_hitpoint = current_max_hitpoint;

		//移动策略 和 开火策略
		Tank_Move();
		//碰撞检测
		Check_Block_By_River();jam_process();
	}

	//检测是否生成新的炮弹
	if(1 == fire_command)
		try_fire();

	//清空开炮信息
	fire_command = 0;
}


//佯攻AI 
void NPC_Tank::Tank_Control_Ambush(int x, int y)
{
	if(current_hitpoint) //本体还在
	{
		//智能模式下还能回血
		current_hitpoint += restore_per_update;
		if(current_hitpoint > current_max_hitpoint)
			current_hitpoint = current_max_hitpoint;


		fire_command = 0;
		//重新靠近智能


		//横坐标
		//远处 -- 逼近

		int dis = abs(x - pos_x) + abs(y - pos_y);
		int dis_x = abs(x - pos_x);
		int dis_y = abs(y - pos_y);


		//重写该逻辑
		//无论目标多远 只要对上了 就开火
		if(abs(pos_x - x) <= AIM_RANGE && abs(pos_y - y) < fire_range) // 横坐标一致 (调整左右)
		{
			fire_command = 1;
			if(pos_y >= y) // 在下面
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
		else if(abs(pos_y - y) <= AIM_RANGE && abs(pos_x - x) < fire_range) //纵坐标一致
		{
			if(pos_x >= x) // 在左面
			{
				fire_command = 0;
				if(orient == LEFT)
				{
					fire_command = 1;
				}
				if(orient == LEFT && abs(pos_x - x) <= pretend_range)
					command = STOP;
				else // 开火特效中
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

		//没对上 再做决定


		else if(dis > Vp_range)
		{
			//移动策略 和 开火策略
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

		//追踪 
		/*
		else if(abs(pos_x - x) <= ALERT_RANGE && abs(pos_x - x) > AIM_RANGE)
		{
			if(pos_x < x ) // 
				command = RIGHT;
			else
				command = LEFT;
		}
		//瞄准 与 发射 -- 在发射的时候 停车
		*/


		//纵坐标
		//远处
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
		//瞄准发射 -- 近距离停车


		

		//移动智能
		else
		{
			fire_command = 1;
			command = orient;
			if(Current_Speed >= 0.9 * Max_Speed || Current_Speed == 0)
				command = Orient(rand() % 5);
		}

		//移动处理和碰撞处理
		Tank_Move();
		Check_Block_By_River();
		jam_process();
	}
	//电脑敌军的修改策略同上



	//检测是否生成新的炮弹
	if(1 == fire_command)
		try_fire();

	//清空开炮信息
	fire_command = 0;
}

//AI 开炮指令处理
void NPC_Tank::try_fire(void)
{
	if(clock() - last_fire <= fire_interval * FIRE_NERF || shell_on_field) //如果 场上还有炮弹或者 炮弹没装好 就不能发射
		return ;


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

	//shell_infor.disprecision = rand() % ((100 - precision) * 2) + 1 - (100 - precision);
}

//普通追踪攻击 策略  
void NPC_Tank::Tank_Control_ELITE(int x, int y)
{
	if(current_hitpoint) //本体还在
	{
		//智能模式下还能回血
		current_hitpoint += restore_per_update;
		if(current_hitpoint > current_max_hitpoint)
			current_hitpoint = current_max_hitpoint;


		fire_command = 0;
		//重新靠近智能


		//横坐标



		if(abs(pos_x - x) <= AIM_RANGE ) // 横坐标一致 (调整左右)
		{
			fire_command = 0;
			if(pos_y >= y) // 在下面
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
		else if(abs(pos_y - y) <= AIM_RANGE) //纵坐标一致
		{
			fire_command = 0;
			if(pos_x >= x) // 在下面
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


		//远处 -- 逼近
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
	//电脑敌军的修改策略同上



	//检测是否生成新的炮弹
	if(1 == fire_command)
		try_fire();
	//清空开炮信息
	fire_command = 0;
}

//防守策略
void NPC_Tank::Tank_Control_VP(int x, int y)
{
	if(current_hitpoint) //本体还在
	{
		//智能模式下还能回血
		current_hitpoint += restore_per_update;
		if(current_hitpoint > current_max_hitpoint)
			current_hitpoint = current_max_hitpoint;


		fire_command = 0;
		//靠近触发智能


		//横坐标
		int dis = abs(x - pos_x) + abs(y - pos_y);
		if(dis > Vp_range)
		{
			//移动策略 和 开火策略
			if(STOP == command || Current_Speed == 0)
				command = Orient(rand() % 5);
			fire_command = 1;

			if(Current_Speed >= 0.7 * Max_Speed || Current_Speed == 0)
				command = Orient(rand() % 5);
		}


		//开火特效

		else if(abs(pos_x - x) <= AIM_RANGE ) // 横坐标一致 (调整左右)
		{
			fire_command = 0;
			if(pos_y >= y) // 在下面
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
		else if(abs(pos_y - y) <= AIM_RANGE) //纵坐标一致
		{
			fire_command = 0;
			if(pos_x >= x) // 在下面
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


		//远处 -- 逼近
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
	//电脑敌军的修改策略同上

	//检测是否生成新的炮弹
	if(1 == fire_command)
		try_fire();

	//清空开炮信息
	fire_command = 0;
}

//炮塔策略 -- 目标选择 依赖仍然是最近的那个
void NPC_Tank::Tank_Control_Turret(int x, int y)
{
	if(current_hitpoint) //本体还在
	{
		//智能模式下还能回血
		current_hitpoint += restore_per_update;
		if(current_hitpoint > current_max_hitpoint)
			current_hitpoint = current_max_hitpoint;


		fire_command = 0;
		//靠近触发智能
		command = STOP;


		//横坐标
		int dis_x = abs(x - pos_x);
		int dis_y = abs(y - pos_y);

		if(abs(pos_x - x) <= AIM_RANGE + 25 ) // 横坐标一致 (调整左右)
		{
			fire_command = 0;
			if(pos_y >= y) // 在下面
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
		else if(abs(pos_y - y) <= AIM_RANGE + 25) //纵坐标一致
		{
			fire_command = 0;
			if(pos_x >= x) // 在下面
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
	//电脑敌军的修改策略同上



	//检测是否生成新的炮弹
	if(1 == fire_command)
		try_fire();

	//清空开炮信息
	fire_command = 0;
}

//保护关键目标的策略
void NPC_Tank::Tank_Control_Protect(int p_x, int p_y, int x, int y)
{
	if(current_hitpoint) //本体还在
	{
		//智能模式下还能回血
		current_hitpoint += restore_per_update;
		if(current_hitpoint > current_max_hitpoint)
			current_hitpoint = current_max_hitpoint;


		fire_command = 0;
		//重新靠近智能


		//横坐标
		//保护 
		if(abs(pos_x - p_x) >= 80)
		{
			if(pos_x > p_x) // 右边 往左走
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

		//开火
		else if(abs(pos_x - x) <= AIM_RANGE ) // 横坐标一致 (调整左右)
		{
			fire_command = 0;
			if(pos_y >= y) // 在下面
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
		else if(abs(pos_y - y) <= AIM_RANGE) //纵坐标一致
		{
			fire_command = 0;
			if(pos_x >= x) // 在下面
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


		//远处 -- 不动
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

	//检测是否生成新的炮弹
	if(1 == fire_command)
		try_fire();

	//清空开炮信息
	fire_command = 0;
}
//行数 1076行