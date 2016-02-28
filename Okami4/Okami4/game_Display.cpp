#include "game_Draw.h"
#include "game_Display.h"
#include "game_Var.h"
#include "game_process.h"

void game_DisplayF(void)
{
	int pic_index=0;
	int i_for;
	/// Clear the window with current clearing color
	game_Process();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	/// Setup the viewing camera
	gluLookAt(0.0,0.0,100.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glPushAttrib(GL_COLOR_BUFFER_BIT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	/// Draw texture square
	if(game_state==0){//開場動畫
	
	}
	else if(game_state==1){//主遊戲內容
		//背景先畫!!!!
		glPushMatrix();
			pic_index=0;
			DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,background_id[pic_index],(background_inf[pic_index][3]/1024)/2*115.2+pos_x,(background_inf[pic_index][4]/512)/2*57+pos_y,0.01f,background_inf[pic_index][3],background_inf[pic_index][4]);

			//DrawObject((GLfloat)background_move/background_inf[pic_index][3],0.0f,0.0f,1.0f,1.0f,background_id[pic_index],0.0f,0.0f,0.00f,background_inf[pic_index][3],background_inf[pic_index][4]);

		glPopMatrix();
		//glPushMatrix();
			//pic_index=6;
			//DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,background_id[pic_index],(background_inf[pic_index][3]/1024)/2*115.2+pos_x,(background_inf[pic_index][4]/512)/2*57+pos_y,0.02f,background_inf[pic_index][3],background_inf[pic_index][4]);

			//DrawObject((GLfloat)background_move/background_inf[pic_index][3],0.0f,0.0f,1.0f,1.0f,background_id[pic_index],0.0f,0.0f,0.00f,background_inf[pic_index][3],background_inf[pic_index][4]);

		//glPopMatrix();

		glPushMatrix();
			pic_index=7;
			DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,background_id[pic_index],(background_inf[pic_index][3]/1024)/2*115.2+pos_x,(background_inf[pic_index][4]/512)/2*57+pos_y,0.03f,background_inf[pic_index][3],background_inf[pic_index][4]);

			//DrawObject((GLfloat)background_move/background_inf[pic_index][3],0.0f,0.0f,1.0f,1.0f,background_id[pic_index],0.0f,0.0f,0.00f,background_inf[pic_index][3],background_inf[pic_index][4]);

		glPopMatrix();
		glPushMatrix();
			pic_index=8;
			DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,background_id[pic_index],(background_inf[pic_index][3]/1024)/2*115.2+pos_x,(background_inf[pic_index][4]/512)/2*57+pos_y,0.04f,background_inf[pic_index][3],background_inf[pic_index][4]);

			//DrawObject((GLfloat)background_move/background_inf[pic_index][3],0.0f,0.0f,1.0f,1.0f,background_id[pic_index],0.0f,0.0f,0.00f,background_inf[pic_index][3],background_inf[pic_index][4]);

		glPopMatrix();
		//畫地板與障礙
		//大神0/////0
		glPushMatrix();
			//glScalef(-1.0f,1.0f,1.0f);
			//pic_index=0;
			//printf("char_id=%d  d_left[]=%d w=%d h=%d\n",char_pic_id,d_left[1],char_inf[char_pic_id][3]/char_inf[char_pic_id][0],char_inf[char_pic_id][4]);
			glTranslatef(ori_x,ori_y,0.0);
			if(char_pic_id==0){//待機
				if(direction==1){
					glScalef(-1.0,1.0,1.0);
					DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,char_id[char_pic_id],3.0,-7.0,0.10f,char_inf[char_pic_id][3]/char_inf[char_pic_id][0],char_inf[char_pic_id][4]);
				}
				else{
					DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,char_id[char_pic_id],3.0,-7.0,0.10f,char_inf[char_pic_id][3]/char_inf[char_pic_id][0],char_inf[char_pic_id][4]);
				}		}
			else if(char_pic_id==1){//走動
				if(direction==1){
					glScalef(-1.0,1.0,1.0);
					DrawObject(0.0f,(float)d_left[1]*(1.0/d_left[2]),0.0f,(float)(d_left[1]+1)*(1.0/d_left[2]),1.0f,char_id[char_pic_id],0.0,0.0,0.10f,char_inf[char_pic_id][3]/char_inf[char_pic_id][0],char_inf[char_pic_id][4]);
				}
				else{
					DrawObject(0.0f,(float)d_right[1]*(1.0/d_right[2]),0.0f,(float)(d_right[1]+1)*(1.0/d_right[2]),1.0f,char_id[char_pic_id],0.0,0.0,0.10f,char_inf[char_pic_id][3]/char_inf[char_pic_id][0],char_inf[char_pic_id][4]);
				}
			}
			else if(char_pic_id==2){//跳
				if(direction==1){
					glScalef(-1.0,1.0,1.0);
					DrawObject(0.0f,(float)d_up[1]*(1.0/d_up[2]),0.0f,(float)(d_up[1]+1)*(1.0/d_up[2]),1.0f,char_id[char_pic_id],-4.0,-22.0,0.10f,char_inf[char_pic_id][3]/char_inf[char_pic_id][0],char_inf[char_pic_id][4]);
				}
				else{
					DrawObject(0.0f,(float)d_up[1]*(1.0/d_up[2]),0.0f,(float)(d_up[1]+1)*(1.0/d_up[2]),1.0f,char_id[char_pic_id],-4.0,-22.0,0.10f,char_inf[char_pic_id][3]/char_inf[char_pic_id][0],char_inf[char_pic_id][4]);
				}
			}
			else if(char_pic_id==3){//跳
				DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,char_id[char_pic_id],0.0,-9.0,0.10f,char_inf[char_pic_id][3]/char_inf[char_pic_id][0],char_inf[char_pic_id][4]);
			}


			//char_pic_id=3;
			//DrawObject(0.0f,(float)d_left[1]*(1.0/d_left[2]),0.0f,(float)(d_left[1]+1)*(1.0/d_left[2]),1.0f,char_id[char_pic_id],0.0,0.0,0.10f,char_inf[char_pic_id][3]/char_inf[char_pic_id][0],char_inf[char_pic_id][4]);

			//DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,char_id[char_pic_id],3.0,-7.0,0.10f,char_inf[char_pic_id][3]/char_inf[char_pic_id][0],char_inf[char_pic_id][4]);

			//char_pic_id=3;
			//DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,char_id[char_pic_id],0.0,-9.0,0.10f,char_inf[char_pic_id][3]/char_inf[char_pic_id][0],char_inf[char_pic_id][4]);
	
		glPopMatrix();	/// Flush drawing commands
		//glPushMatrix();
			//char_pic_id=3;
			//DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,char_id[char_pic_id],-50.0,-15.0,0.10f,char_inf[char_pic_id][3]/char_inf[char_pic_id][0],char_inf[char_pic_id][4]);
		//glPopMatrix();
		//--------------------------------------------------------------		
		//物件

		if(flower==0){
			item_pic_id=2;
			glPushMatrix();
				//printf("i_for=%d %f\n",-45+i_for*10,0.50f+(float)i_for*0.01);
			DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,item_id[item_pic_id],187.0+pos_x,19.0+pos_y,0.40f,item_inf[item_pic_id][3],item_inf[item_pic_id][4]);
			glPopMatrix();	/// Flush drawing commands
		}
		else if(flower>0 && flower <=5){
			//開花筆劃1
			item_pic_id=2;
			glPushMatrix();
				//printf("i_for=%d %f\n",-45+i_for*10,0.50f+(float)i_for*0.01);
			DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,item_id[item_pic_id],187.0+pos_x,19.0+pos_y,0.40f,item_inf[item_pic_id][3],item_inf[item_pic_id][4]);
			glPopMatrix();	/// Flush drawing commands
			item_pic_id=9;
			glPushMatrix();
			DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,item_id[item_pic_id],188.0+pos_x,23.0+pos_y,0.41f,item_inf[item_pic_id][3],item_inf[item_pic_id][4]);
			glPopMatrix();	/// Flush drawing commands


			flower++;
		}
		else if(flower>5 && flower <=9){

			item_pic_id=2;
			//開花筆劃2
			glPushMatrix();
				//printf("i_for=%d %f\n",-45+i_for*10,0.50f+(float)i_for*0.01);
			DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,item_id[item_pic_id],187.0+pos_x,19.0+pos_y,0.40f,item_inf[item_pic_id][3],item_inf[item_pic_id][4]);
			glPopMatrix();	/// Flush drawing commands
			item_pic_id=10;
			glPushMatrix();
			DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,item_id[item_pic_id],188.0+pos_x,23.0+pos_y,0.41f,item_inf[item_pic_id][3],item_inf[item_pic_id][4]);
			glPopMatrix();	/// Flush drawing commands


			flower++;
		}
		else{
			item_pic_id=3;
			glPushMatrix();
				//printf("i_for=%d %f\n",-45+i_for*10,0.50f+(float)i_for*0.01);
			DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,item_id[item_pic_id],187.0+pos_x,19.0+pos_y,0.40f,item_inf[item_pic_id][3],item_inf[item_pic_id][4]);
			glPopMatrix();	/// Flush drawing commands
		}

		if(mon_kill==1){
				if(monster<4 && monster>=0){
					item_pic_id=14;
					glPushMatrix();
						//printf("i_for=%d %f\n",-45+i_for*10,0.50f+(float)i_for*0.01);
					DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,item_id[item_pic_id],80.0+monster+pos_x,50.0+pos_y,0.45f,item_inf[item_pic_id][3],item_inf[item_pic_id][4]);
					glPopMatrix();	/// Flush drawing commands
					item_pic_id=4;
					glPushMatrix();
						//printf("i_for=%d %f\n",-45+i_for*10,0.50f+(float)i_for*0.01);
					DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,item_id[item_pic_id],80.0+monster+pos_x,50.0+pos_y,0.45f,item_inf[item_pic_id][3],item_inf[item_pic_id][4]);
					glPopMatrix();	/// Flush drawing commands
					monster++;
				}
				else if(monster>=4 && monster <9){
					item_pic_id=14;
					glPushMatrix();
						//printf("i_for=%d %f\n",-45+i_for*10,0.50f+(float)i_for*0.01);
					DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,item_id[item_pic_id],80.0+monster+pos_x,50.0+pos_y,0.45f,item_inf[item_pic_id][3],item_inf[item_pic_id][4]);
					glPopMatrix();	/// Flush drawing commands
					item_pic_id=5;
					glPushMatrix();
						//printf("i_for=%d %f\n",-45+i_for*10,0.50f+(float)i_for*0.01);
					DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,item_id[item_pic_id],80.0+monster+pos_x,50.0+pos_y,0.45f,item_inf[item_pic_id][3],item_inf[item_pic_id][4]);
					glPopMatrix();	/// Flush drawing commands
					monster++;
				}
				else if(monster>=9 && monster <13){
					item_pic_id=15;
					glPushMatrix();
						//printf("i_for=%d %f\n",-45+i_for*10,0.50f+(float)i_for*0.01);
					DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,item_id[item_pic_id],80.0+monster+pos_x,50.0+pos_y,0.45f,item_inf[item_pic_id][3],item_inf[item_pic_id][4]);
					glPopMatrix();	/// Flush drawing commands
					monster++;
				}
				else if(monster>=13 && monster <18){
					item_pic_id=16;
					glPushMatrix();
						//printf("i_for=%d %f\n",-45+i_for*10,0.50f+(float)i_for*0.01);
					DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,item_id[item_pic_id],80.0+monster+pos_x,50.0+pos_y,0.45f,item_inf[item_pic_id][3],item_inf[item_pic_id][4]);
					glPopMatrix();	/// Flush drawing commands
					monster++;
				}			

		}
			else{
				if(monster<4 && monster>=0){
					item_pic_id=14;
					glPushMatrix();
						//printf("i_for=%d %f\n",-45+i_for*10,0.50f+(float)i_for*0.01);
					DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,item_id[item_pic_id],90.0-monster+pos_x,50.0+pos_y,0.45f,item_inf[item_pic_id][3],item_inf[item_pic_id][4]);
					glPopMatrix();	/// Flush drawing commands
					monster++;
				}
				else{
					item_pic_id=14;
					glPushMatrix();
							//printf("i_for=%d %f\n",-45+i_for*10,0.50f+(float)i_for*0.01);
					DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,item_id[item_pic_id],90.0-monster+pos_x,50.0+pos_y,0.45f,item_inf[item_pic_id][3],item_inf[item_pic_id][4]);
					glPopMatrix();	/// Flush drawing commands
					monster++;
					if(monster>8){
						monster=0;
					}
				}
			}
		if(wait_count==57){
			if(break_count>=0 && break_count<4){
				item_pic_id=17;
				glPushMatrix();
				glTranslatef(ori_x,ori_y,0.0);
				DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,item_id[item_pic_id],3.0,-7.0,0.11f,item_inf[item_pic_id][3],item_inf[item_pic_id][4]);
				glPopMatrix();
				break_count++;
			}
			else if(break_count>=4 && break_count<8){
				item_pic_id=18;
				glPushMatrix();
				glTranslatef(ori_x,ori_y,0.0);
				DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,item_id[item_pic_id],3.0,-7.0,0.11f,item_inf[item_pic_id][3],item_inf[item_pic_id][4]);
				glPopMatrix();
				break_count++;
			}
			else if(break_count>=8 && break_count<12){
				item_pic_id=19;
				glPushMatrix();
				glTranslatef(ori_x,ori_y,0.0);
				DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,item_id[item_pic_id],3.0,-7.0,0.11f,item_inf[item_pic_id][3],item_inf[item_pic_id][4]);
				glPopMatrix();
				break_count++;
			}
			else if(break_count>=12 && break_count<16){
				item_pic_id=20;
				glPushMatrix();
				glTranslatef(ori_x,ori_y,0.0);
				DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,item_id[item_pic_id],3.0,-7.0,0.11f,item_inf[item_pic_id][3],item_inf[item_pic_id][4]);
				glPopMatrix();
				break_count++;			
			}
			else if(break_count>=16 && break_count<20){
				item_pic_id=21;
				glPushMatrix();
				glTranslatef(ori_x,ori_y,0.0);
				DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,item_id[item_pic_id],3.0,-7.0,0.11f,item_inf[item_pic_id][3],item_inf[item_pic_id][4]);
				glPopMatrix();
				break_count++;			
			}
			else if(break_count>=20 && break_count<24){
				item_pic_id=22;
				glPushMatrix();
				glTranslatef(ori_x,ori_y,0.0);
				DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,item_id[item_pic_id],3.0,-7.0,0.11f,item_inf[item_pic_id][3],item_inf[item_pic_id][4]);
				glPopMatrix();
				break_count++;			
			}
			else if(break_count>=24 && break_count<28){
				item_pic_id=23;
				glPushMatrix();
				glTranslatef(ori_x,ori_y,0.0);
				DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,item_id[item_pic_id],3.0,-7.0,0.11f,item_inf[item_pic_id][3],item_inf[item_pic_id][4]);
				glPopMatrix();
				break_count++;			
			}
			else if(break_count>=28 && break_count<32){
				item_pic_id=24;
				glPushMatrix();
				glTranslatef(ori_x,ori_y,0.0);
				DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,item_id[item_pic_id],3.0,-7.0,0.11f,item_inf[item_pic_id][3],item_inf[item_pic_id][4]);
				glPopMatrix();
				break_count++;			
			}
			else if(break_count>=32 && break_count<36){
				item_pic_id=25;
				glPushMatrix();
				glTranslatef(ori_x,ori_y,0.0);
				DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,item_id[item_pic_id],3.0,-7.0,0.11f,item_inf[item_pic_id][3],item_inf[item_pic_id][4]);
				glPopMatrix();
				break_count++;
				if(break_count>=36){
					break_count=0;
				}
			}

		}
		//血條與MP
		item_pic_id=0;
			for(i_for=0;i_for<(int)ink;i_for++){
				glPushMatrix();
				//printf("i_for=%d %f\n",-45+i_for*10,0.50f+(float)i_for*0.01);
				DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,item_id[item_pic_id],-45+i_for*10,8,0.50f+(float)i_for*0.01,item_inf[item_pic_id][3],item_inf[item_pic_id][4]);
				glPopMatrix();	/// Flush drawing commands
			}
		item_pic_id=1;
			for(i_for=0;i_for<blood;i_for++){
				glPushMatrix();
				//printf("i_for=%d %f\n",-45+i_for*10,0.50f+(float)i_for*0.01);
				DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,item_id[item_pic_id],-45+i_for*13,10,0.50f+(float)i_for*0.01,item_inf[item_pic_id][3],item_inf[item_pic_id][4]);
				glPopMatrix();	/// Flush drawing commands
			}

		//火
			if(fire==-1){
				item_pic_id=13;
				glPushMatrix();
						//printf("i_for=%d %f\n",-45+i_for*10,0.50f+(float)i_for*0.01);
				DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,item_id[item_pic_id],260.0+pos_x,17.0+pos_y,0.45f,item_inf[item_pic_id][3],item_inf[item_pic_id][4]);
				glPopMatrix();	/// Flush drawing commands
			
			}
			else{
				if(fire<4 && fire>=0){
					item_pic_id=11;
					glPushMatrix();
						//printf("i_for=%d %f\n",-45+i_for*10,0.50f+(float)i_for*0.01);
					DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,item_id[item_pic_id],260.0+pos_x,17.0+pos_y,0.45f,item_inf[item_pic_id][3],item_inf[item_pic_id][4]);
					glPopMatrix();	/// Flush drawing commands
					fire++;
				}
				else{
					item_pic_id=12;
					glPushMatrix();
							//printf("i_for=%d %f\n",-45+i_for*10,0.50f+(float)i_for*0.01);
					DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,item_id[item_pic_id],260.0+pos_x,17.0+pos_y,0.45f,item_inf[item_pic_id][3],item_inf[item_pic_id][4]);
					glPopMatrix();	/// Flush drawing commands
					fire++;
					if(fire>8){
						fire=0;
					}
				}
			}
		if(wind>=1 && wind <5){
			item_pic_id=6;
			glPushMatrix();
				//printf("i_for=%d %f\n",-45+i_for*10,0.50f+(float)i_for*0.01);
			DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,item_id[item_pic_id],0.0,25.0,0.82f,item_inf[item_pic_id][3],item_inf[item_pic_id][4]);
			glPopMatrix();	/// Flush drawing commands
			wind++;
		}
		else if(wind>=5 && wind <9){
			item_pic_id=7;
			glPushMatrix();
				//printf("i_for=%d %f\n",-45+i_for*10,0.50f+(float)i_for*0.01);
			DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,item_id[item_pic_id],0.0,25.0,0.82f,item_inf[item_pic_id][3],item_inf[item_pic_id][4]);
			glPopMatrix();	/// Flush drawing commands
			wind++;
		}
		else if(wind>=9 && wind <13){
			item_pic_id=8;
			glPushMatrix();
				//printf("i_for=%d %f\n",-45+i_for*10,0.50f+(float)i_for*0.01);
			DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,item_id[item_pic_id],0.0,25.0,0.82f,item_inf[item_pic_id][3],item_inf[item_pic_id][4]);
			glPopMatrix();	/// Flush drawing commands
			if(background_move>1000){
				fire=-1;
			}
			wind++;
			if(wind>12){
				wind=0;
			}
		}

