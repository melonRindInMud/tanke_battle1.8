#include "stdafx.h"
#include "resource.h"
#include "my_resource.h"

clock_t last_kill = -9999;
int kill_stack = 0;

clock_t t_last_dmg_cause = -9999;
int last_dmg_cause = 0;



// v 1.6 ��ʼ����
// 1. �������ڵ����ٹ��� ���¿��Ի��б���Ŀ���bug -- �����
//�µĴ��� �� ���� ���Ȼ��� ������ ֮ǰ�� Զ���� �˺�˥�� �� ������ �˺����ӻ���
// �����ܹ�׼ȷ�ļ���� ����ʱ�ľ���
//�����ֿ� ���ڽ��ж��Ƿ����


int  Shell_try_hit(Tank& attacker, Tank& target)
{
	if(target.current_hitpoint == 0 || !target.is_on_field)
		return -1;
	int hit_index = 0;


	Shell& sh = attacker.shell_infor;
	int hit_distance_to_center = 0; //���о��� 0 - 52 0 ����ߵ�  ʵ����Ч�������� 47 ����
	int hit_distance = sh.distance; // ����ʱ�ڵ�ʵ�ʷ��о��� 

	//���ж��Ƿ����
	if(UP == sh.orient)  //������  ֮ǰ�� �� y + 100  x ����  y �� �� ��С
	{
		if( abs(target.pos_x - sh.pos_x) <= 52 
			&& target.pos_y <= sh.pos_y + sh.speed - sh.d_cut + 52 
			&& target.pos_y >= sh.pos_y - 52) //����Ŀ��
		{
			hit_index = 1;
			hit_distance -= (40 + target.pos_y - sh.pos_y);
			hit_distance_to_center = abs(target.pos_x - sh.pos_x);

			// ��  �� �� Ϊ �� ��  �� Ϊ ��  ����Ϊ ��
			if(UP == target.orient)
			{
				target.last_hit_orient = BEHIND;
			}
			else if(DOWN == target.orient)
			{
				target.last_hit_orient = FRONT;
			}
			else
			{
				target.last_hit_orient = SIDE;
			}
		}
	}
	else if(DOWN == sh.orient) 
	{
		if( abs(target.pos_x - sh.pos_x) <= 52 
			&& target.pos_y <= sh.pos_y + 52
			&& target.pos_y >= sh.pos_y - sh.speed + sh.d_cut- 52)
		{
			hit_index = 1;
			hit_distance -= sh.pos_y + 40 - target.pos_y; 
			hit_distance_to_center = abs(target.pos_x - sh.pos_x);


			if(UP == target.orient) // �� �� �� ���� �� �� ��ͷ ������Ϊ����
			{
				target.last_hit_orient = FRONT;

			}
			else if(DOWN == target.orient)
			{
				target.last_hit_orient = BEHIND;
			}
			else
			{
				target.last_hit_orient = SIDE;
			}
		}
	}
	else if(LEFT == sh.orient) // x֮ǰҪ����
	{
		if( abs(target.pos_y - sh.pos_y) <= 52
			&& target.pos_x <= sh.pos_x + sh.speed - sh.d_cut + 52
			&& target.pos_x >= sh.pos_x - 52)
		{
			hit_index = 1;
			hit_distance -= (40 + target.pos_x - sh.pos_x);
			hit_distance_to_center = abs(target.pos_y - sh.pos_y);

			if(LEFT == target.orient)// ��� ��Ϊ ���� ����Ϊͷ
			{
				target.last_hit_orient = BEHIND;
			}
			else if(RIGHT == target.orient)
			{
				target.last_hit_orient = FRONT;
			}
			else
			{
				target.last_hit_orient = SIDE;
			}
		}
	}
	else if(RIGHT == sh.orient)
	{
		if( abs(target.pos_y - sh.pos_y) <= 52
			&& target.pos_x <= sh.pos_x + 52
			&& target.pos_x >= sh.pos_x - sh.speed + sh.d_cut- 52)
		{
			hit_index = 1;
			hit_distance -= sh.pos_x + 40 - target.pos_x; 
			hit_distance_to_center = abs(target.pos_y - sh.pos_y);

			if(RIGHT == target.orient)
			{
				target.last_hit_orient = BEHIND;
			}
			else if(LEFT == target.orient)
			{
				target.last_hit_orient = FRONT;
			}
			else
			{
				target.last_hit_orient = SIDE;
			}
		}
	}



	if(hit_index) // �˺� ��������
		return hit_distance;	
	else
		return -1;
}


//��һ�� Ҫ ��������ÿ�صı���

