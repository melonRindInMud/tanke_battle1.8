#include "stdafx.h"
#include "̹�˴�սϵ��Dlg.h"
//���ƺ����Ķ���ȫ��д������


extern clock_t t_last_dmg_cause;
extern int last_dmg_cause;

//ս���������
// ս�������� ����
void C̹�˴�սϵ��Dlg::Draw_Update(void)
{
	//��ͼ��������

	//ɭ�ֱ���
	if(8 == current_stage || 13 == current_stage || 16 == current_stage)
	{
		bkresouceDC.SelectObject(&frost_bk);
		memDC.BitBlt(0, 0, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(0, 1000, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(1500, 1000, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(1500, 0, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
	}
	else if ( -1 == current_stage) //��ҹ����
	{
		bkresouceDC.SelectObject(&darkness_bk);
		memDC.BitBlt(0, 0, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(0, 1000, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(1500, 1000, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(1500, 0, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
	}
	//��ɳ��ͼ
	else if(6 == current_stage) 
	{
		bkresouceDC.SelectObject(&town_bk);
		memDC.BitBlt(0, 0, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(0, 1000, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(1500, 1000, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(1500, 0, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		bkresouceDC.SelectObject(&city_bk);
		memDC.BitBlt(750, 500, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
	}
	//��³������ͼ
	else if(9 == current_stage) 
	{
		bkresouceDC.SelectObject(&town_bk);
		memDC.BitBlt(0, 0, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(0, 1000, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(1500, 1000, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(1500, 0, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		bkresouceDC.SelectObject(&city_bk);
		memDC.BitBlt(0, 500, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
	}

	//���˳ǵ�ͼ
	else if(11 == current_stage)
	{
		bkresouceDC.SelectObject(&grass_bk);
		memDC.BitBlt(0, 0, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(0, 1000, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(1500, 1000, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(1500, 0, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		bkresouceDC.SelectObject(&city_bk);
		memDC.BitBlt(0, 1000, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
	}
	// �����ͼ
	else if(12 == current_stage)
	{
		bkresouceDC.SelectObject(&city_bk);
		memDC.BitBlt(0, 0, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(0, 1000, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(1500, 1000, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(1500, 0, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
	}


	//��һ������ѵ��������
	else if(1 == current_stage)
	{
		bkresouceDC.SelectObject(&tg_bk);
		memDC.BitBlt(0, 0, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(0, 1000, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(1500, 1000, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(1500, 0, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
	}
	else if(2 == current_stage || 3 == current_stage)
	{		
		bkresouceDC.SelectObject(&grass_bk);
		memDC.BitBlt(0, 0, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(0, 1000, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(1500, 1000, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(1500, 0, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		bkresouceDC.SelectObject(&tg_bk);
		memDC.BitBlt(750, 500, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);

	}
	//���Ĺ�
	else if(4 == current_stage)
	{
		bkresouceDC.SelectObject(&grass_bk);
		memDC.BitBlt(0, 0, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(0, 1000, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(1500, 1000, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(1500, 0, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		bkresouceDC.SelectObject(&town_bk);
		memDC.BitBlt(750, 500, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);

	}
	//����� �� �� 101 ��
	else if(5 == current_stage || 101 == current_stage)
	{
		bkresouceDC.SelectObject(&town_bk);
		memDC.BitBlt(0, 0, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(0, 1000, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(1500, 1000, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(1500, 0, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
	}
	//����ŵ����
	else if(10 == current_stage)
	{
		bkresouceDC.SelectObject(&frost_bk);
		memDC.BitBlt(0, 0, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(0, 1000, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(1500, 1000, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(1500, 0, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		bkresouceDC.SelectObject(&defense_bk);
		memDC.BitBlt(750, 0, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(750, 1000, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);


	}
	//���߹�
	else if(7 == current_stage)
	{
		bkresouceDC.SelectObject(&frost_bk);
		memDC.BitBlt(0, 0, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(0, 1000, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(1500, 1000, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(1500, 0, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		bkresouceDC.SelectObject(&town_bk);
		memDC.BitBlt(0, 0, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
	}
	else  //�ݵ�����
	{
		bkresouceDC.SelectObject(&grass_bk);
		memDC.BitBlt(0, 0, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(0, 1000, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(1500, 1000, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(1500, 0, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
	}





	supportDC.BitBlt(0, 0, FIELD_WIDTH, FIELD_HEIGHT, &memDC, 0, 0, SRCCOPY);//�󱳾� ���۶���̹�˶�ֻ��һ��
	supportDC.SetBkMode(TRANSPARENT);
	
	//��������
	pictureDC.SelectObject(&river_bitmap);
	for(int i = 0; i < river_box_number; i++)
	{
		supportDC.BitBlt(river_infor[i].x - 40, river_infor[i].y - 40, 80, 80, &pictureDC, 0, 0, SRCCOPY);
	}





	//�������� ���Ʋ��� 
	//�²� ̹�˻�����Ϣ
	//�о� ���Ʋ���
	for(int i = 0; i < NUM_OF_ENEMY; i++)
	{
		//���ڳ� ����������ص�һ�л���
		if(!enemy_tanks[i].is_on_field)
			continue;

		else if(enemy_tanks[i].current_hitpoint || enemy_tanks[i].is_hit || enemy_tanks[i].shell_on_field) //���������ֹ�����ڵ�����ʧЧ
		{
			if(enemy_tanks[i].current_hitpoint && current_stage != -1) //������ ���Ҳ������ع�
			{
				if(c_d_t == V_KVP && i == 0)
					supportDC.SetTextColor(RGB(255, 0, 255));
				else
					supportDC.SetTextColor(RGB(255, 0, 0));

				//̹�˻��Ʋ���
				Tank_Graph_Drawer(enemy_tanks[i], 2);
			}
		}
	}
	
#ifdef USE_ALLIENCE
	//�Ѿ�����
	for(int i = 0; i < NUM_OF_ALLIENCE; i++)
	{
		if(!allience_tanks[i].is_on_field)
			continue;
		else if(allience_tanks[i].current_hitpoint || allience_tanks[i].is_hit || allience_tanks[i].shell_on_field) //���������ֹ�����ڵ�����ʧЧ
		{
			if(allience_tanks[i].current_hitpoint) //������
			{
				if(c_d_t == D_LVP && i == 0)
					supportDC.SetTextColor(RGB(255, 128, 0));
				else
					supportDC.SetTextColor(RGB(0, 0, 255));
				
				//̹�˻���
				Tank_Graph_Drawer(allience_tanks[i], 1);
			}	
		}
	}
#endif
	//�Լ�����
	if(tank1.current_hitpoint || tank1.is_hit) //����Ѫ ���߱����б�ը -- һ����4��ͼ ������static �͵� --- ����ȥ��
	{
		//��ǰ�������ֵbug����
		if(tank1.current_max_hitpoint < 0)
			tank1.current_max_hitpoint = 0;
		//�޵�
		if(Dialog_current_clock <= immune_to)
		{
			pictureDC.SelectObject(&immue);
			supportDC.TransparentBlt(tank1.pos_x - 64, tank1.pos_y - 64, 128, 128, &pictureDC, 0, 0, 128, 128,  RGB(0, 0, 0));
		}

		if(current_stage != -1)
			Draw_Fire_Control();

		//̹�˻���
		if(tank1.current_hitpoint)
		{
			Tank_Graph_Drawer(tank1, 3);
		}
	}


	//�ֲ���� - �ϲ� ��ը ���� �ڵ� �� 
	for(int i = 0; i < NUM_OF_ENEMY; i++)
	{
		if((enemy_tanks[i].current_hitpoint || (Dialog_current_clock - enemy_tanks[i].die_time) <= 1000 || enemy_tanks[i].shell_on_field) && enemy_tanks[i].is_on_field)
			Attach_Graph_Drawer(enemy_tanks[i], 1);
		enemy_tanks[i].is_hit = 0;
	}
	
	//�Ѿ�����
	for(int i = 0; i < NUM_OF_ALLIENCE; i++)
	{
		if((allience_tanks[i].current_hitpoint || ((Dialog_current_clock - allience_tanks[i].die_time) <= 1000) || allience_tanks[i].shell_on_field) && allience_tanks[i].is_on_field)
			Attach_Graph_Drawer(allience_tanks[i], 2);
		allience_tanks[i].is_hit = 0;
	}

	//�Լ�����
	Attach_Graph_Drawer(tank1, 2);
	tank1.is_hit = 0;

	//�ܴ��ӽ���ʾ
	Show_Player_Hit_Effect();
}

// ս����ʾ��Ϣ����  ����
void C̹�˴�սϵ��Dlg::SubView_Update(void)
{

	int curr_y = 0;
	pictureDC.SelectObject(&subviewbk);
	stateDC.BitBlt(0, 0, 400, 1000, &pictureDC, 0, 0, SRCCOPY);
	stateDC.SetBkMode(TRANSPARENT);

	//������Ϣ���� Ѫ�� �ؿ����� �ؿ����� �Ѷ� ֮���
	StateDC_Basic_Infor_Draw();


	//����ؿ���ʾ��Ϣ����
	StateDC_Special_Reming();

	
	//��������ʹ��״������
	StateDC_Additional_Ability_Draw();


	//״̬�������
	StateDC_Damage_State_Draw();


	//С��ͼ���� �ӽ�ѡ�� �Լ� �����ܻ���
	StateDC_Draw_Litter_Map_And_View();

	//��״̬����ӵ���̨DC��

}
//750��

//1�Ѿ� 2���� 3�Լ�
void C̹�˴�սϵ��Dlg::Tank_Graph_Drawer(Tank& tk, int p)
{
	int draw_x = tk.pos_x - TANK_WIDTH/2;
	int draw_y = tk.pos_y - TANK_WIDTH/2;

	//�Ĵ��ۼ� --  ����Ч������
	/*
	if(UP == tk.orient)
	{
		pictureDC.SelectObject(&move_hint_up_down);
		supportDC.TransparentBlt(draw_x, draw_y + 80, 80, tk.Current_Speed * 3, &pictureDC, 0, 0, 80, tk.Current_Speed * 3, RGB(255, 255, 255));

	}
	else if(DOWN == tk.orient)
	{
		pictureDC.SelectObject(&move_hint_up_down);
		supportDC.TransparentBlt(draw_x, draw_y  - tk.Current_Speed * 3, 80, tk.Current_Speed * 3, &pictureDC, 0, 0, 80, tk.Current_Speed * 3, RGB(255, 255, 255));
	}
	else if(LEFT == tk.orient)
	{
		pictureDC.SelectObject(&move_hint_left_right);
		supportDC.TransparentBlt(draw_x + 80, draw_y, tk.Current_Speed * 3, 80, &pictureDC, 0, 0, tk.Current_Speed * 3, 80, RGB(255, 255, 255));
	}
	else
	{
		pictureDC.SelectObject(&move_hint_left_right);
		supportDC.TransparentBlt(draw_x - tk.Current_Speed * 3, draw_y, tk.Current_Speed * 3, 80, &pictureDC, 0, 0, tk.Current_Speed * 3, 80, RGB(255, 255, 255));
	}
	*/


	//��Ӱ����(��͸����
	pictureDC.SelectObject(&tank_shadow);

	memDC.BitBlt(0, 0, 90, 90, &supportDC, draw_x - 5, draw_y - 5, SRCCOPY);
	memDC.TransparentBlt(0, 0, 90, 90, &pictureDC, 0, 0, 90, 90, RGB(255, 255, 255));
	

	BLENDFUNCTION blendFunction;
	memset( &blendFunction, 0, sizeof(blendFunction) );
	blendFunction.BlendOp = AC_SRC_OVER;
	blendFunction.BlendFlags = 0;
	blendFunction.SourceConstantAlpha = 192;

	supportDC.AlphaBlend(draw_x - 5, draw_y - 5, 90, 90, &memDC, 0, 0, 90, 90, blendFunction);




	

	//Ѫ������
	//���
	supportDC.FillSolidRect(draw_x - 12, draw_y - 18, 104, 15, RGB(0, 0, 0));

	//����
	int  index = float(100 * tk.current_max_hitpoint / tk.max_hitpoint);
	supportDC.FillSolidRect(draw_x - 10, draw_y - 16, index, 11, RGB(250, 250, 250));

	//��ǰֵ
	index = float(100 * tk.current_hitpoint / tk.max_hitpoint);


	//�Լ�
	if(3 == p)
		supportDC.FillSolidRect(draw_x - 10, draw_y - 16, index, 11, RGB(0.5 * index + 50, 1.2 * index + 120, 0.5 * index + 50));
	//�ѷ�
	else if(1 == p)
		supportDC.FillSolidRect(draw_x - 10, draw_y - 16, index, 11, RGB(0.25 * index + 25, 0.5 * index + 50, 1.2 * index + 120));
	//����
	else
		supportDC.FillSolidRect(draw_x - 10, draw_y - 16, index, 11, RGB(1.28 * index + 127, 0, 0));
	//Ѫ������Ż�
	BLENDFUNCTION blendFunction2;
	memset( &blendFunction2, 0, sizeof(blendFunction2) );
	blendFunction2.BlendOp = AC_SRC_OVER;
	blendFunction2.BlendFlags = 0;
	blendFunction2.SourceConstantAlpha = 128;

	pictureDC.SelectObject(&pro_clt);
	supportDC.AlphaBlend(draw_x - 10, draw_y - 16, 100, 11, &pictureDC, 0, 0, 200, 35, blendFunction2);



	if(Turret == tk.icon)
	{
		if(UP == tk.orient)
		{
			pictureDC.SelectObject(&Turret_Up);
		}
		else if(DOWN == tk.orient)
		{
			pictureDC.SelectObject(&Turret_Down);
		}
		else if(LEFT == tk.orient)
		{
			pictureDC.SelectObject(&Turret_Left);
		}
		else if(RIGHT == tk.orient)
		{
			pictureDC.SelectObject(&Turret_Right);
		}
	}
	//̹�˻���
	else if(G_T2 == tk.icon)
	{
		if(UP == tk.orient)
		{
			pictureDC.SelectObject(&G_T2_Up);
		}
		else if(DOWN == tk.orient)
		{
			pictureDC.SelectObject(&G_T2_Down);
		}
		else if(LEFT == tk.orient)
		{
			pictureDC.SelectObject(&G_T2_Left);
		}
		else if(RIGHT == tk.orient)
		{
			pictureDC.SelectObject(&G_T2_right);
		}
	}
	else if(G_T2_B == tk.icon)
	{
		if(UP == tk.orient)
		{
			pictureDC.SelectObject(&G_T2_B_Up);
		}
		else if(DOWN == tk.orient)
		{
			pictureDC.SelectObject(&G_T2_B_Down);
		}
		else if(LEFT == tk.orient)
		{
			pictureDC.SelectObject(&G_T2_B_Left);
		}
		else if(RIGHT == tk.orient)
		{
			pictureDC.SelectObject(&G_T2_B_right);
		}
	}
	else if(G_T1 == tk.icon)
	{
		if(UP == tk.orient)
		{
			pictureDC.SelectObject(&Tank1_Up);
		}
		else if(DOWN == tk.orient)
		{
			pictureDC.SelectObject(&Tank1_Down);
		}
		else if(LEFT == tk.orient)
		{
			pictureDC.SelectObject(&Tank1_Left);
		}
		else if(RIGHT == tk.orient)
		{
			pictureDC.SelectObject(&Tank1_right);
		}
	}
	else if(Turret == tk.icon)
	{
		if(UP == tk.orient)
		{
			pictureDC.SelectObject(&Turret_Up);
		}
		else if(DOWN == tk.orient)
		{
			pictureDC.SelectObject(&Turret_Down);
		}
		else if(LEFT == tk.orient)
		{
			pictureDC.SelectObject(&Turret_Left);
		}
		else if(RIGHT == tk.orient)
		{
			pictureDC.SelectObject(&Turret_Right);
		}

					
	}
	//�վ�
	else if(USSR_T1 == tk.icon)
	{
		if(UP == tk.orient)
		{
			pictureDC.SelectObject(&ussr_tank1_Up);
		}
		else if(DOWN == tk.orient)
		{
			pictureDC.SelectObject(&ussr_tank1_Down);
		}
		else if(LEFT == tk.orient)
		{
			pictureDC.SelectObject(&ussr_tank1_Left);
		}
		else if(RIGHT == tk.orient)
		{
			pictureDC.SelectObject(&ussr_tank1_right);
		}
	}
	//�վ�III
	else if(USSR_T3 == tk.icon)
	{
		if(UP == tk.orient)
		{
			pictureDC.SelectObject(&ussr_tanks3_Up);
		}
		else if(DOWN == tk.orient)
		{
			pictureDC.SelectObject(&ussr_tanks3_Down);
		}
		else if(LEFT == tk.orient)
		{
			pictureDC.SelectObject(&ussr_tanks3_Left);
		}
		else if(RIGHT == tk.orient)
		{
			pictureDC.SelectObject(&ussr_tanks3_right);
		}
	}
	else if(USSR_T4 == tk.icon)
	{
		if(UP == tk.orient)
		{
			pictureDC.SelectObject(&ussr_tanks4_Up);
		}
		else if(DOWN == tk.orient)
		{
			pictureDC.SelectObject(&ussr_tanks4_Down);
		}
		else if(LEFT == tk.orient)
		{
			pictureDC.SelectObject(&ussr_tanks4_Left);
		}
		else if(RIGHT == tk.orient)
		{
			pictureDC.SelectObject(&ussr_tanks4_right);
		}
	}
	else if(UK_T1 == tk.icon)
	{
		if(UP == tk.orient)
		{
			pictureDC.SelectObject(&uk_tank1_Up);
		}
		else if(DOWN == tk.orient)
		{
			pictureDC.SelectObject(&uk_tank1_Down);
		}
		else if(LEFT == tk.orient)
		{
			pictureDC.SelectObject(&uk_tank1_Left);
		}
		else if(RIGHT == tk.orient)
		{
			pictureDC.SelectObject(&uk_tank1_right);
		}
	}


	//̹�˻���
	supportDC.TransparentBlt(draw_x, draw_y, TANK_WIDTH, TANK_WIDTH, &pictureDC, 0, 0, TANK_WIDTH, TANK_WIDTH, RGB(255, 255, 255));

	//����ͼ��
	if(Dialog_current_clock - tk.t_last_hit < 300)//������
	{
		if(tk.current_hitpoint)
		{
			BLENDFUNCTION blendFunction;
			memset( &blendFunction, 0, sizeof(blendFunction) );
			blendFunction.BlendOp = AC_SRC_OVER;
			blendFunction.BlendFlags = 0;
			blendFunction.SourceConstantAlpha = 255 - (Dialog_current_clock - tk.t_last_hit) * 128 / 300;


			memDC.BitBlt(0, 0, 66, 66, &supportDC, draw_x + 7, draw_y + 7, SRCCOPY);



			CBitmap mask;
			mask.LoadBitmapA(IDB_HIT_MASK);
			pictureDC.SelectObject(&hit);
			memDC.TransparentBlt(0, 0, 66, 66, &pictureDC, 0, 0, 66, 66, RGB(255, 255, 255));

			supportDC.AlphaBlend(draw_x + 7, draw_y + 7, 66, 66, &memDC, 0, 0, 66, 66, blendFunction);
		}

	}
	//��Ӱ����
	
	BLENDFUNCTION blendFunction3;
	memset( &blendFunction3, 0, sizeof(blendFunction3) );
	blendFunction3.BlendOp = AC_SRC_OVER;
	blendFunction3.BlendFlags = 0;
	blendFunction3.SourceConstantAlpha = 64;

	pictureDC.SelectObject(&tank_light_effect);
	supportDC.AlphaBlend(draw_x, draw_y, 80, 80, &pictureDC, 0, 0, 80, 80, blendFunction3);
	


	//״̬��
	if(tk.is_engine_damage)
	{
		pictureDC.SelectObject(engine_damage);
		supportDC.TransparentBlt(tk.pos_x + TANK_WIDTH/2 + 14 , draw_y - 18, 24, 24, &pictureDC, 0, 0, 24, 24, RGB(255, 255, 255));
	}
	if(tk.is_gun_damage)
	{
		pictureDC.SelectObject(gun_damage);
		supportDC.TransparentBlt(tk.pos_x + TANK_WIDTH/2 + 14 , draw_y  + 8, 24, 24, &pictureDC, 0, 0, 24, 24, RGB(255, 255, 255));
	}
}

void C̹�˴�սϵ��Dlg::Attach_Graph_Drawer(Tank& tk, int p)
{
	int draw_x = tk.pos_x - TANK_WIDTH/2;
	int draw_y = tk.pos_y - TANK_WIDTH/2;
	//������ɫ
	if(p == 1)
		supportDC.SetTextColor(RGB(255, 0, 0));
	else
		supportDC.SetTextColor(RGB(0, 0, 255));

	//����	--�������ع�
	
	if(tk.current_hitpoint && (current_stage != -1 && current_stage != 15 || PLAYER == tk.rc))
	{
		
		CString t;
		t.Format(" %4d / %4d ", tk.current_hitpoint, tk.max_hitpoint);
		supportDC.TextOutA(draw_x - 40, draw_y - 40, t);
		//����
		if(PLAYER == tk.rc)
		{
			pictureDC.SelectObject(&player_name);
			supportDC.TransparentBlt(draw_x - 38, draw_y - 65, 175, 31, &pictureDC, 0, 0, 175, 31, RGB(255, 255, 255));
		}
		else
			supportDC.TextOutA(draw_x - 35, draw_y - 55, tk.name);
	}
	
	//������Ч -- �������ع�
	if(current_stage != -1 && Dialog_current_clock - tk.last_fire <= 300)
	{
		BLENDFUNCTION blendFunction;
		memset( &blendFunction, 0, sizeof(blendFunction) );
		blendFunction.BlendOp = AC_SRC_OVER;
		blendFunction.BlendFlags = 0;
		blendFunction.SourceConstantAlpha = 255 - (Dialog_current_clock - tk.t_last_hit) * 256 / 300;

		pictureDC.SelectObject(&fire_effect);
		if(UP == tk.orient)
			supportDC.AlphaBlend(draw_x + 35, draw_y, 10, 10, &pictureDC, 0, 0, 10, 10, blendFunction);
		else if(DOWN == tk.orient)
			supportDC.AlphaBlend(draw_x + 35, draw_y + 70, 10, 10, &pictureDC, 0, 0, 10, 10, blendFunction);
		else if(LEFT == tk.orient)
			supportDC.AlphaBlend(draw_x, draw_y + 20, 10, 10, &pictureDC, 0, 0, 10, 10, blendFunction);
		else
			supportDC.AlphaBlend(draw_x + 70, draw_y + 20, 10, 10, &pictureDC, 0, 0, 10, 10, blendFunction);


	}


	//������ը
	if(tk.die_time > 0 && Dialog_current_clock - tk.die_time <= 1000) 
	{
		BLENDFUNCTION blendFunction;
		memset( &blendFunction, 0, sizeof(blendFunction) );
		blendFunction.BlendOp = AC_SRC_OVER;
		blendFunction.BlendFlags = 0;
		blendFunction.SourceConstantAlpha = 255 - (Dialog_current_clock - tk.die_time) * 128 / 1000;


		memDC.BitBlt(0, 0, 80, 80, &supportDC, draw_x, draw_y, SRCCOPY);
		pictureDC.SelectObject(&boom);
		memDC.TransparentBlt(0, 0, 80, 80, &pictureDC, 0, 0, 80, 80, RGB(255, 255, 255));

	
	
		supportDC.AlphaBlend(draw_x, draw_y, 80, 80, &memDC, 0, 0, 80, 80, blendFunction); 

		CString t;
		t.Format(" %4d / %4d ", tk.current_hitpoint, tk.max_hitpoint);

		//-40 - 65 ��ʼ   200  80
		memDC2.BitBlt(0, 0, 250, 80, &supportDC, draw_x - 40, draw_y - 65, SRCCOPY);
		memDC2.TextOutA(2, 0, tk.name);
		memDC2.TextOutA(0, 25, t);
		memDC2.FillSolidRect(28, 47, 104, 15, RGB(0, 0, 0));
		BLENDFUNCTION blendFunction2;
		memset( &blendFunction2, 0, sizeof(blendFunction2) );
		blendFunction2.BlendOp = AC_SRC_OVER;
		blendFunction2.BlendFlags = 0;
		blendFunction2.SourceConstantAlpha = 128;
		pictureDC.SelectObject(&pro_clt);
		memDC2.AlphaBlend(30, 49, 100, 11, &pictureDC, 0, 0, 200, 35, blendFunction2);



		supportDC.AlphaBlend(draw_x - 40, draw_y - 65, 250, 80, &memDC2, 0, 0, 250, 80, blendFunction);
	}	

	//�˺����� -- ����
	if(Dialog_current_clock - tk.t_last_hit <= 1000)
	{
		BLENDFUNCTION blendFunction;
		memset( &blendFunction, 0, sizeof(blendFunction) );
		blendFunction.BlendOp = AC_SRC_OVER;
		blendFunction.BlendFlags = 0;
		blendFunction.SourceConstantAlpha = 255 - (Dialog_current_clock - tk.t_last_hit) * 128 / 1000;



		memDC.FillSolidRect(0, 0, 200, 100, RGB(255, 255, 255));
	



		if(UNPENERTRATE == tk.last_hit_result) //ǰ��������Ϊ��ɫ����
			memDC.SetTextColor(RGB(0, 0, 128));
		else if(EFFECTIVE_PENERTRATED == tk.last_hit_result)//���󱻻���Ϊ��ɫ����
			memDC.SetTextColor(RGB(128, 0, 0));
		else // ���� Ϊ  ��ɫ
			memDC.SetTextColor(RGB(128, 128, 0));
		CString t;
		t.Format(" -%d ", tk.last_hit);
		memDC.TextOutA(0, 0, t);

		//�ڶ��Σ���ӰЧ����
		if(UNPENERTRATE == tk.last_hit_result) //ǰ��������Ϊ��ɫ����
			memDC.SetTextColor(RGB(0, 0, 255));
		else if(EFFECTIVE_PENERTRATED == tk.last_hit_result)//���󱻻���Ϊ��ɫ����
			memDC.SetTextColor(RGB(255, 0, 0));
		else // ���� Ϊ  ��ɫ
			memDC.SetTextColor(RGB(255, 255, 0));
		memDC.TextOutA(3, 3, t);



		memDC2.BitBlt(0, 0, 200, 100, &supportDC, draw_x  - 45, draw_y, SRCCOPY);
		memDC2.TransparentBlt(0, 0, 200, 100, &memDC, 0, 0, 200, 100, RGB(255, 255, 255));


		supportDC.AlphaBlend(draw_x  - 45, draw_y, 200, 100, &memDC2, 0, 0, 200, 100, blendFunction);
	}

	//�ڵ���� + ����
	if(tk.shell_on_field && tk.shell_infor.pos_x < FIELD_WIDTH - 12 && tk.shell_infor.pos_y < FIELD_HEIGHT) 
	{
		//�з��ڵ�
		if(p == 1)
			pictureDC.SelectObject(shell);
		//�Ѿ��ڵ�
		else if(p == 2)
			pictureDC.SelectObject(shell_f);


		//��һ��
		supportDC.TransparentBlt(tk.shell_infor.pos_x - SHELL_WIDTH/2, tk.shell_infor.pos_y - SHELL_WIDTH/2, SHELL_WIDTH, SHELL_WIDTH, &pictureDC, 0, 0, SHELL_WIDTH, SHELL_WIDTH, RGB(255, 255, 255));


		//������������Ч��
		BLENDFUNCTION blendFunction;
		memset( &blendFunction, 0, sizeof(blendFunction) );
		blendFunction.BlendOp = AC_SRC_OVER;
		blendFunction.BlendFlags = 0;
		blendFunction.SourceConstantAlpha = 128;


		int d_x = tk.shell_infor.pos_x;
		int d_y = tk.shell_infor.pos_y;

		int d_move = tk.shell_infor.speed / 6;

		int k = 3;
		while(k -- && tk.shell_infor.distance)
		{

			if(UP == tk.shell_infor.orient)
				d_y += d_move;
			else if(DOWN == tk.shell_infor.orient)
				d_y -= d_move;
			else if(LEFT == tk.shell_infor.orient)
				d_x += d_move;
			else 
				d_x -= d_move;

			memDC.BitBlt(0, 0, SHELL_WIDTH, SHELL_WIDTH, &supportDC, d_x - 12, d_y - 12, SRCCOPY);
			memDC.TransparentBlt(0, 0, SHELL_WIDTH, SHELL_WIDTH, &pictureDC, 0, 0, SHELL_WIDTH, SHELL_WIDTH, RGB(255, 255, 255));
			supportDC.AlphaBlend(d_x - 12, d_y - 12, 24, 24, &memDC, 0, 0, 24, 24, blendFunction);
			blendFunction.SourceConstantAlpha -= 42;
		}

		//supportDC.BitBlt(tk.shell_infor.pos_x - SHELL_WIDTH/2, tk.shell_infor.pos_y - SHELL_WIDTH/2, SHELL_WIDTH, SHELL_WIDTH, &pictureDC, 0, 0, SRCCOPY);
	}
}

void C̹�˴�սϵ��Dlg::StateDC_Basic_Infor_Draw(void)
{
	// ����ֵ װ����Ϣ����
	CString str1;
	CString w_str;
	CString d_str;
	int curr_y = 390;

	//ʤ�ܣ���������
	//ʱ�������  ��  235 ����  275 Ѫ��
	if(c_v_t == V_TLE)
	{
		w_str.Format("��־���ʤ��");
	}
	else if(c_v_t == V_KVP)
	{
		w_str.Format("��������    ");
	}
	else if(c_v_t == V_KNE)
	{
		w_str.Format("ɱ���Ӻ�    ");

	}
	else if(c_v_t == V_STD)
	{
		w_str.Format("ͨͨ�䱬    ");
	}
	else
	{
		w_str.Format("");
	}

	//ʧ������������
	if(c_d_t == D_NSH)
	{
		d_str.Format("���ʱ��ҪС��");

	}
	else if(c_d_t == D_TLE)
	{
		d_str.Format("ʱ����ǽ�Ǯ  ");
	}
	else if(c_d_t == D_LVP)
	{
		d_str.Format("����Ŀ��      ");
	}
	else if(c_d_t == D_LNA)
	{
		d_str.Format("��������      ");
	}
	else if(c_d_t == D_DLD)
	{
		d_str.Format("Ϊ����ҫ      ");
	}
	else 
	{
		d_str.Format("");
	}

	//��һ�����

	stateDC.SetTextColor(RGB(112, 112, 0));
	stateDC.TextOutA(38, 100, "�ڵ�װ�����");
	stateDC.TextOutA(38, 165, "����ֵ");
	stateDC.TextOutA(38, curr_y, stage_name.c_str());

	if(current_stage != -1)
	{
		pictureDC.SelectObject(&enemy_infor);
		stateDC.TransparentBlt(38, 20, 111, 29, &pictureDC, 0, 0, 111, 29, RGB(255, 255, 255));


		str1.Format(" %3d / %3d", enemys, all_enemys);
		stateDC.TextOutA(150, 20, str1);


		pictureDC.SelectObject(&allience_infor);
		stateDC.TransparentBlt(38, 60, 110, 30, &pictureDC, 0, 0, 110, 30, RGB(255, 255, 255));

		str1.Format(" %3d / %3d ", alliences, all_alliences);
		stateDC.TextOutA(150, 60, str1);
	}
	stateDC.TextOutA(38, 235, w_str); 
	stateDC.TextOutA(38, 300, d_str);

	stateDC.TextOutA(258, 200, "��Ч�˺�");
	CString c_dmg;
	if(Dialog_current_clock <= t_last_dmg_cause + 1000)
		c_dmg.Format("%+6d", last_dmg_cause);
	else
		c_dmg.Format("%7d", tank1.dmg_cause);
	stateDC.TextOutA(258, 230, c_dmg);
	stateDC.TextOutA(258, 265, "�����˺�");
	CString c_resist;
	c_resist.Format("%7d", tank1.dmg_recv);
	stateDC.TextOutA(258, 295, c_resist);


	stateDC.TextOutA(258, 330, "��ǰ����");
	CString c_speed;
	c_speed.Format("%2d", tank1.Current_Speed);
	stateDC.TextOutA(298, 360, c_speed);



	stateDC.SetTextColor(RGB(223, 223, 0));
	stateDC.TextOutA(40, 100, "�ڵ�װ�����");
	stateDC.TextOutA(40, 165, "����ֵ");
	stateDC.TextOutA(40, curr_y, stage_name.c_str());
	if(current_stage != -1)
	{
		str1.Format(" %3d / %3d", enemys, all_enemys);
		stateDC.TextOutA(152, 20, str1);
		str1.Format(" %3d / %3d ", alliences, all_alliences);


	}
	stateDC.TextOutA(152, 60, str1);
	stateDC.TextOutA(40, 235, w_str);
	stateDC.TextOutA(40, 300, d_str);

	stateDC.TextOutA(260, 200, "��Ч�˺�");
	stateDC.TextOutA(260, 230, c_dmg);
	stateDC.TextOutA(260, 265, "�����˺�");
	stateDC.TextOutA(260, 295, c_resist);

	stateDC.TextOutA(260, 330, "��ǰ����");
	stateDC.TextOutA(300, 360, c_speed);


	curr_y  = 435;
	//�Ѷ�
	if(Player_Tank::difficulty == 2)
	{
		stateDC.SetTextColor(RGB(128, 0, 0));
		stateDC.TextOutA(38, curr_y, "����");

		stateDC.SetTextColor(RGB(255, 0, 0));
		stateDC.TextOutA(40, curr_y, "����");
	}
	else if(Player_Tank::difficulty == 1)
	{
		stateDC.SetTextColor(RGB(128, 64, 0));
		stateDC.TextOutA(38, curr_y, "��ͨ");

		stateDC.SetTextColor(RGB(255, 128, 0));
		stateDC.TextOutA(40, curr_y, "��ͨ");
	}
	else if(Player_Tank::difficulty == 0)
	{
		stateDC.SetTextColor(RGB(0, 0, 128));
		stateDC.TextOutA(38, curr_y, "��");

		stateDC.SetTextColor(RGB(0, 0, 255));
		stateDC.TextOutA(40, curr_y, "��");
	}
	else
	{
		stateDC.SetTextColor(RGB(128, 128, 128));
		stateDC.TextOutA(38, curr_y, "����");

		stateDC.SetTextColor(RGB(255, 255, 255));
		stateDC.TextOutA(40, curr_y, "����");
	}

	//�ӽ�
	if(view_orient == UP)
	{
		stateDC.SetTextColor(RGB(128, 128, 128));
		stateDC.TextOutA(148, curr_y, "�ӽ��Ϸ�");

		stateDC.SetTextColor(RGB(255, 255, 255));
		stateDC.TextOutA(150, curr_y, "�ӽ��Ϸ�");
	}

	else if(view_orient == DOWN)
	{
		stateDC.SetTextColor(RGB(128, 128, 128));
		stateDC.TextOutA(148, curr_y, "�ӽ��·�");

		stateDC.SetTextColor(RGB(255, 255, 255));
		stateDC.TextOutA(150, curr_y, "�ӽ��·�");
	}
	else if(view_orient == LEFT)
	{
		stateDC.SetTextColor(RGB(128, 128, 128));
		stateDC.TextOutA(148, curr_y, "�ӽ����");

		stateDC.SetTextColor(RGB(255, 255, 255));
		stateDC.TextOutA(150, curr_y, "�ӽ����");
	}
	else if(view_orient == RIGHT)
	{
		stateDC.SetTextColor(RGB(128, 128, 128));
		stateDC.TextOutA(148, curr_y, "�ӽ��Ҳ�");

		stateDC.SetTextColor(RGB(255, 255, 255));
		stateDC.TextOutA(150, curr_y, "�ӽ��Ҳ�");
	}
	else if(view_orient == STOP)
	{
		stateDC.SetTextColor(RGB(128, 128, 128));
		stateDC.TextOutA(148, curr_y, "�ӽ�����");

		stateDC.SetTextColor(RGB(255, 255, 255));
		stateDC.TextOutA(150, curr_y, "�ӽ�����");
	}

	//Ѫ�� ��������
	//װ��״̬����
	stateDC.FillSolidRect(40, 130, 200, 35, RGB(255, 255, 255));
	int index = float (clock() - tank1.last_fire) * 100 / (tank1.fire_interval * FIRE_NERF);
	if(index > 100)
		index = 100;
	if(index != 100)
	{
		int x = 40;
		int y = 130;

		//���������
		pictureDC.SelectObject(&pro_clt);
		Standard_Pro_Ctrl_Draw(x, y , 200, 35, index, &pictureDC, &stateDC, RGB(255, 255, 255), RGB(240 - 1.4 * index, 100 + 1.4 * index, 100), 180); 
	}
	else
	{
		int x = 40;
		int y = 130;

		//���������
		pictureDC.SelectObject(&pro_clt);
		Standard_Pro_Ctrl_Draw(x, y , 200, 35, index, &pictureDC, &stateDC, RGB(255, 255, 255), RGB(100, 100, 240), 180); 
	}
	//����״̬����
	int r_time = RECOVER_TIME;
	if(Player_Tank::upgrade_generation)
	{
		r_time /= 2;;
	}
	if(Dialog_current_clock - tank1.t_last_effect_hit <= r_time)
		stateDC.SetTextColor(RGB(255, 128, 0));
	else
		stateDC.SetTextColor(RGB(223, 223, 0));


	//Ѫ��
	CString t;
	t.Format(" %4d / %4d ", tank1.current_hitpoint, tank1.max_hitpoint);
	stateDC.TextOutA(160, 165, t);

	index = float (tank1.current_hitpoint * 100)/ tank1.max_hitpoint;



	//Ѫ������
	//Ѫ�����
	pictureDC.SelectObject(&pro_clt);
	stateDC.BitBlt(40, 195, 200, 35, &pictureDC, 0, 0, SRCCOPY);

	//Ѫ����
	blackBackDC.FillSolidRect(0, 0, 200, 35, RGB(0, 0, 0));

	//��ǰ���ֵѪ��
	int index2 = float (tank1.current_max_hitpoint * 100)/ tank1.max_hitpoint;
	blackBackDC.FillSolidRect(0, 0, 2 * index2, 35, RGB(190, 190, 190));

	//��ǰѪ�� -- �����ж�ʱ����ɫ�����ɫ�˺����⣩
	if(Dialog_current_clock - tank1.t_last_effect_hit > r_time)
	{
		blackBackDC.FillSolidRect(0, 0, 2 * index, 35, RGB(240 - 1.4 * index, 100 + 1.4 * index, 100));
	}
	else
	{
		blackBackDC.FillSolidRect(0, 0, 2 * index, 35, RGB(120 - 0.7 * index, 50 + 0.7 * index, 50));
	}

	//ͳһ��ɫ����
	BLENDFUNCTION blendFunction;
	memset( &blendFunction, 0, sizeof(blendFunction) );
	blendFunction.BlendOp = AC_SRC_OVER;
	blendFunction.BlendFlags = 0;
	blendFunction.SourceConstantAlpha = 180;
	stateDC.AlphaBlend(40, 195, 200, 35, &blackBackDC, 0, 0, 200, 35, blendFunction);
	//Ѫ�����ƽ���




	//������
	//ʤ������������
	if(c_v_t == V_TLE)
	{
		index = 100 - (v_addtion_param - clock()) * 100 / v_addtion_time;
	}
	else if(c_v_t == V_KVP)
	{
		index = 100 - (enemy_tanks[0].current_hitpoint) * 100 / enemy_tanks[0].max_hitpoint;

	}
	else if(c_v_t == V_KNE)
	{
		index = (NUM_OF_ENEMY - all_enemys) * 100 / v_addtion_param;

	}
	else if(c_v_t == V_STD)
	{
		if(current_stage != -1)
		{
			index = (NUM_OF_ENEMY - all_enemys) * 100 / NUM_OF_ENEMY;
		}
	}
	if(current_stage != -1)
	{
		int x = 40;
		int y = 265;

		//���������
		pictureDC.SelectObject(&pro_clt);
		Standard_Pro_Ctrl_Draw(x, y , 200, 35, index, &pictureDC, &stateDC, RGB(255, 255, 255), RGB(60 + index * 1, 100 + index * 1.5, 60 + index * 1), 180); 
	}



	//ʧ������������
	if(c_d_t == D_NSH)
	{
		index = (d_addtion_param + 1 - Player_Tank::use_shell)*100 / (d_addtion_param + 1);
	}
	else if(c_d_t == D_TLE)
	{
		index = (d_addtion_param - clock()) * 100 / d_addtion_time;
	}
	else if(c_d_t == D_LVP)
	{
		index = (allience_tanks[0].current_hitpoint) * 100 / allience_tanks[0].max_hitpoint;
	}
	else if(c_d_t == D_LNA)
	{
		int lose = NUM_OF_ALLIENCE - all_alliences;
		index = 100 - lose * 100 / d_addtion_param;
	}
	else if(c_d_t == D_DLD)
	{
		index = tank1.dmg_cause * 100 / d_addtion_param;
		if(index > 100)
			index = 100;
	}



	if(c_d_t != D_STD)
	{
		int x = 40;
		int y = 335;

		//���������
		pictureDC.SelectObject(&pro_clt);
		Standard_Pro_Ctrl_Draw(x, y , 200, 35, index, &pictureDC, &stateDC, RGB(255, 255, 255), RGB(60 + index * 1, 100 + index * 1.5, 60 + index * 1), 180); 
	}
}

void C̹�˴�սϵ��Dlg::StateDC_Draw_Litter_Map_And_View(void)
{

	//���ջ��� -- �͵�ǰλ���й�ϵ 
	int center_x = tank1.pos_x;
	int center_y = tank1.pos_y;

	//��ͬ�ӽ�

	//�����ʾ
	int x_s = tank1.pos_x - tank1.fire_range - 52;
	if(x_s < 0)
		x_s = 0;

	int x_e = tank1.pos_x + tank1.fire_range + 52;
	if(x_e > 3000)
		x_e = 3000; 

	int y_s = tank1.pos_y - tank1.fire_range - 52;
	if(y_s < 0)
		y_s = 0;

	int y_e = tank1.pos_y + tank1.fire_range + 52;
	if(y_e > 2000)
		y_e = 2000;


	
	//����2 -- Ŀǰ������ ת��ͷ��
	//��10֡ת����
	
	static int pro = 0;


	if(view_orient == LEFT)
	{
		pro ++;
		if(pro > 10 )
			pro = 10;

		center_x = tank1.pos_x - 65 * pro;
		center_y = tank1.pos_y;


	}
	else if(view_orient == RIGHT)
	{
		pro ++;
		if(pro > 10 )
			pro = 10;

		center_x = tank1.pos_x + 65 * pro;
		center_y = tank1.pos_y;
	}
	else if(view_orient == UP)
	{
		pro ++;
		if(pro > 10 )
			pro = 10;

		center_x = tank1.pos_x;
		center_y = tank1.pos_y - 40 * pro;
	}
	else if(view_orient == DOWN)
	{
		pro ++;
		if(pro > 10 )
			pro = 10;
		center_x = tank1.pos_x;
		center_y = tank1.pos_y + 40 * pro;
	}
	else if(view_orient == STOP)
	{
		pro --;
		if(pro < 0 )
			pro = 0;
		
		if(last_view_orient == UP)
		{
			center_x = tank1.pos_x;
			center_y = tank1.pos_y - 40 * pro;
		}
		else if(last_view_orient == DOWN)
		{
			center_x = tank1.pos_x;
			center_y = tank1.pos_y + 40 * pro;
		}
		else if(last_view_orient == LEFT)
		{
			center_x = tank1.pos_x - 65 * pro;
			center_y = tank1.pos_y;
		}
		else if(last_view_orient == RIGHT)
		{
			center_x = tank1.pos_x + 65 * pro;
			center_y = tank1.pos_y;
		}
		else
		{
			center_x = tank1.pos_x;
			center_y = tank1.pos_y;
		}
	}

	//��ҰԽ�紦��

	if(center_x > FIELD_WIDTH - 750)
		center_x = FIELD_WIDTH - 750;
	else if(center_x < 750)
		center_x = 750;
	if(center_y > FIELD_HEIGHT - 500)
		center_y = FIELD_HEIGHT - 500;
	else if(center_y < 500)
		center_y = 500;


	//�ܻ���ʾ
	
	if(Dialog_current_clock - tank1.t_last_hit <= 600)
	{
		BLENDFUNCTION blendFunction;
		memset( &blendFunction, 0, sizeof(blendFunction));
		blendFunction.BlendOp = AC_SRC_OVER;
		blendFunction.BlendFlags = 0;
		blendFunction.SourceConstantAlpha = (600 - (Dialog_current_clock - tank1.t_last_hit)) * 128 / 600;


		if(UP == tank1.last_hit_from)
		{
			pictureDC.SelectObject(&hit_up);
			memDC.BitBlt(0, 0, 200, 200, &supportDC, center_x - 100, center_y + 300, SRCCOPY);
			memDC.TransparentBlt(0, 0, 200, 200, &pictureDC, 0, 0, 200, 200, RGB(255, 255, 255));

			supportDC.AlphaBlend(center_x - 100, center_y + 300, 200, 200, &memDC, 0, 0, 200, 200, blendFunction); 
		}
		else if(DOWN == tank1.last_hit_from)
		{
			pictureDC.SelectObject(&hit_down);
			memDC.BitBlt(0, 0, 200, 200, &supportDC, center_x - 100, center_y - 500, SRCCOPY);
			memDC.TransparentBlt(0, 0, 200, 200, &pictureDC, 0, 0, 200, 200, RGB(255, 255, 255));

			supportDC.AlphaBlend(center_x - 100, center_y - 500, 200, 200, &memDC, 0, 0, 200, 200, blendFunction); 
		}
		else if(LEFT == tank1.last_hit_from)
		{
			pictureDC.SelectObject(&hit_left);
			memDC.BitBlt(0, 0, 200, 200, &supportDC, center_x + 550, center_y - 100, SRCCOPY);
			memDC.TransparentBlt(0, 0, 200, 200, &pictureDC, 0, 0, 200, 200, RGB(255, 255, 255));

			supportDC.AlphaBlend(center_x + 550, center_y - 100, 200, 200, &memDC, 0, 0, 200, 200, blendFunction); 
		}
		else if(RIGHT == tank1.last_hit_from)
		{
			pictureDC.SelectObject(&hit_right);
			memDC.BitBlt(0, 0, 200, 200, &supportDC, center_x - 750, center_y - 100, SRCCOPY);
			memDC.TransparentBlt(0, 0, 200, 200, &pictureDC, 0, 0, 200, 200, RGB(255, 255, 255));

			supportDC.AlphaBlend(center_x - 750, center_y - 100, 200, 200, &memDC, 0, 0, 200, 200, blendFunction); 
		}

	}
	


	


	int st_x = 40;
	int st_y = 460;

	CPen pen(PS_SOLID, 2, RGB(0, 0, 0)); //���׼��
	stateDC.SelectObject(&pen);
	//С��ͼָʾ��
	
	//��ͼ
	if(current_stage != -1)
		stateDC.FillSolidRect(st_x, st_y, 300, 200, RGB(150, 190, 255));
	else
		stateDC.FillSolidRect(st_x, st_y, 300, 200, RGB(255, 0, 0));
	//��ͼ���
	pictureDC.SelectObject(&main_hor_bkg);
	BLENDFUNCTION blendFunction;
	memset( &blendFunction, 0, sizeof(blendFunction) );
	blendFunction.BlendOp = AC_SRC_OVER;
	blendFunction.BlendFlags = 0;
	blendFunction.SourceConstantAlpha = 50;
	stateDC.AlphaBlend(st_x, st_y, 300, 200, &pictureDC, 0, 0, 1500, 1000, blendFunction);

	//�����ʾ
	if(current_stage != -1)
		stateDC.FillSolidRect(st_x + x_s / 10, st_y + y_s / 10, (x_e - x_s) / 10, (y_e - y_s) / 10, RGB(140, 230, 190));
	else
		stateDC.FillSolidRect(st_x + x_s / 10, st_y + y_s / 10, (x_e - x_s) / 10, (y_e - y_s) / 10, RGB(255, 255, 0));
	//�����ʾ���
	stateDC.AlphaBlend(st_x + x_s / 10, st_y + y_s / 10, (x_e - x_s) / 10, (y_e - y_s) / 10, &pictureDC, 0, 0, 1500, 1000, blendFunction);

		
	//��ǰ��Ұ
	if(current_stage != -1)
		stateDC.FillSolidRect(st_x + center_x/10 - 75, st_y + center_y/10 - 50, 150, 100, RGB(135, 150, 210));
	else
		stateDC.FillSolidRect(st_x + center_x/10 - 75, st_y + center_y/10 - 50, 150, 100, RGB(255, 128, 0));
	//��Ұ���
	pictureDC.SelectObject(&main_hor_bkg);
	stateDC.AlphaBlend(st_x + center_x/10 - 75, st_y + center_y/10 - 50, 150, 100, &pictureDC, 0, 0, 1500, 1000, blendFunction);

	//���׼��
	stateDC.MoveTo(st_x + tank1.pos_x/10, st_y + tank1.pos_y/10);
	if(tank1.orient == UP)
	{
		stateDC.LineTo(st_x + tank1.pos_x/10, st_y);
	}
	else if(tank1.orient == DOWN)
	{
		stateDC.LineTo(st_x + tank1.pos_x/10, st_y + 200);
	}
	else if(tank1.orient == LEFT)
	{
		stateDC.LineTo(st_x, st_y + tank1.pos_y/10);
	}
	else 
	{
		stateDC.LineTo(st_x + 300, st_y + tank1.pos_y/10);
	}



	//С��ͼ�Ѿ�
	for(int i = 0; i < NUM_OF_ALLIENCE; i++)
	{
		if(allience_tanks[i].current_hitpoint && allience_tanks[i].is_on_field ||(allience_tanks[i].die_time > 0 && Dialog_current_clock - allience_tanks[i].die_time <= 600))
		{
			if(c_d_t == D_LVP && i == 0) 
			{
				stateDC.FillSolidRect(st_x + allience_tanks[i].pos_x/10 - 4, st_y + allience_tanks[i].pos_y/10 - 4, 8, 8, RGB(255, 255, 0));
			}
			else if(allience_tanks[i].current_hitpoint)
			{
				if(i < NUM_OF_TEAMMATE)
					stateDC.FillSolidRect(st_x + allience_tanks[i].pos_x/10 - 4, st_y + allience_tanks[i].pos_y/10 - 4, 8, 8, RGB(0, 255, 255));
				else
					stateDC.FillSolidRect(st_x + allience_tanks[i].pos_x/10 - 4, st_y + allience_tanks[i].pos_y/10 - 4, 8, 8, RGB(0, 0, 255));
				// �Ѿ��߼���λ
				if(allience_tanks[i].icon == G_T2 || allience_tanks[i].icon == G_T2_B)
				{
					stateDC.FillSolidRect(st_x + allience_tanks[i].pos_x/10 - 2, st_y + allience_tanks[i].pos_y/10 - 2, 4, 4, RGB(255, 128, 0));
				}
			}
			else
			{
				stateDC.FillSolidRect(st_x + allience_tanks[i].pos_x/10 - 4, st_y + allience_tanks[i].pos_y/10 - 4, 8, 8, RGB(255, 255, 255));
			}
		}
	}

	if(current_stage != -1)
	{
		//С��ͼ�о�
		for(int i = 0; i < NUM_OF_ENEMY; i++)
		{

			if(enemy_tanks[i].current_hitpoint && enemy_tanks[i].is_on_field ||(enemy_tanks[i].die_time > 0 && Dialog_current_clock - enemy_tanks[i].die_time <= 600))
			{
				if(c_v_t == V_KVP && i == 0 && enemy_tanks[i].current_hitpoint) // �о�VPΪ��ɫ
				{
					stateDC.FillSolidRect(st_x + enemy_tanks[i].pos_x/10 - 4, st_y + enemy_tanks[i].pos_y/10 - 4, 8, 8, RGB(128, 0, 255));
				}
				else if(enemy_tanks[i].current_hitpoint)
				{
					stateDC.FillSolidRect(st_x + enemy_tanks[i].pos_x/10 - 4, st_y + enemy_tanks[i].pos_y/10 - 4, 8, 8, RGB(255, 0, 0));
					// �о��߼���λ
					if(enemy_tanks[i].icon == USSR_T3)
					{
						stateDC.FillSolidRect(st_x + enemy_tanks[i].pos_x/10 - 2, st_y + enemy_tanks[i].pos_y/10 - 2, 4, 4, RGB(255, 128, 0));
					}
					else if(enemy_tanks[i].icon == USSR_T4)
					{
						stateDC.FillSolidRect(st_x + enemy_tanks[i].pos_x/10 - 2, st_y + enemy_tanks[i].pos_y/10 - 2, 4, 4, RGB(128, 0, 255));
					}
				}
				else //������ը
					stateDC.FillSolidRect(st_x + enemy_tanks[i].pos_x/10 - 4, st_y + enemy_tanks[i].pos_y/10 - 4, 8, 8, RGB(0, 0, 0));

			}
		}
	}


	//С��ͼ����
	if(current_stage != -1)
		stateDC.FillSolidRect(st_x + tank1.pos_x/10 - 4, st_y + tank1.pos_y/10 - 4, 8, 8, RGB(0, 255, 0));
	else
		stateDC.FillSolidRect(st_x + tank1.pos_x/10 - 4, st_y + tank1.pos_y/10 - 4, 8, 8, RGB(255, 255, 0));

	//С��ͼ�л��������Լ����ڵ�
	if(tank1.shell_on_field)
	{
		stateDC.FillSolidRect(st_x + tank1.shell_infor.pos_x/10 - 2, st_y + tank1.shell_infor.pos_y/10 - 2, 4, 4, RGB(255, 255, 0));
	}




	//��Ļ���ѳ̶�
	int degreer = tank1.current_hitpoint * 100 / tank1.max_hitpoint;
	pictureDC.SelectObject(&hor_state);
	temp_DC.BitBlt(0, 0, 1500, 1000, &pictureDC, 0, 0, SRCCOPY);

	//�̶ȿ���
	temp_DC.FillSolidRect(1.875 * (100 - degreer), 1.25 * (100 - degreer), 3.75 * (degreer + 300), 2.5 * (degreer + 300), RGB(0, 0, 0));
	//����Ǩ��
	supportDC.TransparentBlt(center_x - 750, center_y - 500,1500, 1000, &temp_DC, 0, 0, 1500, 1000, RGB(0, 0, 0));








	//���ӽǱ��������� -- ���ĵƹ�Ч��
	pictureDC.SelectObject(&main_hor_bkg);
	BLENDFUNCTION blendFunction2;
	memset( &blendFunction2, 0, sizeof(blendFunction2) );
	blendFunction2.BlendOp = AC_SRC_OVER;
	blendFunction2.BlendFlags = 0;
	blendFunction2.SourceConstantAlpha = 128;
	supportDC.AlphaBlend(center_x - 750, center_y - 500, 1500, 1000, &pictureDC, 0,0, 1500, 1000, blendFunction2);
	

	
	//����2 ʹ��SRCAND
	//supportDC.StretchBlt(center_x - 750, center_y - 500, 1500, 1000, &pictureDC, 0,0, 1500, 1000, SRCAND);



	//���ջ��� �Ӻ�̨ת��ǰ̨
#ifdef LOW_DENSITY
	pDC->StretchBlt(0, 0, 1000, 666, &supportDC, center_x - 750, center_y - 500, 1500, 1000, SRCCOPY);
	pDC->StretchBlt(1000, 0, 266, 666, &stateDC, 0, 0, 400, 1000, SRCCOPY);
#else
	pDC->BitBlt(VIEW_WIDTH, 0, SUBVIEW_WIDTH, SUBVIEW_HEIGHT, &stateDC, 0, 0, SRCCOPY);
	pDC->BitBlt(0, 0, VIEW_WIDTH, VIEW_HEIGHT, &supportDC, center_x - 750, center_y - 500, SRCCOPY);
#endif
	
	
	
}

void C̹�˴�սϵ��Dlg::StateDC_Additional_Ability_Draw(void)
{
	int curr_y = 660;
	//�������
	if(Player_Tank::upgrade_engine && tank1.Max_Speed > tank1.init_max_speed)
	{
		stateDC.SetTextColor(RGB(128, 30, 90));
		stateDC.TextOutA(38, curr_y, "�������������");
		
		stateDC.SetTextColor(RGB(255, 60, 180));
		stateDC.TextOutA(40, curr_y, "�������������");
	}
	else if(Player_Tank::upgrade_engine == 1)
	{
		stateDC.SetTextColor(RGB(90, 0, 90));
		stateDC.TextOutA(38, curr_y, "�������δ����");

		stateDC.SetTextColor(RGB(180, 0, 180));
		stateDC.TextOutA(40, curr_y, "�������δ����");
	}
	else
	{
		stateDC.SetTextColor(RGB(223, 223, 0));	
		stateDC.TextOutA(40, curr_y, "Finish Stage7 to Unlock");
	}

	//С��ָ��
	curr_y = 700;
	if(Player_Tank::upgrade_command)
	{
		stateDC.SetTextColor(RGB(0, 128, 64));
		if(instruct == 1)
			stateDC.TextOutA(38, curr_y, "С��ָ�����");
		else if(instruct == 2)
			stateDC.TextOutA(38, curr_y, "С��ָ�����");
		else if(instruct == 3)
			stateDC.TextOutA(38, curr_y, "С��ָ�ͻϮ");
		else if(instruct == 4)
			stateDC.TextOutA(38, curr_y, "С��ָ�ǣ��");
		else
			stateDC.TextOutA(38, curr_y, "�ȴ��µ�С��ָ��");

		stateDC.SetTextColor(RGB(0, 255, 128));
		if(instruct == 1)
			stateDC.TextOutA(40, curr_y, "С��ָ�����");
		else if(instruct == 2)
			stateDC.TextOutA(40, curr_y, "С��ָ�����");
		else if(instruct == 3)
			stateDC.TextOutA(40, curr_y, "С��ָ�ͻϮ");
		else if(instruct == 4)
			stateDC.TextOutA(40, curr_y, "С��ָ�ǣ��");
		else
			stateDC.TextOutA(40, curr_y, "�ȴ��µ�С��ָ��");
	}
	else
	{
		stateDC.SetTextColor(RGB(223, 223, 0));	
		stateDC.TextOutA(40, curr_y, "��ɵ�12���Խ���");
	}


	//����֮��
	curr_y = 740;
	if(Player_Tank::upgrade_generation && (Dialog_current_clock - tank1.t_last_effect_hit > 800))
	{
		stateDC.SetTextColor(RGB(0, 128, 0));
		stateDC.TextOutA(38, curr_y, "Recover Storm Actived");

		stateDC.SetTextColor(RGB(0, 255, 0));
		stateDC.TextOutA(40, curr_y, "Recover Storm Actived");
	}
	else if(Player_Tank::upgrade_generation)
	{
		stateDC.SetTextColor(RGB(80, 80, 0));
		stateDC.TextOutA(38, curr_y, "Recover Storm Inactived");

		stateDC.SetTextColor(RGB(160, 160, 0));
		stateDC.TextOutA(40, curr_y, "Recover Storm Inactived");
	}
	else
	{
		stateDC.SetTextColor(RGB(223, 223, 0));	
		stateDC.TextOutA(40, curr_y, "Test in particular stage");
	}

	curr_y = 780;
	//������װ�� ��ռ���У�
	if(Player_Tank::upgrade_gun)
	{
		if(Dialog_current_clock <= gun_up_to)
		{
			stateDC.SetTextColor(RGB(128, 128, 60));	
			stateDC.TextOutA(38, curr_y, "������װ���");

			stateDC.SetTextColor(RGB(255, 255, 0));	
			stateDC.TextOutA(40, curr_y, "������װ���");

			int index = (gun_up_to - Dialog_current_clock) * 100 / T_UPGRADE_GUN;
			stateDC.FillSolidRect(40, curr_y + 40, 200, 35, RGB(0, 0, 0));
			stateDC.FillSolidRect(40, curr_y + 40, 2 * index, 35, RGB(240 - index * 1.4, 100 + index * 1.4, 100));
		}
		else
		{
			if(Player_Tank::energy < MAX_ENERGY)
			{
				stateDC.SetTextColor(RGB(30, 128, 90));	
				stateDC.TextOutA(38, curr_y, "������װ�������");

				stateDC.SetTextColor(RGB(60, 255, 180));	
				stateDC.TextOutA(40, curr_y, "������װ�������");
				int index = Player_Tank::energy * 100 / MAX_ENERGY;
				stateDC.FillSolidRect(40, curr_y + 40, 200, 35, RGB(255, 255, 255));
				stateDC.FillSolidRect(40, curr_y + 40, 2 * index , 35, RGB(240 - 1.4 * index, 100 + 1.4 * index, 100));

			}
			else
			{
				stateDC.SetTextColor(RGB(128, 64, 0));	
				stateDC.TextOutA(38, curr_y, "������װ��������");

				stateDC.SetTextColor(RGB(255, 128, 0));	
				stateDC.TextOutA(40, curr_y, "������װ��������");
				stateDC.FillSolidRect(40, curr_y + 40, 200, 35, RGB(100, 100, 240));
			}
		}
		BLENDFUNCTION blendFunction2;
		memset( &blendFunction2, 0, sizeof(blendFunction2) );
		blendFunction2.BlendOp = AC_SRC_OVER;
		blendFunction2.BlendFlags = 0;
		blendFunction2.SourceConstantAlpha = 128;
		pictureDC.SelectObject(&pro_clt);
		stateDC.AlphaBlend(40, curr_y + 40, 200, 35, &pictureDC, 0, 0, 200, 35, blendFunction2);


	}
	else
	{
		stateDC.SetTextColor(RGB(223, 223, 0));	
		stateDC.TextOutA(40, curr_y, "Test in particular stage");
	}
}

void C̹�˴�սϵ��Dlg::StateDC_Special_Reming(void)
{
	stateDC.SetTextColor(RGB(223, 223, 0));
	//������Ҫ�¼���ʾ
	if(current_stage == 11 && Dialog_current_clock - stage_begin_time <= 150000)
	{
		CString h;
		h.Format("�����Ѿ���Ԯ���� %d ��    ", (150000 - Dialog_current_clock + stage_begin_time) / 1000);
		stateDC.TextOutA(40, 960, h);
	}
	else if(current_stage == 11)
	{
		CString h;
		h.Format("�Ѿ�֧Ԯ�Ѿ�����        ");
		stateDC.TextOutA(40, 960, h);
	}
	else if(current_stage == 13 && Dialog_current_clock - stage_begin_time <= 25000)
	{
		CString h;
		h.Format("����о��������� %d ��    ", (25000 - Dialog_current_clock + stage_begin_time) / 1000);
		stateDC.TextOutA(40, 960, h);
	}
	else if(current_stage == 13)
	{
		CString h;
		h.Format("�о��Ѿ���ʼ����        ");
		stateDC.TextOutA(40, 960, h);
	}
}

void C̹�˴�սϵ��Dlg::StateDC_Damage_State_Draw(void)
{
	int curr_y = 425;
	//�����Ƿ�����
	if(tank1.is_engine_damage)
	{
		stateDC.SetTextColor(RGB(128, 0, 0));
		stateDC.TextOutA(28, 880, "��������");

		stateDC.SetTextColor(RGB(255, 0, 0));
		stateDC.TextOutA(30, 880, "��������");

			
		//�����޸�������
		//stateDC.FillSolidRect(160, 880, 200, 35, RGB(0, 0, 0));
		int index = (Dialog_current_clock - tank1.t_last_fital_hit) * 100 / (ENGINE_REPAIR_TIME);

		int x = 160;
		int y = 880;

		//���������
		pictureDC.SelectObject(&pro_clt);
		Standard_Pro_Ctrl_Draw(x, y , 200, 35, index, &pictureDC, &stateDC, RGB(0, 0, 0), RGB(240 - 1.4 * index, 100 + 1.4 * index, 100), 180); 
	}
	
	else
	{
		stateDC.SetTextColor(RGB(112, 112, 0));
		stateDC.TextOutA(28, 880, "��������");

		stateDC.SetTextColor(RGB(223, 223, 0));
		stateDC.TextOutA(30, 880, "��������");

		int cx = 160;
		int cy = 880;

		//���������
		pictureDC.SelectObject(&pro_clt);
		stateDC.BitBlt(cx, cy, 200, 35, &pictureDC, 0, 0, SRCCOPY);


		//����������
		blackBackDC.FillSolidRect(0, 0, 200 , 35, RGB(0, 0, 0));
		//ǰ����ɫ����
		blackBackDC.FillSolidRect(0, 0, 200, 35, RGB(100, 100, 240));

		BLENDFUNCTION blendFunction;
		memset( &blendFunction, 0, sizeof(blendFunction) );
		blendFunction.BlendOp = AC_SRC_OVER;
		blendFunction.BlendFlags = 0;
		blendFunction.SourceConstantAlpha = 180;
		stateDC.AlphaBlend(cx, cy, 200 , 35, &blackBackDC, 0, 0, 200, 35, blendFunction);

		

	}
	
	//�����Ƿ�����
	if(tank1.is_gun_damage)
	{
		stateDC.SetTextColor(RGB(128, 64, 0));
		stateDC.TextOutA(28, 920, "��������");

		stateDC.SetTextColor(RGB(255, 128, 0));
		stateDC.TextOutA(30, 920, "��������");


		//stateDC.FillSolidRect(160, 920, 200, 35, RGB(0, 0, 0));
		int index = (Dialog_current_clock - tank1.t_last_gun_hit) * 100 / (GUN_REPAIR_TIME);
		int x = 160;
		int y = 920;

		//���������
		pictureDC.SelectObject(&pro_clt);
		Standard_Pro_Ctrl_Draw(x, y , 200, 35, index, &pictureDC, &stateDC, RGB(0, 0, 0), RGB(240 - 1.4 * index, 100 + 1.4 * index, 100), 180); 
	}
	
	else
	{

		int cx = 160;
		int cy = 920;

		//���������
		pictureDC.SelectObject(&pro_clt);


		stateDC.BitBlt(cx, cy, 200, 35, &pictureDC, 0, 0, SRCCOPY);


		//����������
		blackBackDC.FillSolidRect(0, 0, 200 , 35, RGB(0, 0, 0));
		//ǰ����ɫ����
		blackBackDC.FillSolidRect(0, 0, 200, 35, RGB(100, 100, 240));

		BLENDFUNCTION blendFunction;
		memset( &blendFunction, 0, sizeof(blendFunction) );
		blendFunction.BlendOp = AC_SRC_OVER;
		blendFunction.BlendFlags = 0;
		blendFunction.SourceConstantAlpha = 180;
		stateDC.AlphaBlend(cx, cy, 200 , 35, &blackBackDC, 0, 0, 200, 35, blendFunction);


		stateDC.SetTextColor(RGB(112, 112, 0));
		stateDC.TextOutA(28, 920, "��������");

		stateDC.SetTextColor(RGB(223, 223, 0));
		stateDC.TextOutA(30, 920, "��������");
	}
}

//1150��
void C̹�˴�սϵ��Dlg::Draw_Fire_Control(void)
{
	//ûװ���ڵ���ʱ�򲻻�
	if(Dialog_current_clock < tank1.last_fire + tank1.fire_interval * FIRE_NERF - 100)
		return ;

	//���ϵͳ
	//��׼����
	CPen t(BS_SOLID, 6, RGB(0, 0, 0)); // δѡ��
	CPen pen_in(BS_SOLID, 6, RGB(0, 128, 255));
	CPen pen_out(BS_SOLID, 6, RGB(255, 0, 0) );
	supportDC.SelectObject(&t);

	//���ܴ���Ԥ��
	int is_select = 0;
	int select_index = -1;
	int d_min = 9999;
	int k_penertrate = 0;

	if(UP == tank1.orient) //����
	{
		//ѡ��Ŀ��
		for(int i = 0; i < NUM_OF_ENEMY; i++)
		{
			if(enemy_tanks[i].is_on_field && enemy_tanks[i].current_hitpoint)
			{
				if((enemy_tanks[i].pos_y <= tank1.pos_y) && (abs(tank1.pos_x - enemy_tanks[i].pos_x) <= 52) && (tank1.pos_y - enemy_tanks[i].pos_y < d_min))
				{
					is_select = 1;
					select_index = i;
					d_min = tank1.pos_y - enemy_tanks[i].pos_y;
				}
			}
		}
		if(is_select && d_min - 104 <= tank1.fire_range)
		{
			if(enemy_tanks[select_index].orient == UP)//����
			{
				k_penertrate = 100 * (tank1.penertrate_level - enemy_tanks[select_index].behind_ammor_level);
			}
			else if(enemy_tanks[select_index].orient == DOWN) //����
 			{
				k_penertrate = 100 * (tank1.penertrate_level - enemy_tanks[select_index].ammor_level);
			}
			else //����
			{
				k_penertrate = 100 * (tank1.penertrate_level - enemy_tanks[select_index].side_ammor_level);
			}
				
			//����
			if(k_penertrate <0)
				k_penertrate = 0;

			//����
			supportDC.SelectObject(&pen_out);
			supportDC.MoveTo(tank1.pos_x, tank1.pos_y - 40);
			supportDC.LineTo(tank1.pos_x, tank1.pos_y - 52 - tank1.fire_range);

			supportDC.SelectObject(&pen_in);
			supportDC.MoveTo(tank1.pos_x, tank1.pos_y - 40);
			if(k_penertrate < tank1.fire_range)
				supportDC.LineTo(tank1.pos_x, tank1.pos_y - 40 - k_penertrate - 12);
			else
				supportDC.LineTo(tank1.pos_x, tank1.pos_y - 40 - tank1.fire_range - 12);

			for(int i = 100; i < tank1.fire_range; i += 100)
			{
				if(i == k_penertrate + 100)
				{
					supportDC.SelectObject(&pen_out);
				}


				if(i % 500 != 0)
				{
					supportDC.MoveTo(tank1.pos_x - 10, tank1.pos_y - 40 - i);
					supportDC.LineTo(tank1.pos_x + 10, tank1.pos_y - 40 - i);
				}
				else
				{
					supportDC.MoveTo(tank1.pos_x - 20, tank1.pos_y - 40 - i);
					supportDC.LineTo(tank1.pos_x + 20, tank1.pos_y - 40 - i);
				}
			}


		}
		else
		{
			supportDC.MoveTo(tank1.pos_x, tank1.pos_y - 40);
			supportDC.LineTo(tank1.pos_x, tank1.pos_y - 52 - tank1.fire_range);
			for(int i = 100; i < tank1.fire_range; i += 100)
			{
				if(i % 500 != 0)
				{
					supportDC.MoveTo(tank1.pos_x - 10, tank1.pos_y - 40 - i);
					supportDC.LineTo(tank1.pos_x + 10, tank1.pos_y - 40 - i);
				}
				else
				{
					supportDC.MoveTo(tank1.pos_x - 20, tank1.pos_y - 40 - i);
					supportDC.LineTo(tank1.pos_x + 20, tank1.pos_y - 40 - i);
				}
			}
		}
	}

	else if(DOWN == tank1.orient)
	{
		//ѡ��Ŀ��
		for(int i = 0; i < NUM_OF_ENEMY; i++)
		{
			if(enemy_tanks[i].is_on_field && enemy_tanks[i].current_hitpoint)
			{
				if((enemy_tanks[i].pos_y >= tank1.pos_y) && (abs(tank1.pos_x - enemy_tanks[i].pos_x) <= 52) && (enemy_tanks[i].pos_y - tank1.pos_y < d_min))
				{
					is_select = 1;
					select_index = i;
					d_min = enemy_tanks[i].pos_y - tank1.pos_y;
				}
			}
		}
		if(is_select && d_min - 104 <= tank1.fire_range)
		{
			if(enemy_tanks[select_index].orient == DOWN)//����
			{
				k_penertrate = 100 * (tank1.penertrate_level - enemy_tanks[select_index].behind_ammor_level);
			}
			else if(enemy_tanks[select_index].orient == UP) //����
 			{
				k_penertrate = 100 * (tank1.penertrate_level - enemy_tanks[select_index].ammor_level);
			}
			else //����
			{
				k_penertrate = 100 * (tank1.penertrate_level - enemy_tanks[select_index].side_ammor_level);
			}
				
			//����
			if(k_penertrate <0)
				k_penertrate = 0;

			//����
			supportDC.SelectObject(&pen_out);
			supportDC.MoveTo(tank1.pos_x, tank1.pos_y + 40);
			supportDC.LineTo(tank1.pos_x, tank1.pos_y + 52 + tank1.fire_range);

			supportDC.SelectObject(&pen_in);
			supportDC.MoveTo(tank1.pos_x, tank1.pos_y + 40);
			if(k_penertrate < tank1.fire_range)
				supportDC.LineTo(tank1.pos_x, tank1.pos_y + 40 + k_penertrate + 12);
			else
				supportDC.LineTo(tank1.pos_x, tank1.pos_y + 40 + tank1.fire_range + 12);

			for(int i = 100; i < tank1.fire_range; i += 100)
			{
				if(i == k_penertrate + 100)
				{
					supportDC.SelectObject(&pen_out);
				}


				if(i % 500 != 0)
				{
					supportDC.MoveTo(tank1.pos_x - 10, tank1.pos_y + 40 + i);
					supportDC.LineTo(tank1.pos_x + 10, tank1.pos_y + 40 + i);
				}
				else
				{
					supportDC.MoveTo(tank1.pos_x - 20, tank1.pos_y + 40 + i);
					supportDC.LineTo(tank1.pos_x + 20, tank1.pos_y + 40 + i);
				}
			}
		}
		else
		{
			supportDC.MoveTo(tank1.pos_x, tank1.pos_y + 40);
			supportDC.LineTo(tank1.pos_x, tank1.pos_y + 52 + tank1.fire_range);
			for(int i = 100; i < tank1.fire_range; i += 100)
			{
				if(i % 500 != 0)
				{
					supportDC.MoveTo(tank1.pos_x - 10, tank1.pos_y + 40 + i);
					supportDC.LineTo(tank1.pos_x + 10, tank1.pos_y + 40 + i);
				}
				else
				{
					supportDC.MoveTo(tank1.pos_x - 20, tank1.pos_y + 40 + i);
					supportDC.LineTo(tank1.pos_x + 20, tank1.pos_y + 40 + i);
				}
			}
		}
	}
	else if(LEFT == tank1.orient)
	{
		//ѡ��Ŀ��
		for(int i = 0; i < NUM_OF_ENEMY; i++)
		{
			if(enemy_tanks[i].is_on_field && enemy_tanks[i].current_hitpoint)
			{
				if((enemy_tanks[i].pos_x <= tank1.pos_x) && (abs(tank1.pos_y - enemy_tanks[i].pos_y) <= 52) && (tank1.pos_x - enemy_tanks[i].pos_x < d_min))
				{
					is_select = 1;
					select_index = i;
					d_min = tank1.pos_x - enemy_tanks[i].pos_x;
				}
			}
		}
		if(is_select && d_min - 104 <= tank1.fire_range)
		{
			if(enemy_tanks[select_index].orient == LEFT)//����
			{
				k_penertrate = 100 * (tank1.penertrate_level - enemy_tanks[select_index].behind_ammor_level);
			}
			else if(enemy_tanks[select_index].orient == RIGHT) //����
 			{
				k_penertrate = 100 * (tank1.penertrate_level - enemy_tanks[select_index].ammor_level);
			}
			else //����
			{
				k_penertrate = 100 * (tank1.penertrate_level - enemy_tanks[select_index].side_ammor_level);
			}
			//����
			if(k_penertrate <0)
				k_penertrate = 0;

			//����
			supportDC.SelectObject(&pen_out);
			supportDC.MoveTo(tank1.pos_x - 40, tank1.pos_y);
			supportDC.LineTo(tank1.pos_x - 52 - tank1.fire_range, tank1.pos_y);

			supportDC.SelectObject(&pen_in);
			supportDC.MoveTo(tank1.pos_x - 40, tank1.pos_y);
			if(k_penertrate < tank1.fire_range)
				supportDC.LineTo(tank1.pos_x - 52 - k_penertrate, tank1.pos_y);
			else
				supportDC.LineTo(tank1.pos_x - 52 - tank1.fire_range, tank1.pos_y);

			for(int i = 100; i < tank1.fire_range; i += 100)
			{
				if(i == k_penertrate + 100)
				{
					supportDC.SelectObject(&pen_out);
				}


				if(i % 500 != 0)
				{
					supportDC.MoveTo(tank1.pos_x - 40 - i, tank1.pos_y + 10);
					supportDC.LineTo(tank1.pos_x - 40 - i, tank1.pos_y - 10);
				}
				else
				{
					supportDC.MoveTo(tank1.pos_x - 40 - i, tank1.pos_y + 20);
					supportDC.LineTo(tank1.pos_x - 40 - i, tank1.pos_y - 20);
				}
			}

		}
		else
		{
			supportDC.MoveTo(tank1.pos_x - 40, tank1.pos_y);
			supportDC.LineTo(tank1.pos_x - 52 - tank1.fire_range, tank1.pos_y);
			for(int i = 100; i < tank1.fire_range; i += 100)
			{
				if(i % 500 != 0)
				{
					supportDC.MoveTo(tank1.pos_x - 40 - i, tank1.pos_y + 10);
					supportDC.LineTo(tank1.pos_x - 40 - i, tank1.pos_y - 10);
				}
				else
				{
					supportDC.MoveTo(tank1.pos_x - 40 - i, tank1.pos_y + 20);
					supportDC.LineTo(tank1.pos_x - 40 - i, tank1.pos_y - 20);
				}
			}
		}
	}
	else if(RIGHT == tank1.orient)
	{
		//ѡ��Ŀ��
		for(int i = 0; i < NUM_OF_ENEMY; i++)
		{
			if(enemy_tanks[i].is_on_field && enemy_tanks[i].current_hitpoint)
			{
				if((enemy_tanks[i].pos_x >= tank1.pos_x) && (abs(tank1.pos_y - enemy_tanks[i].pos_y) <= 52) && (- tank1.pos_x + enemy_tanks[i].pos_x < d_min))
				{
					is_select = 1;
					select_index = i;
					d_min = enemy_tanks[i].pos_x - tank1.pos_x;
				}
			}
		}
		if(is_select && d_min - 104 <= tank1.fire_range)
		{
			if(enemy_tanks[select_index].orient == RIGHT)//����
			{
				k_penertrate = 100 * (tank1.penertrate_level - enemy_tanks[select_index].behind_ammor_level);
			}
			else if(enemy_tanks[select_index].orient == LEFT) //����
 			{
				k_penertrate = 100 * (tank1.penertrate_level - enemy_tanks[select_index].ammor_level);
			}
			else //����
			{
				k_penertrate = 100 * (tank1.penertrate_level - enemy_tanks[select_index].side_ammor_level);
			}
			//����
			if(k_penertrate <0)
				k_penertrate = 0;

			//����
			supportDC.SelectObject(&pen_out);
			supportDC.MoveTo(tank1.pos_x + 40, tank1.pos_y);
			supportDC.LineTo(tank1.pos_x + 52 + tank1.fire_range, tank1.pos_y);

			supportDC.SelectObject(&pen_in);
			supportDC.MoveTo(tank1.pos_x + 40, tank1.pos_y);

			if(k_penertrate < tank1.fire_range)
				supportDC.LineTo(tank1.pos_x + 52 + k_penertrate, tank1.pos_y);
			else
				supportDC.LineTo(tank1.pos_x + 52 + tank1.fire_range, tank1.pos_y);
			for(int i = 100; i < tank1.fire_range; i += 100)
			{
				if(i == k_penertrate + 100)
				{
					supportDC.SelectObject(&pen_out);
				}


				if(i % 500 != 0)
				{
					supportDC.MoveTo(tank1.pos_x + 40 + i, tank1.pos_y + 10);
					supportDC.LineTo(tank1.pos_x + 40 + i, tank1.pos_y - 10);
				}
				else
				{
					supportDC.MoveTo(tank1.pos_x + 40 + i, tank1.pos_y + 20);
					supportDC.LineTo(tank1.pos_x + 40 + i, tank1.pos_y - 20);
				}
			}

		}
		else
		{
			supportDC.MoveTo(tank1.pos_x + 40, tank1.pos_y);
			supportDC.LineTo(tank1.pos_x + 52 + tank1.fire_range, tank1.pos_y);
			for(int i = 100; i < tank1.fire_range; i += 100)
			{
				if(i % 500 != 0)
				{
					supportDC.MoveTo(tank1.pos_x + 40 + i, tank1.pos_y + 10);
					supportDC.LineTo(tank1.pos_x + 40 + i, tank1.pos_y - 10);
				}
				else
				{
					supportDC.MoveTo(tank1.pos_x + 40 + i, tank1.pos_y + 20);
					supportDC.LineTo(tank1.pos_x + 40 + i, tank1.pos_y - 20);
				}
			}
		}
	}
	//������־
	if(is_select && d_min - 104 <= tank1.fire_range)
	{
	
		if(d_min - 92 - k_penertrate < 0)
			supportDC.SelectObject(&pen_in);
		else
			supportDC.SelectObject(&pen_out);

		int x1 = enemy_tanks[select_index].pos_x;
		int y1 = enemy_tanks[select_index].pos_y;

		//ʮ��
		supportDC.MoveTo(x1, y1 - 20);
		supportDC.LineTo(x1, y1 + 20);
		supportDC.MoveTo(x1 - 20, y1);
		supportDC.LineTo(x1 + 20, y1);

		//���ı���
		//���Ͻ�
		supportDC.MoveTo(x1 - 40, y1 - 40);
		supportDC.LineTo(x1 - 40, y1 - 20);
		supportDC.MoveTo(x1 - 40, y1 - 40);
		supportDC.LineTo(x1 - 20, y1 - 40);

		//���Ͻ�
		supportDC.MoveTo(x1 + 40, y1 - 40);
		supportDC.LineTo(x1 + 40, y1 - 20);
		supportDC.MoveTo(x1 + 40, y1 - 40);
		supportDC.LineTo(x1 + 20, y1 - 40);

		//���½�
		supportDC.MoveTo(x1 - 40, y1 + 40);
		supportDC.LineTo(x1 - 40, y1 + 20);
		supportDC.MoveTo(x1 - 40, y1 + 40);
		supportDC.LineTo(x1 - 20, y1 + 40);
			
		//���½�
		supportDC.MoveTo(x1 + 40, y1 + 40);
		supportDC.LineTo(x1 + 40, y1 + 20);
		supportDC.MoveTo(x1 + 40, y1 + 40);
		supportDC.LineTo(x1 + 20, y1 + 40);
	}

}
//�ܴ��ӽ���ʾ
void C̹�˴�սϵ��Dlg::Show_Player_Hit_Effect(void)
{
	//��Ч����
	if(Dialog_current_clock - tank1.t_last_effect_penertrated <= STUNE_TIME)
	{
		int index = 150 * (STUNE_TIME - (Dialog_current_clock - tank1.t_last_effect_penertrated))/STUNE_TIME;
		BLENDFUNCTION blendFunction;
		memset( &blendFunction, 0, sizeof(blendFunction) );
		blendFunction.BlendOp = AC_SRC_OVER;
		blendFunction.BlendFlags = 0;
		blendFunction.SourceConstantAlpha = index;

		supportDC.AlphaBlend(0, 0, 3000, 2000, &blackBackDC, 0, 0, 3000, 2000, blendFunction);
	}
	//����
	else if(Dialog_current_clock - tank1.t_last_penertrated <= SHOCK_TIME)
	{
		int index = 60 * (SHOCK_TIME - (Dialog_current_clock - tank1.t_last_penertrated))/SHOCK_TIME;
		BLENDFUNCTION blendFunction;
		memset( &blendFunction, 0, sizeof(blendFunction) );
		blendFunction.BlendOp = AC_SRC_OVER;
		blendFunction.BlendFlags = 0;
		blendFunction.SourceConstantAlpha = index;
		supportDC.AlphaBlend(0, 0, 3000, 2000, &redBackDC, 0, 0, 3000, 2000, blendFunction);

	}
}

void C̹�˴�սϵ��Dlg::Standard_Pro_Ctrl_Draw(int x, int y, int cx, int cy, int index, CDC* stylemapDC, CDC* groundDC, COLORREF bkclr, COLORREF ftclr, int transparent_degree)
{
	groundDC->BitBlt(x, y, cx, cy, stylemapDC, 0, 0, SRCCOPY);

	//����������
	memDC.FillSolidRect(0, 0, cx , cy, bkclr);
	//������ǰ����ɫ����
	memDC.FillSolidRect(0, 0, cx / 100 * index, cy, ftclr);

	BLENDFUNCTION blendFunction;
	memset( &blendFunction, 0, sizeof(blendFunction) );
	blendFunction.BlendOp = AC_SRC_OVER;
	blendFunction.BlendFlags = 0;
	blendFunction.SourceConstantAlpha = transparent_degree;
	groundDC->AlphaBlend(x, y, cx , cy, &memDC, 0, 0, cx, cy, blendFunction);
}