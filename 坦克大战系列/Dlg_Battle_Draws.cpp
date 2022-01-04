#include "stdafx.h"
#include "坦克大战系列Dlg.h"
//绘制函数的定义全部写在这里


extern clock_t t_last_dmg_cause;
extern int last_dmg_cause;

//战斗画面更新
// 战斗主画面 更新
void C坦克大战系列Dlg::Draw_Update(void)
{
	//地图背景绘制

	//森林背景
	if(8 == current_stage || 13 == current_stage || 16 == current_stage)
	{
		bkresouceDC.SelectObject(&frost_bk);
		memDC.BitBlt(0, 0, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(0, 1000, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(1500, 1000, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(1500, 0, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
	}
	else if ( -1 == current_stage) //黑夜主题
	{
		bkresouceDC.SelectObject(&darkness_bk);
		memDC.BitBlt(0, 0, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(0, 1000, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(1500, 1000, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(1500, 0, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
	}
	//华沙地图
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
	//布鲁塞尔地图
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

	//大撤退城地图
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
	// 巴黎地图
	else if(12 == current_stage)
	{
		bkresouceDC.SelectObject(&city_bk);
		memDC.BitBlt(0, 0, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(0, 1000, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(1500, 1000, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(1500, 0, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
	}


	//第一二三关训练场地形
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
	//第四关
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
	//第五关 和 第 101 关
	else if(5 == current_stage || 101 == current_stage)
	{
		bkresouceDC.SelectObject(&town_bk);
		memDC.BitBlt(0, 0, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(0, 1000, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(1500, 1000, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(1500, 0, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
	}
	//马奇诺防线
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
	//第七关
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
	else  //草地主题
	{
		bkresouceDC.SelectObject(&grass_bk);
		memDC.BitBlt(0, 0, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(0, 1000, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(1500, 1000, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
		memDC.BitBlt(1500, 0, 1500, 1000, &bkresouceDC, 0, 0, SRCCOPY);
	}





	supportDC.BitBlt(0, 0, FIELD_WIDTH, FIELD_HEIGHT, &memDC, 0, 0, SRCCOPY);//大背景 无论多少坦克都只画一次
	supportDC.SetBkMode(TRANSPARENT);
	
	//河流绘制
	pictureDC.SelectObject(&river_bitmap);
	for(int i = 0; i < river_box_number; i++)
	{
		supportDC.BitBlt(river_infor[i].x - 40, river_infor[i].y - 40, 80, 80, &pictureDC, 0, 0, SRCCOPY);
	}





	//第三部分 绘制部分 
	//下层 坦克基本信息
	//敌军 绘制部分
	for(int i = 0; i < NUM_OF_ENEMY; i++)
	{
		//不在场 跳过与其相关的一切绘制
		if(!enemy_tanks[i].is_on_field)
			continue;

		else if(enemy_tanks[i].current_hitpoint || enemy_tanks[i].is_hit || enemy_tanks[i].shell_on_field) //第三个或防止死后炮弹立刻失效
		{
			if(enemy_tanks[i].current_hitpoint && current_stage != -1) //还活着 并且不是隐藏关
			{
				if(c_d_t == V_KVP && i == 0)
					supportDC.SetTextColor(RGB(255, 0, 255));
				else
					supportDC.SetTextColor(RGB(255, 0, 0));

				//坦克绘制部分
				Tank_Graph_Drawer(enemy_tanks[i], 2);
			}
		}
	}
	
#ifdef USE_ALLIENCE
	//友军部分
	for(int i = 0; i < NUM_OF_ALLIENCE; i++)
	{
		if(!allience_tanks[i].is_on_field)
			continue;
		else if(allience_tanks[i].current_hitpoint || allience_tanks[i].is_hit || allience_tanks[i].shell_on_field) //第三个或防止死后炮弹立刻失效
		{
			if(allience_tanks[i].current_hitpoint) //还活着
			{
				if(c_d_t == D_LVP && i == 0)
					supportDC.SetTextColor(RGB(255, 128, 0));
				else
					supportDC.SetTextColor(RGB(0, 0, 255));
				
				//坦克绘制
				Tank_Graph_Drawer(allience_tanks[i], 1);
			}	
		}
	}
#endif
	//自己部分
	if(tank1.current_hitpoint || tank1.is_hit) //还有血 或者被击中爆炸 -- 一共就4张图 可以用static 型的 --- 现在去改
	{
		//当前最大生命值bug修正
		if(tank1.current_max_hitpoint < 0)
			tank1.current_max_hitpoint = 0;
		//无敌
		if(Dialog_current_clock <= immune_to)
		{
			pictureDC.SelectObject(&immue);
			supportDC.TransparentBlt(tank1.pos_x - 64, tank1.pos_y - 64, 128, 128, &pictureDC, 0, 0, 128, 128,  RGB(0, 0, 0));
		}

		if(current_stage != -1)
			Draw_Fire_Control();

		//坦克绘制
		if(tank1.current_hitpoint)
		{
			Tank_Graph_Drawer(tank1, 3);
		}
	}


	//分层绘制 - 上层 爆炸 死亡 炮弹 等 
	for(int i = 0; i < NUM_OF_ENEMY; i++)
	{
		if((enemy_tanks[i].current_hitpoint || (Dialog_current_clock - enemy_tanks[i].die_time) <= 1000 || enemy_tanks[i].shell_on_field) && enemy_tanks[i].is_on_field)
			Attach_Graph_Drawer(enemy_tanks[i], 1);
		enemy_tanks[i].is_hit = 0;
	}
	
	//友军部分
	for(int i = 0; i < NUM_OF_ALLIENCE; i++)
	{
		if((allience_tanks[i].current_hitpoint || ((Dialog_current_clock - allience_tanks[i].die_time) <= 1000) || allience_tanks[i].shell_on_field) && allience_tanks[i].is_on_field)
			Attach_Graph_Drawer(allience_tanks[i], 2);
		allience_tanks[i].is_hit = 0;
	}

	//自己部分
	Attach_Graph_Drawer(tank1, 2);
	tank1.is_hit = 0;

	//受创视角提示
	Show_Player_Hit_Effect();
}

// 战斗提示信息画面  更新
void C坦克大战系列Dlg::SubView_Update(void)
{

	int curr_y = 0;
	pictureDC.SelectObject(&subviewbk);
	stateDC.BitBlt(0, 0, 400, 1000, &pictureDC, 0, 0, SRCCOPY);
	stateDC.SetBkMode(TRANSPARENT);

	//基本信息绘制 血量 关卡进度 关卡名称 难度 之类的
	StateDC_Basic_Infor_Draw();


	//特殊关卡提示消息绘制
	StateDC_Special_Reming();

	
	//特殊能力使用状况绘制
	StateDC_Additional_Ability_Draw();


	//状态受损绘制
	StateDC_Damage_State_Draw();


	//小地图绘制 视角选定 以及 最后的总绘制
	StateDC_Draw_Litter_Map_And_View();

	//将状态栏添加到后台DC中

}
//750行

//1友军 2敌人 3自己
void C坦克大战系列Dlg::Tank_Graph_Drawer(Tank& tk, int p)
{
	int draw_x = tk.pos_x - TANK_WIDTH/2;
	int draw_y = tk.pos_y - TANK_WIDTH/2;

	//履带痕迹 --  现在效果不行
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


	//阴影绘制(半透明）
	pictureDC.SelectObject(&tank_shadow);

	memDC.BitBlt(0, 0, 90, 90, &supportDC, draw_x - 5, draw_y - 5, SRCCOPY);
	memDC.TransparentBlt(0, 0, 90, 90, &pictureDC, 0, 0, 90, 90, RGB(255, 255, 255));
	

	BLENDFUNCTION blendFunction;
	memset( &blendFunction, 0, sizeof(blendFunction) );
	blendFunction.BlendOp = AC_SRC_OVER;
	blendFunction.BlendFlags = 0;
	blendFunction.SourceConstantAlpha = 192;

	supportDC.AlphaBlend(draw_x - 5, draw_y - 5, 90, 90, &memDC, 0, 0, 90, 90, blendFunction);




	

	//血条绘制
	//外框
	supportDC.FillSolidRect(draw_x - 12, draw_y - 18, 104, 15, RGB(0, 0, 0));

	//白条
	int  index = float(100 * tk.current_max_hitpoint / tk.max_hitpoint);
	supportDC.FillSolidRect(draw_x - 10, draw_y - 16, index, 11, RGB(250, 250, 250));

	//当前值
	index = float(100 * tk.current_hitpoint / tk.max_hitpoint);


	//自己
	if(3 == p)
		supportDC.FillSolidRect(draw_x - 10, draw_y - 16, index, 11, RGB(0.5 * index + 50, 1.2 * index + 120, 0.5 * index + 50));
	//友方
	else if(1 == p)
		supportDC.FillSolidRect(draw_x - 10, draw_y - 16, index, 11, RGB(0.25 * index + 25, 0.5 * index + 50, 1.2 * index + 120));
	//敌人
	else
		supportDC.FillSolidRect(draw_x - 10, draw_y - 16, index, 11, RGB(1.28 * index + 127, 0, 0));
	//血条风格优化
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
	//坦克绘制
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
	//苏军
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
	//苏军III
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


	//坦克绘制
	supportDC.TransparentBlt(draw_x, draw_y, TANK_WIDTH, TANK_WIDTH, &pictureDC, 0, 0, TANK_WIDTH, TANK_WIDTH, RGB(255, 255, 255));

	//击中图标
	if(Dialog_current_clock - tk.t_last_hit < 300)//被击中
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
	//光影绘制
	
	BLENDFUNCTION blendFunction3;
	memset( &blendFunction3, 0, sizeof(blendFunction3) );
	blendFunction3.BlendOp = AC_SRC_OVER;
	blendFunction3.BlendFlags = 0;
	blendFunction3.SourceConstantAlpha = 64;

	pictureDC.SelectObject(&tank_light_effect);
	supportDC.AlphaBlend(draw_x, draw_y, 80, 80, &pictureDC, 0, 0, 80, 80, blendFunction3);
	


	//状态栏
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

void C坦克大战系列Dlg::Attach_Graph_Drawer(Tank& tk, int p)
{
	int draw_x = tk.pos_x - TANK_WIDTH/2;
	int draw_y = tk.pos_y - TANK_WIDTH/2;
	//文字颜色
	if(p == 1)
		supportDC.SetTextColor(RGB(255, 0, 0));
	else
		supportDC.SetTextColor(RGB(0, 0, 255));

	//文字	--不是隐藏关
	
	if(tk.current_hitpoint && (current_stage != -1 && current_stage != 15 || PLAYER == tk.rc))
	{
		
		CString t;
		t.Format(" %4d / %4d ", tk.current_hitpoint, tk.max_hitpoint);
		supportDC.TextOutA(draw_x - 40, draw_y - 40, t);
		//名称
		if(PLAYER == tk.rc)
		{
			pictureDC.SelectObject(&player_name);
			supportDC.TransparentBlt(draw_x - 38, draw_y - 65, 175, 31, &pictureDC, 0, 0, 175, 31, RGB(255, 255, 255));
		}
		else
			supportDC.TextOutA(draw_x - 35, draw_y - 55, tk.name);
	}
	
	//开火特效 -- 不是隐藏关
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


	//死亡爆炸
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

		//-40 - 65 起始   200  80
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

	//伤害数字 -- 渐出
	if(Dialog_current_clock - tk.t_last_hit <= 1000)
	{
		BLENDFUNCTION blendFunction;
		memset( &blendFunction, 0, sizeof(blendFunction) );
		blendFunction.BlendOp = AC_SRC_OVER;
		blendFunction.BlendFlags = 0;
		blendFunction.SourceConstantAlpha = 255 - (Dialog_current_clock - tk.t_last_hit) * 128 / 1000;



		memDC.FillSolidRect(0, 0, 200, 100, RGB(255, 255, 255));
	



		if(UNPENERTRATE == tk.last_hit_result) //前方被击中为紫色数字
			memDC.SetTextColor(RGB(0, 0, 128));
		else if(EFFECTIVE_PENERTRATED == tk.last_hit_result)//背后被击中为红色数字
			memDC.SetTextColor(RGB(128, 0, 0));
		else // 其他 为  橘色
			memDC.SetTextColor(RGB(128, 128, 0));
		CString t;
		t.Format(" -%d ", tk.last_hit);
		memDC.TextOutA(0, 0, t);

		//第二次（重影效果）
		if(UNPENERTRATE == tk.last_hit_result) //前方被击中为紫色数字
			memDC.SetTextColor(RGB(0, 0, 255));
		else if(EFFECTIVE_PENERTRATED == tk.last_hit_result)//背后被击中为红色数字
			memDC.SetTextColor(RGB(255, 0, 0));
		else // 其他 为  橘色
			memDC.SetTextColor(RGB(255, 255, 0));
		memDC.TextOutA(3, 3, t);



		memDC2.BitBlt(0, 0, 200, 100, &supportDC, draw_x  - 45, draw_y, SRCCOPY);
		memDC2.TransparentBlt(0, 0, 200, 100, &memDC, 0, 0, 200, 100, RGB(255, 255, 255));


		supportDC.AlphaBlend(draw_x  - 45, draw_y, 200, 100, &memDC2, 0, 0, 200, 100, blendFunction);
	}

	//炮弹检测 + 绘制
	if(tk.shell_on_field && tk.shell_infor.pos_x < FIELD_WIDTH - 12 && tk.shell_infor.pos_y < FIELD_HEIGHT) 
	{
		//敌方炮弹
		if(p == 1)
			pictureDC.SelectObject(shell);
		//友军炮弹
		else if(p == 2)
			pictureDC.SelectObject(shell_f);


		//第一遍
		supportDC.TransparentBlt(tk.shell_infor.pos_x - SHELL_WIDTH/2, tk.shell_infor.pos_y - SHELL_WIDTH/2, SHELL_WIDTH, SHELL_WIDTH, &pictureDC, 0, 0, SHELL_WIDTH, SHELL_WIDTH, RGB(255, 255, 255));


		//现在增加留视效果
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

void C坦克大战系列Dlg::StateDC_Basic_Infor_Draw(void)
{
	// 生命值 装弹信息绘制
	CString str1;
	CString w_str;
	CString d_str;
	int curr_y = 390;

	//胜败（仅字样）
	//时间进度条  起  235 文字  275 血条
	if(c_v_t == V_TLE)
	{
		w_str.Format("坚持就是胜利");
	}
	else if(c_v_t == V_KVP)
	{
		w_str.Format("擒贼擒王    ");
	}
	else if(c_v_t == V_KNE)
	{
		w_str.Format("杀鸡儆猴    ");

	}
	else if(c_v_t == V_STD)
	{
		w_str.Format("通通射爆    ");
	}
	else
	{
		w_str.Format("");
	}

	//失败条件进度条
	if(c_d_t == D_NSH)
	{
		d_str.Format("射的时候要小心");

	}
	else if(c_d_t == D_TLE)
	{
		d_str.Format("时间就是金钱  ");
	}
	else if(c_d_t == D_LVP)
	{
		d_str.Format("保护目标      ");
	}
	else if(c_d_t == D_LNA)
	{
		d_str.Format("减少伤亡      ");
	}
	else if(c_d_t == D_DLD)
	{
		d_str.Format("为了荣耀      ");
	}
	else 
	{
		d_str.Format("");
	}

	//第一遍绘制

	stateDC.SetTextColor(RGB(112, 112, 0));
	stateDC.TextOutA(38, 100, "炮弹装填进度");
	stateDC.TextOutA(38, 165, "生命值");
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

	stateDC.TextOutA(258, 200, "有效伤害");
	CString c_dmg;
	if(Dialog_current_clock <= t_last_dmg_cause + 1000)
		c_dmg.Format("%+6d", last_dmg_cause);
	else
		c_dmg.Format("%7d", tank1.dmg_cause);
	stateDC.TextOutA(258, 230, c_dmg);
	stateDC.TextOutA(258, 265, "防御伤害");
	CString c_resist;
	c_resist.Format("%7d", tank1.dmg_recv);
	stateDC.TextOutA(258, 295, c_resist);


	stateDC.TextOutA(258, 330, "当前车速");
	CString c_speed;
	c_speed.Format("%2d", tank1.Current_Speed);
	stateDC.TextOutA(298, 360, c_speed);



	stateDC.SetTextColor(RGB(223, 223, 0));
	stateDC.TextOutA(40, 100, "炮弹装填进度");
	stateDC.TextOutA(40, 165, "生命值");
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

	stateDC.TextOutA(260, 200, "有效伤害");
	stateDC.TextOutA(260, 230, c_dmg);
	stateDC.TextOutA(260, 265, "防御伤害");
	stateDC.TextOutA(260, 295, c_resist);

	stateDC.TextOutA(260, 330, "当前车速");
	stateDC.TextOutA(300, 360, c_speed);


	curr_y  = 435;
	//难度
	if(Player_Tank::difficulty == 2)
	{
		stateDC.SetTextColor(RGB(128, 0, 0));
		stateDC.TextOutA(38, curr_y, "困难");

		stateDC.SetTextColor(RGB(255, 0, 0));
		stateDC.TextOutA(40, curr_y, "困难");
	}
	else if(Player_Tank::difficulty == 1)
	{
		stateDC.SetTextColor(RGB(128, 64, 0));
		stateDC.TextOutA(38, curr_y, "普通");

		stateDC.SetTextColor(RGB(255, 128, 0));
		stateDC.TextOutA(40, curr_y, "普通");
	}
	else if(Player_Tank::difficulty == 0)
	{
		stateDC.SetTextColor(RGB(0, 0, 128));
		stateDC.TextOutA(38, curr_y, "简单");

		stateDC.SetTextColor(RGB(0, 0, 255));
		stateDC.TextOutA(40, curr_y, "简单");
	}
	else
	{
		stateDC.SetTextColor(RGB(128, 128, 128));
		stateDC.TextOutA(38, curr_y, "作弊");

		stateDC.SetTextColor(RGB(255, 255, 255));
		stateDC.TextOutA(40, curr_y, "作弊");
	}

	//视角
	if(view_orient == UP)
	{
		stateDC.SetTextColor(RGB(128, 128, 128));
		stateDC.TextOutA(148, curr_y, "视角上方");

		stateDC.SetTextColor(RGB(255, 255, 255));
		stateDC.TextOutA(150, curr_y, "视角上方");
	}

	else if(view_orient == DOWN)
	{
		stateDC.SetTextColor(RGB(128, 128, 128));
		stateDC.TextOutA(148, curr_y, "视角下方");

		stateDC.SetTextColor(RGB(255, 255, 255));
		stateDC.TextOutA(150, curr_y, "视角下方");
	}
	else if(view_orient == LEFT)
	{
		stateDC.SetTextColor(RGB(128, 128, 128));
		stateDC.TextOutA(148, curr_y, "视角左侧");

		stateDC.SetTextColor(RGB(255, 255, 255));
		stateDC.TextOutA(150, curr_y, "视角左侧");
	}
	else if(view_orient == RIGHT)
	{
		stateDC.SetTextColor(RGB(128, 128, 128));
		stateDC.TextOutA(148, curr_y, "视角右侧");

		stateDC.SetTextColor(RGB(255, 255, 255));
		stateDC.TextOutA(150, curr_y, "视角右侧");
	}
	else if(view_orient == STOP)
	{
		stateDC.SetTextColor(RGB(128, 128, 128));
		stateDC.TextOutA(148, curr_y, "视角中心");

		stateDC.SetTextColor(RGB(255, 255, 255));
		stateDC.TextOutA(150, curr_y, "视角中心");
	}

	//血条 进度条等
	//装填状态绘制
	stateDC.FillSolidRect(40, 130, 200, 35, RGB(255, 255, 255));
	int index = float (clock() - tank1.last_fire) * 100 / (tank1.fire_interval * FIRE_NERF);
	if(index > 100)
		index = 100;
	if(index != 100)
	{
		int x = 40;
		int y = 130;

		//进度条风格
		pictureDC.SelectObject(&pro_clt);
		Standard_Pro_Ctrl_Draw(x, y , 200, 35, index, &pictureDC, &stateDC, RGB(255, 255, 255), RGB(240 - 1.4 * index, 100 + 1.4 * index, 100), 180); 
	}
	else
	{
		int x = 40;
		int y = 130;

		//进度条风格
		pictureDC.SelectObject(&pro_clt);
		Standard_Pro_Ctrl_Draw(x, y , 200, 35, index, &pictureDC, &stateDC, RGB(255, 255, 255), RGB(100, 100, 240), 180); 
	}
	//生命状态绘制
	int r_time = RECOVER_TIME;
	if(Player_Tank::upgrade_generation)
	{
		r_time /= 2;;
	}
	if(Dialog_current_clock - tank1.t_last_effect_hit <= r_time)
		stateDC.SetTextColor(RGB(255, 128, 0));
	else
		stateDC.SetTextColor(RGB(223, 223, 0));


	//血量
	CString t;
	t.Format(" %4d / %4d ", tank1.current_hitpoint, tank1.max_hitpoint);
	stateDC.TextOutA(160, 165, t);

	index = float (tank1.current_hitpoint * 100)/ tank1.max_hitpoint;



	//血条绘制
	//血量风格
	pictureDC.SelectObject(&pro_clt);
	stateDC.BitBlt(40, 195, 200, 35, &pictureDC, 0, 0, SRCCOPY);

	//血量后景
	blackBackDC.FillSolidRect(0, 0, 200, 35, RGB(0, 0, 0));

	//当前最大值血量
	int index2 = float (tank1.current_max_hitpoint * 100)/ tank1.max_hitpoint;
	blackBackDC.FillSolidRect(0, 0, 2 * index2, 35, RGB(190, 190, 190));

	//当前血量 -- 被击中短时间颜色变深（蓝色伤害除外）
	if(Dialog_current_clock - tank1.t_last_effect_hit > r_time)
	{
		blackBackDC.FillSolidRect(0, 0, 2 * index, 35, RGB(240 - 1.4 * index, 100 + 1.4 * index, 100));
	}
	else
	{
		blackBackDC.FillSolidRect(0, 0, 2 * index, 35, RGB(120 - 0.7 * index, 50 + 0.7 * index, 50));
	}

	//统一混色绘制
	BLENDFUNCTION blendFunction;
	memset( &blendFunction, 0, sizeof(blendFunction) );
	blendFunction.BlendOp = AC_SRC_OVER;
	blendFunction.BlendFlags = 0;
	blendFunction.SourceConstantAlpha = 180;
	stateDC.AlphaBlend(40, 195, 200, 35, &blackBackDC, 0, 0, 200, 35, blendFunction);
	//血条绘制结束




	//进度条
	//胜利条件进度条
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

		//进度条风格
		pictureDC.SelectObject(&pro_clt);
		Standard_Pro_Ctrl_Draw(x, y , 200, 35, index, &pictureDC, &stateDC, RGB(255, 255, 255), RGB(60 + index * 1, 100 + index * 1.5, 60 + index * 1), 180); 
	}



	//失败条件进度条
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

		//进度条风格
		pictureDC.SelectObject(&pro_clt);
		Standard_Pro_Ctrl_Draw(x, y , 200, 35, index, &pictureDC, &stateDC, RGB(255, 255, 255), RGB(60 + index * 1, 100 + index * 1.5, 60 + index * 1), 180); 
	}
}

void C坦克大战系列Dlg::StateDC_Draw_Litter_Map_And_View(void)
{

	//最终绘制 -- 和当前位置有关系 
	int center_x = tank1.pos_x;
	int center_y = tank1.pos_y;

	//不同视角

	//射程提示
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


	
	//方案2 -- 目前不可用 转的头晕
	//分10帧转过来
	
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

	//视野越界处理

	if(center_x > FIELD_WIDTH - 750)
		center_x = FIELD_WIDTH - 750;
	else if(center_x < 750)
		center_x = 750;
	if(center_y > FIELD_HEIGHT - 500)
		center_y = FIELD_HEIGHT - 500;
	else if(center_y < 500)
		center_y = 500;


	//受击提示
	
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

	CPen pen(PS_SOLID, 2, RGB(0, 0, 0)); //射击准线
	stateDC.SelectObject(&pen);
	//小地图指示器
	
	//底图
	if(current_stage != -1)
		stateDC.FillSolidRect(st_x, st_y, 300, 200, RGB(150, 190, 255));
	else
		stateDC.FillSolidRect(st_x, st_y, 300, 200, RGB(255, 0, 0));
	//地图风格
	pictureDC.SelectObject(&main_hor_bkg);
	BLENDFUNCTION blendFunction;
	memset( &blendFunction, 0, sizeof(blendFunction) );
	blendFunction.BlendOp = AC_SRC_OVER;
	blendFunction.BlendFlags = 0;
	blendFunction.SourceConstantAlpha = 50;
	stateDC.AlphaBlend(st_x, st_y, 300, 200, &pictureDC, 0, 0, 1500, 1000, blendFunction);

	//射程提示
	if(current_stage != -1)
		stateDC.FillSolidRect(st_x + x_s / 10, st_y + y_s / 10, (x_e - x_s) / 10, (y_e - y_s) / 10, RGB(140, 230, 190));
	else
		stateDC.FillSolidRect(st_x + x_s / 10, st_y + y_s / 10, (x_e - x_s) / 10, (y_e - y_s) / 10, RGB(255, 255, 0));
	//射程提示风格
	stateDC.AlphaBlend(st_x + x_s / 10, st_y + y_s / 10, (x_e - x_s) / 10, (y_e - y_s) / 10, &pictureDC, 0, 0, 1500, 1000, blendFunction);

		
	//当前视野
	if(current_stage != -1)
		stateDC.FillSolidRect(st_x + center_x/10 - 75, st_y + center_y/10 - 50, 150, 100, RGB(135, 150, 210));
	else
		stateDC.FillSolidRect(st_x + center_x/10 - 75, st_y + center_y/10 - 50, 150, 100, RGB(255, 128, 0));
	//视野风格
	pictureDC.SelectObject(&main_hor_bkg);
	stateDC.AlphaBlend(st_x + center_x/10 - 75, st_y + center_y/10 - 50, 150, 100, &pictureDC, 0, 0, 1500, 1000, blendFunction);

	//射击准线
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



	//小地图友军
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
				// 友军高级单位
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
		//小地图敌军
		for(int i = 0; i < NUM_OF_ENEMY; i++)
		{

			if(enemy_tanks[i].current_hitpoint && enemy_tanks[i].is_on_field ||(enemy_tanks[i].die_time > 0 && Dialog_current_clock - enemy_tanks[i].die_time <= 600))
			{
				if(c_v_t == V_KVP && i == 0 && enemy_tanks[i].current_hitpoint) // 敌军VP为紫色
				{
					stateDC.FillSolidRect(st_x + enemy_tanks[i].pos_x/10 - 4, st_y + enemy_tanks[i].pos_y/10 - 4, 8, 8, RGB(128, 0, 255));
				}
				else if(enemy_tanks[i].current_hitpoint)
				{
					stateDC.FillSolidRect(st_x + enemy_tanks[i].pos_x/10 - 4, st_y + enemy_tanks[i].pos_y/10 - 4, 8, 8, RGB(255, 0, 0));
					// 敌军高级单位
					if(enemy_tanks[i].icon == USSR_T3)
					{
						stateDC.FillSolidRect(st_x + enemy_tanks[i].pos_x/10 - 2, st_y + enemy_tanks[i].pos_y/10 - 2, 4, 4, RGB(255, 128, 0));
					}
					else if(enemy_tanks[i].icon == USSR_T4)
					{
						stateDC.FillSolidRect(st_x + enemy_tanks[i].pos_x/10 - 2, st_y + enemy_tanks[i].pos_y/10 - 2, 4, 4, RGB(128, 0, 255));
					}
				}
				else //死亡爆炸
					stateDC.FillSolidRect(st_x + enemy_tanks[i].pos_x/10 - 4, st_y + enemy_tanks[i].pos_y/10 - 4, 8, 8, RGB(0, 0, 0));

			}
		}
	}


	//小地图自身
	if(current_stage != -1)
		stateDC.FillSolidRect(st_x + tank1.pos_x/10 - 4, st_y + tank1.pos_y/10 - 4, 8, 8, RGB(0, 255, 0));
	else
		stateDC.FillSolidRect(st_x + tank1.pos_x/10 - 4, st_y + tank1.pos_y/10 - 4, 8, 8, RGB(255, 255, 0));

	//小地图中还将绘制自己的炮弹
	if(tank1.shell_on_field)
	{
		stateDC.FillSolidRect(st_x + tank1.shell_infor.pos_x/10 - 2, st_y + tank1.shell_infor.pos_y/10 - 2, 4, 4, RGB(255, 255, 0));
	}




	//屏幕碎裂程度
	int degreer = tank1.current_hitpoint * 100 / tank1.max_hitpoint;
	pictureDC.SelectObject(&hor_state);
	temp_DC.BitBlt(0, 0, 1500, 1000, &pictureDC, 0, 0, SRCCOPY);

	//程度控制
	temp_DC.FillSolidRect(1.875 * (100 - degreer), 1.25 * (100 - degreer), 3.75 * (degreer + 300), 2.5 * (degreer + 300), RGB(0, 0, 0));
	//整体迁移
	supportDC.TransparentBlt(center_x - 750, center_y - 500,1500, 1000, &temp_DC, 0, 0, 1500, 1000, RGB(0, 0, 0));








	//主视角背景风格绘制 -- 中心灯光效果
	pictureDC.SelectObject(&main_hor_bkg);
	BLENDFUNCTION blendFunction2;
	memset( &blendFunction2, 0, sizeof(blendFunction2) );
	blendFunction2.BlendOp = AC_SRC_OVER;
	blendFunction2.BlendFlags = 0;
	blendFunction2.SourceConstantAlpha = 128;
	supportDC.AlphaBlend(center_x - 750, center_y - 500, 1500, 1000, &pictureDC, 0,0, 1500, 1000, blendFunction2);
	

	
	//方法2 使用SRCAND
	//supportDC.StretchBlt(center_x - 750, center_y - 500, 1500, 1000, &pictureDC, 0,0, 1500, 1000, SRCAND);



	//最终绘制 从后台转到前台
#ifdef LOW_DENSITY
	pDC->StretchBlt(0, 0, 1000, 666, &supportDC, center_x - 750, center_y - 500, 1500, 1000, SRCCOPY);
	pDC->StretchBlt(1000, 0, 266, 666, &stateDC, 0, 0, 400, 1000, SRCCOPY);
#else
	pDC->BitBlt(VIEW_WIDTH, 0, SUBVIEW_WIDTH, SUBVIEW_HEIGHT, &stateDC, 0, 0, SRCCOPY);
	pDC->BitBlt(0, 0, VIEW_WIDTH, VIEW_HEIGHT, &supportDC, center_x - 750, center_y - 500, SRCCOPY);
#endif
	
	
	
}

void C坦克大战系列Dlg::StateDC_Additional_Ability_Draw(void)
{
	int curr_y = 660;
	//引擎加速
	if(Player_Tank::upgrade_engine && tank1.Max_Speed > tank1.init_max_speed)
	{
		stateDC.SetTextColor(RGB(128, 30, 90));
		stateDC.TextOutA(38, curr_y, "引擎加速已启用");
		
		stateDC.SetTextColor(RGB(255, 60, 180));
		stateDC.TextOutA(40, curr_y, "引擎加速已启用");
	}
	else if(Player_Tank::upgrade_engine == 1)
	{
		stateDC.SetTextColor(RGB(90, 0, 90));
		stateDC.TextOutA(38, curr_y, "引擎加速未启用");

		stateDC.SetTextColor(RGB(180, 0, 180));
		stateDC.TextOutA(40, curr_y, "引擎加速未启用");
	}
	else
	{
		stateDC.SetTextColor(RGB(223, 223, 0));	
		stateDC.TextOutA(40, curr_y, "Finish Stage7 to Unlock");
	}

	//小队指令
	curr_y = 700;
	if(Player_Tank::upgrade_command)
	{
		stateDC.SetTextColor(RGB(0, 128, 64));
		if(instruct == 1)
			stateDC.TextOutA(38, curr_y, "小队指令：跟随");
		else if(instruct == 2)
			stateDC.TextOutA(38, curr_y, "小队指令：伏击");
		else if(instruct == 3)
			stateDC.TextOutA(38, curr_y, "小队指令：突袭");
		else if(instruct == 4)
			stateDC.TextOutA(38, curr_y, "小队指令：牵制");
		else
			stateDC.TextOutA(38, curr_y, "等待新的小队指令");

		stateDC.SetTextColor(RGB(0, 255, 128));
		if(instruct == 1)
			stateDC.TextOutA(40, curr_y, "小队指令：跟随");
		else if(instruct == 2)
			stateDC.TextOutA(40, curr_y, "小队指令：伏击");
		else if(instruct == 3)
			stateDC.TextOutA(40, curr_y, "小队指令：突袭");
		else if(instruct == 4)
			stateDC.TextOutA(40, curr_y, "小队指令：牵制");
		else
			stateDC.TextOutA(40, curr_y, "等待新的小队指令");
	}
	else
	{
		stateDC.SetTextColor(RGB(223, 223, 0));	
		stateDC.TextOutA(40, curr_y, "完成第12关以解锁");
	}


	//复苏之风
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
	//主炮再装填 （占两行）
	if(Player_Tank::upgrade_gun)
	{
		if(Dialog_current_clock <= gun_up_to)
		{
			stateDC.SetTextColor(RGB(128, 128, 60));	
			stateDC.TextOutA(38, curr_y, "主炮再装填激活");

			stateDC.SetTextColor(RGB(255, 255, 0));	
			stateDC.TextOutA(40, curr_y, "主炮再装填激活");

			int index = (gun_up_to - Dialog_current_clock) * 100 / T_UPGRADE_GUN;
			stateDC.FillSolidRect(40, curr_y + 40, 200, 35, RGB(0, 0, 0));
			stateDC.FillSolidRect(40, curr_y + 40, 2 * index, 35, RGB(240 - index * 1.4, 100 + index * 1.4, 100));
		}
		else
		{
			if(Player_Tank::energy < MAX_ENERGY)
			{
				stateDC.SetTextColor(RGB(30, 128, 90));	
				stateDC.TextOutA(38, curr_y, "主炮再装填充能中");

				stateDC.SetTextColor(RGB(60, 255, 180));	
				stateDC.TextOutA(40, curr_y, "主炮再装填充能中");
				int index = Player_Tank::energy * 100 / MAX_ENERGY;
				stateDC.FillSolidRect(40, curr_y + 40, 200, 35, RGB(255, 255, 255));
				stateDC.FillSolidRect(40, curr_y + 40, 2 * index , 35, RGB(240 - 1.4 * index, 100 + 1.4 * index, 100));

			}
			else
			{
				stateDC.SetTextColor(RGB(128, 64, 0));	
				stateDC.TextOutA(38, curr_y, "主炮再装填充能完毕");

				stateDC.SetTextColor(RGB(255, 128, 0));	
				stateDC.TextOutA(40, curr_y, "主炮再装填充能完毕");
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

void C坦克大战系列Dlg::StateDC_Special_Reming(void)
{
	stateDC.SetTextColor(RGB(223, 223, 0));
	//附加重要事件显示
	if(current_stage == 11 && Dialog_current_clock - stage_begin_time <= 150000)
	{
		CString h;
		h.Format("距离友军增援还有 %d 秒    ", (150000 - Dialog_current_clock + stage_begin_time) / 1000);
		stateDC.TextOutA(40, 960, h);
	}
	else if(current_stage == 11)
	{
		CString h;
		h.Format("友军支援已经到达        ");
		stateDC.TextOutA(40, 960, h);
	}
	else if(current_stage == 13 && Dialog_current_clock - stage_begin_time <= 25000)
	{
		CString h;
		h.Format("距离敌军反击还有 %d 秒    ", (25000 - Dialog_current_clock + stage_begin_time) / 1000);
		stateDC.TextOutA(40, 960, h);
	}
	else if(current_stage == 13)
	{
		CString h;
		h.Format("敌军已经开始反击        ");
		stateDC.TextOutA(40, 960, h);
	}
}

void C坦克大战系列Dlg::StateDC_Damage_State_Draw(void)
{
	int curr_y = 425;
	//引擎是否受损
	if(tank1.is_engine_damage)
	{
		stateDC.SetTextColor(RGB(128, 0, 0));
		stateDC.TextOutA(28, 880, "引擎受损");

		stateDC.SetTextColor(RGB(255, 0, 0));
		stateDC.TextOutA(30, 880, "引擎受损");

			
		//引擎修复进度条
		//stateDC.FillSolidRect(160, 880, 200, 35, RGB(0, 0, 0));
		int index = (Dialog_current_clock - tank1.t_last_fital_hit) * 100 / (ENGINE_REPAIR_TIME);

		int x = 160;
		int y = 880;

		//进度条风格
		pictureDC.SelectObject(&pro_clt);
		Standard_Pro_Ctrl_Draw(x, y , 200, 35, index, &pictureDC, &stateDC, RGB(0, 0, 0), RGB(240 - 1.4 * index, 100 + 1.4 * index, 100), 180); 
	}
	
	else
	{
		stateDC.SetTextColor(RGB(112, 112, 0));
		stateDC.TextOutA(28, 880, "引擎正常");

		stateDC.SetTextColor(RGB(223, 223, 0));
		stateDC.TextOutA(30, 880, "引擎正常");

		int cx = 160;
		int cy = 880;

		//进度条风格
		pictureDC.SelectObject(&pro_clt);
		stateDC.BitBlt(cx, cy, 200, 35, &pictureDC, 0, 0, SRCCOPY);


		//进度条背景
		blackBackDC.FillSolidRect(0, 0, 200 , 35, RGB(0, 0, 0));
		//前景颜色控制
		blackBackDC.FillSolidRect(0, 0, 200, 35, RGB(100, 100, 240));

		BLENDFUNCTION blendFunction;
		memset( &blendFunction, 0, sizeof(blendFunction) );
		blendFunction.BlendOp = AC_SRC_OVER;
		blendFunction.BlendFlags = 0;
		blendFunction.SourceConstantAlpha = 180;
		stateDC.AlphaBlend(cx, cy, 200 , 35, &blackBackDC, 0, 0, 200, 35, blendFunction);

		

	}
	
	//主炮是否受损
	if(tank1.is_gun_damage)
	{
		stateDC.SetTextColor(RGB(128, 64, 0));
		stateDC.TextOutA(28, 920, "主炮受损");

		stateDC.SetTextColor(RGB(255, 128, 0));
		stateDC.TextOutA(30, 920, "主炮受损");


		//stateDC.FillSolidRect(160, 920, 200, 35, RGB(0, 0, 0));
		int index = (Dialog_current_clock - tank1.t_last_gun_hit) * 100 / (GUN_REPAIR_TIME);
		int x = 160;
		int y = 920;

		//进度条风格
		pictureDC.SelectObject(&pro_clt);
		Standard_Pro_Ctrl_Draw(x, y , 200, 35, index, &pictureDC, &stateDC, RGB(0, 0, 0), RGB(240 - 1.4 * index, 100 + 1.4 * index, 100), 180); 
	}
	
	else
	{

		int cx = 160;
		int cy = 920;

		//进度条风格
		pictureDC.SelectObject(&pro_clt);


		stateDC.BitBlt(cx, cy, 200, 35, &pictureDC, 0, 0, SRCCOPY);


		//进度条背景
		blackBackDC.FillSolidRect(0, 0, 200 , 35, RGB(0, 0, 0));
		//前景颜色控制
		blackBackDC.FillSolidRect(0, 0, 200, 35, RGB(100, 100, 240));

		BLENDFUNCTION blendFunction;
		memset( &blendFunction, 0, sizeof(blendFunction) );
		blendFunction.BlendOp = AC_SRC_OVER;
		blendFunction.BlendFlags = 0;
		blendFunction.SourceConstantAlpha = 180;
		stateDC.AlphaBlend(cx, cy, 200 , 35, &blackBackDC, 0, 0, 200, 35, blendFunction);


		stateDC.SetTextColor(RGB(112, 112, 0));
		stateDC.TextOutA(28, 920, "主炮正常");

		stateDC.SetTextColor(RGB(223, 223, 0));
		stateDC.TextOutA(30, 920, "主炮正常");
	}
}

//1150行
void C坦克大战系列Dlg::Draw_Fire_Control(void)
{
	//没装好炮弹的时候不画
	if(Dialog_current_clock < tank1.last_fire + tank1.fire_interval * FIRE_NERF - 100)
		return ;

	//火控系统
	//瞄准基线
	CPen t(BS_SOLID, 6, RGB(0, 0, 0)); // 未选中
	CPen pen_in(BS_SOLID, 6, RGB(0, 128, 255));
	CPen pen_out(BS_SOLID, 6, RGB(255, 0, 0) );
	supportDC.SelectObject(&t);

	//智能穿深预瞄
	int is_select = 0;
	int select_index = -1;
	int d_min = 9999;
	int k_penertrate = 0;

	if(UP == tank1.orient) //向上
	{
		//选择目标
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
			if(enemy_tanks[select_index].orient == UP)//背后
			{
				k_penertrate = 100 * (tank1.penertrate_level - enemy_tanks[select_index].behind_ammor_level);
			}
			else if(enemy_tanks[select_index].orient == DOWN) //正面
 			{
				k_penertrate = 100 * (tank1.penertrate_level - enemy_tanks[select_index].ammor_level);
			}
			else //侧面
			{
				k_penertrate = 100 * (tank1.penertrate_level - enemy_tanks[select_index].side_ammor_level);
			}
				
			//归零
			if(k_penertrate <0)
				k_penertrate = 0;

			//绘制
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
		//选择目标
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
			if(enemy_tanks[select_index].orient == DOWN)//背后
			{
				k_penertrate = 100 * (tank1.penertrate_level - enemy_tanks[select_index].behind_ammor_level);
			}
			else if(enemy_tanks[select_index].orient == UP) //正面
 			{
				k_penertrate = 100 * (tank1.penertrate_level - enemy_tanks[select_index].ammor_level);
			}
			else //侧面
			{
				k_penertrate = 100 * (tank1.penertrate_level - enemy_tanks[select_index].side_ammor_level);
			}
				
			//归零
			if(k_penertrate <0)
				k_penertrate = 0;

			//绘制
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
		//选择目标
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
			if(enemy_tanks[select_index].orient == LEFT)//背后
			{
				k_penertrate = 100 * (tank1.penertrate_level - enemy_tanks[select_index].behind_ammor_level);
			}
			else if(enemy_tanks[select_index].orient == RIGHT) //正面
 			{
				k_penertrate = 100 * (tank1.penertrate_level - enemy_tanks[select_index].ammor_level);
			}
			else //侧面
			{
				k_penertrate = 100 * (tank1.penertrate_level - enemy_tanks[select_index].side_ammor_level);
			}
			//归零
			if(k_penertrate <0)
				k_penertrate = 0;

			//绘制
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
		//选择目标
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
			if(enemy_tanks[select_index].orient == RIGHT)//背后
			{
				k_penertrate = 100 * (tank1.penertrate_level - enemy_tanks[select_index].behind_ammor_level);
			}
			else if(enemy_tanks[select_index].orient == LEFT) //正面
 			{
				k_penertrate = 100 * (tank1.penertrate_level - enemy_tanks[select_index].ammor_level);
			}
			else //侧面
			{
				k_penertrate = 100 * (tank1.penertrate_level - enemy_tanks[select_index].side_ammor_level);
			}
			//归零
			if(k_penertrate <0)
				k_penertrate = 0;

			//绘制
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
	//锁定标志
	if(is_select && d_min - 104 <= tank1.fire_range)
	{
	
		if(d_min - 92 - k_penertrate < 0)
			supportDC.SelectObject(&pen_in);
		else
			supportDC.SelectObject(&pen_out);

		int x1 = enemy_tanks[select_index].pos_x;
		int y1 = enemy_tanks[select_index].pos_y;

		//十字
		supportDC.MoveTo(x1, y1 - 20);
		supportDC.LineTo(x1, y1 + 20);
		supportDC.MoveTo(x1 - 20, y1);
		supportDC.LineTo(x1 + 20, y1);

		//外四边形
		//左上角
		supportDC.MoveTo(x1 - 40, y1 - 40);
		supportDC.LineTo(x1 - 40, y1 - 20);
		supportDC.MoveTo(x1 - 40, y1 - 40);
		supportDC.LineTo(x1 - 20, y1 - 40);

		//右上角
		supportDC.MoveTo(x1 + 40, y1 - 40);
		supportDC.LineTo(x1 + 40, y1 - 20);
		supportDC.MoveTo(x1 + 40, y1 - 40);
		supportDC.LineTo(x1 + 20, y1 - 40);

		//左下角
		supportDC.MoveTo(x1 - 40, y1 + 40);
		supportDC.LineTo(x1 - 40, y1 + 20);
		supportDC.MoveTo(x1 - 40, y1 + 40);
		supportDC.LineTo(x1 - 20, y1 + 40);
			
		//右下角
		supportDC.MoveTo(x1 + 40, y1 + 40);
		supportDC.LineTo(x1 + 40, y1 + 20);
		supportDC.MoveTo(x1 + 40, y1 + 40);
		supportDC.LineTo(x1 + 20, y1 + 40);
	}

}
//受创视角提示
void C坦克大战系列Dlg::Show_Player_Hit_Effect(void)
{
	//有效击穿
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
	//击穿
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

void C坦克大战系列Dlg::Standard_Pro_Ctrl_Draw(int x, int y, int cx, int cy, int index, CDC* stylemapDC, CDC* groundDC, COLORREF bkclr, COLORREF ftclr, int transparent_degree)
{
	groundDC->BitBlt(x, y, cx, cy, stylemapDC, 0, 0, SRCCOPY);

	//进度条背景
	memDC.FillSolidRect(0, 0, cx , cy, bkclr);
	//进度条前景颜色控制
	memDC.FillSolidRect(0, 0, cx / 100 * index, cy, ftclr);

	BLENDFUNCTION blendFunction;
	memset( &blendFunction, 0, sizeof(blendFunction) );
	blendFunction.BlendOp = AC_SRC_OVER;
	blendFunction.BlendFlags = 0;
	blendFunction.SourceConstantAlpha = transparent_degree;
	groundDC->AlphaBlend(x, y, cx , cy, &memDC, 0, 0, cx, cy, blendFunction);
}