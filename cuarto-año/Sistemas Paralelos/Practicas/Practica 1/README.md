# Practica 1

#### Pautas

En todos los ejercicios de matrices probar con tamaños de matriz potencias de 2
(32, 64, 128, 256, 512, 1024, 2048) etc.

### Ejercicio 1

Hay dos cuestiones simples a optimizar en cuanto al código. La primera es
respecto del acceso a los valores en las matrices. En el codigo se accede
a los datos de la matriz por fila. Cuando se cambia esta configuracion
establecida mediante macros, accediendo por columnas, el tiempo de
ejecucion es menor. Luego, se puede optimizar el uso del stack. Por cada
llamado a una función se carga las referencias necesarias en el stack,
así como los parametros enviados. Esto podría optimizarse minimamente
mediante el uso de funciones `inline`, pero en este caso quedaría a
elección del compilador evaluar si la función pasa a ser efectivamente
inline o no. Al mismo tiempo esto se podría forzar mediante extensiones
del compilador, pero no va al caso. La solucion mas simple es evitar
el llamado a estas funciones cambiando el codigo donde estas rutinas
son llamadas por el codigo correspondiente sin el llamado.

### Ejercicio 2

Viendo muy rapidamente ambos algortimos vemos la misma estructura en cuanto
a lo que refiere a inicialización de estructuras se refiere, por lo que
se descarta en este analisis esos fragmentos de programas al momento de
estudiar la complejidad de los mismos.

En cuanto al tiempo de ejecucion de los programas, se nota una gran diferencia
entre uno y el otro. Para poner un ejemplo, con un input de `512`,
el tiempo promedio de `SumMulMatrices` es de aproximadamente `1.5 segundos`
mientras que el de `SumMulMatricesOpt` es `1.15 segundos`. Es una gran
diferencia que talvez puede parecer rara si no le prestamos demasiada atencion
a cada una de las lineas de codigo en las que se resuelve la operacion
con las matrices. Sin embargo, mirando más detalladamente, se puede notar
algo que posiblemente sea un error en el código del primer programa mencionado,
y se puede notar mejor en el siguiente fragmento de código:

```c

for (i = 0; i < N; i++)
{
        for (j = 0; j < N; j++)
        {
                ab[i*N + j] = 0;
                cd[i*N + j] = 0;
                for (k = 0; k < N; k++) {
                        ab[i*N + j] = ab[i*N+j] + A[i*N + k] * B[k + j*N];
                        cd[i*N + j] = cd[i*N + j] + C[i*N + k] * D[k + j*N];
                        tot[i*N + j] = cd[i*N + j]+ ab[i*N + j];
                }
        }
}
```

Si nos centramos en esta linea de codigo,

```c
tot[i*N + j] = cd[i*N + j]+ ab[i*N + j];
```
, podemos observar que la misma esta definida unicamente en función de las
variables _i_ y _j_, pero no de _k_. Esto permitiría sacarla de una de las
iteraciones y reduciendo notablemente el tiempo de ejecucion.
Haciendo esto, la media de ejecucion pasa de `1.5 s` a `1.07 s`, siendo así
más rápidos que el planteado por el otro programa. Al mismo tiempo,
se pueden evitar las inicializaciones en 0 de la matriz si en lugar de utilizar
`malloc` se utilizara `calloc` para las matrices _ab_ y _cd_, siendo
estas las unicas matrices que necesariamente deben tener esa inicialización.

En este caso, los códigos quedaría de la siguiente forma:

```c
ab = (double*) calloc(N*N, sizeof(double));
cd = (double*) calloc(N*N, sizeof(double));
```

```c

for (i = 0; i < N; i++)
{
        for (j = 0; j < N; j++)
        {
                for (k = 0; k < N; k++)
                {
                        ab[i*N + j] = ab[i*N+j] + A[i*N + k] * B[k + j*N];
                        cd[i*N + j] = cd[i*N + j] + C[i*N + k] * D[k + j*N];
                }

                tot[i*N + j] = cd[i*N + j]+ ab[i*N + j];
        }
}
```
