#include "stdafx.h"
#include "̹�˴�սϵ��Dlg.h"
//ս���ڼ�  ������߼����� �ʹ�������ս�����̼���  ������Ϸ���̼���


//ս���ڼ�   ս������  ̹�˲��� �ڵ�����  ʤ���ж�  �����غ��� ������ ̹�˲��� �ڵ����е�
void C̹�˴�սϵ��Dlg::Battle_Update_Control(void)
{
	//������װ����������
	if(Player_Tank::upgrade_gun)
	{
		Player_Tank::energy += 1;
		if(Player_Tank::energy > MAX_ENERGY)
			Player_Tank::energy = MAX_ENERGY;
	}

	//��ǰʱ��  ����λ��
	Dialog_current_clock = clock();
	//�Ȼ���Ȼ���ж�
	enemys = 0;
	alliences = 0;
	all_alliences = 0;
	all_enemys = 0;
	for(int i = 0; i < NUM_OF_ENEMY; i++)
	{
		if(enemy_tanks[i].current_hitpoint)
		{
			all_enemys += 1;
			if(enemy_tanks[i].is_on_field)
				enemys += 1;
		}
	}
	for(int i = 0; i < NUM_OF_ALLIENCE; i++)
	{
		if(allience_tanks[i].current_hitpoint)
		{
			all_alliences += 1;
			if(allience_tanks[i].is_on_field)
				alliences += 1;
		}
	}

	clock_t current_clock = clock();

	Query_Events();

#ifdef EXPLOSE_BOOM

	Explose_Effect();
#endif 

	Shells_Update();

	
	Command_Update();
	Draw_Update();
	SubView_Update();

	int key = Win_Lose_Judge();
	if(1 == key)  //ʤ��
	{
		KillTimer(1);
		//��״̬����
		KillTimer(20);
		KillTimer(21);
		tank1.is_gun_damage = 0;
		tank1.damage = tank1.max_damage;
		tank1.fire_interval = tank1.fastest_fire_interval;
		tank1.Accelerate_Power = tank1.init_accelerate_power;
		tank1.Max_Speed = tank1.init_max_speed;
		tank1.route_interval = tank1.init_fastest_route_interval;

		::mciSendString("close victory ", NULL, 0, NULL);
		::mciSendString("open victory.mp3 alias victory", NULL, 0, NULL); //�� �ļ�123.mp3  ��ȡ���� start
 		::mciSendString("play victory", NULL, 0, NULL);
	
		pictureDC.SelectObject(&victory_map);
		BLENDFUNCTION blendFunction;
		memset( &blendFunction, 0, sizeof(blendFunction) );
		blendFunction.BlendOp = AC_SRC_OVER;
		blendFunction.BlendFlags = 0;
		blendFunction.SourceConstantAlpha = 196;

		Sleep(1000);
		pDC->AlphaBlend(570, 250, 360, 500, &pictureDC, 0, 0,360, 500, blendFunction);
		Sleep(1500);


		process = After;
		Process_Show();
		//exit(0);
	}



	else if(-1 == key) // ʧ��
	{
		KillTimer(1);
		//��״̬����
		KillTimer(20);
		KillTimer(21);
		tank1.is_gun_damage = 0;
		tank1.damage = tank1.max_damage;
		tank1.fire_interval = tank1.fastest_fire_interval;
		tank1.Accelerate_Power = tank1.init_accelerate_power;
		tank1.Max_Speed = tank1.init_max_speed;
		tank1.route_interval = tank1.init_fastest_route_interval;

		pictureDC.SelectObject(&defeat_map);
		BLENDFUNCTION blendFunction;
		memset( &blendFunction, 0, sizeof(blendFunction) );
		blendFunction.BlendOp = AC_SRC_OVER;
		blendFunction.BlendFlags = 0;
		blendFunction.SourceConstantAlpha = 196;


		Sleep(1000);
		pDC->AlphaBlend(570, 250, 360, 500, &pictureDC, 0, 0,360, 500, blendFunction);
		my_sound_player(EXPLOSE_SOUND);
		Sleep(1500);

		//exit(0);
		//����Ч��
		tank1 = player_at_stage_begin;
		process = Prepare;
		Process_Show();
	}

}

//�ڵ����� ���� ����
void C̹�˴�սϵ��Dlg::Shells_Update(void)
{
	//�Ѵ��ڵ��ڵ� ���ƶ� �� �����ϵ
	//���ڵ�  �ڵ����ƶ�
	if(tank1.shell_on_field) 
	{
		tank1.shells_move();
		tank1.out_process();
		int hit_index = -100;
		int min_hit_distance = 9999;
		//ͬʱ�ж��������Ŀ��ÿ�ж�һ���Ժ�Ҫ�ж��ڵ��Ƿ���
		for(int i = 0; tank1.shell_on_field && i < NUM_OF_ENEMY; i ++)
		{
			int h = Shell_try_hit(tank1, enemy_tanks[i]);
			if(h != -1)
			{
				if(h < min_hit_distance)
				{
					min_hit_distance = h;
					hit_index = i;
				}
			}
		}
		if(hit_index != -100)
			Shell_hit(tank1, enemy_tanks[hit_index]);
	}

	//�о��ڵ�
	for(int i = 0; i < NUM_OF_ENEMY; i++)
	{
		if(enemy_tanks[i].shell_on_field) 
		{
			enemy_tanks[i].shells_move();
			enemy_tanks[i].out_process();

			int hit_index = -100;
			int min_hit_distance = 9999;
			
			//�����ҵ�̹�˲��޵в��ܹ���
			if(Dialog_current_clock > immune_to)
			{
				int h = Shell_try_hit(enemy_tanks[i], tank1);
				if(h != -1)
				{
					if(h < min_hit_distance)
					{
						
						min_hit_distance = h;
						hit_index = -1;
					}
				}
			}

			//ͬʱ�ж��������Ŀ��ÿ�ж�һ���Ժ�Ҫ�ж��ڵ��Ƿ���
			for(int z = 0; enemy_tanks[i].shell_on_field && z < NUM_OF_ALLIENCE; z ++)
			{
				int h = Shell_try_hit(enemy_tanks[i], allience_tanks[z]);
				if(h != -1)
				{
					if(h < min_hit_distance)
					{
						min_hit_distance = h;
						hit_index = z;
					}
				}
			}
			if(hit_index != -100)
			{
				if(hit_index == -1) //���
					Shell_hit(enemy_tanks[i], tank1);
				else
					Shell_hit(enemy_tanks[i], allience_tanks[hit_index]);
			}
			
		}
	}

	//�Ѿ��ڵ�
	for(int i = 0; i < NUM_OF_ALLIENCE; i++)
	{
		if(allience_tanks[i].shell_on_field) 
		{
			allience_tanks[i].shells_move();
			allience_tanks[i].out_process();

			int hit_index = -100;
			int min_hit_distance = 9999;

			for(int z = 0; allience_tanks[i].shell_on_field && z < NUM_OF_ENEMY; z++ )
			{
				int h = Shell_try_hit(allience_tanks[i], enemy_tanks[z]);
				if(h != -1)
				{
					if(h < min_hit_distance)
					{
						min_hit_distance = h;
						hit_index = z;
					}
				}
			}
			if(hit_index != -100)
				Shell_hit(allience_tanks[i], enemy_tanks[hit_index]);
		}
	}

}

