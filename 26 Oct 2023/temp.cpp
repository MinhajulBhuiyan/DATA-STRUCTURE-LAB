#include <iostream>
#include <bits/stdc++.h>

const int N = 1e5+10;

int parent[N];

void make(int v)
{
    parent[v] = v; 
}

int find(int v)
{
    if(v==parent[v]) return 0;
    return find(parent[v]);
}

void Union(int a, int b)
{
    
}

int main()
{
    char h;
    cout << h;

    return 0;

}