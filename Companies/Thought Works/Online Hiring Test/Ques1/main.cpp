#include<bits/stdc++.h>
using namespace std;

long long totalSadness (vector<long long> Height, long long n, long long &index)
{
    long long sadness = 0;
    set<long long, greater<long long>> temp;
    long long prev = Height[0], last_max = 0;
    temp.insert(Height[0]);
    for(long long i=1;i<n;i++)
    {
        long long count = 0;
        set<long long, greater<long long>> :: iterator itr;
        for(itr = temp.begin(); itr!=temp.end(); ++itr)
        {
            if(*itr>Height[i])
                count++;
            else
                break;
        }
        if(sadness>last_max)
        {
            last_max = sadness; index = i;
        }
        sadness += count;
        //cout<<i<<" "<<sadness<<endl;
    }
    return sadness;
}

long long func1 (vector<long long> Height) 
{
    long long n = Height.size();
    if(n==1)
        return 0;
    long long index = 0;
    cout<<"Yo "<<" ";
    long long nextSad = totalSadness(Height, n, index), prevSad = 0;
    cout<<"Yo "<<" ";
    //cout<<index<<endl;
    do
    {
        prevSad = nextSad;
        cout<<"Hi "<<" ";
        long long s=-1, e = n-1;
        long long prev = 0;
        for(long long i =0; i<n; i++)
        {
            if(Height[i]<Height[prev])
                s=prev;
        }
        if(s == -1)
            break;
        long long tmp = Height[s];
        s++;
        while(s<n)
        {
            Height[s-1] = Height[s];
        }
        Height[s] = tmp;
        nextSad = totalSadness(Height, n, index);
        cout<<"Hi "<<" ";
    }while(prevSad != nextSad);
    
    //index = 0;
    //cout<<"ABC: "<<totalSadness(Height, n, index)<<endl;
    
    return prevSad;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout<<"Hi "<<" ";
    int T;
    cin >> T;
    for(int t_i=0; t_i<T; t_i++)
    {
        int N;
        cin >> N;
        vector<long long> Height(N);
        for(int i_Height=0; i_Height<N; i_Height++)
        {
        	cin >> Height[i_Height];
        }

        long long out_;
        out_ = func1(Height);
        cout << out_;
        cout << "\n";
    }
    return 0;
}