/*A happy number 
�
n is a positive integer defined by the following process:

Starting with 
�
n, replace it with the sum of the squares of its digits.
Repeat the process until the number reaches 1 (where it will stay in eternal happiness), or repeats in an infinite loop that does not include 1.
Those numbers for which this process ends in 1 are happy numbers.
For example, 23 is a happy number: 23 -> 13 -> 10 -> 1 -> 1.

However, 89 is not a happy number (cycle in bold): 89 -> 145 -> 42 -> 20 -> 4 -> 16 -> 37 -> 58 -> 89 -> 145 -> 42 -> 20 -> 4

Given two numbers 
�
,
�
a,b return the number of happy numbers between 
�
a and 
�
b (inclusive).

Standard Input
Each test contains two space separated integers 
�
,
�
a,b

Standard Output
For each test case, output a single integer, the number of happy numbers between 
�
a and 
�
b (inclusive).

Constraints and notes
1
≤
�
≤
�
≤
1
0
16
1≤a≤b≤10 
*/
#include <stdio.h>
#include <stdbool.h>

bool is_happy(int n) {
    int seen [1000];
    int count = 0;

    while (n != 1 && count < 1000) {
        seen[count++] = n;
        int sum_of_squares = 0;

        while (n > 0) {
            int digit = n % 10;
            sum_of_squares += digit * digit;
            n /= 10;
        }

        n = sum_of_squares;

        for (int i = 0; i < count; i++) {
            if (seen[i] == n) {
                return false;
            }
        }
    }

    return n == 1;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    int count = 0;

    for (int i = a; i <= b; i++) {
        if (is_happy(i)) {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}