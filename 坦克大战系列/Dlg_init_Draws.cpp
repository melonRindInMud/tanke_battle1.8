#include "stdafx.h"
#include "坦克大战系列Dlg.h"
//绘制函数

extern int river_box_number = 0;
extern CPoint river_infor[50] = {CPoint(0,0)};

//初始绘制 并且 加载 音乐 音效
void C坦克大战系列Dlg::init_multi_media(void)
{
	//当前对话框设备上下文的确定（绘制背景）
	pDC = GetDC();

	//黑背景
	
	blackBackDC.CreateCompatibleDC(pDC);
	blackBackBmp.CreateCompatibleBitmap(pDC, 3000, 2000);
	blackBackDC.SelectObject(&blackBackBmp);
	blackBackDC.FillSolidRect(0, 0, 3000, 2000, RGB(255, 0, 0));
	
	//红背景
	redBackDC.CreateCompatibleDC(pDC);
	redBackBmp.CreateCompatibleBitmap(pDC, 3000, 2000);
	redBackDC.SelectObject(&redBackBmp);
	redBackDC.FillSolidRect(0, 0, 3000, 2000, RGB(255, 128, 0));
	
	//临时DC
	temp_DC.CreateCompatibleDC(pDC);
	temp_DCBmp.CreateCompatibleBitmap(pDC, 1500, 1000);
	temp_DC.SelectObject(&temp_DCBmp);
	temp_DC.FillSolidRect(0, 0, 500, 500, RGB(255, 255, 255));




	//设置后台DC 
	supportDC.CreateCompatibleDC(GetDC());
	supportbk.CreateCompatibleBitmap(GetDC(), FIELD_WIDTH, FIELD_HEIGHT);
	supportDC.SelectObject(&supportbk);
	supportDC.FillSolidRect(0, 0, FIELD_WIDTH, FIELD_HEIGHT, RGB(240, 240, 240));


	//选择背景图片
	
	bkbmp.LoadBitmapA(IDB_BACKGROUND);
	bkresouceDC.CreateCompatibleDC(&memDC);
	bkresouceDC.SelectObject(&bkbmp);


	bkbmp2.LoadBitmapA(IDB_NIGHTMARE);
	bkresouceDC2.CreateCompatibleDC(&memDC2);
	bkresouceDC2.SelectObject(&bkbmp2);


	//加载状态栏背景
	subviewbk.LoadBitmapA(IDB_SUBVIEWBK);



	//初始化背景1
	memDC.CreateCompatibleDC(&supportDC);
	dcbk.LoadBitmapA(IDB_BACKGROUND);
	dcbk.CreateCompatibleBitmap(&supportDC, FIELD_WIDTH, FIELD_HEIGHT);
	memDC.SelectObject(&dcbk);
	//memDC.FillSolidRect(0, 0, FIELD_WIDTH, FIELD_HEIGHT, RGB(255, 255, 255));


	//初始化背景2--梦魇背景
	memDC2.CreateCompatibleDC(&supportDC);
	dcbk2.LoadBitmapA(IDB_NIGHTMARE);
	memDC2.SelectObject(&dcbk2);




	//初始化状态栏DC
	stateDC.CreateCompatibleDC(GetDC());
	stateDCbk.CreateCompatibleBitmap(GetDC(), SUBVIEW_WIDTH, SUBVIEW_HEIGHT);
	stateDC.SelectObject(&stateDCbk);
	stateDC.FillSolidRect(0, 0, SUBVIEW_WIDTH, SUBVIEW_HEIGHT, RGB(240, 240, 240));
	
	//字体设置
	f.CreatePointFont(200, "宋体");
	fbig.CreatePointFont(320, "宋体");
	fdmg.CreatePointFont(350, "宋体");
	ftitle.CreatePointFont(600, "宋体");
	//supportDC.SelectObject(&f);
	supportDC.SelectObject(&ftitle);
	supportDC.SetBkMode(TRANSPARENT);


	
	//加载静态常用图片防止重复加载

	//河流
	river_bitmap.LoadBitmapA(IDB_RIVER);

	Tank_Up.LoadBitmapA(IDB_TANK_UP);
	Tank_Down.LoadBitmapA(IDB_TANK_DOWN);
	Tank_Left.LoadBitmapA(IDB_TANK_LEFT);
	Tank_right.LoadBitmapA(IDB_TANK_RIGHT);

	Tank1_Up.LoadBitmapA(IDB_TANK1_UP);
	Tank1_Down.LoadBitmapA(IDB_TANK1_DOWN);
	Tank1_Left.LoadBitmapA(IDB_TANK1_LEFT);
	Tank1_right.LoadBitmapA(IDB_TANK1_RIGHT);

	uk_tank1_Up.LoadBitmapA(IDB_uk_tank1_Up);
	uk_tank1_Down.LoadBitmapA(IDB_uk_tank1_Down);
	uk_tank1_Left.LoadBitmapA(IDB_uk_tank1_Left);
	uk_tank1_right.LoadBitmapA(IDB_uk_tank1_right);

	G_T2_Up.LoadBitmapA(IDB_G_TANK2_UP);
	G_T2_Down.LoadBitmapA(IDB_G_TANK2_DOWN);
	G_T2_Left.LoadBitmapA(IDB_G_TANK2_LEFT);
	G_T2_right.LoadBitmapA(IDB_G_TANK2_RIGHT);

	G_T2_B_Up.LoadBitmapA(IDB_G_TANK2_B_UP);
	G_T2_B_Down.LoadBitmapA(IDB_G_TANK2_B_DOWN);
	G_T2_B_Left.LoadBitmapA(IDB_G_TANK2_B_LEFT);
	G_T2_B_right.LoadBitmapA(IDB_G_TANK2_B_RIGHT);



	Turret_Up.LoadBitmapA(IDB_TURRERT_UP);
	Turret_Down.LoadBitmapA(IDB_TURRERT_DOWN);
	Turret_Left.LoadBitmapA(IDB_TURRERT_LEFT);
	Turret_Right.LoadBitmapA(IDB_TURRERT_RIGHT);

	ussr_tank1_Up.LoadBitmapA(IDB_ussr_tank1_Up);
	ussr_tank1_Down.LoadBitmapA(IDB_ussr_tank1_Down);
	ussr_tank1_Left.LoadBitmapA(IDB_ussr_tank1_Left);
	ussr_tank1_right.LoadBitmapA(IDB_ussr_tank1_right);

	ussr_tanks3_Up.LoadBitmapA(IDB_USSR_TANK3_UP);
	ussr_tanks3_Down.LoadBitmapA(IDB_USSR_TANK3_DOWN);
	ussr_tanks3_Left.LoadBitmapA(IDB_USSR_TANK3_LEFT);
	ussr_tanks3_right.LoadBitmapA(IDB_USSR_TANK3_RIGHT);

	ussr_tanks4_Up.LoadBitmapA(IDB_USSR_TANK4_UP);
	ussr_tanks4_Down.LoadBitmapA(IDB_USSR_TANK4_DOWN);
	ussr_tanks4_Left.LoadBitmapA(IDB_USSR_TANK4_LEFT);
	ussr_tanks4_right.LoadBitmapA(IDB_USSR_TANK4_RIGHT);


	shell.LoadBitmapA(IDB_SHELL);
	shell_f.LoadBitmapA(IDB_SHELL_F);
	immue.LoadBitmapA(IDB_IMMUNE);
	hit.LoadBitmapA(IDB_HIT);
	boom.LoadBitmapA(IDB_BOOM);
	tnt.LoadBitmapA(IDB_TNT);

	engine_damage.LoadBitmapA(IDB_ENGINE_DAMAGE);
	gun_damage.LoadBitmapA(IDB_GUN_DAMAGE);


	memDC.SetStretchBltMode(HALFTONE);

	//将图片资源DC 与 后台DC 相关联
	pictureDC.CreateCompatibleDC(&supportDC);

	//进度条风格图
	pro_clt.LoadBitmapA(IDB_PRO_CLT);
	

	//主视角背景风格
	main_hor_bkg.LoadBitmapA(IDB_MAIN_HOR_BKG);

	//准备阶段背景图
	prepare_bk.LoadBitmapA(IDB_PREPARE_BK);

	//森林背景图
	frost_bk.LoadBitmapA(IDB_BK_FROST);

	//草地背景图
	grass_bk.LoadBitmapA(IDB_BACKGROUND);

	//黑暗背景图
	darkness_bk.LoadBitmapA(IDB_NIGHTMARE);

	//城市背景图
	city_bk.LoadBitmapA(IDB_CITY_BKG);

	//训练场背景图
	tg_bk.LoadBitmapA(IDB_TG_BKG);

	//要塞背景图
	defense_bk.LoadBitmapA(IDB_DEFENSE_BKG);

	//城镇
	town_bk.LoadBitmapA(IDB_TOWN_BKG);

	//阴影
	tank_shadow.LoadBitmapA(IDB_TANK_SHADOW);

	//玩家名字
	player_name.LoadBitmapA(IDB_PLAYER_NAME);

	//敌方数量信息
	enemy_infor.LoadBitmapA(IDB_ENEMY_INFOR);

	//友方信息
	allience_infor.LoadBitmapA(IDB_ALLIENCE_INFOR);

	//失败图像
	defeat_map.LoadBitmapA(IDB_DEFEAT);

	//胜利图像
	victory_map.LoadBitmapA(IDB_VICTORY);

	//开炮特效
	fire_effect.LoadBitmapA(IDB_FIRE_EFFECT);

	//履带痕迹
	move_hint_up_down.LoadBitmapA(IDB_MOVE_HINT_UP_DOWN);
	move_hint_left_right.LoadBitmapA(IDB_MOVE_HINT_LEFT_AND_RIIGHT);

	logo.LoadBitmapA(IDB_LOGO);

	//界面碎裂程度
	hor_state.LoadBitmapA(IDB_HOR_STATE);

	//四个方向受击提示图
	hit_left.LoadBitmapA(IDB_HIT_LEFT);
	hit_right.LoadBitmapA(IDB_HIT_RIGHT);
	hit_down.LoadBitmapA(IDB_HIT_DOWN);
	hit_up.LoadBitmapA(IDB_HIT_UP);

	//坦克立体光影效果
	tank_light_effect.LoadBitmapA(IDB_TANK_LIGHT_EFFECT);


	//状态界面区绘制

	//初始提示 状态 绘
	stateDC.SelectObject(&f);


}

