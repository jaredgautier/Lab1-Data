#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "omp.h"

int totalArraySize(int k, int dimArr[]);
int * initialiseArray(int values);                                    // PROCEDURE 1
int * populateOnes(int values, int finalArr[]);                        // PROCEDURE 2
void printVals(int values,  int finalArr[], int dimArr[], int k);    // PROCEDURE 3
void coordToArray(int k, int dimArr[], int coordArr[]);
int * indexToCoord(int k, int dimArr[], int remainder);

int main(int argc, char *argv[])
{
      srand(time(NULL));
    
    // ARRAY ONE
    int k = 2;                                     // Matrix dimensions
    int dimArr1[] = {100,100};                     // Dimension quantities
       int values = totalArraySize(k, dimArr1);
    int *finalArr1 = initialiseArray(values);     // Procedure 1
    finalArr1 = populateOnes(values, finalArr1);     // Procedure 2
    printVals(values, finalArr1, dimArr1, k);        // Procedure 3

    // ARRAY TWO
    k = 3;                                     // Matrix dimensions
    int dimArr2[] = {100,100,100};                     // Dimension quantities
       values = totalArraySize(k, dimArr2);
    int *finalArr2 = initialiseArray(values);     // Procedure 1
    finalArr2 = populateOnes(values, finalArr2);     // Procedure 2
    printVals(values, finalArr2, dimArr2, k);        // Procedure 3
    
    // ARRAY THREE
    k = 4;                                     // Matrix dimensions
    int dimArr3[] = {50,50,50,50};                 // Dimension quantities
       values = totalArraySize(k, dimArr3);
    int *finalArr3 = initialiseArray(values);     // Procedure 1
    finalArr3 = populateOnes(values, finalArr3);     // Procedure 2
    printVals(values, finalArr3, dimArr3, k);        // Procedure 3
    
    // ARRAY FOUR
    k = 5;                                     // Matrix dimensions
    int dimArr4[] = {20,20,20,20,20};             // Dimension quantities
       values = totalArraySize(k, dimArr4);
    int *finalArr4 = initialiseArray(values);     // Procedure 1
    finalArr4 = populateOnes(values, finalArr4);     // Procedure 2
    printVals(values, finalArr4, dimArr4, k);        // Procedure 3

}

// Returns final array size
int totalArraySize(int k, int dimArr[])
{
    // Calculate total array members
    int values = 1;
    for (int a = 0; a < k ; a++){
        values = values*dimArr[a];
    }
    
    return values;

}

// ~~~~~~~~~~~~~ PROCEDURE 1 ~~~~~~~~~~~~~
// Initialises final array and sets all to zero
int * initialiseArray(int values)
{    
    // Creating final array
    int *finalArr;
    finalArr = malloc(values*sizeof(int));

    for (int a = 0; a < values; a++){
        finalArr[a] = 0;
    }

    return finalArr;

}

// ~~~~~~~~~~~~~ PROCEDURE 2 ~~~~~~~~~~~~~
// Uniformly sets ten percent of array values to one
int * populateOnes(int values, int finalArr[]){
    
    for(int a=0; a<values; a+=10){
        finalArr[a] = 1;
    }
    return finalArr;
}

// ~~~~~~~~~~~~~ PROCEDURE 3 ~~~~~~~~~~~~~
// Uniformly prints five percent of values
void printVals(int values, int finalArr[], int dimArr[], int k){
    int index = 0;
    //int coordArr[k];
    for(int a=0; a < (values*0.05); a++){
        index = rand() % values;
        int *coordArr = indexToCoord(k, dimArr, index);
        printf("Index: ");
        printf("%d", index);
        printf(" Coordinates ");
        for(int b = 0; b<k; b++){
            printf("%d ", coordArr[b]);
            printf(" ");
        }
        printf("Value: ");
        printf("%d ", finalArr[index]);
        printf("\n");
    }
}



void coordToArray(int k, int dimArr[], int coordArr[])
{
    int arrayIndex = 0;
    int coord = 1;
    // Getting array index
    for (int a = 0; a < k; a++){

        coord = coordArr[k-a-1];

        for (int b = a; b < k-1; b++){
            coord = coord*dimArr[b];
        }

         arrayIndex = arrayIndex + coord;
    }
     printf("Index: ");
     printf("%d ", arrayIndex);
     printf("\n");

     //remainder = arrayIndex;
}

int * indexToCoord(int k, int dimArr[], int index)    
{
    int* fetchedCoordArr = malloc(k*sizeof(int));

     // Array index to coordinates
     for (int a = 0; a < k; a++){
        int fancy = 1;
        for (int b = 0; b < k-a-1; b++){
            fancy = fancy*dimArr[b];
        }
        
       fetchedCoordArr[a] = index/fancy;
       index = index%fancy;
        
     }
    
    return fetchedCoordArr;
}