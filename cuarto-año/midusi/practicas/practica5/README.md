# practica 5

## Ejercicio 1

### Cargar el conjunto de datos en Rapidminer. Recordar que el atributo cluster debe ser configurado como label para que no se considere al hacer el clustering.

### Determinar visualmente la cantidad de clusters utilizando algún gráfico de Rapidminer.

Se ven claramente 4 clusters utilizando el grafico Scatter.

### Utilizando los operadores Clustering (K-Means) y Performance: (Average) Silhouette, realice un clustering de los datos y evalúe el resultado con el índice promedio Silhouette. El clustering debe realizarse con k=2 y distancia Euclídea.

### Repita el punto 3 variando el valor de k (al menos con k=2,3,..,9). Haga una tabla con el valor del índice Silhouette para cada valor de k. Con esa tabla, determine el valor de k óptimo ¿coincide con el valor que determinó en el punto 2? Recuerde que en el índice Silhouette es mejor si el valor es más alto.

### Repita el punto 4, pero ahora con el puntuando el resultado del clustering con Davies-Bouldin en lugar de Silhouette. Para ello utilizar el operador Performance (Cluster Distance Performance), con main criterion=”Davies Bouldin”, y tildar “main criterion only”, “normalize” y “maximize”. Recuerde que el criterio Davies Bouldin es mejor cuando el valor es más chico.

### Repita los puntos 1-5 para el conjunto de datos 2d_complex.csv. Explicar por qué en este conjunto de datos el valor óptimo de k calculado con los índices Silhouette y Davies Bouldin no coincide con el óptimo determinado visualmente.

## Ejercicio 2

El archivo Vidrios2.csv contiene 214 muestras que corresponden a propiedades físicas de diferentes tipos de vidrios. Cada una está compuesta por los siguientes atributos:

-   RI: Indice de refracción

-   Na: Porcentaje de sodiopresente

-   Mg: Porcentaje de magnesio presente

-   Al: Porcentaje de aluminio presente

-   Si: Porcentaje de silicio presente

-   K: Porcentaje de potasio presente

-   Ca: Porcentaje de calciopresente

-   Ba: Porcentaje de bario presente

-   Fe: Porcentaje de hierro presente

-   Type: Tipo de vidrio
