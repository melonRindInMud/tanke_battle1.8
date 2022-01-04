#include "stdafx.h"
#include "坦克大战系列Dlg.h"

// 背景故事 初始化
void C坦克大战系列Dlg::Process_Show(void)
{
	static int fire_interval_prove = 0; // 最多提升5次 每次 50毫秒 -- 等效于 5%左右的火力
	static int max_speed_prove = 0; // 最多提升4次 每次 提升2 
	static int engine_prove = 0; // 最多提升3次  每次提升 1


	supportDC.SelectObject(&f);

	//音乐
	if(Prepare == process)
	{
		prepartion_bgm_player(current_stage);
	}
	else if(After == process)
	{
		after_bgm_player(current_stage);
	}



	if(process == After)
	{
		buy_free_access = 1;
	

		Tank_Auto_Upgrade_By_Stage(current_stage);		

		Stage_Complete_Draw(current_stage);


	}


	else if(process == Prepare)
	{
		//画图
		if(current_stage != -1)
		{
			CDC tempDC;
			tempDC.CreateCompatibleDC(pDC);
			CBitmap tempbmp;

			//不同关卡的不同背景
			if(current_stage == 1)
				tempbmp.LoadBitmapA(IDB_PREPARE_S1);
			else if(current_stage == 2)
				tempbmp.LoadBitmapA(IDB_PREPARE_S2);
			else if(current_stage == 3)
				tempbmp.LoadBitmapA(IDB_PREPARE_S3);
			else if(current_stage == 4)
				tempbmp.LoadBitmapA(IDB_PREPARE_S4);
			else if(current_stage == 5)
				tempbmp.LoadBitmapA(IDB_PREPARE_S5);
			else if(current_stage == 6)
				tempbmp.LoadBitmapA(IDB_PREPARE_S6);
			else if(current_stage == 7)
				tempbmp.LoadBitmapA(IDB_PREPARE_S7);
			else if(current_stage == 8)
				tempbmp.LoadBitmapA(IDB_PREPARE_S8);
			else if(current_stage == 9)
				tempbmp.LoadBitmapA(IDB_PREPARE_S9);
			else if(current_stage == 10)
				tempbmp.LoadBitmapA(IDB_PREPARE_S10);
			else if(current_stage == 11)
				tempbmp.LoadBitmapA(IDB_PREPARE_S11);
			else if(current_stage == 12)
				tempbmp.LoadBitmapA(IDB_PREPARE_S12);
			else if(current_stage == 13)
				tempbmp.LoadBitmapA(IDB_PREPARE_S13);
			else if(current_stage == 14)
				tempbmp.LoadBitmapA(IDB_PREPARE_S14);
			else if(current_stage == 15)
				tempbmp.LoadBitmapA(IDB_RREPARE_S15);


			else if(current_stage == 100)
				tempbmp.LoadBitmapA(IDB_PREPARE_S100);
			else if(current_stage == 101)
				tempbmp.LoadBitmapA(IDB_PREPARE_S101);
			else
				tempbmp.LoadBitmapA(IDB_PREPARE);

			tempDC.SelectObject(tempbmp);

			supportDC.BitBlt(0, 0, DIALOG_WIDTH, DIALOG_HEIGHT, &tempDC, 0, 0, SRCCOPY);
			//supportDC.BitBlt(0, 0, DIALOG_WIDTH, DIALOG_HEIGHT, &tempDC, 0, 0, SRCCOPY);
	
			
			
			supportDC.SetBkMode(TRANSPARENT);

			supportDC.SetTextColor(RGB(255, 0, 0));
		}
		else
		{
			CDC tempDC;
			tempDC.CreateCompatibleDC(pDC);
			CBitmap tempbmp;
		
			tempbmp.LoadBitmapA(IDB_ADD_PREPARE);


			tempDC.SelectObject(tempbmp);
			supportDC.BitBlt(0, 0, DIALOG_WIDTH, DIALOG_HEIGHT, &tempDC, 0, 0, SRCCOPY);
			supportDC.SetBkMode(TRANSPARENT);

			supportDC.SetTextColor(RGB(255, 255, 0));

		}
		if (current_stage == -1)
		{
			int print_l = 1;
			int s_x = 430;
			//supportDC.FillSolidRect(0, 0, DIALOG_WIDTH, DIALOG_WIDTH, RGB(240, 240, 240));
			supportDC.SelectObject(&f);
			supportDC.TextOutA(s_x, 40 * (print_l ++), "隐藏章节   心魔");
			supportDC.TextOutA(s_x, 40 * (print_l ++), "希伯来战役结束后  奥托回到了家里 虽然 在这次战斗中 奥托的坦克并没有受到 ");
			supportDC.TextOutA(s_x, 40 * (print_l ++), "致命威胁 但是 有一两个奥托认识的战友却在战斗中阵亡了 想起他们");
			supportDC.TextOutA(s_x, 40 * (print_l ++), "除去怀念 和 惋惜 奥托心中也有一些恐惧  以至于经常做噩梦");
			supportDC.TextOutA(s_x, 40 * (print_l ++), "这天晚上 奥托由于没盖好被子而且天气比较冷 又开始做噩梦了：");
			supportDC.TextOutA(s_x, 40 * (print_l ++), "奥托和所在部队走散 并且 进入到了一个奇怪的森林中 一等奥托他们进入");
			supportDC.TextOutA(s_x, 40 * (print_l ++), "森林中便四处响起恐怖的呼喊声  纳命来 侵略者们 声音空洞干枯但及其洪亮 此起彼伏 ");
			supportDC.TextOutA(s_x, 40 * (print_l ++), "难道是阵亡的希伯来军的亡魂 奥托等人惊魂未定  一堆炮弹就向他们飞来");
			print_l ++;
			supportDC.TextOutA(s_x, 40 * (print_l ++), "隐藏一关   惧之魇");
			supportDC.TextOutA(s_x, 40 * (print_l ++), "本关中 敌人 是隐形的 他们的名字 血条  位置 外形 都不会显示在主界面或者小地图上");
			supportDC.TextOutA(s_x, 40 * (print_l ++), "同时 敌军数量也不会显示");
			supportDC.TextOutA(s_x, 40 * (print_l ++), "但是敌人的炮弹飞行速度较慢 可以通过反应躲开或者用正面硬抗");
			supportDC.TextOutA(s_x, 40 * (print_l ++), "胜利条件： 驾驶自己的坦克 摧毁所有敌军");
			supportDC.TextOutA(s_x, 40 * (print_l ++), "失败条件： 玩家坦克被摧毁 (如果这样的话 奥托会由于 被惊醒而被吓死 从而导致故事结束）");
			supportDC.TextOutA(s_x, 40 * (print_l ++), "本关提示： 可以通过炮弹 来定位他们 对于开出去的炮弹是否打中 可以通过音效来判断");
			supportDC.TextOutA(s_x, 40 * (print_l ++), "本关提示2:  不要抱有打一遍记位置再打的想法 敌人的位置是而且每次都会变动的  敌人防御很低");
			supportDC.TextOutA(s_x, 40 * (print_l ++), "本关提示3： 敌人的伤害很高  ·困难难度下本关难度过高 需要非常快的反应速度");
			supportDC.TextOutA(s_x, 40 * (print_l ++), "再按tab键 开始本关");
		}
		else if(current_stage == 100)
		{
			supportDC.SetTextColor(RGB(0, 0, 0));
			int print_l = 1;
			//supportDC.FillSolidRect(0, 0, DIALOG_WIDTH, DIALOG_WIDTH, RGB(240, 240, 240));
			supportDC.SelectObject(&f);
			supportDC.TextOutA(488, 40 * (print_l ++), "本关为彩蛋1 单人练习关卡");
			supportDC.TextOutA(488, 40 * (print_l ++), "第100关 望中犹记 烽火扬州路");
			supportDC.TextOutA(488, 40 * (print_l ++), "大战结束后 奥托在家乡开了一家药店 名为 老虎药店 并过着平静的生活");
			supportDC.TextOutA(488, 40 * (print_l ++), "直到一天 这天风雨大作 晚上奥托躺在床上睡不着 于是决定在庭院的长廊里走走");
			supportDC.TextOutA(488, 40 * (print_l ++), "正当奥托走出房门时 一道闪电击中了 奥托的房子 奥托受到了闪电能量的波及 昏了过去");
			supportDC.TextOutA(488, 40 * (print_l ++), "别愣着了 苏联人要打过来了 排长  奥托 睁开眼睛 居然看到了 阔别已经的战友车组和坦克");
			supportDC.TextOutA(488, 40 * (print_l ++), "以及远处的敌军.... 还不等犹豫 奥托立刻 登上了自己的217号坐车");
			supportDC.TextOutA(488, 40 * (print_l ++), "但是奇怪的是 周围居然没有友军？");
			supportDC.TextOutA(488, 40 * (print_l ++), "就在这时 远处炮声响起......");
			//supportDC.TextOutA(488, 40 * (print_l ++), "第一关 新兵");
			supportDC.TextOutA(488, 40 * (print_l ++), "本关你将 面对源源不断的敌军 请 尽可能得到 消灭他们 如果你想退出此关 按 回车 即可");
			supportDC.TextOutA(488, 40 * (print_l ++), "胜利条件  摧毁所有敌军");
			supportDC.TextOutA(488, 40 * (print_l ++), "失败条件  玩家坦克被摧毁");
			supportDC.TextOutA(488, 40 * (print_l ++), "本关提示  这是一场持久战 请做好准备！敌人会越来越强");
			supportDC.TextOutA(488, 40 * (print_l ++), "按B键 开始本关");

			supportDC.SetTextColor(RGB(255, 255, 255));
			print_l = 1;
			//supportDC.FillSolidRect(0, 0, DIALOG_WIDTH, DIALOG_WIDTH, RGB(240, 240, 240));
			supportDC.SelectObject(&f);
			supportDC.TextOutA(490, 40 * (print_l ++), "本关为彩蛋1 单人练习关卡");
			supportDC.TextOutA(490, 40 * (print_l ++), "第100关 望中犹记 烽火扬州路");
			supportDC.TextOutA(490, 40 * (print_l ++), "大战结束后 奥托在家乡开了一家药店 名为 老虎药店 并过着平静的生活");
			supportDC.TextOutA(490, 40 * (print_l ++), "直到一天 这天风雨大作 晚上奥托躺在床上睡不着 于是决定在庭院的长廊里走走");
			supportDC.TextOutA(490, 40 * (print_l ++), "正当奥托走出房门时 一道闪电击中了 奥托的房子 奥托受到了闪电能量的波及 昏了过去");
			supportDC.TextOutA(490, 40 * (print_l ++), "别愣着了 苏联人要打过来了 排长  奥托 睁开眼睛 居然看到了 阔别已经的战友车组和坦克");
			supportDC.TextOutA(490, 40 * (print_l ++), "以及远处的敌军.... 还不等犹豫 奥托立刻 登上了自己的217号坐车");
			supportDC.TextOutA(490, 40 * (print_l ++), "但是奇怪的是 周围居然没有友军？");
			supportDC.TextOutA(490, 40 * (print_l ++), "就在这时 远处炮声响起......");
			//supportDC.TextOutA(488, 40 * (print_l ++), "第一关 新兵");
			supportDC.TextOutA(490, 40 * (print_l ++), "本关你将 面对源源不断的敌军 请 尽可能得到 消灭他们 如果你想退出此关 按 回车 即可");
			supportDC.TextOutA(490, 40 * (print_l ++), "胜利条件  摧毁所有敌军");
			supportDC.TextOutA(490, 40 * (print_l ++), "失败条件  玩家坦克被摧毁");
			supportDC.TextOutA(490, 40 * (print_l ++), "本关提示  这是一场持久战 请做好准备！敌人会越来越强");
			supportDC.TextOutA(490, 40 * (print_l ++), "按B键 开始本关");
		}
		else if(current_stage == 101)
		{
			Story_Information_Presentor(current_stage);
			//supportDC.FillSolidRect(0, 0, DIALOG_WIDTH, DIALOG_WIDTH, RGB(240, 240, 240));
	
		}
		else if(current_stage == 1)
		{
			Story_Information_Presentor(current_stage);
		}
		else if(current_stage == 2)
		{
			Story_Information_Presentor(current_stage);
		}
		else if(current_stage == 3)
		{
			//supportDC.FillSolidRect(0, 0, DIALOG_WIDTH, DIALOG_WIDTH, RGB(240, 240, 240));
			supportDC.SelectObject(&f);
			supportDC.SetTextColor(RGB(0, 0, 0));
			supportDC.TextOutA(488, 60, "剧情概述： 奥托的车组在混战中取得了辉煌的战绩 不仅自身的坦克只被命中了两次炮盾");
			supportDC.TextOutA(488, 100, "还击中了 大量 其他坦克 的 腚部 和 侧面  指挥官对奥托的车组非常满意");
			supportDC.TextOutA(488, 140, "又经过了一系列的 越野 穿越障碍物 等训练 下一项训练 团队配合作战开始了");
			supportDC.TextOutA(488, 180, "小胡子帝国的坦克其实在卡利姆多大陆不算优秀 但是他们具有独特的优势 ");
			supportDC.TextOutA(488, 220, "第一是坦克集群作战的先进作战思路 第二是 先进的无线电通讯 这使得坦克集群作战能力很强");
			supportDC.TextOutA(488, 260, "因此 这次训练主要训练 新兵们的团队配合能力");
			supportDC.TextOutA(488, 300, "此次训练的分组是根据上一次训练的成绩来的 奥托的车组被分在了4个装甲军挑选出来的最优秀的");
			supportDC.TextOutA(488, 340, "十八组车组的 分队中 对手包括了 巴克曼 魏特曼 鲍尔特 而友方也有 博尔特 和 科舍尔");
			supportDC.TextOutA(488, 380, "（不知道这些人来历的可以百度");
			supportDC.TextOutA(488, 420, "虽然此次训练仍然是使用颜料弹 但是 裁判会根据 坦克的中弹情况 实时判定坦克是否出局");
			supportDC.TextOutA(488, 460, "训练开始之前 大家先都握手致敬 之后 走进自己的坐车 看着摩拳擦掌的敌人 奥托不由得紧张起来");
			supportDC.TextOutA(488, 500, "不过这并不影响他聪明的大脑的运转 比赛一开始 他就下令将战车右拐 企图绕到敌人的侧面");

			supportDC.TextOutA(488, 540, "第三关 团队战训练");
			supportDC.TextOutA(488, 580, "本关你需要配合 8位友军 击败 9 名敌人 出于平衡性考虑 本关你没有开局无敌");
			supportDC.TextOutA(488, 620, "敌军和 友军 不论是 实力还是智能都旗鼓相当 同时如果你选择困难难度 多数人的坦克");
			supportDC.TextOutA(488, 660, "都会在性能上 碾压你 （不过 如果是 简单难度 就反之）");
			supportDC.TextOutA(488, 700, "有2位友军和 3位敌军 经验非常丰富 其他人 虽然攻势凌厉 但是过于头铁 可能很快就没了");
			supportDC.TextOutA(488, 740, "胜利条件 配合友军 摧毁所有敌军");
			supportDC.TextOutA(488, 780, "失败条件 玩家坦克被摧毁");
			supportDC.TextOutA(488, 820, "本关提示 利用友军牵制敌人正面 然后从侧面或背面输出 被集火时 靠近友军分担仇恨");
			supportDC.TextOutA(488, 860, "再按tab键 开始本关");



			supportDC.SetTextColor(RGB(255, 255, 255));
			supportDC.TextOutA(490, 60, "剧情概述： 奥托的车组在混战中取得了辉煌的战绩 不仅自身的坦克只被命中了两次炮盾");
			supportDC.TextOutA(490, 100, "还击中了 大量 其他坦克 的 腚部 和 侧面  指挥官对奥托的车组非常满意");
			supportDC.TextOutA(490, 140, "又经过了一系列的 越野 穿越障碍物 等训练 下一项训练 团队配合作战开始了");
			supportDC.TextOutA(490, 180, "小胡子帝国的坦克其实在卡利姆多大陆不算优秀 但是他们具有独特的优势 ");
			supportDC.TextOutA(490, 220, "第一是坦克集群作战的先进作战思路 第二是 先进的无线电通讯 这使得坦克集群作战能力很强");
			supportDC.TextOutA(490, 260, "因此 这次训练主要训练 新兵们的团队配合能力");
			supportDC.TextOutA(490, 300, "此次训练的分组是根据上一次训练的成绩来的 奥托的车组被分在了4个装甲军挑选出来的最优秀的");
			supportDC.TextOutA(490, 340, "十八组车组的 分队中 对手包括了 巴克曼 魏特曼 鲍尔特 而友方也有 博尔特 和 科舍尔");
			supportDC.TextOutA(490, 380, "（不知道这些人来历的可以百度");
			supportDC.TextOutA(490, 420, "虽然此次训练仍然是使用颜料弹 但是 裁判会根据 坦克的中弹情况 实时判定坦克是否出局");
			supportDC.TextOutA(490, 460, "训练开始之前 大家先都握手致敬 之后 走进自己的坐车 看着摩拳擦掌的敌人 奥托不由得紧张起来");
			supportDC.TextOutA(490, 500, "不过这并不影响他聪明的大脑的运转 比赛一开始 他就下令将战车右拐 企图绕到敌人的侧面");

			supportDC.TextOutA(490, 540, "第三关 团队战训练");
			supportDC.TextOutA(490, 580, "本关你需要配合 8位友军 击败 9 名敌人 出于平衡性考虑 本关你没有开局无敌");
			supportDC.TextOutA(490, 620, "敌军和 友军 不论是 实力还是智能都旗鼓相当 同时如果你选择困难难度 多数人的坦克");
			supportDC.TextOutA(490, 660, "都会在性能上 碾压你 （不过 如果是 简单难度 就反之）");
			supportDC.TextOutA(490, 700, "有2位友军和 3位敌军 经验非常丰富 其他人 虽然攻势凌厉 但是过于头铁 可能很快就没了");
			supportDC.TextOutA(490, 740, "胜利条件 配合友军 摧毁所有敌军");
			supportDC.TextOutA(490, 780, "失败条件 玩家坦克被摧毁");
			supportDC.TextOutA(490, 820, "本关提示 利用友军牵制敌人正面 然后从侧面或背面输出 被集火时 靠近友军分担仇恨");
			supportDC.TextOutA(490, 860, "再按tab键 开始本关");

		

		}
		else if(current_stage == 4)
		{
			//supportDC.FillSolidRect(0, 0, DIALOG_WIDTH, DIALOG_WIDTH, RGB(240, 240, 240));
			supportDC.SelectObject(&f);
			supportDC.SetTextColor(RGB(0, 0, 0));
			supportDC.TextOutA(488, 100, "剧情概述： 由于奥托机智的绕侧 和队友的犀利 抗伤害 我方小队连战连捷 最后取得了全军团冠军小队");
			supportDC.TextOutA(488, 140, "随后奥托的小组顺利通过新兵教程结业考核 成为一名预备役坦克车长 随后军队放了几个月假 ");
			supportDC.TextOutA(488, 180, "放假期间 奥托和他的战友们整天泡在酒吧 把妹 喝酒 还有...  好不酸爽 正在此时指挥官突然宣布假期顺延");
			supportDC.TextOutA(488, 220, "原来 皇帝的扩张欲望不断变强 在捷伐斯克洛克 的 慕黑尼 与 不断绥靖的 嘤嘤怪帝国 和 我投降共和国 签订了");
			supportDC.TextOutA(488, 260, "满足皇帝扩张的不平等条约之后  皇帝将目光锁定了 在 帝国 东侧的 希伯来民主联邦");
			supportDC.TextOutA(488, 300, "希伯来民主联邦是 帝国在上次世界大战战败后割让土地所形成的一个国家");
			supportDC.TextOutA(488, 340, "为了使其 拥有出海港 它还将 帝国从版图上一分为二 这是皇帝所不能容忍的");
			supportDC.TextOutA(488, 380, "为此 皇帝 和 希伯来民主联邦东面的巨熊帝国秘密签署了一份合约 决定东西夹击 摧毁这个新生的国家");
			supportDC.TextOutA(488, 420, "本着训练新兵的目的  奥托和其大部分战友都参加了这次战役 奥托有幸被分在 著名将军古德里安的麾下");

			supportDC.TextOutA(488, 500, "第二章 初露锋芒");
			supportDC.TextOutA(488, 540, "第四关 秋风扫落叶（不是你扫 也不是扫你）");
			supportDC.TextOutA(488, 580, "作为刚投入战斗的新兵 本关 你将和 三位经验丰富的老兵 并肩作战 突袭敌军 重要港市 蛋泽");
			supportDC.TextOutA(488, 620, "敌军虽然人数众多 但是 缺乏训练 并且 坦克性能非常差 所以 你只要跟在大哥后面吃肉就行了");
			supportDC.TextOutA(488, 660, "胜利条件  和友军协同 消灭所有 敌军 （你可以试着站着不同看友军表演）");
			supportDC.TextOutA(488, 700, "失败条件  玩家坦克被摧毁 或者造成的伤害不够 ");
			supportDC.TextOutA(488, 740, "本关提示  尽量躲在大哥后面规避打击 这三位老鸽都带了殉爆旗和模块血量加成 非常能锤 但是同时注意不要过于酱油");
			supportDC.TextOutA(488, 780, "再按tab键 开始本关");


			supportDC.SetTextColor(RGB(255, 255, 255));
			supportDC.TextOutA(490, 100, "剧情概述： 由于奥托机智的绕侧 和队友的犀利 抗伤害 我方小队连战连捷 最后取得了全军团冠军小队");
			supportDC.TextOutA(490, 140, "随后奥托的小组顺利通过新兵教程结业考核 成为一名预备役坦克车长 随后军队放了几个月假 ");
			supportDC.TextOutA(490, 180, "放假期间 奥托和他的战友们整天泡在酒吧 把妹 喝酒 还有...  好不酸爽 正在此时指挥官突然宣布假期顺延");
			supportDC.TextOutA(490, 220, "原来 皇帝的扩张欲望不断变强 在捷伐斯克洛克 的 慕黑尼 与 不断绥靖的 嘤嘤怪帝国 和 我投降共和国 签订了");
			supportDC.TextOutA(490, 260, "满足皇帝扩张的不平等条约之后  皇帝将目光锁定了 在 帝国 东侧的 希伯来民主联邦");
			supportDC.TextOutA(490, 300, "希伯来民主联邦是 帝国在上次世界大战战败后割让土地所形成的一个国家");
			supportDC.TextOutA(490, 340, "为了使其 拥有出海港 它还将 帝国从版图上一分为二 这是皇帝所不能容忍的");
			supportDC.TextOutA(490, 380, "为此 皇帝 和 希伯来民主联邦东面的巨熊帝国秘密签署了一份合约 决定东西夹击 摧毁这个新生的国家");
			supportDC.TextOutA(490, 420, "本着训练新兵的目的  奥托和其大部分战友都参加了这次战役 奥托有幸被分在 著名将军古德里安的麾下");

			supportDC.TextOutA(490, 500, "第二章 初露锋芒");
			supportDC.TextOutA(490, 540, "第四关 秋风扫落叶（不是你扫 也不是扫你）");
			supportDC.TextOutA(490, 580, "作为刚投入战斗的新兵 本关 你将和 三位经验丰富的老兵 并肩作战 突袭敌军 重要港市 蛋泽");
			supportDC.TextOutA(490, 620, "敌军虽然人数众多 但是 缺乏训练 并且 坦克性能非常差 所以 你只要跟在大哥后面吃肉就行了");
			supportDC.TextOutA(490, 660, "胜利条件  和友军协同 消灭所有 敌军 （你可以试着站着不同看友军表演）");
			supportDC.TextOutA(490, 700, "失败条件  玩家坦克被摧毁 或者造成的伤害不够");
			supportDC.TextOutA(490, 740, "本关提示  尽量躲在大哥后面规避打击 这三位老鸽都带了殉爆旗和模块血量加成 非常能锤 但是同时注意不要过于酱油");
			supportDC.TextOutA(490, 780, "再按tab键 开始本关");
		}
		else if(current_stage == 5)
		{
			//supportDC.FillSolidRect(0, 0, DIALOG_WIDTH, DIALOG_WIDTH, RGB(240, 240, 240));
			supportDC.SelectObject(&f);
			supportDC.SetTextColor(RGB(0, 0, 0));
			supportDC.TextOutA(488, 100, "剧情概述： 蛋泽迅速被攻克 希伯来民主联邦节节败退 我方迅速拿下了敌人多个城市");
			supportDC.TextOutA(488, 140, "敌人虽然数量众多 但是 缺乏训练 因此 一溃千里 我方现在已经逼近敌人首都 华石");
			supportDC.TextOutA(488, 180, "但是 敌人也不会束手就擒 现在 大量的敌军正在 华石附近集结  企图作最后的抵抗");
			supportDC.TextOutA(488, 220, "这些 负隅顽抗的敌军  都经历了战火的洗礼  已经从乌合之众中蜕变出来");
			supportDC.TextOutA(488, 260, "现在 军团长命令 你们 彻底消灭 集结的敌军 为 进攻华石 作准备 ");
			supportDC.TextOutA(488, 340, "第五关 负隅顽抗");
			supportDC.TextOutA(488, 380,  "随着参加实战的增加你具有了一定的经验 不过 仍然还需要抱大腿");
			supportDC.TextOutA(488, 420, "这关中  有大量敌人具备高级智能 同时有少量敌人会以你为第一目标");
			supportDC.TextOutA(488, 460, "胜利条件  和友军协同 消灭所有  敌军");
			supportDC.TextOutA(488, 500, "失败条件  玩家坦克被摧毁");
			supportDC.TextOutA(488, 540, "本关提示  尽量靠近友方大哥多数敌人的仇恨都是最近目标 敌人会从四面打来但友军非常强悍 注意一定不要落单");
			supportDC.TextOutA(488, 580, "再按tab键 开始本关");

			supportDC.SetTextColor(RGB(255, 255, 255));
			supportDC.TextOutA(490, 100, "剧情概述： 蛋泽迅速被攻克 希伯来民主联邦节节败退 我方迅速拿下了敌人多个城市");
			supportDC.TextOutA(490, 140, "敌人虽然数量众多 但是 缺乏训练 因此 一溃千里 我方现在已经逼近敌人首都 华石");
			supportDC.TextOutA(490, 180, "但是 敌人也不会束手就擒 现在 大量的敌军正在 华石附近集结  企图作最后的抵抗");
			supportDC.TextOutA(490, 220, "这些 负隅顽抗的敌军  都经历了战火的洗礼  已经从乌合之众中蜕变出来");
			supportDC.TextOutA(490, 260, "现在 军团长命令 你们 彻底消灭 集结的敌军 为 进攻华石 作准备 ");
			supportDC.TextOutA(490, 340, "第五关 负隅顽抗");
			supportDC.TextOutA(490, 380,  "随着参加实战的增加你具有了一定的经验 不过 仍然还需要抱大腿");
			supportDC.TextOutA(490, 420, "这关中  有大量敌人具备高级智能 同时有少量敌人会以你为第一目标");
			supportDC.TextOutA(490, 460, "胜利条件  和友军协同 消灭所有  敌军");
			supportDC.TextOutA(490, 500, "失败条件  玩家坦克被摧毁");
			supportDC.TextOutA(490, 540, "本关提示  尽量靠近友方大哥多数敌人的仇恨都是最近目标 敌人会从四面打来但友军非常强悍 注意一定不要落单");
			supportDC.TextOutA(490, 580, "再按tab键 开始本关");
		}
		else if(current_stage == 6)
		{
			//supportDC.FillSolidRect(0, 0, DIALOG_WIDTH, DIALOG_WIDTH, RGB(240, 240, 240));
			supportDC.SelectObject(&f);
			supportDC.SetTextColor(RGB(0, 0, 0));
			supportDC.TextOutA(488, 100, "剧情概述： 首都华石附近的敌人主力已经被我们歼灭 现在 是给敌人最后一击的时候了");
			supportDC.TextOutA(488, 140, "华石虽然不是军事重镇 但是 敌军仍然在城中布置了大量炮塔（架空历史 历史上华沙被一顿轰炸就投了）");
			supportDC.TextOutA(488, 180, "同时 所有 敌军剩余的部队 都 在这座城市中集结 它们将誓死保卫它们的首都");
			supportDC.TextOutA(488, 220, "因此 军团长古德里安 想出了一个 攻占敌人 城防设施的 计划 ");
			supportDC.TextOutA(488, 260, "根据 皇帝的走狗  盖世太保们 探听的情报 只要摧毁 位于华石城正中心的城防炮塔");
			supportDC.TextOutA(488, 300, "就能控制 其他城防建筑 从而 控制整个城市  于是 这个计划开始了 奥托 也被 编入了这个任务的分队中");
			supportDC.TextOutA(488, 340, "为了顶住炮塔的火力 皇帝特意向 潘达利亚大陆的盟友 - 天朝 求援，借来了一大堆城管 据说他们很会拆建筑");

			supportDC.TextOutA(488, 380, "第六关 进攻华石");
			supportDC.TextOutA(488, 420, "前面一直打酱油？这关是你大显身手的时候了 炮塔的弱点在于背面和侧面 所以你需要和友军配合从多面进攻");
			supportDC.TextOutA(488, 460, "这关中 你的炮弹拥有更高的几率触发殉爆 并且 队友的AI 目的在于牵制敌人");
			supportDC.TextOutA(488, 500, "胜利条件  消灭位于城市正中心的华石城防核心炮塔");
			supportDC.TextOutA(488, 540, "失败条件  玩家坦克被摧毁");
			supportDC.TextOutA(488, 580, "本关提示  利用友军牵制敌人 从侧面和后面摧毁敌人的炮塔");
			supportDC.TextOutA(488, 620, "再按tab键 开始本关");



			supportDC.SetTextColor(RGB(255, 255, 255));
			supportDC.TextOutA(490, 100, "剧情概述： 首都华石附近的敌人主力已经被我们歼灭 现在 是给敌人最后一击的时候了");
			supportDC.TextOutA(490, 140, "华石虽然不是军事重镇 但是 敌军仍然在城中布置了大量炮塔（架空历史 历史上华沙被一顿轰炸就投了）");
			supportDC.TextOutA(490, 180, "同时 所有 敌军剩余的部队 都 在这座城市中集结 它们将誓死保卫它们的首都");
			supportDC.TextOutA(490, 220, "因此 军团长古德里安 想出了一个 攻占敌人 城防设施的 计划 ");
			supportDC.TextOutA(490, 260, "根据 皇帝的走狗  盖世太保们 探听的情报 只要摧毁 位于华石城正中心的城防炮塔");
			supportDC.TextOutA(490, 300, "就能控制 其他城防建筑 从而 控制整个城市  于是 这个计划开始了 奥托 也被 编入了这个任务的分队中");
			supportDC.TextOutA(490, 340, "为了顶住炮塔的火力 皇帝特意向 潘达利亚大陆的盟友 - 天朝 求援，借来了一大堆城管 据说他们很会拆建筑");

			supportDC.TextOutA(490, 380, "第六关 进攻华石");
			supportDC.TextOutA(490, 420, "前面一直打酱油？这关是你大显身手的时候了 炮塔的弱点在于背面和侧面 所以你需要和友军配合从多面进攻");
			supportDC.TextOutA(490, 460, "这关中 你的炮弹拥有更高的几率触发殉爆 并且 队友的AI 目的在于牵制敌人");
			supportDC.TextOutA(490, 500, "胜利条件  消灭位于城市正中心的华石城防核心炮塔");
			supportDC.TextOutA(490, 540, "失败条件  玩家坦克被摧毁");
			supportDC.TextOutA(490, 580, "本关提示  利用友军牵制敌人 从侧面和后面摧毁敌人的炮塔");
			supportDC.TextOutA(490, 620, "再按tab键 开始本关");
		}
		else if(current_stage == 7)
		{
			//supportDC.FillSolidRect(0, 0, DIALOG_WIDTH, DIALOG_WIDTH, RGB(240, 240, 240));
			supportDC.SelectObject(&f);
			supportDC.SetTextColor(RGB(0, 0, 0));
			supportDC.TextOutA(488, 100, "剧情概述： 由于古德里安将军的出色指挥 华石城迅速被我军攻克 与此同时 巨熊帝国也攻到了华石东面");
			supportDC.TextOutA(488, 140, "希伯来民主联邦灭国  部分 在联邦 境内的出埃及人 侥幸逃脱 ");
			supportDC.TextOutA(488, 180, "但是大部分则 落入 巨熊帝国 和 小胡子帝国 手中 他们中的一部分被立刻无理由杀死");
			supportDC.TextOutA(488, 220, "更多人 则被 送进了 小胡子帝国 和 巨熊帝国 的集中营 在那里承受了无数非人的虐待和凌辱后");
			supportDC.TextOutA(488, 260, "几乎被屠杀殆尽  只有少部分活到了战后  返回到了他们的发源地 铝安（真实名称 锡安）并创建了椅色列帝国");
			supportDC.TextOutA(488, 300, "城破之后 盖世太保和皇卫军 在城内烧杀抢掠 然而奥托所在的国防军并没有这么做 他们开始向城东巡逻");
			supportDC.TextOutA(488, 340, "巡逻过程中 奥托和 众人分开行动 突然他发现了 一堆灰绿色的坦克 他们不由分说就开始向奥托开火 ");
			supportDC.TextOutA(488, 420, "第七关 遭遇巨熊");
			supportDC.TextOutA(488, 460, "这关中 你需要独自面对 敌军 敌军不会一次性出现 而是 源源不断的涌来");
			supportDC.TextOutA(488, 500, "在消灭一定数量的敌军后 友方援军就会赶到 届时 我方便具有碾压优势 ");
			supportDC.TextOutA(488, 540, "胜利条件  和友军配合 或独自 消灭所有敌军");
			supportDC.TextOutA(488, 580, "失败条件  玩家坦克被摧毁");
			supportDC.TextOutA(488, 620, "本关提示  尽快消灭数个敌军 召唤友军结束战斗  对方坦克虽然智能很高 但是很慢 很容易被风筝");
			supportDC.TextOutA(488, 660, "本关提示2 敌军大本营位于东方 开始的支援将从东方派来 所以在交战中尽量靠西走 ");
			supportDC.TextOutA(488, 700, "本关提示3 友方大军出现后 可以考虑躲在角落里避免被击杀");
			supportDC.TextOutA(488, 740, "再按tab键 开始本关");

			supportDC.SetTextColor(RGB(255, 255, 255));
			supportDC.TextOutA(490, 100, "剧情概述： 由于古德里安将军的出色指挥 华石城迅速被我军攻克 与此同时 巨熊帝国也攻到了华石东面");
			supportDC.TextOutA(490, 140, "希伯来民主联邦灭国  部分 在联邦 境内的出埃及人 侥幸逃脱 ");
			supportDC.TextOutA(490, 180, "但是大部分则 落入 巨熊帝国 和 小胡子帝国 手中 他们中的一部分被立刻无理由杀死");
			supportDC.TextOutA(490, 220, "更多人 则被 送进了 小胡子帝国 和 巨熊帝国 的集中营 在那里承受了无数非人的虐待和凌辱后");
			supportDC.TextOutA(490, 260, "几乎被屠杀殆尽  只有少部分活到了战后  返回到了他们的发源地 铝安（真实名称 锡安）并创建了椅色列帝国");
			supportDC.TextOutA(490, 300, "城破之后 盖世太保和皇卫军 在城内烧杀抢掠 然而奥托所在的国防军并没有这么做 他们开始向城东巡逻");
			supportDC.TextOutA(490, 340, "巡逻过程中 奥托和 众人分开行动 突然他发现了 一堆灰绿色的坦克 他们不由分说就开始向奥托开火 ");
			supportDC.TextOutA(490, 420, "第七关 遭遇巨熊");
			supportDC.TextOutA(490, 460, "这关中 你需要独自面对 敌军 敌军不会一次性出现 而是 源源不断的涌来");
			supportDC.TextOutA(490, 500, "在消灭一定数量的敌军后 友方援军就会赶到 届时 我方便具有碾压优势 ");
			supportDC.TextOutA(490, 540, "胜利条件  和友军配合 或独自 消灭所有敌军");
			supportDC.TextOutA(490, 580, "失败条件  玩家坦克被摧毁");
			supportDC.TextOutA(490, 620, "本关提示  尽快消灭数个敌军 召唤友军结束战斗  对方坦克虽然智能很高 但是很慢 很容易被风筝");
			supportDC.TextOutA(490, 660, "本关提示2 敌军大本营位于东方 开始的支援将从东方派来 所以在交战中尽量靠西走 ");
			supportDC.TextOutA(490, 700, "本关提示3 友方大军出现后 可以考虑躲在角落里避免被击杀");
			supportDC.TextOutA(490, 740, "再按tab键 开始本关");
		}
		else if(current_stage == 8)
		{
			//supportDC.FillSolidRect(0, 0, DIALOG_WIDTH, DIALOG_WIDTH, RGB(240, 240, 240));
			supportDC.SelectObject(&f);
			int print_l = 1;
			supportDC.SetTextColor(RGB(0, 0, 0));
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "第三章 石破天惊");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "剧情概述： 侦查小分队消灭了 巨熊帝国的侦查分队 但是付出了敌人两倍的伤亡 这使军团长非常震惊");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "通过分析残骸 我们的科学家得到了惊人的结论：巨熊帝国现役的坦克远比我们的强大但不够先进 比如无通信设备");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "回到华石的驻扎地 奥托 正期待着 连长的训斥 因为 巨熊帝国从名义上是友军 但是 连长并没有这么做");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "相反 连长很高兴的说 虽然你们付出了代价 但是 也痛击了我们的敌人 敌人？ 奥托满脸狐疑 但随后恍然大悟");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "由于这次作战 奥托被授予二级战斗嘉奖令 同时 巨熊帝国 和 小胡子帝国 均称 这次交火是一场误会");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "占领华石后 奥托迎来了 长达7个月的假期 经历了战场上随时都可能一命呜呼的紧张之后 这可以说是 大狂欢了");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "然而 奥托并没有特别感到兴奋相反 他感觉有点无聊 只能在家弹弹钢琴或者和朋友听音乐（奥托自幼想成为音乐家)");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "七个月后 也就是 西元1940年 5月初 军方宣布所有士兵结束休假 回到军中 又可以见到基友了 奥托不由得兴奋起来");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "自入侵希伯来民主联邦以后 嘤嘤怪帝国和我投降共和国 一直在对小胡子帝国作战 但是 却虎头蛇尾 攻势没有持续");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "现在 在消灭了 东临希伯来北临蛋卖等国之后 军方决定对实力强大的 帝国一百年一来的宿敌 我投降共和国展开攻击");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "最高统帅部 决定 部分部队 吸引住 敌方大部队 然后主力先攻击弱小的邻国然后穿越被敌军认为坦克部队不可穿越的迷雾森林");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "我投降共和国 有 引以为傲的 万里长城 这是在上次世界大战 后 其将军借鉴了战争经验所修建的 绵延数百公里 坚不可摧 ");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "然而万里长城 有个弱点 就是 在 迷雾山 和 迷雾森林地区 由于地形过于恶劣 所以军方认为敌国不会从哪里进攻而没延伸到此");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "只要穿过了 迷雾森林 就能绕过万里长城 使其变成无用的摆设 同时 我投降共和国 的首都埃菲尔 也会暴露在我军的攻击下");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "奥托由于之前在华石战役中表现优秀 被分在了主攻队 这在新兵中可不常见 同行的同期新兵只有 魏特曼 和 巴克曼");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "作为主攻队 奥托他们的任务是 迅速 到位 不过 他们现在就要面对 弱小邻国 比例比例 和 卢森巴克 的 守军 他们不算太强");
			print_l ++;
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "第八关 风驰电掣");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "胜利条件 和友军配合 在指定时间内 消灭所有敌军 ");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "失败条件 玩家坦克被摧毁 或者 超过指定时间 ");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "本关提示 尽量和友军分散站位 因为敌军会按波次出现在不同位置 同时 本关单独行动并不会有太大的危险 多利用引擎加速跑位");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "再按tab键 开始本关");


			print_l = 1;
			supportDC.SetTextColor(RGB(255, 255, 255));
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "第三章 石破天惊");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "剧情概述： 侦查小分队消灭了 巨熊帝国的侦查分队 但是付出了敌人两倍的伤亡 这使军团长非常震惊");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "通过分析残骸 我们的科学家得到了惊人的结论：巨熊帝国现役的坦克远比我们的强大但不够先进 比如无通信设备");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "回到华石的驻扎地 奥托 正期待着 连长的训斥 因为 巨熊帝国从名义上是友军 但是 连长并没有这么做");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "相反 连长很高兴的说 虽然你们付出了代价 但是 也痛击了我们的敌人 敌人？ 奥托满脸狐疑 但随后恍然大悟");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "由于这次作战 奥托被授予二级战斗嘉奖令 同时 巨熊帝国 和 小胡子帝国 均称 这次交火是一场误会");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "占领华石后 奥托迎来了 长达7个月的假期 经历了战场上随时都可能一命呜呼的紧张之后 这可以说是 大狂欢了");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "然而 奥托并没有特别感到兴奋相反 他感觉有点无聊 只能在家弹弹钢琴或者和朋友听音乐（奥托自幼想成为音乐家)");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "七个月后 也就是 西元1940年 5月初 军方宣布所有士兵结束休假 回到军中 又可以见到基友了 奥托不由得兴奋起来");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "自入侵希伯来民主联邦以后 嘤嘤怪帝国和我投降共和国 一直在对小胡子帝国作战 但是 却虎头蛇尾 攻势没有持续");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "现在 在消灭了 东临希伯来北临蛋卖等国之后 军方决定对实力强大的 帝国一百年一来的宿敌 我投降共和国展开攻击");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "最高统帅部 决定 部分部队 吸引住 敌方大部队 然后主力先攻击弱小的邻国然后穿越被敌军认为坦克部队不可穿越的迷雾森林");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "我投降共和国 有 引以为傲的 万里长城 这是在上次世界大战 后 其将军借鉴了战争经验所修建的 绵延数百公里 坚不可摧 ");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "然而万里长城 有个弱点 就是 在 迷雾山 和 迷雾森林地区 由于地形过于恶劣 所以军方认为敌国不会从哪里进攻而没延伸到此");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "只要穿过了 迷雾森林 就能绕过万里长城 使其变成无用的摆设 同时 我投降共和国 的首都埃菲尔 也会暴露在我军的攻击下");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "奥托由于之前在华石战役中表现优秀 被分在了主攻队 这在新兵中可不常见 同行的同期新兵只有 魏特曼 和 巴克曼");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "作为主攻队 奥托他们的任务是 迅速 到位 不过 他们现在就要面对 弱小邻国 比例比例 和 卢森巴克 的 守军 他们不算太强");
			print_l ++;
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "第八关 风驰电掣");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "胜利条件 和友军配合 在指定时间内 消灭所有敌军 ");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "失败条件 玩家坦克被摧毁 或者 超过指定时间 ");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "本关提示 尽量和友军分散站位 因为敌军会按波次出现在不同位置 同时 本关单独行动并不会有太大的危险 多利用引擎加速跑位");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "再按tab键 开始本关");
		}

		else if(current_stage == 9)
		{
			//supportDC.FillSolidRect(0, 0, DIALOG_WIDTH, DIALOG_WIDTH, RGB(240, 240, 240));
			supportDC.SelectObject(&f);
			int print_l = 1;
			supportDC.SetTextColor(RGB(0, 0, 0));
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "剧情概述： 比例比例 和 卢森巴克 的 守军 被 奥托所在的集团军迅速歼灭 地方比奥托家后院大不了多少的卢森巴克 迅速宣布投降");
			//                                          "本关提示  尽量靠近友方大哥多数敌人的仇恨都是最近目标 敌人会从四面打来但友军非常强悍 注意一定不要落单");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "然而 比例比例国还在硬抗 虽然他们的主力已经损失殆尽 但是他们在首都 塞尔布鲁 仍然有坚固的防御工事和 训练有素的卫队");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "现在 嘤嘤怪帝国的著名将军 蒙哥马利 和 我投降共和国未来的总统 戴高乐 以及 上次世界大战 中 我投降共和国的著名将军");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), " 已经有80岁高龄的魏刚 等 有先见之明的将军 们 已经 看出了我军的企图 正全力回防  ");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "但是他们赶来还需要一些时间 为了不使突袭计划功亏一篑  指挥部命令奥托所在的集团军 用最快速度 拿下 塞尔布鲁");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "如果我们能如期攻下塞尔布鲁 那么 我们就有充足的时间穿过迷雾森林 届时 我们不仅绕过了万里长城");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "前来救援的 联萌军也将会被困在我们的包围圈之中 这样的话 我们离胜利就不远了");
			print_l ++;
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "第九关 进攻塞尔布鲁");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "奥托所在的集团军已经逼近 比例比例国 首都 塞尔布鲁 时间紧迫 他们要尽可能快的攻下这座城市");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "和华石城一样 塞尔布鲁拥有城防炮塔 但是无论从数量还是 质量上都不如 华石 但仍然需要触发数次殉爆才能摧毁 ");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "同时 敌军有多波 增援部队 增援部队 的 单体战力不如 友军 和 你 但是 数量众多 并且会从奇奇怪怪的地方出现");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "友军也会有 两次增援 从不同方向赶来");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "友军AI 的 策略是 正面对刚 因此 你需要进行权衡 要么你吸引 炮塔火力 友军拆背面 要么 反之 你需要随机应变");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "胜利条件 和友军配合 在指定时间内 消灭所有敌军 ");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "失败条件 玩家坦克被摧毁 或者超过指定时间");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "本关提示 和华石战役类似 你需要和友军从不同夹角进攻 不过这关请注意安全 对方可能随时从你身后出现给你一个惊喜");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "再按tab键 开始本关");


			print_l = 1;
			supportDC.SetTextColor(RGB(255, 255, 255));
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "剧情概述： 比例比例 和 卢森巴克 的 守军 被 奥托所在的集团军迅速歼灭 地方比奥托家后院大不了多少的卢森巴克 迅速宣布投降");
			//                                          "本关提示  尽量靠近友方大哥多数敌人的仇恨都是最近目标 敌人会从四面打来但友军非常强悍 注意一定不要落单");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "然而 比例比例国还在硬抗 虽然他们的主力已经损失殆尽 但是他们在首都 塞尔布鲁 仍然有坚固的防御工事和 训练有素的卫队");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "现在 嘤嘤怪帝国的著名将军 蒙哥马利 和 我投降共和国未来的总统 戴高乐 以及 上次世界大战 中 我投降共和国的著名将军");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), " 已经有80岁高龄的魏刚 等 有先见之明的将军 们 已经 看出了我军的企图 正全力回防  ");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "但是他们赶来还需要一些时间 为了不使突袭计划功亏一篑  指挥部命令奥托所在的集团军 用最快速度 拿下 塞尔布鲁");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "如果我们能如期攻下塞尔布鲁 那么 我们就有充足的时间穿过迷雾森林 届时 我们不仅绕过了万里长城");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "前来救援的 联萌军也将会被困在我们的包围圈之中 这样的话 我们离胜利就不远了");
			print_l ++;
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "第九关 进攻塞尔布鲁");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "奥托所在的集团军已经逼近 比例比例国 首都 塞尔布鲁 时间紧迫 他们要尽可能快的攻下这座城市");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "和华石城一样 塞尔布鲁拥有城防炮塔 但是无论从数量还是 质量上都不如 华石 但仍然需要触发数次殉爆才能摧毁 ");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "同时 敌军有多波 增援部队 增援部队 的 单体战力不如 友军 和 你 但是 数量众多 并且会从奇奇怪怪的地方出现");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "友军也会有 两次增援 从不同方向赶来");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "友军AI 的 策略是 正面对刚 因此 你需要进行权衡 要么你吸引 炮塔火力 友军拆背面 要么 反之 你需要随机应变");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "胜利条件 和友军配合 在指定时间内 消灭所有敌军 ");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "失败条件 玩家坦克被摧毁 或者超过指定时间");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "本关提示 和华石战役类似 你需要和友军从不同夹角进攻 不过这关请注意安全 对方可能随时从你身后出现给你一个惊喜");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "再按tab键 开始本关");
		}
		else if(current_stage == 10)
		{
			//supportDC.FillSolidRect(0, 0, DIALOG_WIDTH, DIALOG_WIDTH, RGB(240, 240, 240));
			supportDC.SelectObject(&f);
			int print_l = 1;
			supportDC.SetTextColor(RGB(0, 0, 0));

			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "剧情概述： 经过一番不算轻松的战斗 奥托所在的装甲军攻克了 塞尔布鲁 并 迅速 穿过了 迷雾森林 ");
			//                                          "本关提示  尽量靠近友方大哥多数敌人的仇恨都是最近目标 敌人会从四面打来但友军非常强悍 注意一定不要落单");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "然后兵分三路 一路向北 准备控制重要港市 大撤退城 截断联盟军 另一路向南 包围驻守在 万里长城中的敌军 阻止他们 回防首都");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "第三路 则直奔首都 埃菲尔  奥托 被分在了 攻打万里长城的那一路 而基友科舍尔 被 分去 进攻 大撤退城");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "临行前 他们约好等再汇合时 要把自己经历的战斗 讲述给对方听（这样作者才能 让玩家同时打 大撤退城和 万里长城这两关");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "大约十天后 我投降共和国 宣布投降 并在南部小镇 逃跑镇 建立了 傀儡政府  我还要投降共和国 奥托和 科舍尔也在埃菲尔汇合");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "不过一部分 我投降共和国余孽 随 他们的 坦克指挥官 戴高乐 跑到了 嘤嘤怪帝国本土 创建了 我一定会回来的共和国");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "一见面 奥托 先抢了话题 滔滔不绝的 讲起他之前的战斗经历");
			print_l ++;
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "第十关 万里长城围歼战");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "拿下 塞尔布鲁后 奥托所在的集团军分成了 三队 奥托奉命 南下 围歼 被困在万里长城 企图 突围支援首都 的敌军 ");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "万里长城 防线非常坚固 配备火力非常强大的 要塞炮 并用 坚固的水泥工事保护起来 比 华石城的要塞还要坚固  ");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "因此 军团长 建议 引蛇出洞 利用敌人急于 回防的 心理 将敌人引出 然后歼灭 各位军事参谋和高级军官对此都非常赞同");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "本关中 敌军会一次性出现 他们规模庞大  战斗力也很不错 但是速度很慢 战斗刚开始时 友军的数量很少 你需要牵制敌人 ");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "等待友军赶到后 再从多个方向攻击敌人  在万里长城 东侧 也就是 还在本土的友军 会派出大量增援 吸引万里长城的火力 ");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "以便 我们消灭 在 要塞附近不肯出来的敌军 本关只要消灭 一定数量的敌军即可 不过请注意 友军的增援并不是无限的 ");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "胜利条件 和友军消灭一定数目的敌军");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "失败条件 玩家坦克被摧毁");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "本关提示 等到友军牵制 分散敌人火力后 从后面 攻击 效率最高 友军数目有限 请 好好利用");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "本关提示2  本关友方攻击力不强 不过很能抗 所以 要做好 输出配合友军");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "再按tab键 开始本关");



			supportDC.SetTextColor(RGB(255, 255, 255));
			print_l = 1;
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "剧情概述： 经过一番不算轻松的战斗 奥托所在的装甲军攻克了 塞尔布鲁 并 迅速 穿过了 迷雾森林 ");
			//                                          "本关提示  尽量靠近友方大哥多数敌人的仇恨都是最近目标 敌人会从四面打来但友军非常强悍 注意一定不要落单");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "然后兵分三路 一路向北 准备控制重要港市 大撤退城 截断联盟军 另一路向南 包围驻守在 万里长城中的敌军 阻止他们 回防首都");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "第三路 则直奔首都 埃菲尔  奥托 被分在了 攻打万里长城的那一路 而基友科舍尔 被 分去 进攻 大撤退城");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "临行前 他们约好等再汇合时 要把自己经历的战斗 讲述给对方听（这样作者才能 让玩家同时打 大撤退城和 万里长城这两关");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "大约十天后 我投降共和国 宣布投降 并在南部小镇 逃跑镇 建立了 傀儡政府  我还要投降共和国 奥托和 科舍尔也在埃菲尔汇合");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "不过一部分 我投降共和国余孽 随 他们的 坦克指挥官 戴高乐 跑到了 嘤嘤怪帝国本土 创建了 我一定会回来的共和国");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "一见面 奥托 先抢了话题 滔滔不绝的 讲起他之前的战斗经历");
			print_l ++;
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "第十关 万里长城围歼战");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "拿下 塞尔布鲁后 奥托所在的集团军分成了 三队 奥托奉命 南下 围歼 被困在万里长城 企图 突围支援首都 的敌军 ");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "万里长城 防线非常坚固 配备火力非常强大的 要塞炮 并用 坚固的水泥工事保护起来 比 华石城的要塞还要坚固  ");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "因此 军团长 建议 引蛇出洞 利用敌人急于 回防的 心理 将敌人引出 然后歼灭 各位军事参谋和高级军官对此都非常赞同");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "本关中 敌军会一次性出现 他们规模庞大  战斗力也很不错 但是速度很慢 战斗刚开始时 友军的数量很少 你需要牵制敌人 ");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "等待友军赶到后 再从多个方向攻击敌人  在万里长城 东侧 也就是 还在本土的友军 会派出大量增援 吸引万里长城的火力 ");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "以便 我们消灭 在 要塞附近不肯出来的敌军 本关只要消灭 一定数量的敌军即可 不过请注意 友军的增援并不是无限的 ");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "胜利条件 和友军消灭一定数目的敌军");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "失败条件 玩家坦克被摧毁");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "本关提示 等到友军牵制 分散敌人火力后 从后面 攻击 效率最高 友军数目有限 请 好好利用");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "本关提示2  本关友方攻击力不强 不过很能抗 所以 要做好 输出配合友军");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "再按tab键 开始本关");

		}
		else if(current_stage == 11)
		{
			//supportDC.FillSolidRect(0, 0, DIALOG_WIDTH, DIALOG_WIDTH, RGB(240, 240, 240));
			supportDC.SelectObject(&f);
			int print_l = 1;
			supportDC.SetTextColor(RGB(0, 0, 0));


			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "剧情概述：奥托 一番绘声绘色的叙述 引来了一帮吃瓜群众 他们全神贯注的听着 都入了迷 然而 科舍尔 似乎 根本没在好好听");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "奥托话音刚落 科舍尔 立刻 抢过话题 喋喋不休的说了起来....");
			print_l ++;
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "第十一关 大撤退城攻防战");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "拿下塞尔布鲁后 奥托一行人 兵分三路  科舍尔 被分到了 前往北方 截短 敌人后路的部队中 他们的目标是 北部港市 大撤退城");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "由于上级一再要求 越快越好 加上 战场环境并不是很开阔 科舍尔和一部分战友先拿下了 大撤退城 并就地修建了防御工事");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "而友方主力 还在前往大撤退城 的 鹿上  此时 联萌军著名将军 蒙哥马利 眼见如果大撤退城被攻占 联萌军将面临被送到海里喂鱼");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "的可怕境况  于是 蒙哥马利 命令 部队反击 夺回大撤退城  但是联萌军之前连战连败 虽然人数众多 但是士气低迷");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "迫不得已 蒙哥马利 只能 使用了 上古时期 巨熊帝国前身 狗熊帝国 为了 抵抗 当时横扫卡利姆多大陆 的 我投降共和国前身 ");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "把你打投降帝国 的 首领 拿着破轮 的 军队 的 攻击 时 所使用的绝招： 不许后退一步 违令者死");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "然而蒙哥马利没有料到的是 众军听到命令后 仍然不敢发起进攻 于是 蒙哥马利命令 坦克向友军步兵开火 ");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "然而 联萌军就是联萌军 在蒙哥马利用 坦克炮 炮决了 十万名 士兵 后 剩下的十五万 士兵 仍然 无动于衷 ");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "此时 其实联萌军无论是在人数 还是 装备 方面仍然具有绝对优势 如何 调动士兵呢 ？ 蒙哥马利 沉思着");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "再后退者  切屌！ 蒙哥马利突然 茅塞顿开 大喊了起来  果然 此法 收效极佳 士兵们听到这么可怕的命令后");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "都向发了疯一样 冲向了 大撤退城  一帮精虫 蒙哥马利 无奈的叹了口气 ");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "本关 你将扮演 奥托的好基友 同样是日后在东线并肩作战的战友 也是日后的一名德军坦克王牌 科舍尔 ");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "敌军将从东北方向源源不断的进攻 但是每波兵力都不太强  我方在大部队赶到之前 需要依靠 城防 阻击敌人");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "一段时间后 我方大部队将赶到 届时发起 反击 一举消灭 敌人 敌人每波人数不多 但是 支援会越来越频繁 ");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "胜利条件 和友军 配合 歼灭所有来犯之敌 ");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "失败条件 玩家坦克被摧毁 或者 大撤退城核心炮塔被摧毁");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "本关提示 血量较低时 可以利用炮塔抗伤害  当敌人和炮塔交火时 可以吸引其注意力 这也是你本关的主要任务");
			supportDC.TextOutA(338, 40 + 40 * (print_l ++ ), "本关提示2  敌军增援的逻辑是 每隔一段时间或者 场上没有敌人 触发 所以 可以留一两个敌人拖延敌军支援");



			print_l = 1;
			supportDC.SetTextColor(RGB(255, 255, 255));
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "剧情概述：奥托 一番绘声绘色的叙述 引来了一帮吃瓜群众 他们全神贯注的听着 都入了迷 然而 科舍尔 似乎 根本没在好好听");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "奥托话音刚落 科舍尔 立刻 抢过话题 喋喋不休的说了起来....");
			print_l ++;
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "第十一关 大撤退城攻防战");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "拿下塞尔布鲁后 奥托一行人 兵分三路  科舍尔 被分到了 前往北方 截短 敌人后路的部队中 他们的目标是 北部港市 大撤退城");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "由于上级一再要求 越快越好 加上 战场环境并不是很开阔 科舍尔和一部分战友先拿下了 大撤退城 并就地修建了防御工事");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "而友方主力 还在前往大撤退城 的 鹿上  此时 联萌军著名将军 蒙哥马利 眼见如果大撤退城被攻占 联萌军将面临被送到海里喂鱼");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "的可怕境况  于是 蒙哥马利 命令 部队反击 夺回大撤退城  但是联萌军之前连战连败 虽然人数众多 但是士气低迷");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "迫不得已 蒙哥马利 只能 使用了 上古时期 巨熊帝国前身 狗熊帝国 为了 抵抗 当时横扫卡利姆多大陆 的 我投降共和国前身 ");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "把你打投降帝国 的 首领 拿着破轮 的 军队 的 攻击 时 所使用的绝招： 不许后退一步 违令者死");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "然而蒙哥马利没有料到的是 众军听到命令后 仍然不敢发起进攻 于是 蒙哥马利命令 坦克向友军步兵开火 ");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "然而 联萌军就是联萌军 在蒙哥马利用 坦克炮 炮决了 十万名 士兵 后 剩下的十五万 士兵 仍然 无动于衷 ");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "此时 其实联萌军无论是在人数 还是 装备 方面仍然具有绝对优势 如何 调动士兵呢 ？ 蒙哥马利 沉思着");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "再后退者  切屌！ 蒙哥马利突然 茅塞顿开 大喊了起来  果然 此法 收效极佳 士兵们听到这么可怕的命令后");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "都向发了疯一样 冲向了 大撤退城  一帮精虫 蒙哥马利 无奈的叹了口气 ");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "本关 你将扮演 奥托的好基友 同样是日后在东线并肩作战的战友 也是日后的一名德军坦克王牌 科舍尔 ");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "敌军将从东北方向源源不断的进攻 但是每波兵力都不太强  我方在大部队赶到之前 需要依靠 城防 阻击敌人");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "一段时间后 我方大部队将赶到 届时发起 反击 一举消灭 敌人 敌人每波人数不多 但是 支援会越来越频繁 ");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "胜利条件 和友军 配合 歼灭所有来犯之敌 ");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "失败条件 玩家坦克被摧毁 或者 大撤退城核心炮塔被摧毁");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "本关提示 血量较低时 可以利用炮塔抗伤害  当敌人和炮塔交火时 可以吸引其注意力 这也是你本关的主要任务");
			supportDC.TextOutA(340, 40 + 40 * (print_l ++ ), "本关提示2  敌军增援的逻辑是 每隔一段时间或者 场上没有敌人 触发 所以 可以留一两个敌人拖延敌军支援");
		}
		else if(current_stage == 12)
		{
			//supportDC.FillSolidRect(0, 0, DIALOG_WIDTH, DIALOG_WIDTH, RGB(240, 240, 240));
			supportDC.SelectObject(&f);
			int print_l = 1;
			supportDC.SetTextColor(RGB(0, 0, 0));
			supportDC.TextOutA(198, 40 + 40 * (print_l ++ ), "剧情概述：不得不说科舍尔是真的能扯 而且还很会扯 他足足扯了三个小时 更奇怪的是 围过来听他讲的人越来越多而且还有人补充");
			supportDC.TextOutA(198, 40 + 40 * (print_l ++ ), "当 科舍尔讲到 蒙哥马利 用 切屌威胁 属下时 大家笑得前仰后合 同时也有不少人暗暗赞叹蒙哥马利的智慧");;
			supportDC.TextOutA(198, 40 + 40 * (print_l ++ ), "之后就是 科舍尔 开始 讲述 他们守城是如何困难 敌军是如何多 如何疯狂 ....大家听得不亦乐乎 尤其是和科舍尔一起行动的战友们");
			supportDC.TextOutA(198, 40 + 40 * (print_l ++ ), "真的是 好险 我的车被打中了6发 引擎 和 履带都坏了 城防也被撕开一个大口子.....他继续讲");
			supportDC.TextOutA(198, 40 + 40 * (print_l ++ ), "不过这是 友军 突然赶到了 不得不说 四号坦克真的比 我们开的二号坦克性能好多了 他们如砍瓜切菜一样 料理掉了敌军");
			supportDC.TextOutA(198, 40 + 40 * (print_l ++ ), "是啊是啊 战友们 随声附和  也有人 鼓励科舍尔和 奥托 说他们 以后肯定能 开上四号坦克");
			supportDC.TextOutA(198, 40 + 40 * (print_l ++ ), "大撤退城战役虽然 以我军获胜 但我军由于突进过快 补给跟不上 所以也不敢贸然追击 就在这千钧一发的时刻");
			supportDC.TextOutA(198, 40 + 40 * (print_l ++ ), "联萌军 将领 亚历山大 急中生智 想到了一套 微波烤炉方案 动员了 一切 我一定会回来共和国 和 嘤嘤怪帝国在大撤退市附近的船只");
			supportDC.TextOutA(198, 40 + 40 * (print_l ++ ), "将 剩下的 15万（事实三十万） 联萌军 成功撤退到了 嘤嘤怪帝国本土 大嘤嘤怪岛 此举为帝国留下了极大的隐患");
			supportDC.TextOutA(198, 40 + 40 * (print_l ++ ), "奥托和战友们刚扯完蛋 营长突然 宣布 单独召见 奥托 和 科舍尔");
			supportDC.TextOutA(198, 40 + 40 * (print_l ++ ), "见到营长后 平时 非常随和的营长一脸严肃 原来 占领 埃菲尔市 以后 皇帝考虑到 装甲兵在这次作战中 贡献极大");
			supportDC.TextOutA(198, 40 + 40 * (print_l ++ ), "于是 决定 亲自举行阅兵 让装甲部队 穿过 埃菲尔广场上 上古时期 我投降共和国前身 把你打投降帝国 皇帝为 自己获胜后凯旋 建造的");
			supportDC.TextOutA(198, 40 + 40 * (print_l ++ ), "只有别国军队才能在这儿凯旋 的 沦陷门  讽刺的是 皇帝 拿着破轮 并没有 在沦陷门 下 凯旋一次 然而 小胡子帝国及其前身却各有一次");
			supportDC.TextOutA(198, 40 + 40 * (print_l ++ ), "皇帝的走狗们 盖世太保 得到情报 有一批激进的埃菲尔市民 暗中勾结我一定会回来共和国余孽 准备利用坦克刺杀 阅兵中的皇帝");
			supportDC.TextOutA(198, 40 + 40 * (print_l ++ ), "皇帝 在 没建立 小胡子帝国时 就已经经历了 11次刺杀 但每次都 能安然无恙 简直有如神助 于是此次");
			supportDC.TextOutA(198, 40 + 40 * (print_l ++ ), "皇帝 决定 将计就计 乘坐一辆四号坦克参加阅兵 并故意大肆宣扬 以此 达到将叛军全部诱出并消灭的目的");
			supportDC.TextOutA(198, 40 + 40 * (print_l ++ ), "奥托 由于之前战绩优异 所以被选入护卫队 他们的任务是 保护皇帝 消灭叛军");
			supportDC.TextOutA(198, 40 + 40 * (print_l ++ ), "一本正经的说完这一切后 营长的表情突然变得轻松下来 他说 别紧张 你一定能做好 不会出差错的");
			print_l;
			supportDC.TextOutA(198, 40 + 40 * (print_l ++ ), "第十二关 护驾");
			supportDC.TextOutA(198, 40 + 40 * (print_l ++ ), "胜利条件 和友军 配合 歼灭所有来犯之敌 为了不使游戏过于艰难 这一关你将有15000生命的buff ");
			supportDC.TextOutA(198, 40 + 40 * (print_l ++ ), "失败条件 玩家坦克被摧毁 或者 皇帝乘坐的坦克被摧毁");
			supportDC.TextOutA(198, 40 + 40 * (print_l ++ ), "本关提示 适当调整走位 让卫队的坦克盖住皇帝 卫队的走位判定是不能离开超过你得一定距离");
			supportDC.TextOutA(198, 40 + 40 * (print_l ++ ), "本关提示2 高难度下 紧靠自身坦克根本扛不住刺客的火力 皇帝的坦克毕竟是 特质的 非常能抗 可以利用皇帝的坦克牵制刺客的正面");



			print_l = 1;
			supportDC.SetTextColor(RGB(255, 255, 255));
			supportDC.TextOutA(200, 40 + 40 * (print_l ++ ), "剧情概述：不得不说科舍尔是真的能扯 而且还很会扯 他足足扯了三个小时 更奇怪的是 围过来听他讲的人越来越多而且还有人补充");
			supportDC.TextOutA(200, 40 + 40 * (print_l ++ ), "当 科舍尔讲到 蒙哥马利 用 切屌威胁 属下时 大家笑得前仰后合 同时也有不少人暗暗赞叹蒙哥马利的智慧");;
			supportDC.TextOutA(200, 40 + 40 * (print_l ++ ), "之后就是 科舍尔 开始 讲述 他们守城是如何困难 敌军是如何多 如何疯狂 ....大家听得不亦乐乎 尤其是和科舍尔一起行动的战友们");
			supportDC.TextOutA(200, 40 + 40 * (print_l ++ ), "真的是 好险 我的车被打中了6发 引擎 和 履带都坏了 城防也被撕开一个大口子.....他继续讲");
			supportDC.TextOutA(200, 40 + 40 * (print_l ++ ), "不过这是 友军 突然赶到了 不得不说 四号坦克真的比 我们开的二号坦克性能好多了 他们如砍瓜切菜一样 料理掉了敌军");
			supportDC.TextOutA(200, 40 + 40 * (print_l ++ ), "是啊是啊 战友们 随声附和  也有人 鼓励科舍尔和 奥托 说他们 以后肯定能 开上四号坦克");
			supportDC.TextOutA(200, 40 + 40 * (print_l ++ ), "大撤退城战役虽然 以我军获胜 但我军由于突进过快 补给跟不上 所以也不敢贸然追击 就在这千钧一发的时刻");
			supportDC.TextOutA(200, 40 + 40 * (print_l ++ ), "联萌军 将领 亚历山大 急中生智 想到了一套 微波烤炉方案 动员了 一切 我一定会回来共和国 和 嘤嘤怪帝国在大撤退市附近的船只");
			supportDC.TextOutA(200, 40 + 40 * (print_l ++ ), "将 剩下的 15万（事实三十万） 联萌军 成功撤退到了 嘤嘤怪帝国本土 大嘤嘤怪岛 此举为帝国留下了极大的隐患");
			supportDC.TextOutA(200, 40 + 40 * (print_l ++ ), "奥托和战友们刚扯完蛋 营长突然 宣布 单独召见 奥托 和 科舍尔");
			supportDC.TextOutA(200, 40 + 40 * (print_l ++ ), "见到营长后 平时 非常随和的营长一脸严肃 原来 占领 埃菲尔市 以后 皇帝考虑到 装甲兵在这次作战中 贡献极大");
			supportDC.TextOutA(200, 40 + 40 * (print_l ++ ), "于是 决定 亲自举行阅兵 让装甲部队 穿过 埃菲尔广场上 上古时期 我投降共和国前身 把你打投降帝国 皇帝为 自己获胜后凯旋 建造的");
			supportDC.TextOutA(200, 40 + 40 * (print_l ++ ), "只有别国军队才能在这儿凯旋 的 沦陷门  讽刺的是 皇帝 拿着破轮 并没有 在沦陷门 下 凯旋一次 然而 小胡子帝国及其前身却各有一次");
			supportDC.TextOutA(200, 40 + 40 * (print_l ++ ), "皇帝的走狗们 盖世太保 得到情报 有一批激进的埃菲尔市民 暗中勾结我一定会回来共和国余孽 准备利用坦克刺杀 阅兵中的皇帝");
			supportDC.TextOutA(200, 40 + 40 * (print_l ++ ), "皇帝 在 没建立 小胡子帝国时 就已经经历了 11次刺杀 但每次都 能安然无恙 简直有如神助 于是此次");
			supportDC.TextOutA(200, 40 + 40 * (print_l ++ ), "皇帝 决定 将计就计 乘坐一辆四号坦克参加阅兵 并故意大肆宣扬 以此 达到将叛军全部诱出并消灭的目的");
			supportDC.TextOutA(200, 40 + 40 * (print_l ++ ), "奥托 由于之前战绩优异 所以被选入护卫队 他们的任务是 保护皇帝 消灭叛军");
			supportDC.TextOutA(200, 40 + 40 * (print_l ++ ), "一本正经的说完这一切后 营长的表情突然变得轻松下来 他说 别紧张 你一定能做好 不会出差错的");
			print_l;
			supportDC.TextOutA(200, 40 + 40 * (print_l ++ ), "第十二关 护驾");
			supportDC.TextOutA(200, 40 + 40 * (print_l ++ ), "胜利条件 和友军 配合 歼灭所有来犯之敌 为了不使游戏过于艰难 这一关你将有15000生命的buff ");
			supportDC.TextOutA(200, 40 + 40 * (print_l ++ ), "失败条件 玩家坦克被摧毁 或者 皇帝乘坐的坦克被摧毁");
			supportDC.TextOutA(200, 40 + 40 * (print_l ++ ), "本关提示 适当调整走位 让卫队的坦克盖住皇帝 卫队的走位判定是不能离开超过你得一定距离");
			supportDC.TextOutA(200, 40 + 40 * (print_l ++ ), "本关提示2 高难度下 紧靠自身坦克根本扛不住刺客的火力 皇帝的坦克毕竟是 特质的 非常能抗 可以利用皇帝的坦克牵制刺客的正面");
		}
		else if(current_stage == 13)
		{
			//supportDC.FillSolidRect(0, 0, DIALOG_WIDTH, DIALOG_WIDTH, RGB(240, 240, 240));
			supportDC.SelectObject(&f);
			int print_l = 1;
			int start_x = 178;
			supportDC.SetTextColor(RGB(0, 0, 0));
			supportDC.TextOutA(start_x, 40                     , "第四章 声震寰宇");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "剧情概述：刺杀者的人数和火力远比想象的强大很多 远远超出了 奥托他们的预料 卫队几乎全军覆没 奥托的坦克也挨了好几炮");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "眼看情况危急 奥托一行人 就要全军覆没了 这时 \"皇帝的坦克\" 突然 冲出来 大杀特杀 将 剩余的 暗杀者全部摧毁");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "这是怎么回事 奥托和 卫队残部 大惊 这时 坦克 的 顶盖 打开了 一面探出个脑袋来 奥托一看 居然是科舍尔");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "大家也不由吃了一惊 看着大家惊讶的表情 科舍尔 大笑起来  皇帝自然不会 亲身犯险 由于之前在大撤退城的防守经历");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "军方高层经过筛选 最终决定让我 驾驶皇帝的坦克 冒充皇帝 引诱叛军上钩  刚才 多谢众位的保护了  ");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "听到这里 方才吓得惊魂未定的 众人 大笑起来  你可真是个小机灵鬼  ...... 真是的 不早点出手 害我们差点被吓死");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "我投降共和国战役自此结束 由于在战斗中出色的表现 奥托 和 科舍尔 被授予 少尉军衔 分配到 不同部队任职");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "战役结束后 奥托他们回国休假 迎接他们 的是 潮水般的掌声 鲜花 和 赞叹 他们被当成英雄一样对待 ");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "随着列车 到站 许多士兵开始高呼 我活着回来了 另一些也高声庆祝 许多人都流下了激动的眼泪 一种 逃出生天 如释重负之感");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "奥托等人 在 亲朋好友的簇拥中 回到了自己的住所 这次战役的激烈程度 远超 希伯来战役 回到家后的几天 奥托没有去听音乐会和弹琴");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "而是整天 和 部队上的基友们 到酒吧狂欢 或者 去做一些非常剧烈（比如....）的运动......显然 这次战役给奥托留下了不少的压力");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "这次假期长达一年 狂欢了半个月后 奥托便 利用 战斗英雄的特权 去 日耳曼尼亚大学 旁听药理学 而 科舍尔则去一家坦克工厂打工");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "西元 1941年 5月初  也就是一年后 帝国的实力达到了巅峰： 卡利姆多东南部的 火药桶半岛 全境被 帝国控制");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "嘤嘤怪帝国在 面对 帝国的空中和海上封锁 毫无还手之力   不过此时 一个消息 让帝国的高层坐立不安起来");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "原来 吞并希伯来民主联邦之后 帝国已经 和 东部的巨熊帝国 接壤 双方 摩拳擦掌 只不过谁也不敢率先轻动");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "但此时 帝国高层得到密报 巨熊帝国 将在 7月中旬对帝国发起攻击 于是 帝国高层决定先下手位强");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "在6月22日 率先发起 代号为 废特劣大弟的行动： 帝国军将兵分三路 北方集团军群 挥师北进 前往广阔的冰原");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "攻击 重要工业城市城市 熊大格勒 中央集团军群 一路向东 攻击 首都 伏特加市  南方集团军群 向南进发 攻击索加高平原油田和");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "以当今巨熊帝国皇帝命名的城市 熊二格勒  奥托被分在了 中央集团军群麾下 科舍尔则在南方集团军群服役（这样你才能打两线的战役）");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "6月22日 清晨 4点左右 在 帝国空军的掩护下 三路帝国装甲集群 越过边界 向敌人发起了大规模的进攻");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "第十三关 攻其不备");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "大军迅速进攻 但是其实我们的坦克质量不如敌人 只能攻其不备 在敌人反应过来之前将其消灭");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "胜利条件 和友军配合 摧毁 所有敌军 失败条件 玩家坦克被摧毁 本关提示 尽快集中火力让敌人减员 这样在他们反应过来时就无力反击了");




			print_l = 1;
			start_x += 2;
			supportDC.SetTextColor(RGB(255, 255, 255));
			supportDC.TextOutA(start_x, 40                     , "第四章 声震寰宇");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "剧情概述：刺杀者的人数和火力远比想象的强大很多 远远超出了 奥托他们的预料 卫队几乎全军覆没 奥托的坦克也挨了好几炮");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "眼看情况危急 奥托一行人 就要全军覆没了 这时 \"皇帝的坦克\" 突然 冲出来 大杀特杀 将 剩余的 暗杀者全部摧毁");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "这是怎么回事 奥托和 卫队残部 大惊 这时 坦克 的 顶盖 打开了 一面探出个脑袋来 奥托一看 居然是科舍尔");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "大家也不由吃了一惊 看着大家惊讶的表情 科舍尔 大笑起来  皇帝自然不会 亲身犯险 由于之前在大撤退城的防守经历");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "军方高层经过筛选 最终决定让我 驾驶皇帝的坦克 冒充皇帝 引诱叛军上钩  刚才 多谢众位的保护了  ");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "听到这里 方才吓得惊魂未定的 众人 大笑起来  你可真是个小机灵鬼  ...... 真是的 不早点出手 害我们差点被吓死");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "我投降共和国战役自此结束 由于在战斗中出色的表现 奥托 和 科舍尔 被授予 少尉军衔 分配到 不同部队任职");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "战役结束后 奥托他们回国休假 迎接他们 的是 潮水般的掌声 鲜花 和 赞叹 他们被当成英雄一样对待 ");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "随着列车 到站 许多士兵开始高呼 我活着回来了 另一些也高声庆祝 许多人都流下了激动的眼泪 一种 逃出生天 如释重负之感");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "奥托等人 在 亲朋好友的簇拥中 回到了自己的住所 这次战役的激烈程度 远超 希伯来战役 回到家后的几天 奥托没有去听音乐会和弹琴");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "而是整天 和 部队上的基友们 到酒吧狂欢 或者 去做一些非常剧烈（比如....）的运动......显然 这次战役给奥托留下了不少的压力");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "这次假期长达一年 狂欢了半个月后 奥托便 利用 战斗英雄的特权 去 日耳曼尼亚大学 旁听药理学 而 科舍尔则去一家坦克工厂打工");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "西元 1941年 5月初  也就是一年后 帝国的实力达到了巅峰： 卡利姆多东南部的 火药桶半岛 全境被 帝国控制");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "嘤嘤怪帝国在 面对 帝国的空中和海上封锁 毫无还手之力   不过此时 一个消息 让帝国的高层坐立不安起来");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "原来 吞并希伯来民主联邦之后 帝国已经 和 东部的巨熊帝国 接壤 双方 摩拳擦掌 只不过谁也不敢率先轻动");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "但此时 帝国高层得到密报 巨熊帝国 将在 7月中旬对帝国发起攻击 于是 帝国高层决定先下手位强");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "在6月22日 率先发起 代号为 废特劣大弟的行动： 帝国军将兵分三路 北方集团军群 挥师北进 前往广阔的冰原");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "攻击 重要工业城市城市 熊大格勒 中央集团军群 一路向东 攻击 首都 伏特加市  南方集团军群 向南进发 攻击索加高平原油田和");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "以当今巨熊帝国皇帝命名的城市 熊二格勒  奥托被分在了 中央集团军群麾下 科舍尔则在南方集团军群服役（这样你才能打两线的战役）");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "6月22日 清晨 4点左右 在 帝国空军的掩护下 三路帝国装甲集群 越过边界 向敌人发起了大规模的进攻");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "第十三关 攻其不备");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "大军迅速进攻 但是其实我们的坦克质量不如敌人 只能攻其不备 在敌人反应过来之前将其消灭");
			supportDC.TextOutA(start_x, 40 + 40 * (print_l ++ ), "胜利条件 和友军配合 摧毁 所有敌军 失败条件 玩家坦克被摧毁 本关提示 尽快集中火力让敌人减员 这样在他们反应过来时就无力反击了");
		}
		else if(current_stage == 14)
		{
			//supportDC.FillSolidRect(0, 0, DIALOG_WIDTH, DIALOG_WIDTH, RGB(240, 240, 240));
			supportDC.SelectObject(&f);
			int print_l = 1;
			int start_x = 478;
			supportDC.SetTextColor(RGB(0, 0, 0));
			supportDC.TextOutA(start_x, 300                     , "第十四关 遭遇强敌");
			supportDC.TextOutA(start_x, 300 + 40 * (print_l ++ ), "起初的几天 进攻十分顺利 帝国成功的控制了巨熊帝国边界大量领土");
			supportDC.TextOutA(start_x, 300 + 40 * (print_l ++ ), "但是好景不长 敌人便回过神来了 这一天 卡尔乌斯和他的队友们在进攻中遇到了三辆从未谋面的坦克");
			supportDC.TextOutA(start_x, 300 + 40 * (print_l ++ ), "卡尔乌斯的队友向它射击 但是炮弹反弹了回来 但对方向我方的射击却几乎招招致命");
			supportDC.TextOutA(start_x, 300 + 40 * (print_l ++ ), "眼看 己方损失惨重 对方却毫发无伤 卡尔乌斯决定贴近距离 绕到对方后面干掉他们");
			supportDC.TextOutA(start_x, 300 + 40 * (print_l ++ ), "胜利条件 消灭所有敌军坦克");
			supportDC.TextOutA(start_x, 300 + 40 * (print_l ++ ), "失败条件 玩家坦克被摧毁 或者 损失超过一定数量的友军");
			supportDC.TextOutA(start_x, 300 + 40 * (print_l ++ ), "本关提示： 利用队友牵制敌方的正面 然后 进行绕侧攻击 注意合理使用小队指令 还有 敌人的装甲很厚");




			print_l = 1;
			start_x += 2;
			supportDC.SetTextColor(RGB(255, 255, 255));
			supportDC.TextOutA(start_x, 300                     , "第十四关 遭遇强敌");
			supportDC.TextOutA(start_x, 300 + 40 * (print_l ++ ), "起初的几天 进攻十分顺利 帝国成功的控制了巨熊帝国边界大量领土");
			supportDC.TextOutA(start_x, 300 + 40 * (print_l ++ ), "但是好景不长 敌人便回过神来了 这一天 卡尔乌斯和他的队友们在进攻中遇到了三辆从未谋面的坦克");
			supportDC.TextOutA(start_x, 300 + 40 * (print_l ++ ), "卡尔乌斯的队友向它射击 但是炮弹反弹了回来 但对方向我方的射击却几乎招招致命");
			supportDC.TextOutA(start_x, 300 + 40 * (print_l ++ ), "眼看 己方损失惨重 对方却毫发无伤 卡尔乌斯决定贴近距离 绕到对方后面干掉他们");
			supportDC.TextOutA(start_x, 300 + 40 * (print_l ++ ), "胜利条件 消灭所有敌军坦克");
			supportDC.TextOutA(start_x, 300 + 40 * (print_l ++ ), "失败条件 玩家坦克被摧毁 或者 损失超过一定数量的友军");
			supportDC.TextOutA(start_x, 300 + 40 * (print_l ++ ), "本关提示： 利用队友牵制敌方的正面 然后 进行绕侧攻击 注意合理使用小队指令 还有 敌人的装甲很厚");
		}
		else if(current_stage == 15)
		{
			supportDC.SelectObject(&f);
			int print_l = 1;
			int start_x = 478;
			supportDC.SetTextColor(RGB(0, 0, 0));
			supportDC.TextOutA(start_x, 300                     , "第十五关 大会战");
			supportDC.TextOutA(start_x, 300 + 40 * (print_l ++ ), "奥托和他指挥的小队靠着队友的掩护 成功切到了对方的背面 然后 摧毁了敌人");
			supportDC.TextOutA(start_x, 300 + 40 * (print_l ++ ), "不过奥托一行人还是损失了很多坦克 于是最高指挥部决定使用装甲改良后的坦克");
			supportDC.TextOutA(start_x, 300 + 40 * (print_l ++ ), "现在你的正面装甲和侧面装甲更好了 但是其实用处不大 得到装备更新后 ");
			supportDC.TextOutA(start_x, 300 + 40 * (print_l ++ ), "奥托一行人 继续向东前进 前方出现了一个庞大的装甲集群 看来又是一场硬仗了！");
			supportDC.TextOutA(start_x, 300 + 40 * (print_l ++ ), "胜利条件 消灭所有敌军坦克");
			supportDC.TextOutA(start_x, 300 + 40 * (print_l ++ ), "失败条件 玩家坦克被摧毁");
			supportDC.TextOutA(start_x, 300 + 40 * (print_l ++ ), "本关提示： 为了维护玩家体验 这一关所有NPC的射速都很低");

			print_l = 1;
			start_x += 2;
			supportDC.SetTextColor(RGB(255, 255, 255));
			supportDC.TextOutA(start_x, 300                     , "第十五关 大会战");
			supportDC.TextOutA(start_x, 300 + 40 * (print_l ++ ), "奥托和他指挥的小队靠着队友的掩护 成功切到了对方的背面 然后 摧毁了敌人");
			supportDC.TextOutA(start_x, 300 + 40 * (print_l ++ ), "不过奥托一行人还是损失了很多坦克 于是最高指挥部决定使用装甲改良后的坦克");
			supportDC.TextOutA(start_x, 300 + 40 * (print_l ++ ), "现在你的正面装甲和侧面装甲更好了 但是其实用处不大 得到装备更新后 ");
			supportDC.TextOutA(start_x, 300 + 40 * (print_l ++ ), "奥托一行人 继续向东前进 前方出现了一个庞大的装甲集群 看来又是一场硬仗了！");
			supportDC.TextOutA(start_x, 300 + 40 * (print_l ++ ), "胜利条件 消灭所有敌军坦克");
			supportDC.TextOutA(start_x, 300 + 40 * (print_l ++ ), "失败条件 玩家坦克被摧毁");
			supportDC.TextOutA(start_x, 300 + 40 * (print_l ++ ), "本关提示： 为了维护玩家体验 这一关所有NPC的射速都很低");
		}
		else if(current_stage == 16)
		{
			supportDC.SelectObject(&f);
			int print_l = 1;
			int start_x = 478;
			supportDC.SetTextColor(RGB(0, 0, 0));
			supportDC.TextOutA(start_x, 300                     , "第十六关 单车闯关");
			supportDC.TextOutA(start_x, 300 + 40 * (print_l ++ ), "会战中 双方均损失惨重 更糟糕的是 奥托和队友们 走散了 当他发现自己走散时");
			supportDC.TextOutA(start_x, 300 + 40 * (print_l ++ ), "他发现周围有巨熊开始围观他  真糟糕 奥托 心想 算了 先尽力突围吧");
			supportDC.TextOutA(start_x, 300 + 40 * (print_l ++ ), "本关中 你将没有任何队友和小队成员支援 你需要独自一人消灭若干敌军 ");
			supportDC.TextOutA(start_x, 300 + 40 * (print_l ++ ), "有意思的是 这是本游戏真正意义上的第一关单挑");
			supportDC.TextOutA(start_x, 300 + 40 * (print_l ++ ), "胜利条件 消灭所有敌军坦克");
			supportDC.TextOutA(start_x, 300 + 40 * (print_l ++ ), "失败条件 玩家坦克被摧毁");
			supportDC.TextOutA(start_x, 300 + 40 * (print_l ++ ), "本关提示: 敌人的出生位置是固定的 困难难度下 难度非常高");

			print_l = 1;
			start_x += 2;
			supportDC.SetTextColor(RGB(255, 255, 255));
			supportDC.TextOutA(start_x, 300                     , "第十六关 单车闯关");
			supportDC.TextOutA(start_x, 300 + 40 * (print_l ++ ), "会战中 双方均损失惨重 更糟糕的是 奥托和队友们 走散了 当他发现自己走散时");
			supportDC.TextOutA(start_x, 300 + 40 * (print_l ++ ), "他发现周围有巨熊开始围观他  真糟糕 奥托 心想 算了 先尽力突围吧");
			supportDC.TextOutA(start_x, 300 + 40 * (print_l ++ ), "本关中 你将没有任何队友和小队成员支援 你需要独自一人消灭若干敌军 ");
			supportDC.TextOutA(start_x, 300 + 40 * (print_l ++ ), "有意思的是 这是本游戏真正意义上的第一关单挑");
			supportDC.TextOutA(start_x, 300 + 40 * (print_l ++ ), "胜利条件 消灭所有敌军坦克");
			supportDC.TextOutA(start_x, 300 + 40 * (print_l ++ ), "失败条件 玩家坦克被摧毁");
			supportDC.TextOutA(start_x, 300 + 40 * (print_l ++ ), "本关提示: 敌人的出生位置是固定的 困难难度下 难度非常高");
		}

		//羊皮纸风格
		pictureDC.SelectObject(&prepare_bk);
		BLENDFUNCTION blendFunction;
		memset( &blendFunction, 0, sizeof(blendFunction) );
		blendFunction.BlendOp = AC_SRC_OVER;
		blendFunction.BlendFlags = 0;
		blendFunction.SourceConstantAlpha = 100;

		supportDC.AlphaBlend(0, 0, 1900, 1040, &pictureDC, 0, 0, 1900, 1000, blendFunction);

#ifdef LOW_DENSITY
		pDC->StretchBlt(0, 0, 1267, 693, &supportDC, 0, 0, 1900, 1040, SRCCOPY);
#else
		pDC->BitBlt(0, 0, DIALOG_WIDTH, DIALOG_HEIGHT, &supportDC, 0, 0, SRCCOPY);
#endif


		memDC.SelectObject(fdmg);
		memDC2.SetBkMode(TRANSPARENT);
		memDC2.SelectObject(&f);
	}
}
//1468行
