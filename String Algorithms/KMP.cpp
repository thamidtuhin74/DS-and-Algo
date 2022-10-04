#include<bits/stdc++.h>
using namespace std;
#define max 100000
int failure[max];
void build_failure_table(string pattern, int m)
{
    failure[0] = 0;
    failure[1] = 0;

    for(int i=2;i<=m;i++)
    {
        int j = failure[i-1];

        while(1)
        {
            if(pattern[j] == pattern[i-1]){
                failure[i] = j+1;
                break;
            }

            if(j==0)
            {
                failure[i] = 0;
                break;
            }

            j = failure[j];
        }
    }
}

bool kmn(string text, string pattern)
{
    int n = text.size();
    int m = pattern.size();

    build_failure_table(pattern, m);

    int i=0;//i will work with pattern
    int j=0;//j will work with text;

    while(1)
    {
        if(j==n)
            return false;


        if(text[j] == pattern[i])
        {
            i++;
            j++;
            if(i==m)
                return true;
        }
        else
        {
            if(i==0)
            {
                j++;
            }

            else
            {
                i = failure [i];
            }
        }
    }
    return false;

}


int main()
{
    string text = "ababcabcabdababd";
    string pattern = "ababd";
    if(kmn(text,pattern))
    {
        cout<<"finding successfull\n";
    }
    else
        cout<<"finding unsuccessfull\n";

    return 0;
}
