#include "stdafx.h"
#include "̹�˴�սϵ��Dlg.h"

//б�ܵ�Ʋ����  ע�ͺ� ������ַ������Ʋ   ת���������

//ս������ �߼����� (�������ղ���ָ��  ս���߼���չ )  ��Ϸ�����߼����� + �����ֳ�ʼ�� timer����������

void C̹�˴�սϵ��Dlg::OnTimer(UINT_PTR nIDEvent)
{	
	enemys = 0;//���˴������
	alliences = 0;


	//ս������ �߼����ƺ���
	if(nIDEvent == 1)
	{
		Battle_Update_Control();
	}

	//��ʼ����
	else if(nIDEvent == 4)
	{
		KillTimer(4);
		init_start_Draws();
	}
	else if(nIDEvent == 10)
	{
		KillTimer(10);
		//PostMessageA(WM_KEYDOWN, VK_RETURN, 0);
		keybd_event(VK_RETURN, 0, 0, 0 );
	}

	//�����޸�
	else if(nIDEvent == 20)
	{
		damage_report(ENGINE_REPAIRED);
		KillTimer(20);
		tank1.is_engine_damage = 0;
		tank1.Accelerate_Power = tank1.init_accelerate_power;
		tank1.Max_Speed = tank1.init_max_speed;
		tank1.route_interval = tank1.init_fastest_route_interval;
	}
	//�����޸�
	else if(nIDEvent == 21)
	{
		damage_report(GUN_REPAIRED);
		KillTimer(21);
		tank1.is_gun_damage = 0;
		tank1.damage = tank1.max_damage;
		tank1.fire_interval = tank1.fastest_fire_interval;
	}
	//������װ��ʧЧ
	else if(nIDEvent == 100)
	{
		KillTimer(100);
		tank1.fire_interval = tank1.fastest_fire_interval;
		Player_Tank::energy = 0;
	}
	//��ʼ����
	/*
	else if(nIDEvent == 888)
	{
		static int k = 0;
		CG_Draw(k);


		k ++;
		if(k > 2952)
			k = 0;
	}
	*/
	//openning ����
	else if(nIDEvent == 999)
	{
		static int k = 0;

		if(k == 0)
		{
			::mciSendString("open openning.mp3 alias op", NULL, 0, NULL);
			::mciSendString("play op", NULL, 0, NULL);
		}
		Openning_Draw(k);

		k++;
		if(k > 146)
		{
			::mciSendString("close op", NULL, 0, NULL);
			Sleep(1000);
			KillTimer(999);
			SetTimer(4, 100, NULL);
		}
	}
	//ending ����
	else if(nIDEvent = 1111)
	{
		static int k = 0;
		if(k == 0)
		{
			::mciSendString("open ending2.mp3 alias ed", NULL, 0, NULL);
			::mciSendString("play ed", NULL, 0, NULL);
		}
		Ending_Draw(k);

		k++;
		if(k > 700)
		{
			::mciSendString("close op", NULL, 0, NULL);
			Sleep(3000);
			KillTimer(1111);


			ActivateKeyboardLayout(my_old_layout, 0);
			this->OnOK();
			//SetTimer(4, 100, NULL);
		}

	}

	CDialogEx::OnTimer(nIDEvent);
}


