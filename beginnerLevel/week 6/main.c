#include <stdio.h>
#include <ctype.h>
#include <windows.h>
#include <stdlib.h>

// Macros
#define STUDENTS_NUMBER 3
#define MAX_NAME_LENGTH 50
#define SUBJECT_NUMBER 8

// Global Variable
char studentData[STUDENTS_NUMBER][SUBJECT_NUMBER][MAX_NAME_LENGTH];
char *subjectName[SUBJECT_NUMBER] = {"ID       ", "Name     ", "Math     ", "Circuits ", "Chemistry", "Physics  ", "English  ", "Science  "};
unsigned int index1 = 0, index2 = 0, retVal = 0;
float totalMark = 0;

unsigned int search_for_name(char array[][SUBJECT_NUMBER][MAX_NAME_LENGTH], unsigned int rows, const char *name);
void storeAllGrades(char array[][SUBJECT_NUMBER][MAX_NAME_LENGTH], unsigned int rows);
void displayAllGrades(char array[][SUBJECT_NUMBER][MAX_NAME_LENGTH], unsigned int rows);
void display_result(float totalMark);
void display_grade(unsigned int index, char array[][SUBJECT_NUMBER][MAX_NAME_LENGTH]);

// Custom Implemetion Functions.
int my_strcmp(const char *str1, const char *str2);
char *my_strcpy(char *dest, const char *src);
size_t my_strlen(const char *str);
int my_atoi(const char *str);

int main()
{
  // Local Variables
  char searchName[MAX_NAME_LENGTH];
  unsigned int StudentID = 0;
  char check = ' ';

  storeAllGrades(studentData, STUDENTS_NUMBER);
  displayAllGrades(studentData, STUDENTS_NUMBER);

  printf("\nEnter a name to search: ");
  scanf("%s", searchName);

  // Perform name search and display the result
  unsigned int nameCount = search_for_name(studentData, STUDENTS_NUMBER, searchName);
  printf("Number of students with name '%s': %u\n", searchName, nameCount);

  printf("\nDo you want to check about subject degree? ( Y / N): ");

  // Validate user input and proceed accordingly
  if ((scanf(" %c", &check)) && (check == 'y' || check == 'Y'))
  {
    printf("\nPlease, Enter student ID to validate it. Then Press ENTER : ");
    scanf("%u", &StudentID);

    for (index1 = 0; index1 < STUDENTS_NUMBER; ++index1)
    {
      if ((unsigned int)my_atoi(&studentData[index1][0][0]) == StudentID)
      {
        // Display the student's grade
        display_grade(index1, studentData);
        break;
      }

      // After the loop, check if the ID was not found
      if (index1 == STUDENTS_NUMBER)
      {
        printf("Wrong ID.\n");
        Sleep(5000);

        return 0;
      }
    }
  }
  else
  {
    printf("\nInvalid ID or Password \nPlease try again later \n");
    Sleep(5000);

    return 0;
  }

  // If You Want To Test An Impelemention Of 3 Functions Remove A Multiple Comment Line Form ( 82 ~ 120 ) Line.
  /*
  char string1[50] = "";
  char string2[50] = "";
  int ret = 0;
  const char *sourceString = "Free Palestine <3";
  char destinationString[50];

  printf("Before copy string \n");
  printf("Source String: %s\n", sourceString);
  printf("Copied String: %s\n", destinationString);
  printf("Size of Source String : %d\n", (signed int)my_strlen(sourceString));
  printf("Size of Copied String : %d\n", (signed int)my_strlen(destinationString));

  // Call your my_strcpy function
  my_strcpy(destinationString, sourceString);

  // Print the result
  printf("\nAfter copy string \n");
  printf("Source String: %s\n", sourceString);
  printf("Copied String: %s\n", destinationString);
  printf("Size of Source String : %d\n", (signed int)my_strlen(sourceString));
  printf("Size of Copied String : %d\n", (signed int)my_strlen(destinationString));

  printf("\nBefore copy string \n");
  printf("string1 : %s\n", string1);
  printf("string2 : %s\n", string2);

  printf("\nAfter copy string \n");
  my_strcpy(string1, "ABCDeF");
  my_strcpy(string2, "ABcDeF");

  printf("string1 : %s\n", string1);
  printf("string2 : %s\n", string2);

  printf("\nWhen Compare to string.\n");
  ret = my_strcmp(string1, string2);
  printf("%s \n", (ret < 0) ? "string1 is less than string2" : (ret > 0) ? "string2 is less than string1"
                                                                        : "string1 is equal to string2");
  */

  return 0;
}

