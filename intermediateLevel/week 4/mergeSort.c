#include <stdio.h>
#include <stdlib.h>

void merge(signed int array[], unsigned int begin, unsigned int mid, unsigned int end);
void mergeSort(signed int array[], unsigned int begin, unsigned int end);
void printArray(signed int array[], unsigned int size);

int main()
{
  // If you want to check the code remove the multiline comment from ( 11 ~ 21 ) line.
  /*
  signed int arr[] = {15, 7, 5, 12, 3, 10, 2, 8, 4, 1, 14, 9, 11, 6, 13};

  printf("Merge Sorting\n");
  printf("--------------------------------------------\n");
  printf("Before :\n");
  printArray(arr, (*(&arr + 1) - arr));
  mergeSort(arr, 0, (*(&arr + 1) - arr) - 1);
  printf("After :\n");
  printArray(arr, (*(&arr + 1) - arr));
  */

  return 0;
}

void mergeSort(signed int array[], unsigned int begin, unsigned int end)
{
  if (begin < end)
  {
    unsigned int mid = begin + ((end - begin) / 2); // ((end + begin) / 2);

    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
  }
}

void merge(signed int array[], unsigned int begin, unsigned int mid, unsigned int end)
{
  unsigned int arrayIndex = begin;
  unsigned int leftCounter = 0, rightCounter = 0;
  unsigned int elementCountLeft = mid - begin + 1;
  unsigned int elementCountRight = end - mid;

  // This is not allowed in C standard to declare an array with sizes determined at runtime like an 'elementCountLeft' or 'elementCountRight'...
  // I should using dynamic memory allocate.
  signed int *leftArray = (signed int *)calloc(elementCountLeft, sizeof(signed int));
  signed int *rightArray = (signed int *)calloc(elementCountRight, sizeof(signed int));

  if(!leftArray || !rightArray)
  {
    return;
  }

  for (leftCounter = 0; leftCounter < elementCountLeft; ++leftCounter)
  {
    leftArray[leftCounter] = array[begin + leftCounter];
  }

  for (rightCounter = 0; rightCounter < elementCountRight; ++rightCounter)
  {
    rightArray[rightCounter] = array[mid + 1 + rightCounter];
  }
  rightCounter = leftCounter = 0;

  while ((leftCounter < elementCountLeft) && (rightCounter < elementCountRight))
  {
    if (leftArray[leftCounter] <= rightArray[rightCounter])
    {
      array[arrayIndex++] = leftArray[leftCounter++];
    }
    else
    {
      array[arrayIndex++] = rightArray[rightCounter++];
    }
  }

  while (leftCounter < elementCountLeft)
  {
    array[arrayIndex++] = leftArray[leftCounter++];
  }

  while (rightCounter < elementCountRight)
  {
    array[arrayIndex++] = rightArray[rightCounter++];
  }

  free(leftArray);
  free(rightArray);
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