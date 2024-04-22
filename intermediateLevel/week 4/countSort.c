#include <stdio.h>
#include <stdlib.h>

// Function prototype
void checkMax(signed int array[], signed int size);
void CountSort(signed int array[], signed int maxElement, signed int size);
void printArray(signed int array[], unsigned int size);

int main ()
{
  // If you want to check the code remove the multiline comment from ( 11 ~ 21 ) line.
  /*
  int arr[] = {15, 7, 5, 12, 3, 10, 2, 8, 4, 1, 14, 9, 11, 6, 13};

  printf("Count Sorting\n");
  printf("--------------------------------------------\n");
  printf("Before :\n");
  printArray(arr, (*(&arr + 1) - arr));
  checkMax(arr, (*(&arr + 1) - arr));
  printf("After :\n");
  printArray(arr, (*(&arr + 1) - arr));
  */
  return 0;
}

void checkMax(signed int array[], signed int size)
{
  signed int max = array[0];
  signed int index = 0;

  for (index = 0; index < size - 1; ++index)
  {
    if (array[index] > array[0])
    {
      max = array[index];
    }
  }
  CountSort(array, max, size);
}

void CountSort(signed int array[], signed int maxElement, signed int size)
{
  // This is not allowed in C standard to declare an array with sizes determined at runtime like an 'maxElement' or 'size'...
  // I should using dynamic memory allocate.
  signed int *count = (signed int *)calloc((size_t)(maxElement + 1), sizeof(signed int));
  signed int *copyArray = (signed int *)calloc((size_t)size, sizeof(signed int));
  signed int index = 0;

  for (index = 0; index < size; ++index)
  {
    copyArray[index] = array[index];
    count[array[index]]++;
  }

  for (index = 1; index <= maxElement; ++index)
  {
    count[index] += count[index - 1];
  }

  for (index = size - 1; index >= 0; --index)
  {
    array[--count[copyArray[index]]] = copyArray[index];
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