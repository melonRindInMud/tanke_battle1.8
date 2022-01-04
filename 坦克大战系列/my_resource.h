#pragma once
#include "stdafx.h"

//低分辨率缩放
//#define LOW_DENSITY


//游戏中使用的宏定义

//是否使用友军
#define USE_ALLIENCE 

//是否使用降速版本
//#define SPEED_DOWN


//是否使用死后爆炸
//#define EXPLOSE_BOOM

//是否 撞击
//#define RAM



//全面降速的时代来临了
#ifdef SPEED_DOWN
#define MOVE_NERF  ((float)2/3)   //第一个是分数
#define FIRE_NERF  3
#define ROUTE_NERF  1.5
#else 
#define MOVE_NERF  1   //第一个是分数
#define FIRE_NERF  1
#define ROUTE_NERF  1
#endif



#define MAX_STAGE 16 // 当前开发出的关卡数

#define INTERAVL    80   //80毫秒一帧
//先做简单一点 同时在场上只能存在一发炮弹


//战场宽度
#define FIELD_WIDTH  3000
#define FIELD_HEIGHT 2000 

//主显示区显示大小
#define VIEW_WIDTH  1500
#define VIEW_HEIGHT 1000 

//状态显示区大小
#define SUBVIEW_WIDTH 400
#define SUBVIEW_HEIGHT 1000


#define TANK_WIDTH 80
#define SHELL_WIDTH 24


//我方火炮标准飞行速度
#define  FIRE_SPEED 135

//敌方火炮标准飞行速度
#define  E_FIRE_SPEED  135


//恢复状态所需时间
#define  RECOVER_TIME 1600 * FIRE_NERF


//不同位置对最大生命的伤害系数
#define PENERTRATED_DMG_X 0.45
#define UNPENERTRATED_DMG_X  0.15
#define EFFECTIVE_PENERTRATED_DMG_X  0.55


//引擎受损恢复时间 -- 毫秒
#define ENGINE_REPAIR_TIME 4000


//主炮受损恢复时间 -- 毫秒
#define GUN_REPAIR_TIME 5000


//未击穿伤害系数
#define UNPENERTRATED_DMG_VALUE 0.09

//主炮再装填可激活能量
#define MAX_ENERGY 200
//主炮再装填持续时间 （毫秒）
#define T_UPGRADE_GUN  4500


//受击音响间隔时间（毫秒）
#define SOUND_INTERVAL  600


//视角切换时间（毫秒）
#define VIEW_SWITCH_INTERVAL 800


//隐藏关触发条件 -- 测试版还是正式版
#define M_DEBUG

#define DIFFICULTY 6

//撞击
//被撞击以后的移动系数
#define FORCE_MOVE_INDEX 5

//撞击伤害系数 -- 越高伤害越低--反比关系
#define RAM_DMG_X 30

//爆炸
#define INI_EXPLOSE_DMG_X  1 //初始爆炸系数（反比 越低越大 最低为1
#define EXPLOSE_RANGE  350  //爆炸作用范围
//目前爆炸伤害是一次线性关系


//受重创后画面颜色改变时间
#define STUNE_TIME  1500
//受击穿伤害后颜色改变时间
#define SHOCK_TIME 1000


//#define ENDING2

//枚举
//行进方向 和 指令方向类 因此 有 五个方向 上下左右 和 停止
enum Orient{UP, DOWN, LEFT, RIGHT, STOP}; //上下左右 停车（这里面停车要花时间）


//被击中的方向  侧面 前面 后面
enum HitOrient{SIDE, FRONT, BEHIND}; //侧面 正面 背后


//坦克单位  AI 类型
// 从前往后 依次为  玩家自己操作  普通随机开炮和行进   突袭指定目标    在指定范围内游击（有敌人进入一定范围内开始追踪攻击 否则 随机移动开炮）   根据敌方人数的多少 自动切换 进攻和防守策略
// 不动   炮塔策略 -- 只转向不移动  位置重合的时候开炮    佯攻策略  攻击敌人时先进行追击 距离小于等于一定范围将停车站撸     保护关键目标策略 -- 始终不会和关键目标脱离一定距离
enum Recognization {PLAYER, NORMAL, ELITE, VP, MASTER, NOOB, TURRET, PROTEND, PROTECT}; // NOOB是不动的  VP 采取防守策略 MASTER采取攻防兼备的策略 TURRET是炮塔采取的攻击策略 //佯攻


//关卡进程
// 准备阶段 （剧本 和 胜利条件 浏览）   战斗阶段   战后阶段--战斗总结和奖励领取
enum Process {Prepare, FIGHT, After};


