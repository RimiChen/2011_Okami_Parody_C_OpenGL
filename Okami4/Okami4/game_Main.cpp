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
//變數
#include "game_Var.h"
//-------------
//初始化OPENGL狀態
#include "game_Init.h"
//使用鍵盤功能
#include "game_Key.h"
//使用滑鼠功能
#include "game_Mouse.h"
//遊戲時間 (Timer Function)
#include "game_Time.h"
//Reshape
#include "game_Reshape.h"
//Display
#include "game_Display.h"
//畫物件
#include "game_Draw.h"


// Main program entry point
int main(int argc, char* argv[])
{
	/// Create a new window
	//////////////////////////////////////////////////////////
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(1024,512);
	glutCreateWindow("Simple Texture Mapping");
	//////////////////////////////////////////////////////////

	/// Register callback functions
	//////////////////////////////////////////////////////////	
	glutReshapeFunc	( game_ReshapeF );
	glutDisplayFunc	( game_DisplayF );
	glutKeyboardFunc( game_KeyF );
	glutMouseFunc	( game_MouseF );	
	glutSpecialFunc	( game_SPKeyF ); 	
	glutTimerFunc	(timer_speed, game_TimeF, timer_flag);
	//////////////////////////////////////////////////////////

	/// Create GLUT menu system
	//My_Menu();

	/// Initialize OpenGL
	InitGL();		

	/// Initialize Textures
	InitTexture();

	/// Entering main loop
	glutMainLoop();

	return 0;
}
