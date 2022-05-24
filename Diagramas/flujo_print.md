# print

~~~mermaid
    flowchart TB
        A((INICIO))
        A-->B[/Recibe: Array, tamaño de array/]
        B-->C[/Imprime: Tus datos ordenados:/]
        C-->D
    subgraph Imprimir Arreglo
        D{i < tamaño del array}
        D-- Si -->E[/Imprime: Separador/]
        E-->F[/Imprime: elemento en posicion i del array/]
        F-->G(i = i + 1)
        G-->D
        D-- No -->J[/Imprime: Separador/]-->H((FIN))
    end



~~~
