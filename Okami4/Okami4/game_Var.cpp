#include "game_Var.h"

//視角
GLfloat camera_L		= 0.0f;		
GLfloat camera_R		= 800.0f;	
GLfloat camera_B		= 0.0f;		
GLfloat camera_T		= 600.0f;

int game_state=1;

float blood=5.0;
float ink=3.0;

float init_coor_x=-115.2;
float init_coor_y=-57.6;

float ori_x=-50;
float ori_y=-2;

int timer_flag = 10;

/// timer speed
int timer_speed = 100;

//視窗長度資訊  >>512*512

//背景圖資訊
int background_move=0;
int background_up=1023;
GLuint background_id[9];
//0 格數   1 每格佔幾分之一   2 現在格數   3 寬度     4 高度   5 Depth  6 Other? 
int background_inf[9][7]={
	 2      ,1                 ,1           ,2048      ,1024    ,0       ,0         
	,2      ,1                 ,1           ,2048      ,512     ,0       ,0
	,1      ,1                 ,1           ,1024      ,512     ,0       ,0
	,2      ,1                 ,1           ,2048      ,512     ,0       ,0
	,1      ,1                 ,1           ,512       ,512     ,0       ,0
	,1      ,1                 ,1           ,1024      ,512     ,0       ,0
	,2      ,1                 ,1           ,2048      ,1024    ,0       ,0         
	,2      ,1                 ,1           ,2048      ,1024    ,0       ,0         
	,2      ,1                 ,1           ,2048      ,1024    ,0       ,0         

};

//腳色資訊
//第幾畫格
int char_move=0;
//動作圖片編號
int char_pic_id=0;
GLuint char_id[4];
//0 格數   1 每格佔幾分之一   2 現在格數   3 寬度  4 高度   5 Depth  6 Other? 
int char_inf[4][7]={
	1       ,1                 ,1           ,512     ,512     ,0       ,0	
   ,4       ,1                 ,1           ,2048    ,512     ,0       ,0	
   ,8       ,1                 ,1           ,4096    ,512     ,0       ,0	
   ,1       ,1                 ,1           ,512     ,512     ,0       ,0	

};

//畫面物件
GLuint item_id[26];
//0 格數   1 每格佔幾分之一   2 現在格數   3 寬度  4 高度   5 Depth  6 Other? 
int item_inf[26][7]={
	1       ,1                 ,1           ,512     ,512     ,0       ,0	
	,1      ,1                 ,1           ,512     ,512     ,0       ,0	
	,1      ,1                 ,1           ,512     ,512     ,0       ,0	
	,1      ,1                 ,1           ,512     ,512     ,0       ,0	
	,1      ,1                 ,1           ,512     ,512     ,0       ,0	
	,1      ,1                 ,1           ,512     ,512     ,0       ,0	
	,1      ,1                 ,1           ,512     ,512     ,0       ,0	
	,1      ,1                 ,1           ,512     ,512     ,0       ,0	
	,1      ,1                 ,1           ,512     ,512     ,0       ,0	
	,1      ,1                 ,1           ,512     ,512     ,0       ,0	
	,1      ,1                 ,1           ,512     ,512     ,0       ,0	
	,1      ,1                 ,1           ,512     ,512     ,0       ,0	
	,1      ,1                 ,1           ,512     ,512     ,0       ,0	
	,1      ,1                 ,1           ,512     ,512     ,0       ,0	
	,1      ,1                 ,1           ,512     ,512     ,0       ,0	
	,1      ,1                 ,1           ,512     ,512     ,0       ,0	
	,1      ,1                 ,1           ,512     ,512     ,0       ,0	
	,1      ,1                 ,1           ,512     ,512     ,0       ,0	
	,1      ,1                 ,1           ,512     ,512     ,0       ,0	
	,1      ,1                 ,1           ,512     ,512     ,0       ,0	
	,1      ,1                 ,1           ,512     ,512     ,0       ,0	
	,1      ,1                 ,1           ,512     ,512     ,0       ,0	
	,1      ,1                 ,1           ,512     ,512     ,0       ,0	
	,1      ,1                 ,1           ,512     ,512     ,0       ,0	
	,1      ,1                 ,1           ,512     ,512     ,0       ,0	
	,1      ,1                 ,1           ,512     ,512     ,0       ,0	

};
int item_pic_id;

int flower=0;
int fire=0;
int wind=0;
int kill=0;
int monster=0;
int break_count=0;

int mon_kill=0;

//圖中心座標
GLfloat pos_x=0;
GLfloat pos_y=0;
//重力
GLfloat gravity=-1;   //if at ground ==1  gravity=0;
GLfloat now_ravity=0; 
//跳參數
int now_jump=0;
int at_ground=1;

//for picture move
GLfloat tran_x=0.0;
GLfloat tran_y=0.0;
GLfloat tran_z=0.0;

//KEY
int draw[3]={0,0,1};
int d_up[3]={0,0,8};
int d_left[3]={0,0,4};
int d_right[3]={0,0,4};

int direction=0;

int wait_count=0;

//滑鼠記錄座標
int mouse_pos[51][2]={0};
