#include <stdio.h>

void quickSort(int array[], int low, int high);
void swap(int *a, int *b);
int partition(int array[], int low, int high);
void printArray(int array[], int lenght);


int main(void){
    int testArray[7] = {43, 2, 34, 7, 9, 4, 5};
    printArray(testArray, 7);
    quickSort(testArray, 0, 6);
    printArray(testArray, 7);
    return 0;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int low, int high){
    // Choosing the last item as a pivot
    int pivot = array[high];
    int index_of_low = low - 1;

    for (int j = low; j < high; j++){
        // If the item at index j is smaller then the pivot, 
        // swap with the one at the low index
        if (array[j] < pivot){
            index_of_low++;
            swap(&array[index_of_low], &array[j]);
        }
        // Else leave as is
    }

    // After finishing the partitioning loop
    // swap the pivot in it's right place
    swap(&array[index_of_low + 1], array[high]);

    // Return the index of the pivot
    return index_of_low + 1;
}

void quickSort(int array[], int low, int high){
    if (low < high){
        int pivot = partition(array, low, high);

        quickSort(array, low, pivot - 1);
        quickSort(array, pivot + 1, high);
    }    
}

void printArray(int array[], int lenght){
    for (int i = 0; i < lenght; i++){
        printf("%d ", array[i]);
    }
    printf("/n");
}