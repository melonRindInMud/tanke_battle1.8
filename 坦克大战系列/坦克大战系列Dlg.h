
// 坦克大战系列Dlg.h : 头文件
//

#pragma once

#include "resource.h"
#include "my_resource.h"
#include "MQuestDialog.h"
#include "M_HelpDialog.h"
#define DIALOG_WIDTH  1900
#define DIALOG_HEIGHT 1040





// C坦克大战系列Dlg 对话框
class C坦克大战系列Dlg : public CDialogEx
{
// 构造
public:
	C坦克大战系列Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog(); // 初始化函数 
public:
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);  // 在具体的函数中有  -- 不在赘述
	afx_msg void OnPaint();   
	afx_msg HCURSOR OnQueryDragIcon();  
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	DECLARE_MESSAGE_MAP()

	virtual BOOL PreTranslateMessage(MSG* pMsg);   //  消息循环影响函数


	//逻辑存储 坦克们 -- 注意 炮弹类型是附属于 坦克的 所以 体现不出来
	Player_Tank tank1;  // 自身坦克
	NPC_Tank enemy_tanks[500]; //敌方
	NPC_Tank allience_tanks[500];//友方
#ifdef USE_ALLIENCE
#endif

	//曾经做出的功能 炸弹 但是由于过于影响关卡平衡性后来被删掉了
	int boomb;//炸弹数量

	//绘图使用
	
	//第一部分 DC 
	//后台DC 和 内存DC
	//
