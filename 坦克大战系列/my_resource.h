#pragma once
#include "stdafx.h"

//�ͷֱ�������
//#define LOW_DENSITY


//��Ϸ��ʹ�õĺ궨��

//�Ƿ�ʹ���Ѿ�
#define USE_ALLIENCE 

//�Ƿ�ʹ�ý��ٰ汾
//#define SPEED_DOWN


//�Ƿ�ʹ������ը
//#define EXPLOSE_BOOM

//�Ƿ� ײ��
//#define RAM



//ȫ�潵�ٵ�ʱ��������
#ifdef SPEED_DOWN
#define MOVE_NERF  ((float)2/3)   //��һ���Ƿ���
#define FIRE_NERF  3
#define ROUTE_NERF  1.5
#else 
#define MOVE_NERF  1   //��һ���Ƿ���
#define FIRE_NERF  1
#define ROUTE_NERF  1
#endif



#define MAX_STAGE 16 // ��ǰ�������Ĺؿ���

#define INTERAVL    80   //80����һ֡
//������һ�� ͬʱ�ڳ���ֻ�ܴ���һ���ڵ�


//ս�����
#define FIELD_WIDTH  3000
#define FIELD_HEIGHT 2000 

//����ʾ����ʾ��С
#define VIEW_WIDTH  1500
#define VIEW_HEIGHT 1000 

//״̬��ʾ����С
#define SUBVIEW_WIDTH 400
#define SUBVIEW_HEIGHT 1000


#define TANK_WIDTH 80
#define SHELL_WIDTH 24


//�ҷ����ڱ�׼�����ٶ�
#define  FIRE_SPEED 135

//�з����ڱ�׼�����ٶ�
#define  E_FIRE_SPEED  135


//�ָ�״̬����ʱ��
#define  RECOVER_TIME 1600 * FIRE_NERF


//��ͬλ�ö�����������˺�ϵ��
#define PENERTRATED_DMG_X 0.45
#define UNPENERTRATED_DMG_X  0.15
#define EFFECTIVE_PENERTRATED_DMG_X  0.55


//��������ָ�ʱ�� -- ����
#define ENGINE_REPAIR_TIME 4000


//��������ָ�ʱ�� -- ����
#define GUN_REPAIR_TIME 5000


//δ�����˺�ϵ��
#define UNPENERTRATED_DMG_VALUE 0.09

//������װ��ɼ�������
#define MAX_ENERGY 200
//������װ�����ʱ�� �����룩
#define T_UPGRADE_GUN  4500


//�ܻ�������ʱ�䣨���룩
#define SOUND_INTERVAL  600


//�ӽ��л�ʱ�䣨���룩
#define VIEW_SWITCH_INTERVAL 800


//���عش������� -- ���԰滹����ʽ��
#define M_DEBUG

#define DIFFICULTY 6

//ײ��
//��ײ���Ժ���ƶ�ϵ��
#define FORCE_MOVE_INDEX 5

//ײ���˺�ϵ�� -- Խ���˺�Խ��--���ȹ�ϵ
#define RAM_DMG_X 30

//��ը
#define INI_EXPLOSE_DMG_X  1 //��ʼ��ըϵ�������� Խ��Խ�� ���Ϊ1
#define EXPLOSE_RANGE  350  //��ը���÷�Χ
//Ŀǰ��ը�˺���һ�����Թ�ϵ


//���ش�������ɫ�ı�ʱ��
#define STUNE_TIME  1500
//�ܻ����˺�����ɫ�ı�ʱ��
#define SHOCK_TIME 1000


//#define ENDING2

//ö��
//�н����� �� ָ����� ��� �� ������� �������� �� ֹͣ
enum Orient{UP, DOWN, LEFT, RIGHT, STOP}; //�������� ͣ����������ͣ��Ҫ��ʱ�䣩


//�����еķ���  ���� ǰ�� ����
enum HitOrient{SIDE, FRONT, BEHIND}; //���� ���� ����


