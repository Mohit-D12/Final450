// Word Break - Part 2
// https://practice.geeksforgeeks.org/problems/word-break-part-23249/1#

// CPP program for above approach
#include <bits/stdc++.h>

using namespace std;

class Solution1
{
    void backtrack(vector<string>& dict, string& s, int n, int index, string sentence, vector<string>& ans)
    {
        if(index >= n)
        {
            ans.push_back(sentence);
            return;
        }
        
        
        string current_word = "";
        
        for(int i = index; i < n; i++)
        {
            current_word.push_back(s[i]);
            if(find(dict.begin(), dict.end(), current_word) != dict.end()) 
            {
                if(sentence.length())
                    backtrack(dict, s, n, i+1, sentence+" "+current_word, ans);
                else
                    backtrack(dict, s, n, i+1, current_word, ans);
            }
        }
    }
    
    public:
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        vector<string> ans;
        
        int size = s.length();
        
        if(size==0)
            return ans;
        
        string sentence = "";
        int index = 0;
        
        backtrack(dict, s, size, index, sentence, ans);
        
        return ans;
    }
};

class Solution2
{
public:
    unordered_map<string, vector<string>> m;
    
    void combine(vector<string> &v, string w)
    {
        for(int i = 0; i < v.size(); i++)
            v[i] += " " + w;
    }
    
    vector<string> cal(string s, unordered_set<string> &mp)
    {
        if(m.find(s) != m.end()) 
            return m[s];

        vector<string> result;

        if(mp.find(s) != mp.end()) 
            result.push_back(s);

        for(int i = 1;i < s.size();i++)
        {
            string rem = s.substr(i);

            if(mp.find(rem) != mp.end())
            {
                vector<string> v = cal(s.substr(0,i), mp);
                combine(v, rem);
                result.insert(result.end(), v.begin(), v.end());
            }
        }

        m[s] = result;
        return result;
    }
    
    vector<string> wordBreak(int n, vector<string>& dict, string s) 
    {
        unordered_set<string> mp;

        for(int i = 0;i < n;i++)
            mp.insert(dict[i]);
            
        vector<string> ans = cal(s, mp);
        return ans;
    }
};