bool rank(NPC_Tank& infor1, NPC_Tank& infor2)
{
	if(infor1.dmg_cause > infor2.dmg_cause)
		return 1;
	else if(infor1.dmg_cause < infor2.dmg_cause)
		return 0;
	else
	{
		if(infor1.dmg_recv > infor2.dmg_recv)
			return 1;
		else
			return 0;
	}
}
//485


int  try_ram(Tank& tank1, Tank& tank2)
{
#ifdef RAM
	//ײ���ж�
	int d_x = tank1.pos_x - tank2.pos_x;
	int d_y = tank1.pos_y - tank2.pos_y;
	clock_t current_clock = clock();
	static clock_t last_sound = 0;
	//����ٶ�
	int d_speed = 0;
	Orient ram_orient_for_tank1 = STOP;

	if(abs(d_y) < 80 && abs(d_x) < 80)
	{
		//��ײ���� �ж�ײ������ -- ��� 1��
		//����
		if(abs(d_y) >=  abs(d_x))
		{
			if(d_y >= 0)
				ram_orient_for_tank1 = UP;
			else 
				ram_orient_for_tank1 = DOWN;
		}
		//����
		else
		{
			if(d_x >= 0)
				ram_orient_for_tank1 = LEFT;
			else
				ram_orient_for_tank1 = RIGHT;
		}
		//�������� 0 1 2 3
		//����ٶ�
		if(tank1.orient == tank2.orient)
		{
			d_speed = abs(tank1.Current_Speed - tank2.Current_Speed);
		}
		else if((tank1.orient + tank2.orient == 1 || tank1.orient + tank2.orient == 5) && abs(tank1.orient - tank2.orient) == 1)
		{
			d_speed = tank1.Current_Speed + tank2.Current_Speed;
		}
		else
		{
			d_speed = sqrt((tank1.Current_Speed * tank1.Current_Speed) + (tank2.Current_Speed * tank2.Current_Speed));
		}
		int major = 0;
		if(tank1.max_hitpoint > tank2.max_hitpoint)
		{
			major = 1;
		}
		else
		{
			major = 2;
		}


		//�˺�
		int cause_destory = 0;

		tank1.current_hitpoint -= tank2.max_hitpoint / RAM_DMG_X * d_speed;
		tank1.is_hit = tank2.max_hitpoint / RAM_DMG_X * d_speed;
		tank1.last_hit = tank1.is_hit;
		tank1.t_last_hit = current_clock;
		tank1.last_hit_result = EFFECTIVE_PENERTRATED;

	

		tank2.current_hitpoint -= tank1.max_hitpoint / RAM_DMG_X * d_speed;
		tank2.is_hit = tank1.max_hitpoint / RAM_DMG_X * d_speed;
		tank2.last_hit = tank2.is_hit;
		tank2.t_last_hit = current_clock;
		tank2.last_hit_result = EFFECTIVE_PENERTRATED;

		//�˺�ͳ��
		tank1.dmg_cause += tank2.is_hit;
		tank2.dmg_cause += tank1.is_hit;

		if(tank1.current_hitpoint < 0)
		{
			tank2.kill += 1;
			tank2.dmg_cause += tank1.current_hitpoint;
			tank1.current_hitpoint = 0;
			tank1.die_time = current_clock;
			cause_destory = 1;
		}
		if(tank2.current_hitpoint < 0)
		{
			tank1.kill += 1;
			tank1.dmg_cause += tank2.current_hitpoint;
			tank2.current_hitpoint = 0;
			tank2.die_time = current_clock;
			cause_destory = 1;
		}

		//��Ч
		if(tank1.rc == PLAYER || tank2.rc == PLAYER && current_clock - last_sound >= 600)
		{
			if(cause_destory)
				my_sound_player(EXPLOSE_SOUND);
			else
				my_sound_player(BEHIND_HIT_SOUND);
			last_sound = current_clock;
		}

		//ǿ���ƶ�
		if(major == 1)
		{
			if(ram_orient_for_tank1 == UP)
				tank2.pos_y = tank1.pos_y - 80 - d_speed * FORCE_MOVE_INDEX;
			else if(ram_orient_for_tank1 == DOWN)
				tank2.pos_y = tank1.pos_y + 80 + d_speed * FORCE_MOVE_INDEX;
			else if(ram_orient_for_tank1 == LEFT)
				tank2.pos_x = tank1.pos_x - 80 - d_speed * FORCE_MOVE_INDEX;
			else if(ram_orient_for_tank1 == RIGHT)
				tank2.pos_x = tank1.pos_x + 80 + d_speed * FORCE_MOVE_INDEX;

			//��Խ��
			tank2.jam_process();
			
			tank1.Current_Speed /= 2;
			tank2.Current_Speed = 0;

		}
		else 
		{
			if(ram_orient_for_tank1 == UP)
				tank1.pos_y = tank2.pos_y + 80 + d_speed * FORCE_MOVE_INDEX;
			else if(ram_orient_for_tank1 == DOWN)
				tank1.pos_y = tank2.pos_y - 80 - d_speed * FORCE_MOVE_INDEX;
			else if(ram_orient_for_tank1 == LEFT)
				tank1.pos_x = tank2.pos_x + 80 + d_speed * FORCE_MOVE_INDEX;
			else if(ram_orient_for_tank1 == RIGHT)
				tank1.pos_x = tank2.pos_x - 80 - d_speed * FORCE_MOVE_INDEX;

			//��Խ��
			tank1.jam_process();
			
			tank1.Current_Speed = 0;
			tank2.Current_Speed /= 2;
			
		}
		return 1;
	}
	else
		return 0;
#else	
	return 0;
#endif

}

