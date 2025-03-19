#include<bits/stdc++.h>
using namespace std;
int main()
{
 
      string s;
      cin>>s;
      int cnt[257]={0};
      for(int i=0;i<s.size();i++)
      {
           cnt[s[i]]++;
      }
     int q;
     cin>>q;
     while (q--)
     {
        char x;
        cin>>x;
        cout<<cnt[x]<<endl;
     }
     


    return 0;
}