// Function to store grades for subjects
void storeAllGrades(char array[][SUBJECT_NUMBER][MAX_NAME_LENGTH], unsigned int rows)
{
  printf("\nEnter Grades For Subjects.\n\n");

  for (index1 = 0; index1 < rows; ++index1)
  {
    retVal = 0; // Reset validation

    // Take ID and check if it's an integer
    printf("\nPlease, Enter ID For Student %d : ", (index1 + 1));
    while (retVal != 1)
    {
      retVal = (unsigned int)scanf("%s", array[index1][0]);
      if (retVal != 1 || my_atoi(array[index1][0]) % 10 != 5)
      {
        printf("\nInvalid Input! \nPlease, Enter ID Again : ");
        while (getchar() != '\n')
          ;         // Clear the input buffer
        retVal = 0; // Reset validation
      }
    }

    // Take name
    printf("Please, Enter Name For Student %d : ", (index1 + 1));
    scanf("%s", array[index1][1]);

    // Store the rest of grades
    totalMark = 0;

    for (index2 = 2; index2 < SUBJECT_NUMBER; ++index2)
    {
      printf("%s : ", subjectName[index2]); // Assuming subjectName is a global array of subject names
      scanf("%s", array[index1][index2]);
      totalMark += (float)my_atoi(array[index1][index2]);
    }
    totalMark /= (SUBJECT_NUMBER - 2);

    // Print percentage and overall rating.
    printf("\nPercentage: %0.2f%%  ", totalMark);
    display_result(totalMark);

    // Motivating sentence
    if (totalMark > 50.0)
    {
      printf("\nCongratulations, %s! Your hard work paid off. \n", array[index1][1]);
    }
    else
    {
      printf("\nKeep trying, %s! Success is a journey, not a destination. \n", array[index1][1]);
    }

    printf("\n");
  }
}

// Function to display all grades
void displayAllGrades(char array[][SUBJECT_NUMBER][MAX_NAME_LENGTH], unsigned int rows)
{
  char *subjectTable[SUBJECT_NUMBER] = {"ID", "Name", "Math", "Circuits", "Chemistry", "Physics", "English", "Science"};

  for (index1 = 0; index1 < rows; ++index1)
  {
    printf("ID: %s\tName: %s\t", array[index1][0], array[index1][1]);

    for (index2 = 2; index2 < SUBJECT_NUMBER; ++index2)
    {
      printf("%s : %s\t", subjectTable[index2], array[index1][index2]);
    }

    printf("\n");
  }
}

// To search about how many time name of student repeated.
unsigned int search_for_name(char array[][SUBJECT_NUMBER][MAX_NAME_LENGTH], unsigned int rows, const char *name)
{
  unsigned int count = 0;

  for (index1 = 0; index1 < rows; ++index1)
  {
    if (my_strcmp(array[index1][1], name) == 0)
    {
      count++;
    }
  }

  return count;
}

void display_result(float totalMarks)
{
  printf("%s",
         (totalMarks >= 85.0) ? "Excellent \n" : (totalMarks >= 75.0) ? "Very Good \n"
                                             : (totalMarks >= 65.0)   ? "Good \n"
                                             : (totalMarks >= 50.0)   ? "Pass \n"
                                                                      : "You Failed Successfully ^_^ \n");
}

void display_grade(unsigned int index, char array[][SUBJECT_NUMBER][MAX_NAME_LENGTH])
{
  char check = ' ';
  unsigned int subjectNum = 0;

  do
  {
    printf("\nPlease Enter a number of subject you want to display.\n");
    printf("[1] Math\n[2] Circuits\n[3] Chemistry\n[4] Physics\n[5] English\n[6] Science\nEnter your choice: ");
    scanf("%u", &subjectNum);
    if (subjectNum < 1 || subjectNum > 6)
    {
      printf("Invalid choice. Please enter a number between 1 and 6.\n");
    }
    else
    {
      printf("%s : %i\n", subjectName[subjectNum + 1], my_atoi(array[index][subjectNum + 1]));
    }

    printf("\nDo you want to check about another subject? (Y / N) : ");
    scanf(" %c", &check);
    getchar(); // Clear the input buffer

  } while (check == 'y' || check == 'Y');

  printf("\nThanks for using my application <3");
  Sleep(5000);
}

// Implement strcmp();
int my_strcmp(const char *str1, const char *str2)
{
  int RetVal = 0;

  if ((NULL != str1) && (NULL != str2))
  {
    while (*str1 != '\0' && *str2 != '\0')
    {
      if (*str1 != *str2)
      {
        RetVal = (*str1 > *str2) ? 1 : -1;
        break; // Exit the loop if a difference is found
      }

      str1++;
      str2++;
    }

    // Check if one string is longer than the other
    if (RetVal == 0 && *str1 != '\0')
    {
      RetVal = 1;
    }
    else if (RetVal == 0 && *str2 != '\0')
    {
      RetVal = -1;
    }
  }

  return RetVal;
}

// Implement strlen();
size_t my_strlen(const char *str)
{
  size_t len = 0;

  if (NULL != str)
  {
    while (*str != '\0')
    {
      str++;
      len++;
    }
  }

  return len;
}

// Implement strcpy();
char *my_strcpy(char *dest, const char *src)
{
  char *newDest = dest;

  if (dest != NULL && src != NULL)
  {
    while ((*dest++ = *src++))
      ;
  }

  return newDest;
}

// Implement atoi();
int my_atoi(const char *str)
{
  int result = 0, sign = 1, i = 0;

  // Handle leading whitespaces
  while (isspace(str[i]))
  {
    i++;
  }

  // Handle the sign
  if (str[i] == '-' || str[i] == '+')
  {
    sign = (str[i++] == '-') ? -1 : 1;
  }

  // Convert digits to integer
  while (isdigit(str[i]))
  {
    result = result * 10 + (str[i++] - '0');
  }

  return sign * result;
}
