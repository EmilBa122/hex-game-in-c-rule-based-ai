#include <stdio.h>


void c1(int *player_colour, int *who_plays){		/* This functionis used for displaying who will play  */
	if(*player_colour==0 && *who_plays==0){		/* If it's the computer's turn to play and it is black */
		printf("Black player (computer) plays now\n");
    	}else if (*player_colour==0 && *who_plays==1){	/* If it's the human's turn to play and is black    */
        	printf("Black player (human) plays now\n");
    	}else if (*player_colour==1 && *who_plays==0){	/* If it's the computer's turn to play and is white */
        	printf("White player (computer) plays now\n");
    	}else if (*player_colour==1 && *who_plays==1){	/* If it's the humans's turn to play and is white */
        	printf("White player (human) plays now\n");
    	}	
}


void c2(int *player_colour,int *who_plays){		/* This function is used for flipping the turn of human or computer */
	if(*who_plays==0 && *player_colour==1){		/* If white computer plays then it's the black humans turn */
        	*who_plays=1;
        	*player_colour=0;
    	}else if(*who_plays==1 && *player_colour==0){	/* If black human plays then it's the white computer turn */
        	*who_plays=0;
        	*player_colour=1;
    	}else if(*who_plays==0 && *player_colour==0){	/* If black computer plays then it's the white human turn */
        	*who_plays=1;
        	*player_colour=1;
    	}else if (*who_plays==1 && *player_colour==1){	/* If white human plays then it's the black computer turn */
        	*who_plays=0;
        	*player_colour=0;
    	}
}
