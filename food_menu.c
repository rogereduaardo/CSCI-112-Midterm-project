// food_menu.c - IMPLEMENTATION

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "food_menu.h"

#define ORDER_PREP_TIME 10 

// Return title of the program
char *food_menu_get_title()
{
  return "Food Menu Program";
}

int num_apples = 0;
int num_burguer = 0;
int num_corn = 0;
int num_drinks = 0;
int num_extras = 0;
int num_fries = 0;

void display_welcome()
{
  //printf("TODO: %s\n", __FUNCTION__); 
  puts("\nWelcome to our new online orrdering system!");
}
void ask_about_specials()
{
  //printf("TODO: %s\n", __FUNCTION__); 
  printf("\nDo you want to see today's specail (y/n): ");
  int c = getchar();
  //printf("c: %c\n", c);
  if (c == 'y' || c == 'Y')
  {
    puts("\nHere are today's specials...");
  }
  // Now "eat" the trailing newline character
  getchar();
}

// Return 1 (true) if takeout
// Return 0 (false) if delivery
// Return -1 on error
int determine_takeout_or_delivery()
{
  printf("\nIs this takeout or delivery (t/d): ");
  int c = getchar();
  //printf("c: %d - %c\n", c, c);
  getchar(); // Eat the return/enter key
  if (c == 'd' || c == 'D')
  {
    return 0; // Return 0 for delivery
  }
  else if (c == 't' || c == 'T')
  {
    return 1; // Return 1 for takeout
  }
   
    return -1; // Return error condition
   
}

void display_menu()
{
  puts("\nMenu Options:");
  puts(" a)Apple\n b)Burger\n c)Corn\n d)Drink\n e)Extra\n f)Fries\n q)Quit");
}

void take_the_order()
{
  // While taking the order
  int taking_order = 1; //true
  while (1 == taking_order)
    {
      display_menu();
      int choice = getchar(); //read_choice();
      printf("\nchoice: %c\n", choice);
      getchar(); // Eat the return /enter key
      //if (choice == 1)
      switch (choice)
        {
          case 'a': 
           num_apples++;
           break;
          case 'A': 
           num_apples++;
           break;
          case 'b':
           num_burguer++;
           break;
           case 'B':
           num_burguer++;
           break;
          case 'c':
           num_corn++;
           break;
          case 'C':
           num_corn++;
           break;
          case 'd':
           num_drinks++;
           break;
           case 'D':
           num_drinks++;
           break;
          case 'e':
           num_extras++;
           break;
          case 'E':
           num_extras++;
           break;
           case 'f':
           num_fries++;
           break;
           case 'F':
           num_fries++;
           break;
          case 'q': return;
          case 'Q': return;
          default: puts("Please enter menu choice");
        }
    }

  /*
 int num_apples = 0;
 int num_burguer = 0;
 int num_corn = 0;
 int num_drinks = 0;
 int num_extras = 0;
 int num_fries = 0;
  */
  // - display menu
  // - read choice
  // - if choice is all done then return
  
}

 int select_payment_method()
{

    int payment_method;
    while (1 == payment_method)
    {
      printf("\nSelect your payment method: ");
      printf("\n 1) Cash;\n 2) Charge;\n 3) Crypto:\n");
      int c = getchar();
      getchar(); // Eat the return/enter
      switch(c) 
      {
        case '1':
          puts("\nYou have selected cash.");
          payment_method = 1;
         return payment_method;
        case '2':
          puts("\nYou have selected charge.");
         payment_method = 2;
         return payment_method;
        case '3':
          puts("\nYou have selected crypto.");
          payment_method = 3;
          return payment_method;
        default:puts("\nError: Must select one option: cash, charge, crypto");
        break;
      }
    }
}

int food_menu_menu()
  {
  // Display Welcome too the Food Store
  display_welcome();
  
  // Ask if specialas are display
  ask_about_specials();

  // Handle takeout or delivery
  int result;
  result = determine_takeout_or_delivery();
  if (result == 1)
  {
    puts("TODO: Handle Takeout details");
  }
  else if ( result == 0)
  {
    puts("TODO: Handle Delivery details");
  }
  else
  {
   puts("Error: Must select either Takeout or Delivery");
   exit(0); 
  }

  // Take the order
  take_the_order();

  // Add items and calaculate the price
  int total = num_apples + num_burguer + num_corn + num_drinks + num_extras + 
  num_fries;
  printf("\nYour order is:\n");
  if (0 != num_apples)
  {
    printf("num_apples: %d\n", num_apples);
  }
  if (0 != num_burguer)
  {
    printf("num_burguers: %d\n", num_burguer);
  }
  if (0 != num_corn)
  {
    printf("num_corn: %d\n", num_corn);
  }
  if (0 != num_drinks)
  {
    printf("num_drinks: %d\n", num_drinks);
  }
  if (0 != num_extras)
  {
    printf("num_extras: %d\n", num_extras);
  }
  if (0 != num_fries)
  {
    printf("num_fries: %d\n", num_fries);
  }
  printf("\nYour total is %d dollars\n", total);

  // Handle payment method
  select_payment_method();

  
  // Display the order summary andd order time
  time_t now;
  now = time(NULL);
  printf("Your order was placed at:\n");
  char *now_str;
  now_str = ctime(&now);
  printf("%s", now_str);

  printf("Your order total was: %d dollars\n", total);

  printf("Your order wiill be ready in %d minutes\n", ORDER_PREP_TIME);
  
  return 0;
}