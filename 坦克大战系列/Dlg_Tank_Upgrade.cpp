#include "stdafx.h"
#include "坦克大战系列Dlg.h"

void C坦克大战系列Dlg::Tank_Auto_Upgrade_By_Stage(int stage)
{
	//强化
	if(current_stage == 1)
	{
		tank1.init_max_speed += 2;
		//max_speed_prove += 1;
		tank1.fastest_fire_interval -= 50;
		tank1.fire_interval -= 50;
		//fire_interval_prove += 1;


		if(2 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 600;
			tank1.current_max_hitpoint += 600;
			tank1.current_hitpoint += 600;
		}
		else if(1 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 1250;
			tank1.current_max_hitpoint += 1250;
			tank1.current_hitpoint += 1250;
		}
		else if(0 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 2000;
			tank1.current_max_hitpoint += 2000;
			tank1.current_hitpoint += 2000;
		}
	}
	else if(current_stage == 2)
	{
		tank1.fastest_fire_interval -= 50;
		tank1.fire_interval -= 50;
		//fire_interval_prove += 1;

		if(2 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 700;
			tank1.current_max_hitpoint += 700;
			tank1.current_hitpoint += 700;
			tank1.max_damage +=  125;
			tank1.damage += 125;
		}
		else if(1 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 1350;
			tank1.current_max_hitpoint += 1350;
			tank1.current_hitpoint += 1050;
			tank1.max_damage +=  145;
			tank1.damage += 145;
		}
		else if(0 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 1800;
			tank1.current_max_hitpoint += 1800;
			tank1.current_hitpoint += 1800;
			tank1.max_damage +=  165;
			tank1.damage += 165;
		}

	

	}
	else if(current_stage == 3)
	{
		tank1.init_accelerate_power += 1;
		tank1.Accelerate_Power += 1;
		Player_Tank::upgrade_gun = 1;

		if(2 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 750;
			tank1.current_max_hitpoint += 750;
			tank1.current_hitpoint += 750;
			tank1.max_damage +=  95;
			tank1.damage += 95;
		}
		else if(1 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 1300;
			tank1.current_max_hitpoint += 1300;
			tank1.current_hitpoint += 1300;
			tank1.max_damage +=  105;
			tank1.damage += 105;
		}
		else if(0 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 1770;
			tank1.current_max_hitpoint += 1770;
			tank1.current_hitpoint += 1770;
			tank1.max_damage +=  117;
			tank1.damage += 117;
		}

	}
	else if(current_stage == 4)
	{
		tank1.init_max_speed += 2;
		//max_speed_prove += 1;
		tank1.fastest_fire_interval -= 50;
		tank1.fire_interval -= 50;
		//fire_interval_prove += 1;

		if(2 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 800;
			tank1.current_max_hitpoint += 800;
			tank1.current_hitpoint += 800;
			tank1.max_damage +=  95;
			tank1.damage += 95;
		}
		else if(1 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 1450;
			tank1.current_max_hitpoint += 1450;
			tank1.current_hitpoint += 1450;
			tank1.max_damage +=  105;
			tank1.damage += 105;
		}
		else if(0 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 2000;
			tank1.current_max_hitpoint += 2000;
			tank1.current_hitpoint += 2000;
			tank1.max_damage +=  120;
			tank1.damage += 120;
		}
		tank1.fire_speed += 20;

	}
	else if(current_stage == 5)
	{
		if(2 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 1350;
			tank1.current_max_hitpoint += 1350;
			tank1.current_hitpoint += 1350;
			tank1.max_damage +=  125;
			tank1.damage += 125;
		}
		else if(1 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 1800;
			tank1.current_max_hitpoint += 1800;
			tank1.current_hitpoint += 1800;
			tank1.max_damage +=  155;
			tank1.damage += 155;
		}
		else if(0 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 2400;
			tank1.current_max_hitpoint += 2400;
			tank1.current_hitpoint += 2400;
			tank1.max_damage +=  195;
			tank1.damage += 195;
		}




		tank1.fire_speed += 10;
		tank1.engine_damage_rate -= 20;
		tank1.gun_damage_rate -= 5;

	}

	//攻克华沙以后 需要大幅度强化
	else if(current_stage == 6)
	{
		if(2 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 1550;
			tank1.current_max_hitpoint += 1550;
			tank1.current_hitpoint += 1550;
			tank1.max_damage +=  125;
			tank1.damage += 125;
		}
		else if(1 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 1900;
			tank1.current_max_hitpoint += 1900;
			tank1.current_hitpoint += 1900;
			tank1.max_damage +=  155;
			tank1.damage += 155;
		}
		else if(0 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 2300;
			tank1.current_max_hitpoint += 2300;
			tank1.current_hitpoint += 2300;
			tank1.max_damage +=  195;
			tank1.damage += 195;
		}
		tank1.init_accelerate_power += 1;
		tank1.init_max_speed += 1;

		tank1.engine_damage_rate -= 20;
		tank1.gun_damage_rate -= 5;
	}
	//遭遇巨熊 -- 第二章结束
	else if(current_stage == 7)
	{
		tank1.penertrate_level += 1;
		Player_Tank::upgrade_engine = 1;
		if(2 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 650;
			tank1.current_max_hitpoint += 650;
			tank1.current_hitpoint += 650;
			tank1.max_damage +=  65;
			tank1.damage += 65;
		}
		else if(1 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 1150;
			tank1.current_max_hitpoint += 1150;
			tank1.current_hitpoint += 1150;
			tank1.max_damage +=  85;
			tank1.damage += 85;
		}
		else if(0 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 1600;
			tank1.current_max_hitpoint += 1600;
			tank1.current_hitpoint += 1600;
			tank1.max_damage +=  100;
			tank1.damage += 100;
		}
		tank1.init_accelerate_power += 1;
		tank1.fire_speed += 15;

	}
	//第八关结束
	else if(current_stage == 8)
	{
		if(2 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 1150;
			tank1.current_max_hitpoint += 1150;
			tank1.current_hitpoint += 1150;
			tank1.max_damage +=  105;
			tank1.damage += 105;
		}
		else if(1 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 1600;
			tank1.current_max_hitpoint += 1600;
			tank1.current_hitpoint += 1600;
			tank1.max_damage +=  125;
			tank1.damage += 125;
		}
		else if(0 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 2100;
			tank1.current_max_hitpoint += 2100;
			tank1.current_hitpoint += 2100;
			tank1.max_damage +=  155;
			tank1.damage += 155;
		}
	}
	//第九关 结束 --- 攻克比利时
	else if(current_stage == 9)
	{
		if(2 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 950;
			tank1.current_max_hitpoint += 950;
			tank1.current_hitpoint += 950;
			tank1.max_damage +=  95;
			tank1.damage += 95;
		}
		else if(1 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 1600;
			tank1.current_max_hitpoint += 1600;
			tank1.current_hitpoint += 1600;
			tank1.max_damage +=  110;
			tank1.damage += 110;
		}
		else if(0 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 2450;
			tank1.current_max_hitpoint +=2450;
			tank1.current_hitpoint += 2450;
			tank1.max_damage +=  125;
			tank1.damage += 125;
		}
		tank1.fire_speed += 10;
	}
	//第十关 马奇诺防线
	else if(current_stage == 10)
	{
		if(2 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 1100;
			tank1.current_max_hitpoint += 1100;
			tank1.current_hitpoint += 1100;
			tank1.max_damage +=  155;
			tank1.damage += 155;
		}
		else if(1 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 1900;
			tank1.current_max_hitpoint += 1900;
			tank1.current_hitpoint += 1900;
			tank1.max_damage +=  180;
			tank1.damage += 180;
		}
		else if(0 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 3550;
			tank1.current_max_hitpoint +=3550;
			tank1.current_hitpoint += 3550;
			tank1.max_damage +=  220;
			tank1.damage += 220;
		}
		tank1.penertrate_level += 1;
	}
	//第十一关敦刻尔克攻防战 结束 -- 大幅增加伤害
	else if(current_stage == 11)
	{
		if(2 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 800;
			tank1.current_max_hitpoint += 800;
			tank1.current_hitpoint += 800;
			tank1.max_damage +=  180;
			tank1.damage += 180;
		}
		else if(1 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 1800;
			tank1.current_max_hitpoint += 1800;
			tank1.current_hitpoint += 1800;
			tank1.max_damage +=  220;
			tank1.damage += 220;
		}
		else if(0 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 3250;
			tank1.current_max_hitpoint += 3250;
			tank1.current_hitpoint += 3250;
			tank1.max_damage +=  275;
			tank1.damage += 275;
		}

		//临时加成
		tank1.max_hitpoint += 15000;
		tank1.current_max_hitpoint +=15000;
		tank1.current_hitpoint += 15000;
	}
	//第十二关 巴黎巡游结束 第三章结束
	else if(current_stage == 12)
	{
		Player_Tank::upgrade_command = 1;

		tank1.max_hitpoint -= 15000;
		tank1.current_max_hitpoint -=15000;

		tank1.init_max_speed += 1;

		if(tank1.current_max_hitpoint <= 0)
			tank1.current_max_hitpoint = 1;
		tank1.current_hitpoint -= 15000;
		if(tank1.current_hitpoint <= 0)
			tank1.current_hitpoint = 1;


		if(2 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 800;
			tank1.current_max_hitpoint += 800;
			tank1.current_hitpoint += 800;
			tank1.max_damage += 240;
			tank1.damage += 240;
		}
		else if(1 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 1600;
			tank1.current_max_hitpoint += 1600;
			tank1.current_hitpoint += 1600;
			tank1.max_damage +=  290;
			tank1.damage += 290;
		}
		else if(0 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 3250;
			tank1.current_max_hitpoint += 3250;
			tank1.current_hitpoint += 3250;
			tank1.max_damage +=  350;
			tank1.damage += 350;
		}
		tank1.init_accelerate_power += 1;
	}
	//第十三关
	else if(current_stage == 13)
	{
		if(2 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 800;
			tank1.current_max_hitpoint += 800;
			tank1.current_hitpoint += 800;
			tank1.max_damage += 200;
			tank1.damage += 200;
		}
		else if(1 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 2100;
			tank1.current_max_hitpoint += 2100;
			tank1.current_hitpoint += 2100;
			tank1.max_damage +=  280;
			tank1.damage += 280;
		}
		else if(0 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 3850;
			tank1.current_max_hitpoint += 3850;
			tank1.current_hitpoint += 3850;
			tank1.max_damage +=  350;
			tank1.damage += 350;
		}
	}
	//第十四关
	else if(current_stage == 14)
	{
		if(2 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 800;
			tank1.current_max_hitpoint += 800;
			tank1.current_hitpoint += 800;
			tank1.max_damage += 200;
			tank1.damage += 200;
		}
		else if(1 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 2000;
			tank1.current_max_hitpoint += 2000;
			tank1.current_hitpoint += 2000;
			tank1.max_damage +=  280;
			tank1.damage += 280;
		}
		else if(0 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 3850;
			tank1.current_max_hitpoint += 3850;
			tank1.current_hitpoint += 3850;
			tank1.max_damage +=  350;
			tank1.damage += 350;
		}
		tank1.ammor_level += 1;
		tank1.side_ammor_level += 1;

	}
	//下一关要坑爹单挑所以 这一关伤害多增加点
	else if(current_stage == 15)
	{
		if(2 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 800;
			tank1.current_max_hitpoint += 800;
			tank1.current_hitpoint += 800;
			tank1.max_damage += 700;
			tank1.damage += 700;
		}
		else if(1 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 2300;
			tank1.current_max_hitpoint += 2300;
			tank1.current_hitpoint += 2300;
			tank1.max_damage +=  880;
			tank1.damage += 880;
		}
		else if(0 == Player_Tank::difficulty)
		{
			tank1.max_hitpoint += 3850;
			tank1.current_max_hitpoint += 3850;
			tank1.current_hitpoint += 3850;
			tank1.max_damage +=  1050;
			tank1.damage += 1050;
		}
		tank1.init_max_speed += 1;

	}

}