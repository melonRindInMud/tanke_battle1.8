#include "stdafx.h"
#include "̹�˴�սϵ��Dlg.h"

void C̹�˴�սϵ��Dlg::Stage_Complete_Draw(int stage)
{
	if(stage != -1)
	{
		//����ͼƬ
		CBitmap tempbmp;
		tempbmp.LoadBitmapA(IDB_AFTER);
		pictureDC.SelectObject(tempbmp);


		supportDC.BitBlt(0, 0, DIALOG_WIDTH, DIALOG_HEIGHT, &pictureDC, 0, 0, SRCCOPY);
		supportDC.SetBkMode(TRANSPARENT);
		//����
		supportDC.SetTextColor(RGB(0, 0, 0));
		supportDC.TextOutA(488, 60, "��ӭ���� �ɵ�Ư���� ��� ̹���Ѿ���� ǿ��");
		CString h;
		h.Format("����������� %5d", tank1.max_hitpoint);
		supportDC.TextOutA(288, 100, h);
		h.Format("��ǰ������� %5d", tank1.current_max_hitpoint);
		supportDC.TextOutA(288, 140, h);
		h.Format("��ǰ    ���� %5d", tank1.current_hitpoint);
		supportDC.TextOutA(288, 180, h);

		h.Format("��ǰ  �˺�ֵ %5d", tank1.max_damage);
		supportDC.TextOutA(288, 220, h);
		h.Format("��ǰ������ %5d", tank1.fastest_fire_interval);
		supportDC.TextOutA(288, 260, h);
		h.Format("��ǰ�ڵ����� %5d", tank1.fire_speed);
		supportDC.TextOutA(288, 300, h);

		h.Format("��ǰ����ٶ� %5d", tank1.init_max_speed);
		supportDC.TextOutA(288, 340, h);
		h.Format("��ǰ  ���ٶ� %5d", tank1.init_accelerate_power);
		supportDC.TextOutA(288, 380, h);
		h.Format("��ǰת���� %5d", tank1.init_fastest_route_interval);
		supportDC.TextOutA(288, 420, h);

		h.Format("��ǰ    ��� %5d", tank1.gold);
		supportDC.TextOutA(288, 460, h);
		h.Format("��ǰ    ��ɱ %5d", tank1.total_kill);
		supportDC.TextOutA(288, 500, h);
		h.Format("��ǰ  ����ȼ� %2d", tank1.penertrate_level);
		supportDC.TextOutA(288, 540, h);
		h.Format("��ǰ  ��������ȼ� %2d", tank1.ammor_level);
		supportDC.TextOutA(288, 580, h);
		h.Format("��ǰ  ��������ȼ� %2d", tank1.side_ammor_level);
		supportDC.TextOutA(288, 620, h);
		h.Format("��ǰ  ��������ȼ� %2d", tank1.behind_ammor_level);
		supportDC.TextOutA(288, 660, h);


		supportDC.TextOutA(288, 700, "��tab������");

		//����
		h.Format("���� ����        ����    �˺�   ���� ��ɱ");
		supportDC.TextOutA(688, 100, h);
		h.Format("%20s  %6d %6d %2d", tank1.name, tank1.dmg_cause, tank1.dmg_recv, tank1.kill);
		supportDC.TextOutA(688, 140, h);
		h.Format("�Ѿ�����������   ����    �˺�   ���� ��ɱ ");
		supportDC.TextOutA(688, 190, h);
		sort(allience_tanks,allience_tanks + NUM_OF_ALLIENCE,rank);
		int pt_l = 1;
		for(int i = 0; i < NUM_OF_ALLIENCE && i < 8;i ++)
		{
			h.Format("%20s  %6d %6d %2d", allience_tanks[i].name, allience_tanks[i].dmg_cause, allience_tanks[i].dmg_recv, allience_tanks[i].kill);
			supportDC.TextOutA(688, 190 + 40 * (pt_l ++), h);

		}
		pt_l++;


		h.Format("�о�����������   ����    �˺�   ���� ��ɱ ");
		supportDC.TextOutA(688, 190 + 40 * (pt_l ++), h);
		sort(enemy_tanks,enemy_tanks + NUM_OF_ENEMY,rank);
		for(int i = 0; i < NUM_OF_ENEMY && i < 8;i ++)
		{
			h.Format("%20s  %6d %6d %2d", enemy_tanks[i].name, enemy_tanks[i].dmg_cause, enemy_tanks[i].dmg_recv, enemy_tanks[i].kill);
			supportDC.TextOutA(688, 190 + 40 * (pt_l ++), h);

		}


		//�ڶ��� -- ����
		supportDC.SetTextColor(RGB(255, 255, 255));
		//CString h;
		supportDC.TextOutA(490, 60, "��ӭ���� �ɵ�Ư���� ��� ̹���Ѿ���� ǿ��");
		h.Format("����������� %5d", tank1.max_hitpoint);
		supportDC.TextOutA(290, 100, h);
		h.Format("��ǰ������� %5d", tank1.current_max_hitpoint);
		supportDC.TextOutA(290, 140, h);
		h.Format("��ǰ    ���� %5d", tank1.current_hitpoint);
		supportDC.TextOutA(290, 180, h);

		h.Format("��ǰ  �˺�ֵ %5d", tank1.max_damage);
		supportDC.TextOutA(290, 220, h);
		h.Format("��ǰ������ %5d", tank1.fastest_fire_interval);
		supportDC.TextOutA(290, 260, h);
		h.Format("��ǰ�ڵ����� %5d", tank1.fire_speed);
		supportDC.TextOutA(290, 300, h);

		h.Format("��ǰ����ٶ� %5d", tank1.init_max_speed);
		supportDC.TextOutA(290, 340, h);
		h.Format("��ǰ  ���ٶ� %5d", tank1.init_accelerate_power);
		supportDC.TextOutA(290, 380, h);
		h.Format("��ǰת���� %5d", tank1.init_fastest_route_interval);
		supportDC.TextOutA(290, 420, h);

		h.Format("��ǰ    ��� %5d", tank1.gold);
		supportDC.TextOutA(290, 460, h);
		h.Format("��ǰ    ��ɱ %5d", tank1.total_kill);
		supportDC.TextOutA(290, 500, h);



		h.Format("��ǰ  ����ȼ� %2d", tank1.penertrate_level);
		supportDC.TextOutA(290, 540, h);
		h.Format("��ǰ  ��������ȼ� %2d", tank1.ammor_level);
		supportDC.TextOutA(290, 580, h);
		h.Format("��ǰ  ��������ȼ� %2d", tank1.side_ammor_level);
		supportDC.TextOutA(290, 620, h);
		h.Format("��ǰ  ��������ȼ� %2d", tank1.behind_ammor_level);
		supportDC.TextOutA(290, 660, h);

		supportDC.TextOutA(290, 700, "��tab������");


		//����
		h.Format("���� ����        ����    �˺�   ���� ��ɱ");
		supportDC.TextOutA(690, 100, h);
		h.Format("%20s  %6d %6d %2d", tank1.name, tank1.dmg_cause, tank1.dmg_recv, tank1.kill);
		supportDC.TextOutA(690, 140, h);
		h.Format("�Ѿ�����������   ����    �˺�   ���� ��ɱ ");
		supportDC.TextOutA(690, 190, h);
		sort(allience_tanks,allience_tanks + NUM_OF_ALLIENCE,rank);
		pt_l = 1;
		for(int i = 0; i < NUM_OF_ALLIENCE && i < 8;i ++)
		{
			h.Format("%20s  %6d %6d %2d", allience_tanks[i].name, allience_tanks[i].dmg_cause, allience_tanks[i].dmg_recv, allience_tanks[i].kill);
			supportDC.TextOutA(690, 190 + 40 * (pt_l ++), h);

		}
		pt_l++;


		h.Format("�о�����������   ����    �˺�   ���� ��ɱ ");
		supportDC.TextOutA(690, 190 + 40 * (pt_l ++), h);
		sort(enemy_tanks,enemy_tanks + NUM_OF_ENEMY,rank);
		for(int i = 0; i < NUM_OF_ENEMY && i < 8;i ++)
		{
			h.Format("%20s  %6d %6d %2d", enemy_tanks[i].name, enemy_tanks[i].dmg_cause, enemy_tanks[i].dmg_recv, enemy_tanks[i].kill);
			supportDC.TextOutA(690, 190 + 40 * (pt_l ++), h);

		}


		if(stage == 3)
		{
			supportDC.TextOutA(190, 830, "��һ�½��� ������װ���Ѽ���");
			supportDC.TextOutA(190, 860, "״̬�������Ϻ� ��Rһ��ʱ�����������");
		}
		if(stage == 7)
		{
			supportDC.TextOutA(190, 830, "�ڶ��½��� �������Ч���Ѽ���");
			supportDC.TextOutA(190, 860, "��ת�򳬹�1��� ����ٶ����50%");
		}
		if(stage == 12)
		{
			supportDC.TextOutA(190, 830, "�����½��� С��ָ��ϵͳ�Ѽ���");
			supportDC.TextOutA(150, 860, "ͨ������ 1 2 3 ʹ �Լ��������Ѿ��任ս������");
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
		supportDC.TextOutA(s_x, (print_l ++) * 40, "��ϲ��ͨ��������һ��");
		supportDC.TextOutA(s_x, (print_l ++) * 40, "��ҿ���������� �׷׶���ɵ�� ��Ϊ�ǹ������ һʱ�䶼�����ֽ�");
		supportDC.TextOutA(s_x, (print_l ++) * 40, "������̹�˱����еľ��� �������Ȼع����� ���󺰵�");
		supportDC.TextOutA(s_x, (print_l ++) * 40, "��ұ����� ���� ��۲���������  ����÷��� ����  ��ʻԱ����ָ��");
		supportDC.TextOutA(s_x, (print_l ++) * 40, "���ߵ��� ����Ӧ��Ҳû������֧Ԯ������ �����ߵ��� ȥ��װ����װ�ڵ�");
		supportDC.TextOutA(s_x, (print_l ++) * 40, "��Ȼ��Ҷ�����δ�� ���Ͼ�������ս���ϵ���ɱ ���Ǻܿ�ͻع����� ");
		supportDC.TextOutA(s_x, (print_l ++) * 40, "�����˵������ ���صĵо��м� �������ϴ���̹�˱�ը������");
		supportDC.TextOutA(s_x, (print_l ++) * 40, "һ��Ĺ��� ��Ұ�б���Ҳû�� �ڵ���Ϯ�� ��ʱ ɭ����Ũ�ص�������ɢ��");
		supportDC.TextOutA(s_x, (print_l ++) * 40, "���ŵ������ ������Ա ������ ���ݻ�̹���ϵ� ���� ���Ǿ��ܵ۹��ı�־");
		supportDC.TextOutA(s_x, (print_l ++) * 40, "ԭ��ֻ��һ�Ѿ��ܰ� ����Ϊ ���ɹ������ �����Ա�����");
		supportDC.TextOutA(s_x, (print_l ++) * 40, "��ʱ װ���� ˵���� ���� �ղŶ���㼰ʱ��Ӧ���� ��Ȼ���Ǿ��군�� ���� ��˵�㺦����");
		supportDC.TextOutA(s_x, (print_l ++) * 40, "��˵����������Ҳ���� ��������Ȼ�� ���� ���� ��ʲô���� ���ܶ������Ǵ����� �����ѵ��ʹ�����");
		supportDC.TextOutA(s_x, (print_l ++) * 40, "������������˵ ��������κ��� �κ��� ֻҪ�Ǳ�����Ե� ��һ����Ҫ���� ��Ҫ����");
		supportDC.TextOutA(s_x, (print_l ++) * 40, "Ҫ�����򶨵�̬��ȥ���� ֻ����������ȡ����õĽ��  �������²������ੲ�������");
		supportDC.TextOutA(s_x, (print_l ++) * 40, "����������˵�Ļ�  ������Ա������ĵ��˵�ͷ");
		supportDC.TextOutA(s_x, (print_l ++) * 40, "���� ��̹�˿���ɭ�� �ѱ��򻵵Ĵ���ϵͳ�޺� ̹�˿�����������ɭ�� �ص����������ĵĴ����");
		supportDC.TextOutA(s_x, (print_l ++) * 40, "ι ɵС�� ���� ̫����ɹƨ����  �� ��Ȼһ��˯��ʮһ�� �������������˯��");
		supportDC.TextOutA(s_x, (print_l ++) * 40, "�������������� ���л��ĵ�Ц��Ц");
		supportDC.TextOutA(s_x, (print_l ++) * 40, "��tab ��������һ�� �ڴ�֮ǰ ������ �������� ��Ȼһ��ᱻ��ɫ������Ϲ24k�ѺϽ���");
	}

#ifdef LOW_DENSITY
	pDC->StretchBlt(0, 0, 1267, 693, &supportDC, 0, 0, DIALOG_WIDTH, DIALOG_HEIGHT, SRCCOPY);
#else
	pDC->BitBlt(0, 0, DIALOG_WIDTH, DIALOG_HEIGHT, &supportDC, 0, 0, SRCCOPY);
#endif
}