//ս������  �������������
//��Ϸ����  ��Ϸ��ʼ ѡ���Ѷ�  �׶εĽ����뷢չ 
BOOL C̹�˴�սϵ��Dlg::PreTranslateMessage(MSG* pMsg)
{
	//��̬�ֲ����� ���� ��¼ ��Ϸ�Ƿ�ʼ
	static  int start = 0;
	static int current_quest = 0;
	static clock_t last_view_switch = 0;

	//���ռ�����Ϣ ��Ϊ��������������һ�� ������Ϣ����������Ϣѭ����������
	if(pMsg->message == WM_KEYDOWN)
	{
		//�ո� --- ���� ָ��   
		if(VK_SPACE == pMsg->wParam)
		{
			tank1.fire_command = 1;
		}
		// ��ʼ����  
		else if(VK_RETURN == pMsg->wParam)
		{
			if(!start)
			{
				if(Player_Tank::is_choice)
				{
					//KillTimer(888);
					timeKillEvent(g_wTimerID); 
					init_difficulty_info();
					::mciSendString("close begin ", NULL, 0, NULL);

					boomb = 2;
					start = 1;
					current_stage = 1;
					process = Prepare;

					Player_Tank::upgrade_generation = 0;
					Player_Tank::upgrade_engine = 0;
					Player_Tank::upgrade_gun = 0;
					tank1 = Player_Tank();
					stage_init_tank(current_stage);

					prepartion_bgm_player(current_stage);
					Process_Show();
				}
				else
				{
					AfxMessageBox("��ѡ���Ѷ�");
				}
			}
			return FALSE;
		}
		else if(VK_TAB == pMsg->wParam)
		{
			if(!start)
			{
				AfxMessageBox("���Ȱ��س���ʼ");
				return CDialogEx::PreTranslateMessage(pMsg);
			}
			if(process == Prepare)
			{
				
				if(current_stage != 3)
					immune_to = clock() + 80 + 4000;
					

				battle_bgm_player(current_stage);
				process = FIGHT;
				stage_init_tank(current_stage);
				SetTimer(1, INTERAVL, NULL);
			}
			else if(process == After)
			{
				if(current_stage == MAX_STAGE)
				{
					//AfxMessageBox("���Ѿ�ͨ��Ŀǰ�����������йؿ� ��ȴ�����");
					::mciSendString("close interval ", NULL, 0, NULL);
					SetTimer(1111, 100, NULL);
					return FALSE;
				}
				if(current_stage == -1)
					current_stage = 8;
				else
					current_stage += 1;
				process = Prepare;
		//		prepartion_bgm_player(current_stage);
				Process_Show();
			}
			return FALSE;
		}
		else if('1' == pMsg->wParam) 
		{
			if(Player_Tank::upgrade_command && instruct != 1)
			{
				for(int i = 0; i < NUM_OF_TEAMMATE; i++)
				{
					allience_tanks[i].protect_index = -1;
					allience_tanks[i].rc = PROTECT;
				}
				instruct = 1;
			}
			
		}
		else if('2' == pMsg->wParam)
		{
			if(Player_Tank::upgrade_command && instruct != 2)
			{
				for(int i = 0; i < NUM_OF_TEAMMATE; i++)
				{
					allience_tanks[i].rc = PROTEND;
					allience_tanks[i].Vp_range = 3000;
					allience_tanks[i].pretend_range = 850;
				}
				instruct = 2;
			}
		
		}
		else if('3' == pMsg->wParam)
		{
			if(Player_Tank::upgrade_command && instruct != 3)
			{
				for(int i = 0; i < NUM_OF_TEAMMATE; i++)
				{
					allience_tanks[i].rc = VP;
					allience_tanks[i].Vp_range = 5000;
				}
				instruct = 3;
			}

		}
		else if('4' == pMsg->wParam)
		{
			if(Player_Tank::upgrade_command && instruct != 4)
			{
				for(int i = 0; i < NUM_OF_TEAMMATE; i++)
				{
					allience_tanks[i].rc = PROTEND;
					allience_tanks[i].Vp_range = 3000;
					allience_tanks[i].pretend_range = 300;
				}
				instruct = 4;
			}
		}
		//�ؼ� ֱ����һ��
		else if('J' == pMsg->wParam)
		{
			if(process == FIGHT)
			{
				KillTimer(1);
				process = After;
				tank1.gold += 50;
				Process_Show();
			}
		}
		//�ش򱾹�
		else if('R' == pMsg->wParam)
		{
			if(process == After)
			{
				process = Prepare;
				tank1 = player_at_stage_begin;

				Process_Show();
				PostMessageA(WM_KEYDOWN, VK_TAB, 0);
			}
			else if(process == FIGHT && Player_Tank::upgrade_gun)
			{
				if(Dialog_current_clock > gun_up_to + 200 && Player_Tank::energy == MAX_ENERGY)
				{
					tank1.fire_interval = tank1.fastest_fire_interval / 4;
					gun_up_to = Dialog_current_clock + T_UPGRADE_GUN;
					SetTimer(100, T_UPGRADE_GUN, NULL);
				}
				return TRUE;
			}
		}
		else if('E' == pMsg->wParam)
		{
			if(!start)
			{
				Player_Tank::difficulty = 0;
				AfxMessageBox("�Ѷ��趨���˼�");
				Player_Tank::is_choice = 1;
				
			}
		}
		else if('N' == pMsg->wParam)
		{
			if(!start)
			{
				Player_Tank::difficulty = 1;
				AfxMessageBox("�Ѷ��趨�����е�");
				Player_Tank::is_choice = 1;
				
			}

		}
		else if('H' == pMsg->wParam)
		{
			if(!start)
			{
				Player_Tank::difficulty = 2;
				AfxMessageBox("�Ѷ��趨��������");
				Player_Tank::is_choice = 1;
				
			}

		}
		else if('U' == pMsg->wParam)
		{
			if(current_stage == 7 && process == After)
			{
				AfxMessageBox("�������˿������عص�ͨ�� ���������������̸��̸�������� �� W ����");

				MQuestDialog dlg;
				//dlg.DoModal();
				dlg.current_quest = 11;
				if(dlg.current_quest == 11)
				{
					current_stage = -1;
					process = Prepare;
					Process_Show();
				}	
				return TRUE;
				
			}
		}
		else if('W' == pMsg->wParam)
		{
			if(current_quest < 1 && process != FIGHT)
				AfxMessageBox("�����뷨������ ������\r\n �ڵ��߹ؽ����ڰ˹ؿ�ʼǰ�� U ���Կ������ع�");
			else if(process == FIGHT)
			{
				if(Dialog_current_clock - last_view_switch >= VIEW_SWITCH_INTERVAL)
				{
					last_view_switch = Dialog_current_clock;
					last_view_orient = view_orient;
					if(view_orient == STOP)
						view_orient = UP;
					else 
						view_orient = STOP;
				}
			}
		}
		else if('S' == pMsg->wParam)
		{
			if(process == FIGHT)
			{
				if(Dialog_current_clock - last_view_switch >= VIEW_SWITCH_INTERVAL)
				{
					last_view_switch = Dialog_current_clock;
					last_view_orient = view_orient;
					if(view_orient == STOP)
						view_orient = DOWN;
					else 
						view_orient = STOP;
				}
			}
		}
		else if('A' == pMsg->wParam)
		{
			if(!start && process != FIGHT)
			{
				KillTimer(888);
				process = Prepare;
				::mciSendString("close begin", NULL, 0, NULL);
				Player_Tank::upgrade_generation = 1;
				Player_Tank::upgrade_engine = 1;
				Player_Tank::upgrade_gun = 1;
				current_stage = 100;
				stage_init_tank(current_stage);
				//prepartion_bgm_player(current_stage);
				Process_Show();
			}
			else if(process == FIGHT)
			{
				if(Dialog_current_clock - last_view_switch >= VIEW_SWITCH_INTERVAL)
				{
					last_view_switch = Dialog_current_clock;
					last_view_orient = view_orient;
					if(view_orient == STOP)
						view_orient = LEFT;
					else 
						view_orient = STOP;
				}
			}
		}
		else if('D' == pMsg->wParam)
		{
			if(process == FIGHT)
			{
				if(Dialog_current_clock - last_view_switch >= VIEW_SWITCH_INTERVAL)
				{
					last_view_switch = Dialog_current_clock;
					last_view_orient = view_orient;
					if(view_orient == STOP)
						view_orient = RIGHT;
					else 
						view_orient = STOP;
				}
			}
		}

		else if('B' == pMsg->wParam)
		{
			if(current_stage == 100)
			{
				if(process == Prepare)
				{
					stage_init_tank(100);
					process = FIGHT;
					SetTimer(1, 80, NULL);

					battle_bgm_player(current_stage);	
				}
				else
				{
					init_start_Draws();
				}
			}
			
		}
		else if('G' == pMsg->wParam)
		{
			if(!start && process != FIGHT)
			{
				timeKillEvent(g_wTimerID);
				KillTimer(888);
				process = Prepare;
				::mciSendString("close begin", NULL, 0, NULL);
				Player_Tank::upgrade_generation = 1;
				Player_Tank::upgrade_engine = 1;
				Player_Tank::upgrade_gun = 1;
				current_stage = 101;
				stage_init_tank(current_stage);
				//prepartion_bgm_player(current_stage);
				Process_Show();
			}
		
		}
		else if('F' == pMsg->wParam)
		{
			if(current_stage == 101)
			{
				if(process == Prepare)
				{
					stage_init_tank(101);
					process = FIGHT;
					SetTimer(1, 80, NULL);

					battle_bgm_player(current_stage);
				}
				else
				{
					init_start_Draws();
				}
			}
			
		}
		else if('C' == pMsg->wParam)
		{
			if(!start)
			{
				Player_Tank::difficulty = -1;
				AfxMessageBox("�Ѷ��趨��������");
				Player_Tank::is_choice = 1;
				
			}
		}
		else if('Q' == pMsg->wParam)
		{
			if(process != FIGHT)
			{
				ActivateKeyboardLayout(my_old_layout, 0);
				this->OnOK();
			}
		}
		else if('P' == pMsg->wParam)
		{
			if(process != FIGHT)
			{
				M_HelpDialog hdlg;
				hdlg.DoModal();
			}
			return TRUE;
		}
		//������װ��
		else if('I' == pMsg->wParam)
		{
		}
	}
	//return TRUE;
	return CDialogEx::PreTranslateMessage(pMsg);
}
//465

