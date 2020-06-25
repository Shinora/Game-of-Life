#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include  <unistd.h>
#include "../include/main.h"


int main(){
    int size;
    char mybool;
    srand(time(NULL));

    printf("Welcome to the game of life ! \n\n");

    printf("Please enter a number to define the bi-dimmensional array size : ");
    //input size
    scanf("%10d", &size);
    //avoid memory overflow
    if(size >1000){ exit(1);}

    char grid[size][size];
    char buffer [size][size];

    // setting up the grid with random bools

    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){

            mybool = random_bool();

            grid[i][j] = convert(mybool);

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

                if(grid[i+1][j] == '#'){
                    ne+=1;
                }
                if(grid[i+1][j+1] == '#'){
                    ne+=1;
                }
                if(grid[i+1][j-1] == '#'){
                    ne+=1;
                }
                if(grid[i][j+1] == '#'){
                    ne+=1;
                }
                if(grid[i][j-1] == '#'){
                    ne+=1;
                }
                if(grid[i-1][j] == '#'){
                    ne+=1;
                }
                if(grid[i-1][j+1] == '#'){
                    ne+=1;
                }
                if(grid[i-1][j-1] == '#'){
                    ne+=1;
                }

                if(grid[i][j] == '#'){
                    if(ne<2 || ne>3){
                        buffer[i][j] = ' ';
                    }
                    else if(ne == 2 || ne == 3){
                        buffer[i][j] = '#';
                    }
                }

                else{
                    if(ne==3)
                    {
                        buffer[i][j] = '#';
                    }
                    else
                    {
                        buffer[i][j] = ' ';
                    }
                }
                
            }
        }
        // updating and printing the grid
        for(int k=0; k<size; k++){
            for(int l=0; l<size; l++){
                grid[k][l] = buffer[k][l];
                printf("%c", grid[k][l]);

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
    return randomdigit;
}

char convert(int mybool){
    if(mybool == 1){
        return '#';
    }
    else if(mybool ==0)
    {
        return ' ';
    }
    else{
        printf("ERROR : The number given in input isn't either 0 or 1 ...");
        exit(1);
    }
    
}