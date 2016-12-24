/*
	Not a game. This is a graphical simulation of the NQuens Problem.
	Some History on that ->The eight queens puzzle is the problem of placing eight chess queens on an 8×8 chessboard so that no two queens threaten each other. Thus, a solution requires that no two queens share the same row, column, or diagonal. The eight queens puzzle is an example of the more general n queens problem of placing n non-attacking queens on an n×n chessboard, for which solutions exist for all natural numbers n with the exception of n=2 and n=3.
*/
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include <alloc.h>

#define BOARD_LINE_COLOR (7)
#define MAX_CELL (8)
#define BASE MAX_CELL
#define SPEED (50)
#define MARGIN (50)

int Q[MAX_CELL];

struct box {
	int x1;
	int y1;
};

struct box cell[MAX_CELL][MAX_CELL];

void show_text(char *s){
	int x=getmaxx()/2;
	int y=getmaxy()-MARGIN+5;
	settextjustify(1,1);
	outtextxy(x,y,s);
}

void draw_queen(int x, int y, int n,int color){
	int k=0;
	int margin=MARGIN;
	int xdiv=(getmaxx()-2*margin)/n;
	int ydiv=(getmaxy()-2*margin)/n;
	int maxx=n*xdiv;
	int maxy=n*ydiv;
	setcolor(color);
	circle(x+xdiv/2,y+ydiv/2,xdiv/4);
}

void draw_board(int n){
	int j=0,k=0;
	int x,y;
	int margin=MARGIN;
	int xdiv=(getmaxx()-2*margin)/n;
	int ydiv=(getmaxy()-2*margin)/n;
	int maxx=n*xdiv;
	int maxy=n*ydiv;
	setcolor(BOARD_LINE_COLOR);
	for(k=0;k<=n;k+=1) {
		line(margin+k*xdiv,margin,margin+k*xdiv,margin+maxy);
		line(margin,margin+k*ydiv,margin+maxx,margin+k*ydiv);
	}
	for(j=0;j<n;j+=1) {
		for(k=0;k<n;k+=1) {
			cell[k][j].x1=margin+j*xdiv;
			cell[k][j].y1=margin+k*ydiv;
			putpixel(cell[k][j].x1+3,cell[k][j].y1+3,10);
		}
	}
}

void clear_column(int col){
	int k=0;
	for(;k<MAX_CELL;k++)
		draw_queen(cell[k][col].x1,cell[k][col].y1,MAX_CELL,0);
}

void clear_row(int r){
	int k=0;
	for(;k<MAX_CELL;k++)
		draw_queen(cell[r][k].x1,cell[r][k].y1,MAX_CELL,0);
}

void show_current_row(int r){
	static int prev=-1;
	int height=((getmaxy()-2*MARGIN)/MAX_CELL)-3;
	int width=10;
	int m=5;
	setcolor(0);
	if(prev==-1) {
		prev=r;
	}
	else  {
		setfillstyle(1,0);
		bar(cell[prev][0].x1+m,cell[prev][0].y1+m,cell[prev][0].x1+width,cell[prev][0].y1+height);
	}
	setfillstyle(1,r+1);
	bar(cell[r][0].x1+m,cell[r][0].y1+m,cell[r][0].x1+width,cell[r][0].y1+height);
	prev=r;
}

void printQ(int n){
	int i=0;
	for(;i<n;i++)
		printf("Q[%d] = %d | ", i, Q[i]);
	printf("\n");
}

int place(int r,int c){
	int row;
	for(row=0;row<=r-1;row++) {
		clear_row(r);
		draw_queen(cell[r][c].x1,cell[r][c].y1,MAX_CELL,7);
		if( (Q[row]==c) || ( abs(Q[row]-c) == abs(row-r))) {
			draw_queen(cell[r][c].x1,cell[r][c].y1,MAX_CELL,r+1);
			return  0;
		}
	}
	clear_row(r);
	draw_queen(cell[r][c].x1,cell[r][c].y1,MAX_CELL,r+1);
	return 1;
}

int nqueen(int row,int n){
	int col;
	setcolor(14);
	show_text("In progress ...");
	for(col=0;col<n;col++){
		delay(SPEED);
		show_current_row(row);
		if(place(row,col)){
			Q[row]=col;
			if(row==n-1) {
				setcolor(0);
				show_text("In progress ...");
				setcolor(2);
				show_text("SOLUTION ARRIVED");
				getch();
				cleardevice();
				closegraph();
				exit(0);
			}
			else {
				nqueen(row+1,n);
			}
		}
		clear_row(row+1);
	}
	return 0;
}

void main() {
	int gdriver = DETECT, gmode = 0;
	initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
	draw_board(MAX_CELL);
	nqueen(0,BASE);
	getch();
	cleardevice();
	closegraph();
}
