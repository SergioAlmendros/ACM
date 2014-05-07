#include <algorithm>
#include <cfloat>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

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

typedef int V;          // tipo de costes
typedef pair<V,int> P;  // par de (coste,nodo)
typedef set<P> S;       // conjunto de pares

int N;                  // numero de nodos
vector<P> A[200001];     // listas adyacencia (coste,nodo)

V dijkstra(int s, int t) {
  //int ant=0,cont=0;
  S m;                          // cola de prioridad
  vector<V> z(N, 1000000000);   // distancias iniciales
  z[s] = 0;                     // distancia a s es 0
  m.insert(MP(0, s));           // insertar (0,s) en m
  
  while (m.SZ > 0) {
     
    P p = *m.begin();   // p=(coste,nodo) con menor coste
    m.erase(m.begin()); // elimina este par de m
    //cout<<ant<<" "<<p.X<<endl;
    /*if(ant > p.X){
      p.X = ant;
    }*/
    
    if (p.Y == t) return p.X; // cuando nodo es t, acaba
    // para cada nodo adjacente al nodo p.Y
    
    for (int i = 0; i < (int)A[p.Y].SZ; i++) {
      // q = (coste hasta nodo adjacente, nodo adjacente)
      P q(p.X + A[p.Y][i].X, A[p.Y][i].Y);
      // si q.X es la menor distancia hasta q.Y
      if (q.X < z[q.Y]) {
        m.erase(MP(z[q.Y], q.Y)); // borrar anterior
        m.insert(q);              // insertar q
        z[q.Y] = q.X;             // actualizar distancia
      }
    }
    /*cont++;
    ant = p.X;*/
  }
  return -1;
}

void printVector(vector<pair<int,pair<int,int> > > &v){
  for(int i=0; i<int(v.size()); i++){
    cout<<v[i].second.first<<" "<<v[i].second.second<<" "<<v[i].first<<endl;
  }
}

int main(){

  int tc,NN,R,a,b,l,Q,k,t;
  cin>>tc;
  //cout<<tc<<endl;
  
  for(int i=0; i<tc; i++){
    cout<<"Case "<<i+1<<endl;
    cin>>NN>>R;
    N = NN+1;
    //cout<<N<<" "<<R<<endl;
    for(int j=0; j<R; j++){
      cin>>a>>b>>l;
      //v.push_back(make_pair(l,make_pair(a,b)));
      A[a].PB(MP(l, b)); // arista (a, b) con coste l
      A[b].PB(MP(l, a)); // arista (a, b) con coste l
      //cout<<a<<" "<<b<<" "<<l<<endl;
    }
    //printVector(v);
    cin>>Q;
    //cout<<Q<<endl;
    for(int j=0; j<Q; j++){
      cin>>k>>t;
      //cout<<k<<" "<<t<<endl;
      cout << dijkstra(k, t) << endl;
    }
    if(i < tc-1)
      cout<<endl;
    for(int i=0; i<N; i++)
      A[i].clear();
  }
  
  return 0;
}


















