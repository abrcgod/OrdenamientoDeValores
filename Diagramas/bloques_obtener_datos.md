# obtener datos

~~~mermaid
    flowchart TD
        A((INICIO))
        A==>B[/Recibe: array vacio del tipo de dato requerido/]
        B==>C[/Recibe Dato/]
        C==>D(Valida dato)
        D== Correcto ==>E(Ingresa Dato en array)
        D== Incorrecto==>F(Mensaje Error)
        F==>C
        E== Array no lleno ==>C
        E== Array lleno ==>G((FIN))
~~~
