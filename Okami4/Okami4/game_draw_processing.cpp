#include "game_draw_processing.h"
#include "game_Var.h"
#include "game_Block.h"
#include "game_monster.h"
void game_Process_pos(int type){
	int i;
	int max=0;
	int min=0;
	int check=0;
	for(i=0;i<3;i++){
		//printf("(%d ,%d)",mouse_pos[i][0],mouse_pos[i][1]);
		if(i==0){
			min=mouse_pos[0][1];
			max=mouse_pos[0][1];
		}
		if(mouse_pos[i][1]>max){
			max=mouse_pos[i][1];
		}
		else if(mouse_pos[i][1]<min){
			min=mouse_pos[i][1];
		}
	}
	//printf("forcheck  (%2f ,%2f)   range %d~%d\n",pos_x,pos_y,background_move,background_move+1023);
	if(max-min>10){
		//printf("not kill\n");
		if(mouse_pos[0][0]<mouse_pos[1][0]){
			//printf("this is wind\n");
			if(wind==0){
				wind++;
				ink-=1;
				if(ink<0){
					ink=0;
				}
			}
			else{//¨¾¤î­«½Æµe­·
				wind=1;
				ink-=1;
				if(ink<0){
					ink=0;
				}
			}
		}
		else{
			//printf("this is flower\n");
			
			if(block_table[mouse_pos[0][1]+512][mouse_pos[0][0]+background_move]==2){
				//printf("blossom ok !!  \n");
				flower=1;
				ink-=1;
				if(ink<0){
					ink=0;
				}
			}
			else{
				//printf("not tree\n");
				ink-=1;
				if(ink<0){
					ink=0;
				}
			}
			
			//printf("(%d,%d,%d)",mouse_pos[0][0]+background_move,mouse_pos[0][1]+512,block_table[mouse_pos[0][1]+512][mouse_pos[0][0]+background_move]);
		}
	}
	else{
		//printf("this is kill\n");
			check=0;
			for(i=0;i<mouse_pos[2][0]-mouse_pos[0][0];i++){
				
				//printf("mouse_pos=%d ,%d",mouse_pos[0][0]+background_move+i,mouse_pos[0][1]+512);
				if(monster_table[617][mouse_pos[0][0]+background_move+i]!=0){
					check++;
					//printf("monster here");
				}	
			}
			if(check>0){
				//printf("blossom ok !!  \n");
				mon_kill=1;
				ink-=1;
				if(ink<0){
					ink=0;
				}
			}
			else{
				//printf("not tree\n");
				ink-=1;
				if(ink<0){
					ink=0;
				}
			}
			
	}


}