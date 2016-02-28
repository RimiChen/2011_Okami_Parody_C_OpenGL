#include "game_Time.h"
#include "game_Var.h"

// Called by GLUT library when the special keyboard event is triggered 
void game_TimeF( int value ) 
{
	if(value == 0) return;		
/*	
	background_move+=14;
	//background_move%=1024;
	if(background_move>1024){
		background_move=1024;
	}
*/
/*
	char_move+=1;
	char_move%=4;
*/

	glutPostRedisplay();
	glutTimerFunc(timer_speed, game_TimeF, timer_flag);
}
