#include <stdio.h>

// Function prototype
void selectionSort(signed int array[], unsigned int size);
void swappingFun(signed int *numberOne, signed int *numberTwo);
void printArray(signed int array[], unsigned int size);

int main()
{
  // If you want to check the code remove the multiline comment from ( 11 ~ 21 ) line.
  /*
  int arr[] = {15, 7, 5, 12, 3, 10, 2, 8, 4, 1, 14, 9, 11, 6, 13};

  printf("Selection Sorting\n");
  printf("--------------------------------------------\n");
  printf("Before :\n");
  printArray(arr, (*(&arr + 1) - arr));
  selectionSort(arr, (*(&arr + 1) - arr));
  printf("After :\n");
  printArray(arr, (*(&arr + 1) - arr));
  */

  return 0;
}

void selectionSort(signed int array[], unsigned int size)
{
  unsigned int counterIndex = 0;
  unsigned int compareIndex = 0;
  unsigned int minimumIndex = 0;

  for (counterIndex = 0; counterIndex < size - 1; ++counterIndex)
  {
    minimumIndex = counterIndex;
    for (compareIndex = counterIndex + 1; compareIndex < size; ++compareIndex)
    {
      if (array[minimumIndex] > array[compareIndex])
      {
        minimumIndex = compareIndex;
      }
    }

    // By this way of swapping I can't swap two variables have a same memory location.
    // In array if two variables have a same memory location then it will be the same variable then i will not swap.
    if (array[minimumIndex] != array[counterIndex]) 
    {
      swappingFun(&array[minimumIndex], &array[counterIndex]);
    }
  }
}

void swappingFun(signed int *numberOne, signed int *numberTwo)
{
  (*numberOne) = (*numberOne) ^ (*numberTwo);
  (*numberTwo) = (*numberOne) ^ (*numberTwo);
  (*numberOne) = (*numberOne) ^ (*numberTwo);
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