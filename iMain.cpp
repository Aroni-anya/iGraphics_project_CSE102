# include "iGraphics.h"
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib,"Winmm.lib")

#define start_codx 200
#define start_cody 400

#define up 0
#define down 1
#define right 2
#define left 3

#define easy 1
#define hard 2
#define on 1
#define off 2

void homemenu();
void play_page_easy();
void instruction_page();
void difficulty_page();
void settings_page();

void start();
void snake();
void eatfood();
void biteself();
void scoreupdate();
void over();
void name_input();
void savescore();
void sound2(void);

int direction;

char homepage[100]="Game Images\\VIPER VOYAGE.bmp";
char page2[100]="Game Images\\instruction_page.bmp";
char play[200]="Game Images\\Play_button.bmp";
char pausepg[100]="Game Images\\pause_page.bmp";
char yes[100]="Game Images\\yes_button.bmp";
char resume[100]="Game Images\\resume_button.bmp";
char howplay[50]="Game Images\\How_to_play_button.bmp";
char difficulty[50]="Game Images\\Diff_button.bmp";
char settings[50]="Game Images\\Settings_button.bmp";
char highscore[50]="Game Images\\Highscore_button.bmp";
char gamebg[50]="Game Images\\play.bmp";
char snakehead[50]="Game Images\\snake_head.bmp";
char inspage[50]="Game Images\\ins_page.bmp";
char backto[50]="Game Images\\back_button2.bmp";
char gameover[50]="Game Images\\gameover.bmp";

int gamestate=1;
int pause=0;
int GameOver=0;

int diff_flag=easy;
int sound_flag=on;

//boolean variables for snake movements
bool snake_move_right = false;
bool snake_move_left = false;
bool snake_move_up = false;
bool snake_move_down = false;
int move=0;

//snake body coordinates
int head_x[100], head_y[100];
int snake_len=5;
int i;

//variable for food appearing
//int seed = time(NULL);
//srand(seed);
int food_x = 10+ (rand() % 1100);
int food_y = 10+ (rand() % 700);


char Score[1000];
int score=0;


char name[50];
int hscore=0;
char Hscore[10000];
char high_name[1000];
int name_len=0;


//bool musicintro=true;
bool musicplay=true;


void start()
{
    for(i=0; i<snake_len; i++)
    {
        head_x[i]=start_codx-i*20;
        head_y[i]=start_cody;
        if(i==0)
        {
            iSetColor(0, 0, 0);
            iFilledRectangle(head_x[0], head_y[0], 20, 20);
        }
        else
        {
            iSetColor(1+rand()%255, 1+rand()%255, 1+rand()%255);
            iFilledRectangle(head_x[i],head_y[i], 20, 20);
        }
    }
}

void snake()
{
    for(i=0; i<snake_len; i++)
    {
        if(i==0)
        {
            iSetColor(0, 0, 0);
            iFilledRectangle(head_x[i], head_y[i], 20, 20);
        }
        else
        {
            iSetColor(rand()%255, rand()%255, rand()%255);
            iFilledRectangle(head_x[i], head_y[i], 20, 20);
        }
    }
}



