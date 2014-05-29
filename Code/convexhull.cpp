
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

#define X first
#define Y second

using namespace std;

typedef int T;       // tipo de coordenada
typedef pair<T,T> P; // puntos en el plano

// calcular el producto vectorial entre (p,q) y (p,r)
T xp(P p, P q, P r) {
  return (q.X-p.X)*(r.Y-p.Y) - (r.X-p.X)*(q.Y-p.Y);
}

// calcular el cuadrado de la longitud de (p,q)
T sd(P p, P q) {
  return (q.X-p.X)*(q.X-p.X) + (q.Y-p.Y)*(q.Y-p.Y);
}

// imprimir un par de dos valores
template <typename T,typename U>
ostream &operator<<(ostream &stream, pair<T,U> &p) {
  return stream << "(" << p.X << "," << p.Y << ")";
}

// imprimir un vector
template <typename T>
ostream &operator<<(ostream &stream, vector<T> &v) {
  stream << "[";
  if (v.size() > 0) stream << v[0];
  for (unsigned i = 1; i < v.size(); i++) stream << "," << v[i];
  return stream << "]";
}

// struct para comparar el angulo entre dos puntos
struct Punto {
  P p, q;
  Punto(P &a, P &b) : p(a), q(b) {}
  bool operator <(const Punto &pt) const {
    T res = xp(q, p, pt.p);
    return res > 0 || (res == 0 && sd(p, q) > sd(pt.p, pt.q));
  }
};

// calcular la envolvente convexa
vector<P> convexhull(vector<P> &v) {
  sort(v.begin(), v.end());
  vector<Punto> u;
  for (unsigned i = 1; i < v.size(); i++)
    u.push_back(Punto(v[i], v[0]));
  sort(u.begin(), u.end());

  vector<P> l;
  l.push_back(v[0]);
  l.push_back(u[0].p);
  for(unsigned i = 1; i < u.size(); i++){
    P p = l.back();
    l.pop_back();
    T o = xp(l.back(), p, u[i].p);
    if (o == 0)
      l.push_back(u[i].p);
    else if (o > 0){
      l.push_back(p);
      l.push_back(u[i].p);
    }
    else {
      while(o <= 0 && 1 < l.size()) {
	p = l.back();
	l.pop_back();
	o = xp(l.back(), p, u[i].p);
      }
      l.push_back(p);
      l.push_back(u[i].p);
    }
  }
  return l;
}

int main(){
  vector<P> v;
  v.push_back(make_pair(0, 1));
  v.push_back(make_pair(1, 2));
  v.push_back(make_pair(3, 2));
  v.push_back(make_pair(2, 1));
  v.push_back(make_pair(3, 1));
  v.push_back(make_pair(6, 3));
  v.push_back(make_pair(7, 0));
  vector<P> w = convexhull(v);
  cout << w << "\n";
} // resultado: [(0,1),(7,0),(6,3),(1,2)]