void  Shell_hit(Tank& attacker, Tank& target)
{
	int dmg_cause_except_this = attacker.dmg_cause;
	if(target.current_hitpoint == 0 || !target.is_on_field)
		return ;

	clock_t current_clock = clock();
	static clock_t last_sound = 0;
	float vdm = 0.4 * (rand()%100)/100.0 + 0.8;
	Shell& sh = attacker.shell_infor;
	int hit_index = 0;
	int hit_distance_to_center = 0; //���о��� 0 - 52 0 ����ߵ�  ʵ����Ч�������� 47 ����
	int hit_distance = sh.distance; // ����ʱ�ڵ�ʵ�ʷ��о��� 
	target.last_hit_from = sh.orient;


	//���ж��Ƿ����
	if(UP == sh.orient)  //������  ֮ǰ�� �� y + 100  x ����  y �� �� ��С
	{
		if( abs(target.pos_x - sh.pos_x) <= 52 
			&& target.pos_y <= sh.pos_y + sh.speed - sh.d_cut + 52 
			&& target.pos_y >= sh.pos_y - 52) //����Ŀ��
		{
			hit_index = 1;
			hit_distance -= (40 + target.pos_y - sh.pos_y);
			hit_distance_to_center = abs(target.pos_x - sh.pos_x);

			// ��  �� �� Ϊ �� ��  �� Ϊ ��  ����Ϊ ��
			if(UP == target.orient)
			{
				target.last_hit_orient = BEHIND;
			}
			else if(DOWN == target.orient)
			{
				target.last_hit_orient = FRONT;
			}
			else
			{
				target.last_hit_orient = SIDE;
			}
		}
	}
	else if(DOWN == sh.orient) 
	{
		if( abs(target.pos_x - sh.pos_x) <= 52 
			&& target.pos_y <= sh.pos_y + 52
			&& target.pos_y >= sh.pos_y - sh.speed + sh.d_cut- 52)
		{
			hit_index = 1;
			hit_distance -= sh.pos_y + 40 - target.pos_y; 
			hit_distance_to_center = abs(target.pos_x - sh.pos_x);


			if(UP == target.orient) // �� �� �� ���� �� �� ��ͷ ������Ϊ����
			{
				target.last_hit_orient = FRONT;

			}
			else if(DOWN == target.orient)
			{
				target.last_hit_orient = BEHIND;
			}
			else
			{
				target.last_hit_orient = SIDE;
			}
		}
	}
	else if(LEFT == sh.orient) // x֮ǰҪ����
	{
		if( abs(target.pos_y - sh.pos_y) <= 52
			&& target.pos_x <= sh.pos_x + sh.speed - sh.d_cut + 52
			&& target.pos_x >= sh.pos_x - 52)
		{
			hit_index = 1;
			hit_distance -= (40 + target.pos_x - sh.pos_x);
			hit_distance_to_center = abs(target.pos_y - sh.pos_y);

			if(LEFT == target.orient)// ��� ��Ϊ ���� ����Ϊͷ
			{
				target.last_hit_orient = BEHIND;
			}
			else if(RIGHT == target.orient)
			{
				target.last_hit_orient = FRONT;
			}
			else
			{
				target.last_hit_orient = SIDE;
			}
		}
	}
	else if(RIGHT == sh.orient)
	{
		if( abs(target.pos_y - sh.pos_y) <= 52
			&& target.pos_x <= sh.pos_x + 52
			&& target.pos_x >= sh.pos_x - sh.speed + sh.d_cut- 52)
		{
			hit_index = 1;
			hit_distance -= sh.pos_x + 40 - target.pos_x; 
			hit_distance_to_center = abs(target.pos_y - sh.pos_y);

			if(RIGHT == target.orient)
			{
				target.last_hit_orient = BEHIND;
			}
			else if(LEFT == target.orient)
			{
				target.last_hit_orient = FRONT;
			}
			else
			{
				target.last_hit_orient = SIDE;
			}
		}
	}


	
	if(hit_index)
	{
		int dmg = attacker.damage * vdm; //ʵ����ɵ��˺�
		if(hit_distance < 0)
			hit_distance = 0;
		//�����������
		bool can_penertrate_by_front = hit_distance <= (attacker.penertrate_level - target.ammor_level) * 100; 
		bool can_penertrate_by_side = hit_distance <= (attacker.penertrate_level - target.side_ammor_level) * 100;
		bool can_penertrate_by_behind = hit_distance <= (attacker.penertrate_level - target.behind_ammor_level) * 100;

		float dmg_index = 0.7 + 0.8 / (attacker.fire_speed / (sh.speed * 1.0)); //�ڵ�������˥��
		dmg *= dmg_index;

		float dmg_index_precise = 0.6 + ((52 - hit_distance_to_center) / (26 * 1.0)); //�ڵ�������λ�õĹ�ϵ
		dmg *= dmg_index_precise;

		int is_destory = 0;

		if(target.last_hit_orient == FRONT) // ��������ж�����
		{
			//����ѹ��
			if(can_penertrate_by_front)
			{
				if(hit_distance_to_center < 17)
				{
					target.current_max_hitpoint -= dmg * EFFECTIVE_PENERTRATED_DMG_X;
					target.last_hit_result = EFFECTIVE_PENERTRATED;
					target.t_last_effect_penertrated = current_clock;
				}
				else 
				{
					target.current_max_hitpoint -= dmg * PENERTRATED_DMG_X;
					target.last_hit_result = PENERTRATED;
					target.t_last_penertrated = current_clock;
				}
			}
			else
			{
				dmg *= UNPENERTRATED_DMG_VALUE;
				target.current_max_hitpoint -= dmg * UNPENERTRATED_DMG_X;
				target.last_hit_result = UNPENERTRATE;
			}
		}
		else if(target.last_hit_orient == SIDE)
		{
			if(can_penertrate_by_side)
			{
				if(hit_distance_to_center < 17)
				{
					target.current_max_hitpoint -= dmg * EFFECTIVE_PENERTRATED_DMG_X;
					target.last_hit_result = EFFECTIVE_PENERTRATED;
					target.t_last_effect_penertrated = current_clock;
				}
				else 
				{
					target.current_max_hitpoint -= dmg * PENERTRATED_DMG_X;
					target.last_hit_result = PENERTRATED;
					target.t_last_penertrated = current_clock;
				}
			}
			else
			{
				dmg *= UNPENERTRATED_DMG_VALUE;
				target.current_max_hitpoint -= dmg * UNPENERTRATED_DMG_X;
				target.last_hit_result = UNPENERTRATE;
			}
		}
		else if(target.last_hit_orient == BEHIND)
		{
			if(can_penertrate_by_behind)
			{
				if(hit_distance_to_center < 17)
				{
					target.current_max_hitpoint -= dmg * EFFECTIVE_PENERTRATED_DMG_X;
					target.last_hit_result = EFFECTIVE_PENERTRATED;
					target.t_last_effect_penertrated = current_clock;
				}
				else 
				{
					target.current_max_hitpoint -= dmg * PENERTRATED_DMG_X;
					target.last_hit_result = PENERTRATED;
					target.t_last_penertrated = current_clock;
				}
			}
			else
			{
				dmg *= UNPENERTRATED_DMG_VALUE;
				target.current_max_hitpoint -= dmg * UNPENERTRATED_DMG_X;
				target.last_hit_result = UNPENERTRATE;
			}
		}
		target.current_hitpoint -= dmg;

		//�˺�ͳ��
		if(target.current_hitpoint <= 0)
		{
			target.is_hit = dmg;
			attacker.dmg_cause += target.is_hit + target.current_hitpoint;
			target.current_hitpoint = 0;
			is_destory = 1;
		}
		else
		{
			target.is_hit = dmg;
			//��Ч�˺�ͳ��
			attacker.dmg_cause += target.is_hit;
		}
			

		attacker.shell_on_field = 0;
		target.dmg_recv += attacker.damage;


	//�ܽ�һ�� 
	//ѳ������

		int c_b_d_r = target.effective_penertrated_detonation_rate;
		int c_s_d_r = target.penertrated_detonation_rate;
		

		if(hit_distance <= 500)
		{
			c_b_d_r *= 1.5;
			c_s_d_r *= 1.5;
		}


		int detonation = rand()%100;
		if(target.last_hit_result == EFFECTIVE_PENERTRATED)
		{
			if(detonation < c_b_d_r)
			{

				target.is_hit += 99999;
				target.current_hitpoint -= 99999;
				target.current_max_hitpoint -= 99999;


				if(target.current_hitpoint <= 0)
				{
					attacker.dmg_cause += 99999 + target.current_hitpoint;
					target.current_hitpoint = 0;
					is_destory = 1;
				}
				else
				{
					attacker.dmg_cause += 99999;
				}
				if(target.current_max_hitpoint <= 0)
					target.current_max_hitpoint = 0;
				
				
			}
		}
		else if(target.last_hit_result == PENERTRATED)
		{
			if(detonation < c_s_d_r)
			{
				target.is_hit += 99999;
				target.current_hitpoint -= 99999;
				target.current_max_hitpoint -= 99999;


				if(target.current_hitpoint <= 0)
				{
					attacker.dmg_cause += 99999 + target.current_hitpoint;
					target.current_hitpoint = 0;
					is_destory = 1;
				}
				else
				{
					attacker.dmg_cause += 99999;
				}
				if(target.current_max_hitpoint <= 0)
					target.current_max_hitpoint = 0;
			}
		}
		//�˺�������
		target.t_last_hit = current_clock;
		target.last_hit = target.is_hit;

		if(is_destory)
		{
			target.die_time = current_clock;
			attacker.kill += 1;
		}
		
		//��Ч
		if(attacker.rc == PLAYER || target.rc == PLAYER)
		{
			if(attacker.rc == PLAYER)
			{
				t_last_dmg_cause = current_clock;
				last_dmg_cause = attacker.dmg_cause - dmg_cause_except_this;

				if(is_destory)
				{
					/*
					if(current_clock - last_kill <= 3800)
					{
						kill_stack += 1;
					}
					else
						kill_stack = 1;
					if(kill_stack > 8)
						kill_stack = 8;
					*/
					kill_stack_broadcast_player(BoardCast(0));
					my_sound_player(EXPLOSE_SOUND);

					last_kill = current_clock;
				}
				else
				{
					if(target.last_hit_result == UNPENERTRATE)
						my_sound_player(FRONT_HIT_SOUND);
					else if(target.last_hit_result == PENERTRATED)
						my_sound_player(SIDE_HIT_SOUND);
					else if(target.last_hit_result == EFFECTIVE_PENERTRATED)
					{
						static clock_t last_cast = -9999;
						my_sound_player(BEHIND_HIT_SOUND);
						if(current_clock - last_cast > 1000)
						{
							::mciSendString("close ch", NULL, 0, NULL);
							::mciSendString("open critical_hit.mp3 alias ch", NULL, 0, NULL); //�� �ļ�123.mp3  ��ȡ���� start
 							::mciSendString("play ch", NULL, 0, NULL);
							last_cast = current_clock;
						}
					}
				}
			}
			else 
			{
				if(is_destory)
				{
					my_sound_player(EXPLOSE_SOUND);
					::mciSendString("close ch", NULL, 0, NULL);
					::mciSendString("close bch", NULL, 0, NULL);
					::mciSendString("close bgm2", NULL, 0, NULL);
					::mciSendString("close kill", NULL, 0, NULL);

				}
				else
				{
					if(target.last_hit_result == UNPENERTRATE)
							my_sound_player(FRONT_HIT_SOUND);
					else if(target.last_hit_result == PENERTRATED)
						my_sound_player(SIDE_HIT_SOUND);
					else if(target.last_hit_result == EFFECTIVE_PENERTRATED)
					{
						static clock_t last_cast = -9999;
						my_sound_player(BEHIND_HIT_SOUND);
						if(current_clock - last_cast > 2100)
						{
							::mciSendString("close bch", NULL, 0, NULL);
							::mciSendString("open critical_hitted.mp3 alias bch", NULL, 0, NULL); //�� �ļ�123.mp3  ��ȡ���� start
 							::mciSendString("play bch", NULL, 0, NULL);
							last_cast = current_clock;
						}

						my_sound_player(BEHIND_HIT_SOUND);
					}
					last_sound = current_clock;
				}
			}
		}
	}
}