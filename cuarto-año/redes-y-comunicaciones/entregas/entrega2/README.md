# Entrega 2

## Punto 1

Hay dos intentos de conexiones TCP en la captura.

## Punto 2

-   Fuente: 10.0.1.10:51375
-   Destino: 10.0.3.10:5001

y la exitosa es

-   Fuente: 10.0.1.10:51376
-   Destino: 10.0.3.10:5001

## Punto 3

Hay dos intentos de conexiones. Solo uno de ellos es exitoso y podemos identificarlo de la siguiente forma:

El flag RST (ver practica 5)...

Luego, en el caso de la primer conexion, podemos ver que el servidor destino responde con el flag RST ACK, indicandole al servidor fuente que el mismo no esta escuchando en ese puerto. Luego, el servidor origen intenta nuevamente establecer la conexion. En este caso el servidor responde con el flag SYN ACK y el cliente establece exitosamente la conexion respondiendo con el flag ACK.

## Punto 6

Mirar la respuesta con el flag SYN ACK que esta recontra explicito.

## Punto 7

10.0.1.10:51376 envia mas datos

## Punto 8

Copiar y pegar la linea 10

lleva 24bytes

se confirma en la linea 11

le confirma 24 bytes dado que le devuelve un ACK = 24 


## Punto 11

mirar linea 1263