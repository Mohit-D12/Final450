// 5. Longest Palindromic Substring
// https://leetcode.com/problems/longest-palindromic-substring/submissions/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.length();
        int x = 0, y = 0;
        
        //checking odd length palindromes
        for(int i = 0; i < n; i++)
        {
            int j = i, k = i;
            while(j >= 0 && k < n && s[j] == s[k])
            {
                if(y - x < k - j)
                {
                    y = k;
                    x = j;
                }
                j--; k++;
            }
        }
        //checking even length palindromes
        for(int i = 0; i < n-1; i++)
        {
            int j = i, k = i+1;
            while(j >= 0 && k < n && s[j] == s[k])
            {
                if(y - x < k - j)
                {
                    y = k;
                    x = j;
                }
                j--; k++;
            }
        }
        
        string res = "";
        while(x <= y)
            res += s[x++];
        return res;
    }
};