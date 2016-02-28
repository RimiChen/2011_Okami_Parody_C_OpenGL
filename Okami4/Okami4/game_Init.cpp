#include "game_Init.h"
#include "game_Var.h"
///////////////////////////////////////////////////////////
// Setup the rendering state
void InitGL(void)
{
	/// Enable texture
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	/// Really Nice Perspective Calculations
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);	
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);
	glDisable(GL_LIGHTING);


	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations

}

///////////////////////////////////////////////////////////
// Initialize textures
void InitTexture(void)
{
	string filename;

	//背景
	filename=".\\pic\\background_01_1.tga";
	background_id[0]=KFLoadText(filename , GL_RGBA);
	filename=".\\pic\\out_01.tga";
	background_id[1]=KFLoadText(filename , GL_RGBA);
	filename=".\\pic\\out_02.tga";
	background_id[2]=KFLoadText(filename , GL_RGBA);
	filename=".\\pic\\out_03.tga";
	background_id[3]=KFLoadText(filename , GL_RGBA);
	filename=".\\pic\\out_04.tga";
	background_id[4]=KFLoadText(filename , GL_RGBA);
	filename=".\\pic\\test.tga";
	background_id[5]=KFLoadText(filename , GL_RGBA);
	filename=".\\pic\\block.tga";
	background_id[6]=KFLoadText(filename , GL_RGBA);
	filename=".\\pic\\block_1.tga";
	background_id[7]=KFLoadText(filename , GL_RGBA);
	filename=".\\pic\\block_2.tga";
	background_id[8]=KFLoadText(filename , GL_RGBA);

	//人物
    
	filename=".\\pic\\char_00.tga";
	char_id[0]=KFLoadText(filename , GL_RGBA);
    filename=".\\pic\\char_01.tga";
	char_id[1]=KFLoadText(filename , GL_RGBA);
    filename=".\\pic\\char_02_2.tga";
	char_id[2]=KFLoadText(filename , GL_RGBA);
    filename=".\\pic\\char_03.tga";
	char_id[3]=KFLoadText(filename , GL_RGBA);
	
	//物件
    filename=".\\pic\\item01.tga";
	item_id[0]=KFLoadText(filename , GL_RGBA);
    filename=".\\pic\\item02.tga";
	item_id[1]=KFLoadText(filename , GL_RGBA);
    filename=".\\pic\\item03_1.tga";
	item_id[2]=KFLoadText(filename , GL_RGBA);
    filename=".\\pic\\item03_2.tga";
	item_id[3]=KFLoadText(filename , GL_RGBA);
	//kill
	filename=".\\pic\\item04_1.tga";
	item_id[4]=KFLoadText(filename , GL_RGBA);
	filename=".\\pic\\item04_2.tga";
	item_id[5]=KFLoadText(filename , GL_RGBA);
	//wind
	filename=".\\pic\\item05_1.tga";
	item_id[6]=KFLoadText(filename , GL_RGBA);
	filename=".\\pic\\item05_2.tga";
	item_id[7]=KFLoadText(filename , GL_RGBA);
	filename=".\\pic\\item05_3.tga";
	item_id[8]=KFLoadText(filename , GL_RGBA);
	//flower
	filename=".\\pic\\item06_1.tga";
	item_id[9]=KFLoadText(filename , GL_RGBA);
	filename=".\\pic\\item06_2.tga";
	item_id[10]=KFLoadText(filename , GL_RGBA);
	//fire
	filename=".\\pic\\item07_1.tga";
	item_id[11]=KFLoadText(filename , GL_RGBA);
	filename=".\\pic\\item07_2.tga";
	item_id[12]=KFLoadText(filename , GL_RGBA);
	filename=".\\pic\\item07_3.tga";
	item_id[13]=KFLoadText(filename , GL_RGBA);
	//monster
	filename=".\\pic\\monster_01.tga";
	item_id[14]=KFLoadText(filename , GL_RGBA);
	filename=".\\pic\\monster_02.tga";
	item_id[15]=KFLoadText(filename , GL_RGBA);
	filename=".\\pic\\monster_03.tga";
	item_id[16]=KFLoadText(filename , GL_RGBA);
	//break
	filename=".\\pic\\char_00_1.tga";
	item_id[17]=KFLoadText(filename , GL_RGBA);
	filename=".\\pic\\char_00_2.tga";
	item_id[18]=KFLoadText(filename , GL_RGBA);
	filename=".\\pic\\char_00_3.tga";
	item_id[19]=KFLoadText(filename , GL_RGBA);
	filename=".\\pic\\char_00_4.tga";
	item_id[20]=KFLoadText(filename , GL_RGBA);
	filename=".\\pic\\char_00_5.tga";
	item_id[21]=KFLoadText(filename , GL_RGBA);
	filename=".\\pic\\char_00_6.tga";
	item_id[22]=KFLoadText(filename , GL_RGBA);
	filename=".\\pic\\char_00_7.tga";
	item_id[23]=KFLoadText(filename , GL_RGBA);
	filename=".\\pic\\char_00_8.tga";
	item_id[24]=KFLoadText(filename , GL_RGBA);
	filename=".\\pic\\char_00_9.tga";
	item_id[25]=KFLoadText(filename , GL_RGBA);


}
void SetTexParameter()
{
	glTexParameterf ( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
	glTexParameterf ( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
	glTexParameterf ( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf ( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
}
