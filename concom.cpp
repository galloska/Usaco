/*
ID: skap1991
LANG: C++11
TASK: concom
*/
#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

const int MAXN = 105;

int dist[MAXN];
bool vis[MAXN];
vector<pii> res;
vector<pii> grafo[MAXN];

void bfs(int padre){
    queue<int> q;
    q.push( padre );

    while(!q.empty()){
        int u = q.front();
        q.pop();
        vis[u] = true;

        for(int i=0;i<grafo[u].size();i++){
            int v = grafo[u][i].first;
            int d = grafo[u][i].second;
            if( dist[ v ] + d >= 50 && !vis[v] ){
                q.push( v );
                res.push_back( pii( padre , v ) );
            }
            dist[ v ] += d;
        }

    }
}

int main(){

    freopen( "concom.in" , "r" , stdin );
    freopen( "concom.out" , "w" , stdout );

    int n,a,b,c;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d %d %d",&a,&b,&c);
        grafo[a].push_back( pii( b , c ) );
    }

    for(int i=1;i<=100;i++){
        fill( dist , dist + MAXN , 0 );
        fill( vis , vis + MAXN , false );
        bfs( i );
    }

    sort( res.begin() , res.end() );
    auto last = unique( res.begin() , res.end() );
    res.erase( last , res.end() );

    for(auto it : res)
        printf("%d %d\n",it.first,it.second);
    return 0;
}
