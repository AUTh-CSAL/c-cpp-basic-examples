#include <stdio.h>

// In-place array reversal with pointers
void reverseArray(int *a, int n) {
    int *first = a;
    int *last  = a + n - 1;

    for (; first < last; first++, last--) {
        int temp = *first;
        *first   = *last;
        *last    = temp;
    }
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n   = sizeof(a) / sizeof(a[0]);

    reverseArray(a, n);

    // Normal printing
    for (int i = 0; i < n; i++)
        printf("%d", a[i]);

    printf("\n");

    // Print using a pointer
    for (int *i = a; i < a + n; i++)
        printf("%d", *i);
}