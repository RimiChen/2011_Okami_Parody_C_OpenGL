//�q�Ψ禡�w
#include <stdio.h>
#include <stdlib.h>
#include "../../freeglut/glut.h"			
#include "../../freeglut/freeglut_ext.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//kgl_�K�Ϩ禡�w
#include "./kgl/kglTexture.h"
#include "./kgl/kglGLExt.h"
//�ܼ�
#include "game_Var.h"
//-------------
//��l��OPENGL���A
#include "game_Init.h"
//�ϥ���L�\��
#include "game_Key.h"
//�ϥηƹ��\��
#include "game_Mouse.h"
//�C���ɶ� (Timer Function)
#include "game_Time.h"
//Reshape
#include "game_Reshape.h"
//Display
#include "game_Display.h"
//�e����
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
