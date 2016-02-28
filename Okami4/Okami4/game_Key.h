#ifndef _GAME_KEY_
#define _GAME_KEY_
//---------------------共通變數------------------//
//通用函式庫
#include <stdio.h>
#include <stdlib.h>
#include "../../freeglut/glut.h"			
#include "../../freeglut/freeglut_ext.h"
#include <iostream>
#include <vector>
#include <algorithm>
//kgl_貼圖函式庫
#include "./kgl/kglTexture.h"
#include "./kgl/kglGLExt.h"
#include "game_Var.h"
#include "game_Time.h"
// Called by GLUT library when the window has changed size
void game_KeyF( unsigned char,int,int);
void game_SPKeyF(int,int,int);
#endif