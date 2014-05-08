/* Pebble solitaire

Utilizar Bitmaps, si las combinaciones 

Cada juego puede ser un entero (2^12)
11000000 = 3
Utilizar bitmaps
Multiplicar '011' AND '111' --> '011'

11011 && 7 = 011 --> RECURSIVIDAD(11100)
11011 >> 1 = 01101 && 7 = 101 
...

MIN(Valor de 1's del primero, el Valor de 1's de los hijos)

Guardar en una array el valor de cada entero, si te viene un juego
de 1010000 sera el entero 5 y no tendra solucion

*/
