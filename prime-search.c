#include <getopt.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "prime-structs.h"
#include "prime-print.h"

bool IsPrime (unsigned long long number);

/**
 * Main entry point.
 *
 * @param argc The argument count.
 * @param argv The argument vector.
 * @return The exit code.
 */
int main(int argc, char *argv[] ) {
  if (argc == 1) {
    printf("\nThis program needs some arguments ...  \n Try prime-search -h \n\n");
  }

  int option = 0;
  int start = -1;
  int end = 0;

  // Handle command line arguments.
  while ((option = getopt(argc, argv, "hvs:e:")) != -1) {
    switch (option) {
      case 's':
        start = atoi(optarg);
        break;

      case 'e':
        end = atoi(optarg);
        break;

      case 'v':
        version_print();
        exit(EXIT_FAILURE);

      case 'h':
        help_print();
        exit(EXIT_FAILURE);

      default:
        usage_print();
        exit(EXIT_FAILURE);
    }
  }

  // This helps keep from core dumps!
  // ie. a bit of conditional error check.
  if ((end < 1) ||  (start <  0) || (end < start)) 
  {
    usage_print();
    exit(EXIT_FAILURE);
  }

  int result = 0;
  struct node_s *current_node;
  struct node_s *end_node;

  // Initialize the end node.
  end_node = NULL;

  for (; end > start; end--) {
    result++;

    // Creating memory space for current node.
    current_node = malloc(sizeof(struct node_s));
    current_node->val_int = end;
    current_node->result = result;

    // Point to next node and set it as the current node.
    current_node->next = end_node;
    end_node = current_node;
  }

  // Reset the head of chain.
  current_node = end_node;

  // Iterate through each node and perform a prime check.
  while (current_node != NULL) {
    if (IsPrime(current_node->val_int)) {
      current_node->val_flag = 1;
    }

    current_node = current_node->next;
  }

  // Reset the head of chain.
  current_node = end_node;

  // Output the data.
  int primesFound = 0;
  while (current_node != NULL) {
    if (current_node->val_flag == 1) {
      //printf("%*s%d", 4, " ", current_node->val_int);
      primesFound++;
    }

    current_node = current_node->next;
  }
  printf("Primes found: %d\n", primesFound);

  return 0;
}

/**
 * Function to determine if an integer is prime.
 * This implements the Sieve of Atkin algorithm.
 * http://en.wikipedia.org/wiki/Sieve_of_Atkin
 *
 * @param number The number to test.
 * @return A value indicating whether the number was prime.
 */
bool IsPrime(unsigned long long number) {
  // Sanity check the input.
  if (number < 2) {
    return false;
  }

  bool isPrime = true;
  if (number > 3) {
    unsigned long long i;

    for (i = 2; i < number; i++) {
      // If the division does not produce a remainder it is not a prime.
      if (number % i == 0) {
        isPrime = false;
        break;
      }
    }
  }

  return isPrime;
}