//̹�˵�λ  AI ����
// ��ǰ���� ����Ϊ  ����Լ�����  ��ͨ������ں��н�   ͻϮָ��Ŀ��    ��ָ����Χ���λ����е��˽���һ����Χ�ڿ�ʼ׷�ٹ��� ���� ����ƶ����ڣ�   ���ݵз������Ķ��� �Զ��л� �����ͷ��ز���
// ����   �������� -- ֻת���ƶ�  λ���غϵ�ʱ����    �𹥲���  ��������ʱ�Ƚ���׷�� ����С�ڵ���һ����Χ��ͣ��վߣ     �����ؼ�Ŀ����� -- ʼ�ղ���͹ؼ�Ŀ������һ������
enum Recognization {PLAYER, NORMAL, ELITE, VP, MASTER, NOOB, TURRET, PROTEND, PROTECT}; // NOOB�ǲ�����  VP ��ȡ���ز��� MASTER��ȡ�����汸�Ĳ��� TURRET��������ȡ�Ĺ������� //��


//�ؿ�����
// ׼���׶� ���籾 �� ʤ������ �����   ս���׶�   ս��׶�--ս���ܽ�ͽ�����ȡ
enum Process {Prepare, FIGHT, After};


//ʤ������
enum Victory_type {V_TLE, V_KVP, V_STD, V_KNE}; // ����ָ��ʱ��    ����ָ��Ŀ��   ����ȫ�����ˣ���������ʤ�� Ҳ ֧�� ����ʤ����  ����һ����Ŀ�ĵо������ѷ�Э����
//ʧ������
enum Defeated_type {D_TLE, D_LVP, D_STD, D_LNA, D_NSH, D_DLD}; // ָ��ʱ����û���������   �ؼ�Ŀ�걻�Է��ݻ�   ���̹�˱��ݻ�   ʧȥһ����Ŀ���Ѿ�  ��ҩ������ ��ɵ��˺�����


//��λͼ��
//�¾�����̹��  Ӣ���𼪶�̹�� T34̹��   ����   ��ʽ̹�� ��ʽ������   ˹���ֶ���  ˹��������
enum UnitType {G_T1, UK_T1, US_T1, USSR_T1, Turret, G_T2, G_T2_B, USSR_T3, USSR_T4}; // ��λ���� --- ͼ��Ļ���


//��Ч����
enum Sounds {FRONT_HIT_SOUND, SIDE_HIT_SOUND, BEHIND_HIT_SOUND, FIRE_SOUND, EXPLOSE_SOUND};


//��������
enum BoardCast {KILL, DOUBLE_KILL, KILLING_SPREE, RUNPAGE, UNSTOPPABLE, DOMINATING, GOD_LIKE, LEGENDARY};


//�ڵ������Ժ��Ч��
enum ShootResult {UNPENERTRATE, PENERTRATED, EFFECTIVE_PENERTRATED};

//�𺦻㱨
enum DamageReport {ENGINE_DAMAGED, ENGINE_REPAIRED, GUN_DAMAGED, GUN_REPAIRED};


class Shell
{
public:
	//λ����Ϣ
	int pos_x;
	int pos_y;
	//������Ϣ 
	Orient orient; //�ڵ�����
	int speed; //�ڵ��ٶ�
	int distance; //���о���
	int d_cut; //�ɳ�����
	int disprecision; //ƫ��ֵ

	Shell();//Ĭ�Ϲ��캯��
	Shell(int x, int y, Orient init_orient, int init_speed);//���캯��
};


// ������� -- ̹�� �������Ҫʵ�� ��Ȼ�� NPC �� ̹�� ���� ��ҵ�̹��
class Tank
{
public:
	//λ����Ϣ
	int pos_x;
	int pos_y;
	//������Ϣ
	Orient  orient; //̹�˳���
	//��������Ϣ
	clock_t route_interval; //ת����
	clock_t last_route;  //��һ��ת��ʱ��
	//�ٶ���Ϣ
	int Max_Speed;
	int Current_Speed;
	//���ٶ�
	int Accelerate_Power;

