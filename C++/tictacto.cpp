//80*48
#include<fstream.h>
#include<stdlib.h>
#include<process.h>
#include<stdio.h>
#include<time.h>
#include<dos.h>
#include<string.h>
#include<graphics.h>
#include<bios.h>
#include<conio.h>
#include<iomanip.h>

unsigned key;
int len=0,count=0,foodtype=0,d,m,food_flag=0,j=0,i=0,display_count=10,
hscore_pos=0,x_index=0,y_index=0,mx,my,maze=1,speed=100;
long score=0,ti_elap=0,ti_rem=15,tot_ti=15,ti_init;
char *main_menu[]={{"1. Play"},{"2. Options"},{"3. Instruction"},
				   {"4. Hi-Score"},{"5. Exit"}};
char *game_menu[]={{"1. Mazes"},{"2. Level"},{"3. Back to Main menu"}};
char *maze_menu[]={{"1. Open"},{"2. Box"},{"3. Twisted"},
				   {"4. Return to Main menu"}};
char *level_menu[]={{"1. Beginner"},{"2. Intermediate"},{"3. Expert"},
					{"4. Return to Main menu"}};
char *m_m[]={"P","O","I","H","E"};
char *g_m[]={"M","L","B"};
char *mm[]={"O","B","T","R"};
char *lm[]={"B","I","E","R"};

int maze3_x[][14]={{2,3,4,5,6,7,8,9,10,11,12,13,14,15},
				   {25},
				   {30},
				   {37,38,39,40,41,42,43,44,45,46,47,48,49,50}};
int maze3_y[][14]={{30},
				   {2,3,4,5,6,7,8,9,10,11,12,13,14,15},
				   {27,28,29,30,31,32,33,34,35,36,37,38,39,40},
				   {20}};


  void showfood();
  void end();
  void show_game_menu();
  void show_main_menu();

enum{UP=1,RIGHT=2,DOWN=3,LEFT=4}DIRECTION,Pre_Dir;

struct
{
 unsigned x:7 ;
 unsigned y:7 ;
}coordinate[1000],tail,head,food;

inline void initialise()
{
  d=DETECT;
  initgraph(&d,&m,"e:\tc\bgi");
  cleardevice();
  mx=getmaxx();
  my=getmaxy();
}

void RESET()
{
  len=count=foodtype=food_flag=i=j=hscore_pos=x_index=y_index=0;
  display_count=10,
  speed=100;
  score=ti_elap=0;ti_rem=tot_ti=15;
  head.x=head.y=tail.x=tail.y=food.x=food.y=0;
  for(i=0;i<1000;i++)
   coordinate[i].x=coordinate[i].y=0;
}

 void showoff_food()
  {
   gotoxy(food.x,food.y);
   cout<<" ";
   food.x=food.y=0;
   showfood();
  }


int showfoodtimer(int fo_fl)
{
 if(fo_fl==1)
 {
  if(ti_rem<=0)
   {
	 showoff_food();
	 ti_rem=15;
	 food_flag=0;
   }
  else
  {
   ti_elap=((biostime(0,0L)-ti_init)/(speed/16));
   ti_rem=(tot_ti-(ti_elap));
   gotoxy(7,46);
   if(ti_rem<10)
	cout<<"0"<<ti_rem;
   else
	cout<<ti_rem;
  }
 }
 else
  {
   gotoxy(7,46);
   cout<<"  ";
  }
  return 0;
}

void showfood()
{
 int flag=0;
 re:
 food.x=random(49)+2;
 food.y=random(39)+2;
 for(i=0;i<len;i++)
 {
  if(food.x==coordinate[i].x && food.y==coordinate[i].y)
	goto re;
 }
 if(maze==3)
  {
   for(i=0;i<4;i++)
   {
	for(j=0;j<14;j++)
	{
	 if(food.x==maze3_x[i][j])
	  flag=1;
	}
	for(j=0;j<14;j++)
	{
	 if(food.y==maze3_y[i][j] && flag==1)
		goto re;
	}
   }
  }
 gotoxy(food.x,food.y);
 textcolor(RED);
 cprintf("@");
}

