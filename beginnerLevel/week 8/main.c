#include <stdio.h>
#include <ctype.h>
#include <windows.h>
#include <stdlib.h>

// Macros
#define STUDENTS_NUMBER 3
#define MAX_NAME_LENGTH 50
#define SUBJECT_NUMBER 8

// Student Info Struct
typedef struct
{
  char name[MAX_NAME_LENGTH];
  unsigned int id;
  float grades[SUBJECT_NUMBER - 2]; // Grades for Math to Science
} Student_info;

// Global Variable
Student_info studentData[STUDENTS_NUMBER];
char *subjectName[SUBJECT_NUMBER] = {"ID       ", "Name     ", "Math     ", "Circuits ", "Chemistry", "Physics  ", "English  ", "Science  "};
unsigned int index1 = 0, index2 = 0, retVal = 0;
float totalMark = 0;

// Function prototypes
unsigned int search_for_name(Student_info array[], unsigned int size, const char *name);
void storeAllGrades(Student_info array[], unsigned int size);
void displayAllGrades(Student_info array[], unsigned int size);
void display_result(float totalMark);
void display_grade(unsigned int index, Student_info array[]);

// Custom Implemetion Functions.
int my_strcmp(const char *str1, const char *str2);

int main()
{
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
      if (studentData[index1].id == StudentID)
      {
        // Display the student's grade
        display_grade(index1, studentData);
        break;
      }
    }

    // After the loop, check if the ID was not found
    if (index1 == STUDENTS_NUMBER)
    {
      printf("Wrong ID.\n");
      Sleep(5000);

      return 0;
    }
  }
  else
  {
    printf("\nInvalid ID or Password \nPlease try again later \n");
    Sleep(5000);

    return 0;
  }

  return 0;
}

// Function to store grades for subjects
void storeAllGrades(Student_info array[], unsigned int size)
{
  printf("\nEnter Grades For Subjects.\n\n");

  for (index1 = 0; index1 < size; ++index1)
  {
    retVal = 0; // Reset validation

    // Take ID and check if it's an integer
    printf("\nPlease, Enter ID For Student %d : ", (index1 + 1));
    while (retVal != 1)
    {
      retVal = (unsigned int)scanf("%u", &array[index1].id);
      if (retVal != 1 || array[index1].id % 10 != 5)
      {
        printf("\nInvalid Input! \nPlease, Enter ID Again : ");
        while (getchar() != '\n')
          ;         // Clear the input buffer
        retVal = 0; // Reset validation
      }
    }

    // Take name
    printf("Please, Enter Name For Student %d : ", (index1 + 1));
    scanf("%s", array[index1].name);

    // Store the rest of grades
    totalMark = 0;

    for (index2 = 2; index2 < SUBJECT_NUMBER; ++index2)
    {
      printf("%s : ", subjectName[index2]); // Assuming subjectName is a global array of subject names
      scanf("%f", &array[index1].grades[index2 - 2]);
      totalMark += array[index1].grades[index2 - 2];
    }
    totalMark /= (SUBJECT_NUMBER - 2);

    // Print percentage and overall rating.
    printf("\nPercentage: %0.2f%%  ", totalMark);
    display_result(totalMark);

    // Motivating sentence
    if (totalMark > 50.0)
    {
      printf("\nCongratulations, %s! Your hard work paid off. \n", array[index1].name);
    }
    else
    {
      printf("\nKeep trying, %s! Success is a journey, not a destination. \n", array[index1].name);
    }

    printf("\n");
  }
}

// Function to display all grades
void displayAllGrades(Student_info array[], unsigned int size)
{
  char *subjectTable[SUBJECT_NUMBER] = {"ID", "Name", "Math", "Circuits", "Chemistry", "Physics", "English", "Science"};

  for (index1 = 0; index1 < size; ++index1)
  {
    printf("ID: %u\tName: %s\t", array[index1].id, array[index1].name);

    for (index2 = 2; index2 < SUBJECT_NUMBER; ++index2)
    {
      printf("%s: %.1f\t", subjectTable[index2], array[index1].grades[index2 - 2]);
    }

    printf("\n");
  }
}

// To search about how many times the name of the student is repeated.
unsigned int search_for_name(Student_info array[], unsigned int size, const char *name)
{
  unsigned int count = 0;

  for (index1 = 0; index1 < size; ++index1)
  {
    if (my_strcmp(array[index1].name, name) == 0)
    {
      count++;
    }
  }

  return count;
}

void display_result(float totalMarks)
{
  printf("%s",
         (totalMarks >= 85.0)   ? "Excellent \n"
         : (totalMarks >= 75.0) ? "Very Good \n"
         : (totalMarks >= 65.0) ? "Good \n"
         : (totalMarks >= 50.0) ? "Pass \n"
                                : "You Failed Successfully ^_^ \n");
}

void display_grade(unsigned int index, Student_info array[])
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
      printf("%s : %.2f\n", subjectName[subjectNum + 1], array[index].grades[subjectNum - 1]);
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
