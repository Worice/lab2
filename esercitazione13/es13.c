#include <stdlib.h>
#include <stdio.h>
#include "es13.h"
#define DIM 100;

/* 
 * Potete usare `coefficiente_binomiale` per implementare la funzione `potenza_binomio`.
 * Visto che una variabile di tipo `int` occupa 32 bit, si possono verificare overflow
 * per valori di `n` maggiori o uguali a 13. Nella fase di test saranno usati solo valori
 * tali per cui non si verifichino overflow.
 */



int fattoriale(int n) {
	int i, f;

	f = 1;
	for (i = 2; i <= n; i++) {
		f *= i;
	}
	return f;
}

int coefficiente_binomiale(int n, int k) {
	return fattoriale(n) / (fattoriale(k) * fattoriale(n-k));
}

int maxGrad(int, int);

int maxGrad(int x, int y){             /*Find the biggets grade*/
        if(x > y)
                return x;
        else
                return y;
}

/* Esercizi da implementare. */
void somma(int p1[], int n1, int p2[], int n2, int pr[], int *nr) {

        int i, grad = 0, sum = 0;
        int max = maxGrad(n1, n2);      /*Call function to check highest grade*/

	/*First polynomial*/
        printf("\n\n>We are going to sum a polynom of grade %d, that is\n\n\t", n1);
        for(i = 0; i <= n1; ++i){
                if(p1[n1 - i] > 0)
                        printf("+");
                printf("%dx^%d ", p1[n1 - i], n1 - i);
        }
	/*Second polynomial*/
        printf("\n\n>and a second polynome of grade %d, that is:\n\n\t", n2);
        for(i = 0; i <= n2; ++i){
                if(p2[n2 - i] > 0)
                        printf("+");
                printf("%dx^%d ", p2[n2  - i], n2 - i);
        }
        printf("\n\n");

        nr = &grad;                     /*pointer to the base of the result array*/
        for(i = 0 ; i <= max; ++i){     /*Sum coefficients*/
                pr[i] = p1[i] + p2[i];
                sum += pr[i];           /*Check for null polynomial*/
        }
	if(sum == 0){                   /*If the polynomial is null*/
                *nr = -1;
                printf(">The result is a null polynomial. Grade is %d.", *nr);
        }
        else{                                   /*Valid polynomial*/
                for(i = 0; i <= max; ++i){      /*Check maximum valid grade*/
                        if(pr[max - i] != 0){
                                *nr = i;
                                break;
                        }
		}
                printf(">The sum of the two polynomials has grade %d and is equal to:\n\n\t", *nr);
                for(i = 0; i <= (max); ++i){
                        if(pr[max - i] != 0){                   /*Print only coeff*/
                                if(pr[max - i] > 0)             /*If positive prin$*/
                                        printf("+");
                                printf("%dx^%d ", pr[max - 1  - i], max - 1 - i);
                        }
                }
        }
        printf("\n\n");
}





/*
void prodotto(int p1[], int n1, int p2[], int n2, int pr[], int *nr) {

}

void potenza_binomio(int c1, int e1, int c2, int e2, int n, int pr[], int *nr) {

}
*/
