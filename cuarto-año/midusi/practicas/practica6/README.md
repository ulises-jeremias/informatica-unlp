# Practica 6 - Redes Neuronales

## Ejercicio 4

El perceptrón utiliza una función discriminante lineal para calcular la respuesta donde: `neta = w(perimetro) * PERIMETRO + w(area) * AREA + intercept`.

Luego, sabemos que INTERCEPT = 1.181647, w(Perimetro) = 1011.642, w(Area) = -134.399.

Sea PERIMETRO = 700, AREA = 5000, hoja corresponde a HELECHO, es decir,
si `neta = 1011.642*700 -134.399*5000 + 1.181647 = 36155.581647 > 0` entonces HOJA = HELECHO.

Luego, sabemos que si `neta < 0`, HOJA = TREBOL.

Finalmente, `neta = 1011.642*650 -134.399*5500 + 1.181647 = -81626.018353 < 0`,
por lo que HOJA = TREBOL cuando PERIMETRO = 650 y AREA = 5500.
