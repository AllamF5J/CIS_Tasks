#include <stdio.h>
#include <windows.h>

#define SUBJECT_NUMBER 6

// Global Variable
float grades[SUBJECT_NUMBER];
float totalMark;

// Function Declartion
_Bool check_student(signed int studentID, signed int studentPass);
float calculator_grade();
void display_result(float totalMark);

int main()
{
  // Local Variables
  signed int studentID = 0, studentPass = 0, retVal = 0;
  unsigned short int repeat = 6;

  // Take ID and check about it's integer.
  printf("Please, Enter Your ID : ");
  while (retVal != 1)
  {
    retVal = scanf("%d", &studentID);
    if (retVal != 1)
    {
      printf("\nInvalid Input! \nPlease, Enter Your ID Again : ");
      while (getchar() != '\n')
        ; // Clear the input buffer
    }
  }

  retVal = 0; // To Reset Validaton

  // Take Password and check about it's integer.
  printf("Please, Enter Your Password : ");
  while (retVal != 1)
  {
    retVal = scanf("%d", &studentPass);
    if (retVal != 1)
    {
      printf("\nInvalid Input! \nPlease, Enter Your Password Again : ");
      while (getchar() != '\n')
        ; // Clear the input buffer
    }
  }

  // Check if ID ends by (5) and ID equal Password
  if (check_student(studentID, studentPass))
  {
    printf("\n\t\t\tWelcome <3\n\t\t\tPlease wait ");
    while (repeat--)
    {
      printf(". ");
      Sleep(500);
    }

    // Print percentage and overall rating.
    printf("Percentage: %0.2f%%  ", calculator_grade());
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
  }
  else
  {
    printf("\nInvalid ID or Password \nPlease try again later \n");
    Sleep(5000);

    return 0;
  }

  return 0;
}

// Check if ID ends by (5) and ID equal Password
_Bool check_student(signed int studentID, signed int studentPass)
{
  return ((studentID % 10 == 5) && (studentPass == studentID));
}

// Take a degree from user and calculate a total grade
float calculator_grade()
{
  unsigned short int index = 0;

  printf("\n\nEnter Grades For Your Subject : \n\n");
  for (index = 0; index < SUBJECT_NUMBER; ++index)
  {
    printf("Subject %i : ", index + 1);
    scanf("%f", &grades[index]);
    totalMark += grades[index];
  }
  printf("\n");

  // Calculate percentage
  totalMark /= SUBJECT_NUMBER;
  return totalMark;
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
