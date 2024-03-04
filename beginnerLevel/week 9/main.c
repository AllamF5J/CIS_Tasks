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
  unsigned int grades[SUBJECT_NUMBER - 2]; // Grades for Math to Science

} Student_info;

typedef enum
{
  Math,
  Circuits,
  Chemistry,
  Physics,
  English,
  Science

} subjects;

// Global Variable
char *subjectName[SUBJECT_NUMBER - 2] = {"Math     ", "Circuits ", "Chemistry", "Physics  ", "English  ", "Science  "};
Student_info studentData[STUDENTS_NUMBER];
subjects Subjects = Math;
unsigned int index1 = 0, retVal = 0, StudentID = 0;
static unsigned int indexs = 0;
float totalMark = 0;
char check = '\0';

// Function prototypes
void storeAllGrades(Student_info array[], unsigned int size);
void displayAllGrades(Student_info array[]);
void display_result(float totalMark);
void display_grade(Student_info array[], unsigned int index);

int main()
{
  printf("\t\t\t ___________________________________________________________________ \n");
  printf("\t\t\t|                   Welcome in my application                       |\n");
  printf("\t\t\t|     Hint: Please don't close the program until choose number 4    |\n");
  printf("\t\t\t|___________________________________________________________________|\n");

  Sleep(800);
  do
  {
    unsigned int cases = 0;

    Sleep(1500);
    printf("\n[1] Add new student information\n[2] Print all students' information\n");
    printf("[3] Print a specific student information\n[4] Stop the program\n");
    printf("_______________________________________\n");
    printf("Your choice : ");

    while (retVal != 1)
    {
      retVal = (unsigned int)scanf(" %u", &cases);
      if (retVal != 1)
      {
        printf("\nInvalid Input! \nPlease, Enter valid choice : ");
        while (getchar() != '\n')
          ; // Clear the input buffer
      }
    }
    printf("\n");
    retVal = 0; // Reset validation

    switch (cases)
    {
      case 1:
        {
          if (indexs < 3)
          {
            storeAllGrades(studentData, STUDENTS_NUMBER);
          }
          else
          {
            printf("Sorry you registered all existing students \n\n");
          }
        }
        break;
      case 2:
        if (indexs != 0)
        {
          displayAllGrades(studentData);
        }
        else
        {
          printf("=> Sorry there are no students who registered their data \n\n");
        }
        break;
      case 3:
        {
          if (indexs != 0)
          {
            printf("\nDo you want to check about subject degree? ( Y / N ) : ");

            // Validate user input and proceed accordingly.
            if ((scanf(" %c", &check)) && (check == 'y' || check == 'Y'))
            {
              printf("\nPlease, Enter student ID to validate it. Then Press ENTER : ");
              scanf("%u", &StudentID);

              for (index1 = 0; index1 < STUDENTS_NUMBER; ++index1)
              {
                if (studentData[index1].id == StudentID)
                {
                  for (Subjects = Math; Subjects <= Science; ++Subjects)
                  {
                    totalMark += (float)studentData[index1].grades[Subjects];
                  }
                  totalMark /= (SUBJECT_NUMBER - 2);

                  Sleep(1000);
                  printf("\n\n_______________________________________\n");
                  // Print percentage and overall rating.
                  printf("\nPercentage: %0.2f%%  ", totalMark);
                  display_result(totalMark);

                  // Motivating sentence
                  if (totalMark > 50.0)
                  {
                    printf("\nCongratulations, %s! Your hard work paid off. \n", studentData[index1].name);
                  }
                  else
                  {
                    printf("\nKeep trying, %s! Success is a journey, not a destination. \n", studentData[index1].name);
                  }
                  printf("_______________________________________\n");

                  Sleep(1000);
                  totalMark = 0;

                  // Display the student's grade.
                  display_grade(studentData, index1);

                  break;
                }
              }

              // After the loop, check if the ID was not found
              if (index1 == STUDENTS_NUMBER)
              {
                printf("Wrong ID.\n");

                Sleep(5000);
              }
            }
            else if ((check == 'n' || check == 'N'))
            {
              Sleep(1000);
            }
            else
            {
              printf("Invalid input.\n");
              Sleep(1000);
            }
          }
          else
          {
            printf("=> Sorry there are no students who registered their data \n\n");
          }
        }
        break;
      case 4:
        printf("\n\t\t\tThanks for using my application <3");

        Sleep(5000);
        return 0;
        break;
      default: // unrecognized Grade
        /* Nothing */
        break;
    }

  } while (1);

  return 0;
}