void showbigfood()
{
 re1:
 food.x=random(49)+2;
 food.y=random(39)+2;
 for(int j=0;j<len;j++)
 {
  if(food.x==coordinate[j].x && food.y==coordinate[j].y)
   goto re1;
 }
  textcolor(YELLOW);
  gotoxy(food.x,food.y);
  cprintf("Ú");
}

void exit()
{
	 delay(50);
	 textmode(4);
	 gotoxy(10,8);
	 cout<<"Exiting the program";
	 delay(2000);
	 exit(0);
}

void border()
{
  setcolor(GREEN);
  rectangle(2,2,mx-2,my-2);
  setcolor(RED);
  rectangle(4,4,mx-4,my-4);
  setcolor(GREEN);
  rectangle(6,6,mx-6,my-6);
  settextstyle(4,0,5);
  outtextxy(180,40,"SNAKEMAN");
  setcolor(YELLOW);
  line(165,88,440,88);
  setcolor(RED);
  line(165,90,440,90);
}


void intro_graphics()
{
  clrscr();
  initialise();

  border();
  settextstyle(3,0,3);
  setcolor(RED);
  outtextxy(130,200,"Programmed By:");
  settextstyle(1,0,3);
  setcolor(WHITE);
  outtextxy(330,200,"Manish Jain");
  outtextxy(150,235,"mkj_manishjain@yahoo.co.in");
  outtextxy(150,275,"         +91 9896455735");
  settextstyle(1,0,4);
  setcolor(RED);
  outtextxy(120,360,"Press any key to play");

  getch();
}

void showtime()
{
  char datebuf[9];
  char timebuf[9];

  _strdate(datebuf);
  _strtime(timebuf);
  gotoxy(30,45);
  cout<<" DATE       TIME";
  gotoxy(30,46);
  cout<<datebuf<<" "<<timebuf;
}

inline void showscore()
{
  gotoxy(15,45);
  cout<<"SCORE";
  gotoxy(16,46);
  cout<<score;
}

char *return_maze()
{
 switch(maze)
 {
  case 1: return ("OPEN");
  case 2: return ("BOX");
  case 3: return ("TWISTED");
 }
 return "OPEN";
}

void init()
{
  DIRECTION=Pre_Dir=RIGHT;

  gotoxy(60,30);
  cout<<"M A Z E";
  gotoxy(60,32);
  cout<<return_maze();
  gotoxy(5,45);
  cout<<"Timer";

  randomize();
  _setcursortype(_NOCURSOR);
  showtime();
  showscore();

  tail.x=10;
  tail.y=10;
  for(int i=10;i<15;i++)
  {
   coordinate[len].x=i;
   coordinate[len].y=10;
   gotoxy(coordinate[len].x,coordinate[len].y);
   cout<<char(223);
   len++;
  }
  head.x=14;
  head.y=10;

  textcolor(BLUE);
  for(i=1;i<=50;i++)
   {
	  j=1;
	  gotoxy(i,j);
	   cprintf("");
	  gotoxy(i,j+40);
	   cprintf("");
   }
  for(i=1;i<=41;i++)
   {
	  j=1;
	  gotoxy(j,i);
	   cprintf("");
	  gotoxy(j+50,i);
	   cprintf("");
   }

  showfood();
}

void show_snake(int DIRECTION)
{
   gotoxy(head.x,head.y);
   textcolor(GREEN);

   switch(DIRECTION)
   {
	case UP   :
		if(Pre_Dir==LEFT)
		  cprintf("¦");
		else
		  cprintf("Ì");
		break;
	case RIGHT:
		if(Pre_Dir==DOWN)
		  cprintf("_");
		else
		  cprintf("¯");
		break;
	case DOWN :
		if(Pre_Dir==RIGHT)
		  cprintf("Ì");
		else
		  cprintf("¦");
		break;
	case LEFT :
		if(Pre_Dir==UP)
		  cprintf("¯");
		else
		  cprintf("_");
		break;
   }
}

