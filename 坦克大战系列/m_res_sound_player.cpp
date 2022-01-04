#include "stdafx.h"
#include "my_resource.h"

//击中 和 开火 音效 播报器 
void my_sound_player(Sounds sd)
{
	clock_t current = clock();
	//正面击中 （未击穿音效）
	if(sd == FRONT_HIT_SOUND)
	{
		static clock_t last_cast = - 9999;
		if(current - last_cast >= 100)
		{
			::mciSendString("close hit", NULL, 0, NULL);
			::mciSendString("open hit.mp3 alias hit", NULL, 0, NULL); 
 			::mciSendString("play hit", NULL, 0, NULL);
			CString cmd;
			cmd.Format("setaudio hit volume to 500");
			::mciSendString(cmd,"",0,NULL);
			last_cast = current;
		}

	
	}
	//侧面击中  （击穿音效）
	else if(sd == SIDE_HIT_SOUND)
	{
		static clock_t last_cast = - 9999;
		if(current - last_cast >= 100)
		{
			::mciSendString("close more_hit", NULL, 0, NULL);
			::mciSendString("open more_hit.mp3 alias more_hit", NULL, 0, NULL); 
 			::mciSendString("play more_hit", NULL, 0, NULL);
			CString cmd;
			cmd.Format("setaudio more_hit volume to 500");
			::mciSendString(cmd,"",0,NULL);
			last_cast = current;
		}

	}
	//背面击中   （击穿音效）
	else if(sd == BEHIND_HIT_SOUND)
	{
		static clock_t last_cast = - 9999;
		if(current - last_cast >= 100)
		{
			::mciSendString("close fital_hit", NULL, 0, NULL);
			::mciSendString("open fital_hit.mp3 alias fital_hit", NULL, 0, NULL); //打开 文件123.mp3  并取别名 start
 			::mciSendString("play fital_hit", NULL, 0, NULL);
			last_cast = current;
		}
	}
	//开火音效
	else if(sd == FIRE_SOUND)
	{
		::mciSendString("close fire", NULL, 0, NULL);
		::mciSendString("open fire.mp3 alias fire", NULL, 0, NULL); //打开 文件123.mp3  并取别名 start
 		::mciSendString("play fire", NULL, 0, NULL);

		CString cmd;
		cmd.Format("setaudio fire volume to 500");
		::mciSendString(cmd,"",0,NULL);
	}
	else if(sd == EXPLOSE_SOUND)
	{
		::mciSendString("close explose", NULL, 0, NULL);
		::mciSendString("open explose.mp3 alias explose", NULL, 0, NULL); //打开 文件123.mp3  并取别名 start
 		::mciSendString("play explose", NULL, 0, NULL);

		CString cmd;
		cmd.Format("setaudio explose volume to 500");
		::mciSendString(cmd,"",0,NULL);
	}
}


//连杀播报
void kill_stack_broadcast_player(BoardCast bc)
{
	static clock_t last_cast = - 9999;
	clock_t current = clock();
	if(current - last_cast >= 1600)
	{
		int rd = rand()%3;
		if(0 == rd)
		{
			::mciSendString("close kill", NULL, 0, NULL);
			::mciSendString("open  kill1.mp3 alias kill", NULL, 0, NULL); //打开 文件123.mp3  并取别名 start
 			::mciSendString("play kill", NULL, 0, NULL);

		}
		else if(1 == rd)
		{
			::mciSendString("close kill", NULL, 0, NULL);
			::mciSendString("open  kill2.mp3 alias kill", NULL, 0, NULL); //打开 文件123.mp3  并取别名 start
 			::mciSendString("play kill", NULL, 0, NULL);
		}
		else
		{
			::mciSendString("close kill", NULL, 0, NULL);
			::mciSendString("open  kill3.mp3 alias kill", NULL, 0, NULL); //打开 文件123.mp3  并取别名 start
 			::mciSendString("play kill", NULL, 0, NULL);
		}
		last_cast = current;
	}
	/*
	if(bc == KILL && current - last_cast >= 1600)
	{
		::mciSendString("close kill", NULL, 0, NULL);
		::mciSendString("open 一杀.mp3 alias kill", NULL, 0, NULL); //打开 文件123.mp3  并取别名 start
 		::mciSendString("play kill", NULL, 0, NULL);
		last_cast = current;
	}
	else if(bc == DOUBLE_KILL && current - last_cast >= 2100)
	{
		::mciSendString("close kill", NULL, 0, NULL);
		::mciSendString("open 两杀.mp3 alias kill", NULL, 0, NULL); //打开 文件123.mp3  并取别名 start
 		::mciSendString("play kill", NULL, 0, NULL);
		last_cast = current;

	}
	else if(bc == KILLING_SPREE && current - last_cast >= 2100)
	{
		::mciSendString("close kill", NULL, 0, NULL);
		::mciSendString("open 三杀.mp3 alias kill", NULL, 0, NULL); //打开 文件123.mp3  并取别名 start
 		::mciSendString("play kill", NULL, 0, NULL);
		last_cast = current;
	}
	else if(bc == RUNPAGE && current - last_cast >= 2100)
	{
		::mciSendString("close kill", NULL, 0, NULL);
		::mciSendString("open 四杀.mp3 alias kill", NULL, 0, NULL); //打开 文件123.mp3  并取别名 start
 		::mciSendString("play kill", NULL, 0, NULL);
		last_cast = current;
	}
	else if(bc == UNSTOPPABLE && current - last_cast >= 2100)
	{
		::mciSendString("close kill", NULL, 0, NULL);
		::mciSendString("open 五杀.mp3 alias kill", NULL, 0, NULL); //打开 文件123.mp3  并取别名 start
 		::mciSendString("play kill", NULL, 0, NULL);
		last_cast = current;
	}
	else if(bc == DOMINATING && current - last_cast >= 2100)
	{
		::mciSendString("close kill", NULL, 0, NULL);
		::mciSendString("open 六杀.mp3 alias kill", NULL, 0, NULL); //打开 文件123.mp3  并取别名 start
 		::mciSendString("play kill", NULL, 0, NULL);
		last_cast = current;
	}
	else if(bc == GOD_LIKE && current - last_cast >= 2100)
	{
		::mciSendString("close kill", NULL, 0, NULL);
		::mciSendString("open 七杀.mp3 alias kill", NULL, 0, NULL); //打开 文件123.mp3  并取别名 start
 		::mciSendString("play kill", NULL, 0, NULL);
		last_cast = current;
	}
	else if(bc == LEGENDARY && current - last_cast >= 2100)
	{
		::mciSendString("close kill", NULL, 0, NULL);
		::mciSendString("open 八杀及以上.mp3 alias kill", NULL, 0, NULL); //打开 文件123.mp3  并取别名 start
 		::mciSendString("play kill", NULL, 0, NULL);
		last_cast = current;
	}
	*/

}

