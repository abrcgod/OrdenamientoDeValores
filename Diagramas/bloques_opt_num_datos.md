# Opt_num_datos

~~~mermaid
    flowchart TD
        A((INICIO))
        A==>B[/Preguntar numero de datos/]
        B==>C(Validar numero de datos)
        C== Correcta ==>G[/Devolver: cant_datos/]==>D((FIN))
        C== Incorrecta ==>E(Mensaje Error)
        E==>B
~~~
