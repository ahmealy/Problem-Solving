//441	Lotto

#include<algorithm>
#include<stdio.h>
#include<iostream>
using namespace std;
#include<vector>

int main()
{
    int n, cnt = 0;
    int S[12];
    while(cin >> k && k !=0)
    {
        cnt++;
        if(cnt > 1)         printf("\n");
        for (int i = 0; i < k; i++) // input: k sorted integers
            scanf("%d", &S[i]);
        for (int a = 0 ; a < k - 5; a++) // six nested loops!
            for (int b = a + 1; b < k - 4; b++)
                for (int c = b + 1; c < k - 3; c++)
                    for (int d = c + 1; d < k - 2; d++)
                        for (int e = d + 1; e < k - 1; e++)
                            for (int f = e + 1; f < k ; f++)
                                printf("%d %d %d %d %d %d\n",S[a],S[b],S[c],S[d],S[e],S[f]);
    }

    return 0;
}
