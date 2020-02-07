# Práctica 6

## Ejercicio 1

> Explique brevemente los siguientes conceptos
> 
> * Parámetro
> * Parámetro real
> * Parámetro formal
> * Ligadura posicional
> * Ligadura por palabra clave o nombre

**Parámetro**: entidad local a una rutina usada para representar *recepción* de datos al momento de la invocación.

**Parámetro real**: es la entidad que da valor a un parámetro en una invocación a una rutina.

**Parámetro formal**: es la entidad local a la rutina que representa al parámetro.

**Ligadura posicional**: la ligadura entre el parámetro formal y el real se lleva a cabo a partir de la posición de los mismos.

**Ligadura por palabra clave o nombre**: la ligadura entre el parámetro formal y el real se efectúa indicando el nombre de los mismos.

## Ejercicio 2

![](./images/06_02.png)

### Modo IN

El **parámetro formal** recibe el dato del **real**.

##### Valor

Se copia el valor efectivo (*l-valor*) del **parámetro real** al **parámetro formal**. La rutina puede sobreescribir el *l-valor* del **formal**, pero los cambios no se verán reflejados en el **real**.

```c
int func(int b) {
	printf("%d", b); // => 3
	b = 0;
	printf("%d", b); // => 0
}

int main() {
	int a = 3;
	printf("%d", a); // => 3
	func(a);
	printf("%d", a); // => 3
	return 0;
}
```

##### Valor constante

Sólo especifica que el **parámetro real** **no debe ser modificado**.

```c
int func(const int b) {
	printf("%d", b); // => 3
	b = 0; // operación inválida -> error en compilación
	printf("%d", b); // => 0
}

int main() {
	int a = 3;
	printf("%d", a); // => 3
	func(a);
	printf("%d", a); // => 3
	return 0;
}
```

### Modo OUT

El **parámetro real** recibe el dato del **formal**.

##### Resultado

El *l-valor* del **parámetro formal** se copiará en el *l-valor* del **parámetro real** al finalizar la rutina.

```c
int func(result int b) {
	b = 0; // se modifica el parámetro formal b
}

int main() {
	int a = 3;
	printf("%d", a); // => 3
	func(a); // al finalizar func(), se copia el resultado de b en a
	printf("%d", a); // => 0
	return 0;
}
```

##### Resultado de funciones

No hay **parámetro real**. El **valor de retorno** de la rutina *reemplaza* a su invocación en la expresión llamadora.

```c
int func() {
	return 1;
}

int main() {
	int a = func();
	printf("%d", a); // => 1
	return 0;
}
```

### Modo IN/OUT

El **parámetro formal** recibe el dato del real, y a su vez el **parámetro real** recibe el dato del formal.

##### Valor-Resultado

Al inicio de la rutina se copia el *l-valor* del **parámetro real** al **formal**, y al finalizar se copia el *l-valor* del **parámetro formal** al **real**. Las referencias al **parámetro formal** son locales y las modificaciones no alteran al **parámetro real**.

##### Referencia

Se copia la **dirección** del **parámetro real** al **parámetro formal**. Las referencias al **parámetro formal** son en realidad al **parámetro real**, por lo que las modificaciones se verán reflejadas fuera de la rutina.

##### Nombre

Se sustituye, en todas sus ocurrencias, el *identificador* del **parámetro formal** por el *identificador* del **parámetro real**. *Nota: no es lo que **realmente** ocurre en la implementación, pero es una buena forma de entenderlo*. Ejemplo:

```c
int a[10];
int i = 0;

int fun(param_by_name b) {
 	i = 1;
 	b = 5;
 	i = 3;
 	b = 9;
 	return b;
}

int main() {
	printf("%d", fun(a[i]));
	return 0;
}
```

Como `main` invoca a `fun` enviándole como parámetro `a[i]`, se *reemplazan* las ocurrencias de `b` (que es el parámetro formal) por `a[i]` (que es el parámetro real). Podría verse al código de `fun` en el contexto de esta invocación como:

```c
int fun(param_by_name b) {
 	i = 1;
 	~~b~~ a[i] = 5;
 	i = 3;
 	~~b~~ a[i] = 9;
 	return ~~b~~ a[i];
}
```

## Ejercicio 3

### a

> Complete el cuadro

Tipo de pasaje de parámetros                  | Lenguaje
---                                           | ---
valor, resultado, valor-resultado, referencia | ADA
valor, valor constante                        | C
valor/referencia?                             | Ruby
valor/referencia                              | Java
valor/referencia?                             | Python

### b

> Ada es más seguro que Pascal respecto al pasaje de parámetros en las funciones. Explique por qué.

En Ada las funciones admiten sólo pasaje de parámetros por valor, lo cual impide que estas produzcan **efectos laterales**.

### c

> Explique cómo maneja Ada los tipos de parámetros IN-OUT de acuerdo al tipo de dato.

* Tipos primitivos: pasaje de parámetros por **valor-resultado**
* Tipos no primitivos/compuestos: pasaje de parámetros por **referencia**

## Ejercicio 5

	(4, 6, 7), (4, 6, 7), 2, 2
		vector -> referencia
		a -> referencia

	(3, 5, 6), (4, 6, 7), 2, 2
		vector -> valor
		a -> referencia

	(3, 5, 6), (5, 5, 6), 0, -1
		vector -> valor
		a -> valor
	

