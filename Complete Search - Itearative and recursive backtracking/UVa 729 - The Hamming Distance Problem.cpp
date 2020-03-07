#include<algorithm>
#include<stdio.h>
#include<iostream>
#include <climits>
using namespace std;
#include<vector>
#include<unordered_map>
#include <bitset>

int main()
{
    int D, N, H;
    int base = 0;
    cin >> D;
    for(int i = 0; i < D; i++)
    {
        cin >> N >> H;

        for (int k = 0; k < (1 << N); k++)  // for each subset, O(2^n)
        {
            if(__builtin_popcount(k ^ base) == H)
            {
                std::bitset<32> y(k);
                const std::string str_bits = y.to_string() ; // convert to a string of zeroes and ones
                    std::cout << str_bits.substr(32-N) << '\n' ;
            }
        }
        if(i != D - 1)  cout << endl;


    }

    return 0;
}
