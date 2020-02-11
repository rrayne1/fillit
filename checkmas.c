#include <stdio.h>
#include <stdlib.h>

int *search (int *cord) {
	cord[0]++;
	cord[1]++;
	return (cord);
}

int main () {
	int *cord;

	cord[0] = 1;
	cord[1] = 4;
	search(cord);
	printf("%d %d\n", cord[0], cord[1]);
	return (0);
}
