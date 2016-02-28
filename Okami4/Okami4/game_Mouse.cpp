#include "game_Mouse.h"
#include "game_Var.h"

// Called by GLUT library when the mouse event is triggered 
void game_MouseF(int button, int state, int x, int y) 
{
	switch (button) 
	{
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
			//cout << "Mouse left button down" << endl;
			//printf("for check position(%d,%d)\n",x,y);
		    if(draw[0]==1){
				mouse_pos[draw[1]][0]=x;
				mouse_pos[draw[1]][1]=y;
				//printf("Mouse in (%d,%d)",mouse_pos[draw[1]][0],mouse_pos[draw[1]][1]); 
				draw[1]++;
			}
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN)
			//cout << "Mouse right button down" << endl;
			//draw[1]=0;
			//printf("for ink disapear (%d,%d)\n",x,y);
			draw[0]=0;
		break;
	default:
		break;
	}
}

