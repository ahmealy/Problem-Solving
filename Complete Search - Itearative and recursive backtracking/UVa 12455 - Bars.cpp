//12455	Bars

#include<algorithm>
#include<stdio.h>
#include<iostream>
using namespace std;
#include<vector>

int main()
{
    int t, n, p;
    int bars[20];
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
        scanf("%d\n%d", &n, &p);
        for(int j = 0; j < p; j++)
        {
            scanf("%d", &bars[j]);
        }

        bool found = false;
        for (int k = 0;k < (1 << p); k++)   // for each subset, O(2^n)
        {
            int sum = 0;
            for (int j = 0; j < p; j++) // check membership, O(n)
                if (k & (1 << j)) // test if bit ‘j’ is turned on in subset ‘i’?
                    sum += bars[j]; // if yes, process ‘j’
            if (sum == n)
            {
                found = true;
                break; // the answer is found: bitmask ‘i’
            }
        }
        if(found)   printf("YES\n");
        else        printf("NO\n");
    }

    return 0;
}
