# bubble_sort

~~~mermaid
    flowchart TB
        A((INICIO))
        A==>B[/Recibe: array desordenado, tamaño de array/]
        B==>C(Itera sobre el array)
        C== Elemento actual menor que elemento siguiente ==>D(Intercambia elementos)
        C== Elemento actual no es menor al siguiente ==>E(Continua al par siguiente)==>C
        C== Fin del array ==> F((FIN))


~~~
