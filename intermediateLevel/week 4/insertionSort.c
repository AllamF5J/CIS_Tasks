#include <stdio.h>

// Function prototype
void insertionSort(signed int array[], unsigned int size);
void printArray(signed int array[], unsigned int size);

int main()
{
  // If you want to check the code remove the multiline comment from ( 10 ~ 20 ) line.
  /*
  int arr[] = {15, 7, 5, 12, 3, 10, 2, 8, 4, 1, 14, 9, 11, 6, 13};

  printf("Insertion Sorting\n");
  printf("--------------------------------------------\n");
  printf("Before :\n");
  printArray(arr, (*(&arr + 1) - arr));
  insertionSort(arr, (*(&arr + 1) - arr));
  printf("After :\n");
  printArray(arr, (*(&arr + 1) - arr));
  */ 

  return 0;
}

void insertionSort(signed int array[], unsigned int size)
{
  signed int compareIndex = 0;
  unsigned int iteratorIndex = 0;
  signed int insertVal = 0;

  for(iteratorIndex = 1; iteratorIndex < size; ++iteratorIndex)
  {
    insertVal = array[iteratorIndex];
    compareIndex = (signed int)iteratorIndex - 1;
    
    while((array[compareIndex] > insertVal) && (compareIndex >= 0))
    {
      array[compareIndex + 1] = array[compareIndex];
      compareIndex--;
    }
    array[compareIndex + 1] = insertVal;
  }
}

void printArray(signed int array[], unsigned int size)
{
  unsigned int l_counter = 0;

  for (l_counter = 0; l_counter < size; ++l_counter)
  {
    printf("%d\t", array[l_counter]);
  }
  printf("\n");
}