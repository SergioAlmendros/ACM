#include <iostream>
#include <vector>
#include <algorithm>
#include <cfloat>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>


#define X first
#define Y second
#define LI long long
#define MP make_pair
#define PB push_back
#define SZ size()
#define SQ(a) ((a)*(a))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

using namespace std;

typedef vector<pair<int,pair<int,int> > > V;

int N, mf[2001]; // numero de nodos N <= 2000
V v;             // lista de aristas (coste, (nodo1, nodo2))

map<string,int> mCit;

int find(int n) { // conjunto conexo de n
  if (mf[n] == n) return n;
  else return mf[n] = find(mf[n]);
}

int kruskal() {
  int a, b, sum = 0;
  sort(v.begin(), v.end());
  for (int i = 0; i < N; i++)
    mf[i] = i; // inicializar conjuntos conexos

  for (int i = 0; i < (int)v.SZ; i++) {
    a = find(v[i].Y.X), b = find(v[i].Y.Y);
    if (a != b) { // si conjuntos son diferentes
      mf[b] = a;  // unificar los conjuntos
      sum += v[i].X; // agregar coste de arista
    }
  }
  return sum;
}

int main(){

  string s,s2;
  int c,t,m,n;
  int unique = 0;
  
  cin>>t;

  for(int i=0; i<t; i++){
    
    cin>>m>>n;
    N = m;
    for(int j=0; j<n; j++){
      cin>>s>>s2>>c;
      if(mCit.find(s) == mCit.end()){
        mCit[s] = unique;
        unique++;
      }
      if(mCit.find(s2) == mCit.end()){
        mCit[s2] = unique;
        unique++;
      }
      v.push_back(make_pair(c,make_pair(mCit[s],mCit[s2])));
    }
    cout << kruskal() << endl;
    if(i < t-1)
      cout<<endl;
    v.clear();
    mCit.clear();
    unique = 0;
  }  
  
  return 0;
}