//战斗音乐播放器
void battle_bgm_player(int stage)
{
	//关闭后区间音乐
	::mciSendString("close interval ", NULL, 0, NULL);


	//经典90开场音效
	::mciSendString("open bgm.mp3 alias bgm", NULL, 0, NULL); //打开 文件123.mp3  并取别名 start
 	::mciSendString("play bgm", NULL, 0, NULL);

	//隐藏关 惧之魇  
	//气氛  恐怖 未知  紧张  背景音乐   雷霆虚空   骆集益
	if(stage == -1)
	{
		::mciSendString("open bgm_nightmare.mp3 alias bgm2", NULL, 0, NULL); //打开 文件123.mp3  并取别名 start
		::mciSendString("play bgm2 repeat", NULL, 0, NULL);
	}

	//第4关 秋风扫落叶
	//第12关  护驾行动
	//气氛  霸气  势不可挡  背景音乐  hellmarch3   freknlin....westwood作曲家
	else if(stage == 4 || stage == 12)
	{
		::mciSendString("open bgm_cg.mp3 alias bgm2", NULL, 0, NULL); //打开 文件123.mp3  并取别名 start
		::mciSendString("play bgm2 repeat", NULL, 0, NULL);
	}
	//  mysongknowwhatyoudidinthedark -- 中等激烈战斗
	else if(stage == 1 || stage == 11 || stage == 5)
	{
		::mciSendString("open begin.mp3 alias bgm2", NULL, 0, NULL); //打开 文件123.mp3  并取别名 start
		::mciSendString("play bgm2 repeat", NULL, 0, NULL);
	}
	//  面对挑战 和 困难  的跃跃欲试 与 紧张感   临危变调1   曾志豪  
	else if(stage == 2 || stage == 3)
	{
		::mciSendString("open bgm_dagerous1.mp3 alias bgm2", NULL, 0, NULL); //打开 文件123.mp3  并取别名 start
		::mciSendString("play bgm2 repeat", NULL, 0, NULL);
	}
	//  一气呵成 但 略显紧张的战斗  UltimateBattle
	else if(stage == 6)
	{
		::mciSendString("open bgm2.mp3 alias bgm2", NULL, 0, NULL); //打开 文件123.mp3  并取别名 start
		::mciSendString("play bgm2 repeat", NULL, 0, NULL);
	}
	//  鏖战1     金戈铁马    卢晓旭
	else if(stage == 7)
	{
		//AfxMessageBox("本关还在编写之中 请等待更新");
		::mciSendString("open bgm_grand_fight.mp3 alias bgm2", NULL, 0, NULL); //打开 文件123.mp3  并取别名 start
		::mciSendString("play bgm2 repeat", NULL, 0, NULL);
	}
	//  豪迈 洒脱 自信 快节奏的战斗音乐    势如劈竹   卢晓旭
	else if(stage == 8 || stage == 9)
	{
		::mciSendString("open bgm_tendency2.mp3 alias bgm2", NULL, 0, NULL); //打开 文件123.mp3  并取别名 start
		::mciSendString("play bgm2 repeat", NULL, 0, NULL);

	}
	//  鏖战2    浣花洗剑 变调   周志华
	else if(stage == 10 || stage == 14)
	{
		::mciSendString("open bgm_attack1.mp3 alias bgm2", NULL, 0, NULL); //打开 文件123.mp3  并取别名 start
		::mciSendString("play bgm2 repeat", NULL, 0, NULL);

	}
	//  冲锋和 突袭 的紧张感   破阵乐  周志华
	else if(stage == 13 || stage == 15)
	{
		::mciSendString("open bgm_attack2.mp3 alias bgm2", NULL, 0, NULL); //打开 文件123.mp3  并取别名 start
		::mciSendString("play bgm2 repeat", NULL, 0, NULL);

	}
	// 紧张的局势 剑影残心 周志华
	else if(stage == 16)	
	{
		::mciSendString("open bgm_battle_3.mp3 alias bgm2", NULL, 0, NULL); //打开 文件123.mp3  并取别名 start
		::mciSendString("play bgm2 repeat", NULL, 0, NULL);
	}

	
	else if(stage == 100 || stage == 101) 
	{
		::mciSendString("open cg_bgm.mp3 alias bgm2", NULL, 0, NULL); //打开 文件123.mp3  并取别名 start
		::mciSendString("play bgm2 repeat", NULL, 0, NULL);
	}

	CString cmd;
	cmd.Format("setaudio bgm2 volume to 300");
	::mciSendString(cmd,"",0,NULL);
}

