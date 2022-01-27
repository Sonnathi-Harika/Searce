/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/


#include <iostream>
#include <queue>

using namespace std;

const int maxn = 100010;
typedef long long ll;

struct Node1 
{
    ll x, y;
    Node1() {}
    Node1(ll t_x, ll t_y) : x(t_x), y(t_y) {}
    bool operator < (const Node1 &p) const 
    {
        return x + y > p.x + p.y;
    }
};

struct Node2 
{
    ll x, y;
    Node2() {}
    Node2(ll t_x, ll t_y) : x(t_x), y(t_y) {}
    bool operator < (const Node2 &p) const 
    {
        return y > p.y;
    }
};

inline ll max(ll x, ll y) 
{
    return x > y ? x : y;
}

int main() 
{
    priority_queue<Node1> pq1;
    priority_queue<Node2> pq2;
    int n;
    ll x, y;
    ll t = 0;
    ll answer = 0;
    Node1 p1;
    Node2 p2;
    cout<<"Enter number of customers:\n";
    cin>>n;
    for(int i = 0; i < n; ++i) 
    {
        cout<<"Enter priority number & corresponding waiting time of customer "<<i<<"\n";
        cin>>x>>y;
        answer -= x;
        pq1.push(Node1(x, y));
    }
    while(!pq1.empty() || !pq2.empty()) 
    {
        if(!pq1.empty()) 
        {
            if(pq1.top().x < t) 
            {
                while(!pq1.empty() && pq1.top().x < t) 
                {
                    p1 = pq1.top();
                    pq1.pop();
                    p2.x = p1.x;
                    p2.y = p1.y;
                    pq2.push(p2);
                }
                if(!pq1.empty()) 
                {
                    p1 = pq1.top();
                    p2 = pq2.top();
                    if(p1.x + p1.y <= t + p2.y) 
                    {
                        if(p1.x + p1.y == t + p2.y && p1.y < p2.y) 
                        {
                            t = t + p2.y;
                            pq2.pop();
                        } 
                        else 
                        {
                            t = p1.x + p1.y;
                            pq1.pop();
                        }
                    } 
                    else 
                    {
                        t = t + p2.y;
                        pq2.pop();
                    }
                } 
                else 
                {
                    p2 = pq2.top();
                    pq2.pop();
                    t = t + p2.y;
                }
            } 
            else 
            {
                p1 = pq1.top();
                if(!pq2.empty()) p2 = pq2.top();
                if(pq2.empty() || p1.x + p1.y <= t + p2.y) 
                {
                    if(!pq2.empty() && p1.x + p1.y == t + p2.y && p1.y < p2.y) 
                    {
                        t = t + p2.y;
                        pq2.pop();
                    } 
                    else 
                    {
                        pq1.pop();
                        t = p1.x + p1.y;
                    }
                } 
                else 
                {
                    t = t + p2.y;
                    pq2.pop();
                }
            }
            answer += t;
            continue;
        }
        if(!pq2.empty()) 
        {
            p2 = pq2.top();
            pq2.pop();
            t = t + p2.y;
            answer += t;
        }
    }
    cout<<"Minimum average waiting time is:\n"<<answer/n;
    return 0;
}