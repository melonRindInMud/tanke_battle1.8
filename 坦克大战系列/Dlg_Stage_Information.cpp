#include "stdafx.h"
#include "坦克大战系列Dlg.h"
#include "my_resource.h"
// 关卡 信息 初始化

extern clock_t last_kill;
extern int kill_stack;

void C坦克大战系列Dlg::stage_init_tank(int stage)
{
	//河流绘制信息
	river_box_number = 0;

	kill_stack = 0;
	last_kill = -9999;


	//存盘效果
	player_at_stage_begin = tank1;
	Player_Tank::use_shell = 0;
	Player_Tank::kill_stack = 0;
	Player_Tank::last_kill = 0;

	stage_begin_time = clock();
	last_allience_send = stage_begin_time;
	last_enemy_send = stage_begin_time;
	allience_is_send = 0;
	h = 1;
	a_h = 1;

	view_orient = STOP;
	last_view_orient = STOP;


	Player_Tank::energy = 100;
	gun_up_to = 0;
	instruct = 0;

	if(current_stage != 11)
		strcpy(tank1.name, "奥托 卡尔乌斯");
	else
		strcpy(tank1.name, "阿尔伯特 科舍尔");
	tank1.dmg_cause = 0;
	tank1.dmg_recv = 0;
	tank1.kill = 0;

	tank1.is_engine_damage = 0;
	tank1.is_gun_damage = 0;
	tank1.t_last_fital_hit = -99999;
	tank1.t_last_gun_hit = -99999;
	tank1.t_last_effect_hit = -99999;


	//玩家表现信息清零

	//关卡名称：
	
	if(current_stage == 1)
	{
		stage_name = "I 新兵        ";
	}
	else if(current_stage == 2)
	{
		stage_name = "II生存训练    ";
	}
	else if(current_stage == 3)
	{
		stage_name = "III团队战训练  ";
	}
	else if(current_stage == 4)
	{
		stage_name = "IV秋风扫落叶  ";
	}
	else if(current_stage == 5)
	{
		stage_name = "V负隅顽抗   ";
	}
	else if(current_stage == 6)
	{
		stage_name = "VI进攻华石   ";
	}
	else if(current_stage == 7)
	{
		stage_name = "VII遭遇巨熊   ";
	}
	else if(current_stage == 8)
	{
		stage_name = "VIII风驰电掣   ";
	}
	else if(current_stage == 9)
	{
		stage_name = "IX进攻塞尔布鲁";
	}
	else if(current_stage == 10)
	{
		stage_name = "X万里长城战役";
	}
	else if(current_stage == 11)
	{
		stage_name = "XI大撤退城防守";
	}
	else if(current_stage == 12)
	{ 
		stage_name = "XII阅兵        ";
	}
	else if(current_stage == 13)
	{
		stage_name = "XIII攻其不备   ";
	}
	else if(current_stage == 14)
	{
		stage_name = "XIV遭遇强敌   ";
	}
	else if(current_stage == 15)
	{
		stage_name = "XV大会战      ";
	}
	else if(current_stage == 16)
	{
		stage_name = "XVI单车闯关    ";
	}
	else if(current_stage == -1)
	{
		stage_name = "隐藏一关惧之魇";
	}
	else if(current_stage == 100)
	{
		stage_name = "P I INREMINDANCE";
	}
	else if(current_stage == 101)
	{
		stage_name = "P II BAGRATION ATTACK";
	}
	




	//每关开始都会恢复2/3的最大生命值 最大生命上限 -- 前三关回满
	int add = 0;
	if(stage <= 3)
		add = tank1.max_hitpoint;
	else 
		add = tank1.max_hitpoint * 2 / 3;
	tank1.current_max_hitpoint += add;
	if(tank1.current_max_hitpoint > tank1.max_hitpoint)
		tank1.current_max_hitpoint = tank1.max_hitpoint;

	tank1.current_hitpoint += add;
	if(tank1.current_hitpoint > tank1.current_max_hitpoint)
		tank1.current_hitpoint = tank1.current_max_hitpoint;

	//清空受损
	tank1.t_last_gun_hit = -4000;
	tank1.t_last_fital_hit = -4000;
	tank1.shell_on_field = 0;




	if(stage == -1)
	{
		c_v_t = V_STD;
		c_d_t = D_STD;
		//d_addtion_param = 20;
		NUM_OF_ALLIENCE = 0;
		NUM_OF_ENEMY = 18;
		//敌军初始化
		for(int i = 0; i < NUM_OF_ENEMY; i++)
		{
			enemy_tanks[i] = NPC_Tank();
			enemy_tanks[i].max_hitpoint = 630;
			enemy_tanks[i].current_max_hitpoint = 630;
			enemy_tanks[i].current_hitpoint = 630;
			enemy_tanks[i].damage = 640;
			enemy_tanks[i].fire_interval = 900;
			enemy_tanks[i].fire_speed = 133;
			enemy_tanks[i].gold= 3;
			enemy_tanks[i].rc = VP;
			enemy_tanks[i].Vp_range = 3000;
			strcpy(enemy_tanks[i].name, "");
			enemy_tanks[i].Max_Speed = 22;
			enemy_tanks[i].Accelerate_Power = 12;
			enemy_tanks[i].is_on_field = 0;
			enemy_tanks[i].ammor_level = 1;

		}
		//友军初始化
		tank1.pos_x = 1500;
		tank1.pos_y = 1000;
		tank1.orient = UP;
	}
	else if(stage == -2)
	{
		c_v_t = V_STD;
		c_d_t = D_STD;
		//d_addtion_param = 20;
		NUM_OF_ALLIENCE = 0;
		NUM_OF_ENEMY = 18;

	}

	else if(stage == 1)
	{
		tank1 = Player_Tank();
		c_v_t = V_STD;
		c_d_t = D_NSH;
		d_addtion_param = 20;
		NUM_OF_ALLIENCE = 0;
		NUM_OF_ENEMY = 8;
		//敌军初始化
		for(int i = 0; i < NUM_OF_ENEMY; i++)
		{
			enemy_tanks[i] = NPC_Tank();
			if(i == 0)
			{
				enemy_tanks[i].pos_x = 300;
				enemy_tanks[i].pos_y = 300;
			}
			else if(i == 1)
			{
				enemy_tanks[i].pos_x = 2700;
				enemy_tanks[i].pos_y = 300;
			}
			else if(i == 2)
			{
				enemy_tanks[i].pos_x = 2700;
				enemy_tanks[i].pos_y = 1700;
			}
			else if(i == 3)
			{
				enemy_tanks[i].pos_x = 300;
				enemy_tanks[i].pos_y = 1700;
			}

			else if(i == 4)
			{
				enemy_tanks[i].pos_x = 300;
				enemy_tanks[i].pos_y = 1000;
			}
			else if(i == 5)
			{
				enemy_tanks[i].pos_x = 1500;
				enemy_tanks[i].pos_y = 300;
			}
			else if(i == 6)
			{
				enemy_tanks[i].pos_x = 2700;
				enemy_tanks[i].pos_y = 1000;
			}
			else if(i == 7)
			{
				enemy_tanks[i].pos_x = 1500;
				enemy_tanks[i].pos_y = 1700;
			}



			enemy_tanks[i].orient = DOWN;
			enemy_tanks[i].max_hitpoint = 4000;
			enemy_tanks[i].current_max_hitpoint = 4000;
			enemy_tanks[i].current_hitpoint = 4000;
			enemy_tanks[i].damage = 0;
			enemy_tanks[i].gold= 3;
			enemy_tanks[i].rc = NOOB;
			strcpy(enemy_tanks[i].name, "靶子");

		}
		//友军初始化
		tank1.pos_x = 1500;
		tank1.pos_y = 1000;
		tank1.orient = UP;

	}
	else if(stage == 2)
	{
		c_v_t = V_TLE;
#ifdef SPEED_DOWN
		v_addtion_param = 75000 * (FIRE_NERF / 2.0) + clock();
		v_addtion_time = 75000 * (FIRE_NERF / 2.0);
#else
		v_addtion_param = 70000 + clock();
		v_addtion_time = 70000;
#endif

		c_d_t = D_STD;
		NUM_OF_ALLIENCE = 0;

		if(Player_Tank::difficulty == 2)
			NUM_OF_ENEMY = 16;
		else
			NUM_OF_ENEMY = 24;
		//敌军初始化
		for(int i = 0; i < NUM_OF_ENEMY; i++)
		{
			enemy_tanks[i] = NPC_Tank();
			enemy_tanks[i].icon = G_T1;
			if(i % 8 == 0)
			{
				enemy_tanks[i].pos_x = 500;
				enemy_tanks[i].pos_y = 500;
			}
			else if(i % 8 == 1)
			{
				enemy_tanks[i].pos_x = 2500;
				enemy_tanks[i].pos_y = 500;
			}
			else if(i % 8 == 2)
			{
				enemy_tanks[i].pos_x = 2500;
				enemy_tanks[i].pos_y = 1500;
			}
			else if(i % 8 == 3)
			{
				enemy_tanks[i].pos_x = 500;
				enemy_tanks[i].pos_y = 1500;
			}
			else if(i % 8 == 4)
			{
				enemy_tanks[i].pos_x = 500;
				enemy_tanks[i].pos_y = 1000;
			}
			else if(i % 8 == 5)
			{
				enemy_tanks[i].pos_x = 1500;
				enemy_tanks[i].pos_y = 500;
			}
			else if(i % 8 == 6)
			{
				enemy_tanks[i].pos_x = 2500;
				enemy_tanks[i].pos_y = 1000;
			}
			else if(i % 8 == 7)
			{
				enemy_tanks[i].pos_x = 1500;
				enemy_tanks[i].pos_y = 1500;
			}



			enemy_tanks[i].orient = DOWN;
			enemy_tanks[i].max_hitpoint = 2500;
			enemy_tanks[i].current_max_hitpoint = 2500;
			enemy_tanks[i].current_hitpoint = 2500;
			enemy_tanks[i].damage = 500;
			enemy_tanks[i].gold = 4;
			if(Player_Tank::difficulty == 2)
			{
				enemy_tanks[i].rc = PROTEND;
				enemy_tanks[i].Vp_range = 5000;
				enemy_tanks[i].pretend_range = 1200;
			}
			else
				enemy_tanks[i].rc = NORMAL;
			strcpy(enemy_tanks[i].name, "帝国装甲军新兵");

		}
		//友军初始化
		tank1.pos_x = 1500;
		tank1.pos_y = 1000;
		tank1.orient = UP;

	}
	else if(stage == 3)
	{
		c_v_t = V_STD;
		c_d_t = D_STD;
		NUM_OF_ALLIENCE = 8;
		NUM_OF_ENEMY = 9;



		//敌军初始化
		for(int i = 0; i < NUM_OF_ENEMY; i++)
		{
			enemy_tanks[i] = NPC_Tank();
			enemy_tanks[i].icon = G_T1;
			enemy_tanks[i].fire_interval = 1350;
			if(i < 3)
			{
				enemy_tanks[i].Vp_range = 3000;
				enemy_tanks[i].orient = LEFT;
				enemy_tanks[i].max_hitpoint = 5300;
				enemy_tanks[i].current_max_hitpoint = 5300;
				enemy_tanks[i].current_hitpoint = 5300;
				enemy_tanks[i].damage = 770;
				enemy_tanks[i].gold = 4;
				//精英需要初始化target
				enemy_tanks[i].rc = VP;
				

				enemy_tanks[i].penertrated_detonation_rate = 0;
				enemy_tanks[i].effective_penertrated_detonation_rate = 0;
				enemy_tanks[i].engine_damage_rate = 28;
				enemy_tanks[i].gun_damage_rate = 4;
				enemy_tanks[i].fire_speed = 180;
			}
			else 
			{
				enemy_tanks[i].Vp_range = 3000;
				enemy_tanks[i].orient = LEFT;
				enemy_tanks[i].max_hitpoint = 4600;
				enemy_tanks[i].current_max_hitpoint = 4600;
				enemy_tanks[i].current_hitpoint = 4600;
				enemy_tanks[i].damage = 880;
				enemy_tanks[i].gold = 4;

				enemy_tanks[i].rc = PROTEND;
				//enemy_tanks[i].target_index = rand()%(NUM_OF_ALLIENCE + 1) - 1;


				enemy_tanks[i].penertrated_detonation_rate = 0;
				enemy_tanks[i].effective_penertrated_detonation_rate = 0;
				enemy_tanks[i].engine_damage_rate = 28;
				enemy_tanks[i].gun_damage_rate = 4;
				enemy_tanks[i].fire_speed = 180;

			}
			if(i == 0)
			{
				strcpy(enemy_tanks[i].name, "恩斯特 巴克曼");
				enemy_tanks[i].pos_x = 2200;
				enemy_tanks[i].pos_y = 750 + rand()%100;
			}
			else if(i == 1)
			{
				strcpy(enemy_tanks[i].name, "米歇尔 魏特曼");
				enemy_tanks[i].pos_x = 2200;
				enemy_tanks[i].pos_y = 850 + rand()%100;
			}
			else if(i == 2) 
			{
				strcpy(enemy_tanks[i].name, "约翰尼斯 鲍尔特");
				enemy_tanks[i].pos_x = 2200;
				enemy_tanks[i].pos_y = 1150 + rand()%100;
			}
			else
			{
				strcpy(enemy_tanks[i].name, "头铁的精英");
				enemy_tanks[i].pos_x = 2100 - 100 * ((i-3)/ 3);
				enemy_tanks[i].pos_y = 1200 - 200 * (i % 3);
			}
	


		}
		for(int i = 0; i < NUM_OF_ALLIENCE; i++)
		{
			allience_tanks[i] = NPC_Tank();
			allience_tanks[i].icon = G_T1;
			allience_tanks[i].fire_interval = 1350;

			if(i < 2)
			{
				allience_tanks[i].Vp_range = 3000;
				allience_tanks[i].orient = RIGHT;
				allience_tanks[i].max_hitpoint = 4500;
				allience_tanks[i].current_max_hitpoint = 4500;
				allience_tanks[i].current_hitpoint = 4500;
				allience_tanks[i].damage = 700;
				allience_tanks[i].gold = 4;
				allience_tanks[i].rc = VP;
				allience_tanks[i].penertrated_detonation_rate = 0;
				allience_tanks[i].effective_penertrated_detonation_rate = 0;
				allience_tanks[i].engine_damage_rate = 28;
				allience_tanks[i].gun_damage_rate = 4;
				allience_tanks[i].fire_speed = 180;
			}
			else 
			{
				allience_tanks[i].Vp_range = 3000;
				allience_tanks[i].orient = RIGHT;
				allience_tanks[i].max_hitpoint = 3800;
				allience_tanks[i].current_max_hitpoint = 3800;
				allience_tanks[i].current_hitpoint = 3800;
				allience_tanks[i].damage = 830;
				allience_tanks[i].gold = 4;

				allience_tanks[i].rc = PROTEND;
				//allience_tanks[i].target_index = rand()%NUM_OF_ENEMY;

				allience_tanks[i].penertrated_detonation_rate = 0;
				allience_tanks[i].effective_penertrated_detonation_rate = 0;
				allience_tanks[i].engine_damage_rate = 28;
				allience_tanks[i].gun_damage_rate = 4;
				allience_tanks[i].fire_speed = 180;
			}
			if(i == 0)
			{
				strcpy(allience_tanks[i].name, "阿尔伯特 科舍尔");
				allience_tanks[i].pos_x = 800;
				allience_tanks[i].pos_y = 850 + rand()%100;
			}
			else if(i == 1)
			{
				strcpy(allience_tanks[i].name, "博尔特（重名的很多）");
				allience_tanks[i].pos_x = 900;
				allience_tanks[i].pos_y = 1000;
			}
			else
			{
				strcpy(allience_tanks[i].name, "头铁的精英");
				allience_tanks[i].pos_x = 900 + 100 * ((i-2)/ 3);
				allience_tanks[i].pos_y = 1200 - 200 * ((i-2) % 3);
			}

		}
		//友军初始化
		tank1.pos_x = 1100;
		tank1.pos_y = 1400;
		tank1.orient = DOWN;

	}
	else if(stage == 4)
	{
		c_v_t = V_STD;
		c_d_t = D_DLD;
		d_addtion_param = 30000;


		NUM_OF_ALLIENCE = 3;
		NUM_OF_ENEMY = 72;
		//敌军初始化
		for(int i = 0; i < NUM_OF_ENEMY; i++)
		{
			enemy_tanks[i] = NPC_Tank();
			//enemy_tanks[i].icon = USSR_T1;
			if(i < 9)
			{
				enemy_tanks[i].pos_x = 1900 + 200 * (i % 3);
				enemy_tanks[i].pos_y = 150 + 200 * (i / 3);
				enemy_tanks[i].orient = DOWN;
			}
			else if(i < 18)
			{
				enemy_tanks[i].pos_x = 150 + 200 * (i % 3);
				enemy_tanks[i].pos_y = 150 + 200 * ((i-9) / 3);
				enemy_tanks[i].orient = DOWN;
			}
			else if(i < 27)
			{
				enemy_tanks[i].pos_x = 1900 + 200 * (i % 3);
				enemy_tanks[i].pos_y = 1300 + 200 * (i-18) / 3;
				enemy_tanks[i].orient = DOWN;
			}
			else if(i < 36)
			{
				enemy_tanks[i].pos_x = 150 + 200 * (i % 3);
				enemy_tanks[i].pos_y = 1300 + 200 * (i-27) / 3;
				enemy_tanks[i].orient = DOWN;
			}
			else
			{
				enemy_tanks[i].pos_x = 50 + rand()% 2900;
				enemy_tanks[i].pos_y = 50 + rand()% 1900;

			}



			enemy_tanks[i].max_hitpoint = 2700;
			enemy_tanks[i].current_max_hitpoint = 2700;
			enemy_tanks[i].current_hitpoint = 2700;
			enemy_tanks[i].damage = 600;
			enemy_tanks[i].gold = 3;
			enemy_tanks[i].rc = NORMAL;
			enemy_tanks[i].penertrated_detonation_rate = 80;
			enemy_tanks[i].effective_penertrated_detonation_rate = 100;

			strcpy(enemy_tanks[i].name, "乌合之众(敌军)");
		}
		//友军初始化
		tank1.pos_x = 1500;
		tank1.pos_y = 1500;
		tank1.orient = UP;
		for(int i = 0; i < NUM_OF_ALLIENCE; i++)
		{
			allience_tanks[i] = NPC_Tank();
			allience_tanks[i].icon = G_T1;
			allience_tanks[i].pos_x = 2500 - 100 * i;
			allience_tanks[i].pos_y = 1800;
			allience_tanks[i].orient = UP;

			allience_tanks[i].max_hitpoint = 15900;
			allience_tanks[i].current_max_hitpoint = 15900;
			allience_tanks[i].current_hitpoint = 15900;
			allience_tanks[i].damage = 1800;

			allience_tanks[i].Max_Speed = 35;
			allience_tanks[i].fire_interval = 450;
			enemy_tanks[i].fire_speed = 190;
			allience_tanks[i].rc = ELITE;
			allience_tanks[i].target_index = rand()%NUM_OF_ENEMY;

			//附加防护参数调整
			allience_tanks[i].penertrated_detonation_rate = 0;
			allience_tanks[i].effective_penertrated_detonation_rate = 0;
			allience_tanks[i].engine_damage_rate = 0;
			allience_tanks[i].gun_damage_rate = 0;

			strcpy(allience_tanks[i].name, "暴走的老鸽");
		}
	}
	else if(stage == 5)
	{
		c_v_t = V_STD;
		c_d_t = D_STD;

		NUM_OF_ALLIENCE = 16;
		NUM_OF_ENEMY = 36;
		//敌军初始化
		for(int i = 0; i < NUM_OF_ENEMY; i++)
		{
			enemy_tanks[i] = NPC_Tank();

			strcpy(enemy_tanks[i].name, "有经验的敌军");
            if((i % 9) < 1)
			{
				if(Player_Tank::difficulty == 2)
				{
					strcpy(enemy_tanks[i].name, "小麻烦");
					enemy_tanks[i].rc = PROTEND;
					enemy_tanks[i].pretend_range = 255;
					enemy_tanks[i].Vp_range = 4000;
					enemy_tanks[i].Max_Speed = 16;

				}
				else
				{
					strcpy(enemy_tanks[i].name, "看手机的敌军");
					enemy_tanks[i].rc = NOOB;
				}
				enemy_tanks[i].max_hitpoint = 7800;
				enemy_tanks[i].current_max_hitpoint = 7800;
				enemy_tanks[i].current_hitpoint = 7800;
	

			}
			else if((i % 9) < 3)
			{
				strcpy(enemy_tanks[i].name, "幸存的新兵");
				if(Player_Tank::difficulty == 2)
				{
					enemy_tanks[i].rc = VP;
					enemy_tanks[i].Vp_range = 4000;
				}
				else
					enemy_tanks[i].rc = NORMAL;
				enemy_tanks[i].max_hitpoint = 3800;
				enemy_tanks[i].current_max_hitpoint = 3800;
				enemy_tanks[i].current_hitpoint = 3800;

			}
			else if( (i % 9) <= 5)
			{
				enemy_tanks[i].max_hitpoint = 4600;
				enemy_tanks[i].current_max_hitpoint = 4600;
				enemy_tanks[i].current_hitpoint = 4600;
				enemy_tanks[i].rc = VP;
				enemy_tanks[i].Vp_range = 4000;
			}
			else
			{
				enemy_tanks[i].rc = ELITE;
				enemy_tanks[i].target_index = (i % 9) - 7;
				enemy_tanks[i].Max_Speed = 24;
				enemy_tanks[i].max_hitpoint = 4600;
				enemy_tanks[i].current_max_hitpoint = 4600;
				enemy_tanks[i].current_hitpoint = 4600;

				strcpy(enemy_tanks[i].name, "激进的敌军");
			}
			if(i < 9)
			{
				enemy_tanks[i].pos_x = 150 + 200 * (i % 3);
				enemy_tanks[i].pos_y = 150 + 200 * (i / 3);
				enemy_tanks[i].orient = DOWN;
			}
			else if(i < 18)
			{
				enemy_tanks[i].pos_x = 150 + 200 * (i % 3);
				enemy_tanks[i].pos_y = 1850 - 200 * ((i-9) / 3);
				enemy_tanks[i].orient = UP;
			}
			else if(i < 27)
			{
				enemy_tanks[i].pos_x = 2850 - 200 * (i % 3);
				enemy_tanks[i].pos_y = 150 + 200 * (i-18) / 3;
				enemy_tanks[i].orient = LEFT;
			}
			else
			{
				enemy_tanks[i].pos_x = 2850 - 200 * (i % 3);
				enemy_tanks[i].pos_y = 1850 - 200 * (i-27) / 3;
				enemy_tanks[i].orient = RIGHT;
			}

			//敌军穿深补正 
			if(Player_Tank::difficulty == 2)
			{
				enemy_tanks[i].penertrate_level += 2;
			}
			if(Player_Tank::difficulty == 1)
			{
				enemy_tanks[i].penertrate_level += 1;
			}



			enemy_tanks[i].damage = 740;
			enemy_tanks[i].gold = 6;

			
		}
		//友军初始化
		tank1.pos_x = 1700;
		tank1.pos_y = 1000;
		tank1.orient = UP;

		for(int i = 0; i < NUM_OF_ALLIENCE; i++)
		{
			allience_tanks[i] = NPC_Tank();
			allience_tanks[i].icon = G_T1;
			allience_tanks[i].pos_x = 1800 - rand()% 200;
			allience_tanks[i].pos_y = 1100 - rand()% 200;
			allience_tanks[i].orient = UP;

			allience_tanks[i].max_hitpoint = 4200;
			allience_tanks[i].current_max_hitpoint = 4200;
			allience_tanks[i].current_hitpoint = 4200;
			allience_tanks[i].damage = 880;

			allience_tanks[i].Max_Speed = 22;
			allience_tanks[i].rc = PROTEND;
			allience_tanks[i].Vp_range = 5000;
			allience_tanks[i].pretend_range = 180;
			allience_tanks[i].target_index = rand() % NUM_OF_ENEMY;

			//附加防护参数调整
			allience_tanks[i].penertrated_detonation_rate = 5;
			allience_tanks[i].effective_penertrated_detonation_rate = 10;
			allience_tanks[i].engine_damage_rate = 50;
			allience_tanks[i].gun_damage_rate = 5;

			strcpy(allience_tanks[i].name, "友军精英");
			allience_tanks[i].penertrated_detonation_rate = 0;
			allience_tanks[i].effective_penertrated_detonation_rate = 0;
			allience_tanks[i].engine_damage_rate = 0;
			allience_tanks[i].gun_damage_rate = 0;

			allience_tanks[i].penertrate_level += 1;
		}
	}
	else if(stage == 6)
	{
		c_v_t = V_KVP;
		c_d_t = D_STD;
		NUM_OF_ALLIENCE = 16;
		NUM_OF_ENEMY = 36;
		//敌军初始化
		for(int i = 0; i < NUM_OF_ENEMY; i++)
		{
			enemy_tanks[i] = NPC_Tank();

			if(i == 0) //关键目标
			{
				enemy_tanks[i].max_hitpoint = 600000;
				enemy_tanks[i].current_max_hitpoint = 600000;
				enemy_tanks[i].current_hitpoint = 600000;

			//炮塔必备三联
				enemy_tanks[i].icon = Turret;
				enemy_tanks[i].Max_Speed = 0;
				enemy_tanks[i].rc = TURRET;

				strcpy(enemy_tanks[i].name, "华石城防核心炮塔");
				enemy_tanks[i].damage = 2100;
				enemy_tanks[i].fire_interval = 600;
				enemy_tanks[i].fire_speed = 230;

				//穿深加成
				enemy_tanks[i].penertrate_level = 18;
				enemy_tanks[i].ammor_level = 7;
				enemy_tanks[i].side_ammor_level = 4;
				enemy_tanks[i].behind_ammor_level = 2;


				//附加项
				enemy_tanks[i].penertrated_detonation_rate = 30;
				enemy_tanks[i].effective_penertrated_detonation_rate = 70;
				enemy_tanks[i].gun_damage_rate = 5;

				enemy_tanks[i].pos_x = 1500;
				enemy_tanks[i].pos_y = 1000;
				enemy_tanks[i].gold = 25;
			}
			else if(i < 9) //城防炮塔
			{
				enemy_tanks[i].gold = 33;
				enemy_tanks[i].max_hitpoint = 300000;
				enemy_tanks[i].current_max_hitpoint = 300000;
				enemy_tanks[i].current_hitpoint = 300000;

			//炮塔必备三联
				enemy_tanks[i].icon = Turret;
				enemy_tanks[i].Max_Speed = 0;
				enemy_tanks[i].rc = TURRET;

				enemy_tanks[i].penertrate_level = 18;
				enemy_tanks[i].ammor_level = 10;
				enemy_tanks[i].side_ammor_level = 4;
				enemy_tanks[i].behind_ammor_level = 2;


				strcpy(enemy_tanks[i].name, "华石城防炮塔");
				enemy_tanks[i].damage = 1300;
				enemy_tanks[i].fire_interval = 1800;
				enemy_tanks[i].fire_speed = 180;

				//附加项
				enemy_tanks[i].penertrated_detonation_rate = 25;
				enemy_tanks[i].effective_penertrated_detonation_rate = 40;
				enemy_tanks[i].gun_damage_rate = 10;

				if(i == 1)
				{
					enemy_tanks[i].pos_x = 1200;
					enemy_tanks[i].pos_y = 700;
				}
				else if(i == 2)
				{
					enemy_tanks[i].pos_x = 1800;
					enemy_tanks[i].pos_y = 700;
				}
				else if(i == 3)
				{
					enemy_tanks[i].pos_x = 1200;
					enemy_tanks[i].pos_y = 1300;
				}
				else if(i == 4)
				{
					enemy_tanks[i].pos_x = 1800;
					enemy_tanks[i].pos_y = 1300;
				}
				else if(i == 5)
				{
					enemy_tanks[i].pos_x = 1800;
					enemy_tanks[i].pos_y = 1000;
				}
				else if(i == 6)
				{
					enemy_tanks[i].pos_x = 1200;
					enemy_tanks[i].pos_y = 1000;
				}
				else if(i == 7)
				{
					enemy_tanks[i].pos_x = 1500;
					enemy_tanks[i].pos_y = 700;
				}
				else if(i == 8)
				{
					enemy_tanks[i].pos_x = 1500;
					enemy_tanks[i].pos_y = 1300;
				}
				
			}

			//敌军精英 数量 7
			else if(i < 18)
			{
				enemy_tanks[i].fire_interval = 1000;
				enemy_tanks[i].Max_Speed = 22;
				enemy_tanks[i].max_hitpoint = 6500;
				enemy_tanks[i].current_max_hitpoint = 6500;
				enemy_tanks[i].current_hitpoint = 6500;
				enemy_tanks[i].rc = PROTEND;
				enemy_tanks[i].Vp_range = 3000;
				enemy_tanks[i].pretend_range = 500;
				enemy_tanks[i].damage = 820;
				strcpy(enemy_tanks[i].name, "华石城防军精英");
				enemy_tanks[i].pos_x = 1700 + rand()%200;
				enemy_tanks[i].pos_y = 900 + rand()%200;
				enemy_tanks[i].gold = 10;
				enemy_tanks[i].penertrate_level += 2;
			}
			else if(i < 35)
			{
				enemy_tanks[i].fire_interval = 1000;
				enemy_tanks[i].Max_Speed = 16;
				enemy_tanks[i].max_hitpoint = 5400;
				enemy_tanks[i].current_max_hitpoint = 5400;
				enemy_tanks[i].current_hitpoint = 5400;
				if(2 == Player_Tank::difficulty)
				{
					enemy_tanks[i].rc = PROTEND;
					enemy_tanks[i].pretend_range = 500;		
				}
				else
					enemy_tanks[i].rc = NORMAL;
				enemy_tanks[i].damage = 785;
				strcpy(enemy_tanks[i].name, "华石普通城防军");
				enemy_tanks[i].pos_x = 1100 + rand()%900;
				enemy_tanks[i].pos_y = 500 + rand()%1000;
				enemy_tanks[i].gold = 7;
				enemy_tanks[i].penertrate_level += 1;
			}
			else if(i == 35)
			{
				enemy_tanks[i].fire_interval = 1000;
				strcpy(enemy_tanks[i].name, "希米格维（BOSS）");
				enemy_tanks[i].Max_Speed = 14;
				enemy_tanks[i].max_hitpoint = 33333;
				enemy_tanks[i].current_max_hitpoint = 33333;
				enemy_tanks[i].current_hitpoint = 33333;
				enemy_tanks[i].rc = PROTEND;
				enemy_tanks[i].pretend_range = 100;
				enemy_tanks[i].damage = 2333;
				enemy_tanks[i].fire_interval = 1400;
				enemy_tanks[i].fire_speed = 210;
				enemy_tanks[i].pos_x = 1420;
				enemy_tanks[i].pos_y = 920;
				enemy_tanks[i].gold = 7;
				enemy_tanks[i].engine_damage_rate = 0;
				enemy_tanks[i].penertrated_detonation_rate = 0;
				enemy_tanks[i].effective_penertrated_detonation_rate = 0;
				enemy_tanks[i].gun_damage_rate = 0;
				enemy_tanks[i].gold = 40;
				enemy_tanks[i].penertrate_level += 3;

			}
		}
		//友军初始化
		tank1.pos_x = 200;
		tank1.pos_y = 200;
		tank1.orient = DOWN;

		for(int i = 0; i < NUM_OF_ALLIENCE; i++)
		{
			allience_tanks[i] = NPC_Tank();
			allience_tanks[i].icon = G_T1;
			allience_tanks[i].restore_per_update = 55;
			allience_tanks[i].pretend_range = 200;
			allience_tanks[i].Vp_range = 1500;
			
			allience_tanks[i].fire_interval = 1500;
			allience_tanks[i].last_fire = -1500;
			if(i % 4 == 0)
			{
				if(2 == Player_Tank::difficulty)
				{
					allience_tanks[i].max_hitpoint = 21000;
					allience_tanks[i].current_max_hitpoint = 21000;
					allience_tanks[i].current_hitpoint = 21000;
				}
				else if(1 == Player_Tank::difficulty)
				{
					allience_tanks[i].max_hitpoint = 23000;
					allience_tanks[i].current_max_hitpoint = 23000;
					allience_tanks[i].current_hitpoint = 23000;
				}
				else
				{
					allience_tanks[i].max_hitpoint = 26000;
					allience_tanks[i].current_max_hitpoint = 26000;
					allience_tanks[i].current_hitpoint = 26000;
				}
				allience_tanks[i].damage = 1700;

				allience_tanks[i].Max_Speed = 21;
				allience_tanks[i].rc = PROTEND;

				allience_tanks[i].target_index = rand() % NUM_OF_ENEMY;

				//附加防护参数调整
				allience_tanks[i].penertrated_detonation_rate = 0;
				allience_tanks[i].effective_penertrated_detonation_rate = 0;


				allience_tanks[i].penertrate_level += 2;
				allience_tanks[i].engine_damage_rate = 20;
				allience_tanks[i].gun_damage_rate = 0;
				strcpy(allience_tanks[i].name, "天朝城管精英");
			}
			else
			{
				if(2 == Player_Tank::difficulty)
				{
					allience_tanks[i].max_hitpoint = 14800;
					allience_tanks[i].current_max_hitpoint = 14800;
					allience_tanks[i].current_hitpoint = 14800;
				}

				else if(1 == Player_Tank::difficulty)
				{
					allience_tanks[i].max_hitpoint = 16500;
					allience_tanks[i].current_max_hitpoint = 16500;
					allience_tanks[i].current_hitpoint = 16500;
				}
				else
				{
					allience_tanks[i].max_hitpoint = 19500;
					allience_tanks[i].current_max_hitpoint = 19500;
					allience_tanks[i].current_hitpoint = 19500;
				}
				allience_tanks[i].damage = 1450;

				allience_tanks[i].Max_Speed = 18;
				allience_tanks[i].rc = PROTEND;
				allience_tanks[i].pretend_range = 200;
				allience_tanks[i].target_index = rand() % NUM_OF_ENEMY;

				//附加防护参数调整
				allience_tanks[i].penertrated_detonation_rate = 0;
				allience_tanks[i].effective_penertrated_detonation_rate = 0;

				allience_tanks[i].penertrate_level += 1;
				allience_tanks[i].engine_damage_rate = 28;
				allience_tanks[i].gun_damage_rate = 4;
				strcpy(allience_tanks[i].name, "天朝城管");
			}
			//位置设定
			if(i < 4)
			{
				allience_tanks[i].pos_x = 200 + rand()%200;
				allience_tanks[i].pos_y = 200 + rand()%200;
			}
			else if(i < 8)
			{
				allience_tanks[i].pos_x = 2800 - rand()%200;
				allience_tanks[i].pos_y = 1800 - rand()%200;
			}
			else if(i < 12)
			{
				allience_tanks[i].pos_x = 200 + rand()%200;
				allience_tanks[i].pos_y = 1800 - rand()%200;
			}
			else
			{
				allience_tanks[i].pos_x = 2800 - rand()%200;
				allience_tanks[i].pos_y = 200 + rand()%200;
			}
		}

	}
	else if(stage == 7)  // 第七关 
	{
		c_v_t = V_STD;
		c_d_t = D_STD;
		NUM_OF_ALLIENCE = 50;
		NUM_OF_ENEMY = 30;

		//一共30 名敌军 55 名友军
		// 每隔15秒 或 场上没人的时候 派遣2个敌军 共10个
		// 前十个全部死亡后 后20个一口气冲出来
		// 友军在玩家击杀10人后 全部涌现而出

		for(int i = 0; i < NUM_OF_ENEMY; i++)
		{
			enemy_tanks[i] = NPC_Tank();
			enemy_tanks[i].icon = USSR_T1;
			enemy_tanks[i].rc = VP;
			enemy_tanks[i].Vp_range = 3500;
			enemy_tanks[i].Max_Speed = 10;
			enemy_tanks[i].fire_speed = 94;
			enemy_tanks[i].damage = 1700;
			enemy_tanks[i].fire_interval = 1200;

			enemy_tanks[i].max_hitpoint = 6900;
			enemy_tanks[i].current_max_hitpoint = 6900;
			enemy_tanks[i].current_hitpoint = 6900;

			enemy_tanks[i].gun_damage_rate = 14;
			enemy_tanks[i].penertrated_detonation_rate = 8;
			enemy_tanks[i].effective_penertrated_detonation_rate = 40;
			enemy_tanks[i].restore_per_update = 10;
			enemy_tanks[i].route_interval = 800;
			enemy_tanks[i].last_route = -800;
			//提高穿深
			// 7 6  2 0
			enemy_tanks[i].penertrate_level += 5;


			strcpy(enemy_tanks[i].name, "巨熊精英");
			//埋伏
			if(i == 0)
				enemy_tanks[i].is_on_field = 1;
			else
				enemy_tanks[i].is_on_field = 0;
			
			//位置
			if(i < 10)
			{
				enemy_tanks[i].pos_x = 2000;
				enemy_tanks[i].pos_y = 300 + i * 100;
			}
			else
			{
				enemy_tanks[i].pos_x = 1200 + rand()%800;
				enemy_tanks[i].pos_y = 700 + rand()%800;
			}
		}
		tank1.pos_x = 1000;
		tank1.pos_y = 350;
		//友方
		// 10 + 40
		for(int i = 0; i < NUM_OF_ALLIENCE; i++)
		{
			allience_tanks[i] = NPC_Tank();
			allience_tanks[i].icon = G_T1;
			allience_tanks[i].rc = VP;
			allience_tanks[i].Vp_range = 3500;
			allience_tanks[i].Max_Speed = 30;
			allience_tanks[i].fire_speed = 135;
			allience_tanks[i].damage = 960;
			allience_tanks[i].fire_interval = 1000;
			allience_tanks[i].max_hitpoint = 4800;
			allience_tanks[i].current_max_hitpoint = 4800;
			allience_tanks[i].current_hitpoint = 4800;
			allience_tanks[i].gun_damage_rate = 0;
			allience_tanks[i].penertrated_detonation_rate = 15;
			allience_tanks[i].effective_penertrated_detonation_rate = 30;
			allience_tanks[i].restore_per_update = 5;
			allience_tanks[i].is_on_field = 0;

			
			if(i < 10)
			{
				strcpy(allience_tanks[i].name, "友军哨兵先遣队");
				allience_tanks[i].pos_x = 50 + rand() % 600;
				allience_tanks[i].pos_y = 600 + rand() % 500; 
			}
			else if(i < 20)
			{
				allience_tanks[i].pos_x = 1400 + rand() % 200;
				allience_tanks[i].pos_y = 50 + rand() % 100; 
				strcpy(allience_tanks[i].name, "友军哨兵大军");
			}
			else if(i < 30)
			{
				allience_tanks[i].pos_x = 1400 + rand() % 200;
				allience_tanks[i].pos_y = 1950 - rand() % 100; 
				strcpy(allience_tanks[i].name, "友军哨兵大军");
			}
			else if(i < 40)
			{
				allience_tanks[i].pos_x = 50 + rand() % 100;
				allience_tanks[i].pos_y = 900 + rand() % 200; 
				strcpy(allience_tanks[i].name, "友军哨兵大军");
			}
			else
			{
				allience_tanks[i].pos_x = 2950 - rand() % 100;
				allience_tanks[i].pos_y = 900 + rand() % 200; 
				strcpy(allience_tanks[i].name, "友军哨兵大军");
			}
		}
	}
	else if(stage == 9)  // 八关 8700   1230 
	{
		c_v_t = V_STD;
		c_d_t = D_TLE;
		d_addtion_param = clock() + 50000;
		d_addtion_time = 50000;
		NUM_OF_ALLIENCE = 12;
		NUM_OF_ENEMY = 30;

		//敌军有3个炮塔  初始还有 9 名敌军  然后其他都是三个一组赶来
		//最后三组为精英
		
		//友方为三个一组赶来 初始有 3个  

		for(int i = 0; i < NUM_OF_ENEMY; i++)
		{
			if(i < 3) // 前三个炮塔
			{
				enemy_tanks[i] = NPC_Tank();
				enemy_tanks[i].icon = Turret;
				enemy_tanks[i].rc = TURRET;
				//enemy_tanks[i].Vp_range = 3500;
				enemy_tanks[i].Max_Speed = 0;
				enemy_tanks[i].fire_speed = 155;
				enemy_tanks[i].damage = 1450;
				enemy_tanks[i].fire_interval = 1100;
				enemy_tanks[i].max_hitpoint = 182500;
				enemy_tanks[i].current_max_hitpoint = 182500;
				enemy_tanks[i].current_hitpoint = 182500;
				enemy_tanks[i].gun_damage_rate = 14;
				enemy_tanks[i].penertrated_detonation_rate = 35;
				enemy_tanks[i].effective_penertrated_detonation_rate = 90;
				enemy_tanks[i].restore_per_update = 2;
				enemy_tanks[i].route_interval = 1000;
				enemy_tanks[i].last_route = -1000;
				enemy_tanks[i].ammor_level += 3;
				enemy_tanks[i].side_ammor_level += 2;
				enemy_tanks[i].behind_ammor_level += 2;
				enemy_tanks[i].penertrate_level += 5;
				strcpy(enemy_tanks[i].name, "联萌军炮塔");

				if(i == 0)
				{
					enemy_tanks[i].pos_x = 400;
					enemy_tanks[i].pos_y = 800;
				}
				else if(i == 1)
				{
					enemy_tanks[i].pos_x = 400;
					enemy_tanks[i].pos_y = 1200;
				}
				else
				{
					enemy_tanks[i].pos_x = 700;
					enemy_tanks[i].pos_y = 1000;
				}

			}
			// 3 - 11 号 (<12 )  初始在场上 分成三股
			else if(i < 12)
			{
				enemy_tanks[i] = NPC_Tank();
				enemy_tanks[i].icon = UK_T1;
				enemy_tanks[i].rc = PROTEND;
				enemy_tanks[i].pretend_range = 465;
				enemy_tanks[i].Vp_range = 1000;
				//enemy_tanks[i].Max_Speed = 0;
				//enemy_tanks[i].fire_speed = 175;
				enemy_tanks[i].damage = 1165;
				enemy_tanks[i].fire_interval = 1050;
				enemy_tanks[i].max_hitpoint = 7900;
				enemy_tanks[i].current_max_hitpoint = 7900;
				enemy_tanks[i].current_hitpoint = 7900;
				enemy_tanks[i].gun_damage_rate = 25;
				//enemy_tanks[i].penertrated_detonation_rate = 10;
				//enemy_tanks[i].effective_penertrated_detonation_rate = 50;
				enemy_tanks[i].restore_per_update = 50;
				//enemy_tanks[i].route_interval = 600;
				//enemy_tanks[i].last_route = -600;
				strcpy(enemy_tanks[i].name, "联萌军先锋");
				if(i < 6)  // 位置
				{
					enemy_tanks[i].pos_x = 750 + rand()%100; // 800
					enemy_tanks[i].pos_y = 450 + rand()%100; // 500
				}
				else if(i < 9)
				{
					enemy_tanks[i].pos_x = 750 + rand()%100; // 800
					enemy_tanks[i].pos_y = 950 + rand()%100; // 1000
				}
				else
				{
					enemy_tanks[i].pos_x = 750 + rand()%100;
					enemy_tanks[i].pos_y = 1450 + rand()%100;
				}
			}
			else if(i < 27) // 普通支援力量
			{
				enemy_tanks[i] = NPC_Tank();
				enemy_tanks[i].icon = UK_T1;
				enemy_tanks[i].rc = PROTEND;
				enemy_tanks[i].Vp_range = 1500;
				//enemy_tanks[i].Max_Speed = 0;
				//enemy_tanks[i].fire_speed = 175;
				enemy_tanks[i].damage = 1280;
				enemy_tanks[i].fire_interval = 1050;
				enemy_tanks[i].max_hitpoint = 7200;
				enemy_tanks[i].current_max_hitpoint = 7200;
				enemy_tanks[i].current_hitpoint = 7200;
				enemy_tanks[i].gun_damage_rate = 25;
				//enemy_tanks[i].penertrated_detonation_rate = 10;
				//enemy_tanks[i].effective_penertrated_detonation_rate = 50;
				enemy_tanks[i].restore_per_update = 50;
				//enemy_tanks[i].route_interval = 600;
				//enemy_tanks[i].last_route = -600;
				strcpy(enemy_tanks[i].name, "联萌军支援部队");
				enemy_tanks[i].is_on_field = 0;
				if(i < 15)  // 位置
				{
					enemy_tanks[i].pos_x = 1050 + rand()%300; // 800
					enemy_tanks[i].pos_y = 350 + rand()%300; // 500
				}
				else if(i < 18)
				{
					enemy_tanks[i].pos_x = 1050 + rand()%300; // 800
					enemy_tanks[i].pos_y = 950 + rand()%100; // 1000
				}
				else if(i < 21)
				{
					enemy_tanks[i].pos_x = 1050 + rand()%300;
					enemy_tanks[i].pos_y = 1350 + rand()%300;
				}

				else if(i < 24)
				{
					enemy_tanks[i].pos_x = 1450 + rand()%300;
					enemy_tanks[i].pos_y = 650 + rand()%300;
				}
				else
				{
					enemy_tanks[i].pos_x = 1450 + rand()%300;
					enemy_tanks[i].pos_y = 1050 + rand()%300;
				}

			}
			else if(i < 29)
			{
				enemy_tanks[i] = NPC_Tank();
				enemy_tanks[i].icon = UK_T1;
				enemy_tanks[i].rc = VP;
				enemy_tanks[i].Vp_range = 1500;
				//enemy_tanks[i].Max_Speed = 0;
				//enemy_tanks[i].fire_speed = 175;
				enemy_tanks[i].damage = 1400;
				enemy_tanks[i].fire_interval = 800;
				enemy_tanks[i].max_hitpoint = 12000;
				enemy_tanks[i].current_max_hitpoint = 12000;
				enemy_tanks[i].current_hitpoint = 12000;
				enemy_tanks[i].gun_damage_rate = 25;
				enemy_tanks[i].penertrated_detonation_rate = 0;
				enemy_tanks[i].effective_penertrated_detonation_rate = 0;
				enemy_tanks[i].restore_per_update = 50;
				//enemy_tanks[i].route_interval = 600;
				//enemy_tanks[i].last_route = -600;
				strcpy(enemy_tanks[i].name, "联萌军精英");
				enemy_tanks[i].is_on_field = 0;
				enemy_tanks[i].pos_x = 400 + rand() % 400;
				enemy_tanks[i].pos_y = 750 + rand() %500;
			}
			else
			{
				enemy_tanks[i] = NPC_Tank();
				enemy_tanks[i].icon = UK_T1;
				enemy_tanks[i].rc = VP;
				enemy_tanks[i].Vp_range = 1500;
				//enemy_tanks[i].Max_Speed = 0;
				//enemy_tanks[i].fire_speed = 175;
				enemy_tanks[i].damage = 1800;
				enemy_tanks[i].fire_interval = 800;
				enemy_tanks[i].max_hitpoint = 16500;
				enemy_tanks[i].current_max_hitpoint = 16500;
				enemy_tanks[i].current_hitpoint = 16500;
				enemy_tanks[i].gun_damage_rate = 0;
				enemy_tanks[i].penertrated_detonation_rate = 0;
				enemy_tanks[i].effective_penertrated_detonation_rate = 0;
				enemy_tanks[i].restore_per_update = 50;
				//enemy_tanks[i].route_interval = 600;
				//enemy_tanks[i].last_route = -600;
				strcpy(enemy_tanks[i].name, "联萌军首领");
				enemy_tanks[i].is_on_field = 0;
				enemy_tanks[i].pos_x = 600;
				enemy_tanks[i].pos_y = 950 + rand()%100;

			}

		}
		tank1.pos_x = 2500;
		tank1.pos_y = 1000;
		//友方
		// 模型是一样的 
		for(int i = 0; i < NUM_OF_ALLIENCE; i++)
		{
			allience_tanks[i] = NPC_Tank();
			allience_tanks[i].icon = G_T1;
			allience_tanks[i].rc = PROTEND;
			allience_tanks[i].Vp_range = 3500;
			allience_tanks[i].Max_Speed = 23;
			allience_tanks[i].fire_speed = 165;
			allience_tanks[i].damage = 1540;
			allience_tanks[i].fire_interval = 900;
			allience_tanks[i].max_hitpoint = 14500;
			allience_tanks[i].current_max_hitpoint = 14500;
			allience_tanks[i].current_hitpoint = 14500;
			allience_tanks[i].gun_damage_rate = 5;
			allience_tanks[i].penertrated_detonation_rate = 0;
			allience_tanks[i].effective_penertrated_detonation_rate = 0;
			allience_tanks[i].restore_per_update = 135;
			if(i < 6)
			{
				allience_tanks[i].is_on_field = 1;
				strcpy(allience_tanks[i].name, "国防军精英先锋");
				allience_tanks[i].pos_x = 1900;
				allience_tanks[i].pos_y = 750 + i*100;
			}
			else
			{
				allience_tanks[i].is_on_field = 0;
				strcpy(allience_tanks[i].name, "国防军精英");
				if(i < 6)
				{
					allience_tanks[i].pos_x = 1000;
					allience_tanks[i].pos_y = 1850 + rand()%100;
				}
				else if(i < 9)
				{
					allience_tanks[i].pos_x = 1000;
					allience_tanks[i].pos_y = 50 + rand()%100;
				}
				else
				{
					allience_tanks[i].pos_x = 1450 + rand()%100;
					allience_tanks[i].pos_y = 950 + rand()%100;
				}
			}
		}
	}
	else if (stage == 8)
	{
		//敌人有 9个出生点  每个出生点 4名敌军  最开始刷出9个敌军  人数低于5时 每次刷新一个敌军  友军5人
		c_v_t = V_STD;
		c_d_t = D_TLE;
		d_addtion_param = clock() + 65000;
		d_addtion_time = 65000;
		NUM_OF_ALLIENCE = 14;
		NUM_OF_ENEMY = 72;

		for (int i = 0; i < NUM_OF_ENEMY; i++)
		{
				
			enemy_tanks[i] = NPC_Tank();
			enemy_tanks[i].icon = UK_T1;
			enemy_tanks[i].rc = VP;
			enemy_tanks[i].Vp_range = 1800;
			//enemy_tanks[i].Max_Speed = 0;
			//enemy_tanks[i].fire_speed = 155;
			enemy_tanks[i].damage = 690;
			enemy_tanks[i].fire_interval = 810;
			enemy_tanks[i].max_hitpoint = 5900;
			enemy_tanks[i].current_max_hitpoint = 5900;
			enemy_tanks[i].current_hitpoint = 5900;
			//enemy_tanks[i].gun_damage_rate = 14;
			//enemy_tanks[i].penertrated_detonation_rate = 25;
			//enemy_tanks[i].effective_penertrated_detonation_rate = 40;
			enemy_tanks[i].restore_per_update = 30;
			//enemy_tanks[i].route_interval = 1000;
			//enemy_tanks[i].last_route = -1000;
			strcpy(enemy_tanks[i].name, "联萌军哨兵");
			if (i < 9)
				enemy_tanks[i].is_on_field = 1;
			else 
				enemy_tanks[i].is_on_field = 0;
			int index = i % 9;
			enemy_tanks[i].pos_x = 450 + (index % 3) * 1000 + rand() % 100;
			enemy_tanks[i].pos_y = 350 + (index / 3) * 600 + rand() % 100;


		
			// 3 - 11 号 (<12 )  初始在场上 分成三股

		}
		tank1.pos_x = 2000;
		tank1.pos_y = 1100;
		//友方
		// 模型是一样的 都在场上
		for(int i = 0; i < NUM_OF_ALLIENCE; i++)
		{
			allience_tanks[i] = NPC_Tank();
			allience_tanks[i].icon = G_T1;
			allience_tanks[i].rc = VP;
			allience_tanks[i].Vp_range = 3500;
			allience_tanks[i].Max_Speed = 23;
			allience_tanks[i].fire_speed = 165;
			allience_tanks[i].damage = 1190;
			allience_tanks[i].fire_interval = 880;
			allience_tanks[i].max_hitpoint = 11400;
			allience_tanks[i].current_max_hitpoint = 11400;
			allience_tanks[i].current_hitpoint = 11400;
			allience_tanks[i].gun_damage_rate = 5;
			allience_tanks[i].penertrated_detonation_rate = 0;
			allience_tanks[i].effective_penertrated_detonation_rate = 0;
			allience_tanks[i].restore_per_update = 105;
			strcpy(allience_tanks[i].name, "国防军精英");

			if(i < 4)
			{
				allience_tanks[i].pos_x = 1900;
				allience_tanks[i].pos_y = 850 + i * 100;
			}
			else if(i < 8)
			{
				allience_tanks[i].pos_x = 2100;
				allience_tanks[i].pos_y = 850 + (i-5) * 100;
			}
			else 
			{
				allience_tanks[i].pos_x = 2000;
				allience_tanks[i].pos_y = 900;
			}
		
		}
	}
	//10800 1430 620
	else if(stage == 10) // 马奇诺防线
	{
		c_v_t = V_KNE; // 杀掉一定数目敌军即可获胜
		c_d_t = D_STD;
		v_addtion_param = 86;
		NUM_OF_ALLIENCE = 54; // 六个出生点 各 8个 友军 每 15 秒 派遣 2个 初始 2个  48
		NUM_OF_ENEMY = 98; // 8个 炮塔  48个敌人     敌人有 三个出生点 分别 位于 防线顶端 中部 和 底部  敌人一次性出动 35
		// 敌人分三组 每组 9个  3个 中距离佯攻 700像素 6 个 向外突围 -- 敌人速度 格外慢很容易风筝
		//敌军
		for(int i = 0; i < NUM_OF_ENEMY; i++)
		{
			enemy_tanks[i] = NPC_Tank();
			int index = i - 8;
			if(i < 8)// 8个炮塔  火力很强 装甲很高 但是 射速很慢 转速也慢
			{
				enemy_tanks[i].icon = Turret;
				enemy_tanks[i].rc = TURRET;
				//enemy_tanks[i].Vp_range = 3500;
				enemy_tanks[i].Max_Speed = 0;
				enemy_tanks[i].fire_speed = 200;

				enemy_tanks[i].damage = 5500;
				enemy_tanks[i].fire_interval = 3000;
				enemy_tanks[i].max_hitpoint = 300000;
				enemy_tanks[i].current_max_hitpoint = 300000;
				enemy_tanks[i].current_hitpoint = 300000;
				enemy_tanks[i].gun_damage_rate = 0;
				enemy_tanks[i].engine_damage_rate = 0;

				enemy_tanks[i].penertrated_detonation_rate = 30;
				enemy_tanks[i].effective_penertrated_detonation_rate = 40;
				enemy_tanks[i].restore_per_update = 45;
				enemy_tanks[i].route_interval = 1400;
				enemy_tanks[i].last_route = -1400;
				strcpy(enemy_tanks[i].name, "万里长城要塞炮");
				enemy_tanks[i].pos_x = 1500;
				enemy_tanks[i].pos_y = 1750 - 140 * i;
				enemy_tanks[i].ammor_level = 9;
				enemy_tanks[i].penertrate_level = 18;
				enemy_tanks[i].fire_range = 2000;
			}
			else
			{
				//类型
				if(index % 16 < 11) // 0 - 5 6个 突击的
				{
					enemy_tanks[i].icon = UK_T1;
					enemy_tanks[i].rc = VP;
					enemy_tanks[i].Vp_range = 1000;
					enemy_tanks[i].Max_Speed = 13;
					enemy_tanks[i].fire_speed = 120;

					enemy_tanks[i].damage = 1230;
					enemy_tanks[i].fire_interval = 900;
					enemy_tanks[i].max_hitpoint = 9900;
					enemy_tanks[i].current_max_hitpoint = 9900;
					enemy_tanks[i].current_hitpoint = 9900;
					enemy_tanks[i].gun_damage_rate = 15;
					enemy_tanks[i].engine_damage_rate = 60;

					//enemy_tanks[i].penertrated_detonation_rate = 25;
					//enemy_tanks[i].effective_penertrated_detonation_rate = 50;
					//enemy_tanks[i].restore_per_update = 45;
					//enemy_tanks[i].route_interval = 1400;
					//enemy_tanks[i].last_route = -1400;
					strcpy(enemy_tanks[i].name, "万里长城守军突击队");
				}
				else
				{
					enemy_tanks[i].icon = UK_T1;
					enemy_tanks[i].rc = PROTEND;
					enemy_tanks[i].Vp_range = 1000;
					enemy_tanks[i].pretend_range = 750;
					enemy_tanks[i].Max_Speed = 11;
					enemy_tanks[i].fire_speed = 160;

					enemy_tanks[i].damage = 1530;
					enemy_tanks[i].fire_interval = 1300;
					enemy_tanks[i].max_hitpoint = 8800;
					enemy_tanks[i].current_max_hitpoint = 8800;
					enemy_tanks[i].current_hitpoint = 8800;
					enemy_tanks[i].gun_damage_rate = 20;
					enemy_tanks[i].engine_damage_rate = 80;

					enemy_tanks[i].penertrated_detonation_rate += 10;
					enemy_tanks[i].effective_penertrated_detonation_rate += 15;
					//enemy_tanks[i].restore_per_update = 45;
					//enemy_tanks[i].route_interval = 1400;
					//enemy_tanks[i].last_route = -1400;
					strcpy(enemy_tanks[i].name, "万里长城守军黑枪手");
				}
				enemy_tanks[i].pos_x = 1350 + rand()%300;
				if(index % 3 == 0)
				{
					enemy_tanks[i].pos_y = 1450 + rand()%300;
				}
				else if(index % 3 == 1)
				{
					enemy_tanks[i].pos_y = 1050 + rand()%300;
				}
				else
				{
					enemy_tanks[i].pos_y = 650 + rand()%300;
				}
			}
			tank1.pos_x = 400;
			tank1.pos_y = 850;
		
			// 友军分为 6股  分为 两种  东侧负责 佯攻  西侧 北侧负责消灭敌人 
 			// 6 * 8   
			for(int i = 0; i < NUM_OF_ALLIENCE; i++)
			{
				allience_tanks[i] = NPC_Tank();
				allience_tanks[i].icon = G_T1;
				if(i % 6 < 4)
				{
					allience_tanks[i].rc = MASTER;
					allience_tanks[i].target_index = 55;
					allience_tanks[i].Vp_range = 800;
					allience_tanks[i].Max_Speed = 22;
					allience_tanks[i].fire_speed = 195;
					allience_tanks[i].damage = 1390;
					allience_tanks[i].fire_interval = 1000;
					allience_tanks[i].max_hitpoint = 25000;
					allience_tanks[i].current_max_hitpoint = 25000;
					allience_tanks[i].current_hitpoint = 25000;
					allience_tanks[i].gun_damage_rate = 5;
					allience_tanks[i].penertrated_detonation_rate = 0;
					allience_tanks[i].effective_penertrated_detonation_rate = 0;
					allience_tanks[i].restore_per_update = 155;
					strcpy(allience_tanks[i].name, "国防军精英突击队");

				}
				else
				{
					allience_tanks[i].rc = PROTEND;
					allience_tanks[i].pretend_range = 270;
					allience_tanks[i].Vp_range = 800;
					allience_tanks[i].Max_Speed = 18;
					allience_tanks[i].fire_speed = 215;
					allience_tanks[i].damage = 2400;
					allience_tanks[i].fire_interval = 2000;
					allience_tanks[i].max_hitpoint = 33000;
					allience_tanks[i].current_max_hitpoint = 33000;
					allience_tanks[i].current_hitpoint = 33000;
					allience_tanks[i].gun_damage_rate = 0;
					allience_tanks[i].penertrated_detonation_rate = 0;
					allience_tanks[i].effective_penertrated_detonation_rate = 0;
					allience_tanks[i].restore_per_update = 400;
					strcpy(allience_tanks[i].name, "国防军攻坚战精英");
				}
				//隐藏
				if(i >= 18)
				{
					allience_tanks[i].is_on_field = 0;
				}
				//位置    上方  700  100   1300 100  左侧   300 800  300 1200  右侧 2700 800 2700 1200
				if(i % 6 == 0)
				{
					allience_tanks[i].pos_x = 1350 + rand()%100;
					allience_tanks[i].pos_y = 50 + rand()%100;
				}
				else if(i % 6 == 1)
				{
					allience_tanks[i].pos_x = 1550 + rand()%100;
					allience_tanks[i].pos_y = 50 + rand()%100;
				}

				else if(i % 6 == 2)
				{
					allience_tanks[i].pos_x = 850 + rand()%100;
					allience_tanks[i].pos_y = 450 + rand()%100;
				}
				else if(i % 6 == 3)
				{
					allience_tanks[i].pos_x = 850 + rand()%100;
					allience_tanks[i].pos_y = 750 + rand()%100;
				}
				else if(i % 6 == 4)
				{
					allience_tanks[i].pos_x = 2050 + rand()%100;
					allience_tanks[i].pos_y = 250 + rand()%100;
				}
				else if(i % 6 == 5)
				{
					allience_tanks[i].pos_x = 2050 + rand()%100;
					allience_tanks[i].pos_y = 550 + rand()%100;
				}		
			}

		}

	}
	//敦刻尔克
	else if(stage == 11) // 马奇诺防线 11900  1585
	{
		c_v_t = V_STD; // 杀掉一定数目敌军即可获胜
		c_d_t = D_LVP;
		//v_addtion_param = 52;
		NUM_OF_ALLIENCE = 47; // 六个出生点 各 8个 友军 每 15 秒 派遣 2个 初始 2个  48
		NUM_OF_ENEMY = 360; // 8个 炮塔  48个敌人     敌人有 三个出生点 分别 位于 防线顶端 中部 和 底部  敌人一次性出动 35
		// 敌人分三组 每组 9个  3个 中距离佯攻 700像素 6 个 向外突围 -- 敌人速度 格外慢很容易风筝
		//敌军
		for(int i = 0; i < NUM_OF_ENEMY; i++)
		{
			//为了平衡困难难度敌方基本数据前后一共修改了19次...
			enemy_tanks[i] = NPC_Tank();
		
			enemy_tanks[i].icon = UK_T1;
			enemy_tanks[i].rc = PROTEND;
			enemy_tanks[i].Vp_range = 3000;
			enemy_tanks[i].pretend_range = 200;
			enemy_tanks[i].Max_Speed = 20;
			enemy_tanks[i].fire_speed = 110;

			enemy_tanks[i].damage = 1500;
			enemy_tanks[i].fire_interval = 845;
			enemy_tanks[i].max_hitpoint = 12500;
			enemy_tanks[i].current_max_hitpoint = 12500;
			enemy_tanks[i].current_hitpoint = 12500;
			enemy_tanks[i].gun_damage_rate = 14;
			enemy_tanks[i].engine_damage_rate = 100;

			//enemy_tanks[i].penertrated_detonation_rate = 10;
			//enemy_tanks[i].effective_penertrated_detonation_rate = 50;
			//enemy_tanks[i].restore_per_update = 45;
			//enemy_tanks[i].route_interval = 1400;
			//enemy_tanks[i].last_route = -1400;
			enemy_tanks[i].is_on_field = 0;

			if(i % 3 == 0)
			{
				enemy_tanks[i].pos_x = 50 + rand() % 100;
				enemy_tanks[i].pos_y = 50 + rand() % 100;
			}
			else if(i % 3 == 1)
			{
				enemy_tanks[i].pos_x = 1250 + rand() % 100;
				enemy_tanks[i].pos_y = 550 + rand() % 100;
			}
			else
			{
				enemy_tanks[i].pos_x = 1850 + rand() % 100;
				enemy_tanks[i].pos_y = 1850 + rand() % 100;
			}
			strcpy(enemy_tanks[i].name, "猪突的联萌军");
		}

		tank1.pos_x = 250;
		tank1.pos_y = 1750;
		

 			
		for(int i = 0; i < NUM_OF_ALLIENCE; i++)
		{
			allience_tanks[i] = NPC_Tank();
			if( i < 1)
			{
				allience_tanks[i].icon = Turret;
				allience_tanks[i].rc = TURRET;
				//allience_tanks[i].target_index = 55;
				//allience_tanks[i].Vp_range = 500;
				allience_tanks[i].Max_Speed = 0;
				allience_tanks[i].fire_speed = 235;
				allience_tanks[i].damage = 6300;
				allience_tanks[i].fire_interval = 1600;
				allience_tanks[i].fire_range = 2400;
				allience_tanks[i].max_hitpoint = 85000;
				allience_tanks[i].current_max_hitpoint = 85000;
				allience_tanks[i].current_hitpoint = 85000;
				allience_tanks[i].gun_damage_rate = 0;
				allience_tanks[i].penertrated_detonation_rate = 0;
				allience_tanks[i].effective_penertrated_detonation_rate = 0;
				allience_tanks[i].restore_per_update = 180;
				strcpy(allience_tanks[i].name, "大撤退城核心炮塔");
				allience_tanks[i].pos_x = 120;
				allience_tanks[i].pos_y = 1880;
				allience_tanks[i].penertrate_level += 15;

				
			}
			else if(i < 4)
			{
				allience_tanks[i].icon = Turret;
				allience_tanks[i].rc = TURRET;
				//allience_tanks[i].target_index = 55;
				//allience_tanks[i].Vp_range = 500;
				allience_tanks[i].Max_Speed = 0;
				allience_tanks[i].fire_speed = 225;
				allience_tanks[i].damage = 5400;
				allience_tanks[i].fire_interval = 1500;
				allience_tanks[i].max_hitpoint = 45000;
				allience_tanks[i].current_max_hitpoint = 45000;
				allience_tanks[i].current_hitpoint = 45000;
				allience_tanks[i].gun_damage_rate = 0;
				allience_tanks[i].fire_range = 2400;
				allience_tanks[i].penertrated_detonation_rate = 0;
				allience_tanks[i].effective_penertrated_detonation_rate = 0;
				allience_tanks[i].restore_per_update = 125;
				strcpy(allience_tanks[i].name, "大撤退城炮塔");
				allience_tanks[i].penertrate_level += 15;

				if(i == 1)
				{
					allience_tanks[i].pos_x = 550;
					allience_tanks[i].pos_y = 1950;
				}
				else if(i == 2)
				{
					allience_tanks[i].pos_x = 50;
					allience_tanks[i].pos_y = 1450;
				}
				else
				{
					allience_tanks[i].pos_x = 450;
					allience_tanks[i].pos_y = 1550;
				}
			}
			else if(i < 18)
			{

				allience_tanks[i].rc = PROTEND;
				allience_tanks[i].pretend_range = 1100;
				allience_tanks[i].Vp_range = 200;
				allience_tanks[i].Max_Speed = 8;
				allience_tanks[i].fire_speed = 195;
				allience_tanks[i].damage = 1900;
				allience_tanks[i].fire_interval = 920;
				allience_tanks[i].max_hitpoint = 13000;
				allience_tanks[i].current_max_hitpoint = 13000;
				allience_tanks[i].current_hitpoint = 13000;
				allience_tanks[i].gun_damage_rate = 0;
				allience_tanks[i].penertrated_detonation_rate = 5;
				allience_tanks[i].effective_penertrated_detonation_rate = 10;
				allience_tanks[i].restore_per_update = 60;
				strcpy(allience_tanks[i].name, "国防军防守砖家");
				allience_tanks[i].pos_x = 50 + rand()%100;
				allience_tanks[i].pos_y = 1850 + rand()%100;
				allience_tanks[i].icon = G_T1;
				allience_tanks[i].penertrate_level += 3;

			}
			else
			{
				allience_tanks[i].rc = VP;
				//allience_tanks[i].pretend_range = 270;
				allience_tanks[i].Vp_range = 3000;
				allience_tanks[i].Max_Speed = 37;
				allience_tanks[i].Accelerate_Power = 15;
				allience_tanks[i].fire_speed = 215;
				allience_tanks[i].damage = 2500;
				allience_tanks[i].fire_interval =  700;
				allience_tanks[i].max_hitpoint = 30000;
				allience_tanks[i].current_max_hitpoint = 30000;
				allience_tanks[i].current_hitpoint = 30000;
				allience_tanks[i].gun_damage_rate = 0;
				allience_tanks[i].engine_damage_rate = 0;
				allience_tanks[i].penertrated_detonation_rate = 0;
				allience_tanks[i].effective_penertrated_detonation_rate = 0;
				allience_tanks[i].restore_per_update = 300;
				strcpy(allience_tanks[i].name, "暴走的老鸽");
				allience_tanks[i].pos_x = 50 + rand()%300;
				allience_tanks[i].pos_y = 1950 - rand()%300;
				allience_tanks[i].is_on_field = 0;
				allience_tanks[i].icon = G_T1;
				allience_tanks[i].penertrate_level += 3;
				allience_tanks[i].ammor_level += 2;
			}
			//隐藏
			if(i >= 18)
			{
				allience_tanks[i].is_on_field = 0;
			}
			//位置    上方  700  100   1300 100  左侧   300 800  300 1200  右侧 2700 800 2700 1200
	
		}

	}
	else if(stage == 12) // 巴黎巡游  12700 1920 620
	{
		c_v_t = V_STD; // 杀掉一定数目敌军即可获胜
		c_d_t = D_LVP;
		//v_addtion_param = 52;
		NUM_OF_ALLIENCE = 17; // 加上皇帝的坦克共17个人  8人 巡逻  8人保护  
		NUM_OF_ENEMY = 120; // 敌人位置动态变化  8个一组 共 10 组 越出越快  8人中有 4人 仇恨为最近的 另外4个人直接刺杀皇帝
	
		for(int i = 0; i < NUM_OF_ENEMY; i++)
		{
			//位置将动态决定
			if(i % 2 == 1)
			{
				enemy_tanks[i] = NPC_Tank();
				enemy_tanks[i].icon = UK_T1;
				enemy_tanks[i].rc = ELITE;
				enemy_tanks[i].target_index = 0;
				//enemy_tanks[i].Vp_range = 3000;
				//enemy_tanks[i].pretend_range = 200;
				enemy_tanks[i].Max_Speed = 25;
				enemy_tanks[i].fire_speed = 130;

				enemy_tanks[i].damage = 1350;
				enemy_tanks[i].fire_interval = 1100;
				enemy_tanks[i].max_hitpoint = 13000;
				enemy_tanks[i].current_max_hitpoint = 13000;
				enemy_tanks[i].current_hitpoint = 13000;
				enemy_tanks[i].gun_damage_rate = 28;
				enemy_tanks[i].engine_damage_rate = 100;
				enemy_tanks[i].ammor_level += 2;

				//enemy_tanks[i].penertrated_detonation_rate = 25;
				//enemy_tanks[i].effective_penertrated_detonation_rate = 50;
				//enemy_tanks[i].restore_per_update = 45;
				//enemy_tanks[i].route_interval = 1400;
				//enemy_tanks[i].last_route = -1400;
				enemy_tanks[i].is_on_field = 0;
				strcpy(enemy_tanks[i].name, "疯狂的刺杀者");
			}
			else
			{
				enemy_tanks[i] = NPC_Tank();
				enemy_tanks[i].icon = UK_T1;
				enemy_tanks[i].rc = PROTEND;
				//enemy_tanks[i].target_index = 0;
				enemy_tanks[i].Vp_range = 3000;
				enemy_tanks[i].pretend_range = 200;
				enemy_tanks[i].Max_Speed = 24;
				enemy_tanks[i].fire_speed = 155;

				enemy_tanks[i].damage = 2000;
				enemy_tanks[i].fire_interval = 1200;
				enemy_tanks[i].max_hitpoint = 9500;
				enemy_tanks[i].current_max_hitpoint = 9500;
				enemy_tanks[i].current_hitpoint = 9500;
				enemy_tanks[i].gun_damage_rate = 14;
				enemy_tanks[i].engine_damage_rate = 100;
				enemy_tanks[i].penertrate_level += 2;

				//enemy_tanks[i].penertrated_detonation_rate = 25;
				//enemy_tanks[i].effective_penertrated_detonation_rate = 50;
				//enemy_tanks[i].restore_per_update = 45;
				//enemy_tanks[i].route_interval = 1400;
				//enemy_tanks[i].last_route = -1400;
				enemy_tanks[i].is_on_field = 0;
				strcpy(enemy_tanks[i].name, "暗杀者");

			}
		}

		// 1500 1000 中心位置
		tank1.pos_x = 1400;
		tank1.pos_y = 900;
		
			// 友军分为 6股  分为 两种  东侧负责 佯攻  西侧 北侧负责消灭敌人 
 			// 6 * 8   
		for(int i = 0; i < NUM_OF_ALLIENCE; i++)
		{
			allience_tanks[i] = NPC_Tank();
			if( i < 1)
			{
				allience_tanks[i].icon = G_T1;
				allience_tanks[i].rc = VP;
				allience_tanks[i].orient = RIGHT;
				//allience_tanks[i].target_index = 55;
				allience_tanks[i].Vp_range = 400;
				allience_tanks[i].Max_Speed = 8;
				allience_tanks[i].fire_speed = 200;
				allience_tanks[i].damage = 7100;
				allience_tanks[i].fire_interval = 1400;
				allience_tanks[i].max_hitpoint = 110000;
				allience_tanks[i].current_max_hitpoint = 110000;
				allience_tanks[i].current_hitpoint = 110000;
				allience_tanks[i].gun_damage_rate = 0;
				allience_tanks[i].engine_damage_rate = 0;
				allience_tanks[i].penertrated_detonation_rate = 0;
				allience_tanks[i].effective_penertrated_detonation_rate = 0;
				allience_tanks[i].restore_per_update = 450;
				strcpy(allience_tanks[i].name, "皇帝的坦克？");
				allience_tanks[i].pos_x = 1500;
				allience_tanks[i].pos_y = 1000;
			}
			else if(i < 9)
			{
				allience_tanks[i].orient = RIGHT;
				allience_tanks[i].icon = G_T1;
				allience_tanks[i].rc = PROTECT;
				allience_tanks[i].protect_index = -1;
				//allience_tanks[i].Vp_range = 500;
				allience_tanks[i].Max_Speed = 15;
				allience_tanks[i].fire_speed = 185;
				allience_tanks[i].damage = 2800;
				allience_tanks[i].fire_interval = 900;
				allience_tanks[i].max_hitpoint = 31000;
				allience_tanks[i].current_max_hitpoint = 31000;
				allience_tanks[i].current_hitpoint = 31000;
				allience_tanks[i].engine_damage_rate = 0;
				allience_tanks[i].gun_damage_rate = 0;
				allience_tanks[i].penertrated_detonation_rate = 0;
				allience_tanks[i].effective_penertrated_detonation_rate = 0;
				allience_tanks[i].restore_per_update = 100;
				strcpy(allience_tanks[i].name, "皇卫军精英");
				if(i == 1)
				{
					allience_tanks[i].pos_x = 1500;
					allience_tanks[i].pos_y = 900;
				}
				else if(i == 2)
				{
					allience_tanks[i].pos_x = 1600;
					allience_tanks[i].pos_y = 900;
				}
				else if(i == 3)
				{
					allience_tanks[i].pos_x = 1400;
					allience_tanks[i].pos_y = 1000;
				}
				else if(i == 4)
				{
					allience_tanks[i].pos_x = 1600;
					allience_tanks[i].pos_y = 1000;
				}
				else if(i == 5)
				{
					allience_tanks[i].pos_x = 1600;
					allience_tanks[i].pos_y = 1000;
				}
				else if(i == 6)
				{
					allience_tanks[i].pos_x = 1400;
					allience_tanks[i].pos_y = 1100;
				}
				else if(i == 7)
				{
					allience_tanks[i].pos_x = 1500;
					allience_tanks[i].pos_y = 1100;
				}
				else if(i == 8)
				{
					allience_tanks[i].pos_x = 1600;
					allience_tanks[i].pos_y = 1100;
				}
			}
			else
			{
				//allience_tanks[i].orient = RIGHT;
				allience_tanks[i].icon = G_T1;
				allience_tanks[i].rc = VP;
				//allience_tanks[i].protect_index = 0;
				allience_tanks[i].Vp_range = 3500;
				allience_tanks[i].Max_Speed = 24;
				allience_tanks[i].fire_speed = 175;
				allience_tanks[i].damage = 2500;
				allience_tanks[i].fire_interval = 800;
				allience_tanks[i].max_hitpoint = 25300;
				allience_tanks[i].current_max_hitpoint = 25300;
				allience_tanks[i].current_hitpoint = 25300;
				allience_tanks[i].gun_damage_rate = 0;
				allience_tanks[i].penertrated_detonation_rate = 0;
				allience_tanks[i].effective_penertrated_detonation_rate = 0;
				allience_tanks[i].restore_per_update = 75;
				strcpy(allience_tanks[i].name, "皇卫军巡逻者");
				if((i - 9) % 8 < 2)
				{
					allience_tanks[i].pos_x = 250;
					allience_tanks[i].pos_y = 250;
				}
				else if((i - 9) % 8 < 4)
				{
					allience_tanks[i].pos_x = 250;
					allience_tanks[i].pos_y = 1750;
				}
				else if((i - 9) % 8 < 6)
				{
					allience_tanks[i].pos_x = 2750;
					allience_tanks[i].pos_y = 250;
				}
				else
				{
					allience_tanks[i].pos_x = 2750;
					allience_tanks[i].pos_y = 1750;
				}
			}
		
		}

	}
	else if(stage == 13) //巴巴罗萨  13500 2005 620
	{
		c_v_t = V_STD; 
		c_d_t = D_STD;
		//v_addtion_param = 52;
		NUM_OF_ALLIENCE = 13; // 6 + 1 + 7  
		NUM_OF_ENEMY = 48; 
		NUM_OF_TEAMMATE = 6;
	
		for(int i = 0; i < NUM_OF_ENEMY; i++)
		{
			
			enemy_tanks[i] = NPC_Tank();
			enemy_tanks[i].icon = USSR_T1;
			enemy_tanks[i].rc = NOOB;
			//enemy_tanks[i].target_index = 0;
			//enemy_tanks[i].Vp_range = 3000;
			//enemy_tanks[i].pretend_range = 200;
			enemy_tanks[i].Max_Speed = 14;
			enemy_tanks[i].fire_speed = 120;

			enemy_tanks[i].damage = 4600;
			enemy_tanks[i].fire_interval = 1600;
			enemy_tanks[i].max_hitpoint = 28000;
			enemy_tanks[i].current_max_hitpoint = 28000;
			enemy_tanks[i].current_hitpoint = 28000;
			enemy_tanks[i].gun_damage_rate = 15;
			enemy_tanks[i].engine_damage_rate = 30;

			enemy_tanks[i].penertrated_detonation_rate = 6;
			enemy_tanks[i].effective_penertrated_detonation_rate = 13;
			enemy_tanks[i].restore_per_update = 235;
			enemy_tanks[i].route_interval = 900;
			enemy_tanks[i].last_route = -900;
			enemy_tanks[i].is_on_field = 1;
			strcpy(enemy_tanks[i].name, "迟钝的巨熊");
			enemy_tanks[i].orient = LEFT;

			enemy_tanks[i].penertrate_level = 10;
			
			if(i < 16)
			{
				enemy_tanks[i].pos_x = 2400 + 100 * (i % 4);
				enemy_tanks[i].pos_y = 100 + 100 * (i / 4);
			}
			else if(i < 32)
			{
				int index = i - 16;
				enemy_tanks[i].pos_x = 2100 + 100 * (index % 4);
				enemy_tanks[i].pos_y = 850 + 100 * (index / 4);
			}
			else
			{
				int index = i - 32;
				enemy_tanks[i].pos_x = 2400 + 100 * (index % 4);
				enemy_tanks[i].pos_y = 1900 - 100 * (index / 4);
			}

		
		}
		//200  200 200 1800
		tank1.pos_x = 200;
		tank1.pos_y = 1800;
		
			// 友军分为 6股  分为 两种  东侧负责 佯攻  西侧 北侧负责消灭敌人 
 			// 6 * 8   
		for(int i = 0; i < NUM_OF_ALLIENCE; i++)
		{
			allience_tanks[i] = NPC_Tank();
			if( i < NUM_OF_TEAMMATE)
			{
				allience_tanks[i].icon = G_T1;
				allience_tanks[i].rc = NORMAL;
				allience_tanks[i].orient = RIGHT;
				//allience_tanks[i].target_index = 55;
				//allience_tanks[i].Vp_range = 400;
				allience_tanks[i].Max_Speed = 22;
				allience_tanks[i].fire_speed = 160;
				allience_tanks[i].damage = 2200;
				allience_tanks[i].fire_interval = 800;
				allience_tanks[i].max_hitpoint = 14800;
				allience_tanks[i].current_max_hitpoint = 14800;
				allience_tanks[i].current_hitpoint = 14800;
				allience_tanks[i].gun_damage_rate = 7;
				allience_tanks[i].engine_damage_rate = 40;
				allience_tanks[i].penertrated_detonation_rate = 5;
				allience_tanks[i].effective_penertrated_detonation_rate = 10;
				allience_tanks[i].restore_per_update = 148;
				strcpy(allience_tanks[i].name, "奥托小队成员");
				allience_tanks[i].pos_x = 150 + rand()%100;
				allience_tanks[i].pos_y = 1750 + rand()%100;
			}
			else 
			{
				allience_tanks[i].icon = G_T1;
				allience_tanks[i].rc = VP;
				allience_tanks[i].orient = RIGHT;
				//allience_tanks[i].target_index = 55;
				allience_tanks[i].Vp_range = 3000;
				allience_tanks[i].Max_Speed = 24;
				allience_tanks[i].fire_speed = 160;
				allience_tanks[i].damage = 2200;
				allience_tanks[i].fire_interval = 800;
				allience_tanks[i].max_hitpoint = 14800;
				allience_tanks[i].current_max_hitpoint = 14800;
				allience_tanks[i].current_hitpoint = 14800;
				allience_tanks[i].gun_damage_rate = 7;
				allience_tanks[i].engine_damage_rate = 40;
				allience_tanks[i].penertrated_detonation_rate = 5;
				allience_tanks[i].effective_penertrated_detonation_rate = 10;
				allience_tanks[i].restore_per_update = 148;
				strcpy(allience_tanks[i].name, "B小队成员");
				allience_tanks[i].pos_x = 150 + rand()%100;
				allience_tanks[i].pos_y = 150 + rand()%100;
			}
		
		
		}

	}
	else if(stage == 14)
	{
		c_v_t = V_STD; 
		c_d_t = D_LNA;
		d_addtion_param = 89;

		NUM_OF_ALLIENCE = 94; // 6 + 1 + 7  
		NUM_OF_ENEMY = 27; 
		NUM_OF_TEAMMATE = 4;
	
		for(int i = 0; i < NUM_OF_ENEMY; i++)
		{
			
			enemy_tanks[i] = NPC_Tank();
			enemy_tanks[i].icon = USSR_T3;
			enemy_tanks[i].rc = PROTEND;
			enemy_tanks[i].pretend_range = 500;
			//enemy_tanks[i].target_index = 0;
			enemy_tanks[i].Vp_range = 5000;
		
			//enemy_tanks[i].pretend_range = 200;
			enemy_tanks[i].Max_Speed = 16;
			enemy_tanks[i].fire_speed = 140;

			enemy_tanks[i].damage = 5300;
			enemy_tanks[i].fire_interval = 1800;
			enemy_tanks[i].max_hitpoint = 53000;
			enemy_tanks[i].current_max_hitpoint = 53000;
			enemy_tanks[i].current_hitpoint = 53000;
			enemy_tanks[i].gun_damage_rate = 5;
			enemy_tanks[i].engine_damage_rate = 40;

			enemy_tanks[i].penertrated_detonation_rate = 0;
			enemy_tanks[i].effective_penertrated_detonation_rate = 0;
			enemy_tanks[i].restore_per_update = 290;
			enemy_tanks[i].route_interval = 700;
			enemy_tanks[i].last_route = -700;
			enemy_tanks[i].is_on_field = 1;

			enemy_tanks[i].ammor_level = 10;
			enemy_tanks[i].side_ammor_level = 8;
			enemy_tanks[i].behind_ammor_level = 4;

			strcpy(enemy_tanks[i].name, "新式巨熊");
			enemy_tanks[i].orient = LEFT;


			enemy_tanks[i].penertrate_level = 11;
			

			enemy_tanks[i].pos_x = 1950 + rand()%100;
			enemy_tanks[i].pos_y = 950 + rand()%100;

			if(i >= 3)
			{
				enemy_tanks[i].is_on_field = 0;
				enemy_tanks[i].pos_x = 1150 + rand()%500;
				enemy_tanks[i].pos_y = 650 + rand()%700;
			}
		}
		//200  200 200 1800
		tank1.pos_x = 1000;
		tank1.pos_y = 1250;
		tank1.orient = DOWN;


		for(int i = 0; i < NUM_OF_ALLIENCE; i++)
		{
			allience_tanks[i] = NPC_Tank();
			if( i < NUM_OF_TEAMMATE)
			{
				allience_tanks[i].icon = G_T1;
				allience_tanks[i].rc = NORMAL;
				allience_tanks[i].orient = DOWN;
				allience_tanks[i].Max_Speed = 50;
				allience_tanks[i].fire_speed = 160;
				allience_tanks[i].damage = 2300;
				allience_tanks[i].fire_interval = 750;
				allience_tanks[i].max_hitpoint = 26700;
				allience_tanks[i].current_max_hitpoint = 26700;
				allience_tanks[i].current_hitpoint = 26700;
				allience_tanks[i].gun_damage_rate = 5;
				allience_tanks[i].engine_damage_rate = 60;
				allience_tanks[i].penertrated_detonation_rate = 0;
				allience_tanks[i].effective_penertrated_detonation_rate = 0;
				allience_tanks[i].restore_per_update = 188;
				strcpy(allience_tanks[i].name, "奥托小队成员");
				allience_tanks[i].pos_x = 950 + rand()%100;
				allience_tanks[i].pos_y = 1150 + rand()%100;
				allience_tanks[i].penertrate_level = 10;
			}
			else 
			{
				allience_tanks[i].icon = G_T1;
				allience_tanks[i].rc = PROTEND;
				allience_tanks[i].Vp_range = 5000;
				allience_tanks[i].pretend_range = 250;
				allience_tanks[i].orient = RIGHT;
				allience_tanks[i].Max_Speed = 22;
				allience_tanks[i].fire_speed = 160;
				allience_tanks[i].damage = 2300;
				allience_tanks[i].fire_interval = 750;
				allience_tanks[i].max_hitpoint = 16700;
				allience_tanks[i].current_max_hitpoint = 16700;
				allience_tanks[i].current_hitpoint = 16700;
				allience_tanks[i].gun_damage_rate = 5;
				allience_tanks[i].engine_damage_rate = 60;
				allience_tanks[i].penertrated_detonation_rate = 10;
				allience_tanks[i].effective_penertrated_detonation_rate = 20;
				allience_tanks[i].restore_per_update = 188;
				strcpy(allience_tanks[i].name, "迷惑的友军");
				allience_tanks[i].pos_x = 750 + rand()%100;
				allience_tanks[i].pos_y = 750 + rand()%100;
				allience_tanks[i].penertrate_level = 8;
				allience_tanks[i].is_on_field = 0;
			}
		
		
		}

	}
	else if(stage == 15)
	{
		c_v_t = V_STD; 
		c_d_t = D_DLD;
		d_addtion_param = 1250000;

		NUM_OF_ALLIENCE = 460; 
		NUM_OF_ENEMY = 450; 
		NUM_OF_TEAMMATE = 20;
	
		for(int i = 0; i < NUM_OF_ENEMY; i++)
		{
			enemy_tanks[i] = NPC_Tank();
			if(i %4 == 0)
			{
				enemy_tanks[i].icon = USSR_T3;
				enemy_tanks[i].rc = PROTEND;
				enemy_tanks[i].pretend_range = 400;
				//enemy_tanks[i].target_index = 0;
				enemy_tanks[i].Vp_range = 5000;
		
				//enemy_tanks[i].pretend_range = 200;
				enemy_tanks[i].Max_Speed = 18;
				enemy_tanks[i].fire_speed = 140;

				enemy_tanks[i].damage = 2400;
				enemy_tanks[i].fire_interval = 3600;
				enemy_tanks[i].max_hitpoint = 45000;
				enemy_tanks[i].current_max_hitpoint = 45000;
				enemy_tanks[i].current_hitpoint = 45000;
				enemy_tanks[i].gun_damage_rate = 5;
				enemy_tanks[i].engine_damage_rate = 40;

				enemy_tanks[i].penertrated_detonation_rate = 10;
				enemy_tanks[i].effective_penertrated_detonation_rate = 15;
				enemy_tanks[i].restore_per_update = 350;
				enemy_tanks[i].route_interval = 1000;
				enemy_tanks[i].last_route = -1000;
				enemy_tanks[i].is_on_field = 1;

				enemy_tanks[i].ammor_level = 8;
				enemy_tanks[i].side_ammor_level = 4;
				enemy_tanks[i].behind_ammor_level = 3;

				strcpy(enemy_tanks[i].name, "巨熊精英");
				enemy_tanks[i].orient = LEFT;


				enemy_tanks[i].penertrate_level = 12;

			}
			else
			{
				enemy_tanks[i].icon = USSR_T1;
				enemy_tanks[i].rc = VP;
				//enemy_tanks[i].pretend_range = 500;
				//enemy_tanks[i].target_index = 0;
				enemy_tanks[i].Vp_range = 5000;
		
				//enemy_tanks[i].pretend_range = 200;
				enemy_tanks[i].Max_Speed = 20;
				enemy_tanks[i].fire_speed = 130;

				enemy_tanks[i].damage = 1350;
				enemy_tanks[i].fire_interval = 1400;
				enemy_tanks[i].max_hitpoint = 20000;
				enemy_tanks[i].current_max_hitpoint = 20000;
				enemy_tanks[i].current_hitpoint = 20000;
				enemy_tanks[i].gun_damage_rate = 15;
				enemy_tanks[i].engine_damage_rate = 70;

				enemy_tanks[i].penertrated_detonation_rate = 10;
				enemy_tanks[i].effective_penertrated_detonation_rate = 15;
				enemy_tanks[i].restore_per_update = 180;
				enemy_tanks[i].route_interval = 200;
				enemy_tanks[i].last_route = -200;
				enemy_tanks[i].is_on_field = 1;

				enemy_tanks[i].ammor_level = 7;
				enemy_tanks[i].side_ammor_level = 2;
				enemy_tanks[i].behind_ammor_level = 1;

				strcpy(enemy_tanks[i].name, "巨熊炮灰");
				enemy_tanks[i].orient = LEFT;


				enemy_tanks[i].penertrate_level = 9;

			}
			enemy_tanks[i].pos_x = 2450 + rand()%100;
			enemy_tanks[i].pos_y = 50 + rand()%1900;
			enemy_tanks[i].is_on_field = 0;
		}
		//200  200 200 1800
		tank1.pos_x = 500;
		tank1.pos_y = 1000;
		tank1.orient = DOWN;


		for(int i = 0; i < NUM_OF_ALLIENCE; i++)
		{
			allience_tanks[i] = NPC_Tank();
			if( i < NUM_OF_TEAMMATE)
			{
				allience_tanks[i].icon = G_T1;
				allience_tanks[i].rc = NORMAL;
				allience_tanks[i].orient = DOWN;
				allience_tanks[i].Max_Speed = 30;
				allience_tanks[i].fire_speed = 180;
				allience_tanks[i].damage = 1700;
				allience_tanks[i].fire_interval = 1830;
				allience_tanks[i].max_hitpoint = 29000;
				allience_tanks[i].current_max_hitpoint = 29000;
				allience_tanks[i].current_hitpoint = 29000;
				allience_tanks[i].gun_damage_rate = 0;
				allience_tanks[i].engine_damage_rate = 30;
				allience_tanks[i].penertrated_detonation_rate = 0;
				allience_tanks[i].effective_penertrated_detonation_rate = 0;
				allience_tanks[i].restore_per_update = 266;
				strcpy(allience_tanks[i].name, "奥托小队成员");
				allience_tanks[i].pos_x = 450 + rand()%100;
				allience_tanks[i].pos_y = 950 + rand()%100;
				allience_tanks[i].penertrate_level = 9;
				allience_tanks[i].is_on_field = 1;
			}
			else if((i -  40) % 4 == 0 ) 
			{
				allience_tanks[i].icon = G_T1;
				allience_tanks[i].rc = PROTEND;
				allience_tanks[i].Vp_range = 5000;
				allience_tanks[i].pretend_range = 700;
				allience_tanks[i].orient = RIGHT;
				allience_tanks[i].Max_Speed = 14;
				allience_tanks[i].fire_speed = 210;
				allience_tanks[i].damage = 3500;
				allience_tanks[i].fire_interval = 4300;
				allience_tanks[i].max_hitpoint = 17000;
				allience_tanks[i].current_max_hitpoint = 17000;
				allience_tanks[i].current_hitpoint = 17000;
				allience_tanks[i].gun_damage_rate = 0;
				allience_tanks[i].engine_damage_rate = 90;
				allience_tanks[i].penertrated_detonation_rate = 20;
				allience_tanks[i].effective_penertrated_detonation_rate = 40;
				allience_tanks[i].restore_per_update = 110;
				strcpy(allience_tanks[i].name, "精英黑枪手");
				allience_tanks[i].pos_x = 250 + rand()%100;
				allience_tanks[i].pos_y = 50 + rand()%1900;
				allience_tanks[i].penertrate_level = 14;
				allience_tanks[i].fire_range = 1900;
				allience_tanks[i].is_on_field = 0;
				
			}
			else
			{
				allience_tanks[i].icon = G_T1;
				allience_tanks[i].rc = PROTEND;
				allience_tanks[i].Vp_range = 3000;
				allience_tanks[i].pretend_range = 200;

				allience_tanks[i].orient = DOWN;
				allience_tanks[i].Max_Speed = 25;
				allience_tanks[i].fire_speed = 140;
				allience_tanks[i].damage = 1600;
				allience_tanks[i].fire_interval = 3900;
				allience_tanks[i].max_hitpoint = 25000;
				allience_tanks[i].current_max_hitpoint = 25000;
				allience_tanks[i].current_hitpoint = 25000;
				allience_tanks[i].gun_damage_rate = 20;
				allience_tanks[i].engine_damage_rate = 50;
				allience_tanks[i].penertrated_detonation_rate = 5;
				allience_tanks[i].effective_penertrated_detonation_rate = 10;
				allience_tanks[i].restore_per_update = 180;
				strcpy(allience_tanks[i].name, "量产型友军");
				allience_tanks[i].pos_x = 450 + rand()%100;
				allience_tanks[i].pos_y = 50 + rand()%1900;
				allience_tanks[i].penertrate_level = 9;
				allience_tanks[i].is_on_field = 0;

			}
			
		}

	}
	else if(stage == 16)
	{
		c_v_t = V_STD; 
		c_d_t = D_STD;

		NUM_OF_ALLIENCE = 0; 
		NUM_OF_ENEMY =  16; 
		NUM_OF_TEAMMATE = 0;
	
		for(int i = 0; i < NUM_OF_ENEMY; i++)
		{
			enemy_tanks[i] = NPC_Tank();
			enemy_tanks[i].icon = USSR_T1;
			enemy_tanks[i].rc = VP;
			//enemy_tanks[i].pretend_range = 500;
			//enemy_tanks[i].target_index = 0;
			enemy_tanks[i].Vp_range = 5000;
		
			//enemy_tanks[i].pretend_range = 200;
			enemy_tanks[i].Max_Speed = 13;
			enemy_tanks[i].fire_speed = 125;

			enemy_tanks[i].damage = 2500;
			enemy_tanks[i].fire_interval = 1800;
			enemy_tanks[i].max_hitpoint = 16000;
			enemy_tanks[i].current_max_hitpoint = 16000;
			enemy_tanks[i].current_hitpoint = 16000;
			enemy_tanks[i].gun_damage_rate = 15;
			enemy_tanks[i].engine_damage_rate = 70;

			enemy_tanks[i].penertrated_detonation_rate = 10;
			enemy_tanks[i].effective_penertrated_detonation_rate = 15;
			enemy_tanks[i].restore_per_update = 200;
			enemy_tanks[i].route_interval = 600;
			enemy_tanks[i].last_route = -600;
			enemy_tanks[i].is_on_field = 0;


			enemy_tanks[i].penertrate_level = 10;
			enemy_tanks[i].ammor_level = 7;
			enemy_tanks[i].side_ammor_level = 3;
			enemy_tanks[i].behind_ammor_level = 2;

			strcpy(enemy_tanks[i].name, "普通巨熊");
			enemy_tanks[i].orient = LEFT;

			if(0 == i % 8)
			{
				enemy_tanks[i].pos_x = 2500;
				enemy_tanks[i].pos_y = 200;
			}
			else if(1 == i % 8)
			{
				enemy_tanks[i].pos_x = 1500;
				enemy_tanks[i].pos_y = 200;
			}
			else if(2 == i % 8)
			{
				enemy_tanks[i].pos_x = 500;
				enemy_tanks[i].pos_y = 200;
			}
			else if(3 == i % 8)
			{
				enemy_tanks[i].pos_x = 2500;
				enemy_tanks[i].pos_y = 1000;
			}
			else if(4 == i % 8)
			{
				enemy_tanks[i].pos_x = 500;
				enemy_tanks[i].pos_y = 1000;
			}
			else if(5 == i % 8)
			{
				enemy_tanks[i].pos_x = 2500;
				enemy_tanks[i].pos_y = 1800;
			}
			else if(6 == i % 8)
			{
				enemy_tanks[i].pos_x = 1500;
				enemy_tanks[i].pos_y = 1800;
			}
			else if(7 == i % 8)
			{
				enemy_tanks[i].pos_x = 500;
				enemy_tanks[i].pos_y = 1800;
			}

		}
		tank1.pos_x = 1500;
		tank1.pos_y = 1000;
	}
	//
	else if(stage == 100)
	{
		c_v_t = V_STD;
		c_d_t = D_STD;
		//固定值
		tank1.pos_x = 1500;
		tank1.pos_y = 1000;
		tank1.max_hitpoint = 168000;
		tank1.current_max_hitpoint = 168000;
		tank1.current_hitpoint = 168000;


		tank1.max_damage = 10800;
		tank1.damage = 10800;
		
		tank1.fire_interval = 600;
		tank1.fastest_fire_interval = 600;
		
		tank1.fire_speed = 275;

		tank1.init_max_speed = 20;
		tank1.Max_Speed = 20;
		tank1.init_accelerate_power = 8;
		tank1.Accelerate_Power = 8;

		tank1.init_fastest_route_interval = 200;
		tank1.route_interval = 200;

		//穿深与防护
		tank1.penertrate_level = 10;
		tank1.ammor_level = 6;

		tank1.gun_damage_rate = 5;
		tank1.engine_damage_rate = 15;

		tank1.icon = G_T2_B;
		
		NUM_OF_ENEMY = 300;
		NUM_OF_ALLIENCE = 0;

		//初始化 -- 最简单的方案
		for(int i = 0; i < 300; i++)
		{
			CString h;
			enemy_tanks[i] = NPC_Tank();
			if(i % 4 == 0)
			{
				h.Format("斯大林二型");
				strcpy(enemy_tanks[i].name, h);
				enemy_tanks[i].icon = USSR_T3;
				enemy_tanks[i].fire_speed = 100 + i / 60;

				enemy_tanks[i].penertrate_level = 9;
				enemy_tanks[i].ammor_level = 7;
				enemy_tanks[i].damage = 2800 + 6 * i;
				enemy_tanks[i].fire_interval = 1600;

				enemy_tanks[i].max_hitpoint = 34000 + 40 * i;
				enemy_tanks[i].current_max_hitpoint = 34000 + 40 * i;
				enemy_tanks[i].current_hitpoint = 34000 + 40 * i;

				enemy_tanks[i].gun_damage_rate = 45 - i / 20;
				enemy_tanks[i].engine_damage_rate = 80 - i / 20;

				enemy_tanks[i].penertrated_detonation_rate = 9;
				enemy_tanks[i].effective_penertrated_detonation_rate = 18;
				enemy_tanks[i].Max_Speed = 12 + i / 220;
				enemy_tanks[i].route_interval = 480;
				enemy_tanks[i].last_route = -480;

			}
			else if(i % 4 == 1)
			{
				h.Format("斯大林三型");
				strcpy(enemy_tanks[i].name, h);
				enemy_tanks[i].icon = USSR_T4;
				enemy_tanks[i].fire_speed = 120 + i / 35;

				enemy_tanks[i].penertrate_level = 10;
				enemy_tanks[i].ammor_level = 8;
				enemy_tanks[i].damage = 4900 + 11 * i;
				enemy_tanks[i].fire_interval = 1900;

				enemy_tanks[i].max_hitpoint = 54000 + 66 * i;
				enemy_tanks[i].current_max_hitpoint = 54000 + 66 * i;
				enemy_tanks[i].current_hitpoint = 54000 + 66 * i;

				enemy_tanks[i].gun_damage_rate = 35 - i / 20;
				enemy_tanks[i].engine_damage_rate = 60 - i / 20;

				enemy_tanks[i].penertrated_detonation_rate = 6;
				enemy_tanks[i].effective_penertrated_detonation_rate = 12;

				enemy_tanks[i].Max_Speed = 10 + i / 220;
				enemy_tanks[i].route_interval = 660;
				enemy_tanks[i].last_route = -660;
			}
			else
			{
				h.Format("T34-85/1944");
				strcpy(enemy_tanks[i].name, h);
				enemy_tanks[i].icon = USSR_T1;
				enemy_tanks[i].fire_speed = 125 + i / 30;

				enemy_tanks[i].penertrate_level = 7;
				enemy_tanks[i].ammor_level = 5;
				enemy_tanks[i].damage = 3000 + 7 * i;
				enemy_tanks[i].fire_interval = 1350;

				enemy_tanks[i].max_hitpoint = 17000 + 20 * i;
				enemy_tanks[i].current_max_hitpoint = 17000 + 20 * i;
				enemy_tanks[i].current_hitpoint = 17000 + 20 * i;

				enemy_tanks[i].gun_damage_rate = 55 - i / 20;
				enemy_tanks[i].engine_damage_rate = 100 - i / 20;

				enemy_tanks[i].penertrated_detonation_rate = 22;
				enemy_tanks[i].effective_penertrated_detonation_rate = 44;
				enemy_tanks[i].Max_Speed = 15 + i / 220;
				enemy_tanks[i].route_interval = 330;
				enemy_tanks[i].last_route = -330;
			}

			enemy_tanks[i].rc = PROTEND;
			//enemy_tanks[i].target_index = 0;
			enemy_tanks[i].Vp_range = 3000;
			enemy_tanks[i].pretend_range = 170;
			enemy_tanks[i].Accelerate_Power = enemy_tanks[i].Max_Speed / 2.5;

			//



		

			enemy_tanks[i].restore_per_update = enemy_tanks[i].max_hitpoint / 100;

			enemy_tanks[i].is_on_field = 0;
			
			
			enemy_tanks[i].pos_x = rand() % 2900 + 50;
			enemy_tanks[i].pos_y = rand() % 1900 + 50;
		
			
		}
	}

	else if(stage == 101)
	{


		c_v_t = V_STD;
		c_d_t = D_STD;
		//固定值
		tank1.pos_x = 500;
		tank1.pos_y = 1000;
		tank1.max_hitpoint = 110000;
		tank1.current_max_hitpoint = 110000;
		tank1.current_hitpoint = 110000;


		tank1.max_damage = 15000;
		tank1.damage = 15000;
		
		tank1.fire_interval = 1000;
		tank1.fastest_fire_interval = 1000;
		
		tank1.fire_speed = 200;

		tank1.init_max_speed = 20;
		tank1.Max_Speed = 20;
		tank1.init_accelerate_power = 8;
		tank1.Accelerate_Power = 8;

		tank1.init_fastest_route_interval =200;
		tank1.route_interval = 200;

		//穿深与防护
		tank1.penertrate_level = 20;
		tank1.ammor_level = 12;
		tank1.side_ammor_level = 10;
		tank1.behind_ammor_level = 8;

		tank1.gun_damage_rate = 5;
		tank1.engine_damage_rate = 15;

		tank1.icon = G_T2_B;
		
		NUM_OF_ENEMY = 80;
		NUM_OF_ALLIENCE = 70;

		Player_Tank::upgrade_generation = 0;

		//初始化 -- 最简单的方案
		for(int i = 0; i < 360; i++)
		{
			CString h;
			enemy_tanks[i] = NPC_Tank();
			if(i % 4 == 0)
			{
				h.Format("I.S.-2");
				strcpy(enemy_tanks[i].name, h);
				enemy_tanks[i].icon = USSR_T3;
				enemy_tanks[i].fire_speed = 100 + i / 60;

				enemy_tanks[i].penertrate_level = 18;
				enemy_tanks[i].ammor_level = 14;
				enemy_tanks[i].side_ammor_level = 12;
				enemy_tanks[i].behind_ammor_level = 11;


				enemy_tanks[i].damage = 5200 + 8 * i;
				enemy_tanks[i].fire_interval = 1150;

				enemy_tanks[i].max_hitpoint = 40000 + 40 * i;
				enemy_tanks[i].current_max_hitpoint = 40000 + 40 * i;
				enemy_tanks[i].current_hitpoint = 40000 + 40 * i;

				enemy_tanks[i].gun_damage_rate = 25 - i / 20;
				enemy_tanks[i].engine_damage_rate = 80 - i / 20;

				enemy_tanks[i].penertrated_detonation_rate = 9;
				enemy_tanks[i].effective_penertrated_detonation_rate = 18;
				enemy_tanks[i].Max_Speed = 12 + i / 220;
				enemy_tanks[i].route_interval = 480;
				enemy_tanks[i].last_route = -480;
				enemy_tanks[i].pretend_range = 375;
			}
			else if(i % 4 == 1)
			{
				h.Format("I.S.-3");
				strcpy(enemy_tanks[i].name, h);
				enemy_tanks[i].icon = USSR_T4;
				enemy_tanks[i].fire_speed = 120 + i / 35;

				enemy_tanks[i].penertrate_level = 20;
				enemy_tanks[i].ammor_level = 16;
				enemy_tanks[i].side_ammor_level = 14;
				enemy_tanks[i].behind_ammor_level = 13;

				enemy_tanks[i].damage = 6900 + 10 * i;
				enemy_tanks[i].fire_interval = 1220;

				enemy_tanks[i].max_hitpoint = 58000 + 66 * i;
				enemy_tanks[i].current_max_hitpoint = 58000 + 66 * i;
				enemy_tanks[i].current_hitpoint = 58000 + 66 * i;

				enemy_tanks[i].gun_damage_rate = 15 - i / 20;
				enemy_tanks[i].engine_damage_rate = 60 - i / 20;

				enemy_tanks[i].penertrated_detonation_rate = 6;
				enemy_tanks[i].effective_penertrated_detonation_rate = 12;

				enemy_tanks[i].Max_Speed = 10 + i / 220;
				enemy_tanks[i].route_interval = 660;
				enemy_tanks[i].last_route = -660;
				enemy_tanks[i].pretend_range = 750;
			}
			else
			{
				h.Format("T34-85/1944");
				strcpy(enemy_tanks[i].name, h);
				enemy_tanks[i].icon = USSR_T1;
				enemy_tanks[i].fire_speed = 125 + i / 30;

				enemy_tanks[i].penertrate_level = 14;
				enemy_tanks[i].ammor_level = 6;
				enemy_tanks[i].side_ammor_level = 5;
				enemy_tanks[i].behind_ammor_level = 5;

				enemy_tanks[i].damage = 3800 + 6 * i;
				enemy_tanks[i].fire_interval = 950;

				enemy_tanks[i].max_hitpoint = 20000 + 22 * i;
				enemy_tanks[i].current_max_hitpoint = 20000 + 22 * i;
				enemy_tanks[i].current_hitpoint = 20000 + 22 * i;

				enemy_tanks[i].gun_damage_rate = 35 - i / 20;
				enemy_tanks[i].engine_damage_rate = 100 - i / 20;

				enemy_tanks[i].penertrated_detonation_rate = 22;
				enemy_tanks[i].effective_penertrated_detonation_rate = 44;
				enemy_tanks[i].Max_Speed = 15 + i / 220;
				enemy_tanks[i].route_interval = 330;
				enemy_tanks[i].last_route = -330;
				enemy_tanks[i].pretend_range = 170;
			}

			enemy_tanks[i].rc = PROTEND;
			//enemy_tanks[i].target_index = 0;
			enemy_tanks[i].Vp_range = 3000;
			enemy_tanks[i].Accelerate_Power = enemy_tanks[i].Max_Speed / 2.5;

			//
			enemy_tanks[i].restore_per_update = enemy_tanks[i].max_hitpoint / 1000;

			enemy_tanks[i].is_on_field = 0;
			
			
			enemy_tanks[i].pos_x = rand() % 1000 + 1950;
			enemy_tanks[i].pos_y = rand() % 1900 + 50;
		
			
		}
		for(int i = 0; i < NUM_OF_ALLIENCE; i++)
		{
			CString h;
			allience_tanks[i] = NPC_Tank();
			if(i % 4 == 0)
			{
				h.Format("Panzer VI A");
				strcpy(allience_tanks[i].name, h);
				allience_tanks[i].icon = G_T2;
				allience_tanks[i].fire_speed = 170 + i / 60;

				allience_tanks[i].penertrate_level = 20;
				allience_tanks[i].ammor_level = 12;
				allience_tanks[i].side_ammor_level = 10;
				allience_tanks[i].behind_ammor_level = 8;


				allience_tanks[i].damage = 4200 + 6 * i;
				allience_tanks[i].fire_interval = 1200;

				allience_tanks[i].max_hitpoint = 31000 + 38 * i;
				allience_tanks[i].current_max_hitpoint = 31000 + 38 * i;
				allience_tanks[i].current_hitpoint = 31000 + 38 * i;

				allience_tanks[i].gun_damage_rate = 25 - i / 20;
				allience_tanks[i].engine_damage_rate = 70 - i / 20;

				allience_tanks[i].penertrated_detonation_rate = 7;
				allience_tanks[i].effective_penertrated_detonation_rate = 15;
				allience_tanks[i].Max_Speed = 17 + i / 220;
				allience_tanks[i].route_interval = 370;
				allience_tanks[i].last_route = -370;
				allience_tanks[i].pretend_range = 300;
			}
			else if(i % 4 == 1)
			{
				h.Format("Panzer VI B");
				strcpy(allience_tanks[i].name, h);
				allience_tanks[i].icon = G_T2_B;
				allience_tanks[i].fire_speed = 178 + i / 60;

				allience_tanks[i].penertrate_level = 20;
				allience_tanks[i].ammor_level = 12;
				allience_tanks[i].side_ammor_level = 10;
				allience_tanks[i].behind_ammor_level = 8;

				allience_tanks[i].damage = 4500 + 7 * i;
				allience_tanks[i].fire_interval = 1080;

				allience_tanks[i].max_hitpoint = 33000 + 39 * i;
				allience_tanks[i].current_max_hitpoint = 33000 + 39 * i;
				allience_tanks[i].current_hitpoint = 33000 + 39 * i;

				allience_tanks[i].gun_damage_rate = 25 - i / 20;
				allience_tanks[i].engine_damage_rate = 70 - i / 20;

				allience_tanks[i].penertrated_detonation_rate = 7;
				allience_tanks[i].effective_penertrated_detonation_rate = 15;
				allience_tanks[i].Max_Speed = 17 + i / 220;
				allience_tanks[i].route_interval = 370;
				allience_tanks[i].last_route = -370;
				allience_tanks[i].pretend_range = 300;
			}
			else
			{
				h.Format("PANZER IV H");
				strcpy(allience_tanks[i].name, h);
				allience_tanks[i].icon = G_T1;
				allience_tanks[i].fire_speed = 158 + i / 60;

				allience_tanks[i].penertrate_level = 14;
				allience_tanks[i].ammor_level = 6;
				allience_tanks[i].side_ammor_level = 3;
				allience_tanks[i].behind_ammor_level = 2;


				allience_tanks[i].damage = 2800 + 6 * i;
				allience_tanks[i].fire_interval = 840;

				allience_tanks[i].max_hitpoint = 18000 + 25 * i;
				allience_tanks[i].current_max_hitpoint = 18000 + 25 * i;
				allience_tanks[i].current_hitpoint = 18000 + 25 * i;

				allience_tanks[i].gun_damage_rate = 35 - i / 20;
				allience_tanks[i].engine_damage_rate = 75 - i / 20;

				allience_tanks[i].penertrated_detonation_rate = 10;
				allience_tanks[i].effective_penertrated_detonation_rate = 20;
				allience_tanks[i].Max_Speed = 22 + i / 220;
				allience_tanks[i].route_interval = 220;
				allience_tanks[i].last_route = -220;
				allience_tanks[i].pretend_range = 0;
			}

			allience_tanks[i].rc = PROTEND;
			//allience_tanks[i].target_index = 0;
			allience_tanks[i].Vp_range = 3000;
			allience_tanks[i].Accelerate_Power = allience_tanks[i].Max_Speed / 2.5;

			//
			allience_tanks[i].restore_per_update = allience_tanks[i].max_hitpoint / 100;

			allience_tanks[i].is_on_field = 0;
			
			
			allience_tanks[i].pos_x = rand() % 1000 + 50;
			allience_tanks[i].pos_y = rand() % 1900 + 50;


		}

	}

	//难度补正
	if(Player_Tank::difficulty == 0 && stage < 100) //简单难度
	{
		for(int i = 0; i < NUM_OF_ALLIENCE; i++)
		{
			allience_tanks[i].damage *= 1.2;
			allience_tanks[i].max_hitpoint *= 1.2;
			allience_tanks[i].current_max_hitpoint *= 1.2;
			allience_tanks[i].current_hitpoint *= 1.2;
		}
	}
	else if(Player_Tank::difficulty == 1) //普通难度
	{
		for(int i = 0; i < NUM_OF_ALLIENCE; i++)
		{
			allience_tanks[i].damage *= 1.1;
			allience_tanks[i].max_hitpoint *= 1.1;
			allience_tanks[i].current_max_hitpoint *= 1.1;
			allience_tanks[i].current_hitpoint *= 1.1;
		}
	}


	
}
//2394行