void eatfood()
{
    if(direction!=left){
    if(direction == right)
    {
        if(food_x>=head_x[0] && food_x<=head_x[0]+20 && food_y>=head_y[0] && food_y<=head_y[0]+20)
        {
            snake_len++;
            food_x=18+(rand()%920);
            food_y=120+(rand()%600);
            score+=10;
        }
        for(int i=snake_len-1; i>0; i--)
        {
            head_x[i]=head_x[i-1];
            head_y[i]=head_y[i-1];
            iSetColor(255, 255, 255);
            iFilledRectangle(head_x[i], head_y[i], 20, 20);
        }
        if(head_x[0]<950)
        {
            head_x[0]+=10;
            iSetColor(0, 0, 0);
            iFilledRectangle(head_x[0], head_y[0], 20, 20);
        }
        else
        {
            head_x[0]=20;
            iSetColor(0, 0, 0);
            iFilledRectangle(head_x[0], head_y[0], 20, 20);
        }
    }
    }

    if(direction!=right){
    if(direction == left)
    {
        if(food_x>=head_x[0] && food_x<=head_x[0]+20 && food_y>=head_y[0] && food_y<=head_y[0]+20)
        {
            snake_len++;
            food_x=18+(rand()%920);
            food_y=120+(rand()%600);
            score+=10;
        }
        for(int i=snake_len-1; i>0; i--)
        {
            head_x[i]=head_x[i-1];
            head_y[i]=head_y[i-1];
            iSetColor(255, 255, 255);
            iFilledRectangle(head_x[i], head_y[i], 20, 20);
        }
        if(head_x[0]>20)
        {
            head_x[0]-=10;
            iSetColor(0, 0, 0);
            iFilledRectangle(head_x[0], head_y[0], 20, 20);
        }
        else
        {
            head_x[0]=950;
            iSetColor(0, 0, 0);
            iFilledRectangle(head_x[0], head_y[0], 20, 20);
        }
    }
    }

    if(direction != down){
    if(direction == up)
    {
        if(food_x>=head_x[0] && food_x<=head_x[0]+20 && food_y>=head_y[0] && food_y<=head_y[0]+20)
        {
            snake_len++;
            food_x=18+(rand()%920);
            food_y=120+(rand()%600);
            score+=10;
        }
        for(int i=snake_len-1; i>0; i--)
        {
            head_x[i]=head_x[i-1];
            head_y[i]=head_y[i-1];
            iSetColor(255, 255, 255);
            iFilledRectangle(head_x[i], head_y[i], 20, 20);
        }
        if(head_y[0]<710)
        {
            head_y[0]+=10;
            iSetColor(0, 0, 0);
            iFilledRectangle(head_x[0], head_y[0], 20, 20);
        }
        else
        {
            head_y[0]=105;
            iSetColor(0, 0, 0);
            iFilledRectangle(head_x[0], head_y[0], 20, 20);
        }
    }
    }

    if(direction!=up){
    if(direction == down)
    {
        if(food_x>=head_x[0] && food_x<=head_x[0]+20 && food_y>=head_y[0] && food_y<=head_y[0]+20)
        {
            snake_len++;
            food_x=18+(rand()%920);
            food_y=120+(rand()%600);
            score+=10;
        }
        for(int i=snake_len-1; i>0; i--)
        {
            head_x[i]=head_x[i-1];
            head_y[i]=head_y[i-1];
            iSetColor(255, 255, 255);
            iFilledRectangle(head_x[i], head_y[i], 20, 20);
        }
        if(head_y[0]>105)
        {
            head_y[0]-=10;
            iSetColor(0, 0, 0);
            iFilledRectangle(head_x[0], head_y[0], 20, 20);
        }
        else
        {
            head_y[0]=710;
            iSetColor(0, 0, 0);
            iFilledRectangle(head_x[0], head_y[0], 20, 20);
        }
    }
    }
}


void biteself()
{
    for(i=1; i<snake_len; i++)
    {
        if(head_x[0]==head_x[i] && head_y[0]==head_y[i])
        {
            gamestate=7;
            //savescore();
            //score=0;
            iShowBMP(500, 300, gameover);
            GameOver=1;
            snake_len=5;
            move=0;
        }
    }
}

