#ifndef _GAME_DISPLAY_
#define _GAME_DISPLAY_
//---------------------�@�q�ܼ�------------------//
//�q�Ψ禡�w
#include <stdio.h>
#include <stdlib.h>
#include "../../freeglut/glut.h"			
#include "../../freeglut/freeglut_ext.h"
#include <iostream>
#include <vector>
#include <algorithm>
//kgl_�K�Ϩ禡�w
#include "./kgl/kglTexture.h"
#include "./kgl/kglGLExt.h"
#include "game_Var.h"
#include "game_Time.h"
//��l��OPENGL���A
#include "game_Init.h"
// Called by GLUT library when the window has changed size
void game_DisplayF(void);
#endif