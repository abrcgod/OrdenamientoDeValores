# opt num datos

~~~mermaid
    flowchart TD
        A((INICIO))
        A---->B
    subgraph Optener Opcion
        B[/Imprimir: Cuantos datos quiere ingresar?/]
        B-->C[/Leer: string cant_datos/]
    end
        C-->X(convertir string a int en cant_datos_i)-->E
    subgraph Validar Opcion
        E{Conversión falló}
        E-- V -->c(cant_datos_i = 0)
        c-->a{cant_datos_i == 0}
    end
        a-- V -->F
    subgraph error
        F[/Imprimir: Ingrese una cantidad numerica entera, diferente de 0/]
        F-->b[[cant_datos_i = obtener_cant_datos]]
    end
        E-- F -->G
        b-->G
    subgraph Salida
        G[/Devolver cant_datos_i/]
        G-->Z((FIN))
    end
~~~