//�������� ���� ����
void C̹�˴�սϵ��Dlg::Command_Update(void)
{
	//�����˽�������
	//�߼��ڶ�����  �ҷ��͵з�̹�˵��ƶ�  �� ���ڲ���
	//���̹�������Ͳ��ж���ըӰ���� -- ��ը�����ڵ�Ч���ж�-- �� ��һ֡�����жϱ�ը


 	if(tank1.current_hitpoint) // ������
	{
		if(tank1.is_hit)//������ -- �쳣״̬�ж�
		{
			//��������˺� -- �����������
			if(BEHIND == tank1.last_hit_orient && tank1.last_hit_result != UNPENERTRATE)
			{
				int engine_hit = rand()%100;
				if(engine_hit < tank1.engine_damage_rate && tank1.is_engine_damage == 0)
				{
					tank1.is_engine_damage = 1;
					tank1.Accelerate_Power /=  2;
					tank1.Max_Speed /= 2;
					tank1.route_interval *= 2;
					damage_report(ENGINE_DAMAGED);
					SetTimer(20, ENGINE_REPAIR_TIME, NULL);
					tank1.t_last_fital_hit = Dialog_current_clock;
				}
				tank1.t_last_effect_hit = Dialog_current_clock;
			}
			//��������˺� -- ���ڸ�������
			else if(FRONT == tank1.last_hit_orient && tank1.last_hit_result != UNPENERTRATE)
			{
				int gun_hit = rand()%100;
				if(gun_hit < tank1.gun_damage_rate * 3 && tank1.is_gun_damage == 0)
				{
					tank1.is_gun_damage = 1;
					tank1.t_last_gun_hit = Dialog_current_clock;
					tank1.damage *= 2;
					tank1.damage /= 3;
					tank1.fire_interval *= 3;
					tank1.fire_interval /= 2;
					damage_report(GUN_DAMAGED);
					SetTimer(21, GUN_REPAIR_TIME, NULL);
				}
				tank1.t_last_effect_hit = Dialog_current_clock;
			}
			//�������
			else if(SIDE == tank1.last_hit_orient && tank1.last_hit_result != UNPENERTRATE)
			{
				tank1.t_last_effect_hit = Dialog_current_clock;
			}
		}
		tank1.Tank_Control_Normal();
		int is_ram = 0;
		for(int u = 0; u < NUM_OF_ENEMY && ! is_ram; u++)
		{
			if(enemy_tanks[u].current_hitpoint && enemy_tanks[u].is_on_field)
			{
				if(try_ram(tank1, enemy_tanks[u]) == 1)
					is_ram = 1;
			}
		}
	}




#ifdef USE_ALLIENCE
	for(int i = 0; i < NUM_OF_ALLIENCE; i++)
	{
		if(allience_tanks[i].is_on_field && allience_tanks[i].current_hitpoint || allience_tanks[i].shell_on_field)
		{
			if(allience_tanks[i].current_hitpoint)
			{
				if(allience_tanks[i].is_hit) //������
				{
					if(!allience_tanks[i].is_engine_damage && BEHIND == allience_tanks[i].last_hit_orient && allience_tanks[i].last_hit_result != UNPENERTRATE)
					{
						int engine_hit = rand()%100;
						if(engine_hit < allience_tanks[i].engine_damage_rate)
						{
						//allience_tanks[i].t_last_fital_hit = current_clock;
							allience_tanks[i].Accelerate_Power /= 2;
							allience_tanks[i].Max_Speed /= 2;
							allience_tanks[i].route_interval *= 2.5;
							allience_tanks[i].is_engine_damage = 1;
						}
					}
					if(!allience_tanks[i].is_gun_damage && FRONT == allience_tanks[i].last_hit_orient && allience_tanks[i].last_hit_result != UNPENERTRATE)
					{
						int gun_hit = rand()%100;
						if(gun_hit < 2 * allience_tanks[i].gun_damage_rate)
						{
							allience_tanks[i].is_gun_damage = 1;
							allience_tanks[i].damage *= 2;
							allience_tanks[i].damage /= 3;

							allience_tanks[i].fire_interval *= 3;
							allience_tanks[i].fire_interval /= 2;
						}
					}
				}
				if(allience_tanks[i].rc == NORMAL)
					allience_tanks[i].Tank_Control_Normal();
				else if(allience_tanks[i].rc == ELITE)
				{
					if(!enemy_tanks[allience_tanks[i].target_index].current_hitpoint || !enemy_tanks[allience_tanks[i].target_index].is_on_field) //��ǰ�з�Ŀ���������ڳ�
					{
						int min_dis = 99999;
						int dis;
						for(int j = 0; j < NUM_OF_ENEMY; j++)
						{
							if(enemy_tanks[j].is_on_field && enemy_tanks[j].current_hitpoint)
							{
								dis = abs(allience_tanks[i].pos_x - enemy_tanks[j].pos_x) + abs(allience_tanks[i].pos_y - enemy_tanks[j].pos_y);
								if(dis < min_dis)
								{
									allience_tanks[i].target_index = j;
									min_dis = dis;
								}
							}
						}
					}
					allience_tanks[i].Tank_Control_ELITE(enemy_tanks[allience_tanks[i].target_index].pos_x, enemy_tanks[allience_tanks[i].target_index].pos_y);
				}
				else if(allience_tanks[i].rc == NOOB)
					;

				else if(allience_tanks[i].rc == VP) //�������� 
				{
					//��������ŵĵо�
					int min_dis = 99999;
					int dis;
					for(int j = 0; j < NUM_OF_ENEMY; j++)
					{
						if(enemy_tanks[j].is_on_field && enemy_tanks[j].current_hitpoint)
						{
							dis = abs(allience_tanks[i].pos_x - enemy_tanks[j].pos_x) + abs(allience_tanks[i].pos_y - enemy_tanks[j].pos_y);
							if(dis < min_dis)
							{
								allience_tanks[i].target_index = j;
								min_dis = dis;
							}
						}
					}
					allience_tanks[i].Tank_Control_VP(enemy_tanks[allience_tanks[i].target_index].pos_x, enemy_tanks[allience_tanks[i].target_index].pos_y);
				}
				else if(allience_tanks[i].rc == MASTER) //��ʦ����
				{
					if(alliences * 1.4 >= enemys)
					{
						allience_tanks[i].Vp_range = 5000;
					}
					int min_dis = 99999;
					int dis;
					for(int j = 0; j < NUM_OF_ENEMY; j++)
					{
						if(enemy_tanks[j].is_on_field && enemy_tanks[j].current_hitpoint)
						{
							dis = abs(allience_tanks[i].pos_x - enemy_tanks[j].pos_x) + abs(allience_tanks[i].pos_y - enemy_tanks[j].pos_y);
							if(dis < min_dis)
							{
								allience_tanks[i].target_index = j;
								min_dis = dis;
							}
						}
					}
					

					allience_tanks[i].Tank_Control_VP(enemy_tanks[allience_tanks[i].target_index].pos_x, enemy_tanks[allience_tanks[i].target_index].pos_y);
				}
				else if(allience_tanks[i].rc == TURRET) //��������
				{
					//��������ŵĵо�
					int min_dis = 99999;
					int dis;
					for(int j = 0; j < NUM_OF_ENEMY; j++)
					{
						if(enemy_tanks[j].is_on_field && enemy_tanks[j].current_hitpoint)
						{
							dis = abs(allience_tanks[i].pos_x - enemy_tanks[j].pos_x) + abs(allience_tanks[i].pos_y - enemy_tanks[j].pos_y);
							if(dis < min_dis)
							{
								allience_tanks[i].target_index = j;
								min_dis = dis;
							}
						}
					}
					allience_tanks[i].Tank_Control_Turret(enemy_tanks[allience_tanks[i].target_index].pos_x, enemy_tanks[allience_tanks[i].target_index].pos_y);

				}
				else if(allience_tanks[i].rc == PROTEND) //�𹥲��� 
				{
					//��������ŵĵо�
					int min_dis = 99999;
					int dis;
					for(int j = 0; j < NUM_OF_ENEMY; j++)
					{
						if(enemy_tanks[j].is_on_field && enemy_tanks[j].current_hitpoint)
						{
							dis = abs(allience_tanks[i].pos_x - enemy_tanks[j].pos_x) + abs(allience_tanks[i].pos_y - enemy_tanks[j].pos_y);
							if(dis < min_dis)
							{
								allience_tanks[i].target_index = j;
								min_dis = dis;
							}
						}
					}
					allience_tanks[i].Tank_Control_Ambush(enemy_tanks[allience_tanks[i].target_index].pos_x, enemy_tanks[allience_tanks[i].target_index].pos_y);
				}
				else if(allience_tanks[i].rc == PROTECT) // ��������
				{
					//��������
					int p_x;
					int p_y;
					if(allience_tanks[i].protect_index == -1)
					{
						p_x = tank1.pos_x;
						p_y = tank1.pos_y;
					}
					else
					{
						p_x = allience_tanks[allience_tanks[i].protect_index].pos_x;
						p_y = allience_tanks[allience_tanks[i].protect_index].pos_y;
					}
					//Ŀ��ѡ�����
					int min_dis = 99999;
					int dis;
					for(int j = 0; j < NUM_OF_ENEMY; j++)
					{
						if(enemy_tanks[j].is_on_field && enemy_tanks[j].current_hitpoint)
						{
							dis = abs(allience_tanks[i].pos_x - enemy_tanks[j].pos_x) + abs(allience_tanks[i].pos_y - enemy_tanks[j].pos_y);
							if(dis < min_dis)
							{
								allience_tanks[i].target_index = j;
								min_dis = dis;
							}
						}
					}
					allience_tanks[i].Tank_Control_Protect(p_x, p_y, enemy_tanks[allience_tanks[i].target_index].pos_x, enemy_tanks[allience_tanks[i].target_index].pos_y);
				}
				int is_ram = 0;
				for(int u = 0; u < NUM_OF_ENEMY && ! is_ram; u++)
				{
					if(enemy_tanks[u].current_hitpoint && enemy_tanks[u].is_on_field)
					{
						if(try_ram(allience_tanks[i], enemy_tanks[u]) == 1)
							is_ram = 1;
					}
				}
			}

		}
	}

#endif

	for(int i = 0; i < NUM_OF_ENEMY; i++)
	{
		if(enemy_tanks[i].is_on_field && enemy_tanks[i].current_hitpoint || enemy_tanks[i].shell_on_field)
		{
			if(enemy_tanks[i].current_hitpoint)
			{
				if(enemy_tanks[i].is_hit) //������
				{
					//û���� �Ƿ񱻱��ֻ�
					if(!enemy_tanks[i].is_engine_damage && BEHIND == enemy_tanks[i].last_hit_orient && enemy_tanks[i].last_hit_result != UNPENERTRATE)
					{
						//enemy_tanks[i].t_last_fital_hit = current_clock;
						int engine_hit = rand()%100;
						if(engine_hit < enemy_tanks[i].engine_damage_rate)
						{
							enemy_tanks[i].Accelerate_Power /= 2;
							enemy_tanks[i].Max_Speed /= 2;
							enemy_tanks[i].route_interval *= 2.5;
							enemy_tanks[i].is_engine_damage = 1;
						}
					}
					//û���� �Ƿ񱻱�����
					if(!enemy_tanks[i].is_gun_damage && FRONT == enemy_tanks[i].last_hit_orient && enemy_tanks[i].last_hit_result != UNPENERTRATE)
					{
						int gun_hit = rand()%100;
						if(gun_hit < 2 * enemy_tanks[i].gun_damage_rate)
						{
							enemy_tanks[i].is_gun_damage = 1;
							enemy_tanks[i].damage *= 2;
							enemy_tanks[i].damage /= 3;

							enemy_tanks[i].fire_interval *= 3;
							enemy_tanks[i].fire_interval /= 2;
						}
					}
				}
				if(enemy_tanks[i].rc == NORMAL)
					enemy_tanks[i].Tank_Control_Normal();
				else if(enemy_tanks[i].rc == ELITE)
				{
					if(-1 == enemy_tanks[i].target_index)
						enemy_tanks[i].Tank_Control_ELITE(tank1.pos_x, tank1.pos_y);
					else if(!alliences)
						enemy_tanks[i].Tank_Control_ELITE(tank1.pos_x, tank1.pos_y);
					else if(!allience_tanks[enemy_tanks[i].target_index].is_on_field || !allience_tanks[enemy_tanks[i].target_index].current_hitpoint) //��ǰ�з�Ŀ������
					{
						int min_dis = 99999;
						int dis;
						for(int j = 0; j < NUM_OF_ALLIENCE; j++)
						{
							if(allience_tanks[j].is_on_field && allience_tanks[j].current_hitpoint)
							{
								dis = abs(enemy_tanks[i].pos_x - allience_tanks[j].pos_x) + abs(enemy_tanks[i].pos_y - allience_tanks[j].pos_y);
								if(dis < min_dis)
								{
									enemy_tanks[i].target_index = j;
									min_dis = dis;
								}
							}
						}
						enemy_tanks[i].Tank_Control_ELITE(allience_tanks[enemy_tanks[i].target_index].pos_x, allience_tanks[enemy_tanks[i].target_index].pos_y);
					}
					else
						enemy_tanks[i].Tank_Control_ELITE(allience_tanks[enemy_tanks[i].target_index].pos_x, allience_tanks[enemy_tanks[i].target_index].pos_y);
				}
				else if(enemy_tanks[i].rc == NOOB)  //����
					;
				else if(enemy_tanks[i].rc == VP) // �߼����ز���
				{
					int min_dis = 99999;
					int dis;
					for(int j = 0; j < NUM_OF_ALLIENCE; j++)
					{
						if(allience_tanks[j].is_on_field && allience_tanks[j].current_hitpoint)
						{
							dis = abs(enemy_tanks[i].pos_x - allience_tanks[j].pos_x) + abs(enemy_tanks[i].pos_y - allience_tanks[j].pos_y);
							if(dis < min_dis)
							{
								enemy_tanks[i].target_index = j;
								min_dis = dis;
							}
						}
					}
					//��Ҹ���
					dis = abs(enemy_tanks[i].pos_x - tank1.pos_x) + abs(enemy_tanks[i].pos_y - tank1.pos_y);
					if(dis < min_dis)
					{
						enemy_tanks[i].target_index = -1;
					}
					if(enemy_tanks[i].target_index != -1)
						enemy_tanks[i].Tank_Control_VP(allience_tanks[enemy_tanks[i].target_index].pos_x, allience_tanks[enemy_tanks[i].target_index].pos_y);
					else 
						enemy_tanks[i].Tank_Control_VP(tank1.pos_x, tank1.pos_y);
				}
				else if(enemy_tanks[i].rc == MASTER) //��ʦ����
				{
					if(enemys >= alliences)
					{
						if(-1 == enemy_tanks[i].target_index)
						enemy_tanks[i].Tank_Control_ELITE(tank1.pos_x, tank1.pos_y);
						else if(!alliences)
							enemy_tanks[i].Tank_Control_ELITE(tank1.pos_x, tank1.pos_y);
						else if(!allience_tanks[enemy_tanks[i].target_index].is_on_field || !allience_tanks[enemy_tanks[i].target_index].current_hitpoint) //��ǰ�з�Ŀ������
						{
							int min_dis = 99999;
							int dis;
							for(int j = 0; j < NUM_OF_ALLIENCE; j++)
							{
								if(allience_tanks[j].is_on_field && allience_tanks[j].current_hitpoint)
								{
									dis = abs(enemy_tanks[i].pos_x - allience_tanks[j].pos_x) + abs(enemy_tanks[i].pos_y - allience_tanks[j].pos_y);
									if(dis < min_dis)
									{
										enemy_tanks[i].target_index = j;
										min_dis = dis;
									}
								}
							}
							enemy_tanks[i].Tank_Control_ELITE(allience_tanks[enemy_tanks[i].target_index].pos_x, allience_tanks[enemy_tanks[i].target_index].pos_y);
						}
						else
							enemy_tanks[i].Tank_Control_ELITE(allience_tanks[enemy_tanks[i].target_index].pos_x, allience_tanks[enemy_tanks[i].target_index].pos_y);
					}
					else
					{
						int min_dis = 99999;
						int dis;
						for(int j = 0; j < NUM_OF_ALLIENCE; j++)
						{
							if(allience_tanks[i].is_on_field && allience_tanks[j].current_hitpoint)
							{
								dis = abs(enemy_tanks[i].pos_x - allience_tanks[j].pos_x) + abs(enemy_tanks[i].pos_y - allience_tanks[j].pos_y);
								if(dis < min_dis)
								{
									enemy_tanks[i].target_index = j;
									min_dis = dis;
								}
							}
						}
						//��Ҹ���
						dis = abs(enemy_tanks[i].pos_x - tank1.pos_x) + abs(enemy_tanks[i].pos_y - tank1.pos_y);
						if(dis < min_dis)
						{
							enemy_tanks[i].target_index = -1;
						}
						if(enemy_tanks[i].target_index != -1)
							enemy_tanks[i].Tank_Control_VP(allience_tanks[enemy_tanks[i].target_index].pos_x, allience_tanks[enemy_tanks[i].target_index].pos_y);
						else 
							enemy_tanks[i].Tank_Control_VP(tank1.pos_x, tank1.pos_y);
					}
				}
				else if(enemy_tanks[i].rc == TURRET) // ��������
				{
					int min_dis = 99999;
					int dis;
					for(int j = 0; j < NUM_OF_ALLIENCE; j++)
					{
						if(allience_tanks[j].is_on_field && allience_tanks[j].current_hitpoint)
						{
							dis = abs(enemy_tanks[i].pos_x - allience_tanks[j].pos_x) + abs(enemy_tanks[i].pos_y - allience_tanks[j].pos_y);
							if(dis < min_dis)
							{
								enemy_tanks[i].target_index = j;
								min_dis = dis;
							}
						}
					}
					//��Ҹ���
					dis = abs(enemy_tanks[i].pos_x - tank1.pos_x) + abs(enemy_tanks[i].pos_y - tank1.pos_y);
					if(dis < min_dis)
					{
						enemy_tanks[i].target_index = -1;
					}
					if(enemy_tanks[i].target_index != -1)
						enemy_tanks[i].Tank_Control_Turret(allience_tanks[enemy_tanks[i].target_index].pos_x, allience_tanks[enemy_tanks[i].target_index].pos_y);
					else 
						enemy_tanks[i].Tank_Control_Turret(tank1.pos_x, tank1.pos_y);
				}
				else if(enemy_tanks[i].rc == PROTEND) // �𹥲���
				{
					int min_dis = 99999;
					int dis;
					for(int j = 0; j < NUM_OF_ALLIENCE; j++)
					{
						if(allience_tanks[j].is_on_field && allience_tanks[j].current_hitpoint)
						{
							dis = abs(enemy_tanks[i].pos_x - allience_tanks[j].pos_x) + abs(enemy_tanks[i].pos_y - allience_tanks[j].pos_y);
							if(dis < min_dis)
							{
								enemy_tanks[i].target_index = j;
								min_dis = dis;
							}
						}
					}
					//��Ҹ���
					dis = abs(enemy_tanks[i].pos_x - tank1.pos_x) + abs(enemy_tanks[i].pos_y - tank1.pos_y);
					if(dis < min_dis)
					{
						enemy_tanks[i].target_index = -1;
					}
					if(enemy_tanks[i].target_index != -1)
						enemy_tanks[i].Tank_Control_Ambush(allience_tanks[enemy_tanks[i].target_index].pos_x, allience_tanks[enemy_tanks[i].target_index].pos_y);
					else 
						enemy_tanks[i].Tank_Control_Ambush(tank1.pos_x, tank1.pos_y);
				}
				else if(enemy_tanks[i].rc == PROTECT) // ��������
				{
					//��������
					int p_x;
					int p_y;
					p_x = enemy_tanks[i].pos_x;
					p_y = enemy_tanks[i].pos_y;
				
					//Ŀ��ѡ�����
					int min_dis = 99999;
					int dis;
					for(int j = 0; j < NUM_OF_ALLIENCE; j++)
					{
						if(allience_tanks[j].is_on_field && allience_tanks[j].current_hitpoint)
						{
							dis = abs(enemy_tanks[i].pos_x - allience_tanks[j].pos_x) + abs(enemy_tanks[i].pos_y - allience_tanks[j].pos_y);
							if(dis < min_dis)
							{
								enemy_tanks[i].target_index = j;
								min_dis = dis;
							}
						}
					}
					//��Ҹ���
					dis = abs(enemy_tanks[i].pos_x - tank1.pos_x) + abs(enemy_tanks[i].pos_y - tank1.pos_y);
					if(dis < min_dis)
					{
						enemy_tanks[i].target_index = -1;
					}
					if(enemy_tanks[i].target_index != -1)
						enemy_tanks[i].Tank_Control_Protect(p_x, p_y, allience_tanks[enemy_tanks[i].target_index].pos_x, allience_tanks[enemy_tanks[i].target_index].pos_y);
					else 
						enemy_tanks[i].Tank_Control_Protect(p_x, p_y, tank1.pos_x, tank1.pos_y);
				}
				int is_ram = 0;
				try_ram(enemy_tanks[i], tank1);

				for(int u = 0; u < NUM_OF_ALLIENCE && ! is_ram; u++)
				{
					if(allience_tanks[u].current_hitpoint && allience_tanks[u].is_on_field)
					{
						if(try_ram(enemy_tanks[i], allience_tanks[u]) == 1)
							is_ram = 1;
					}
				}
			}
		

		}
	}

}

