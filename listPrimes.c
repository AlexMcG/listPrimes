#include "stdio.h"

#define INPUT_MAX 22

void listPrimes(unsigned long start, unsigned long stop);

int main() {
	while(1) {		
		//initialize variables
		unsigned long start = 2;
		unsigned long stop = 2;
		
		//describes program and prompt for input
		printf("This program lists all the prime numbers in a given range.\n");
		printf("Enter a start and stop value greater than one. Stop must be greater than start.\n");
		printf("Enter i for all primes. Enter q to quit.\n");
		
		//get input and check for length
		char input[INPUT_MAX];
		int index = 0;
		char ch = getchar();
		while (ch != '\n' && ch != EOF) {
			if (index < INPUT_MAX) input[index] = ch;
			index++;
			ch = getchar();
		}
		
		//parse input
		int check = sscanf(input, "%lu %lu", &start, &stop);
		
		//debug
		//printf("input %s\n", input);
		//printf("start: %lu stop: %lu check: %d\n", start, stop, check);
		
		//check for non-range options, check for errors, and call listPrimes
		if (input[0] == 'q' || input[0] == 'Q') return 1;
		else if (input[0] == 'i' || input[0] == 'I') listPrimes(2, 0);
		else if (check < 2 || start >= stop || start < 2 || stop < 2 || input == NULL || index >= INPUT_MAX) {
			printf("INPUT ERROR\n");
			continue;
		}
		else listPrimes(start, stop);
	}
	return 0;
}

//lists prime numbers frome number start to number stop
void listPrimes(unsigned long start, unsigned long stop) {
	unsigned int prime = start;
	while (prime <= stop || !stop) {
		int divisor = 2;
		while (prime % divisor != 0) divisor++;
		if (divisor == prime) printf("%d ", prime);
		prime++;
	}
	printf("\n");
}
