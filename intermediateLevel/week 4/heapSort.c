#include <stdio.h>

// Function prototype
void HeapSort(signed int array[], signed int size);
void buildHeap(signed int array[], signed int size);
void Heapify(signed int array[], signed int begin, signed int size);
void printArray(signed int array[], signed int size);
void swap(signed int *numberOne, signed int *numberTwo);

int main ()
{
  // If you want to check the code remove the multiline comment from ( 13 ~ 23 ) line.
  /*
  int arr[] = {15, 7, 5, 12, 3, 10, 2, 8, 4, 1, 14, 9, 11, 6, 13};

  printf("Heap Sorting\n");
  printf("--------------------------------------------\n");
  printf("Before :\n");
  printArray(arr, (*(&arr + 1) - arr));
  HeapSort(arr, (*(&arr + 1) - arr));
  printf("After :\n");
  printArray(arr, (*(&arr + 1) - arr));
  */

  return 0;
}

void HeapSort(signed int array[], signed int size)
{
  signed int start = 0;
  buildHeap(array, size);

  for (start = size - 1; start > 0; start--)
  {
    swap(&array[0], &array[start]);
    Heapify(array, 0, start);
  }
}

void buildHeap(signed int array[], signed int size)
{
  signed int start = (size - 1) / 2;

  while (start >= 0)
  {
    Heapify(array, start, size);
    start--;
  }
}

void Heapify (signed int array[], signed int begin, signed int size)
{
  signed int left = 2 * begin + 1;
  signed int right = 2 * begin + 2;
  signed int max = begin;

  if (left < size && array[left] > array[max])
  {
    max = left;
  }

  if (right < size && array[right] > array[max])
  {
    max = right;
  }

  if (max != begin)
  {
    swap(&array[begin], &array[max]);
    Heapify(array, max, size);
  }
}

void swap(signed int *numberOne, signed int *numberTwo)
{
  (*numberOne) = (*numberOne) ^ (*numberTwo);
  (*numberTwo) = (*numberOne) ^ (*numberTwo);
  (*numberOne) = (*numberOne) ^ (*numberTwo);
}

void printArray(signed int array[], signed int size)
{
  signed int l_counter = 0;

  for (l_counter = 0; l_counter < size; ++l_counter)
  {
    printf("%d\t", array[l_counter]);
  }
  printf("\n");
}