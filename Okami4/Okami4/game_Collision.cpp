#include "game_process.h"
#include "game_Var.h"
#include "game_Block.h"
#include "game_Collision.h"

void game_collision(void){
		//printf("now_place   (%d,%d)=%d\n",background_move+275,background_up-512+360,block_table[background_up-512+360][background_move+275]);
		int i;
		i=-30;
		while(i<35){
			if(block_table[background_up-512+387+2][background_move+280+i]==1){
				at_ground=1;
				printf("at ground\n");
				break;
			}
			i++;
		}
		if(i==35){
			at_ground=0;
			printf("in the sky\n");
		}
}