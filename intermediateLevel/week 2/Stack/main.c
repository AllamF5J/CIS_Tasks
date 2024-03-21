#include "stack_ds.h"

stack_ds_t my_stack;
char_t value[STACK_MAX_SIZE] = {'\0'};
return_status_t validation = STACK_NOK;

// Enum to represent the status of balanced parentheses
typedef enum
{
  RETURN_NOK,
  RETURN_OK

} balanced_status_t;

// Function prototypes
static bool_t check_fun(char_t open, char_t close);
static balanced_status_t balanced_fun();

int main()
{
  // Variable to hold the balanced status of the expression
  balanced_status_t retVal = balanced_fun();

  // Check if stack is initialized correctly
  if (validation == STACK_OK)
  {
    // Print whether the expression is balanced or not
    if (retVal == RETURN_OK)
    {
      printf(" => Balanced \n");
    }
    else
    {
      printf(" => Not Balanced \n");
    }
  }
  else
  {
    printf("Stack is not initialized correctly\n");
  }
  
  return 0;
}

static balanced_status_t balanced_fun()
{
  balanced_status_t balanced = RETURN_NOK;
  uint32_t l_counter1 = ZERO_INIT;

  printf("Enter your expression: ");
  fgets(value, (*(&value + 1) - value), stdin);

  // Initialize the stack and mark validation status accordingly
  if (stack_init(&my_stack) == STACK_OK)
  {
    validation = STACK_OK;

    for (l_counter1 = ZERO; value[l_counter1] != '\0'; ++l_counter1)
    {
      const char brackets[] = "(){}[]";
      char current_char = value[l_counter1];

      // Print only the bracket characters from the expression
      if (strchr(brackets, current_char) != NULL)
      {
        printf("%c", value[l_counter1]);
      }
    }
  }

  // Check balanced parentheses
  for (l_counter1 = ZERO; value[l_counter1] != '\0'; l_counter1++)
  {
    if (value[l_counter1] == '(' || value[l_counter1] == '{' || value[l_counter1] == '[')
    {
      balanced = RETURN_OK;

      // Push opening brackets onto the stack
      stack_push(&my_stack, (uint32_t)value[l_counter1]);
    }
    else if (value[l_counter1] == ')' || value[l_counter1] == '}' || value[l_counter1] == ']')
    {
      uint32_t poppedVal;

      // Pop from the stack and check if closing brackets match
      if (stack_pop(&my_stack, &poppedVal) != STACK_OK || !check_fun((char)poppedVal, value[l_counter1]))
      {
        balanced = RETURN_NOK;
        break;
      }
    }
  }

  if (!(stack_status(&my_stack) == STACK_EMPTY))
  {
    balanced = RETURN_NOK;
  }

  return balanced;
}

// Function to check if an opening bracket matches its corresponding closing bracket
static bool_t check_fun(char_t open, char_t close)
{
  return ((open == '(' && close == ')') ||
          (open == '{' && close == '}') ||
          (open == '[' && close == ']'));
}