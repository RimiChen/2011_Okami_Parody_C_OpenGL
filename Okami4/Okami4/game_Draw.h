#ifndef _GAME_DRAW_
#define _GAME_DRAW_
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
//��l��OPENGL���A
#include "game_Init.h"
#include "game_Var.h"
#include "game_Time.h"
// Called by GLUT library when the window has changed size
void DrawObject(GLfloat,GLfloat,GLfloat,GLfloat,GLfloat,GLuint,GLfloat,GLfloat,GLfloat,GLint,GLint);
#endif