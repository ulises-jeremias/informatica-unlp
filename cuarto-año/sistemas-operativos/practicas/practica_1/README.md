# Práctica 1

## Repaso general

### 1. ¿Qué es la shell? ¿Para qué sirve?

Una shell o intérprete de órdenes o intérprete de comandos es el programa informático que provee una interfaz de usuario para acceder a los servicios del sistema operativo.

### 2. ¿En qué espacio (de usuario o de kernel) se ejecuta?

En el espacio de usuario.

### 3. Si pensamos en el funcionamiento de una shell básica podríamos detallarlo secuencialmente de la siguiente manera:

* Esperar a que el usuario ingrese un comando
* Procesar la entrada del usuario y obtener el comando con sus parámetros
* Crear un nuevo proceso para ejecutar el comando, iniciarlo y esperar que retorne
* Presentar la salida (de haberla) al usuario
* Volver a empezar.

Este tipo de comportamiento, típico de las shell interactivas, se conoce como REPL (ReadEval-Print Loop, Ciclo de leer, interpretar e imprimir).
Analice cómo implementaría este ciclo básico de interpretación de scripts.

### 4. Investigue la system call fork:

#### a. ¿Qué es lo que realiza?

Crea un nuevo proceso duplicando el proceso existente desde donde se llamo la funcion. El proceso existente de donde la función fue llamada se convierte en el proceso padre, y el proceso creado se convierte en el proceso hijo. Los procesos resultantes de este proceso son idénticos a su padre, salvo que tienen distinto número de proceso (PID). La operación fork crea un espacio de direcciones separado para el nuevo proceso hijo. Este tiene una copia exacta de todos los segmentos de memoria del proceso padre.

#### b. ¿Qué retorna?

La llamada a fork retorna al proceso padre el identificador del proceso hijo y retorna un cero al proceso hijo.

#### c. ¿Para qué podrian servir los valores que retorna?

A partir de los resultados se puede identificar cuál de los procesos es el padre y cuál es el hijo. También puede usarse para hacer frente a un error.

#### d. ¿Por qué invocaria a la misma al implementar una shell?

Cuando se ejecuta un proceso desde una shell, la shell hace un fork() antes de ejecutar el proceso. Esto se produce así porque cuando alguien llama a una instrucción de la familia de exec esto no crea un nuevo proceso, sino que reemplaza la memoria e instrucciones del proceso actual con las del proceso que se quiere ejecutar. Así que cuando bash quiere ejecutar algo primero tiene que hacer un fork() y luego ejecutar. Si no lo hiciera así, se ejecutaría el proceso pero no podriamos acceder mas a la terminal bash.

https://oskarth.com/unix01/

### 5. Investigue la system call exec:

#### a. ¿Para qué sirve?

Exec provee una funcionalidad que permite correr archivos ejecutables dentro del contexto de un proceso existente. Exec reemplaza el programa actual en el proceso actual sin necesidad de forkear un nuevo proceso. 

#### b. ¿Comó se comporta?

El comportamiento básico es conocido como overlay. No crea un nuevo proceso, por lo tanto el PID no cambia, pero el código, datos, heap, y el Stack del proceso son reemplazados por los del nuevo programa ejecutado. Al finalizar no se retorna al programa inicial.

#### c. ¿Cuáles son sus diferentes declaraciones POSIX?

### 6. Investigue la system call wait:

#### a. ¿Para qué sirve?

A call to wait() blocks the calling process until one of its child processes exits or a signal is received. After child process terminates, parent continues its execution after wait system call instruction.

Child process may terminate due to any of these:

* It calls exit();
* It returns (an int) from main
* It receives a signal (from the OS or another process) whose default action is to terminate.

#### b. Sin ella, ¿qué sucedería, pensando en la implementación de la shell?

Sin el wait no se podría esperar a que una línea de comando termine de ejecutarse para poder recibir la siguiente.

```
Every shell is structured as the following loop:
* print out a prompt
* read a line of input from the user
* parse the line into the program name, and an array of parameters
* use the fork() system call to spawn a new child process
  * the child process then uses the exec() system call to launch the specified program
  * the parent process (the shell) uses the wait() system call to wait for the child to terminate
* when the child (i.e. the launched program) finishes, the shell repeats the loop by jumping to 1.
Although most of the commands people type on the prompt are the name of other UNIX programs (such as ls or more), shells recognize some special commands (called internal commands) which are not program names. For example, the exit command terminates the shell, and the cd command changes the current working directory. Shells directly make system calls to execute these commands, instead of forking a child process to handle them.
```
