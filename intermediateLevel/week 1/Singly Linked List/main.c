#include "linkedList_ds.h" // Include the header file for the linked list data structure

node_ds_t *ListHead = NULL; // Initialize the head pointer of the linked list to NULL
linkedList_status_t retVal = LINKED_LIST_NOK;

int main()
{
  uint32_t UserChoice = ZERO_INIT; // Variable to store user input for menu choice
  uint32_t item = ZERO_INIT;
  uint32_t position = ZERO_INIT;

  printf("-> Hello to Single Linked List \n");

  while (1) // Infinite loop to display the menu until the user chooses to quit
  {
    // Display the menu options
    printf("\n");
    printf("===============================\n");
    printf("[1] Insert Node At Beginning \n");
    printf("[2] Insert Node At Position \n");
    printf("[3] Insert Node At End \n");
    printf("[4] Delete Node At Beginning \n");
    printf("[5] Delete Node At Position \n");
    printf("[6] Delete Node At End \n");
    printf("[7] Traversing All Nodes \n");
    printf("[8] Get Length \n");
    printf("[9] Quit from application \n");
    printf("===============================\n");
    printf("\n");

    printf("UserChoice : ");
    scanf("%u", &UserChoice); // Prompt the user to enter their choice

    switch (UserChoice)
    {
      case 1:
        {      
          // Insert a node at the beginning of the linked list
          printf("Please, Enter your number to add : ");
          scanf("%u", &item);
          Insert_Node_At_Beginning(&ListHead, &item, &retVal);
          Display_All_Nodes(ListHead);    
        }
        break; 
      case 2:
        {
          // Insert a node at a specific position in the linked list
          printf("Please, Enter your number to add : ");
          scanf("%u", &item);
          printf("Please, Enter your position : ");
          scanf("%u", &position);
          Insert_Node_At_Position(ListHead, &item, &position);
          Display_All_Nodes(ListHead);
        }
        break;    
      case 3:
        {
          // Insert a node at the end of the linked list
          printf("Please, Enter your number to add : ");
          scanf("%u", &item);
          Insert_Node_At_End(&ListHead, &item);
          Display_All_Nodes(ListHead);
        }
        break;    
      case 4:
        {      
          // Delete a node from the beginning of the linked list
          Delete_Node_At_Beginning(&ListHead);
          Display_All_Nodes(ListHead);    
        }
        break; 
      case 6:
        {
          // Delete a node from the end of the linked list
          Delete_Node_At_End(ListHead);
          Display_All_Nodes(ListHead);
        }
        break;
      case 5:
        {
          // Delete a node from a specific position in the linked list
          printf("Please, Enter your position : ");
          scanf("%u", &position);
          Delete_Node_At_Position(ListHead, &position);
          Display_All_Nodes(ListHead);
        }
        break;    
      case 7:
        {
          // Display all nodes in the linked list
          Display_All_Nodes(ListHead);
        }
        break;
      case 8:
        {
          // Get the length of the linked list
          printf("Length => %u \n", Get_Length(ListHead, &retVal));
        }
        break;
      case 9:
        {
          exit(1); // Quit the application
        }
        break;

      default: // unrecognized choice
        /* Nothing */
        break;
    }
  }

  return 0;
}