public:

	CDC tempDC;
	CDC* spDC;
	CDC memDC; //背景DC
	CDC memDC2; //第二个背景DC
	CDC supportDC;  //后台DC
	CDC stateDC; // 状态栏DC
	CDC* pDC;  // 前台DC
	CDC pictureDC;      //  图片DC （动态 不断更新使用）
	CDC bkresouceDC;  // 背景资源DC 
	CDC bkresouceDC2;  // 背景资源DC 
	CDC blackBackDC;// 黑背景DC
	CDC redBackDC; //红背景DC
	CDC temp_DC; //用来临时绘制一些物件 像素不能超过500 * 500

	//第二部分 图片 和 用于兼容内存 DC 的 画布
	//第二部分第一分部 画布
	CBitmap dcbk; //背景DC 画布
	CBitmap dcbk2; //第二张背景 画不
	CBitmap supportbk;
	CBitmap stateDCbk;
	CBitmap bkbmp;
	CBitmap bkbmp2;
	CBitmap blackBackBmp;//黑背景 画布
	CBitmap redBackBmp; //红背景画布
	CBitmap temp_DCBmp; //临时DC画布




	//第二分部  资源图像
	CBitmap subviewbk;
	CBitmap hit;  //  被击中的图标 -- 后期需要使用拼接技术
	CBitmap boom; // 被摧毁图标
	CBitmap tnt; // 炸弹图标
	CBitmap pro_clt; //进度条风格图像
	CBitmap main_hor_bkg; //主视角背景风格
	CBitmap prepare_bk; //准备阶段背景图
	CBitmap frost_bk; //森林背景图
	CBitmap grass_bk; //草地背景图
	CBitmap darkness_bk; //黑暗背景图
	CBitmap city_bk; //城市
	CBitmap tg_bk; //训练场
	CBitmap defense_bk; //要塞
	CBitmap town_bk; //城镇

	CBitmap tank_shadow; //坦克影子

	CBitmap enemy_infor; //敌方数量
	CBitmap allience_infor; //盟友数量
	CBitmap player_name; //玩家名字
	CBitmap fire_effect; //开火后的炮口特效
	CBitmap hor_state; //视线碎裂程度


	//坦克履带压过的痕迹
	CBitmap move_hint_up_down;  
	CBitmap move_hint_left_right; 


	CBitmap hit_up; 
	CBitmap hit_down;
	CBitmap hit_right;
	CBitmap hit_left;

	//不同国家坦克图标 -- 都有对应的原画
	//坦克不同方向图标  -- 坦克原型车
	CBitmap Tank_Up;
	CBitmap Tank_Down;
	CBitmap Tank_Left;
	CBitmap Tank_right;
	//德军坦克
	CBitmap Tank1_Up;
	CBitmap Tank1_Down;
	CBitmap Tank1_Left;
	CBitmap Tank1_right;
	//英军 法军  波军 坦克
	CBitmap uk_tank1_Up;
	CBitmap uk_tank1_Down;
	CBitmap uk_tank1_Left;
	CBitmap uk_tank1_right;
	//炮塔
	CBitmap Turret_Up;
	CBitmap Turret_Down;
	CBitmap Turret_Left;
	CBitmap Turret_Right;
	//苏军坦克
	CBitmap ussr_tank1_Up;
	CBitmap ussr_tank1_Down;
	CBitmap ussr_tank1_Left;
	CBitmap ussr_tank1_right;
	//苏军坦克3   斯大林二型
	CBitmap ussr_tanks3_Up;
	CBitmap ussr_tanks3_Down;
	CBitmap ussr_tanks3_Left;
	CBitmap ussr_tanks3_right;
	//苏军坦克4  斯大林三型
	CBitmap ussr_tanks4_Up;
	CBitmap ussr_tanks4_Down;
	CBitmap ussr_tanks4_Left;
	CBitmap ussr_tanks4_right;
	//德军 虎式
	CBitmap G_T2_Up;
	CBitmap G_T2_Down;
	CBitmap G_T2_Left;
	CBitmap G_T2_right;
	//德军 虎式北非涂装
	CBitmap G_T2_B_Up;
	CBitmap G_T2_B_Down;
	CBitmap G_T2_B_Left;
	CBitmap G_T2_B_right;
	// 炮弹 免疫 图标 
	CBitmap shell; //敌方炮弹图标
	CBitmap shell_f;  // 友方炮弹图标
	CBitmap immue;  // 免疫图标
	//不利状态附加图标
	CBitmap engine_damage; // 引擎损坏图标
	CBitmap gun_damage;  // 主炮损坏图标
	//河流图像
	CBitmap river_bitmap;

	//失败图像
	CBitmap defeat_map;
	//胜利图像
	CBitmap victory_map;

	//坦克光影效果
	CBitmap tank_light_effect;

	//标志
	CBitmap logo;
	

	//字体
	CFont f;    //  故事叙述 和 正文所用字体
	CFont fbig; 
	CFont fdmg;  // 伤害值显示 所用字体
	CFont ftitle;  //  标题所用字体

	//重要时间点记录
	clock_t Dialog_current_clock; // 对话框级  当前 战斗进程 时刻   ————重要
	clock_t immune_to;  //自身坦克免疫时间  --- 每关开始坦克都有四秒钟的免疫
	clock_t stage_begin_time; // 当前关卡开始的时间
	clock_t last_allience_send; //上次友军到达时间  -- 用于多波次 友军出现的关卡
	clock_t last_enemy_send; // 上次敌军到达时间  --  同上
	clock_t gun_up_to; // 主炮再装填继续到达时间

	//连杀播报

	//中文键盘存储信息
	HKL my_old_layout;


	//关卡信息（局部静态信息） 统观信息
	int NUM_OF_ENEMY; //本关敌方人数
	int NUM_OF_ALLIENCE;//本关友方人数
	int NUM_OF_TEAMMATE; //本关小队人数
	//当前关卡失败 胜利 条件
	Victory_type c_v_t;
	Defeated_type c_d_t;
	int  v_addtion_param; //胜利附加项 
	int  d_addtion_param; //失败附加项 -- 
	int  v_addtion_time; //时间胜利追加项 
	int  d_addtion_time;
	//存盘效果  -- 如果 打不过会自动重来的  -- 游戏每关第一次开始时 会自动记录 信息为静态的 直到下一关的开始
	Player_Tank player_at_stage_begin; //关卡初始状态

	//局部动态信息
	int enemys; //当前敌方人数
	int alliences; // 当前友方人数
	//剧情使用 不同关卡效果不同
	int allience_is_send; //当前友方派送波数信息
	int h;  // 当前敌方 场上是否有人 以及派送的综合信息 （是一个综合性变量 所以 命名有点奇怪）
	int a_h; // 当前友方 .... 场上是否有人等...

	//当前  所有敌军人数 （ 场面上和场面下 存活的
	int all_enemys;
	int all_alliences;
	//小队指令 -- 开启小队指令以后 用 这个变量记录小队指令
	int instruct;


	//游戏全局信息 -- 还有一个 是否开始 在 pretranlatemsg 中 做 局部静态变量 但是 地位是一样的 不过 访问级别不一样
	int current_stage; // 当前关卡
	Process process; //当前进程


	//由于时间紧急  升级免费升级选项系统并没有开发
	int buy_free_access; //当前获得免费升级效果 

	//视角
	Orient view_orient;  //当前视角 
	Orient last_view_orient;  //之前视角

	//关卡名称
	string stage_name;

	//多媒体计时器编号
	MMRESULT g_wTimerID;



	//初始化模块
	void init_multi_media(void); // 初始化图像 并播放音乐 （无论执行几关这个函数都执行一遍）
	void init_difficulty_info(void); //选择难度后 将 难度刻在 stateDC 上
	void init_start_Draws(void);


	//关卡信息初始化函数
	void stage_init_tank(int stage); // 关卡初始化敌方


	//关卡事件询问
	void Query_Events(void);

	//动画更新函数 战斗部分画面更新
	void Battle_Update_Control(void); //动画更新主函数
	//战斗进程 逻辑更新函数  炮弹逻辑更新
	void Shells_Update(void); //炮弹逻辑更新 包括 炮弹移动 和 是否击中 目标
	//战斗进程 逻辑更新函数  玩家 和 模拟 AI 的指令更新
	void Command_Update(void); // 先包含 炮弹集中以后 的判断   然后再 坦克移动 开炮操作更新


    // 画面更新  主画面更新 辅助画面更新
	void Draw_Update(void); //主画面更新
	void SubView_Update(void); //状态栏更新

	//战斗进程逻辑更新函数 -- 胜负判定
	int Win_Lose_Judge(void);//胜负判定

	//游戏进程更新 -- 战斗区间剧本更新
	void Process_Show(void); // 关卡之间的信息

	//CG绘画
	void CG_Draw(int k);

	//剧本读取函数
	//故事剧本现在从外部文件读取
	void Story_Information_Presentor(int stage);

	//完成时候的界面整体绘制
	void Stage_Complete_Draw(int stage);
	//每关结束后的坦克升级
	void Tank_Auto_Upgrade_By_Stage(int stage);



	//战斗进程绘制函数
	//坦克图画选择并绘制
	void Tank_Graph_Drawer(Tank& tk, int p);
	//伤害数字 炮弹等附加图画绘制
	void Attach_Graph_Drawer(Tank& tk, int p);
	//火控系统
	void Draw_Fire_Control(void);
	//受创提示
	void Show_Player_Hit_Effect(void);
	//进度条绘制(除血条外)
	void Standard_Pro_Ctrl_Draw(int x, int y, int cx, int cy, int index, CDC* stylemapDC, CDC* groundDC, COLORREF bkclr, COLORREF ftclr, int transparent_degree);


	
	//状态栏绘制
	//基本信息绘制
	void StateDC_Basic_Infor_Draw(void);
	//小地图绘制
	void StateDC_Draw_Litter_Map_And_View(void);
	//附加能力绘制
	void StateDC_Additional_Ability_Draw(void);
	//特殊提示绘制 
	void StateDC_Special_Reming(void);
	//引擎主炮状态绘制
	void StateDC_Damage_State_Draw(void);



	//死亡时的溅射爆炸
	void Explose_Effect(void);


	//Openning 
	void Openning_Draw(int k);
	//Ending
	void Ending_Draw(int k);

	


};
//249行