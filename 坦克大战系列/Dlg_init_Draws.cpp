#include "stdafx.h"
#include "̹�˴�սϵ��Dlg.h"
//���ƺ���

extern int river_box_number = 0;
extern CPoint river_infor[50] = {CPoint(0,0)};

//��ʼ���� ���� ���� ���� ��Ч
void C̹�˴�սϵ��Dlg::init_multi_media(void)
{
	//��ǰ�Ի����豸�����ĵ�ȷ�������Ʊ�����
	pDC = GetDC();

	//�ڱ���
	
	blackBackDC.CreateCompatibleDC(pDC);
	blackBackBmp.CreateCompatibleBitmap(pDC, 3000, 2000);
	blackBackDC.SelectObject(&blackBackBmp);
	blackBackDC.FillSolidRect(0, 0, 3000, 2000, RGB(255, 0, 0));
	
	//�챳��
	redBackDC.CreateCompatibleDC(pDC);
	redBackBmp.CreateCompatibleBitmap(pDC, 3000, 2000);
	redBackDC.SelectObject(&redBackBmp);
	redBackDC.FillSolidRect(0, 0, 3000, 2000, RGB(255, 128, 0));
	
	//��ʱDC
	temp_DC.CreateCompatibleDC(pDC);
	temp_DCBmp.CreateCompatibleBitmap(pDC, 1500, 1000);
	temp_DC.SelectObject(&temp_DCBmp);
	temp_DC.FillSolidRect(0, 0, 500, 500, RGB(255, 255, 255));




	//���ú�̨DC 
	supportDC.CreateCompatibleDC(GetDC());
	supportbk.CreateCompatibleBitmap(GetDC(), FIELD_WIDTH, FIELD_HEIGHT);
	supportDC.SelectObject(&supportbk);
	supportDC.FillSolidRect(0, 0, FIELD_WIDTH, FIELD_HEIGHT, RGB(240, 240, 240));


	//ѡ�񱳾�ͼƬ
	
	bkbmp.LoadBitmapA(IDB_BACKGROUND);
	bkresouceDC.CreateCompatibleDC(&memDC);
	bkresouceDC.SelectObject(&bkbmp);


	bkbmp2.LoadBitmapA(IDB_NIGHTMARE);
	bkresouceDC2.CreateCompatibleDC(&memDC2);
	bkresouceDC2.SelectObject(&bkbmp2);


	//����״̬������
	subviewbk.LoadBitmapA(IDB_SUBVIEWBK);



	//��ʼ������1
	memDC.CreateCompatibleDC(&supportDC);
	dcbk.LoadBitmapA(IDB_BACKGROUND);
	dcbk.CreateCompatibleBitmap(&supportDC, FIELD_WIDTH, FIELD_HEIGHT);
	memDC.SelectObject(&dcbk);
	//memDC.FillSolidRect(0, 0, FIELD_WIDTH, FIELD_HEIGHT, RGB(255, 255, 255));


	//��ʼ������2--���ʱ���
	memDC2.CreateCompatibleDC(&supportDC);
	dcbk2.LoadBitmapA(IDB_NIGHTMARE);
	memDC2.SelectObject(&dcbk2);




	//��ʼ��״̬��DC
	stateDC.CreateCompatibleDC(GetDC());
	stateDCbk.CreateCompatibleBitmap(GetDC(), SUBVIEW_WIDTH, SUBVIEW_HEIGHT);
	stateDC.SelectObject(&stateDCbk);
	stateDC.FillSolidRect(0, 0, SUBVIEW_WIDTH, SUBVIEW_HEIGHT, RGB(240, 240, 240));
	
	//��������
	f.CreatePointFont(200, "����");
	fbig.CreatePointFont(320, "����");
	fdmg.CreatePointFont(350, "����");
	ftitle.CreatePointFont(600, "����");
	//supportDC.SelectObject(&f);
	supportDC.SelectObject(&ftitle);
	supportDC.SetBkMode(TRANSPARENT);


	
	//���ؾ�̬����ͼƬ��ֹ�ظ�����

	//����
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

	//��ͼƬ��ԴDC �� ��̨DC �����
	pictureDC.CreateCompatibleDC(&supportDC);

	//���������ͼ
	pro_clt.LoadBitmapA(IDB_PRO_CLT);
	

	//���ӽǱ������
	main_hor_bkg.LoadBitmapA(IDB_MAIN_HOR_BKG);

	//׼���׶α���ͼ
	prepare_bk.LoadBitmapA(IDB_PREPARE_BK);

	//ɭ�ֱ���ͼ
	frost_bk.LoadBitmapA(IDB_BK_FROST);

	//�ݵر���ͼ
	grass_bk.LoadBitmapA(IDB_BACKGROUND);

	//�ڰ�����ͼ
	darkness_bk.LoadBitmapA(IDB_NIGHTMARE);

	//���б���ͼ
	city_bk.LoadBitmapA(IDB_CITY_BKG);

	//ѵ��������ͼ
	tg_bk.LoadBitmapA(IDB_TG_BKG);

	//Ҫ������ͼ
	defense_bk.LoadBitmapA(IDB_DEFENSE_BKG);

	//����
	town_bk.LoadBitmapA(IDB_TOWN_BKG);

	//��Ӱ
	tank_shadow.LoadBitmapA(IDB_TANK_SHADOW);

	//�������
	player_name.LoadBitmapA(IDB_PLAYER_NAME);

	//�з�������Ϣ
	enemy_infor.LoadBitmapA(IDB_ENEMY_INFOR);

	//�ѷ���Ϣ
	allience_infor.LoadBitmapA(IDB_ALLIENCE_INFOR);

	//ʧ��ͼ��
	defeat_map.LoadBitmapA(IDB_DEFEAT);

	//ʤ��ͼ��
	victory_map.LoadBitmapA(IDB_VICTORY);

	//������Ч
	fire_effect.LoadBitmapA(IDB_FIRE_EFFECT);

	//�Ĵ��ۼ�
	move_hint_up_down.LoadBitmapA(IDB_MOVE_HINT_UP_DOWN);
	move_hint_left_right.LoadBitmapA(IDB_MOVE_HINT_LEFT_AND_RIIGHT);

	logo.LoadBitmapA(IDB_LOGO);

	//�������ѳ̶�
	hor_state.LoadBitmapA(IDB_HOR_STATE);

	//�ĸ������ܻ���ʾͼ
	hit_left.LoadBitmapA(IDB_HIT_LEFT);
	hit_right.LoadBitmapA(IDB_HIT_RIGHT);
	hit_down.LoadBitmapA(IDB_HIT_DOWN);
	hit_up.LoadBitmapA(IDB_HIT_UP);

	//̹�������ӰЧ��
	tank_light_effect.LoadBitmapA(IDB_TANK_LIGHT_EFFECT);


	//״̬����������

	//��ʼ��ʾ ״̬ ��
	stateDC.SelectObject(&f);


}

