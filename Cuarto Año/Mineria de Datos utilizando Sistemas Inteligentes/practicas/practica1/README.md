# Practica 1

## Punto 1

Indique qué tipo de información brindan las siguientes representaciones gráficas:

#### Diagrama de Dispersión _(scatter plot)_

Un **diagrama de dispersión** es un tipo de diagrama matemático que utiliza
las coordenadas cartesianas para mostrar los valores de dos variables
para un conjunto de datos.

Se emplea cuando una variable está bajo el control del experimentador.
Si existe un parámetro que se incrementa o disminuye de forma sistemática
por el experimentador, se le denomina parámetro de control o variable
independiente y habitualmente se representa a lo largo del eje horizontal
(eje de las abscisas). La variable medida o dependiente usualmente se
representa a lo largo del eje vertical (eje de las ordenadas).
Si no existe una variable dependiente, cualquier variable se puede
representar en cada eje y el diagrama de dispersión mostrará el
grado de correlación (no causalidad) entre las dos variables.

Un diagrama de dispersión puede sugerir varios tipos de correlaciones
entre las variables con un intervalo de confianza determinado.
La correlación puede ser positiva (aumento), negativa (descenso),
o nula (las variables no están correlacionadas). Se puede dibujar una
línea de ajuste (llamada también "línea de tendencia") con el fin de
estudiar la correlación entre las variables. Una ecuación para la
correlación entre las variables puede ser determinada por procedimientos
de ajuste. Para una correlación lineal, el procedimiento de ajuste es
conocido como regresión lineal y garantiza una solución correcta en
un tiempo finito.

Uno de los aspectos más poderosos de un gráfico de dispersión,
sin embargo, es su capacidad para mostrar las relaciones
no lineales entre las variables. Además, si los datos son representados
por un modelo de mezcla de relaciones simples, estas relaciones
son visualmente evidentes como patrones superpuestos.

#### Diagrama de Caja _(box plot)_

Un **diagrama de caja**, también conocido como diagrama de caja y bigotes,
es un gráfico que está basado en cuartiles y mediante el cual se visualiza
la distribución de un conjunto de datos. Está compuesto por un rectángulo
(la _caja_) y dos brazos (los _bigotes_).

Es un gráfico que suministra información sobre los valores mínimo y máximo,
los cuartiles Q1, Q2 o mediana y Q3, y sobre la existencia de valores atípicos
y la simetría de la distribución. Primero es necesario encontrar la mediana
para luego encontrar los 2 cuartiles restantes.

Un diagrama de cajas proporcionan una visión general de la simetría
de la distribución de los datos; si la mediana no está en el centro
del rectángulo, la distribución no es simétrica. Son útiles para ver la
presencia de valores atípicos también llamados outliers. Pertenece a las
herramientas de las estadística descriptiva. Permite ver como es la
dispersión de los puntos con la mediana, los percentiles 25 y 75 y los
valores máximos y mínimos. Ponen en una sola dimensión los datos
de un histograma, facilitando así el análisis de la información al
detectar que el 50% de la población está en los límites de la caja.

#### Histograma

En estadística, un **histograma** es una representación gráfica de una
variable en forma de barras, donde la superficie de cada barra es
proporcional a la frecuencia de los valores representados. Sirven
para obtener una "primera vista" general, o panorama, de la distribución
de la población, o de la muestra, respecto a una característica, cuantitativa
y continua (como la longitud o el peso). De esta manera ofrece una visión
de grupo permitiendo observar una preferencia, o tendencia, por parte de
la muestra o población por ubicarse hacia una determinada región de valores
dentro del espectro de valores posibles (sean infinitos o no) que pueda
adquirir la característica. Así pues, podemos evidenciar comportamientos,
observar el grado de homogeneidad, acuerdo o concisión entre los valores
de todas las partes que componen la población o la muestra, o, en
contraposición, poder observar el grado de variabilidad, y por ende,
la dispersión de todos los valores que toman las partes, también es posible
no evidenciar ninguna tendencia y obtener que cada miembro de la población
toma por su lado y adquiere un valor de la característica aleatoriamente sin
mostrar ninguna preferencia o tendencia, entre otras cosas.

#### Diagramas de Barras

Un **diagrama de barras** es una forma de representar gráficamente un conjunto
de datos o valores, y está conformado por barras rectangulares de longitudes
proporcionales a los valores representados. Los gráficos de barras son usados
para comparar dos o más valores. Las barras pueden orientarse horizontal o
verticalmente.

## Punto 2

En la Figura 1 se pueden ver los diagramas de clase correspondientes al atributo
**Practica** separando los alumnos que aprobaron el curso de los que no
lo hicieron (atributo **Calificacion**). Utilícelos, en caso de ser posible,
para indicar el valor de verdad de las siguientes afirmaciones.
Si no es posible, justifique:

Un diagrama de cajas es un gráfico que suministra información sobre
los valores mínimo y máximo, los cuartiles Q1, Q2 o mediana y Q3, y
sobre la existencia de valores atípicos y la simetría de la distribución.

