// mileage_reimbursement.c - IMPLEMENTATION

#include <stdio.h>
#include <stdlib.h>

#include "mileage_reimbursement.h"

//Constant
#define KMS_PER_MILE 1.6
#define VERSION 5
#define RATEPERMILE 0.35

// Return title of the program
char *mileage_reimbursement_get_title()
{
  return "Mileage Reimbursement Calculator Program";
}

int mileage_reimbursement_menu()
{
  //Display Title and Version Info
  printf("\nMILEAGE REIMBURSEMENT CALCULATOR - Version %d\n", VERSION);
  puts("Code by Roger Martinez\n");

  //Get the inputs
  double miles_start;
  double miles_end;
  
  printf("Enter beginning odometer reading: ");
  scanf("%lf", &miles_start);

  printf("Enter ending odometer reading: ");
  scanf("%lf", &miles_end);
  
  //Make the calculation
  double total_miles;
  double reimbursement;

  total_miles = miles_end - miles_start;
  reimbursement = total_miles * RATEPERMILE;

  //Display Results
  printf("\nYou traveled %.2lf miles. At $%.2lf:\n", total_miles, RATEPERMILE);
  printf("\nYour reimbursement is %.2lf\n", reimbursement);

  getchar();
  return 0;
}