inline void showoff()
{
 gotoxy(tail.x,tail.y);
 cout<<" ";
}

inline void SOUND()
{
 sound(1500);
 delay(55);
 nosound();
}

void gameover()
{
 sound(1220);
 delay(500);
 nosound();

 initialise();
 border();
 settextstyle(1,0,5);
 setcolor(RED);
 outtextxy(130,180,"GAME  OVER");

 settextstyle(1,0,5);
 setcolor(BLUE);
 outtextxy(140,250,"SCORE");

 gotoxy(48,16);
 char *s;
 ltoa(score,s,10);
 outtextxy(325,250,s);

 settextstyle(4,0,5);
 setcolor(WHITE);
 outtextxy(65,350,"Wish to continue:(Y/N):");
 char ch=getche();

 if(ch=='y'||ch=='Y')
 {
  outtextxy(510,350,"Y");
  getch();
  RESET();
  initialise();
  show_main_menu();
 }
 else if(ch=='n'||ch=='N')
  {
   outtextxy(510,350,"N");
   free(maze_menu);
   free(main_menu);
   free(level_menu);
   free(game_menu);
   free(m_m);
   free(mm);
   free(lm);
   free(g_m);
   exit();
  }
}


void loadmaze()
{
 if(maze==3)
 {
  textcolor(WHITE);
  for(i=1;i<15;i++)
  {
   gotoxy(i+1,30);
   cprintf("¦");
   gotoxy(25,i+1);
   cprintf("¦");
   gotoxy(36+i,20);
   cprintf("¦");
   gotoxy(30,26+i);
   cprintf("¦");
  }
 }
}

void game()
{
  init();
  loadmaze();
  sleep(2);
  while(1)
  {
   if(bioskey(1))
   {
	 key=bioskey(0);
	 int s=key>>8;
	 if(s==1)
	  exit();
	 else
	 if(s==72)      //If UP arrow key is pressed
	 {
	  if(DIRECTION==4 || DIRECTION==2)
	   {
		 Pre_Dir=DIRECTION;
		 DIRECTION=UP;
	   }
	 }
	 else if(s==80)  //If DOWN arrow key is pressed
	 {
	  if(DIRECTION==4 || DIRECTION==2)
	   {
		 Pre_Dir=DIRECTION;
		 DIRECTION=DOWN;
	   }
	 }
	 else if(s==77)   ////If RIGHT arrow key is pressed
	 {
	  if(DIRECTION==1 || DIRECTION==3)
	   {
		 Pre_Dir=DIRECTION;
		 DIRECTION=RIGHT;
	   }
	 }
	 else if(s==75)   ////If LEFT arrow key is pressed
	 {
	  if(DIRECTION==1 || DIRECTION==3)
	   {
		 Pre_Dir=DIRECTION;
		 DIRECTION=LEFT;
	   }
	 }
   }

   if(DIRECTION==2)         //Right Key
	 head.x++;
   else if(DIRECTION==1)    //Up Key
	 head.y--;
   else if(DIRECTION==4)    //Left Key
	 head.x--;
   else if(DIRECTION==3)    //Down Key
	 head.y++;

   if(maze==1)              //OPEN maze
   {
	if(head.x>50)
	   head.x=2;
	else if(head.x<=1)
	   head.x=50;
	if(tail.x>50)
	   tail.x=2;
	else if(tail.x<=1)
	   tail.x=50;
	if(head.y>40)
	   head.y=2;
	else if(head.y<=1)
	   head.y=40;
	if(tail.y>40)
	   tail.y=2;
	else if(tail.y<=1)
	   tail.y=40;
   }

   else if(maze==2)         //BOX Maze
   {
	 if(head.x>50 ||head.y>40 ||head.x<2 ||head.y<2)
	  gameover();
   }
   else if(maze==3)        //TWISTED or SPIRAL Maze
   {
	for(i=2;i<16;i++)
	{
	 if((head.x==25 && head.y==i)||(head.x==i && head.y==30)
		||(head.x==35+i && head.y==20)||(head.x==30 && head.y==25+i))
	  {
			gameover();
	  }
	}
   if(head.x>50)
	   head.x=2;
   else if(head.x<=1)
	   head.x=50;
   if(tail.x>50)
	   tail.x=2;
   else if(tail.x<=1)
	   tail.x=50;
   if(head.y>40)
	   head.y=2;
   else if(head.y<=1)
	   head.y=40;
   if(tail.y>40)
	   tail.y=2;
   else if(tail.y<=1)
	   tail.y=40;
 }


   for(int i=0;i<len;i++)
	 {
	  if(head.x==coordinate[i].x && head.y==coordinate[i].y)
		{
		  gameover();
		}
	 }

	show_snake(DIRECTION);

	if(head.x==food.x && head.y==food.y)
	 {
		 count++;
		 if(ti_rem>5)
		   score+=(foodtype*8)+2+(foodtype*((ti_rem*3)/2));
		 else
		   score+=(foodtype*8)+2;

	  ti_rem=15;
	  SOUND();
	  food.x=food.y=0;

	  if(count==5)
	   {
		 showbigfood();
		 food_flag=1;
		 ti_init=biostime(0,0);
		 showfoodtimer(1);
		 foodtype=1;
		 count=0;
	   }
	  else
	   {
		 showfood();
		 food_flag=0;
		 foodtype=0;
	   }
	  len++;
	 }
	else
	 {
	  tail.x=coordinate[0].x;
	  tail.y=coordinate[0].y;

	  showoff();

		for(int k=0;k<len-1;k++)
		 {
			coordinate[k].x=coordinate[k+1].x;
			coordinate[k].y=coordinate[k+1].y;
		 }
	 }

	coordinate[len-1].x=head.x;
	coordinate[len-1].y=head.y;

	delay(speed);
	showtime();
	showscore();
	showfoodtimer(food_flag);

	gotoxy(64,14);
	cout<<"X-Cor Y-Cor";

	gotoxy(65,15);
	cout<<head.x<<"    "<<head.y;
  }
}

