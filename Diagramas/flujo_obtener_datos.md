# Obtener Datos

~~~mermaid
    flowchart TB
        A((INICIO))
        A-->B[/Recibe: array vacio, tipo de dato seleccionado, tamaño del array/]
        B-->C
    subgraph Obtener Dato 
        C[/Imprime: Ingresa los datos uno por uno, presiona Enter para enviar cada dato/]
        C-->D{i < tamaño array}
        D-- F -->X((FIN))
        D-- V -->E[/Imprime: Dato i + 1: /]
        E-->F[/Lee: dato en array/]
    end
        F-->G
    subgraph Validar dato 
        G{Leer falló}
    end
        G-- V -->H
        G-- F -->Z(i = i + 1)-->D
    subgraph Mensaje Error
        H[/Imprimir: Valor invalido. Reingresa un valor valido/]
    end
        H-->F

~~~
