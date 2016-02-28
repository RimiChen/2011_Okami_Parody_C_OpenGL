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
	//同時要計算background_move
	if(wait_count==57){
		//printf("now break");
	}
	if(draw[0]==0){//不是畫圖模式
		//向左
		if(draw[1]>0){

			//printf("stop draw mode");
			game_Process_pos(1);
			draw[1]=0;
		}
		if(d_up[0]==0 && d_left[0]==0 && d_right[0]==0){ //沒有任何動作
			//printf("no actions");
			char_pic_id=0;
			d_left[1]=0;
			d_right[1]=0;
			if(at_ground==0){//往下掉，重力座標
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
					//處理撞到地板
			}
			else{//在地上且無動作
				wait_count++;
				if(wait_count>57){//休息
					wait_count=57;
				}
			}
		}
		else{
			char_pic_id=1;
			if(d_left[0]==1){
				//其他歸零
				direction=1;
				wait_count=0;
				d_right[1]=0;
				if(d_left[1]==0){
					//轉向
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
			//向右
			if(d_right[0]==1){
				//其他歸零
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
			//向上
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
					//跳完
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
					//跳完
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
				if(at_ground==0){//不是跳也不在地上
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
					
//處理撞到地板
				}
			}
			printf("\n");
		}
	}
	else{//進入繪圖模式
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

	//初始在275,360 
	printf("now_place   (%d,%d)=%d\n",background_move+275,background_up-512+360,monster_table[background_up-512+360][background_move+275]);
	if(mon_kill==0){//怪沒被殺死
		if(monster_table[background_up-512+360][background_move+275]!=0){//碰到怪
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