# Print

~~~mermaid
    flowchart TB
        A((INICIO))
        A==>B[/Recibe: array, tamaño de array/]
        B==>C[/Imprime: dato actual en array/]
        C==>D{array terminado}
        D== V ==>E((Fin))
        D== F ==>F(Continua al siguiente dato)==>C
~~~