//��ʼ��  �Ѷ� ��Ϣ
void C̹�˴�սϵ��Dlg::init_difficulty_info(void)
{
	stateDC.SetBkColor(RGB(240, 240, 240));
}

//��ý���ʱ���ص�����
void CALLBACK SendFun(UINT wTimerID, UINT msg, DWORD dwUser, DWORD dwl, DWORD dw2)
{
	C̹�˴�սϵ��Dlg* ptr = (C̹�˴�սϵ��Dlg*) dwUser;
	static int is_start = 0;
	static int x_d = 10;
	static int y_d = 20;
	static int k = 0;
	static int m = 0;
	k+= 2;
	//m++;

	if(990 == m)  //����ʱ���
	{
		k -= 1;
		m = 0;
	}

	if (k > 2952)
	{
		k -= 2952;
	}


	//��ʹ��opencv����Ƶ��
	CString pic_name;
	pic_name.Format("CG//%d.jpg", k);
	CImage img;
	img.Load(pic_name);
	img.StretchBlt(ptr->spDC->m_hDC, CRect(CPoint(0, 0), CPoint(1900, 1080)), CRect(CPoint(0, 0), CPoint(1080, 608)), SRCCOPY);


	
	int p_x = 490;
	ptr->spDC->SetTextColor(RGB(0, 0, 0));
	ptr->spDC->SelectObject(&(ptr->ftitle));
	ptr->spDC->TextOutA(867 + x_d, 200 + y_d, "̹�˴�ս");
	ptr->spDC->SelectObject(&(ptr->fbig));
	ptr->spDC->TextOutA(p_x - 4 + x_d, 330 + y_d, "    ����Ƭ1 ���п�����˹-��Ţ�е��ϻ�");
	ptr->spDC->TextOutA(p_x - 4 + x_d, 430 + y_d, "       ��һ�ν�����Ϸ�밴P���ؽ̳�");
	ptr->spDC->TextOutA(p_x - 4 + x_d, 530 + y_d, "��ʼ֮ǰ�밴E N H ѡ���Ѷ�(easy normal hard)");
	ptr->spDC->TextOutA(p_x - 4 + x_d, 630 + y_d, " Ϊ�˱���������������� ��һ�β�����������");
	ptr->spDC->SelectObject(&(ptr->ftitle));
	ptr->spDC->TextOutA(506 + x_d, 730 + y_d, "  ׼�����˰�Enter��ʼ");



	ptr->spDC->SetTextColor(RGB(255, 255, 255));
	ptr->spDC->SelectObject(&(ptr->ftitle));
	ptr->spDC->TextOutA(870 + x_d, 200 + y_d, "̹�˴�ս");
	ptr->spDC->SelectObject(&(ptr->fbig));
	ptr->spDC->TextOutA(p_x + x_d, 330 + y_d, "    ����Ƭ1 ���п�����˹-��Ţ�е��ϻ�");
	ptr->spDC->TextOutA(p_x + x_d, 430 + y_d, "       ��һ�ν�����Ϸ�밴P���ؽ̳�");
	ptr->spDC->TextOutA(p_x + x_d, 530 + y_d, "��ʼ֮ǰ�밴E N H ѡ���Ѷ�(easy normal hard)");
	ptr->spDC->TextOutA(p_x + x_d, 630 + y_d, " Ϊ�˱���������������� ��һ�β�����������");
	ptr->spDC->SelectObject(&(ptr->ftitle));
	ptr->spDC->TextOutA(510 + x_d, 730 + y_d, "  ׼�����˰�Enter��ʼ");

	ptr->spDC->SetTextColor(RGB(0, 0, 0));
	ptr->spDC->SelectObject(&(ptr->f));
	

	//��logo
	ptr->pictureDC.SelectObject(&(ptr->logo));
	ptr->spDC->TransparentBlt(650, 120, 201, 232, &(ptr->pictureDC), 0, 0, 402, 464, RGB(255, 255, 255)); 



	//�����ӽǷ��
	ptr->pictureDC.SelectObject(&(ptr->main_hor_bkg));
	BLENDFUNCTION blendFunction;
	memset( &blendFunction, 0, sizeof(blendFunction) );
	blendFunction.BlendOp = AC_SRC_OVER;
	blendFunction.BlendFlags = 0;
	blendFunction.SourceConstantAlpha = 96;
	ptr->supportDC.AlphaBlend(0, 0, 1900, 1040, &(ptr->pictureDC), 0,0, 1500, 1000, blendFunction);

	ptr->pDC->BitBlt(0, 0, DIALOG_WIDTH, DIALOG_HEIGHT, ptr->spDC, x_d, y_d, SRCCOPY);

}

//��ʼ��  �������ʱ�Ľ���
void C̹�˴�սϵ��Dlg::init_start_Draws(void)
{
	//�ö�ý�嶨ʱ������
	TIMECAPS   tc;   //��ʱ���ṹ�� 
	UINT wTimerRes;  // ʱ������Դ

	if(timeGetDevCaps(&tc, sizeof(TIMECAPS)) != TIMERR_NOERROR)
		AfxMessageBox("�����ý�嶨ʱ��ʧ��");

	wTimerRes = MIN(MAX(tc.wPeriodMin, 1), tc.wPeriodMax);
	timeBeginPeriod(wTimerRes);

	// +2  84
	g_wTimerID = timeSetEvent(84,  wTimerRes, (LPTIMECALLBACK)SendFun,  (DWORD)this, TIME_PERIODIC);


	//SetTimer(888, 35, NULL);
	//һ��һ���Ļ��ƿ��ܻᵼ��  �� ���� ����ʹ�ñ���DC ��	
	//bgm_cg.mp3
	::mciSendString("open cg_bgm.mp3 alias begin", NULL, 0, NULL); //�� �ļ�123.mp3  ��ȡ���� start
	::mciSendString("play begin repeat", NULL, 0, NULL);

}
// 182