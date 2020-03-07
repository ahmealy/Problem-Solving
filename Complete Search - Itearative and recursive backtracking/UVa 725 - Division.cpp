// 725	Division

#include<algorithm>
#include<stdio.h>
#include<iostream>
using namespace std;
#include<vector>

int main()
{
    int k, cnt = 0;
    int S[12];
    while(cin >> n && n !=0)
    {
        cnt++;
        if(cnt > 1)         printf("\n");
        for (int fghij = 1234; fghij <= 98765 / n; fghij++)
        {
            int abcde = fghij * n; // this way, abcde and fghij are at most 5 digits
            int tmp, used = (fghij < 10000); // if digit f=0, then we have to flag it
            tmp = abcde;
            while (tmp)
            {
                used |= 1 << (tmp % 10);
                tmp /= 10;
            }
            tmp = fghij;
            while (tmp)
            {
                used |= 1 << (tmp % 10);
                tmp /= 10;
            }
            if (used == (1<<10) - 1)   // if all digits are used, print it   1023 -> 111111111
            {
                found = true;
                printf("%05d / %05d = %d\n", abcde, fghij, n);
            }
        }
        if(! found) printf("There are no solutions for %d.\n",n);
    }

    return 0;
}
