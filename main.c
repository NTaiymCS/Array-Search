
#include <stdio.h>
#include <stdlib.h>

// step 2 -- Make a copy of the array
// allocated enough space for the copy
// call arrayCopy() 
void arrayCopy (int arr1[], int arr2[], int size){
    for(int i = 0; i < size; i++){
        arr2[i] = arr1[i];
    }
}

// step 3 -- sort one of the arrays
// call myFavorateSort() - ascending order
// "Write your own function"
void myFavorateSort(int arr1[], int size){
    int smallestIndex = 0;
    int temporary;
    for(int i = 0; i < size-1; i++){
        for(int j = i+1; j < size; j++){
            if(arr1[j] < arr1[i])
            {
                smallestIndex = arr1[i]; // swaps
                arr1[i] = arr1[j];
                arr1[j] = smallestIndex;
            }
        }
    }
}

// step 4 -- read in the search data
// loop until second value of -999 is encountered
// for each value call both linearSearch() and binarySearch()
// print out in main
// first value 4137
// linear search: Found at position: 6      number of Comparisons: 7
int linSearch(int arr1[], int size, int pos, int* numComparisons){
    for(int i = 0; i < size; i++){
        if(arr1[i] == pos){
            return i;
        }
        *numComparisons = i+1;
    }
    return -1;
}
int binSearch(int arr1[], int size, int pos, int* numComparisons){
    
    int i = 0;
    int j = size-1;
    while(i <= j){
        int middleInd = (i+j)/2;
        
        if(arr1[middleInd] > pos){
            i = middleInd - 1;
        }
        else if(arr1[middleInd] == pos){
            middleInd = middleInd + 1;
            return middleInd;
        }
        else{
            i = middleInd + 1;
        }
        (*numComparisons)++;
    }
    return -1;
}


int main (int argc, char **argv)
{
    int x, i;
    int size = 100;
    int val = 0;
    
    int *arr1; // main pointer array
    arr1 = (int *) malloc (size * sizeof(int)); // dynamic array allocation
    
    printf("Input numbers into the array ending with -999");
    scanf ("%d", &x); // scans Input
    // step one -- reading data in until value -999 is encountered
    while(x != -999){
        if(val > size - 1){
            int *tempArr = arr1; // initializes a temporary pointer array to the current
            arr1 = (int *) malloc (size * 2 * sizeof(int)); // doubles the size of array
            
            for(i = 0;  i < size; ++i){
                arr1[i] = tempArr[i]; 
            }
            
            free(tempArr); // deallocates the memory for the temporary array
            size = 2 * size;
        }
        arr1[val] = x; // stores the scanned input into array
        scanf("%d", &x);
        printf ("arr1 %d\n", arr1[val]);
        val++;
    }
    int* arr2;
    arr2 = (int*)malloc(val*sizeof(int));
    int *newArray = (int*)malloc(val*sizeof(int));
    arrayCopy(arr1, newArray, val); // copies array 1 to array 2 unsorted
    
    int val2 = 0;
    size = 100;
    scanf("%d", &x);
    while(x != -999){
        arr2[val2] = x;
        val2++;
        
        if(val2 == size){
            arr2 = (int *) malloc (size * 2 * sizeof(int));
            size = 2 * size;
        }
        scanf("%d", &x);
    }
    
    myFavorateSort(arr1, val); // sorts array 1
    
    printf("Enter position");
    int pos, index;
    
    int *numComparisons = 0;
    //int found = 0;
    for(int k = 0; k < val2; k++){
        index = linSearch(arr1, val, arr2[k], numComparisons);
        
        if(pos == -1){
            printf("Linear Search: Position was not found \n");
        }
        else{
            printf("Linear Search: Found at position: %d", index);
            printf("%i Number of Comparisons: ", *numComparisons);
        }
    }
    *numComparisons = 0;
    for(int k = 0; k < size; k++){
        index = binSearch(newArray, val, arr2[k], numComparisons);
        
        if(pos == -1){
            printf("Binary Search: Position was not found \n");
        }
        else{
            printf("Binary Search: Found at position: %d", index);
            //printf("%i Number of Comparisons: %d\n", *numComparisons);
        }
    }
    
    return 0;
}
