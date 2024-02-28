#include <stdio.h>
#include <windows.h>

// Number of students and subjects are defined as constants
#define STUDENTS_NUMBER 3
#define SUBJECT_NUMBER 7

float totalMark;

unsigned int arr[STUDENTS_NUMBER][SUBJECT_NUMBER];
unsigned int index1 = 0, index2 = 0, retVal = 0;

// Array of subject names
char *subjectName[SUBJECT_NUMBER] = {"ID       ", "Math     ", "Circuits ", "Chemistry", "Physics  ", "English  ", "Science  "};
char sign[] = "\t\tNow we have an update!!\n\t\tNow you are an 'admin'.\n\tPlease take your time to remember the ID and Password.\nHint : The ID and Password should be the same. ^_^";

_Bool check_student(unsigned int studentID, unsigned int studentPass);
void storeAllGrades(unsigned int array[][SUBJECT_NUMBER], unsigned int rows);
void displayAllGrades(unsigned int array[][SUBJECT_NUMBER], unsigned int rows);
void display_grade();
void display_result(float totalMark);

int main()
{
  // Local Variables
  unsigned int adminID = 0, adminPass = 0;
  unsigned short int repeat = 6, iterator = 0;
  char check = ' ';

  // Display sign message
  for (iterator = 0; iterator < (*(&sign + 1) - sign); ++iterator)
  {
    printf("%c", sign[iterator]);
    Sleep(50);
  }

  // Take ID and check if it's an integer
  printf("\n\nPlease, Enter Your ID : ");
  while (retVal != 1)
  {
    retVal = (unsigned int)scanf("%u", &adminID);
    if (retVal != 1)
    {
      printf("\nInvalid Input! \nPlease, Enter Your ID Again : ");
      while (getchar() != '\n')
        ; // Clear the input buffer
    }
  }
  retVal = 0; // Reset validation

  // Take Password and check if it's an integer
  printf("Please, Enter Your Password : ");
  while (retVal != 1)
  {
    retVal = (unsigned int)scanf("%u", &adminPass);
    if (retVal != 1)
    {
      printf("\nInvalid Input! \nPlease, Enter Your Password Again : ");
      while (getchar() != '\n')
        ; // Clear the input buffer
    }
  }
  retVal = 0; // Reset validation

  // Check if ID ends with 5 and ID equals Password
  if (check_student(adminID, adminPass))
  {
    printf("\n\t\t\tWelcome <3\n\t\tPlease wait ");
    while (repeat--)
    {
      printf(". ");
      Sleep(500);
    }

    storeAllGrades(arr, STUDENTS_NUMBER);
    displayAllGrades(arr, STUDENTS_NUMBER);

    printf("\nDo you want to check about subject degree? ( Y / N): ");
    if ((scanf(" %c", &check)) && (check == 'y' || check == 'Y'))
    {
      printf("\nPlease, Enter student ID to validate it. Then Press ENTER : ");
      scanf("%u", &adminID);

      for (index1 = 0; index1 < STUDENTS_NUMBER; ++index1)
      {
        if (arr[index1][0] == adminID)
        {
          display_grade(index1 /*, subjectNumber*/);
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
  }
  else
  {
    printf("\nInvalid ID or Password \nPlease try again later \n");
    Sleep(5000);

    return 0;
  }

  return 0;
}

_Bool check_student(unsigned int adminID, unsigned int adminPass)
{
  return (adminID != 0) && (adminID % 10 == 5) && (adminPass == adminID);
}

void storeAllGrades(unsigned int array[][SUBJECT_NUMBER], unsigned int rows)
{
  printf("\n\nEnter Grades For Subject.\n\n");
  for (index1 = 0; index1 < rows; ++index1)
  {
    retVal = 0; // Reset validation

    // Take ID and check if it's an integer
    printf("\nPlease, Enter ID For Student %d : ", (index1 + 1));
    while (retVal != 1)
    {
      retVal = (unsigned int)scanf("%u", &array[index1][0]);
      if (retVal != 1 || array[index1][0] % 10 != 5)
      {
        printf("\nInvalid Input! \nPlease, Enter ID Again : ");
        while (getchar() != '\n')
          ;         // Clear the input buffer
        retVal = 0; // Reset validation
      }
    }
    retVal = 0; // Reset validation

    // Store the rest of grades
    for (index2 = 1; index2 < SUBJECT_NUMBER; ++index2)
    {
      printf("%s : ", subjectName[index2]);
      scanf("%u", &array[index1][index2]);
      totalMark += (float)array[index1][index2];
    }
    totalMark /= (SUBJECT_NUMBER - 1);

    // Print percentage and overall rating.
    printf("\nPercentage: %0.2f%%  ", totalMark);
    display_result(totalMark);

    // Motivating sentence
    if (totalMark > 50.0)
    {
      printf("\nCongratulations, Your hard work paid off. \n");
    }
    else
    {
      printf("\nKeep trying, Success is a journey, not a destination. \n");
    }
    
    totalMark = 0;

    printf("\n");
  }
}

void displayAllGrades(unsigned int array[][SUBJECT_NUMBER], unsigned int rows)
{
  char *subjectTable[SUBJECT_NUMBER] = {"ID", "Math", "Circuits", "Chemistry", "Physics", "English", "Science"};
  for (index1 = 0; index1 < rows; ++index1)
  {
    for (index2 = 0; index2 < SUBJECT_NUMBER; ++index2)
    {
      printf("%s: %u\t", subjectTable[index2], array[index1][index2]);
    }
    printf("\n");
  }
}

void display_grade(unsigned int index)
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
      printf("%s : %u\n", subjectName[subjectNum], arr[index][subjectNum]);
    }

    printf("\nDo you want to check about another subject? (Y / N) : ");
    scanf(" %c", &check);
    getchar(); // Clear the input buffer

  } while (check == 'y' || check == 'Y');

  printf("\nThanks for using my application <3");
  Sleep(5000);
}

void display_result(float totalMarks)
{
  if (totalMarks >= 85.0)
  {
    printf("Excellent \n");
  }
  else if (totalMarks >= 75.0)
  {
    printf("Very Good \n");
  }
  else if (totalMarks >= 65.0)
  {
    printf("Good \n");
  }
  else if (totalMarks >= 50.0)
  {
    printf("Pass \n");
  }
  else
  {
    printf("You Failed Successfully ^_^ \n");
  }
}