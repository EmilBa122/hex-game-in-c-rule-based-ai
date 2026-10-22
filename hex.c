#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define  MAX 100
#include "prints.h" 
#include "lists.h"


/*

If you type cont command on computers play then it's not 100% sure that the command will be executed correctly
while on the other hand when you give cont command individually it is sure 100% percent it will work .
Also the program is unable to identify the winner and it cannot run suggest and level 

*/


 
int check(char  **board,int n,int i,int j){
	if(board[i][j]=='w'|| board[i][j]=='b' || i>=n || j>=n || j<0 || i<0) return 0;
	else return 1;
}

int *AI_move(char **board,int n,int who_plays,int player_colour){
	char color = ' ';
	if(player_colour==0){
		color = 'b';
	}else{
		color = 'w';	
	}
 	int x,y,flag,ok;
	static int flag3 = 0,s = 0,i,j;
	static int flag2 = 0;
	static int temp_x,temp_y;
	static int played_move[2];
	srand(time(NULL));
	if(s==0){
		//Random move
		x = rand()%n;
		y = rand()%n;
		
		temp_x = y;
		temp_y = x;

		i=temp_x;
		j=temp_y;
		printf("Move played %d %d: \n",x,y);
		printf("ok1");

		if(board[y][x]==' '){
			board[y][x] = color;
			add(color,y,x);		
		}
		s = 1;
		played_move[0] = x;
		played_move[1] = y;
	}else{
		ok = check(board,n,i-1,j);
		if(ok){
			board[i-1][j] = color;
			add(color, i-1,j);
			flag2 = 1 ;
		}

		ok = check(board,n,i-1,j+1);
		if(ok && flag2==0){
			board[i-1][j+1] = color;
			add(color, i-1,j+1);
			flag2 = 1 ;
		}
		

		ok = check(board,n,i-1,j-1);
		if(ok && flag2==0){
			board[i-1][j-1] = color;
			add(color, i-1,j-1);
			flag2 = 1 ;
		}


		ok = check(board,n,temp_x+1,temp_y);
		if(ok && flag2==0){
			board[temp_x+1][temp_y] = color;
			add(color, temp_x+1,temp_y);
			flag2 = 1 ;
		}


		ok = check(board,n,temp_x+1,temp_y+1);
		if(ok && flag2==0){
			board[temp_x+1][temp_y+1] = color;
			add(color, temp_x+1,temp_y+1);
			flag2 = 1 ;
		}


		ok = check(board,n,temp_x+1,temp_y-1);
		if(ok && flag2==0){
			board[temp_x+1][temp_y-1] = color;
			add(color, temp_x+1,temp_y-1);
			flag2 = 1 ;
		}

		ok = check(board,n,temp_x,temp_y+1);
		if(ok && flag2==0){
			board[temp_x+1][temp_y+1] = color;
			add(color, temp_x,temp_y+1);
			flag2 = 1 ;
		}


		ok = check(board,n,temp_x,temp_y-1);
		if(ok && flag2==0){
			board[temp_x][temp_y-1] = color;
			add(color, temp_x,temp_y-1);
			flag2 = 1 ;
		}

	}
	s = 1 ;
	//p=ch1-65;
	//g-=1;

	//played_move[0] = p+65;
	//played_move[1] = g+1;
	
	played_move[0] = x+65;
	played_move[1] = y+1;

	return played_move;
}
	


int strcmp(const char *s1, const char *s2){	/* Compare strings */
	for ( ; *s1 == *s2 ; s1++, s2++)
		if (! *s1) 
			return 0;
	return *s1 - *s2;			/* */
}

void update_arguments(int *n,int *diff,int *b_swap,int *who_plays ,int *swap_ability,int argc,char **argv){
	for(int i=1;i<argc;i++){
		/* update for n X n */
		if(strcmp(argv[i],"-n")==0){
			i++;
			*n = atoi(argv[i]);
		}
		/* update for difficulty */
		if(strcmp(argv[i],"-d")==0){
			i++;
			*diff = atoi(argv[i]);
		}
		/* Who will play first and in which color ? */
		if(strcmp(argv[i],"-b")==0){
			*who_plays = 1; 	/* Player will play first */
			*b_swap = 1;       	/* Players have swaped */
		}
		/* Game swap ability */
		if(strcmp(argv[i],"-s")==0){
			*swap_ability = 1;	/* Swap ability in game active */
		}
	}
}


