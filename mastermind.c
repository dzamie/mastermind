#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void disp_arr(int *array) {
	int i;
	for(i= 0; i < 4; i ++) {
		printf("%d", array[i]);
	}
}

int main() {
	int secret[]= {9,9,9,9};
	int s_copy[4];
	int guess[]= {-1,-1,-1,-1};
	int guess_num;
	int guesses= 0;
	int black= 0;
	int white= 0;
	int i, j;
	
	srand(time(NULL));
	
	for(i= 0; i < 4; i ++) {
		secret[i]= rand() % 5;
	}
	// secret now set up
	
	while(black < 4) {
		guesses ++;
		for(i= 0; i < 4; i ++) {
			s_copy[i]= secret[i];
		}
		black= 0;
		white= 0;
		printf("Your guess (4x[0-4]): ");
		scanf("%d", &guess_num);
		
		for(i= 3; i >= 0; i --) {
			guess[i]= guess_num % 10;
			guess_num /= 10;
		}
		for(i= 0; i < 4; i ++) {
			if(s_copy[i] == guess[i]) {
				black ++;
				s_copy[i]= -1;
				guess[i]= -2;
			}
		}
		for(i= 0; i < 4; i ++) {
			for(j= 0; j < 4; j ++) {
				if(guess[i] == s_copy[j]) {
					white ++;
					guess[i]= -2;
					s_copy[j]= -1;
					j= 4;
				}
			}
		}
		printf("Black: %d\nWhite: %d\n", black, white);
	}
	printf("You win! The answer was ");
	disp_arr(secret);
	printf("!\n");
	printf("You took %d guesses to win.\n", guesses);
}