1.  La mayoría de los alumnos aprobaron el curso.

No me permite saber esta información, dado que no conozco a partir del gráfico
la frecuencia de datos para los alumnos aprobados. Para obtener esto rapidamente,
podría utilizar un gráfico de barras sobre el atributo CALIFICACIÓN.

2.  Conocer el valor que un alumno ha obtenido en el atributo **Practica** no alcanza para
    determinar la **Calificacion** que obtuvo en el curso.

No es una conclusión que se pueda extraer directamente del gráfico de cajas,
pero si puede extraerse a partir de los valores atípicos (información la
cual provee este tipo de gráficos). Entonces podríamos decir que este gráfico
en cuestion permite concluir esto.

3.  Al menos el 50% de los alumnos que aprobaron el curso obtuvo una nota de **Practica**
    superior a 6 puntos.

Claramente, dado que la mediana se encuentra por encima de esa nota, podemos
saber eso a partir del gráfico.

4.  Al menos el 50% de los desaprobados obtuvo una nota de **Practica** inferior a 4 puntos.

Claramente, dado que la mediana se encuentra por debajo de esa nota, podemos
saber eso a partir del gráfico.

5.  Todos los alumnos que obtuvieron 8 o más como nota de **Practica** aprobaron el curso.

Esto es falso, y lo podemos determinar a partir de los valores atípicos que
nos muestra el gráfico.

6.  Es raro que un alumno que aprobó el curso obtenga una nota de **Practica** inferior a 1
    punto.

Lo podemos determinar dados los valores atípicos que aparecen en la gráfica,
y esto es porque el brazo _ó bigote_ inferior, no llega a abarcar esas
dos mediciones que se muestran.

## Punto 3

Abra el archivo **Curso.xls** y visualice los metadatos.

1.  Indique cuáles son los atributos que presentan datos faltantes.

Los atributos faltantes son:

-   Practica
-   Activ_Distancia
-   Activ_Presencial
-   Trabaja
-   Colegio_UNLP

2.  ¿Puede indicar con sólo observar los metadatos cuántos alumnos poseen la información
    correspondiente a los 6 atributos completa? Es decir, ¿cuántos alumnos NO presentan
    datos faltantes?

3.  ¿Por qué es necesario completar los datos faltantes? Mencione al menos tres formas de
    realizar esta tarea. Indique en cada caso como influye en la distribución de valores del
    atributo.

Los **valores faltantes**, perdidos o ausentes _(missing values)_ pueden ser reemplazados por
varias razones. En primer lugar, el método de minería de datos que utilicemos puede no
tratar bien los campos faltantes. En segundo lugar, podemos querer agregar los datos
(especialmente los numéricos) para realizar otras vistas minables y que los valores faltantes
no nos permitan agregar correctamente (totales, medias, etc.). En tercer lugar, si el método
es capaz de tratar campos faltantes es posible que ignore todo el ejemplo (produciendo un
sesgo) o es posible que tenga un método de sustitución de campos faltantes que no sea
adecuado debido a que no conoce el contexto asociado al atributo faltante.

A la hora de hablar de campos faltantes, debemos tratar de su detección y de su
tratamiento. La detección de campos faltantes puede parecer sencilla. Si los datos proceden
de una base de datos, basta mirar en la tabla de resumen de atributos/características y ver
la cantidad de nulos que tiene cada atributo. El problema es que a veces los campos
faltantes no están representados como nulos. Por ejemplo, aunque hay campos en los que
las restricciones de integridad del sistema evitan introducir códigos fuera del formato para
representar valores faltantes, esto al final ocurre en muchos otros, especialmente en campos
sin formato: direcciones o teléfono como “no tiene”, códigos postales o números de tarjeta
de crédito con valor –1, etc. A veces son las propias restricciones de integridad las que
causan el problema.

-   Ignorar la tupla.
-   Rellenar la tupla manualmente.
-   Usar una constante global para rellenar el valor nulo.
-   Utilizar el valor de la media u otra medida de centralidad para rellenar el valor.
-   Utilizar el valor de la media u otra medida de centralidad de los objetos que pertenecen la misma clase.
-   Utilizar alguna herramienta de Minería de Datos para calcular el valor más probable.

4.  Utilice el operador **ReplaceMissingValues** para completar los datos faltantes utilizando las
    opciones por defecto para todos los atributos salvo **Activ_Distancia** que deber
    completarse con el valor mínimo. Ejecute el proceso y verifique que ya no quedan datos
    faltantes. Indique cuales han sido los valores utilizados para completar cada atributo.

## Punto 4

El atributo **Activ_Presencial** debe contener valores entre 0 y 1 indicando
la proporción entre la cantidad de clases a las que asistió el alumno y
el total de clases del curso. Ej: un valor 0.1 indica que el alumno
asistió al 10% de las clases. Utilice un diagrama de caja para verificar
que existen valores excesivamente fuera de rango en el atributo **Activ_Presencial**.
Utilice el operador **GenerateAttribute** para generar un nuevo atributo
llamado **ASISTENCIA** que posea los mismos valores que **Activ_Presencial** cuando
éste posea un valor menor o igual a 1 y **Activ_Presencial/100** cuando supera 1.
Rehaga el diagrama de caja para el atributo **ASISTENCIA** y verifique que no
existen valores fuera de rango extremos.

