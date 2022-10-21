#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct pnt {
    int x, y;
    pnt(int _x, int _y){
        x = _x;
        y = _y;
    }
};

bool operator<(pnt a, pnt b){
    if (a.x < b.x){
        return true;
    }
    if (b.x < a.x){
        return false;
    }
    return a.y > b.y;
}

long long cross(pnt a, pnt b, pnt c){
    a.x -= b.x; a.y -= b.y;
    c.x -= b.x; c.y -= b.y;
    return (ll)(a.x) * (ll)(c.y) - (ll)(c.x) * (ll)(a.y);
}

bool insideTriangle(pnt a, pnt b, pnt c, pnt x){
    if (cross(a, b, c) == 0){
        if (cross(a, b, x) != 0){
            return false;
        }
        int r = min( min( a.x, b.x ), c.x );
        int r1 = max( max( a.x, b.x ), c.x );
        int s = min( min( a.y, b.y ), c.y );
        int s1 = max( max( a.y, b.y), c.y );
        return x.x >= r && x.x <= r1 && x.y >= s && x.y <= s1;
    }

    long long PA = cross( a, b, x ), PB = cross( b, c, x ), PC = cross( c, a ,x );
    return ( PA <= 0 && PB <= 0 && PC <= 0 ) || ( PA >= 0 && PB >= 0 && PC >= 0 );
}

int insidePolygon(vector<pnt> &P, pnt x){
    int b = 1, e = P.size() - 1, m;
    while(b != e){
        m = (b + e) / 2;
        if (cross(P[0], P[m], x) < 0){
            e = m;
        }
        else {
            b = m + 1;
        }
    }
    return insideTriangle(P[0], P[b], P[b - 1], x) ? 1 : 0;
}

vector< pnt > convex_hull( vector< pnt > &A ){

    sort( A.begin(), A.end() );

    vector< pnt > cmpA;
    int e = 0, n = A.size();
    for( int i = 0; i < n; i++ ){
        if( e < 2 ){
            cmpA.push_back( A[i] );
            e++;
            continue;
        }
        while( cross( cmpA[ e - 2 ], cmpA[ e - 1 ], A[i] ) <= 0 ){
            cmpA.pop_back();
            e--;
            if( e < 2 ) break;
        }
        cmpA.push_back( A[i] );
        e++;
    }

    vector< pnt > cmpB;
    e = 0;
    for( int i = 0; i < n; i++ ){
        if( e < 2 ){
            cmpB.push_back( A[i] );
            e++;
            continue;
        }
        while( cross( cmpB[ e - 2 ], cmpB[ e - 1 ], A[i] ) >= 0 ){
            cmpB.pop_back();
            e--;
            if( e < 2 ) break;
        }
        cmpB.push_back( A[i] );
        e++;
    }

    cmpB.pop_back();
    reverse( cmpB.begin(), cmpB.end() );
    cmpB.pop_back();
    for( int i = 0; i < cmpB.size(); i++ )
        cmpA.push_back( cmpB[i] );
    return cmpA;

}

int score(vector<pnt> &A, vector<pnt> &B){
    int ret = 0;
    vector<pnt> hull = convex_hull(A);
    for (int i = 0; i < B.size(); i++){
        ret += insidePolygon(hull, B[i]);
    }
    return ret;
}

int n, x, y;
vector<pnt> A, B;

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> x >> y;
        A.push_back(pnt(x, y));
    }
    for(int i = 1; i <= n; i++){
        cin >> x >> y;
        B.push_back(pnt(x, y));
    }
    cout << score(A, B) << ' ' << score(B, A) << endl;
    return 0;
}