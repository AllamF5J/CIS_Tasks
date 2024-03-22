#include <stdio.h>

// Function prototype
int binarySearch(int array[], int begin, int end, int checkElement);

int main()
{
  // If you want to check the code remove the multiline comment from ( 9 ~ 21 ) line.
  /*
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

  int result = binarySearch(arr, 0, (*(&arr + 1) - arr) - 1, 17);
  if (result != -1)
  {
    printf("Element found at index %d.\n", result); // 16
  }
  else
  {
    printf("Element not found in the array.\n");
  }
  */

  return 0;
}

/* ************************ Function recursion *********************** */
int binarySearch(int array[], int begin, int end, int checkElement)
{
  int middle = 0;

  while (begin <= end)
  {
    middle = begin + ((end - begin) / 2); // ((end + begin) / 2)

    if (array[middle] == checkElement)
    {
      return middle;
    }
    else if (array[middle] < checkElement)
    {
      return binarySearch(array, middle + 1, end, checkElement);
    }
    else if (array[middle] > checkElement)
    {
      return binarySearch(array, begin, middle - 1, checkElement);
    }
  }

  return -1;
}