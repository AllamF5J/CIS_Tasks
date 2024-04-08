#include <stdio.h>

// Function prototype
void quickSort(int array[], int begin, int end);
int partition(int array[], int begin, int end);
void swap(signed int *numberOne, signed int *numberTwo);
void printArray(signed int array[], unsigned int size);

int main()
{
  // If you want to check the code remove the multiline comment from ( 12 ~ 22 ) line.
  /*
  int arr[] = {15, 7, 5, 12, 3, 10, 2, 8, 4, 1, 14, 9, 11, 6, 13};
  
  printf("Quick Sorting\n");
  printf("--------------------------------------------\n");
  printf("Before :\n");
  printArray(arr, (*(&arr + 1) - arr));
  quickSort(arr, 0, 14);
  printf("After :\n");
  printArray(arr, (*(&arr + 1) - arr));
  */

  return 0;
}

void quickSort(int array[], int begin, int end)
{
  int pivot = 0;

  if (begin < end)
  {
    pivot = partition(array, begin, end);

    quickSort(array, begin, pivot - 1);
    quickSort(array, pivot + 1, end);
  }
}

int partition(int array[], int begin, int end)
{
  int pivot = array[end]; // Choose the last element as pivot
  int i = begin - 1;      // Index of smaller element points to an invalid index

  for (int j = begin; j < end; j++)
  {
    if (array[j] < pivot)
    {
      i++;

      // Swap if the elements are different
      if (array[i] != array[j])
      {
        swap(&array[i], &array[j]);
      }
    }
  }

  // By this way of swapping I can't swap two variables have a same memory location.
  // In array if two variables have a same memory location then it will be the same variable then i will not swap.
  if (array[i + 1] != array[end])
  {
    swap(&array[i + 1], &array[end]);
  }

  return (i + 1);
}

void swap(signed int *numberOne, signed int *numberTwo)
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