#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include <math.h>
#define MAX 100
typedef struct{
	int row;
	int col;
	int dir;
}elem;
elem stack[MAX];
typedef struct{
	int vert;
	int horiz;
}offsets;

offsets move[8] ={{-1,1},{-1,0},{-1,1},{0,1},{0,-1},{1,-1},{1,0},{1,1}};
int top=-1;
int maze[10][10]=
{
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,1,1,0,1},
	{1,0,0,1,1,0,0,1,1,1},
	{1,1,0,0,1,0,1,1,0,1},
	{1,0,0,0,1,0,0,1,1,1},
	{1,0,1,0,1,1,0,0,1,1},
	{1,0,0,0,0,0,0,0,1,1},
	{1,1,1,0,0,1,0,0,0,1},
	{1,0,0,1,1,1,1,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}
 } ;
 int mark[10][10];
 #define enter_row 1
 #define enter_col 1
 #define exit_row 8
 #define exit_col 7
 void path(void);
 void push(int *top,elem a){
 	(*top)++;
	 if(*top>MAX-1){
 		printf("overflow\n");
 		return;
	 }
	 else{
	 	stack[*top]=a;
	 }
 }
elem pop(int *top){
 	if(*top==-1){
 		printf("enpty");
 	exit(1);
	 }
	 else{
	 	return stack[*top];
	 }
 }
 elem gettop(int *top){
 	if(*top>-1){
 		return stack[*top];
	 }
	 else{
	 	printf("empty\n");
	 	exit(1);
	 }
 }
 void path(){
 	int i,j,col,dir=0,row,next_col,next_row,found=0;
 	elem position;
 	for(i=0;i<=9;i++){
 		for(j=0;j<=9;j++){
 			mark[i][j]=0;
		 }
	 }
	 mark[1][1]=1;
	 top=0;
	 stack[0].col=enter_col;
	 stack[0].row=enter_row;
	 stack[0].dir=0;
	 int count=0;
	 while(top>-1&&!found){
	 	position=gettop(&top);
	 	row=position.row;
	 	col=position.col;
	 	dir=position.dir;
	 	if(count>100000)
	 	{
	 		break;
		 }
		 count++;
		 while(dir<8&&!found){
			next_row=row+move[dir].vert;
		 	next_col=col+move[dir].horiz;
		 	
		 	
		 	if(next_row==exit_row&&next_col==exit_col){
		 		found=1;
			 }
			 else if(!maze[next_row][next_col]&&!mark[next_row][next_col]){
				mark[next_row][next_col]=1;
				position.row=next_row;
				position.col=next_col;
				position.dir=++dir;
				push(&top,position);
				row=next_row;
				col=next_col;
				dir=0;
			 }
			 else{
			 	dir++;
			 }
			if(!found){
		 		position=pop(&top);
			}
		 }
	 	
	 }
	 if(found){
	 	printf("the path is:\n");
	 	for(i=0;i<=top;i++){
	 		printf("%5d  %5d  %5d\n",i+1,stack[i].row,stack[i].col);
		 }
		 printf("%5d %5d\n",exit_row,exit_col);
	 }
	 else{
	 	printf("the maze do not have any path\n");
	 }
 }
main()
{
  path();
}
