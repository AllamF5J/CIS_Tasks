#include "stack_ds.h"

return_status_t stack_status(stack_ds_t *my_stack)
{
  return ((!my_stack) ? STACK_NULL_POINTER : (my_stack->stack_pointer == STACK_MAX_SIZE - 1) ? STACK_FULL :
                                             (my_stack->stack_pointer == -1) ? STACK_EMPTY :
                                                                               STACK_NOT_FULL);
}
return_status_t stack_init(stack_ds_t *my_stack)
{
  return_status_t retVal = STACK_NOK;

  if (NULL != my_stack)
  {
    retVal = STACK_OK;

    my_stack->stack_pointer = -1;
  }
  else
  {
    retVal = STACK_NULL_POINTER;
  }

  return retVal;
}

return_status_t stack_push(stack_ds_t *my_stack, uint32_t value)
{
  return_status_t retVal = STACK_NOK;

  if (NULL != my_stack)
  {
    if (stack_status(my_stack) == STACK_FULL)
    {
      retVal = STACK_FULL;
    }
    else
    {
      retVal = STACK_OK;

      my_stack->Data[++my_stack->stack_pointer] = (char_t)value;
    }
  }
  else
  {
    retVal = STACK_NULL_POINTER;
  }

  return retVal;
}

return_status_t stack_pop(stack_ds_t *my_stack, uint32_t *value)
{
  return_status_t retVal = STACK_NOK;

  if ((NULL != my_stack) || (NULL != value))
  {
    retVal = STACK_OK;

    if (stack_status(my_stack) != STACK_EMPTY)
    {
      *value = (uint32_t)my_stack->Data[my_stack->stack_pointer--];
    }
    else
    {
      retVal = STACK_EMPTY;
    }
  }
  else
  {
    retVal = STACK_NULL_POINTER;
  }

  return retVal;
}
