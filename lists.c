#include <stdio.h>
#include <stdlib.h>

struct node{
    int i;	/* I */
    int j;	/* J */
    char s;	/* Data */
    struct node *next;	/* Linker to next node */
};
struct node *list_head = NULL ;	/* ROOT */
 

int* getdata(){			/* This function returns the i,j of the first element of the list */
    	static int a[2];		
    	if(list_head==NULL){
       		a[0] = -1;
       		a[1] = -1;
    	}else{
       		a[0] = list_head->i;
       		a[1] = list_head->j;
    	}

    	return a;
}


void add(int d,int p,int g){ 		/* This function adds elements to the list (d=data,p=i,g=j)*/
    	struct node *new_node;		/* Creating new node */
    	new_node = malloc(sizeof(struct node));
    	if(new_node == NULL ) printf("Unable to allocate memory ! \n");

	/* Assigning values to the new node */
    	new_node->i = p;	
    	new_node->j = g;
    	new_node->s = d;

	/* Changing next pointer */
    	if(list_head==NULL){
        	list_head = new_node;
        	new_node->next = NULL;
    	}else if(list_head!=NULL){
        	new_node->next = list_head;
        	list_head = new_node;
    	}
}

/* This function prints the list */
void print_list(){
    	struct node *p;
    	p = list_head;
    	while(p!=NULL){
        	printf(" %c ,%d, %d  \n",p->s,p->i,p->j);
        	p = p->next;
    	}
    	printf("\n");
}

/* This function deletes the first element of the lists if it exists */
void del(){
    	if(list_head!=NULL){
        	struct node *temp;
        	temp = list_head;
        	if(list_head!=NULL){
           	 	list_head = temp->next;
        	}
        	free(temp);
    	}
}



