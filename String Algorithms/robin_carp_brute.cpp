#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int i,j,n,m;
bool match;

bool naive_matching(string text, string pattern){
  n = text.size();
  m = pattern.size();
  for(i = 0; i < n; i++) {
    for(j = 0; j < m && i + j < n; j++) {
      if(text[i + j] != pattern[j]) {
        break; // mismatch found, break the inner loop
      }
    }
    if(j == m) {

    return match=1;
     // match found
    }
  }
}

int main()
{
    string t = "abacba";
    string p = "acb";
    naive_matching(t,p);
    if(match)
        printf("match");
    else
        printf("not matched");
}
