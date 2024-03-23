#include <stdio.h>

// Function prototype
void bubbleSort(signed int array[], unsigned int size);
void swappingFun(signed int *numberOne, signed int *numberTwo);
void printArray(signed int array[], unsigned int size);

int main()
{
  // If you want to check the code remove the multiline comment from ( 11 ~ 21 ) line.
  /*
  int arr[] = {15, 7, 5, 12, 3, 10, 2, 8, 4, 1, 14, 9, 11, 6, 13};

  printf("Bubble Sorting\n");
  printf("--------------------------------------------\n");
  printf("Before :\n");
  printArray(arr, (*(&arr + 1) - arr));
  bubbleSort(arr, (*(&arr + 1) - arr));
  printf("After :\n");
  printArray(arr, (*(&arr + 1) - arr));
  */

  return 0;
}

void bubbleSort(signed int array[], unsigned int size)
{
  unsigned int l_counter = 0;
  unsigned int l_iterator = 0;
  unsigned int flag = 1;

  for(l_counter = 0; l_counter < size - 1; ++l_counter)
  {
    for(l_iterator = 0; l_iterator < size - l_counter -1; ++l_iterator)
    {
      if(array[l_iterator] > array[l_iterator + 1])
      {
        flag = 0;

        swappingFun(&array[l_iterator], &array[l_iterator + 1]);
      }
      
      if(flag)
      {
        return;
      }
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