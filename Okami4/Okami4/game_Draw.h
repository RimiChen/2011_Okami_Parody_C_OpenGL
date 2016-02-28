#ifndef _GAME_DRAW_
#define _GAME_DRAW_
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
//初始化OPENGL狀態
#include "game_Init.h"
#include "game_Var.h"
#include "game_Time.h"
// Called by GLUT library when the window has changed size
void DrawObject(GLfloat,GLfloat,GLfloat,GLfloat,GLfloat,GLuint,GLfloat,GLfloat,GLfloat,GLint,GLint);
#endif