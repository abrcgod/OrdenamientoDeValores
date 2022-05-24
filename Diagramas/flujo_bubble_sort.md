# bubble_sort

~~~mermaid
    flowchart TB
        A((INICIO))
        A-->B[/Recibe: array vacio y tamaño de array/]
        B-->Z(define: i = 0, j = 0)
        Z-->D
    subgraph Ordenamiento
        D{i < tamaño del array}
        D-- F -->V((FIN))
        D-- V -->E{j < tamaño del array -i -1}
        E-- F -->H(i = i + 1)
        H-->D
        E-- V -->J{array en j > array en j + 1}
        J-- V -->K[[Swap array en j con array en j+ 1]]
        K-->L(j = j + 1)
        J-- F -->L
        L-->E
    end
~~~