	//״̬��Ϣ
	int is_hit; //����֡�����У�
	int last_hit;  //  �ϴα����е��˺�����  --- ������¼�˺����л���
	clock_t t_last_hit;   // ��һ�α�����ʱ��  �����ж��Ƿ���� �˺�����
	HitOrient last_hit_orient; //  ��һ�α����еķ��� --  ���ڽ��л����ж�
	ShootResult last_hit_result; //  ��һ�λ������  -- �����ж��˺����ֻ��Ƶ���ɫ
	Orient last_hit_from; //��һ�������ڵ����ĸ�������

	clock_t t_last_effect_penertrated; //�ϴα���Ч����ʱ��
	clock_t t_last_penertrated;//�ϴα�����ʱ��
	//������Ϣ
	int fire_command; //������˲��ָ�� ������Ҫ��Ϣѭ�� �����Σ�
	Orient  command; //�������ָ��

	//����״̬����
	int is_engine_damage;
	int is_gun_damage;


	//�����봩��
	int penertrate_level; //�ڵ���͸��
	int ammor_level;//����װ��ǿ��
	int side_ammor_level; //����װ��ǿ��
	int behind_ammor_level; //����װ��ǿ��

	//������Ϣ
	int  damage; //�ڵ��˺�
	int fire_speed; // �ڵ�����
	int fire_range; //���
	int precision; //���ھ���

	//������Ϣ
	clock_t  fire_interval; //������
	clock_t  last_fire;  //��һ�η���ʱ��  
	int  shell_on_field; //�Ƿ����ڵ��ڳ���
	Shell  shell_infor; //�ڵ�������Ϣ


	// ������Ϣ
	int max_hitpoint;  // �������ֵ
	int current_max_hitpoint; // ��ǰ�������ֵ
	int current_hitpoint; // ��ǰ����ֵ 
	int restore_per_update; //ÿ֡�ָ�������ֵ
	clock_t die_time; //����ʱ��
	int is_explose; //�������Ƿ�ը��

	//ʶ����Ϣ
	Recognization rc; // AI ����ʶ�� ���������
	UnitType icon;    //  ͼ����Ϣ
	char name[30];   //����
	int is_on_field; //ʶ����Ϣ ���ڼ���Ƿ��ڳ���

	//������Ϣ  --  ��ʱû��ʹ��
	int gold;
	int total_kill;

	//������������
	int penertrated_detonation_rate;
	int effective_penertrated_detonation_rate;
	int engine_damage_rate;
	int gun_damage_rate;

	//���ر�����Ϣ
	int kill;       // ��ɱ����
	int dmg_recv;  // Ǳ���˺�
	int dmg_cause;  // ��Ч�˺�


public:
	//���տ�����Ϣ����
	virtual void try_fire(void) = 0; //���Կ���
	virtual void Tank_Control_Normal(void) = 0; //���ƺ��� ���ڿ���̹���ڻ������ʱ��ı���


	//����������
	void Tank_Move(void); //�ƶ�����
	void Tank_Route(void); //ת����
	void jam_process(void); //���ڴ���ײǽ����

	//�ڵ�������
	void shells_move(void); // �ڵ��ƶ�����
	void out_process(void); //�ж� �Ƿ����

	//������ײ���
	void Check_Block_By_River(void);

};

