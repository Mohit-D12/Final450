// Reverse a stack using recursion
// https://www.geeksforgeeks.org/reverse-a-stack-using-recursion/

#include<bits/stdc++.h>
using namespace std;
 
void insert_at_bottom(stack<char>& st, char x)
{
    if(st.size() == 0)
    st.push(x);
 
    else
    {
        char a = st.top();
        st.pop();

        insert_at_bottom(st, x);
        st.push(a);
    }
}

void reverse(stack<char>& st)
{
    if(st.size()>0)
    {
        char x = st.top();
        st.pop();
        reverse(st);
        insert_at_bottom(st, x);
    }
}