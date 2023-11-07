/*Time limit: 5000 ms
Memory limit: 256 MB

The remote country of Xtremeland is planning a highway system that will allow for travel between all its cities. There is a lot of controversy over which cities should be directly connected. As a result, the following system will be used to impartially select these roads.

The costs for roads that could be built between pairs of cities will be estimated. Then, the country will select the roads that make up the cheapest highway network, that could provide routes between any pair of cities. If there is more than one possible cheapest network, then the roads from all possible cheapest networks will be selected.

Standard Input
Input begins with an integer 
�
n on a line by itself that indicates the number of potential roads with cost estimates.

The next 
�
n lines have the following format:

�
�
n 
i
​
  
�
�
n 
j
​
  
�
�
�
c 
ij
​
 

where 
�
�
n 
i
​
  is a city name, 
�
�
n 
j
​
  is a city name, and 
�
�
�
c 
ij
​
  is an integer representing the cost of a 2-way highway that connects 
�
�
n 
i
​
  and 
�
�
n 
j
​
 .

Standard Output
Output the cost of the highway system, that meets the requirements above. If there is no way to build a highway system that connects all of the cities, then output -1.

Constraints and notes
1
≤
�
≤
400
,
000
1≤n≤400,000
1
≤
�
�
�
≤
1
,
000
,
000
1≤c 
ij
​
 ≤1,000,000 for all 
�
�
�
c 
ij
​
 
Each city name will consist of between 1 and 5 lowercase letters.

All cities will be listed in at least one of the input lines.

Input	Output	Explanation
5
a b 1
b c 2
a c 2
b d 4
a d 5
9
There are two road networks that cost 7 units:

a-b, b-c, b-d

and

a-b, a-c, b-d

We must, therefore, build all of the roads in the networks, a-b, a-c, b-c, and b-d, at a cost of 9.

5
a b 1
b c 1
a c 1
b d 1
a d 1
5
There are a number of road networks that cost 3 and connect all cities, for example:

a-b, b-c, b-d

a-c, b-c, a-d

a-d, b-d, b-c

Since all of the roads appear in at least one of these cheapest networks, we must build all roads at a cost of 5.

5
a b 1
b c 1
a c 1
b d 1
f e 1
-1
There is no way to build a network that connects city e or city f to cities a, b, c, or d, and therefore, we output -1.
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXN 105
#define INF INT_MAX

// Definitions for the flow network
int n, m;
int elevations[MAXN][MAXN];
int capacity[MAXN][MAXN];
int flow[MAXN][MAXN];
int visited[MAXN];
int parent[MAXN];

// Helper function to compute the maximum flow in the network
int maxFlow(int source, int sink) {
    int maxFlow = 0;

    while (1) {
        for (int i = 0; i < n; i++) {
            visited[i] = 0;
            parent[i] = -1;
        }

        visited[source] = 1;
        int minCapacity = INF;
        int current = source;

        while (current != sink) {
            for (int next = 0; next < n; next++) {
                if (!visited[next] && capacity[current][next] - flow[current][next] > 0) {
                    visited[next] = 1;
                    parent[next] = current;
                    minCapacity = minCapacity < (capacity[current][next] - flow[current][next]) ? minCapacity : (capacity[current][next] - flow[current][next]);
                    current = next;
                    if (current == sink) break;
                }
            }
        }

        if (current == sink) {
            maxFlow += minCapacity;
            int node = sink;

            while (node != source) {
                int prevNode = parent[node];
                flow[prevNode][node] += minCapacity;
                flow[node][prevNode] -= minCapacity;
                node = prevNode;
            }
        } else {
            break;
        }
    }

    return maxFlow;
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &elevations[i][j]);
        }
    }

    int source = n * m;
    int sink = source + 1;

    int totalCapacity = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int elevation = elevations[i][j];
            capacity[i][j] = elevation;
            totalCapacity += elevation;

            if (i > 0) capacity[i][j] = elevation - elevations[i - 1][j];
            if (j > 0) capacity[i][j] = elevation - elevations[i][j - 1];
            if (i < n - 1) capacity[i][j] = elevation - elevations[i + 1][j];
            if (j < m - 1) capacity[i][j] = elevation - elevations[i][j + 1];
        }
    }

    int maxFlowValue = maxFlow(source, sink);
    printf("%d\n", maxFlowValue);

    return 0;
}
