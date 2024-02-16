#include <stdio.h>

#define MAX_NAME_LENGTH 50
#define SUBJECT_NUMBER 6

// Global Variables
char studentName[MAX_NAME_LENGTH];
float grades[SUBJECT_NUMBER];
unsigned int studentID;

int main() 
{
  // Local Variables
  unsigned int Grade = 0;
  unsigned short int index = 0;
  unsigned short int retVal = 0;
  float totalMark = 0;

  // Take Data From Student.
  printf("Please, Enter Your Name : ");
  gets(studentName); // For Taking All Sentence Not One Word. "gets" is a bad practise but i using it for simplicity. Cause Overflow.

  printf("Please, Enter Your ID : ");
  while (retVal != 1)
  {
    retVal = scanf("%i", &studentID);
    if (retVal != 1) 
    {
      printf("\nInvalid Input! \nPlease, Enter Your ID Again : ");
      while (getchar() != '\n'); // Clear the input buffer
    }
  }

  // Check if ID ends with number 5.
  if (studentID % 10 != 5) 
  {
    printf("Invalid ID. \n");

    return 0;
  }

  // Take grades for 6 subjects
  printf("\nEnter Grades For Your Subject : \n\n");
  for (index = 0; index < SUBJECT_NUMBER; ++index) 
  {
    printf("Subject %i : ", index + 1);
    scanf("%f", &grades[index]);
  }
  printf("\n");

  // Calculate percentage
  for (index = 0; index < SUBJECT_NUMBER; ++index) 
  {
    totalMark += grades[index];
  }
  totalMark /= SUBJECT_NUMBER;
  Grade = (unsigned int)totalMark;

  // Display the percentage
  printf("Percentage: %0.2f%%  ", totalMark);

  if(totalMark > 100)
  {
    printf("You're a Fuck'in Dragon !! \n");
  }

  // Display the letter grade
  switch (Grade)
  {
    case 85 ... 100:  // My Compiler allow This Extension. GCC version 13.2.0 => Copyright (C) 2023.
      printf("Excellent \n");
      break;
    case 75 ... 84:
      printf("Very Good \n");
      break;
    case 65 ... 74:
      printf("Good \n");
      break;
    case 50 ... 64:
      printf("Pass \n");
      break;
    case 0 ... 49:
      printf("You Failed Successfully ^_^ \n");
      break;
    default: // unrecognized Grade
      /* Nothing */
      break;
  }

  // Motivating sentence
  if (Grade > 50)  // Black Box is helping me ^_^ in this sentences.
  {
    printf("\nCongratulations, %s! Your hard work paid off. \n", studentName);
  } 
  else 
  {
    printf("\nKeep trying, %s! Success is a journey, not a destination. \n", studentName);
  }
  
  return 0;
}

