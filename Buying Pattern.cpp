#include<bits/stdc++.h>
using namespace std;
int main()
{
    string items[] = {"milk","bread","jam","pen","notebook","corn-flex","pencil", "eraser","ketchup"};
    cout<<"enter the no. of customers : ";
    int n;
    cin>>n;
    vector<vector<string>> c(n, vector<string>());
   /* c[0] = {"notebook","pen","milk"};
    c[1] = {"bread","jam"};
    c[2] =  {"corn-flex", "milk", "pen"};
    c[3] = {"bread", "jam", "milk"};
    c[4] = {"pen", "notebook", "jam", "bread"}; */
    int p;
    for(int i = 0; i < n; i++)
    {
        cout<<"for customer - "<<i+1<<" : \n";
        cout<<"enter the purchased items : \n";
        cin>>p;
        string s;
        for(int j = 0; j < p; j++)
        {
            cout<<"item - "<<j+1<<" : ";
            cin>>s;
            cout<<"\n";
            c[i].push_back(s);
        }
        cout<<"\n";
    }
    unordered_map<string,int> m;
    int ans = 0;
    for(auto i : c)
    {
        for(auto j : i)
        {
            m[j]++;
            ans = max(ans, m[j]);
        }
    }
    vector<string> a;
    for(auto i : m)
    {
        if(i.second == ans)
        {
            a.push_back(i.first);
        }
    }
    cout<<"most purchased item(s) : \n";
    for(auto i : a)
    {
        cout<<i<<"\t";
    }
    cout<<"\n";
    for(auto i : c)
    {
        sort(i.begin(), i.end());
    }
    int res = 0;
    map<vector<string>, int> m2;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < c[i].size() - 1; j++)
        {
            for(int k = j + 1; k < c[i].size(); k++)
            {
                m2[{c[i][j],c[i][k]}]++;
                res = max(res, m2[{c[i][j],c[i][k]}]);
            }
        }
    }
    int t;
    cout<<"\nset the threshold for together bought items : ";
    cin>>t;
    cout<<"\n\nmost frequently together bought items : \n";
    vector<vector<string>> final;
    for(auto i : m2)
    {
        if(i.second >= t)
        {
            final.push_back(i.first);
        }
    }
    for(auto i : final)
    {
        for(auto j : i)
        {
            cout<<j<<" ";
        }
        cout<<" : "<<m2[i];
        cout<<"\n";
    }
}
