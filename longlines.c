/*When standing in a line, some people are more noticeable than others, and height has a lot to do with it. For this problem, we define a person 
�
i as noticeable to person 
�
j if and only if:

Person 
�
i is standing in front of person 
�
j in line, and
There are no people standing between person 
�
i and 
�
j that are as tall or taller than person 
�
i.
Given the heights of people in line, and these definitions, you are to count how many times people are noticeable in a line.

Standard Input
Input consists of 5 space-separated integers, 
�
n, 
ℎ
0
h 
0
​
 , 
�
a, 
�
c, and 
�
q. 
�
n is the number of people in the line, and the other values are used in the formula below.

To find the heights of people in the line, you should apply the following formula:

ℎ
�
=
(
�
×
ℎ
�
−
1
+
�
)
h 
i
​
 =(a×h 
i−1
​
 +c) mod 
�
q, for 
1
≤
�
<
�
1≤i<n

The person with height 
ℎ
0
h 
0
​
  is standing at the front of the line, the person with height 
ℎ
1
h 
1
​
  is second in line, the person with height 
ℎ
2
h 
2
​
  is third in line, and so on.

Standard Output
Output the sum of the number of people who are noticeable in the line.

Constraints and notes
1
≤
�
≤
1
0
7
1≤n≤10 
7
 
1
≤
ℎ
0
<
�
≤
1
0
9
1≤h 
0
​
 <q≤10 
9
 
1
≤
�
<
�
1≤a<q
1
≤
�
<
�
1≤c<q
*/
#include <stdio.h>

long long count_noticeable_people(int n, long long h_0, long long a, long long c, long long q) {
    long long heights[n];
    heights[0] = h_0;
    long long noticeable_count = 1;

    for (int i = 1; i < n; ++i) {
        long long new_height = (a * heights[i - 1] + c) % q;
        heights[i] = new_height;
        noticeable_count++;
    }

    return noticeable_count;
}

int main() {
    int n;
    long long h_0, a, c, q;
    scanf("%d %lld %lld %lld %lld", &n, &h_0, &a, &c, &q);

    // Count noticeable people
    long long result = count_noticeable_people(n, h_0, a, c, q);
    printf("%lld\n", result);

    return 0;
}
