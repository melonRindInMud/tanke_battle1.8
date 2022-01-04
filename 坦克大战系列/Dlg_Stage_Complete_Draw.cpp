#include "stdafx.h"
#include "坦克大战系列Dlg.h"

void C坦克大战系列Dlg::Stage_Complete_Draw(int stage)
{
	if(stage != -1)
	{
		//背景图片
		CBitmap tempbmp;
		tempbmp.LoadBitmapA(IDB_AFTER);
		pictureDC.SelectObject(tempbmp);


		supportDC.BitBlt(0, 0, DIALOG_WIDTH, DIALOG_HEIGHT, &pictureDC, 0, 0, SRCCOPY);
		supportDC.SetBkMode(TRANSPARENT);
		//黑字
		supportDC.SetTextColor(RGB(0, 0, 0));
		supportDC.TextOutA(488, 60, "欢迎回来 干的漂亮！ 你的 坦克已经获得 强化");
		CString h;
		h.Format("共计最大生命 %5d", tank1.max_hitpoint);
		supportDC.TextOutA(288, 100, h);
		h.Format("当前最大生命 %5d", tank1.current_max_hitpoint);
		supportDC.TextOutA(288, 140, h);
		h.Format("当前    生命 %5d", tank1.current_hitpoint);
		supportDC.TextOutA(288, 180, h);

		h.Format("当前  伤害值 %5d", tank1.max_damage);
		supportDC.TextOutA(288, 220, h);
		h.Format("当前发射间隔 %5d", tank1.fastest_fire_interval);
		supportDC.TextOutA(288, 260, h);
		h.Format("当前炮弹初速 %5d", tank1.fire_speed);
		supportDC.TextOutA(288, 300, h);

		h.Format("当前最大速度 %5d", tank1.init_max_speed);
		supportDC.TextOutA(288, 340, h);
		h.Format("当前  加速度 %5d", tank1.init_accelerate_power);
		supportDC.TextOutA(288, 380, h);
		h.Format("当前转向间隔 %5d", tank1.init_fastest_route_interval);
		supportDC.TextOutA(288, 420, h);

		h.Format("当前    金币 %5d", tank1.gold);
		supportDC.TextOutA(288, 460, h);
		h.Format("当前    击杀 %5d", tank1.total_kill);
		supportDC.TextOutA(288, 500, h);
		h.Format("当前  穿深等级 %2d", tank1.penertrate_level);
		supportDC.TextOutA(288, 540, h);
		h.Format("当前  正面防护等级 %2d", tank1.ammor_level);
		supportDC.TextOutA(288, 580, h);
		h.Format("当前  侧面防护等级 %2d", tank1.side_ammor_level);
		supportDC.TextOutA(288, 620, h);
		h.Format("当前  背面防护等级 %2d", tank1.behind_ammor_level);
		supportDC.TextOutA(288, 660, h);


		supportDC.TextOutA(288, 700, "按tab键继续");

		//排行
		h.Format("本关 表现        名字    伤害   防御 击杀");
		supportDC.TextOutA(688, 100, h);
		h.Format("%20s  %6d %6d %2d", tank1.name, tank1.dmg_cause, tank1.dmg_recv, tank1.kill);
		supportDC.TextOutA(688, 140, h);
		h.Format("友军表现优异者   名字    伤害   防御 击杀 ");
		supportDC.TextOutA(688, 190, h);
		sort(allience_tanks,allience_tanks + NUM_OF_ALLIENCE,rank);
		int pt_l = 1;
		for(int i = 0; i < NUM_OF_ALLIENCE && i < 8;i ++)
		{
			h.Format("%20s  %6d %6d %2d", allience_tanks[i].name, allience_tanks[i].dmg_cause, allience_tanks[i].dmg_recv, allience_tanks[i].kill);
			supportDC.TextOutA(688, 190 + 40 * (pt_l ++), h);

		}
		pt_l++;


		h.Format("敌军表现优异者   名字    伤害   防御 击杀 ");
		supportDC.TextOutA(688, 190 + 40 * (pt_l ++), h);
		sort(enemy_tanks,enemy_tanks + NUM_OF_ENEMY,rank);
		for(int i = 0; i < NUM_OF_ENEMY && i < 8;i ++)
		{
			h.Format("%20s  %6d %6d %2d", enemy_tanks[i].name, enemy_tanks[i].dmg_cause, enemy_tanks[i].dmg_recv, enemy_tanks[i].kill);
			supportDC.TextOutA(688, 190 + 40 * (pt_l ++), h);

		}


		//第二遍 -- 白字
		supportDC.SetTextColor(RGB(255, 255, 255));
		//CString h;
		supportDC.TextOutA(490, 60, "欢迎回来 干的漂亮！ 你的 坦克已经获得 强化");
		h.Format("共计最大生命 %5d", tank1.max_hitpoint);
		supportDC.TextOutA(290, 100, h);
		h.Format("当前最大生命 %5d", tank1.current_max_hitpoint);
		supportDC.TextOutA(290, 140, h);
		h.Format("当前    生命 %5d", tank1.current_hitpoint);
		supportDC.TextOutA(290, 180, h);

		h.Format("当前  伤害值 %5d", tank1.max_damage);
		supportDC.TextOutA(290, 220, h);
		h.Format("当前发射间隔 %5d", tank1.fastest_fire_interval);
		supportDC.TextOutA(290, 260, h);
		h.Format("当前炮弹初速 %5d", tank1.fire_speed);
		supportDC.TextOutA(290, 300, h);

		h.Format("当前最大速度 %5d", tank1.init_max_speed);
		supportDC.TextOutA(290, 340, h);
		h.Format("当前  加速度 %5d", tank1.init_accelerate_power);
		supportDC.TextOutA(290, 380, h);
		h.Format("当前转向间隔 %5d", tank1.init_fastest_route_interval);
		supportDC.TextOutA(290, 420, h);

		h.Format("当前    金币 %5d", tank1.gold);
		supportDC.TextOutA(290, 460, h);
		h.Format("当前    击杀 %5d", tank1.total_kill);
		supportDC.TextOutA(290, 500, h);



		h.Format("当前  穿深等级 %2d", tank1.penertrate_level);
		supportDC.TextOutA(290, 540, h);
		h.Format("当前  正面防护等级 %2d", tank1.ammor_level);
		supportDC.TextOutA(290, 580, h);
		h.Format("当前  侧面防护等级 %2d", tank1.side_ammor_level);
		supportDC.TextOutA(290, 620, h);
		h.Format("当前  背面防护等级 %2d", tank1.behind_ammor_level);
		supportDC.TextOutA(290, 660, h);

		supportDC.TextOutA(290, 700, "按tab键继续");


		//排行
		h.Format("本关 表现        名字    伤害   防御 击杀");
		supportDC.TextOutA(690, 100, h);
		h.Format("%20s  %6d %6d %2d", tank1.name, tank1.dmg_cause, tank1.dmg_recv, tank1.kill);
		supportDC.TextOutA(690, 140, h);
		h.Format("友军表现优异者   名字    伤害   防御 击杀 ");
		supportDC.TextOutA(690, 190, h);
		sort(allience_tanks,allience_tanks + NUM_OF_ALLIENCE,rank);
		pt_l = 1;
		for(int i = 0; i < NUM_OF_ALLIENCE && i < 8;i ++)
		{
			h.Format("%20s  %6d %6d %2d", allience_tanks[i].name, allience_tanks[i].dmg_cause, allience_tanks[i].dmg_recv, allience_tanks[i].kill);
			supportDC.TextOutA(690, 190 + 40 * (pt_l ++), h);

		}
		pt_l++;


		h.Format("敌军表现优异者   名字    伤害   防御 击杀 ");
		supportDC.TextOutA(690, 190 + 40 * (pt_l ++), h);
		sort(enemy_tanks,enemy_tanks + NUM_OF_ENEMY,rank);
		for(int i = 0; i < NUM_OF_ENEMY && i < 8;i ++)
		{
			h.Format("%20s  %6d %6d %2d", enemy_tanks[i].name, enemy_tanks[i].dmg_cause, enemy_tanks[i].dmg_recv, enemy_tanks[i].kill);
			supportDC.TextOutA(690, 190 + 40 * (pt_l ++), h);

		}


		if(stage == 3)
		{
			supportDC.TextOutA(190, 830, "第一章结束 主炮再装填已激活");
			supportDC.TextOutA(190, 860, "状态条填充完毕后 按R一定时间内提高射速");
		}
		if(stage == 7)
		{
			supportDC.TextOutA(190, 830, "第二章结束 引擎加速效果已激活");
			supportDC.TextOutA(190, 860, "不转向超过1秒后 最大速度提高50%");
		}
		if(stage == 12)
		{
			supportDC.TextOutA(190, 830, "第三章结束 小队指令系统已激活");
			supportDC.TextOutA(150, 860, "通过输入 1 2 3 使 自己下属的友军变换战斗策略");
		}
	}
	else
	{
		CBitmap tempbmp;
		tempbmp.LoadBitmapA(IDB_ADD_AFTER);
		pictureDC.SelectObject(tempbmp);
		supportDC.BitBlt(0, 0, DIALOG_WIDTH, DIALOG_HEIGHT, &pictureDC, 0, 0, SRCCOPY);
		supportDC.SetBkMode(TRANSPARENT);
		supportDC.SetTextColor(RGB(105, 105, 235));
		int s_x = 400;
		int print_l = 1;
		supportDC.TextOutA(s_x, (print_l ++) * 40, "恭喜你通过了隐藏一关");
		supportDC.TextOutA(s_x, (print_l ++) * 40, "大家看到这个景象 纷纷都吓傻了 认为是鬼怪作怪 一时间都乱了手脚");
		supportDC.TextOutA(s_x, (print_l ++) * 40, "伴随着坦克被击中的巨响 奥托最先回过神来 他大喊道");
		supportDC.TextOutA(s_x, (print_l ++) * 40, "大家保持镇定 炮手 你观察来弹方向  并向该方向 还击  驾驶员听我指挥");
		supportDC.TextOutA(s_x, (print_l ++) * 40, "无线电手 现在应该也没人能来支援我们了 别发无线电了 去帮装填手装炮弹");
		supportDC.TextOutA(s_x, (print_l ++) * 40, "虽然大家都惊魂未定 但毕竟经过了战场上的厮杀 他们很快就回过神来 ");
		supportDC.TextOutA(s_x, (print_l ++) * 40, "在众人的配合中 神秘的敌军中间 接连不断传来坦克爆炸的声音");
		supportDC.TextOutA(s_x, (print_l ++) * 40, "一会的功夫 视野中便再也没有 炮弹来袭了 此时 森林中浓重的雾气消散了");
		supportDC.TextOutA(s_x, (print_l ++) * 40, "借着点点阳光 车组人员 看到了 被摧毁坦克上的 红星 那是巨熊帝国的标志");
		supportDC.TextOutA(s_x, (print_l ++) * 40, "原来只是一堆巨熊啊 还以为 神仙鬼怪来了 车组成员轻蔑道");
		supportDC.TextOutA(s_x, (print_l ++) * 40, "这时 装填手 说话了 车长 刚才多亏你及时反应过来 不然我们就完蛋了 不过 话说你害怕嘛");
		supportDC.TextOutA(s_x, (print_l ++) * 40, "我说不害怕你们也不信 害怕是自然的 不过 害怕 有什么用呢 活熊都被我们打死了 死熊难道就打不死？");
		supportDC.TextOutA(s_x, (print_l ++) * 40, "朋友曾经和我说 无论面对任何人 任何事 只要是必须面对的 就一定不要害怕 不要慌张");
		supportDC.TextOutA(s_x, (print_l ++) * 40, "要用最镇定的态度去处理 只有这样才能取得最好的结果  奥托兴致勃勃的喋喋不休起来");
		supportDC.TextOutA(s_x, (print_l ++) * 40, "不过听到他说的话  车组人员都钦佩的点了点头");
		supportDC.TextOutA(s_x, (print_l ++) * 40, "好了 将坦克开出森林 把被打坏的传动系统修好 坦克开出了阴暗的森林 回到了阳光明媚的大道上");
		supportDC.TextOutA(s_x, (print_l ++) * 40, "喂 傻小子 醒醒 太阳都晒屁股了  咦 居然一觉睡到十一点 奥托睁开惺忪的睡眼");
		supportDC.TextOutA(s_x, (print_l ++) * 40, "想起昨晚做的梦 奥托会心的笑了笑");
		supportDC.TextOutA(s_x, (print_l ++) * 40, "按tab 键进行下一关 在此之前 建议你 看看窗外 不然一会会被亮色背景闪瞎24k钛合金眼");
	}

#ifdef LOW_DENSITY
	pDC->StretchBlt(0, 0, 1267, 693, &supportDC, 0, 0, DIALOG_WIDTH, DIALOG_HEIGHT, SRCCOPY);
#else
	pDC->BitBlt(0, 0, DIALOG_WIDTH, DIALOG_HEIGHT, &supportDC, 0, 0, SRCCOPY);
#endif
}