void get_level_choice()
{
 get:
 int cho=bioskey(0);
 cho=cho>>8;
 switch(cho)
 {
  case 2:
  case 48:
  case 28:
  case 79: speed=125;
		   show_main_menu();
		   break;
  case 3:
  case 23:
  case 80: speed=90;
		   show_main_menu();
		   break;
  case 4:
  case 18:
  case 81: speed=55;
		   show_main_menu();
		   break;
  case 5:
  case 19:
  case 75: show_game_menu();
		   break;
  default: goto get;
 }
}

void get_maze_choice()
{
 get:
 int cho=bioskey(0);
 cho=cho>>8;
 switch(cho)
 {
  case 2:
  case 28:
  case 24:
  case 79: maze=1;
		   show_main_menu();
		   break;
  case 3:
  case 48:
  case 80: maze=2;
		   show_main_menu();
		   break;
  case 4:
  case 20:
  case 81: maze=3;
		   show_main_menu();
		   break;
  case 5:
  case 19:
  case 75:         show_game_menu();
		   break;
  default: goto get;
 }
}

void getlevel()
{
  cleardevice();
  border();

  settextstyle(1,0,5);
  setcolor(RED);
  outtextxy(50,140,"L E V E L");

  settextstyle(3,0,5);
  for(i=0;i<4;i++)
  {
   setcolor(WHITE);
   outtextxy(67,190+(45*i),level_menu[i]);
   setcolor(RED);
   outtextxy(130,190+(45*i),lm[i]);
  }
  get_level_choice();
}


void getmaze()
{
  cleardevice();
  border();

  settextstyle(1,0,5);
  setcolor(RED);
  outtextxy(50,140,"M A Z E S");
  settextstyle(3,0,5);

  for(i=0;i<4;i++)
  {
   setcolor(WHITE);
   outtextxy(67,190+(45*i),maze_menu[i]);
   setcolor(RED);
   outtextxy(130,190+(45*i),mm[i]);
  }
  get_maze_choice();
}

