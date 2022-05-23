# Diagrama de Bloques

~~~mermaid
    flowchart TD
        A((Inicio))==>B(Portada)
        B==>C(Menu de Opciones)
        C==>D(Optener Opcion)
        D==Opciones de ordenamiento==>E(Obtener Datos)
        E==>F(Ordenar Datos)
        F==>G(Imprimir Datos)
        D==Opcion Salir==>H((Fin))
        G==Continuar==>C
~~~
