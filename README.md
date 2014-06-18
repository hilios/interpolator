Interpolator
============

This is a academic project that implements two interpolation functions in C++:

- [Lagrange polynomial](http://en.wikipedia.org/wiki/Lagrange_polynomial)
- [Newton polynomial](http://en.wikipedia.org/wiki/Newton_polynomial)

For a given set of data points (X,Y) generate the only polynomial, of least possible degree, that passes through all of them.

This is a interactive shell software, that allow to genereate the polynomial and plot any number within the function.

#### Output

```sh
                  Trabalho de Métodos Numéricos
------------------------------------------------------------------
|                    Programa de Interpolação                    |
------------------------------------------------------------------

Qual função de interpolação deseja utilizar?
1: Lagrange, 2: Newton = 1
Digite os valores de X
x(0) = 1.3
Deseja digitar outro valor? S: Sim, N: Não = S
x(1) = 3.4
Deseja digitar outro valor? S: Sim, N: Não = N
Digite os valores de f(x)
f(x_0) = 2.3
f(x_1) = 2.9

Valores informados são:
 x  : 1.3 3.4
f(x): 2.3 2.9

Funções parciais:
L0(x) = -0.47619x+1.61905
L1(x) = +0.47619x-0.619048
A função de aproximação é:
P(x) = +0.285714x+1.92857

Quer plotar um ponto com esta função? S: Sim, N: Não = S
x = 0.5
P(0.5) = 2.07143

Deseja repetir a operação? S: Sim, N: Não = N
```