//----------------------------------------------------------
		
		//前景
		glPushMatrix();

		pic_index=1;
			DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,background_id[pic_index],(background_inf[pic_index][3]/1024)/2*115.2+pos_x,(background_inf[pic_index][4]/512)/2*57,0.96f,background_inf[pic_index][3],background_inf[pic_index][4]);

			//DrawObject((GLfloat)background_move/background_inf[pic_index][3],0.0f,0.0f,(GLfloat)1.0f/background_inf[pic_index][0],1.0f,background_id[pic_index],0.0f,0.0f,0.96f,background_inf[pic_index][3]/background_inf[pic_index][0],background_inf[pic_index][4]);
		glPopMatrix();	/// Flush drawing commands
		glPushMatrix();
			pic_index=2;
			DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,background_id[pic_index],(background_inf[pic_index][3]/1024)/2*115,(background_inf[pic_index][4]/512)/2*57,0.97f,background_inf[pic_index][3],background_inf[pic_index][4]);

			//DrawObject(0.0f,0.0f,0.0f,(GLfloat)1.0f/background_inf[pic_index][0],1.0f,background_id[pic_index],57.0f,0.0f,0.97f,background_inf[pic_index][3]/background_inf[pic_index][0],background_inf[pic_index][4]);
		glPopMatrix();	/// Flush drawing commands
		glPushMatrix();
			pic_index=3;
			DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,background_id[pic_index],(background_inf[pic_index][3]/1024)/2*115.2+pos_x,(background_inf[pic_index][4]/512)/2*57,0.98f,background_inf[pic_index][3],background_inf[pic_index][4]);

			//DrawObject((GLfloat)background_move/background_inf[pic_index][3],0.0f,0.0f,(GLfloat)1.0f/background_inf[pic_index][0],1.0f,background_id[pic_index],0.0f,0.0f,0.98f,background_inf[pic_index][3]/background_inf[pic_index][0],background_inf[pic_index][4]);
		glPopMatrix();	/// Flush drawing commands
		glPushMatrix();
			pic_index=4;
			DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,background_id[pic_index],(background_inf[pic_index][3]/1024)/2*115+57.5,(background_inf[pic_index][4]/512)/2*57,0.99f,background_inf[pic_index][3],background_inf[pic_index][4]);

			//DrawObject(0.0f,0.0f,0.0f,(GLfloat)1.0f/background_inf[pic_index][0],1.0f,background_id[pic_index],57.0f,0.0f,0.99f,background_inf[pic_index][3]/background_inf[pic_index][0],background_inf[pic_index][4]);
		glPopMatrix();	/// Flush drawing commands
		//glPushMatrix();
			//pic_index=5;
			//DrawObject(0.0f,0.0f,0.0f,1.0f,1.0f,background_id[pic_index],(background_inf[pic_index][3]/1024)/2*115,(background_inf[pic_index][4]/512)/2*57,0.99f,background_inf[pic_index][3],background_inf[pic_index][4]);

			//DrawObject(0.0f,0.0f,0.0f,(GLfloat)1.0f/background_inf[pic_index][0],1.0f,background_id[pic_index],57.0f,0.0f,0.99f,background_inf[pic_index][3]/background_inf[pic_index][0],background_inf[pic_index][4]);
		//glPopMatrix();	/// Flush drawing commands
	}
	else if(game_state==2){//結尾動畫
	
	}
	glPopAttrib();
	glutSwapBuffers();
}