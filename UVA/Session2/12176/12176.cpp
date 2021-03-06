//Utilizar Kruskal para sacar el arbol con valores minimos, y luego hacer un DFS y coger el valor de la arista mas grande

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
#include <stack>

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

int N, mf[3001]; // numero de nodos N <= 2000
V v;             // lista de aristas (coste, (nodo1, nodo2))
vector<pair<int,int> > A[10001];   // listas de adyacencia

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
      //vmin.push_back(v[i]);
      A[v[i].second.first].push_back(make_pair(v[i].second.second,v[i].first));
      A[v[i].second.second].push_back(make_pair(v[i].second.first,v[i].first));
    }
  }
  return sum;
}

void printVector(vector<pair<int,pair<int,int> > > &v){
  
  for(int i=0; i<int(v.size());++i){
    cout<<" "<<v[i].second.first<<" "<<v[i].second.second<<" "<<v[i].first<<endl;
  }
  cout<<endl; 
  
}


/*int BFS(int s, int t) { // distancia entre s y t
  if (s == t) return 0;
  pair<int,int> l[100001];
  int k = 0;  // inicializar cola
  vector<int> v(N, -1); // inicializar distancias
  l[k++] = make_pair(s,0); // agregar s a la cola
  v[s] = 0;             // distancia hasta s es 0
  
  for (int i = 0; i < k; i++)
    // para todos los nodos adyacentes de l[i]
    for (int j = 0; j < (int)A[l[i].first].SZ; j++)
      // si el vecino no se ha visitado
      if (v[ A[ l[i].first ][j].first ] < 0) {
        // actualizar su distancia
        
        if( A[l[i].first][j].second > l[i].second)
          v[A[l[i].first][j].first] = A[l[i].first][j].second;
        else
          v[A[l[i].first][j].first] = l[i].second;
              // si encontramos t, devolver resultado

	      if (A[l[i].first][j].first == t) return v[t];
              // agregar a la cola
        
	      l[k++] = A[l[i].first][j];
	      
      }
  return -1;
}*/

int DFS(int s, int t) { // distancia entre s y t
  if (s == t) return 0;
  stack<pair<int,int> > l;
  vector<int> v(N, -1); // inicializar distancias
  l.push(make_pair(s,0));
  v[s] = 0;             // distancia hasta s es 0
  
  pair<int,int> a,b;
  while(!l.empty()){
    // para todos los nodos adyacentes de l.top()
    a = l.top();
    l.pop();
    //cout<<a.first<<endl;
    for (int j = (int)A[a.first].SZ-1; j >=0 ; j--){
      // si el vecino no se ha visitado
      if (v[ A[ a.first ][j].first ] < 0) {
        // actualizar su distancia
        
        if( A[a.first][j].second > a.second)
          v[A[a.first][j].first] = A[a.first][j].second;
        else
          v[A[a.first][j].first] = a.second;
              // si encontramos t, devolver resultado

	      if (A[a.first][j].first == t) return v[t];
              // agregar a la cola
        
	      //l[k++] = A[l[i].first][j];
	      //l.push(A[a.first][j]);
	      b = A[a.first][j];
	      b.second = v[A[a.first][j].first];
	      l.push(b);
	      
      }
    }
  }
  return -1;
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
      v.push_back(make_pair(l,make_pair(a,b)));
      //cout<<a<<" "<<b<<" "<<l<<endl;
    }
    kruskal();
    
    cin>>Q;
    //cout<<Q<<endl;
    for(int j=0; j<Q; j++){
      cin>>k>>t;
      //cout<<k<<" "<<t<<endl;
      //cout<<"\n"<<DFS(k,t)<<"\n"<<endl;
      cout<<DFS(k,t)<<endl;
    }
    //if(i < tc-1)
      cout<<endl;
    v.clear();
    for(int i=0; i<N; i++) A[i].clear();
  }
  
  return 0;
}


















