#include <stdio.h>
#include <stdlib.h>


typedef struct s_try {
	int a[3];
	int b[3];
	char ch;
} t_try;

void fulltry (t_try *tr1) {
	int i;

	i = 0;
	while (i < 3) {
		tr1->a[i] = i;
		i++;
	}
	i = 0;
	while (i < 3) {
		tr1->b[i] = i + 3;
		i++;
	}
	tr1->ch = 'A';
}

int main (void) {
	t_try *tr1;

	fulltry(tr1);
	printf("%d ", tr1->a[0]);
	printf("%d ", tr1->a[1]);
	printf("%d ", tr1->a[2]);
	printf("%d ", tr1->b[0]);
	printf("%d ", tr1->b[1]);
	printf("%d ", tr1->b[2]);
	printf("%c\n", tr1->ch);
	return (0);
}
