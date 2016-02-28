#include "game_Draw.h"
#include "game_Var.h"

void DrawObject(GLfloat start,GLfloat _tex_x1, GLfloat _tex_y1, GLfloat _tex_x2, GLfloat _tex_y2, GLuint pic_id,GLfloat x_tran,GLfloat y_tran,GLfloat z_tran,GLint pic_w,GLint pic_h)
{
	int pic_pro=512;
	float pic_fac=0.2251;
	float temp=(float)(pic_w/pic_pro)*pic_fac;
	//printf("(w,h) = (%f , %f)",temp,pic_fac);
	//printf("(w,h) = (%d , %d)",pic_w,pic_h);

	glBindTexture(GL_TEXTURE_2D, pic_id);
		//初始化系統畫面座標至0,0
		//glTranslatef(init_coor_x,init_coor_y,0.0f);
		//printf("%f",start);
		glTranslatef(x_tran,y_tran,z_tran);
		glBegin(GL_QUADS);
			glTexCoord2f(start+_tex_x1, _tex_y1);			
			glVertex2f(pic_w/2*-pic_fac , pic_h/2*-pic_fac);

			glTexCoord2f(start+_tex_x1, _tex_y2);			 
			glVertex2f(pic_w/2*-pic_fac , pic_h/2*pic_fac);

			glTexCoord2f(start+_tex_x2, _tex_y2);		
			glVertex2f(pic_w/2*pic_fac , pic_h/2*pic_fac);

			glTexCoord2f(start+_tex_x2, _tex_y1);		
			glVertex2f(pic_w/2*pic_fac , pic_h/2*-pic_fac);

		glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
}

