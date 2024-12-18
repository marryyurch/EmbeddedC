#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void readInput(double* a);
void calculateResults(double a, double* z1, double* z2);
void displayResults(double z1, double z2);

int main() {
    double a, z1, z2;

    readInput(&a);
    calculateResults(a, &z1, &z2);
    displayResults(z1, z2);

    return 0;
}

void readInput(double* a) {
    printf("Enter the value of A:");
    scanf("%lf", a);
}

void calculateResults(double a, double* z1, double* z2) {
    *z1 = (1 - 2*pow(sin(a), 2)) / (1 + sin(2 * a));
    *z2 = (1 - tan(a)) / (1 + tan(a));
}

void displayResults(double z1, double z2) {
    printf("Computed Z1: %f\n", z1);
    printf("Computed Z2: %f\n", z2);
}