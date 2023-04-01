/*
 * Created by acidpuzzle on 6/28/22.
 *
 * Adding and Removing an Array Element. Last In First Out (LIFO) or STACK conception.
 *
 * A[] - array
 * int top - top points to the next free cell, at the beginning the first free cell A[0]; top = 0;
 *
 * +----PUSH-----+
 * | A[top] = x; |
 * | top += 1;   |
 * +-------------+
 *
 * +----POP-----+
 * | top -= 1;  |
 * | x = A[top] |
 * +------------+
 *
 */
#include <stdio.h>
#include <stdlib.h>

#define N 100 // MAX array size in elements

int getNum();
void push(int* p_top, int a[]);
void pop(int* p_top, const int a[]);
void print(const int* p_top, int a[]);
void sort(const int* p_top, int a[], int revers);


int main() {
    int top = 0;
    int array[N] = {0};
    int action;

    while (1) {
        printf("\n================="
               "\nPossible actions:"
               "\n1 - Push"
               "\n2 - Pop"
               "\n3 - Print"
               "\n4 - Sort <"
               "\n5 - Sort >"
               "\n0 - Exit"
               "\nAction: ");
        action = getNum();

        if (action == 1) {
            push(&top, array);
        } else if (action == 2) {
            pop(&top, array);
        } else if (action == 3) {
            print(&top, array);
        } else if (action == 4) {
            sort(&top, array, 0);
        } else if (action == 5) {
            sort(&top, array, 1);
        } else if (action == 0) {
            break;
        } else {
            printf("\n================="
                   "\nSorry, no action \"%d\".\n", action);
        }
    }
    return 0;
}

int getNum() {
    /* Read from stdin */
    char buff[10] = {0};
    char *end_ptr = NULL;
    fgets(buff, sizeof(buff), stdin);
    int num = (int)strtol(buff, &end_ptr, 10);
    return num;
}

void push(int* p_top, int a[]) {
    /* Add new element to array. */
    printf("New element: ");
    a[*p_top] = getNum();
    *p_top += 1;
}

void pop(int* p_top, const int a[]) {
    /* Remove and return last element. */
    if (*p_top == 0) {
        printf("No elements in array.\n");
    } else {
        *p_top -= 1;
        printf("Element = %d\n", a[*p_top]);
    }
}

void print(const int* p_top, int a[]) {
    /* Print elements in array. */
    if (*p_top == 0) {
        printf("No elements in array.\n");
    } else {
        for (int i = 0; i < *p_top; ++i) {
            printf("%4d", a[i]);
        }
        printf("\n");
    }
}

void sort(const int* p_top, int a[], int revers) {
    /* Sorting elements in array with inserting sort algorithm */
    if (*p_top == 0) {
        printf("No elements in array.\n");
    } else if (*p_top == 1) {
        printf("One elements in array, nothing to sorting.\n");
    } else {
        for (int i = 1; i < *p_top; ++i) {
            int k = i;
            while (k > 0 && (revers ? a[k - 1] < a[k] : a[k - 1] > a[k])) {
                int tmp = a[k - 1];
                a[k - 1] = a[k];
                a[k] = tmp;
                k -= 1;
            }
        }
    }
}
