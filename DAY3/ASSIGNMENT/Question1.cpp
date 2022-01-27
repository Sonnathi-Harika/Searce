/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100010;
typedef long long ll;

struct Node1 {
    ll a, b;
    Node1() {}
    Node1(ll t_a, ll t_b) : a(t_a), b(t_b) {}
    bool operator < (const Node1 &p) const {
        return a + b > p.a + p.b;
    }
};

struct Node2 {
    ll a, b;
    Node2() {}
    Node2(ll t_a, ll t_b) : a(t_a), b(t_b) {}
    bool operator < (const Node2 &p) const {
        return b > p.b;
    }
};

inline ll max(ll a, ll b) {
    return a > b ? a : b;
}

int main() {

    priority_queue<Node1> pq1;
    priority_queue<Node2> pq2;
    int n;
    ll a, b;
    ll t = 0;
    ll ans = 0;
    Node1 p1;
    Node2 p2;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%lld %lld", &a, &b);
        ans -= a;
        pq1.push(Node1(a, b));
    }
    while(!pq1.empty() || !pq2.empty()) {
        if(!pq1.empty()) {
            if(pq1.top().a < t) {
                while(!pq1.empty() && pq1.top().a < t) {
                    p1 = pq1.top();
                    pq1.pop();
                    p2.a = p1.a;
                    p2.b = p1.b;
                    pq2.push(p2);
                }
                if(!pq1.empty()) {
                    p1 = pq1.top();
                    p2 = pq2.top();
                    if(p1.a + p1.b <= t + p2.b) {
                        if(p1.a + p1.b == t + p2.b && p1.b < p2.b) {
                            t = t + p2.b;
                            pq2.pop();
                        } else {
                            t = p1.a + p1.b;
                            pq1.pop();
                        }
                    } else {
                        t = t + p2.b;
                        pq2.pop();
                    }
                } else {
                    p2 = pq2.top();
                    pq2.pop();
                    t = t + p2.b;
                }
            } else {
                p1 = pq1.top();
                if(!pq2.empty()) p2 = pq2.top();
                if(pq2.empty() || p1.a + p1.b <= t + p2.b) {
                    if(!pq2.empty() && p1.a + p1.b == t + p2.b && p1.b < p2.b) {
                        t = t + p2.b;
                        pq2.pop();
                    } else {
                        pq1.pop();
                        t = p1.a + p1.b;
                    }
                } else {
                    t = t + p2.b;
                    pq2.pop();
                }
            }
            ans += t;
            continue;
        }
        if(!pq2.empty()) {
            p2 = pq2.top();
            pq2.pop();
            t = t + p2.b;
            ans += t;
        }
    }
    printf("%lld\n", ans/n);
    return 0;
}