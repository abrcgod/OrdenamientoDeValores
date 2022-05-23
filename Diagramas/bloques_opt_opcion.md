# Opt Opcion

~~~mermaid
flowchart TD
    A((INICIO))==>B[/Optiene opcion del usuario/]
    B==>C(Valida opcion)
    C== Correcta ==>D[/Devuelve: opcion/]
    C== Incorrecta ==>E(Mensaje de error)
    E==>B
    D==>F((FIN))
~~~