//胜利条件
enum Victory_type {V_TLE, V_KVP, V_STD, V_KNE}; // 熬过指定时间    消灭指定目标   消灭全部敌人（其他三种胜利 也 支持 这种胜利）  消灭一定数目的敌军（和友方协力）
//失败条件
enum Defeated_type {D_TLE, D_LVP, D_STD, D_LNA, D_NSH, D_DLD}; // 指定时间内没有完成任务   关键目标被对方摧毁   玩家坦克被摧毁   失去一定数目的友军  弹药用完了 造成的伤害不够


//单位图标
//德军三号坦克  英军丘吉尔坦克 T34坦克   炮塔   虎式坦克 虎式后期型   斯大林二型  斯大林三型
enum UnitType {G_T1, UK_T1, US_T1, USSR_T1, Turret, G_T2, G_T2_B, USSR_T3, USSR_T4}; // 单位类型 --- 图标的绘制


//音效类型
enum Sounds {FRONT_HIT_SOUND, SIDE_HIT_SOUND, BEHIND_HIT_SOUND, FIRE_SOUND, EXPLOSE_SOUND};


//播报类型
enum BoardCast {KILL, DOUBLE_KILL, KILLING_SPREE, RUNPAGE, UNSTOPPABLE, DOMINATING, GOD_LIKE, LEGENDARY};


//炮弹击中以后的效果
enum ShootResult {UNPENERTRATE, PENERTRATED, EFFECTIVE_PENERTRATED};

//损害汇报
enum DamageReport {ENGINE_DAMAGED, ENGINE_REPAIRED, GUN_DAMAGED, GUN_REPAIRED};


class Shell
{
public:
	//位置信息
	int pos_x;
	int pos_y;
	//方向信息 
	Orient orient; //炮弹方向
	int speed; //炮弹速度
	int distance; //飞行距离
	int d_cut; //飞出补正
	int disprecision; //偏差值

	Shell();//默认构造函数
	Shell(int x, int y, Orient init_orient, int init_speed);//构造函数
};


// 抽象基类 -- 坦克 （如果需要实现 必然是 NPC 的 坦克 或者 玩家的坦克
class Tank
{
public:
	//位置信息
	int pos_x;
	int pos_y;
	//方向信息
	Orient  orient; //坦克朝向
	//机动性信息
	clock_t route_interval; //转向间隔
	clock_t last_route;  //上一次转向时间
	//速度信息
	int Max_Speed;
	int Current_Speed;
	//加速度
	int Accelerate_Power;

	//状态信息
	int is_hit; //（本帧被击中）
	int last_hit;  //  上次被击中的伤害数字  --- 用来记录伤害进行绘制
	clock_t t_last_hit;   // 上一次被击中时间  用于判定是否绘制 伤害数字
	HitOrient last_hit_orient; //  上一次被击中的方向 --  用于进行击穿判定
	ShootResult last_hit_result; //  上一次击穿情况  -- 用于判定伤害数字绘制的颜色
	Orient last_hit_from; //上一发命中炮弹从哪个方向来

	clock_t t_last_effect_penertrated; //上次被有效击穿时间
	clock_t t_last_penertrated;//上次被击穿时间
	//控制信息
	int fire_command; //开火是瞬间指令 还是需要消息循环 （无奈）
	Orient  command; //方向控制指令

	//鼓掌状态变量
	int is_engine_damage;
	int is_gun_damage;


	//防护与穿深
	int penertrate_level; //炮弹穿透力
	int ammor_level;//正面装甲强度
	int side_ammor_level; //侧面装甲强度
	int behind_ammor_level; //背面装甲强度

	//火力信息
	int  damage; //炮弹伤害
	int fire_speed; // 炮弹初速
	int fire_range; //射程
	int precision; //火炮精度

	//发射信息
	clock_t  fire_interval; //发射间隔
	clock_t  last_fire;  //上一次发射时刻  
	int  shell_on_field; //是否有炮弹在场上
	Shell  shell_infor; //炮弹具体信息


	// 生存信息
	int max_hitpoint;  // 最大生命值
	int current_max_hitpoint; // 当前最大生命值
	int current_hitpoint; // 当前生命值 
	int restore_per_update; //每帧恢复的生命值
	clock_t die_time; //死亡时间
	int is_explose; //死亡后是否爆炸了

	//识别信息
	Recognization rc; // AI 类型识别 或者是玩家
	UnitType icon;    //  图标信息
	char name[30];   //名称
	int is_on_field; //识别信息 用于检测是否在场上

	//道具信息  --  暂时没有使用
	int gold;
	int total_kill;

	//防护能力补充
	int penertrated_detonation_rate;
	int effective_penertrated_detonation_rate;
	int engine_damage_rate;
	int gun_damage_rate;