//准备阶段音乐播放器
void prepartion_bgm_player(int stage)
{
	::mciSendString("close bgm2 ", NULL, 0, NULL);
	::mciSendString("close bgm ", NULL, 0, NULL);
	::mciSendString("close interval", NULL, 0, NULL);
	
		//::mciSendString("close interval", NULL, 0, NULL);
	if(stage == 1)
	{
		//开头音乐
		::mciSendString("open start.mp3 alias interval", NULL, 0, NULL); //打开 文件123.mp3  并取别名 start
		::mciSendString("play interval repeat", NULL, 0, NULL);
	}

	if(stage == -1)
	{
		::mciSendString("open interval_nightmare.mp3 alias interval", NULL, 0, NULL); //打开 文件123.mp3  并取别名 start
		::mciSendString("play interval repeat", NULL, 0, NULL);
	}

	else if(stage <= 3)
	{
		::mciSendString("open interval5.mp3 alias interval", NULL, 0, NULL); //打开 文件123.mp3  并取别名 start
		::mciSendString("play interval repeat", NULL, 0, NULL);
	}
	else if(stage <= 7)
	{
		::mciSendString("open interval3.mp3 alias interval", NULL, 0, NULL); //打开 文件123.mp3  并取别名 start
		::mciSendString("play interval repeat", NULL, 0, NULL);
	}
	else if(stage <= 12)
	{
		::mciSendString("open interval4.mp3 alias interval", NULL, 0, NULL);
		::mciSendString("play interval repeat", NULL, 0, NULL);
	}
	else if(stage < 30 || stage == 100 || stage == 101)
	{
		::mciSendString("open interval2.mp3 alias interval", NULL, 0, NULL);
		::mciSendString("play interval repeat", NULL, 0, NULL);
	}

	/*
	else
	{
		::mciSendString("open interval6.mp3 alias interval", NULL, 0, NULL);
		::mciSendString("play interval repeat", NULL, 0, NULL);
	}*/

}

//战斗完成阶段音乐播放器
void after_bgm_player(int stage)
{
	::mciSendString("close bgm ", NULL, 0, NULL);
	::mciSendString("close bgm2 ", NULL, 0, NULL);
	if(stage != -1)
	{
		::mciSendString("open interval.mp3 alias interval", NULL, 0, NULL);
		::mciSendString("play interval repeat", NULL, 0, NULL);
	}
	else
	{
		::mciSendString("open bgm_start2.mp3 alias interval", NULL, 0, NULL);
		::mciSendString("play interval repeat", NULL, 0, NULL);
	}
}
//251

//损害汇报
void damage_report(DamageReport infor)
{
	//因为很久报一次所以不需要时间限制
	if( ENGINE_DAMAGED == infor)
	{
		::mciSendString("close ed", NULL, 0, NULL);
		::mciSendString("open engine_damaged.mp3 alias ed", NULL, 0, NULL); //打开 文件123.mp3  并取别名 start
 		::mciSendString("play ed", NULL, 0, NULL);
	}
	else if(ENGINE_REPAIRED == infor)
	{
		::mciSendString("close er", NULL, 0, NULL);
		::mciSendString("open engine_fixed.mp3 alias er", NULL, 0, NULL); //打开 文件123.mp3  并取别名 start
 		::mciSendString("play er", NULL, 0, NULL);
	}
	else if(GUN_DAMAGED == infor)
	{
		::mciSendString("close gd", NULL, 0, NULL);
		::mciSendString("open gun_damaged.mp3 alias gd", NULL, 0, NULL); //打开 文件123.mp3  并取别名 start
 		::mciSendString("play gd", NULL, 0, NULL);
	}
	else if(GUN_REPAIRED == infor)
	{
		::mciSendString("close gr", NULL, 0, NULL);
		::mciSendString("open gun_fixed.mp3 alias gr", NULL, 0, NULL); //打开 文件123.mp3  并取别名 start
 		::mciSendString("play gr", NULL, 0, NULL);
	}
}