void collision()
{
    if(head_x[0]>=20 && head_x[0]<=420 && head_y[0]>=220 && head_y[0]<=250)
    {
        gamestate=7;
        //savescore();
            //score=0;
            iShowBMP(500, 300, gameover);
            GameOver=1;
            snake_len=5;
            move=0;
    }
    if(head_x[0]>=250 && head_x[0]<=280 && head_y[0]>=220 && head_y[0]<=570)
    {
        gamestate=7;
        //savescore();
            //score=0;
            iShowBMP(500, 300, gameover);
            GameOver=1;
            snake_len=5;
            move=0;
    }
    if(head_x[0]>=20 && head_x[0]<=270 && head_y[0]>=640 && head_y[0]<=670)
    {
        gamestate=7;
        //savescore();
            //score=0;
            iShowBMP(500, 300, gameover);
            GameOver=1;
            snake_len=5;
            move=0;
    }
    if(head_x[0]>=450 && head_x[0]<=480 && head_y[0]>=400 && head_y[0]<=728)
    {
        gamestate=7;
        //savescore();
            //score=0;
            iShowBMP(500, 300, gameover);
            GameOver=1;
            snake_len=5;
            move=0;
    }
    if(head_x[0]>=470 && head_x[0]<=770 && head_y[0]>=480 && head_y[0]<=528)
    {
        gamestate=7;
        //savescore();
            //score=0;
            iShowBMP(500, 300, gameover);
            GameOver=1;
            snake_len=5;
            move=0;
    }
    if(head_x[0]>=645 && head_x[0]<=675 && head_y[0]>=105 && head_y[0]<=375)
    {
        gamestate=7;
        //savescore();
            //score=0;
            iShowBMP(500, 300, gameover);
            GameOver=1;
            snake_len=5;
            move=0;
    }
    if(head_x[0]>=850 && head_x[0]<=971 && head_y[0]>=400 && head_y[0]<=430)
    {
        gamestate=7;
        //savescore();
            //score=0;
            iShowBMP(500, 300, gameover);
            GameOver=1;
            snake_len=5;
            move=0;
    }
    if(head_x[0]>=795 && head_x[0]<=825 && head_y[0]>=660 && head_y[0]<=730)
    {
        gamestate=7;
       //savescore();
            //score=0;
            iShowBMP(500, 300, gameover);
            GameOver=1;
            snake_len=5;
            move=0;
    }

}



