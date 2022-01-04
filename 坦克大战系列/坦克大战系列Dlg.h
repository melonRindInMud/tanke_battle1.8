
// ̹�˴�սϵ��Dlg.h : ͷ�ļ�
//

#pragma once

#include "resource.h"
#include "my_resource.h"
#include "MQuestDialog.h"
#include "M_HelpDialog.h"
#define DIALOG_WIDTH  1900
#define DIALOG_HEIGHT 1040





// C̹�˴�սϵ��Dlg �Ի���
class C̹�˴�սϵ��Dlg : public CDialogEx
{
// ����
public:
	C̹�˴�սϵ��Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog(); // ��ʼ������ 
public:
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);  // �ھ���ĺ�������  -- ����׸��
	afx_msg void OnPaint();   
	afx_msg HCURSOR OnQueryDragIcon();  
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	DECLARE_MESSAGE_MAP()

	virtual BOOL PreTranslateMessage(MSG* pMsg);   //  ��Ϣѭ��Ӱ�캯��


	//�߼��洢 ̹���� -- ע�� �ڵ������Ǹ����� ̹�˵� ���� ���ֲ�����
	Player_Tank tank1;  // ����̹��
	NPC_Tank enemy_tanks[500]; //�з�
	NPC_Tank allience_tanks[500];//�ѷ�
#ifdef USE_ALLIENCE
#endif

	//���������Ĺ��� ը�� �������ڹ���Ӱ��ؿ�ƽ���Ժ�����ɾ����
	int boomb;//ը������

	//��ͼʹ��
	
	//��һ���� DC 
	//��̨DC �� �ڴ�DC
	//
