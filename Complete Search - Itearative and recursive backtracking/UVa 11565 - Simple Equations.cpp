//11565	Simple Equations
#include<algorithm>
#include<stdio.h>
#include<iostream>
using namespace std;
#include<vector>

int main()
{
    int n, A, B, C;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> A>>B>>C;

        bool sol = false;
        int x, y, z;
        for (x = -22; x <= 22 && !sol; x++)
            if (x * x <= C)
                for (y = -100; y <= 100 && !sol; y++)
                    if (y != x && x * x + y * y <= C)
                        for (z = -100; z <= 100 && !sol; z++)
                            if (z != x && z != y &&
                                    x + y + z == A && x * y * z == B && x * x + y * y + z * z == C)
                            {
                                printf("%d %d %d\n", x, y, z);
                                sol = true;
                            }
        if (!sol)
            printf("No solution.\n");
    }
    return 0;
}
