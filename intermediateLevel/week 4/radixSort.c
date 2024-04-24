#include <stdio.h>
#include <stdlib.h>

// Function prototype
void RadixSort(signed int array[], signed int size);
void CountSort(signed int array[], signed int exp, signed int size);
signed int checkMax(signed int array[], signed int size);
void printArray(signed int array[], unsigned int size);

int main()
{
  // If you want to check the code remove the multiline comment from ( 13 ~ 23 ) line.
  /*
  int arr[] = {15, 7, 5, 12, 3, 10, 2, 8, 4, 1, 14, 9, 11, 6, 13};

  printf("Radix Sorting\n");
  printf("--------------------------------------------\n");
  printf("Before :\n");
  printArray(arr, (*(&arr + 1) - arr));
  RadixSort(arr, (*(&arr + 1) - arr));
  printf("After :\n");
  printArray(arr, (*(&arr + 1) - arr));
  */

  return 0;
}

void RadixSort(signed int array[], signed int size)
{
  signed int max = checkMax(array, size);
  signed int exp = 0;

  for (exp = 1; (max / exp) > 0; exp *= 10)
  {
    CountSort(array, exp, size);
  }
}

signed int checkMax(signed int array[], signed int size)
{
  signed int max = array[0];
  signed int index = 0;

  // Find the maximum element in the array
  for (index = 1; index < size; ++index)
  {
    if (array[index] > max)
    {
      max = array[index];
    }
  }

  return max;
}

void CountSort(signed int array[], signed int exp, signed int size)
{
  signed int *count = (signed int *)calloc((size_t)(10), sizeof(signed int));
  signed int *copyArray = (signed int *)calloc((size_t)size, sizeof(signed int));

  if (!count || !copyArray)
  {
    // Memory allocation failed
    return;
  }

  signed int index = 0;
  for (index = 0; index < size; ++index)
  {
    copyArray[index] = array[index];
    count[(array[index] / exp) % 10]++;
  }

  for (index = 1; index < 10; ++index)
  {
    count[index] += count[index - 1];
  }

  for (index = size - 1; index >= 0; --index)
  {
    array[--count[(copyArray[index] / exp) % 10]] = copyArray[index];
  }

  // Free dynamically allocated memory
  free(count);
  free(copyArray);
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