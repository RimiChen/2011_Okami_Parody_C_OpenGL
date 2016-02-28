#include "game_Reshape.h"
#include "game_Var.h"

// Called by GLUT library when the window has changed size
void game_ReshapeF(int w, int h){

	if(h == 0) h = 1;
	// Set Viewport to window dimensions
	glViewport(0, 0, w, h);

	// Reset coordinate system
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();		

	//gluOrtho2D(camera_L, camera_R, camera_B, camera_T);

	// Use perspective projection
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 128.0);	
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	/// Setup the viewing camera
	gluLookAt(0.0,0.0,100.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}