void scoreupdate()
{
        iSetColor(255,255,255);
        iFilledRectangle(1040, 210 , 150, 30);

        iSetColor(25, 25, 112);
        iText(1025, 250, "NAME :", GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(25, 25, 112);
        iText(1125, 250, name, GLUT_BITMAP_TIMES_ROMAN_24);

        iSetColor(25, 25, 112);
        iText(1025, 215, "SCORE :", GLUT_BITMAP_TIMES_ROMAN_24);

        sprintf(Score, "%d", score);
        iText(1125, 215, Score, GLUT_BITMAP_TIMES_ROMAN_24);
}


void name_input(unsigned char key)
{
    if(key=='\r')
    {
        gamestate=2;
    }
    else if(key == '\b')
    {
        if(name_len<=0)
        {
            name_len = 0;
        }
        else
        {
            name_len--;
        }

        name[name_len]='\0';
    }

    else
    {
        name[name_len]=key;
        name_len++;
        if(name_len>50)
            name_len=50;

        name[name_len]='\0';
    }
}


void savescore()
{
    FILE *fp;
    fp=fopen("scorefile.txt","r");
    if(fp!=NULL)
    {
        fscanf(fp, "%s", &high_name);
        fscanf(fp, "%s", &Hscore);
        sscanf(Hscore, "%d", &hscore);
        printf("%s %s\n", high_name, Hscore);
        //fscanf(fp, "%s", &high_name);
        fclose(fp);
    }
    printf("running savescore\n");
    printf("%d score : %d\n", hscore, score);
    if(score > hscore)
    {
        printf("score %d", score);
        printf("Hscore %s", Hscore);
        hscore=score;
        printf("hscore = %d", hscore);
        FILE *fp;
        fp=fopen("scorefile.txt", "w");
        sprintf(Hscore, "%d", hscore);
        sprintf(high_name, "%s", name);
        fprintf(fp, "%s\n", high_name);
        fprintf(fp, "%s", Hscore);
        //fprintf(fp, "%s", high_name);
        fclose(fp);
    }
}


void name_page() //gamestate=8;
{
    iClear();
    //name_input(key);
    iShowBMP(0, 0, "Game Images//page3.bmp");
    iShowBMP2(960, 60, "Game Images//snake5.bmp",0);


    //iText(470, 430, "Please enter a name for Little Snakey", GLUT_BITMAP_HELVETICA_18);

    //iRectangle(500, 350, 200, 50);
    iSetColor(25,25,102);
    iText(620, 370, name, GLUT_BITMAP_HELVETICA_18);

    iSetColor(25, 25, 102);
    iFilledRectangle(1000, 55, 120, 30);
    iSetColor(255, 255, 255);
    iText(1000, 60, "GO BACK", GLUT_BITMAP_TIMES_ROMAN_24);
}



void homemenu()
{
    iClear();
    iShowBMP(0, 0, homepage);
    iShowBMP2(100, 500, play,0);
    iShowBMP2(100, 400, howplay,0);
    iShowBMP2(100, 300, difficulty,0);
    iShowBMP2(100, 200, settings,0);
    iShowBMP2(100, 100, highscore,0);

    iSetColor(25, 25, 102);
    iFilledRectangle(1000, 55, 120, 30);
    iSetColor(255, 255, 255);
    iText(1018, 60, "QUIT", GLUT_BITMAP_TIMES_ROMAN_24);

    //iShowBMP(960, 90, backto);

}



void play_page_easy()
{
    iShowBMP(0,0, "Game Images//bg2.bmp");

    iSetColor(255,255,255);
    iFilledRectangle(990, 0, 300, 90);

    iSetColor(255,255,255);
    iFilledRectangle(993, 0, 300, 280);

    iShowBMP2(1000, 15, "Game Images//snake5.bmp",0);

    //iShowBMP2(1000, 5, "Game Images//snake.bmp",0);


    if (pause == 1)
    {
        move = 0;
        iShowBMP(360,264,pausepg);
        iShowBMP(500,400,yes);
        iShowBMP(500,300,resume);
    }

    scoreupdate();
    //savescore();
}

void play_page_hard()
{
    iClear();

    iShowBMP(0,0, "Game Images//bg2.bmp");

    iSetColor(30,144,255);
    iFilledRectangle(20,220, 400, 30);

    iSetColor(30,144,255);
    iFilledRectangle(250,220, 30, 350);

    iSetColor(30,144,255);
    iFilledRectangle(20,640, 250, 30);

    iSetColor(30,144,255);
    iFilledRectangle(450,400, 30, 328);

    iSetColor(30,144,255);
    iFilledRectangle(470,498, 300, 30);

    iSetColor(30,144,255);
    iFilledRectangle(645,105, 30, 270);

    iSetColor(30,144,255);
    iFilledRectangle(850,400, 121, 30);

    iSetColor(30,144,255);
    iFilledRectangle(795,660, 30, 70);




    iSetColor(255,255,255);
    iFilledRectangle(990, 0, 300, 90);

    iSetColor(255,255,255);
    iFilledRectangle(993, 0, 300, 280);

    iShowBMP2(1000, 15, "Game Images//snake5.bmp",0);

    if (pause == 1)
    {
        move = 0;
        iShowBMP(360,264,pausepg);
        iShowBMP2(500,400,yes,0);
        iShowBMP2(500,300,resume,0);
    }


    scoreupdate();
    collision();
}

void instruction_page()
{
    iClear();


    iSetColor(0, 0, 102);
    iFilledRectangle(0, 0, 1200, 750);



    iShowBMP(0, 0,"Game Images//page2.bmp");
    iShowBMP2(960, 60, "Game Images//snake5.bmp",0);



    iSetColor(25, 25, 102);
    iFilledRectangle(400, 450, 10, 10);
    iSetColor(25, 25, 102);
    iText(420, 448, "Press 'INSERT' to start moving Little Snakey.", GLUT_BITMAP_HELVETICA_18);

    iSetColor(25, 25, 102);
    iFilledRectangle(400, 400, 10, 10);
    iSetColor(25, 25, 102);
    iText(420, 398, "Press 'UP ARROW', 'DOWN ARROW', 'LEFT ARROW' & 'RIGHT ARROW'", GLUT_BITMAP_HELVETICA_18);
    iText(420, 370, "to move Snakey upwards, downwards, leftwards &rightwards accordingly.", GLUT_BITMAP_HELVETICA_18);

    iSetColor(25, 25, 102);
    iFilledRectangle(400, 320, 10, 10);
    iSetColor(25, 25, 102);
    iText(420, 318, "DO NOT MAKE SNAKEY GO BACK THE SAME WAY HE CAME IN!", GLUT_BITMAP_HELVETICA_18);



    iSetColor(25, 25, 102);
    iFilledRectangle(1000, 55, 120, 30);
    iSetColor(255, 255, 255);
    iText(1000, 60, "GO BACK", GLUT_BITMAP_TIMES_ROMAN_24);

}

 void difficulty_page()
{
    iClear();

    iShowBMP(0, 0,"Game Images//page2.bmp");
    iShowBMP2(960, 60, "Game Images//snake5.bmp",0);

    iSetColor(25,25,102);
    iFilledEllipse(450, 400, 100, 30, 500);
    iSetColor(255,255,255);
    iText(420, 395, "Easy", GLUT_BITMAP_TIMES_ROMAN_24);

    iSetColor(25,25,102);
    iFilledEllipse(450, 300, 100, 30, 500);
    iSetColor(255,255,255);
    iText(420, 295, "Hard", GLUT_BITMAP_TIMES_ROMAN_24);

    if(diff_flag==easy)
    {
        iSetColor(255,105,180);
        iFilledEllipse(450, 400, 100, 30, 500);
        iSetColor(0,0,0);
        iText(420, 395, "Easy", GLUT_BITMAP_TIMES_ROMAN_24);
    }
    else if(diff_flag==hard)
    {
        iSetColor(255,105,180);
        iFilledEllipse(450, 300, 100, 30, 500);
        iSetColor(0,0,0);
        iText(420, 295, "Hard", GLUT_BITMAP_TIMES_ROMAN_24);
    }


    iSetColor(25, 25, 102);
    iFilledRectangle(1000, 55, 120, 30);
    iSetColor(255, 255, 255);
    iText(1000, 60, "GO BACK", GLUT_BITMAP_TIMES_ROMAN_24);
}

void settings_page()
{
    iClear();

    iShowBMP(0, 0,"Game Images//page2.bmp");
    iShowBMP2(960, 60, "Game Images//snake5.bmp",0);

    iSetColor(25,25,102);
    iFilledEllipse(450, 400, 100, 30, 500);
    iSetColor(255,255,255);
    iText(420, 395, "ON", GLUT_BITMAP_TIMES_ROMAN_24);

    iSetColor(25,25,102);
    iFilledEllipse(450, 300, 100, 30, 500);
    iSetColor(255,255,255);
    iText(420, 295, "OFF", GLUT_BITMAP_TIMES_ROMAN_24);

    if(sound_flag==on)
    {
        iSetColor(255,105,180);
        iFilledEllipse(450, 400, 100, 30, 500);
        iSetColor(0,0,0);
        iText(420, 395, "ON", GLUT_BITMAP_TIMES_ROMAN_24);
    }
    else if(sound_flag==off)
    {
        iSetColor(255,105,180);
        iFilledEllipse(450, 300, 100, 30, 500);
        iSetColor(0,0,0);
        iText(420, 295, "OFF", GLUT_BITMAP_TIMES_ROMAN_24);
    }


    iSetColor(25, 25, 102);
    iFilledRectangle(1000, 55, 120, 30);
    iSetColor(255, 255, 255);
    iText(1000, 60, "GO BACK", GLUT_BITMAP_TIMES_ROMAN_24);
}

void over()//
{
    iClear();

    iSetColor(255,255,255);
    iFilledRectangle(0,0, 1200, 750);

    iShowBMP(400, 300, gameover);

    iSetColor(25, 25, 112);
    iFilledRectangle(500, 200, 300, 50);
    iSetColor(255, 255, 255);
    iText(505, 217, "   OOPS!!!   YOUR SCORE: ", GLUT_BITMAP_HELVETICA_18);

    iSetColor(255, 255, 255);
    iText(740, 217, Score, GLUT_BITMAP_HELVETICA_18);

    iShowBMP2(970, 60, "game Images//snake3.bmp",0);

    iSetColor(25, 25, 102);
    iFilledRectangle(1000, 55, 120, 30);
    iSetColor(255, 255, 255);
    iText(1000, 60, "GO BACK", GLUT_BITMAP_TIMES_ROMAN_24);

    //savescore();

}

void high_page()//gamestate=9;
{
    iShowBMP(0, 0,"Game Images//page2.bmp");
    iShowBMP2(960, 60, "Game Images//snake5.bmp",0);

    iSetColor(25,25,102);
    iText(500, 400, "Snakey-'MY GREATEST WARRIOR'", GLUT_BITMAP_HELVETICA_18);

    iSetColor(25,25,102);
    iText(500, 350, high_name, GLUT_BITMAP_HELVETICA_18);

    iSetColor(25,25,102);
    iText(580, 350, Hscore, GLUT_BITMAP_HELVETICA_18);

    // Display the top five high scores


    iSetColor(25, 25, 102);
    iFilledRectangle(1000, 55, 120, 30);
    iSetColor(255, 255, 255);
    iText(1000, 60, "GO BACK", GLUT_BITMAP_TIMES_ROMAN_24);
}

/*
	function iDraw() is called again and again by the system.

	*/
//int gamestate = 1;


void iDraw() {
	//place your drawing codes here


	iClear();


	if(gamestate==1)
    {
        homemenu();
        /*if(musicintro)
        {
            PlaySound("Game Sounds\\intro.wav", NULL, SND_ASYNC | SND_LOOP);
        }*/
    }
    if(gamestate==8)
    {
        name_page();
    }

    if(gamestate==2)
    {
        /*if(musicplay)
        {
            PlaySound("Game Sounds\\playmode.wav", NULL, SND_ASYNC | SND_LOOP);
        }*/
        //scoreupdate();

        if(diff_flag==easy)
        {
            play_page_easy();
            if(move==0)
            {
                start();
                iSetColor(0, 0, 0);
                iFilledCircle(food_x, food_y, 5);
            }
            if(move==1)
            {
                snake();
                iSetColor(0,0,0);
                iFilledCircle(food_x, food_y, 5);
                biteself();
            }
        }
        if(diff_flag==hard)
        {
            play_page_hard();
            if(move==0)
            {
                start();
                iSetColor(0, 0, 0);
                iFilledCircle(food_x, food_y, 5);
            }
            if(move==1)
            {
                snake();
                iSetColor(0,0,0);
                iFilledCircle(food_x, food_y, 5);
                biteself();
            }
        }
    }
    if(gamestate==3)
    {
        instruction_page();
    }
    if(gamestate==4)
    {
        difficulty_page();
    }

    if(gamestate==5)
    {
        settings_page();
    }

    if(gamestate==7)
    {
        over();
    }

    if(gamestate==6)
    {
        high_page();
    }



	//iSetColor(255, 255, 255);
	//iFilledCircle(head_x, head_y, 10,1000);

	//iSetColor(255, 255, 0);
	//iFilledCircle(food_x, food_y, r, 1000);
}



/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my) {
	printf("x = %d, y= %d\n",mx,my);
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
		if(gamestate==1)
		{
		    /*musicintro=true;
            musicplay=false;
            PlaySound("Game Sounds\\intro.wav", NULL, SND_ASYNC );
            //PlaySound(0,0,0);*/



		    if(mx>100 && mx<300 && my>500 && my<570) {
                    gamestate=8;
                    score  = 0;
                    for(int i = 0; i < name_len; i++){
                        name[i] = 0;
                    }
                    name_len = 0;
		    /*FILE *fp;
            fp=fopen("scorefile.txt","r");
            if(fp!=NULL)
            {
            fscanf(fp, "%s", &high_name);
            fscanf(fp, "%d", &hscore);
            printf("reading %s %d\n", high_name, hscore);
            sprintf(Hscore, "%d", hscore);
            //fscanf(fp, "%s", &high_name);
            fclose(fp);*/
            //}
        }
     //playpage (namepage)
		    if(mx>100 && mx<300 && my>400 && my<470) gamestate=3; //instruction page
		    if(mx>100 && mx<300 && my>300 && my<370) gamestate=4; //difficulty
		    if(mx>100 && mx<300 && my>200 && my<270) gamestate=5;  //settings
		    if(mx>100 && mx<300 && my>100 && my<170) gamestate=6; //highscore
		    if(mx>980 && mx<1160 && my>60 && my<90) exit(1);
	        //PlaySound("Game Sounds\\playmode.wav", NULL, SND_ASYNC | SND_LOOP);
        }
		else if(gamestate==2 && pause==1)
        {
            /*musicintro=false;
            musicplay=true;
            PlaySound(0,0,0);

            PlaySound("Game Sounds\\playmode.wav", NULL, SND_ASYNC );
            /  /PlaySound(0,0,0);*/
            iPauseTimer(0);
            if(mx>500 && mx<700 && my>400 && my<470)
            {
                gamestate=1;
            }
            if(mx>500 && mx<700 && my>300 && my<370)
            {
                iResumeTimer(0);
                pause=0;
            }
        }
		else if(gamestate==3)
		{
		    /*PlaySound(0,0,0);

            PlaySound("Game Sounds\\intro.wav", NULL, SND_ASYNC );*/

		    //musicintro=true;
            //musicplay=false;
		    if(mx>980 && mx<1100 && my>60 && my<90)
		    {
                gamestate=1;
		    }
		}
		else if(gamestate==4)
		{
		    /*PlaySound(0,0,0);
            PlaySound("Game Sounds\\intro.wav", NULL, SND_ASYNC | SND_LOOP);*/

		    //musicintro=true;
            //musicplay=false;
		    if(mx>=350 && mx<=550 && my>=370 && my<=430)
            {
                diff_flag=easy;
            }

            else if(mx>=350 && mx<=550 && my>=270 && my<=330)
            {
                diff_flag=hard;
            }
		    else if(mx>980 && mx<1160 && my>60 && my<90) gamestate=1;
		}

		else if(gamestate==5)
        {
            /*PlaySound(0,0,0);
            PlaySound("Game Sounds\\intro.wav", NULL, SND_ASYNC | SND_LOOP);*/

            //musicintro=true;
            //musicplay=false;
            if(mx>=350 && mx<=550 && my>=370 && my<=430)
            {

                sound_flag=on;
                musicplay=true;
                PlaySound("Game Sounds\\playmode.wav", NULL, SND_ASYNC|SND_LOOP);
                //printf("%d",musicplay);
            }

            else if(mx>=350 && mx<=550 && my>=270 && my<=330)
            {
                sound_flag=off;
                PlaySound(0, 0, 0);
                musicplay=false;
                printf("%d",musicplay);
            }
		    else if(mx>980 && mx<1160 && my>60 && my<90) gamestate=1;
        }

        else if(gamestate==8)
        {
            if(mx>980 && mx<1160 && my>60 && my<90) gamestate=1;
        }

        else if(gamestate==6)
        {
            if(mx>980 && mx<1160 && my>60 && my<90) gamestate=1;
        }
        else if(gamestate==7)
        {
            //PlaySound("Game Sounds//gameov.wav",NULL, SND_ASYNC);
            if(mx>980 && mx<1160 && my>60 && my<90)
            {
                savescore();
                gamestate=1;
            }//gamestate=1;
        }

	}
	//if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		//place your codes here
		//x -= 10;
		//y -= 10;
	//}

}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key) {
	//if (key == 'q') {
	//	exit(0);
	//}
	//place your codes for other keys here
	//if(key == 's')
	//{
	//    x+=10;
	//}

	if(gamestate==2)
    {
        if(key==' ')
        {
            pause=1;
            //move=0;
        }
    }

    if(gamestate==8)
    {
        name_input(key);
    }

}


/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key) {

	//if (key == GLUT_KEY_END) {
	//	exit(0);
	//}
	//place your codes for other keys here

    if(key == GLUT_KEY_INSERT)
    {
        move=1;
        pause=0;
    }
    if(move==1){
	if (key == GLUT_KEY_UP)
    {
        direction = 0;
    }
    if (key == GLUT_KEY_DOWN)
    {
        direction = 1;
    }
    if (key == GLUT_KEY_RIGHT)
    {
        direction = 2;
    }
    if (key == GLUT_KEY_LEFT)
    {
        direction = 3;
    }
    }

    //name_input(unsigned char key);
}





int main() {

    FILE *fp;
    fp=fopen("scorefile.txt","r");
    if(fp!=NULL)
    {
        fscanf(fp, "%s", &high_name);
        fscanf(fp, "%s", &Hscore);
        fclose(fp);
    }

	int t_move = iSetTimer(35, eatfood);


	if(musicplay==true)
    {
        PlaySound("Game Sounds\\playmode.wav", NULL, SND_ASYNC|SND_LOOP);
    }
    else if(musicplay==false)
    {
        PlaySound(0, 0, 0);
    }



	iInitialize(1200, 750 , "VIPER VOYAGE");

	return 0;
}