//初始化  难度 信息
void C坦克大战系列Dlg::init_difficulty_info(void)
{
	stateDC.SetBkColor(RGB(240, 240, 240));
}

//多媒体计时器回调函数
void CALLBACK SendFun(UINT wTimerID, UINT msg, DWORD dwUser, DWORD dwl, DWORD dw2)
{
	C坦克大战系列Dlg* ptr = (C坦克大战系列Dlg*) dwUser;
	static int is_start = 0;
	static int x_d = 10;
	static int y_d = 20;
	static int k = 0;
	static int m = 0;
	k+= 2;
	//m++;

	if(990 == m)  //减少时间差
	{
		k -= 1;
		m = 0;
	}

	if (k > 2952)
	{
		k -= 2952;
	}


	//不使用opencv做视频：
	CString pic_name;
	pic_name.Format("CG//%d.jpg", k);
	CImage img;
	img.Load(pic_name);
	img.StretchBlt(ptr->spDC->m_hDC, CRect(CPoint(0, 0), CPoint(1900, 1080)), CRect(CPoint(0, 0), CPoint(1080, 608)), SRCCOPY);


	
	int p_x = 490;
	ptr->spDC->SetTextColor(RGB(0, 0, 0));
	ptr->spDC->SelectObject(&(ptr->ftitle));
	ptr->spDC->TextOutA(867 + x_d, 200 + y_d, "坦克大战");
	ptr->spDC->SelectObject(&(ptr->fbig));
	ptr->spDC->TextOutA(p_x - 4 + x_d, 330 + y_d, "    资料片1 奥托卡尔乌斯-泥泞中的老虎");
	ptr->spDC->TextOutA(p_x - 4 + x_d, 430 + y_d, "       第一次进入游戏请按P加载教程");
	ptr->spDC->TextOutA(p_x - 4 + x_d, 530 + y_d, "开始之前请按E N H 选择难度(easy normal hard)");
	ptr->spDC->TextOutA(p_x - 4 + x_d, 630 + y_d, " 为了避免出现铁锅炖萌新 第一次不建议玩困难");
	ptr->spDC->SelectObject(&(ptr->ftitle));
	ptr->spDC->TextOutA(506 + x_d, 730 + y_d, "  准备好了按Enter开始");



	ptr->spDC->SetTextColor(RGB(255, 255, 255));
	ptr->spDC->SelectObject(&(ptr->ftitle));
	ptr->spDC->TextOutA(870 + x_d, 200 + y_d, "坦克大战");
	ptr->spDC->SelectObject(&(ptr->fbig));
	ptr->spDC->TextOutA(p_x + x_d, 330 + y_d, "    资料片1 奥托卡尔乌斯-泥泞中的老虎");
	ptr->spDC->TextOutA(p_x + x_d, 430 + y_d, "       第一次进入游戏请按P加载教程");
	ptr->spDC->TextOutA(p_x + x_d, 530 + y_d, "开始之前请按E N H 选择难度(easy normal hard)");
	ptr->spDC->TextOutA(p_x + x_d, 630 + y_d, " 为了避免出现铁锅炖萌新 第一次不建议玩困难");
	ptr->spDC->SelectObject(&(ptr->ftitle));
	ptr->spDC->TextOutA(510 + x_d, 730 + y_d, "  准备好了按Enter开始");

	ptr->spDC->SetTextColor(RGB(0, 0, 0));
	ptr->spDC->SelectObject(&(ptr->f));
	

	//加logo
	ptr->pictureDC.SelectObject(&(ptr->logo));
	ptr->spDC->TransparentBlt(650, 120, 201, 232, &(ptr->pictureDC), 0, 0, 402, 464, RGB(255, 255, 255)); 



	//加上视角风格
	ptr->pictureDC.SelectObject(&(ptr->main_hor_bkg));
	BLENDFUNCTION blendFunction;
	memset( &blendFunction, 0, sizeof(blendFunction) );
	blendFunction.BlendOp = AC_SRC_OVER;
	blendFunction.BlendFlags = 0;
	blendFunction.SourceConstantAlpha = 96;
	ptr->supportDC.AlphaBlend(0, 0, 1900, 1040, &(ptr->pictureDC), 0,0, 1500, 1000, blendFunction);

	ptr->pDC->BitBlt(0, 0, DIALOG_WIDTH, DIALOG_HEIGHT, ptr->spDC, x_d, y_d, SRCCOPY);

}

//初始化  进入程序时的界面
void C坦克大战系列Dlg::init_start_Draws(void)
{
	//用多媒体定时器代替
	TIMECAPS   tc;   //定时器结构体 
	UINT wTimerRes;  // 时间间隔资源

	if(timeGetDevCaps(&tc, sizeof(TIMECAPS)) != TIMERR_NOERROR)
		AfxMessageBox("申请多媒体定时器失败");

	wTimerRes = MIN(MAX(tc.wPeriodMin, 1), tc.wPeriodMax);
	timeBeginPeriod(wTimerRes);

	// +2  84
	g_wTimerID = timeSetEvent(84,  wTimerRes, (LPTIMECALLBACK)SendFun,  (DWORD)this, TIME_PERIODIC);


	//SetTimer(888, 35, NULL);
	//一条一条的绘制可能会导致  其 卡顿 还是使用备用DC 吧	
	//bgm_cg.mp3
	::mciSendString("open cg_bgm.mp3 alias begin", NULL, 0, NULL); //打开 文件123.mp3  并取别名 start
	::mciSendString("play begin repeat", NULL, 0, NULL);

}
// 182