#ifndef _GAME_RESHAPE_
#define _GAME_RESHAPE_
//---------------------共通變數------------------//
//通用函式庫
#include <stdio.h>
#include <stdlib.h>
#include "../../freeglut/glut.h"			
#include "../../freeglut/freeglut_ext.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//kgl_貼圖函式庫
#include "./kgl/kglTexture.h"
#include "./kgl/kglGLExt.h"
#include "game_Var.h"
#include "game_Time.h"
//初始化OPENGL狀態
#include "game_Init.h"
// Called by GLUT library when the window has changed size
void game_ReshapeF(int,int);
#endif