// Die Simulator
//
// Die Simulator simulates any number of die rolls with
// any number of sides within 1 and INT_MAX and prints
// the results in a table and histogram
//
// Date: 4/14/2016
// Written By: Toby Wang


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>


// init_random_number_generator() initiates random number generator
// time: O(1)
void init_random_number_generator(void)
{
  srand(time(NULL));
}


// random_number() returns a random number between 0 and RAND_MAX
// time: O(1)
int random_number(void)
{
  int r = rand();
  return r;
}


// roll_die(numSides) returns a digit between 1 and numSides
// requires: numSides >= 1
// time: O(1)
int roll_die(const int numSides)
{
  assert(numSides >= 1);
  int r = (random_number() % numSides) + 1;
  return r;
}


// print_table(counter, len) prints data stored in counter in a frequency table
// requires: counter != NULL
//           len > 0
// effects: outputs to screen
// time: O(n) where n is the len
void print_table(const int *counter, const int len)
{
  assert(counter);
  assert(len > 0);
  printf("\t\tResults: Table\n");
  printf("Side\t\tFrequency\n");
  for (int i = 0; i < len; i++)
  {
    printf("%d%12d\n", i + 1, counter[i]);
  }
  return;
}


// print_histogram(counter, len) prints data stored in counter 
//   in a histogram
// requires: counter != NULL
//           len > 0
// effects: outputs to screen
// time: O(nm) where n is the len and m is the sum of values
//          stored at all the indices in counter
void print_histogram(const int *counter, const int len)
{
  assert(counter);
  assert(len > 0);
  printf("\t\tResults: Histogram\n");
  printf("Side\t\tFrequency\n");
  for (int i = 0; i < len; i++)
  {
    // print side
    printf("%d\t\t\t", i + 1);
    
    // print frequency
    for (int j = 0; j < counter[i]; ++j)
    {
      printf("*");
    }
    
    printf("\n");
  }
  return;
}


int main(void)
{
  int numRolls = 0;
  int numSides = 0;
  
  printf("Welcome to die simulator!\n");
  init_random_number_generator();
  
  // input number of sides desired
  printf("Enter number of sides: ");
  scanf("%d", &numSides);
  
  // input number of rolls desired
	printf("Enter number of rolls: ");
  scanf("%d", &numRolls);
  printf("\n");
  
  // initiate counter for each side
  int *counter = malloc(numSides * sizeof(int));
  for (int i = 0; i < numSides; i++)
  {
    counter[i] = 0;
  }
  
  // roll die numRolls times
  for (int i = 0; i < numRolls; i++)
  {
    int curRoll = roll_die(numSides);
    counter[curRoll - 1] += 1;
  }
  
  // print results
  print_table(counter, numSides);
  printf("\n");
  print_histogram(counter, numSides);
  
  // clean up memory
  free(counter);
  
	return 0;
}