#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>


#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

void startgame();
void delay();
void boorder();
void gotoxy(int x, int y);
void gotoXY(int x, int y);
int spikes();
void ENDGAME();


struct coordinate {//the magic of the operation
	int x;
	int y;
	int direction;
};

typedef struct coordinate coordinate;

coordinate head, spike, spook[100];

main() {
	int i=0, time=0, e=0;
	char key = DOWN;

	startgame();
	head.x = 15;
	head.y = 20;
	boorder();// to initialize the border
	spikes();//to initialize their inevitable death
	while ((key = _getch()) != 27 && head.x != 70 && head.y != 30 && head.x != 10 && head.y != 10) /* 27 = Esc key, and the fish cannot hit the borders */
	{

		do {
		
			time++;

			gotoXY(13, 9);
			printf("%d", time);

			if (time < 100) {//difficulty increment 1
				delay();
					gotoXY(spook[1].x, spook[1].y);
					printf("%c", 207);	
			}
			if (time < 200) {//difficulty increment 2
						
							delay();
			}
			if (time < 300) {//difficulty increment 3
				delay();
				gotoXY(spook[6].x, spook[6].y);
				printf("%c", 207);
				gotoXY(spook[7].x, spook[7].y);
				printf("%c", 207);
			}
			if (time < 500) {//difficulty increment 4
				gotoXY(spook[8].x, spook[8].y);
				printf("%c", 207);
				gotoXY(spook[9].x, spook[9].y);
				printf("%c", 207); 
				gotoXY(spook[10].x, spook[10].y);
				printf("%c", 207);
				gotoXY(spook[11].x, spook[11].y);
				printf("%c", 207);
			}
				
				
			
			if (time < 1000) {//difficulty increment 5
				delay();
				gotoXY(spook[1].x, spook[1].y);
				printf("%c", 207);
				gotoXY(spook[2].x, spook[2].y);
				printf("%c", 207);
				gotoXY(spook[3].x, spook[3].y);
				printf("%c", 207);
				gotoXY(spook[4].x, spook[4].y);
				printf("%c", 207);
				gotoXY(spook[5].x, spook[5].y);
				printf("%c", 207);
			}
			if (time < 2000) {//difficulty increment 6
				delay();
				gotoXY(spook[12].x, spook[12].y);
				printf("%c", 207);
				gotoXY(spook[13].x, spook[13].y);
				printf("%c", 207);
				gotoXY(spook[14].x, spook[14].y);
				printf("%c", 207);
				gotoXY(spook[15].x, spook[15].y);
				printf("%c", 207);
				gotoXY(spook[16].x, spook[16].y);
				printf("%c", 207);
			}
			if (time % 100==0) {//randomizer
				spikes();
			}
			boorder();
			
				
					
					
				



			if (key == UP)
			{
				gotoxy(head.x, head.y);
				printf("%c", 94);C
				head.y--;

			}
			if (key == DOWN)
			{
				gotoxy(head.x, head.y);
				printf("%c", 118);
				head.y++;

			}
			if (key == RIGHT)

			{
				gotoxy(head.x, head.y);
				printf("%c", 431);
				head.x++;


			}
			if (key == LEFT)
			{

				gotoxy(head.x, head.y);
				printf("%c", 174);
				head.x--;

			}
			for (i = 1; i < 17; i++) {//gg by mine
				if (head.x == spook[i].x && head.y == spook[i].y) {
					system("cls");
					gotoXY(30, 7);
					printf("Your total TIME was: %d\n\n\t\t\t", time);
					system("pause");
					ENDGAME();
				}
			}
			if (head.x == 70 || head.y == 30 || head.x == 10 || head.y == 10) {//gg by wall
				system("cls");
				gotoXY(30, 7);
				printf("Your total TIME was: %d\n\n\t\t\t", time);
				system("pause");
				ENDGAME();
	}
			
		} while (!_kbhit());
	}
	
}


	void delay()//because hoomans can't move too quick
{
	int delay;
	for (delay = 0; delay < 10000000; delay++);
}

void boorder() {
	system("cls");
	int i;
	
	for (i = 10; i < 71; i++)//x border
	{
		gotoXY(i, 10);
		printf("%c", 176);
		gotoXY(i, 30);
		printf("%c", 176);
	}
	for (i = 10; i < 31; i++)//y border
	{
		gotoXY(10, i);
		printf("%c", 176);
		gotoXY(70, i);
		printf("%c", 176);
	}

}


int spikes() {//its gettin' pretty spooky
	int i;
	for (i = 0; i < 100; i++) {
		spook[i].x = rand() % 70;
		if (spook[i].x <= 10)
			spook[i].x += 11;
		spook[i].y = rand() % 30;
		if (spook[i].y <= 10)
			spook[i].y += 11;
	}
		return(spook[i].x, spook[i].y);
		
		
}

void startgame() {//start print
	gotoXY(13, 9);
	printf("WELCOME TO FISH GAME~ \n \tUse arrow keys to control the fish. \n\t Avoid the Mines and Walls\n\t");
	system("pause");
}



/* int main()
{
	int ch;

	while ((ch = _getch()) != 27) // 27 = Esc key 
	{
		printf("%d", ch);
		if (ch == 0 || ch == 224)
			printf(", %d", _getch());
		printf("\n");
	}

	printf("ESC %d\n", ch);

	return (0);
}
program to pull action keys of _getch*/






/* main()
{
	int x, y, i, d, delay;
	for (d = 25; d >0; d--) {

		for (i = 25; i > 0; i--) {
			x = d;
			y = i;
			gotoxy(x, y);
			printf("*");
		}
		for (delay = 0; delay < 100000000; delay++);
	}

	gotoxy(x, y);

	printf("*");

	system("pause");

	scanf("%d", &x);
	scanf("%d", &y);
	gotoxy(x, y);
	printf("*");
	system("pause");
	return 0;
}*/ //backwards printing function

void gotoXY(int x, int y)
{
	HANDLE a;
	COORD b;
	fflush(stdout);
	b.X = x;
	b.Y = y;
	a = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(a, b);
}

void gotoxy(int x, int y)
{

	COORD coord;

	coord.X = x;

	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}//coordinate plane function
//fish key 431
void ENDGAME()
{
	system("cls");
	gotoxy(30, 7);
	printf("GAME OVER\n\t\t\t");

		system("pause");
	
		exit(0);
}