//ʤ���ж� ����
int  C̹�˴�սϵ��Dlg::Win_Lose_Judge(void) //-1Ϊʧ�� 1Ϊʤ�� 0 Ϊ����
{
	//ʧ������
	//�����ݻ� �ض� ʧ��
	if(0 == tank1.current_hitpoint)
	{
		//if(current_stage != 101)
		return -1;
		//101�� �������޸���
	}
	//��ҩ�þ�
	else if(D_NSH == c_d_t && Player_Tank::use_shell > d_addtion_param)
		return -1;
	else if(D_TLE == c_d_t && clock() >= d_addtion_param)
		return -1;
	else if(D_LVP == c_d_t && !allience_tanks[0].current_hitpoint)
		return -1;
	else if(D_LNA == c_d_t && NUM_OF_ALLIENCE - all_alliences > d_addtion_param)
		return -1;



	//ʤ������
	if(!all_enemys)
	{
		if(c_d_t == D_DLD && tank1.dmg_cause < d_addtion_param)
		{
			return -1;
		}
		else
			return 1;
	}
	else if(c_v_t == V_TLE && clock() >= v_addtion_param)
		return 1;
	else if(c_v_t == V_KNE && NUM_OF_ENEMY - all_enemys >= v_addtion_param)
		return 1;
	else if(c_v_t == V_KVP && !enemy_tanks[0].current_hitpoint)
		return 1;

	else
		return 0;
}
// 1010
void C̹�˴�սϵ��Dlg::Explose_Effect(void)
{
	//��ըֻӰ���Ѿ�����Ȼ��û��ײ���ˣ�
	for(int i = 0; i < NUM_OF_ALLIENCE; i++)
	{
		if(allience_tanks[i].is_on_field && allience_tanks[i].is_explose == 0 && allience_tanks[i].current_hitpoint == 0)
		{
			allience_tanks[i].is_explose = 1;
			int x = allience_tanks[i].pos_x;
			int y = allience_tanks[i].pos_y;
			for(int j = 0; j < NUM_OF_ALLIENCE; j++)
			{
				//�����ڳ�
				if(allience_tanks[j].is_on_field && allience_tanks[j].current_hitpoint)
				{
					int d = abs(allience_tanks[j].pos_x - x) + abs(allience_tanks[j].pos_y - y);
					if(d < EXPLOSE_RANGE) //���˺�
					{
						int dmg = allience_tanks[i].last_hit;
						//���
						if(dmg > allience_tanks[i].max_hitpoint)
							dmg = allience_tanks[i].max_hitpoint;

						dmg /= INI_EXPLOSE_DMG_X;
						dmg = dmg * (EXPLOSE_RANGE - d)/EXPLOSE_RANGE;

						//�˺�
						allience_tanks[j].current_hitpoint -= dmg;
						allience_tanks[j].current_max_hitpoint -= dmg / 2;
						if(allience_tanks[j].current_hitpoint < 0)
						{
							allience_tanks[j].current_hitpoint = 0;
							allience_tanks[j].die_time = Dialog_current_clock + 80; //�Ӻ�

						}
						
						if(allience_tanks[j].current_max_hitpoint < 0)
							allience_tanks[j].current_max_hitpoint = 0;

						allience_tanks[j].is_hit = dmg;
						allience_tanks[j].last_hit = dmg;
						allience_tanks[j].t_last_hit = Dialog_current_clock + 80;

						if(d > EXPLOSE_RANGE * 2 / 3)
							allience_tanks[j].last_hit_result = UNPENERTRATE;
						else if(d > EXPLOSE_RANGE * 1 / 3)
							allience_tanks[j].last_hit_result = PENERTRATED;
						else
							allience_tanks[j].last_hit_result = EFFECTIVE_PENERTRATED;
					}
				}
			}

		}
	}

	for(int i = 0; i < NUM_OF_ENEMY; i++)
	{
		if(enemy_tanks[i].is_on_field && enemy_tanks[i].is_explose == 0 && enemy_tanks[i].current_hitpoint == 0)
		{
			enemy_tanks[i].is_explose = 1;
			int x = enemy_tanks[i].pos_x;
			int y = enemy_tanks[i].pos_y;
			for(int j = 0; j < NUM_OF_ENEMY; j++)
			{
				//�����ڳ�
				if(enemy_tanks[j].is_on_field && enemy_tanks[j].current_hitpoint)
				{
					int d = abs(enemy_tanks[j].pos_x - x) + abs(enemy_tanks[j].pos_y - y);
					if(d < EXPLOSE_RANGE) //���˺�
					{
						int dmg = enemy_tanks[i].last_hit;
						//���
						if(dmg > enemy_tanks[i].max_hitpoint)
							dmg = enemy_tanks[i].max_hitpoint;

						dmg /= INI_EXPLOSE_DMG_X;
						dmg = dmg * (EXPLOSE_RANGE - d)/EXPLOSE_RANGE;

						//�˺�
						enemy_tanks[j].current_hitpoint -= dmg;
						enemy_tanks[j].current_max_hitpoint -= dmg / 2;
						if(enemy_tanks[j].current_hitpoint < 0)
						{
							enemy_tanks[j].current_hitpoint = 0;
							enemy_tanks[j].die_time = Dialog_current_clock + 80; //�Ӻ�

						}
						
						if(enemy_tanks[j].current_max_hitpoint < 0)
							enemy_tanks[j].current_max_hitpoint = 0;

						enemy_tanks[j].is_hit = dmg;
						enemy_tanks[j].last_hit = dmg;
						enemy_tanks[j].t_last_hit = Dialog_current_clock + 80;

						if(d > EXPLOSE_RANGE * 2 / 3)
							enemy_tanks[j].last_hit_result = UNPENERTRATE;
						else if(d > EXPLOSE_RANGE * 1 / 3)
							enemy_tanks[j].last_hit_result = PENERTRATED;
						else
							enemy_tanks[j].last_hit_result = EFFECTIVE_PENERTRATED;
					}
				}
			}

		}
	}
}
void C̹�˴�սϵ��Dlg::Query_Events(void)
{
	clock_t current_clock = clock();
	//����ؿ� �Ѿ� �о��ļ���ս�� 

	if(current_stage == 100)
	{
		if(h <= 30 && (enemys == 0 || current_clock - last_enemy_send >= 32000)) 
		{
			for(int i = 0; i < 10; i ++)
			{
				enemy_tanks[10 * (h-1) + i].is_on_field = 1;
			}
			last_enemy_send = current_clock;
			h += 1;
		}
	}

	else if(current_stage == 101)
	{
		if(h <= 30 && enemys == 0) 
		{
			for(int i = 0; i < 12; i ++)
			{
				enemy_tanks[12 * (h-1) + i].is_on_field = 1;
	//			allience_tanks[10 * (h-1) + i].is_on_field = 1;
			}
			//last_enemy_send = current_clock;
			h += 1;
		}
		if(a_h <= 30 && alliences == 0) 
		{
			for(int i = 0; i < 10; i ++)
			{
		//		enemy_tanks[10 * (a_h-1) + i].is_on_field = 1;
				allience_tanks[10 * (a_h-1) + i].is_on_field = 1;
			}
			//last_enemy_send = current_clock;
			a_h += 1;
		}
	}


	else if(current_stage == -1)
	{
		if(h <= 9 && (enemys == 0 || current_clock - last_enemy_send >= 8000))
		{
			enemy_tanks[2 * (h-1)].pos_x = rand() % 2899 + 50; 
			enemy_tanks[2 * (h-1)].pos_y = rand() % 1899 + 50;
			enemy_tanks[2 * (h-1)].is_on_field = 1;

			enemy_tanks[2 * (h-1) + 1].pos_x = rand() % 2899 + 50; 
			enemy_tanks[2 * (h-1) + 1].pos_y = rand() % 1899 + 50;
			enemy_tanks[2 * (h-1) + 1].is_on_field = 1;

			/*
			enemy_tanks[2 * (h-1) + 2].pos_x = rand() % 2899 + 50; 
			enemy_tanks[2 * (h-1) + 2].pos_y = rand() % 1899 + 50;
			enemy_tanks[2 * (h-1) + 2].is_on_field = 1;
			*/
			last_enemy_send = current_clock;
			h += 1;
		}
	}



	else if(current_stage == 7) //���߹� ��������
	{
		if(h < 4 && (clock() - stage_begin_time >= 25000 * h * ROUTE_NERF || enemys == 0))
		{
			if(h == 1)
			{
				enemy_tanks[1].is_on_field = 1;
				enemy_tanks[2].is_on_field = 1;
				enemy_tanks[1].pos_y = tank1.pos_y + 150;
				enemy_tanks[2].pos_y = tank1.pos_y + 50;
				
				for(int i = 1; i <= 2; i ++)
				{
					if(enemy_tanks[i].pos_y > 1950)
						enemy_tanks[i].pos_y = 1950;
				}				
				
			}
			else if(h == 2)
			{
				enemy_tanks[3].is_on_field = 1;
				enemy_tanks[4].is_on_field = 1;
				enemy_tanks[5].is_on_field = 1;
				enemy_tanks[3].pos_y = tank1.pos_y + 150;
				enemy_tanks[4].pos_y = tank1.pos_y + 100;
				enemy_tanks[5].pos_y = tank1.pos_y + 50;
				
				for(int i = 3; i <= 5; i ++)
				{
					if(enemy_tanks[i].pos_y > 1950)
						enemy_tanks[i].pos_y = 1950;
				}	
				
			}
			else if(h == 3)
			{
				enemy_tanks[6].is_on_field = 1;
				enemy_tanks[7].is_on_field = 1;
				enemy_tanks[8].is_on_field = 1;
				enemy_tanks[9].is_on_field = 1;
				enemy_tanks[6].pos_y = tank1.pos_y + 200;
				enemy_tanks[7].pos_y = tank1.pos_y + 150;
				enemy_tanks[8].pos_y = tank1.pos_y + 100;
				enemy_tanks[9].pos_y = tank1.pos_y + 50;
				
				for(int i = 6; i <= 9; i ++)
				{
					if(enemy_tanks[i].pos_y > 1950)
						enemy_tanks[i].pos_y = 1950;
				}		
				

			}
			h += 1;
			last_enemy_send = clock();
		}
		else if( h == 4 && allience_is_send && enemys == 0)
		{
			h += 1;
			for(int i = 10; i < NUM_OF_ENEMY; i++)
				enemy_tanks[i].is_on_field = 1;
		}
		
		if(tank1.kill >= 6 && !allience_is_send)
		{
			allience_is_send += 1;
			for(int i = 0; i < 10; i++)
				allience_tanks[i].is_on_field = 1;
		}
		else if(h == 5 && !alliences)
		{
			allience_is_send += 1;
			for(int i = 10; i < NUM_OF_ALLIENCE; i++)
				allience_tanks[i].is_on_field = 1;

		}

	}

	//��۵糸 �򵥵ĵо����� h��ֵΪ1
	else if(current_stage == 8)
	{
	  
		// h ���� 63��
		if(h <= 63 && enemys < 4)
		{
			enemy_tanks[h + 8].is_on_field = 1;
			h += 1;
		}
	}


	//�ھŹ� ����������³
	else if(current_stage == 9) // h = 1 
	{
		//�з�֧Ԯ���� ֧Ԯ�� h = 1 - h = 6
		if (h <= 6 && (enemys <= 5 || current_clock - last_enemy_send >= 15000 * ROUTE_NERF))
		{
			enemy_tanks[(3*h) + 9].is_on_field = 1;
			enemy_tanks[(3*h) + 10].is_on_field = 1;
			enemy_tanks[(3*h) + 11].is_on_field = 1;
			h += 1;
			last_enemy_send = current_clock;
		}
		if (allience_is_send < 3 && current_clock - last_allience_send >= 7500 * ROUTE_NERF)
		{

			allience_tanks[(3 * allience_is_send) + 3].is_on_field = 1;
			allience_tanks[(3 * allience_is_send) + 4].is_on_field = 1;
			allience_tanks[(3 * allience_is_send) + 5].is_on_field = 1;
			allience_is_send += 1;
			last_allience_send = current_clock;
		}
	}
	//��ʮ�� ���ﳤ�ǹ���ս
	else if(current_stage == 10)
	{
		//�ҷ� ֧Ԯ 4 �� 
		if (h <= 3 && current_clock - last_allience_send >= 6000 * ROUTE_NERF)
		{
			for(int i = 0;i < 18; i++)
			{
				allience_tanks[18 * (h - 1) + i].is_on_field = 1;
			}
			h += 1;
			last_allience_send = current_clock;
		}
	}
	//��ʮһ�� ���ﳤ�ǹ���ս
	else if(current_stage == 11)
	{
	  
		// h ���� 15��
		if (h <= 20 && ((current_clock - last_enemy_send >= (15000 - 500 * h) * ROUTE_NERF || !enemys)))
		{
			for(int i = 0;i < 18; i++)
			{
				enemy_tanks[18 * (h - 1) + i].is_on_field = 1;
			}
			h += 1;
			last_enemy_send = current_clock;
			//enemy_tanks[h + 8].is_on_field = 1;
			//h += 1;
		}
		if(allience_is_send  == 0 && current_clock - stage_begin_time >= 150000 * ROUTE_NERF)
		{
			for(int i = 14; i < NUM_OF_ALLIENCE; i ++)
			{
				allience_tanks[i].is_on_field = 1;
			}
			allience_is_send = 1;
		}
	}

	else if(current_stage == 12)
	{
	  
		// h ���� 10�� -- �ʼ�Ĵ������  7.5 �� ���� ������� 3 ��
		if(h <= 15 && ((current_clock - last_enemy_send >= (7500 - 300 * h))))
		{
			for(int i = 0;i < 8; i++)
			{
				int index = 8 * (h - 1) + i;
				enemy_tanks[index].is_on_field = 1;
				if(i < 2)
				{
					enemy_tanks[index].pos_x = allience_tanks[0].pos_x;
					enemy_tanks[index].pos_y = allience_tanks[0].pos_y - 400;
					if(enemy_tanks[index].pos_y < 50)
						enemy_tanks[index].pos_y = 50;
				}
				else if(i < 4)
				{
					enemy_tanks[index].pos_x = allience_tanks[0].pos_x;
					enemy_tanks[index].pos_y = allience_tanks[0].pos_y + 400;
					if(enemy_tanks[index].pos_y > 1950)
						enemy_tanks[index].pos_y = 1950;
				}
				else if(i < 6)
				{
					enemy_tanks[index].pos_x = allience_tanks[0].pos_x - 400;
					enemy_tanks[index].pos_y = allience_tanks[0].pos_y;
					if(enemy_tanks[index].pos_x < 50)
						enemy_tanks[index].pos_x = 50;
				}
				else 
				{
					enemy_tanks[index].pos_x = allience_tanks[0].pos_x + 400;
					enemy_tanks[index].pos_y = allience_tanks[0].pos_y;
					if(enemy_tanks[index].pos_x > 2950)
						enemy_tanks[index].pos_x = 2950;
				}

			}
			h += 1;
			last_enemy_send = current_clock;
		}
	}
	//�Ͱ������ж�
	else if(current_stage == 13)
	{
		if(h == 1 && current_clock - stage_begin_time >= 25000)
		{
			h = 2;
			for(int i = 0; i < NUM_OF_ENEMY; i++)
			{
				enemy_tanks[i].rc = VP;
				enemy_tanks[i].Vp_range = 3000;
			}
		}
	}
	//����ǿ��
	else if(current_stage == 14)
	{
		if(h < 9 && !enemys)
		{
			enemy_tanks[3 * h].is_on_field = 1;
			enemy_tanks[3 * h + 1].is_on_field = 1;
			enemy_tanks[3 * h + 2].is_on_field = 1;
			h += 1;

		}
		if(allience_is_send <= 9 && alliences < 7)
		{
			for(int i = NUM_OF_TEAMMATE + allience_is_send * 10; i < NUM_OF_TEAMMATE + 10 + allience_is_send * 10; i++)
			{
				allience_tanks[i].is_on_field = 1;
			}
			allience_is_send += 1;
		}
	}
	//���ս
	else if(current_stage == 15)
	{
		if(h < 11 && enemys <= 27)
		{
			for(int i = 0; i < 45; i ++)
			{
				enemy_tanks[45 * (h-1) + i].is_on_field = 1;
			}
			h += 1;
		}
		if(allience_is_send < 10 && alliences <= 35)
		{
			for(int i = 0; i < 44; i ++)
			{
				allience_tanks[44 * (allience_is_send) + 20 + i].is_on_field = 1;
			}
			allience_is_send += 1;
		}
	}
	// ��������
	else if(current_stage == 16)
	{
		if(h < 5 && (!enemys || current_clock -  last_enemy_send >= 75000))
		{
			for(int i = 0; i < 4; i ++)
			{
				enemy_tanks[4 * (h-1) + i].is_on_field = 1;
			}
			h += 1;
			last_enemy_send = current_clock;
		}
	}

}