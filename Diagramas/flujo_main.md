# Main

~~~mermaid
    flowchart TD
        A((INICIO))-->B[[mostrar_portada]]
        B-->C[[mostrar_menu]]
        C-->D[[obtener_opcion]]
        D-->E
    subgraph Switch
        E{opcion = 1}
        E-- F -->F{opcion = 2}
        F-- F -->G{opcion = 3}
        G-- F -->H{opcion= 4}
    end
        E-- V -->I
    subgraph Ordenar Numeros
        I[[obtener_cantidad_datos]]
        I-->J(crear arr_numeros)
        J-->K[[obtener_datos tipo numero]]
        K-->L[[bubble_sort]]
        L-->M[[print]] 
    end
        F-- V -->N
    subgraph Ordenar Caracteres
        N[[obtener_cantidad_datos]]
        N-->O(crear arr_char)
        O-->P[[obtener_datos tipo caracter]]
        P-->Q[[bubble_sort]]
        Q-->R[[print]]
    end 
        G-- V -->S
    subgraph Ordenar Palabras
        S[[obtener_cantidad_datos]]
        S-->T(crear arr_palabras)
        T-->U[[obtener_datos tipo palabra]]
        U-->V[[bubble_sort]]
        V-->W[[print]] 
    end 
     H-- V -->Y
     H-- F -->D
    subgraph Salida
        Y[/imprimir: Gracias por usar el programa. Presiona Enter para salir/]
        Y-->Z((FIN))
    end
        X-->C
        M-->X
        R-->X
        W-->X 
    subgraph Continuar
        X[/imprimir: Presiona Enter para volver al menu/]
    end 
~~~