void swap(int ch1,char **board,int *who_plays,int *player_colour){
   	int x,y;
	while((ch1=getchar())!='\n');
        int *got = getdata();
        x = got[0];
        y = got[1];
        got = getdata();
	if(x!=-1 && y!=-1){		/* Means that the list is not empty */
		board[x][y] = ' ';	/* Assign space value */
            	del();			/* Delete node */
       	}
   	board[y][x] = 'w';		/* Swap i,j to j,i */
    	*who_plays=1;			/* 0:Human plays  1:Computer plays */
	*player_colour=1;		/* 0:Black 1:White */
	add('w',y,x);			/* Add it to the list */
}



void undo(int ch1,char **board){
  	int x,y;				/* Variables to save intreger data */
	int *toremove;				/* A 1-Dimension table to save intregers */
	while( (ch1=getchar())!='\n');		/* Read characters till we get \n */
    	for(int i=0; i<2; i++){			/* 2 times repeates because we want to delete black and white previous moves if they exist */
        	toremove = getdata();		/* Calling getdata() function which returns an array of 2 intregets i,j */
        	x = toremove[0];		 
        	y = toremove[1];		 
        	if(x!=-1 && y!=-1){		/* Check if the array is not empty */
            		board[x][y] = ' ';	/* Assign space */
            		del();			/* Delete element from the saved list */
            		print_list();		/* Print the list*/
        	}else{
			break;			/* Otherwise we now that the list is empty and we break the loop */
       		}
    	}
}

int* play(int ch1,int ch2,int p,int g,char **board,int *player_colour,int *who_plays){
	static int played_move[2];	/* A array to return the move played ex. A3,C12,B1 */

	while((ch1=getchar())!=' ');	/* Read characters till we get space */
	while((ch1=getchar())==' ');	/* Read all spaces till we get a number*/
	ch2=getchar();
	while(ch2>='0' && ch2<='9'){	/* Basic method of finding the number */
		g=g*10+(ch2-'0');	//Finding out the number i,-->(j) play E3
		ch2=getchar();
	}
	p=ch1-65;			/* Subtracting 65='A' because A is equal to the first column () in the table   */
	g-=1;				/* Because the counting in the table starts from one -1 because this is it's actual position */

	played_move[0] = p+65;		/* Saving the values properly for output on return array played move */
	played_move[1] = g+1;	

 

	if(board[g][p]==' ' && *player_colour==0  ){		/* If the player colour is  black */
		board[g][p] = 'b';				/* Assign 'b' value to the table */
		add('b',g,p);					/* Add the move to the list */
	}else if(board[g][p]==' ' && *player_colour==1 ){	/* If the player colour is  white */
		board[g][p] = 'w';				/* Assign 'b' value to the table */
        	add('w',g,p);					/* Add the move to the list */
	}
	 

	return played_move;					/* Return the array */
}