public:

	CDC tempDC;
	CDC* spDC;
	CDC memDC; //����DC
	CDC memDC2; //�ڶ�������DC
	CDC supportDC;  //��̨DC
	CDC stateDC; // ״̬��DC
	CDC* pDC;  // ǰ̨DC
	CDC pictureDC;      //  ͼƬDC ����̬ ���ϸ���ʹ�ã�
	CDC bkresouceDC;  // ������ԴDC 
	CDC bkresouceDC2;  // ������ԴDC 
	CDC blackBackDC;// �ڱ���DC
	CDC redBackDC; //�챳��DC
	CDC temp_DC; //������ʱ����һЩ��� ���ز��ܳ���500 * 500

	//�ڶ����� ͼƬ �� ���ڼ����ڴ� DC �� ����
	//�ڶ����ֵ�һ�ֲ� ����
	CBitmap dcbk; //����DC ����
	CBitmap dcbk2; //�ڶ��ű��� ����
	CBitmap supportbk;
	CBitmap stateDCbk;
	CBitmap bkbmp;
	CBitmap bkbmp2;
	CBitmap blackBackBmp;//�ڱ��� ����
	CBitmap redBackBmp; //�챳������
	CBitmap temp_DCBmp; //��ʱDC����




	//�ڶ��ֲ�  ��Դͼ��
	CBitmap subviewbk;
	CBitmap hit;  //  �����е�ͼ�� -- ������Ҫʹ��ƴ�Ӽ���
	CBitmap boom; // ���ݻ�ͼ��
	CBitmap tnt; // ը��ͼ��
	CBitmap pro_clt; //���������ͼ��
	CBitmap main_hor_bkg; //���ӽǱ������
	CBitmap prepare_bk; //׼���׶α���ͼ
	CBitmap frost_bk; //ɭ�ֱ���ͼ
	CBitmap grass_bk; //�ݵر���ͼ
	CBitmap darkness_bk; //�ڰ�����ͼ
	CBitmap city_bk; //����
	CBitmap tg_bk; //ѵ����
	CBitmap defense_bk; //Ҫ��
	CBitmap town_bk; //����

	CBitmap tank_shadow; //̹��Ӱ��

	CBitmap enemy_infor; //�з�����
	CBitmap allience_infor; //��������
	CBitmap player_name; //�������
	CBitmap fire_effect; //�������ڿ���Ч
	CBitmap hor_state; //�������ѳ̶�


	//̹���Ĵ�ѹ���ĺۼ�
	CBitmap move_hint_up_down;  
	CBitmap move_hint_left_right; 


	CBitmap hit_up; 
	CBitmap hit_down;
	CBitmap hit_right;
	CBitmap hit_left;

	//��ͬ����̹��ͼ�� -- ���ж�Ӧ��ԭ��
	//̹�˲�ͬ����ͼ��  -- ̹��ԭ�ͳ�
	CBitmap Tank_Up;
	CBitmap Tank_Down;
	CBitmap Tank_Left;
	CBitmap Tank_right;
	//�¾�̹��
	CBitmap Tank1_Up;
	CBitmap Tank1_Down;
	CBitmap Tank1_Left;
	CBitmap Tank1_right;
	//Ӣ�� ����  ���� ̹��
	CBitmap uk_tank1_Up;
	CBitmap uk_tank1_Down;
	CBitmap uk_tank1_Left;
	CBitmap uk_tank1_right;
	//����
	CBitmap Turret_Up;
	CBitmap Turret_Down;
	CBitmap Turret_Left;
	CBitmap Turret_Right;
	//�վ�̹��
	CBitmap ussr_tank1_Up;
	CBitmap ussr_tank1_Down;
	CBitmap ussr_tank1_Left;
	CBitmap ussr_tank1_right;
	//�վ�̹��3   ˹���ֶ���
	CBitmap ussr_tanks3_Up;
	CBitmap ussr_tanks3_Down;
	CBitmap ussr_tanks3_Left;
	CBitmap ussr_tanks3_right;
	//�վ�̹��4  ˹��������
	CBitmap ussr_tanks4_Up;
	CBitmap ussr_tanks4_Down;
	CBitmap ussr_tanks4_Left;
	CBitmap ussr_tanks4_right;
	//�¾� ��ʽ
	CBitmap G_T2_Up;
	CBitmap G_T2_Down;
	CBitmap G_T2_Left;
	CBitmap G_T2_right;
	//�¾� ��ʽ����Ϳװ
	CBitmap G_T2_B_Up;
	CBitmap G_T2_B_Down;
	CBitmap G_T2_B_Left;
	CBitmap G_T2_B_right;
	// �ڵ� ���� ͼ�� 
	CBitmap shell; //�з��ڵ�ͼ��
	CBitmap shell_f;  // �ѷ��ڵ�ͼ��
	CBitmap immue;  // ����ͼ��
	//����״̬����ͼ��
	CBitmap engine_damage; // ������ͼ��
	CBitmap gun_damage;  // ������ͼ��
	//����ͼ��
	CBitmap river_bitmap;

	//ʧ��ͼ��
	CBitmap defeat_map;
	//ʤ��ͼ��
	CBitmap victory_map;

	//̹�˹�ӰЧ��
	CBitmap tank_light_effect;

	//��־
	CBitmap logo;
	

	//����
	CFont f;    //  �������� �� ������������
	CFont fbig; 
	CFont fdmg;  // �˺�ֵ��ʾ ��������
	CFont ftitle;  //  ������������

	//��Ҫʱ����¼
	clock_t Dialog_current_clock; // �Ի���  ��ǰ ս������ ʱ��   ����������Ҫ
	clock_t immune_to;  //����̹������ʱ��  --- ÿ�ؿ�ʼ̹�˶��������ӵ�����
	clock_t stage_begin_time; // ��ǰ�ؿ���ʼ��ʱ��
	clock_t last_allience_send; //�ϴ��Ѿ�����ʱ��  -- ���ڶನ�� �Ѿ����ֵĹؿ�
	clock_t last_enemy_send; // �ϴεо�����ʱ��  --  ͬ��
	clock_t gun_up_to; // ������װ���������ʱ��

	//��ɱ����

	//���ļ��̴洢��Ϣ
	HKL my_old_layout;


	//�ؿ���Ϣ���ֲ���̬��Ϣ�� ͳ����Ϣ
	int NUM_OF_ENEMY; //���صз�����
	int NUM_OF_ALLIENCE;//�����ѷ�����
	int NUM_OF_TEAMMATE; //����С������
	//��ǰ�ؿ�ʧ�� ʤ�� ����
	Victory_type c_v_t;
	Defeated_type c_d_t;
	int  v_addtion_param; //ʤ�������� 
	int  d_addtion_param; //ʧ�ܸ����� -- 
	int  v_addtion_time; //ʱ��ʤ��׷���� 
	int  d_addtion_time;
	//����Ч��  -- ��� �򲻹����Զ�������  -- ��Ϸÿ�ص�һ�ο�ʼʱ ���Զ���¼ ��ϢΪ��̬�� ֱ����һ�صĿ�ʼ
	Player_Tank player_at_stage_begin; //�ؿ���ʼ״̬

	//�ֲ���̬��Ϣ
	int enemys; //��ǰ�з�����
	int alliences; // ��ǰ�ѷ�����
	//����ʹ�� ��ͬ�ؿ�Ч����ͬ
	int allience_is_send; //��ǰ�ѷ����Ͳ�����Ϣ
	int h;  // ��ǰ�з� �����Ƿ����� �Լ����͵��ۺ���Ϣ ����һ���ۺ��Ա��� ���� �����е���֣�
	int a_h; // ��ǰ�ѷ� .... �����Ƿ����˵�...

	//��ǰ  ���ео����� �� �����Ϻͳ����� ����
	int all_enemys;
	int all_alliences;
	//С��ָ�� -- ����С��ָ���Ժ� �� ���������¼С��ָ��
	int instruct;


	//��Ϸȫ����Ϣ -- ����һ�� �Ƿ�ʼ �� pretranlatemsg �� �� �ֲ���̬���� ���� ��λ��һ���� ���� ���ʼ���һ��
	int current_stage; // ��ǰ�ؿ�
	Process process; //��ǰ����


	//����ʱ�����  �����������ѡ��ϵͳ��û�п���
	int buy_free_access; //��ǰ����������Ч�� 

	//�ӽ�
	Orient view_orient;  //��ǰ�ӽ� 
	Orient last_view_orient;  //֮ǰ�ӽ�

	//�ؿ�����
	string stage_name;

	//��ý���ʱ�����
	MMRESULT g_wTimerID;



	//��ʼ��ģ��
	void init_multi_media(void); // ��ʼ��ͼ�� ���������� ������ִ�м������������ִ��һ�飩
	void init_difficulty_info(void); //ѡ���ѶȺ� �� �Ѷȿ��� stateDC ��
	void init_start_Draws(void);


	//�ؿ���Ϣ��ʼ������
	void stage_init_tank(int stage); // �ؿ���ʼ���з�


	//�ؿ��¼�ѯ��
	void Query_Events(void);

	//�������º��� ս�����ֻ������
	void Battle_Update_Control(void); //��������������
	//ս������ �߼����º���  �ڵ��߼�����
	void Shells_Update(void); //�ڵ��߼����� ���� �ڵ��ƶ� �� �Ƿ���� Ŀ��
	//ս������ �߼����º���  ��� �� ģ�� AI ��ָ�����
	void Command_Update(void); // �Ȱ��� �ڵ������Ժ� ���ж�   Ȼ���� ̹���ƶ� ���ڲ�������


    // �������  ��������� �����������
	void Draw_Update(void); //���������
	void SubView_Update(void); //״̬������

	//ս�������߼����º��� -- ʤ���ж�
	int Win_Lose_Judge(void);//ʤ���ж�

	//��Ϸ���̸��� -- ս������籾����
	void Process_Show(void); // �ؿ�֮�����Ϣ

	//CG�滭
	void CG_Draw(int k);

	//�籾��ȡ����
	//���¾籾���ڴ��ⲿ�ļ���ȡ
	void Story_Information_Presentor(int stage);

	//���ʱ��Ľ����������
	void Stage_Complete_Draw(int stage);
	//ÿ�ؽ������̹������
	void Tank_Auto_Upgrade_By_Stage(int stage);



	//ս�����̻��ƺ���
	//̹��ͼ��ѡ�񲢻���
	void Tank_Graph_Drawer(Tank& tk, int p);
	//�˺����� �ڵ��ȸ���ͼ������
	void Attach_Graph_Drawer(Tank& tk, int p);
	//���ϵͳ
	void Draw_Fire_Control(void);
	//�ܴ���ʾ
	void Show_Player_Hit_Effect(void);
	//����������(��Ѫ����)
	void Standard_Pro_Ctrl_Draw(int x, int y, int cx, int cy, int index, CDC* stylemapDC, CDC* groundDC, COLORREF bkclr, COLORREF ftclr, int transparent_degree);


	
	//״̬������
	//������Ϣ����
	void StateDC_Basic_Infor_Draw(void);
	//С��ͼ����
	void StateDC_Draw_Litter_Map_And_View(void);
	//������������
	void StateDC_Additional_Ability_Draw(void);
	//������ʾ���� 
	void StateDC_Special_Reming(void);
	//��������״̬����
	void StateDC_Damage_State_Draw(void);



	//����ʱ�Ľ��䱬ը
	void Explose_Effect(void);


	//Openning 
	void Openning_Draw(int k);
	//Ending
	void Ending_Draw(int k);

	


};
//249��