	//本关表现信息
	int kill;       // 击杀数量
	int dmg_recv;  // 潜在伤害
	int dmg_cause;  // 有效伤害


public:
	//接收控制信息函数
	virtual void try_fire(void) = 0; //尝试开火
	virtual void Tank_Control_Normal(void) = 0; //控制函数 用于控制坦克在画面更新时候的表现


	//操作处理函数
	void Tank_Move(void); //移动函数
	void Tank_Route(void); //转向函数
	void jam_process(void); //用于处理撞墙现象

	//炮弹处理函数
	void shells_move(void); // 炮弹移动函数
	void out_process(void); //判断 是否出界

	//河流碰撞检测
	void Check_Block_By_River(void);

};

class Player_Tank :public Tank
{
	//静态变量  --- 游戏全局信息
public:
	static int difficulty;// 难度 0 - 2  简单 普通 困难  -1 作弊
	static int use_shell; //每关 炮弹的用量
	static int is_choice;  //  是否选择了难度 
	static int upgrade_generation;  // 恢复是否升级
	static int upgrade_engine;  // 引擎是否升级
	static int upgrade_command;  //  小队指令是否解锁
	static int upgrade_gun;  //主炮再装填是否解锁
	static int energy;   // 能量
	static int kill_stack;  // 连杀记录
	static clock_t last_kill;  // 上一次完成击杀的时间
public:
	clock_t t_last_effect_hit;//用于记录回复是否中断 NPC没有
	clock_t t_last_fital_hit; // 用于记录 轮机是否恢复 NPC没有
	clock_t t_last_gun_hit; // 用于记录  主炮是否恢复NPC没有

	//用于记录恢复buff 或 nerff后的状态 
	int max_damage;         //初始伤害
	int fastest_fire_interval;  //初始射速
	int init_max_speed;  //初始速度
	int init_fastest_route_interval;  // 初始转向间隔
	int init_accelerate_power;  // 初始加速度

public:
	Player_Tank(); //构造函数

	//控制消息传递函数 -- 虚函数重写
	void Tank_Control_Normal(void);
	void try_fire(void);

};
class NPC_Tank: public Tank
{
public:
	NPC_Tank();
	NPC_Tank(int hp, int damage, int fire_interval = 800, int Maxspeed = 25, int accerelerate = 7);

	void try_fire(void);

	
	//智能中的目标选择 需要 依靠 Dlg中的 commandupdate实现

	//普通人工智能 随机 攻击 和 移动
	void Tank_Control_Normal(void);
	
	//高级人工智能 --- 能攻击敌人后 停车正面硬打
	void Tank_Control_Ambush(int x, int y);

	//高级人工智能 -- 穷追猛打 -- 第一个目标随机 之后 选择最近的目标
	void Tank_Control_ELITE(int x, int y);

	//每次选择最近的目标  只有最近的目标靠的足够近的时候才会发动
	void Tank_Control_VP(int x, int y);

	//炮塔策略 选择最近的目标 瞄准 其 最近的方向
	void Tank_Control_Turret(int x, int y);

	//保护策略 保护选定的目标 （在其周围） 攻击策略： 攻击最近的敌军 并冲向他
	void Tank_Control_Protect(int p_x, int p_y, int x, int y);

public:
	static int  AIM_RANGE;
	static int CLOSE_RANGE; 
    static int ALERT_RANGE;
	static int TRIGGER_RANGE;

//智能目标选择的参数记录
	int target_index; // -1 代表 玩家 0 - n-1 代表第n+1个机器人
	int protect_index; //-1 代表  玩家 同上
	
	int Vp_range; // VP 触发进攻的范围
	int pretend_range; // 对攻 保持的距离
};

//炮弹命中判定
int  Shell_try_hit(Tank& attacker, Tank& target);
//命中返回命中距离 否则返回-1


//炮弹命中处理
void  Shell_hit(Tank& attacker, Tank& target);



//每关表现排序函数
bool rank(NPC_Tank& infor1,  NPC_Tank& infor2);

//撞击判断与处理函数
int  try_ram(Tank& tank1, Tank& tank2);




// ========================================音频播放管理器===================================== // 

//音效播放播放器
void my_sound_player(Sounds sd);

//击杀播报播放器
void kill_stack_broadcast_player(BoardCast bc);

//战斗音乐播放器
void battle_bgm_player(int stage);

//前背景音乐播放器（准备阶段音乐播放器）
void prepartion_bgm_player(int stage);

//后背景音乐播放器（关卡完成阶段音乐播放器）
void after_bgm_player(int stage);
//336行

//受损及恢复音效
void damage_report(DamageReport infor);
