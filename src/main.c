#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../include/main.h"


int main(){
    int size;
    srand(time(NULL));

    printf(" Welcome to the game of life, please enter a number to define the bi-dimmensional array size : ");
    scanf("%10d", &size);

    char grid[size][size];

    init_state(**grid, size);

    return 0;
  
}

void init_state(char **pointeuronarray,int size){

	for(int i=0; i<50; i++){
        random_bool();
		
	}

}

int random_bool(){

    int randomdigit = 0;
	 // initialisation de rand
	
	randomdigit = rand();
	printf("%d ",randomdigit);

    return randomdigit;
	


    // generates a random bool
}