void print_board(char **board,int n){
    	/* Creating board */
	/* The array below is used for printing reasons only */
    	char words[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

	
	for(int i=0;i<(2*n)+2;i++)printf(" ");		/* This is the way we figured out the distance from left of word WHITE */
	printf("WHITE\n");				/* Printing white on top */

	/* Printing alphabet */
	for(int i=0;i<n+2;i++)printf(" ");		
	for(int i=0;i<n;i++)printf("%c   ",words[i]);	/* Printing out the ALPHABET characters on top */
	printf("\n");			

	/* Printing table upper part (cap) */
	for(int i=0;i<n+2;i++)printf(" ");
	for(int i=0;i<n;i++)printf("_   ");		 
	printf("\n");

	for(int i=0;i<n+1;i++) printf(" ");	
	for(int i=0;i<n+1;i++){
		if(i==n-1){
			printf("/ \\");
			break;
		}
		printf("/ \\_");
	}
	printf("\n");
	/* Table upper part printing has finished */

	int num = 1;	
	int space = n-2;
    	int line_counter=4;		
	char *b="BLACK";


	/* Printing out the the rest of the table */
	for(int i=0;i<n;i++){
		/* Printing out the number of line */
		if(line_counter<=n){	/* FOr every line < than the n */
			for(int i=0;i<space-1;i++)printf(" ");
		}else if(line_counter>n && *b!='\0'){   /* For the lines which contain a character of the word BLACK */
			for(int i=0;i<space-3;i++)printf(" ");
			printf("%c ",*b++);
		}else{
	 		for(int i=0;i<space-1;i++)printf(" ");	/* Same as the first one but when line_counter is bigger than  n */
		}
		printf("%2d ",num);
		
		/* Printing out the data 'b'-'w'(black,white) */
		for(int j=0;j<n;j++){
			printf("| %c ",board[i][j]);
		}
		printf("|");
		
		/* Printing out the number of line in the end */
		printf(" %2d",num++);
		printf("\n");////////
		line_counter++;
		
		/* Printing out the lower part*/
		space++;
		/* Printing out the number of line */
		if(line_counter<=n){				/* For every line < than the n */
			for(int i=0;i<space-1;i++)printf(" ");
		}
		else if(line_counter>n && *b!='\0'){   		/* For the lines which contain a character of the word BLACK */
			for(int i=0;i<space-3;i++)printf(" ");
			printf("%c ",*b++);
		}else{
	 		for(int i=0;i<space-1;i++)printf(" ");	/* Same as the first one but when line_counter is bigger than  n */
		}


		for(int i=0;i<3;i++)printf(" ");
		for(int k=0;k<n;k++){
			printf("\\_/ ");
		}
	
		/* If is used to avoid the extra \ in the end */
		if(num<=n)printf("\\");
		printf("\n"); 
		line_counter++;
		space++;
	}
	/* Printing out ALPHABET characters on bottom */
	for(int i=0;i<space+2;i++)printf(" ");
	for(int i=0;i<n;i++)printf("%c   ",words[i]);
	printf("\n");

}


int main(int argc,char *argv[]){
	/* Initializing some basic variables */
	int s_counter = 0; 		/* Swap counter*/
	int *get_move;			/* A array to save the move played */
	int n = 11;			/* Size of the board */
	int diff = 1;			/* Difficulty level set as default to 1 */
	int b_swap = 0;	       		/* Has the player swaped ?(Black,White) 0:False | 1:True */
	int who_plays=0;		/* 0:computer | 1:Human */
	int swap_ability = 0;   	/* Swap ability in game inactive */
	int player_colour=1; 		/* 1:White | 0:Black */
	int move_flag = 0 ;		/* Did the player play ? */
	int load_flag = 0;		/* Did it load */
	char **board;			/* The 2-dimension table where the game is going to be playes */
	int s1,s2;			/* Two variables to read new game */
	char board_space = 'n';		/* A variable to save the character 'n'=' ' which is equal to space */

	update_arguments(&n,&diff,&b_swap,&who_plays,&swap_ability,argc,argv);	/* Updating all the game states  */

	
	printf(">");
	s1 = getchar();
	s2 = getchar();

	char string[MAX];
	char ch = ' ';
	int counter = 0;





	if(s1=='n' && s2=='e'){
		//Read characters till we find space or '\n'
		s1 = getchar();
		while(s1!=' ' && s1!='\n'){
			s1 = getchar();
		}
		if(s1==' '){
			//Read characters till we find 'w'(white) , 'b'(black) or '\n'
			s1 = getchar();
			while(s1!='w' && s1!='b' && s1!='\n'){
				s1 = getchar();
			}
			if(s1=='w'){
				printf("White!");
				player_colour = 1;
				who_plays = 1;
			}else if(s1=='b'){
				s1 ='x';
			}
			while(s1!=' ' && s1!='\n'){
				s1 = getchar();
			}
			if(s1==' '){
				s1 = getchar();
				//Read characters till we find 'n'(swapon) , 'f'(swapoff) or '\n'
				while(s1!='n' && s1!='f' && s1!='\n'){
					s1 = getchar();
				}
				if(s1=='n'){
					swap_ability = 1;
				}else if(s1=='f'){
					swap_ability = 0;
				}
				// Read till we find a space or \n
				while(s1!=' ' && s1!='\n'){
					s1 = getchar();
				}
				if(s1==' '){
					s1 = getchar();
					while(s1<='0' && s1>='9' && s1!='\n'){
						s1 = getchar();
					}
					if(s1>='0' && s1<='9'){
						n = 0;
						while(s1>='0' && s1<='9'){
							n = n*10 + (s1-'0');
							s1 = getchar();
						}
						while(s1==' ' || (s1<='z' && s1>='a'))	/* Cleaning buffer */
							s1 = getchar();
					}
				}

			}

        	}
	}else if(s1=='l' && s2=='o'){		 
		load_flag = 1;
		/* Load goes over here */
		/* Read characters till we find space */
		while((s1=getchar())!=' ');

		char str2[MAX];		/* Read the file name */
		scanf("%s",str2);		
		
		FILE *fp_load = fopen(str2,"rb");	/* Open the file for reading in binary mode */

		fread(&n,sizeof(char),1,fp_load);	/* Read the number of the lines */
		 
		board = malloc(n*sizeof(char*));	/* Allocate required memory for 2-dimension array*/
		if(board == NULL) return -1;

		for(int i=0;i<n;i++){
			board[i] = malloc(n*sizeof(char));
			if(board[i] == NULL) return -1;
		}
		/* Initializing board with spaces */
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				board[i][j] = ' ';
			}
		}
	
	 
		fread(&who_plays,sizeof(char),1,fp_load);			/* Read who_plays */

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				fread(&(board[i][j]),sizeof(char),1,fp_load);	/* Read 'n'=' ','b','w' and save the values in the board */	
				if(board[i][j]=='n')
					board[i][j] = ' ';			
			}
		}
		 
		/* Close the file */
		fclose(fp_load);
			
 						 
	}


	while(s1==' ' || (s1<='z' && s1>='a') ){	/* Cleaning buffer */
		s1 = getchar();
	}






	/* Creation of the board if there was no load */
	if(load_flag==0){
		board = malloc(n*sizeof(char*));
		if(board == NULL) return -1;


		for(int i=0;i<n;i++){
			board[i] = malloc(n*sizeof(char));
			if(board[i] == NULL) return -1;
		}
		/* Iitializing boardn with space*/
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				board[i][j] = ' '; 
			}
		}
	}

	print_board(board,n);
	printf("\n\n");


  
	/* ===================  Game starts here ============================== */



	int p,g;	/* Two variables used to handle board positioning */
	int ch1,ch2; 	/* Command first 2 characters*/
	int swapflag=0;
 


	while(1){
        	s_counter++;
		p = g = 0;
		c1(&player_colour,&who_plays);	/* Printing who plays and in which color */
		printf(">");

		/* Reading first two letters of each command e.x. play <move> : ch1=p , ch2=l */
		ch1=getchar();
		ch2=getchar();
		if (ch1=='p' && ch2=='l'){	/* PLAY */
			get_move = play(ch1,ch2,p,g,board,&player_colour,&who_plays);
			move_flag = 1;
		}else if(ch1=='u' && ch2=='n'){	/* UNDO */
			undo(ch1,board);
        	}else if(ch1=='s' && ch2=='w' && s_counter==2 && swap_ability==1){	/* SWAP */
			swap(ch1,board,&who_plays,&player_colour);
			swapflag=1;
       		}else if(ch1=='q' && ch2=='u'){	/* QUIT */
			return 0;
		}else if(ch1=='s' && ch2=='h'){	/* Showstate */
			print_board(board,n);
			ch1=getchar();
			while(ch1==' ' || (ch1<='z' && ch1>='a')){ /* Cleaning buffer */
				ch1 = getchar();
			}
			continue;
		}else if(ch1=='s' && ch2=='a'){
            		/* Save goes over here */
			while((ch1=getchar())!=' ');

			char str1[MAX];		/* Reading the fille name */
			scanf("%s",str1);		
			FILE *fp_save  = fopen(str1,"wb+");		/* Opening the file in writing mode in binary */
			fwrite(&n,sizeof(char),1,fp_save);		/* Writing n as first character */
			fwrite(&who_plays,sizeof(char),1,fp_save);	/* Writing who plays as character */

			for(int i=0;i<n;i++){				/* Writing spaces='n','b','w' */
				for(int j=0;j<n;j++){
					if(board[i][j]=='b')
						fwrite(&(board[i][j]),sizeof(char),1,fp_save);
					else if(board[i][j]=='w')
						fwrite(&(board[i][j]),sizeof(char),1,fp_save);					
					else
						fwrite(&board_space,sizeof(char),1,fp_save);					
				}
			}
		
			fclose(fp_save);				/* Close the file */	
			printf(">");
			while((s1=getchar())!='q');			/* Read character till we don't get quit */
			ch2=getchar();					
			if(ch2=='u')	{
				return 0;
			}
        	}else if(who_plays==0 && ch1=='c' && ch2=='o'){		/* Cont move by computer AI */
			while((ch1=getchar())!='\n');					
			get_move = AI_move(board,n,who_plays,player_colour);
			move_flag = 1;		
		}
	
	
		print_board(board,n);	
	
		printf("\n");
		if(move_flag){		// If there was a play move by the user
			move_flag = 0;
			//Printing out the move
			printf("Move played: %c%d\n",get_move[0],get_move[1]);
		}else if(swapflag){
			swapflag=0;
			printf("Move played : swap\n");
		}
		c2(&player_colour,&who_plays);
	}

	/* Free the allocated memory */
	for(int l=0;l<n;l++){
		free(board[l]);
	}
	free(board);



	printf("\n\n");
	return 0;
}











