class Player_Tank :public Tank
{
	//��̬����  --- ��Ϸȫ����Ϣ
public:
	static int difficulty;// �Ѷ� 0 - 2  �� ��ͨ ����  -1 ����
	static int use_shell; //ÿ�� �ڵ�������
	static int is_choice;  //  �Ƿ�ѡ�����Ѷ� 
	static int upgrade_generation;  // �ָ��Ƿ�����
	static int upgrade_engine;  // �����Ƿ�����
	static int upgrade_command;  //  С��ָ���Ƿ����
	static int upgrade_gun;  //������װ���Ƿ����
	static int energy;   // ����
	static int kill_stack;  // ��ɱ��¼
	static clock_t last_kill;  // ��һ����ɻ�ɱ��ʱ��
public:
	clock_t t_last_effect_hit;//���ڼ�¼�ظ��Ƿ��ж� NPCû��
	clock_t t_last_fital_hit; // ���ڼ�¼ �ֻ��Ƿ�ָ� NPCû��
	clock_t t_last_gun_hit; // ���ڼ�¼  �����Ƿ�ָ�NPCû��

	//���ڼ�¼�ָ�buff �� nerff���״̬ 
	int max_damage;         //��ʼ�˺�
	int fastest_fire_interval;  //��ʼ����
	int init_max_speed;  //��ʼ�ٶ�
	int init_fastest_route_interval;  // ��ʼת����
	int init_accelerate_power;  // ��ʼ���ٶ�

public:
	Player_Tank(); //���캯��

	//������Ϣ���ݺ��� -- �麯����д
	void Tank_Control_Normal(void);
	void try_fire(void);

};
class NPC_Tank: public Tank
{
public:
	NPC_Tank();
	NPC_Tank(int hp, int damage, int fire_interval = 800, int Maxspeed = 25, int accerelerate = 7);

	void try_fire(void);

	
	//�����е�Ŀ��ѡ�� ��Ҫ ���� Dlg�е� commandupdateʵ��

	//��ͨ�˹����� ��� ���� �� �ƶ�
	void Tank_Control_Normal(void);
	
	//�߼��˹����� --- �ܹ������˺� ͣ������Ӳ��
	void Tank_Control_Ambush(int x, int y);

	//�߼��˹����� -- ��׷�ʹ� -- ��һ��Ŀ����� ֮�� ѡ�������Ŀ��
	void Tank_Control_ELITE(int x, int y);

	//ÿ��ѡ�������Ŀ��  ֻ�������Ŀ�꿿���㹻����ʱ��Żᷢ��
	void Tank_Control_VP(int x, int y);

	//�������� ѡ�������Ŀ�� ��׼ �� ����ķ���
	void Tank_Control_Turret(int x, int y);

	//�������� ����ѡ����Ŀ�� ��������Χ�� �������ԣ� ��������ĵо� ��������
	void Tank_Control_Protect(int p_x, int p_y, int x, int y);

public:
	static int  AIM_RANGE;
	static int CLOSE_RANGE; 
    static int ALERT_RANGE;
	static int TRIGGER_RANGE;

//����Ŀ��ѡ��Ĳ�����¼
	int target_index; // -1 ���� ��� 0 - n-1 �����n+1��������
	int protect_index; //-1 ����  ��� ͬ��
	
	int Vp_range; // VP ���������ķ�Χ
	int pretend_range; // �Թ� ���ֵľ���
};

//�ڵ������ж�
int  Shell_try_hit(Tank& attacker, Tank& target);
//���з������о��� ���򷵻�-1


//�ڵ����д���
void  Shell_hit(Tank& attacker, Tank& target);



//ÿ�ر���������
bool rank(NPC_Tank& infor1,  NPC_Tank& infor2);

//ײ���ж��봦����
int  try_ram(Tank& tank1, Tank& tank2);




// ========================================��Ƶ���Ź�����===================================== // 

//��Ч���Ų�����
void my_sound_player(Sounds sd);

//��ɱ����������
void kill_stack_broadcast_player(BoardCast bc);

//ս�����ֲ�����
void battle_bgm_player(int stage);

//ǰ�������ֲ�������׼���׶����ֲ�������
void prepartion_bgm_player(int stage);

//�󱳾����ֲ��������ؿ���ɽ׶����ֲ�������
void after_bgm_player(int stage);
//336��

//���𼰻ָ���Ч
void damage_report(DamageReport infor);
