#include "game_process.h"
#include "game_draw_processing.h"
#include "game_Var.h"
#include "game_Block.h"
#include "game_Collision.h"
#include "game_monster.h"


// Called by GLUT library when the special keyboard event is triggered 
void game_Process(void) 
{
	int distance=50;
	int i_for;
	int j;
	int count;
	
	if(blood==0){
		exit(0);
	}
	//printf("process things\n");
	//printf("up=%d jump=%d left=%d right=%d draw=%d at_ground=%d wait%d ",d_up[0],d_up[1],d_left[0],d_right[0],draw[0],at_ground,wait_count);
	ink+=0.025;
	if(ink>3){
		ink=3;
	}
	//game_collision();
	//�P�ɭn�p��background_move
	if(wait_count==57){
		//printf("now break");
	}
	if(draw[0]==0){//���O�e�ϼҦ�
		//�V��
		if(draw[1]>0){

			//printf("stop draw mode");
			game_Process_pos(1);
			draw[1]=0;
		}
		if(d_up[0]==0 && d_left[0]==0 && d_right[0]==0){ //�S������ʧ@
			//printf("no actions");
			char_pic_id=0;
			d_left[1]=0;
			d_right[1]=0;
			if(at_ground==0){//���U���A���O�y��
				wait_count=0;
				//printf("now falling 1");
					background_up+=50;
					if(background_up>1023){
						background_up=1023;
					}
					game_collision();
					if(at_ground==1){
						//printf("hit1\n");
						j=background_up;
						while(j>background_up-100){
							if(block_table[j-512+387+2][background_move+280+10]==0){
								//printf("surface is at %d  but now position is %d\n",j,background_up);
								background_up=j-1;
								break;
							}
							j--;
						}
					}
					else{
						//printf("jump1\n");
					}
					pos_y=-(1023-background_up)*0.2251;
					//�B�z����a�O
			}
			else{//�b�a�W�B�L�ʧ@
				wait_count++;
				if(wait_count>57){//��
					wait_count=57;
				}
			}
		}
		else{
			char_pic_id=1;
			if(d_left[0]==1){
				//��L�k�s
				direction=1;
				wait_count=0;
				d_right[1]=0;
				if(d_left[1]==0){
					//��V
					background_move-=distance;
					if(background_move<0){
						background_move=0;
					}
					if(block_table[background_up-512+387+2][background_move+280+10]==0){
						//printf("ready to fall 1\n");
						at_ground=0;
					}
					pos_x=-background_move*0.2251;
					//pos_x+=distance;
					if(pos_x>0){
						pos_x=0;
					}
					d_left[1]++;
				}
				else if(d_left[1]==1){
					background_move-=distance;
					if(background_move<0){
						background_move=0;
					}
					if(block_table[background_up-512+387+2][background_move+280+10]==0){
						//printf("ready to fall 2\n");
						at_ground=0;
					}
					pos_x=-background_move*0.2251;
					//pos_x+=distance;
					if(pos_x>0){
						pos_x=0;
					}
					d_left[1]++;
				}
				else if(d_left[1]==2){
					background_move-=distance;
					if(background_move<0){
						background_move=0;
					}
					if(block_table[background_up-512+387+2][background_move+280+10]==0){
						//printf("ready to fall 3\n");
						at_ground=0;
					}

					pos_x=-background_move*0.2251;
					//pos_x+=distance;
					if(pos_x>0){
						pos_x=0;
					}
					d_left[1]++;
				}
				else if(d_left[1]==3){
					background_move-=distance;
					if(background_move<0){
						background_move=0;
					}
					if(block_table[background_up-512+387+2][background_move+280+10]==0){
						//printf("ready to fall 4\n");
						at_ground=0;
					}

					pos_x=-background_move*0.2251;
					//pos_x+=distance;
					if(pos_x>0){
						pos_x=0;
					}
					d_left[1]++;
				}
				else if(d_left[1]==4){
					background_move-=distance;
					if(background_move<0){
						background_move=0;
					}
					if(block_table[background_up-512+387+2][background_move+280+10]==0){
						//printf("ready to fall 5\n");
						at_ground=0;
					}

					pos_x=-background_move*0.2251;
					//pos_x+=distance;
					if(pos_x>0){
						pos_x=0;
					}
					d_left[1]=0;
				}

				d_left[0]=0;
			}
			//�V�k
			if(d_right[0]==1){
				//��L�k�s
				direction=0;
				wait_count=0;
				d_left[1]=0;
				if(d_right[1]==0){
					if(d_up[0]==1){
						//printf("in jump \n");
					}
					background_move+=distance;
					if(background_move>1023){
						background_move=1023;
					}
					if(block_table[background_up-512+387+2][background_move+280+10]==0){
						//printf("ready to fall 1\n");
						at_ground=0;
					}
					pos_x=-background_move*0.2251;
					//pos_x-=distance;
					if(pos_x<-230){
						pos_x=-230;
					}
					d_right[1]++;
				}
				else if(d_right[1]==1){
					background_move+=distance;
					if(background_move>1023){
						background_move=1023;
					}
					if(block_table[background_up-512+387+2][background_move+280+10]==0){
						//printf("ready to fall 1\n");
						at_ground=0;
					}

					pos_x=-background_move*0.2251;
					//pos_x-=distance;
					if(pos_x<-230){
						pos_x=-230;
					}
					d_right[1]++;
				}		
				else if(d_right[1]==2){
					background_move+=distance;
					if(background_move>1023){
						background_move=1023;
					}					
					if(block_table[background_up-512+387+2][background_move+280+10]==0){
						//printf("ready to fall 1\n");
						at_ground=0;
					}

					pos_x=-background_move*0.2251;
					//pos_x-=distance;
					if(pos_x<-230){
						pos_x=-230;
					}
					d_right[1]++;
				}
				else if(d_right[1]==3){
					background_move+=distance;
					if(background_move>1023){
						background_move=1023;
					}
					if(block_table[background_up-512+387+2][background_move+280+10]==0){
						//printf("ready to fall 1\n");
						at_ground=0;
					}

					pos_x=-background_move*0.2251;
					//pos_x-=distance;
					if(pos_x<-230){
						pos_x=-230;
					}
					d_right[1]++;
				}
				else if(d_right[1]==4){
					background_move+=distance;
					if(background_move>1023){
						background_move=1023;
					}
					if(block_table[background_up-512+387+2][background_move+280+10]==0){
						//printf("ready to fall 1\n");
						at_ground=0;
					}

					pos_x=-background_move*0.2251;
					//pos_x-=distance;
					if(pos_x<-230){
						pos_x=-230;
					}
					d_right[1]=0;
				}
				d_right[0]=0;
			}
			//�V�W
			if(d_up[0]==1){
				char_pic_id=2;
				wait_count=0;
				d_left[1]=0;
				d_right[1]=0;
				if(d_up[1]==0){
					d_up[1]++;
				}
				else if(d_up[1]==1){
					d_up[1]++;
				}
				else if(d_up[1]==2){
					//pos_y-=20;
					background_up-=100;
					if(background_up<512){
						background_up=512;
					}
						pos_y=-(1023-background_up)*0.2251;
						//printf("pos_y=%f",pos_y);
						d_up[1]++;
				}
				else if(d_up[1]==3){
					background_up-=50;
					if(background_up<512){
						background_up=512;
					}
					pos_y=-(1023-background_up)*0.2251;
					//printf("pos_y=%f    %f",pos_y,pos_x);
					d_up[1]++;
				}
				else if(d_up[1]==4){
					background_up-=25;
					if(background_up<512){
						background_up=512;
					}
					pos_y=-(1023-background_up)*0.2251;
					//printf("pos_y=%f    %f",pos_y,pos_x);
					d_up[1]++;
				}
				else if(d_up[1]==5){
					background_up+=25;
					if(background_up>1023){
						background_up=1023;
					}
					game_collision();
					if(at_ground==1){
						//printf("hit1\n");
						j=background_up;
						while(j>background_up-100){
							if(block_table[j-512+387+2][background_move+280+10]==0){
								//printf("surface is at %d  but now position is %d\n",j,background_up);
								background_up=j-1;
								break;
							}
							j--;
						}
					}
					else{
						//printf("jump1\n");
					}
					pos_y=-(1023-background_up)*0.2251;
					//printf("pos_y=%f    %f",pos_y,pos_x);
					d_up[1]++;
				}
				else if(d_up[1]==6){
					//����
					background_up+=50;
					if(background_up>1023){
						background_up=1023;
					}
					game_collision();
					if(at_ground==1){
						//printf("hit2\n");
						j=background_up;
						while(j>background_up-100){
							if(block_table[j-512+387+2][background_move+280+10]==0){
								//printf("surface is at %d  but now position is %d\n",j,background_up);
								background_up=j-1;
								break;
							}
							j--;
						}
					}
					else{
						//printf("jump2\n");
					}
					pos_y=-(1023-background_up)*0.2251;
					//printf("pos_y=%f    %f",pos_y,pos_x);
					d_up[1]++;
				}
				else if(d_up[1]==7){
					//����
					background_up+=100;
					if(background_up>1023){
						background_up=1023;
					}
					game_collision();
					if(at_ground==1){
						//printf("hit3\n");
						j=background_up;
						while(j>background_up-100){
							if(block_table[j-512+387+2][background_move+280+10]==0){
								//printf("surface is at %d  but now position is %d\n",j,background_up);
								background_up=j-1;
								break;
							}
							j--;
						}
					}
					else{
						//printf("jump3\n");
					}
					pos_y=-(1023-background_up)*0.2251;
					
					//printf("pos_y=%f    %f",pos_y,pos_x);
					d_up[1]=0;
					d_up[0]=0;
				}
			}
			else{
				if(at_ground==0){//���O���]���b�a�W
					//printf("now falling 2");
					background_up+=50;
					if(background_up>1023){
						background_up=1023;
					}
					game_collision();
					if(at_ground==1){
						//printf("hit1\n");
						j=background_up;
						while(j>background_up-100){
							if(block_table[j-512+387+2][background_move+280+10]==0){
								//printf("surface is at %d  but now position is %d\n",j,background_up);
								background_up=j-1;
								break;
							}
							j--;
						}
					}
					else{
						//printf("jump1\n");
					}
					pos_y=-(1023-background_up)*0.2251;
					
//�B�z����a�O
				}
			}
			printf("\n");
		}
	}
	else{//�i�Jø�ϼҦ�
		wait_count=0;
		if(draw[1]>2){
			//start process
			//printf("now_processing\n");
			game_Process_pos(3);
			draw[0]=0;
			draw[1]=0;
		}
		else{
			//printf("now draw   wait for get corrdination \n");
		}

	}

	//��l�b275,360 
	printf("now_place   (%d,%d)=%d\n",background_move+275,background_up-512+360,monster_table[background_up-512+360][background_move+275]);
	if(mon_kill==0){//�ǨS�Q����
		if(monster_table[background_up-512+360][background_move+275]!=0){//�I���
			blood=blood-1;
			char_pic_id=3;
			if(blood<0){
				blood=0;
			}
			background_move-=(distance+40);
			if(background_move<0){
				background_move=0;
			}
			if(block_table[background_up-512+387+2][background_move+280+10]==0){
				//printf("ready to fall 1\n");
				at_ground=0;
			}
			pos_x=-background_move*0.2251;
			//pos_x+=distance;
			if(pos_x>0){
				pos_x=0;
			}
			d_left[1]++;
		}
	}
	//printf("forcheck  (%2f ,%2f)   range %d~%d\n",pos_x,pos_y,background_move,background_move+1023);
	//printf("\n");
}