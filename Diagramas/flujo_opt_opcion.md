# Opt opcion

~~~mermaid
    flowchart TD
        A((INICIO))
        A------>B
    subgraph Obtiene opcion
        B[/Imprime: Ingresa la opcion deseada/]
        B-->C[/Lee: string opc/]
    end
        C-->D
    subgraph Valida opcion
        D{leer falla o tamaño de opcion != 1}
        D-- F -->E(crear int opc_i)
        E-->F(convertir opc o entero en opc_i)
        F-->G{conversion falla}
        G-- V -->H(opc_i = 0)
        G-- F -->I(opc_i = opc)
        H & I -->J{opc_i < 1 o opc_i > 4}
    end
        D-- V -->K
        J-- V -->K
    subgraph Mensaje Error
        K[/Imprimir: Opcion no valida. Presiona Enter para continuar/]
        K-->L[[mostrar_menu]]
    end
        J-- F -->M
        L-->B
    subgraph Salida
        M[/Devuelve: opc_i/]
        M-->N((FIN))
    end

~~~