// Function to store grades for subjects
void storeAllGrades(Student_info array[], unsigned int size)
{
  printf("\nAdd new student information.\n\n");

  for (/*indexs = 0*/; indexs < size; /*++indexs*/)
  {
    retVal = 0; // Reset validation

    // Take ID and check if it's an integer
    printf("\nPlease, Enter ID For Student %d : ", (indexs + 1));
    while (retVal != 1)
    {
      retVal = (unsigned int)scanf("%u", &array[indexs].id);
      if (retVal != 1 || array[indexs].id % 10 != 5)
      {
        printf("\nInvalid Input! \nPlease, Enter ID Again : ");
        while (getchar() != '\n')
          ;         // Clear the input buffer
        retVal = 0; // Reset validation
      }
    }

    retVal = 0; // Reset validation

    // Take name
    printf("Please, Enter Name For Student %d : ", (indexs + 1));
    while (retVal != 1)
    {
      retVal = (unsigned int)scanf("%s", array[indexs].name);
      if (retVal != 1)
      {
        printf("\nInvalid Input! \nPlease, Enter valid name : ");
        while (getchar() != '\n')
          ; // Clear the input buffer
      }
    }

    retVal = 0;    // Reset validation
    totalMark = 0; // Store the rest of grades

    for (Subjects = Math; Subjects <= Science; ++Subjects)
    {
      printf("%s : ", subjectName[Subjects]); // Assuming subjectName is a global array of subject names

      while (retVal != 1)
      {
        retVal = (unsigned int)scanf("%u", &array[indexs].grades[Subjects]);
        if (retVal != 1)
        {
          printf("\nInvalid Input! \nPlease, Enter valid degree : ");
          while (getchar() != '\n')
            ; // Clear the input buffer
        }
      }

      retVal = 0; // Reset validation
    }

    Sleep(1000);
    printf("\nComplete......\n");
    printf("__________________________________________________________\n");
    ++indexs;

    break;
  }
}

// Function to display all grades
void displayAllGrades(Student_info array[])
{
  char *subjectTable[SUBJECT_NUMBER] = {"ID", "Name", "Math", "Circuits", "Chemistry", "Physics", "English", "Science"};

  for (index1 = 0; index1 < indexs; ++index1)
  {
    printf("ID: %u\tName: %s\t", array[index1].id, array[index1].name);

    for (Subjects = Math; Subjects <= Science; ++Subjects)
    {
      printf("%s: %u\t", subjectTable[Subjects + 2], array[index1].grades[Subjects]);
    }

    printf("\n");
  }
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

void display_grade(Student_info array[], unsigned int index)
{
  unsigned int subjectNum = 0;

  do
  {
    printf("\nPlease Enter a number of subject you want to display.\n\n");
    printf("[1] Math\n[2] Circuits\n[3] Chemistry\n[4] Physics\n[5] English\n[6] Science\nEnter your choice: ");
    while (retVal != 1)
    {
      retVal = (unsigned int)scanf("%u", &subjectNum);
      if (retVal != 1)
      {
        printf("\nInvalid Input! \nPlease, Enter valid choice : ");
        while (getchar() != '\n')
          ; // Clear the input buffer
      }
    }
    retVal = 0; // Reset validation

    if (subjectNum < 1 || subjectNum > 6)
    {
      printf("Invalid choice. Please enter a number between 1 and 6.\n");
    }
    else
    {
      printf("\n%s : %u\n", subjectName[subjectNum - 1], array[index].grades[subjectNum - 1]);
    }

    printf("\nDo you want to check about another subject? (Y / N) : ");
    while (retVal != 1)
    {
      retVal = (unsigned int)scanf(" %c", &check);
      if (retVal != 1)
      {
        printf("\nInvalid Input! \nPlease, Enter valid choice : ");
        while (getchar() != '\n')
          ; // Clear the input buffer
      }
    }
    retVal = 0; // Reset validation

  } while (check == 'y' || check == 'Y');

  printf("%s\n", (check == 'n' || check =='N')? "" : "Invalid choice.");
  Sleep(1000);

  printf("\n\n");
}