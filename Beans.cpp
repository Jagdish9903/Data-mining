#include<bits/stdc++.h>
using namespace std;
void show(vector<vector<int>> s)
{
    for(int i = 0; i < s.size(); i++)
    {
        cout<<"Bean - "<<i+1<<" :";
        for(int j = 0; j < s[0].size(); j++)
        {
            cout<<"\t"<<s[i][j];
        }
        cout<<"\n";
    }
}
void mean(vector<vector<int>> &s)
{
    for(int i = 0; i < s.size(); i++)
    {
        int sum = 0;
        int count = 0;
        for(int j = 0; j < s[0].size(); j++)
        {
            if(s[i][j] != 0)
            {
                sum += s[i][j];
                count++;
            }
        }
        sum /= count;
        //s[i] = vector<int> (s[0].size(), sum);
        for(int j = 0; j < s[0].size(); j++)
        {
            if(s[i][j] != 0) s[i][j] = sum;
        }
    }
    cout<<"smoothing by mean : \n";
}
void mode(vector<vector<int>> &s)
{
    for(int i = 0; i < s.size(); i++)
    {
        unordered_map<int,int> m;
        int maxi = 0;
        int element = 0;
        for(int j = 0; j < s[0].size(); j++)
        {
            if(s[i][j] != 0)
            m[s[i][j]]++;
            if(m[s[i][j]]> maxi)
            {
                maxi = m[s[i][j]];
                element = s[i][j];
            }
        }
        //s[i] = vector<int> (s[0].size(), element);
        for(int j = 0; j < s[0].size(); j++)
        {
            if(s[i][j] != 0) s[i][j] = element;
        }
    }
    cout<<"smoothing by mode : \n";
}
void median(vector<vector<int>> &s)
{
    for(int i = 0; i < s.size(); i++)
    {
        int ans;
        sort(s[i].begin(), s[i].end());
        ans = s[i][s[i].size()/2];
        if(s[i].size() % 2)
        {
            //s[i] = vector<int> (s[0].size(), ans);
            for(int j = 0; j < s[0].size(); j++)
        {
            if(s[i][j] != 0) s[i][j] = ans;
        }
        }
        else
        {
            ans = (s[i][(s[i].size()-1)/2] + s[i][s[i].size()/2])/2;
            //s[i] = vector<int> (s[0].size(), ans);
            for(int j = 0; j < s[0].size(); j++)
            {
                if(s[i][j] != 0) s[i][j] = ans;
            }
        }
    }
    cout<<"smoothing by median : \n";
}void boundary(vector<vector<int>> &s)
{
    for(int i = 0; i < s.size(); i++)
    {
        sort(s[i].begin(), s[i].end());
        int j = 0;
        while(s[i][j] == 0)
        {
            j++;
        }
        int mini = s[i][j];
        int maxi = s[i][s[i].size() - 1];
        for(int j = 0; j < s[0].size(); j++)
        {
            if(s[i][j] != mini && s[i][j] != maxi && s[i][j] != 0)
            {
                int a = abs(mini - s[i][j]);
                int b = abs(maxi - s[i][j]);
                if(a < b)
                {
                    s[i][j] = mini;
                }
                else
                {
                    s[i][j] = maxi;
                }
            }
        }
    }
    cout<<"smoothing by boundary : \n";
}
void stand(vector<vector<int>> &s)
{
    for(int i = 0; i < s.size(); i++)
    {
        int sum = 0;
        int count = 0;
        for(int j = 0; j < s[0].size(); j++)
        {
            if(s[i][j] != 0)
            {
                sum += s[i][j];
                count++;
            }
        }
        sum /= count;
        double res = 0;
        for(int j = 0; j < s[0].size(); j++)
        {
            if(s[i][j] != 0)
            res += pow(s[i][j] - sum, 2);
        }
        res /= count;
        res = sqrt(res);
        //s[i] = vector<int> (s[0].size(), res);
        for(int j = 0; j < s[0].size(); j++)
        {
            if(s[i][j] != 0) s[i][j] = res;
        }
    }
    cout<<"smoothing by standard deviation :\n";
}
int main()
{
    int n, m;
    cout<<"enter the no. of data : ";
    cin>>n;
    cout<<"enter the no. of beans : ";
    cin>>m;
    cout<<"enter the values : ";
    int len = n;
    if(n % m)
    {
        len = n + m - n%m;
    }
    //cout<<len<<"\n";
    vector<int> a(len,0);
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    n = len;
    sort(a.begin(), a.end());
    vector<vector<int>> bean(m, vector<int> (n / m, 0)), dup;
    int k = 0;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < bean[0].size(); j++)
        {
            bean[i][j] = a[k++];
        }
    }
    cout<<"initially beans are : \n";
    show(bean);
    int choice = 0;
    while(choice != 6)
    {
        cout<<"1) mode\n 2) median\n 3) mean\n 4) standard deviation\n 5) boundary\n 6) exit\n";
        cout<<"how do you wanna smooth ? : ";
        cin>>choice;
        dup = bean;
        if(choice == 1)
        {
            mode(dup);
            show(dup);
        }
        else if(choice == 2)
        {
            median(dup);
            show(dup);
        }
        else if(choice == 3)
        {
            mean(dup);
            show(dup);
        }
        else if(choice == 4)
        {
            stand(dup);
            show(dup);
        }
        else if(choice == 5)
        {
            boundary(dup);
            show(dup);
        }
        else
        {
            return 0;
        }
    }
}
