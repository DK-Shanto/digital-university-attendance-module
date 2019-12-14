#include<bits/stdc++.h>
using namespace std;
int main()
{
    char n[5];
    int g[5][5];

    cout<<"values of node:";

    for( int i = 0 ; i < 4 ; i++ ){
        cin>>n[i];
    }
    for( int i = 0 ; i < 4 ; i++ ){
        for( int j = 0 ; j < 4 ; j++ ){
            //cout<<"cost between "<<n[i]<<" & "<<n[j]<<" node:";
            cin>>g[i][j];
        }
    }

    cout<<endl<<"Vertex       Adjeacent list with cost"<<endl<<"------       ------------------------"<<endl;

    for( int i = 0 ; i < 4 ; i++ ){
        cout<<n[i]<<"             ";
        for( int j = 0 ; j < 4 ; j++ ){
            if( g[i][j] != 0 ){
                cout<<n[j]<<","<<g[i][j]<<",";
            }
        }
        cout<<endl;
    }
}
