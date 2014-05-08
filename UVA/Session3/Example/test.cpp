//Fibonacci recursivo tiene una complejidad de 2^n (porque por cada elemento se llama 2 veces a la funcion) --> Dinamico sera n.
//Problema de la moneda:
//Recursivo:

A[3] = {1,4,6}
int moneda(int n){

  if(n==0) return 0;
  if(n<0) return -1;
  return 1 + min( moneda(n-A[0]), moneda(n-A[1]), moneda(n-A[2]));
}

//Memoizacion

C[7] = {0,1,-1,-1,1,-1,1};

mismo codio que el recursivo, pero guardando en C los valores encontrados.

/*knapsack
Mochila_Volumen = 8;
Si quisiese maximizar objetos añado 1 en la recursividad, pero
si quiero maximizar el valor
Dado una cantidad de objetos con un volumen maximizame el valor

*/
