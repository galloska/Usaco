/*
ID: skap1991
LANG: C++
TASK: prefix
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

string aux;
string cad;
int memo[MAXN];
vector<string> pos;

int DP(){

    for(int id=cad.size()-1;id>=0;id--){
        int res = 0;

        for(int j=0;j<pos.size();j++){
            bool flag = true;
            if( id + pos[j].size() > cad.size() ) continue;
            for(int h=0;h<pos[j].size();h++)
                if(cad[ id + h ]!=pos[j][h])
                    flag = false;
            if(!flag) continue;
            res = max( res , memo[id + pos[j].size() ] + (int) pos[j].size() );
        }

        memo[id] = res;
    }

    return memo[0];
        
}

int main(){
    freopen( "prefix.in" , "r" , stdin );
    freopen( "prefix.out" , "w" , stdout );

    for(;;){
        cin>>cad;
        if(cad==".") break;
        pos.push_back(cad);
    }

    cad = "";

    while(cin>>aux){
        for(int i=0;i<aux.size();i++)
            if(aux[i]!='\n')
                cad += aux[i];
    }

    cout<<DP()<<"\n";
    return 0;
}