void get_gm_choice()
{
 get:
 int cho=bioskey(0);
 cho=cho>>8;
 switch(cho)
 {
  case 2:
  case 50:
  case 28:
  case 79: getmaze();
		   break;
  case 3:
  case 38:
  case 80: getlevel();
		   break;
  case 4:
  case 48:
  case 81: show_main_menu();
		   break;
  default: goto get;
 }
}

void show_game_menu()
 {
  cleardevice();
  border();
  settextstyle(1,0,5);
  setcolor(RED);
  outtextxy(50,140,"G A M E  M E N U");

  settextstyle(3,0,5);

  for(i=0;i<3;i++)
  {
   setcolor(WHITE);
   outtextxy(67,190+(45*i),game_menu[i]);
   setcolor(RED);
   outtextxy(130,190+(45*i),g_m[i]);
  }
   get_gm_choice();
 }

void play()
{
 cleardevice();
 restorecrtmode();
 textmode(64);
 game();
}

void options()
{
 show_game_menu();
}

void instruction()
{
 cleardevice();
 border();
 setcolor(RED);
 settextstyle(1,0,5);
 outtextxy(50,140,"I N S T R U C T I O N S");
 settextstyle(3,0,3);
 setcolor(WHITE);
 outtextxy(60,190,"1. Move the snake using Arrow Keys -> ");
 outtextxy(60,230,"   UP, DOWN, LEFT, RIGHT");
 outtextxy(60,270,"2. Eat food (@,Ú) and make snake grow longer.");
 outtextxy(60,300,"3. You will get 2 points for (@) and");
 outtextxy(60,330,"   more points for Bonus food(Ú)");
 outtextxy(60,365,"4. Don't let it hit the walls or its tail");
 settextstyle(4,0,4);
 setcolor(RED);
 outtextxy(140,425,"Press any key to Continue");
 getch();
 show_main_menu();
}

void hiscore()
{
 cleardevice();
 border();
 setcolor(RED);
 settextstyle(1,0,5);
 outtextxy(50,140,"    H I   S C O R E");
 settextstyle(3,0,3);
 setcolor(WHITE);
 outtextxy(60,220,"Sorry! This feature is not available in this version
");
 outtextxy(60,270,"For further details, Contact  :  ");
 setcolor(GREEN);
 outtextxy(60,310,"        mkj_manishjain@yahoo.co.in");
 outtextxy(60,345,"        Mobile no.: +91 9896455735 ");
 settextstyle(4,0,4);
 setcolor(RED);
 outtextxy(140,425,"Press any key to Continue");
 getch();
 show_main_menu();
}


void get_mm_choice()
{
 get:
 int cho=bioskey(0);
 cho=cho>>8;
 switch(cho)
 {
  case 2:
  case 25:
  case 28:
  case 79: play();
	   break;

  case 3:
  case 24:
  case 80: options();
	   break;

  case 4:
  case 23:
  case 81: instruction();
	   break;

  case 5:
  case 35:
  case 75: hiscore();
	   break;

  case 6:
  case 18:
  case 76: exit();
	   break;
  default: goto get;
 }
}

void show_main_menu()
{
 cleardevice();
 border();
 settextstyle(1,0,5);
 setcolor(GREEN);
 outtextxy(60,130,"M A I N  M E N U");

 settextstyle(3,0,5);

 for(i=0;i<5;i++)
 {
 setcolor(WHITE);
 outtextxy(67,180+(35*i),main_menu[i]);
 setcolor(RED);
 outtextxy(130,180+(35*i),m_m[i]);
 }

 get_mm_choice();
}

void end()
{
  initialise();

  for(j=0;j<=2;j++)
  {
   setcolor(RED+j);
   circle(mx/2,my/2,150+j*2);
  }
  settextstyle(4,0,5);
  outtextxy(mx/2-65,my/2-20,"The End");
  getch();
  closegraph();
  restorecrtmode();
  exit(0);
}

//MAIN FUNCTION
void main()
{
  intro_graphics();
  show_main_menu();
}