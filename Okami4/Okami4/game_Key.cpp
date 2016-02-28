#include "game_Key.h"
#include "game_Var.h"
// Called by GLUT library when the special keyboard event is triggered 
void game_SPKeyF( int key, int x, int y )
{
	switch( key ) {
	case GLUT_KEY_F1 :
		//cout << "This is F1 key" << endl;
		break;
	case GLUT_KEY_PAGE_UP :
		//cout << "This is PageUp key" << endl;
		break;	
	case GLUT_KEY_LEFT :
		//cout << "This is Left key" << endl;
		break;	
	}
}
// Called by GLUT library when the keyboard event is triggered 
void game_KeyF( unsigned char key, int x, int y )
{
	switch( key ) {
	case 'w' : case 'W' :
		//cout << "This is W key" << endl;
		//printf("jump=%d",now_jump);
		if(ink>=1){
			draw[0]=1;
		}
		else{
			draw[0]=0;
		}
		break;	
	case 'a' : case 'A':
		//cout << "This is A key   pos_x=" <<pos_x<< endl;
		d_left[0]=1;
		break;
	case 'd' : case 'D':
		//cout << "This is D key   pos_x=" <<pos_x<< endl;
		d_right[0]=1;
		break;
	case 32:		// SPACE		
		//cout << "This is SPACE" << endl;
		if(at_ground==1 && d_up[1]==0){   //沒在跳且在地上
			d_up[0]=1;
		}
		break;
	}
 
}

