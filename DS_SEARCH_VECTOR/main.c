#include <stdio.h>

int linearSearch(int* vector, int size, int element);
int inOrderSearch(int* vector, int size, int element);
int binarySearch(int* vector, int size, int element);

int main(int argc, const char * argv[]) {
    int vector[10] = {34, 23, 40, 21, 67, 12, 18, 28, 9, 79};

    int index = linearSearch(vector, 10, 21);
    printf("Linear Search: %d \n", index);
    
    int vectorOrdered[7] = {-8, 4, 21, 23, 54, 67, 90};
    int indexOrdered = inOrderSearch(vectorOrdered, 7, 54);
    printf("inOrder Search: %d \n", indexOrdered);
    
    int indexBinary = binarySearch(vectorOrdered, 7, 67);
    printf("Binary Search: %d \n", indexBinary);
    return 0;
}

int linearSearch(int* vector, int size, int element) {
    int index;
    for (index = 0; index < size; index++){
        if (element == vector[index])
            return index;
    }
    return -1;
}

int inOrderSearch(int* vector, int size, int element) {
    int index;
    for (index = 0; index < size; index++){
        if (element == vector[index])
            return index; // find
        else {
            if (element < vector[index])
                return -1; // not find
        }
            
    }
    return -1;
}

int binarySearch(int* vector, int size, int element) {
    int middle;
    int begin = 0;
    int end = size - 1;
    while (begin < end) {
        middle = (begin + end) / 2;
        if (element < vector[middle])
            end = middle - 1;
        else {
            if (element > vector[middle])
                begin = middle + 1;
            else
                return middle;
                
        }
    }
    return -1;
}
