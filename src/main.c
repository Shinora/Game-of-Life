#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include  <unistd.h>
#include "../include/main.h"


int main(){
    int size;
    srand(time(NULL));

    printf(" Welcome to the game of life, please enter a number to define the bi-dimmensional array size : ");
    //input size
    scanf("%10d", &size);
    //avoid memory overflow
    if(size >1000){ exit(1);}

    int grid[size][size];
    int buffer [size][size];

    // setting up the grid with random bools

    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){

            grid[i][j] = random_bool();

        }
        printf("\n");
        
    }
    printf("\n");
    printf("\n");
    printf("\n");

    // game infinite loop

    while(1){
        
        //life game rules

        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                int ne = 0;

                if(grid[i+1][j] == 1){
                    ne+=1;
                }
                if(grid[i+1][j+1] == 1){
                    ne+=1;
                }
                if(grid[i+1][j-1] == 1){
                    ne+=1;
                }
                if(grid[i][j+1] == 1){
                    ne+=1;
                }
                if(grid[i][j-1] == 1){
                    ne+=1;
                }
                if(grid[i-1][j] == 1){
                    ne+=1;
                }
                if(grid[i-1][j+1] == 1){
                    ne+=1;
                }
                if(grid[i-1][j-1] == 1){
                    ne+=1;
                }

                if(grid[i][j] == 1){
                    if(ne<2 || ne>3){
                        buffer[i][j] = 0;
                    }
                    else if(ne == 2 || ne == 3){
                        buffer[i][j] = 1;
                    }
                }

                else{
                    if(ne==3)
                    {
                        buffer[i][j] = 1;
                    }
                    else
                    {
                        buffer[i][j] = 0;
                    }
                }
                
            }
        }
        // updating and printing the grid
        for(int k=0; k<size; k++){
            for(int l=0; l<size; l++){
                grid[k][l] = buffer[k][l];
                printf("%d", grid[k][l]);

            }
            printf("\n");
        }
        sleep(1);
        printf("\n");
        printf("\n");
        printf("\n");
    }

    return 0;
}


int random_bool(){

    int randomdigit = 0;
	
	randomdigit = rand()%2;
	printf("%d",randomdigit);

    return randomdigit;
}