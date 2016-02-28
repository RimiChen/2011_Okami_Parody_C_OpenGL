#ifndef _GAME_VAR_
#define _GAME_VAR_
//---------------------硄跑计------------------//
//硄ノㄧΑ畐
#include <stdio.h>
#include <stdlib.h>
#include "../../freeglut/glut.h"			
#include "../../freeglut/freeglut_ext.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//kgl_禟瓜ㄧΑ畐
#include "./kgl/kglTexture.h"
#include "./kgl/kglGLExt.h"

//跌à
extern GLfloat camera_L;	
extern GLfloat camera_R;
extern GLfloat camera_B;
extern GLfloat camera_T;

extern int game_state;

extern float init_coor_x;
extern float init_coor_y;
extern float ori_x;
extern float ori_y;
/// flag of timer 
extern int timer_flag;
/// timer speed
extern int timer_speed;
extern float blood;
extern float ink;

extern GLuint background_id[9];
//0 计   1 –碭だぇ   2 瞷计   3 糴  4 蔼   5 Depth  6 Other? 
extern int background_inf[9][7];
extern int background_move;
extern int background_up;

extern GLuint item_id[26];
//0 计   1 –碭だぇ   2 瞷计   3 糴  4 蔼   5 Depth  6 Other? 
extern int item_inf[26][7];
extern int item_pic_id;

extern int flower;
extern int fire;

extern int wind;

extern int monster;
extern int kill;

extern int break_count;

extern int mon_kill;


extern GLuint char_id[4];
//0 计   1 –碭だぇ   2 瞷计   3 糴  4 蔼   5 Depth  6 Other? 
extern int char_inf[4][7];
extern int char_move;
extern int char_pic_id;
//瓜いみ畒夹
extern GLfloat pos_x;
extern GLfloat pos_y;
//
extern GLfloat gravity;
extern GLfloat now_ravity;
//铬把计
extern int now_jump;
extern int at_ground;

//KEY
extern int d_up[3];
extern int draw[3];
extern int d_left[3];
extern int d_right[3];

//
extern int direction;  

extern int wait_count;

//for picture move
extern GLfloat tran_x,tran_y,tran_z;
extern int mouse_pos[51][2];
#endif