## Punto 5

El atributo **Trabaja** presenta errores en su codificación. Utilice el operador **Map**
para convertir los valores “S” en “si” y “N” en “no”.

## Punto 6

Utilice un mismo operador **DiscretizeByUserSpecification** para discretizar los valores de los
atributos **ASISTENCIA** y **Activ_Distancia** asignando la etiqueta BAJA o ALTA según si el valor del
atributo es menor o igual a 0.5 o no respectivamente.

## Punto 7

Utilice otro operador **DiscretizeByBinning** para discretizar los valores del atributo **Practica**
dividiendo su rango en tres intervalos. Observe los metadatos e indique como quedaron
formados los intervalos y cuántos alumnos hay en cada uno de ellos.

| Nominal Value          | Absolute count | Fraction |
| ---------------------- | :------------- | :------- |
| range2 [3.337 - 6.668] | 104            | 0.52     |
| range1 [-∞ - 3.337]    | 55             | 0.275    |
| range3 [6.668 - ∞]     | 41             | 0.205    |

## Punto 8

¿Qué diferencia hay entre una discretización por intervalos **_(DiscretizeByBinning)_** y una
discretización por frecuencia **_(DiscretizeByFrecuency)_**?

Ejemplifique nuevamente su respuesta utilizando la información del archivo Curso.xls

La diferencia entre ambos es que el primero discretización por intervalos
(bins) iguales, es decir dividiendo el rango en partes iguales, mientras que el
segundo operador permite discretizar por frecuencia, es decir, dividiendo la
cantidad de ejemplos en partes iguales.

## Punto 9

En el siguiente link encontrará información referida al uso de bicicletas que el Gobierno de la
Ciudad de Buenos Aires pone a disposición de la población en forma gratuita como medio de
transporte:

[recorrido-bicis-2016.csv](https://recursos-data.buenosaires.gob.ar/ckan2/bicicletas-publicas/recorrido-bicis-2016.csv)

Estas bicicletas están ubicadas en distintos puntos de la ciudad y se encuentran disponibles las
24 horas del día durante todo el año. En el archivo encontrará información referida a las
estaciones de origen y destino, la hora de partida y la duración de los viajes realizados por las
bicicletas durante el año 2016.

1.  A partir del atributo FECHA_HORA_RETIRO genere un atributo nuevo que contenga
    únicamente el horario en el cual la bicicleta fue retirada. Luego, utilizando el diagrama de
    caja visto en clase, informe si hay horarios inusuales (fuera de rango) de retiro de
    bicicletas. Justifique su respuesta indicando los valores de los cuartiles y el criterio
    utilizado para decidir qué es un horario inusual.

Para generar el nuevo atributo **HORA** utilicé el operador **GenerateAttribute**
con la siguiente función:

HORA_RETIRO &lt;= `parse(date_str_custom(date_parse_custom(FECHA_HORA_RETIRO, "dd/MM/yyyy HH:mm"), "HH"))`

Se pueden observar los horarios inusuales, dado que estos estan fuera del
rango que alcanzan los _bigotes_ en el gráfico de cajas.

2.  Indique el valor de verdad de la siguiente proposición: “Se obtendrán los mismos
    resultados si se discretiza por rango el atributo generado en a) utilizando 4 intervalos que
    si se lo discretiza por frecuencia utilizando 4 intervalos”. Justifique su respuesta.

Para aplicar los operadores, la función `parse()` mencionada anteriormente debe
ser utilizada, para pasar de tipo de dato **Nominal** a **Integer**. Como era
de esperarse, los resultados obtenidos no fueron los mismos, y esto es porque
la discretización generará intervalos distintos en ambos casos.

3.  A partir del atributo FECHA_HORA_RETIRO genere un segundo atributo con el número de
    mes en el cual la bicicleta fue retirada. Grafique manualmente el histograma
    correspondiente a este atributo utilizando 3 intervalos.

MES_RETIRO &lt;= `parse(date_str_custom(date_parse_custom(FECHA_HORA_RETIRO, "dd/MM/yyyy HH:mm"), "MM"))`

## Punto 10

Analice la información del archivo **Sopas.xls** cuyo contenido se encuentra descripto en “Caso
de Estudio 2: Sopas.pdf”.

1.  Indique qué tipo de gráfica puede construir con los atributos. Ejemplifique cada caso.

2.  Utilizando distintas representaciones gráficas, describa la distribución de los atributos, e
    indique si observa relaciones entre los mismos.

3.  La Minería de Datos permite extraer dos tipos de conocimiento: descriptivo y predictivo.
    Ejemplifíquelos para el caso de las Sopas.

4.  Calcule el coeficiente de correlación lineal entre los atributos numéricos. Relacione los
    valores obtenidos con los diagramas de dispersión de cada par de atributos
