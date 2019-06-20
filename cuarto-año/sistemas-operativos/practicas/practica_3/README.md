# Practica 3

> Conceptos Generales

## 1. ¿Qué es una System Call?, ¿para que se utiliza?

Las **System Call** son llamados al kernel que se utilizan para ejecutar una función en específico permitiendo así el control de un dispositivo o instrucción provilegiada. Tiene como objetivo proveer una interfaz común logrando portabilidad donde la funcionalidad se ejecuta en modo Kernel en el contexto del proceso.

Comúnmente utilizan una instrucción especial de la CPU que causa que el procesador transfiera el control a un código privilegiado (generalmente el _kernel_), previamente especificado. Esto permite al código privilegiado especificar donde va a ser conectado así como el estado del procesador.

Cuando una system call es invocada, la ejecución del programa que invoca es interrumpida y sus datos son guardados, normalmente en su PCB (_Bloque de Control de Proceso_ del inglés _**Process Control Block**_), para poder continuar ejecutándose luego. El procesador entonces comienza a ejecutar las instrucciones de código de bajo nivel de privilegio, para realizar la tarea requerida. Cuando esta finaliza, se retorna al proceso original, y continúa su ejecución. El retorno al proceso demandante no obligatoriamente es inmediato, depende del tiempo de ejecución de la system call y del algoritmo de planificación de CPU.

## 2. ¿Para qué sirve la macro syscall?. Describa el propósito de cada uno de sus parámetros.

> man syscall

```
[...]

SYNOPSIS

    #define _GNU_SOURCE         /* See feature_test_macros(7) */
    #include <unistd.h>
    #include <sys/syscall.h>   /* For SYS_xxx definitions */

    long syscall(long number, ...);

[...]
```

Es una función que permite invocar una system call efectiva cuya interfaz de código assembler tiene el número especificado `number` con los argumentos especificados `...`. Se utiliza comunmente cuando se desea invocar una llamada al sistema la cual no tiene un binding directo a alguna funcionalidad de C existente.

syscall() guarda los registros de la CPU antes de realizar la llamada al sistema, restaura los registros al regresar de la llamada al sistema y almacena cualquier código de error devuelto por la llamada al sistema en `errno` si ocurre un error.

Las constantes simbólicas para los números de llamadas al sistema se pueden encontrar en el archivo de encabezado `<sys/syscall.h>`.

syscall esta declarada en `unistd.h`.

```c
long syscall(long number, ...);
```

## 3. ¿Para que sirven los siguientes archivos?

### <kernel_code>/arch/x86/syscalls/syscall_32.tbla

```
# 32-bit system call numbers and entry vectors
#
# The format is:
# <number> <abi> <name> <entry point> <compat entry point>
```

### <kernel_code>/arch/x86/syscalls/syscall_64.tbl

```
# 64-bit system call numbers and entry vectors
#
# The format is:
# <number> <abi> <name> <entry point>
```

Son los archivos en los cuales se declaran las system calls accesibles para 32 y 64 bist respectivamente. Si deseamos agregar una syscall nueva debemos agregar una nueva entreada al archivo. En el archivo `syscall_64.tbl` se debe tener particular cuidado al momento de agregar una nueva entreada dado que existen algunas con `<abi> = x32`. Se deberá buscar el final de las entradas con `<abi>=common` y agregar la nueva ahí con ese formato.

### 4. ¿Para qué sirve la macro asmlinkage?

```c
asmlinkage long sys_custom_syscall(void);
```

Es una macro que permite indicarle al compilador, en principio _gcc_, que la función que la función no debe esperar encontrar ninguno de sus argumentos en los registros sino solo en el stack de la CPU. Se realiza como idea de optimización. La `syscall` toma su primer argumento (número de system call) y permite hasta 4 argumentos más que se pasan al llamado del sistema real. Para lograr esto, se dejan todos los argumentos que se pasaron en la pila del CPU.

Todas las llamadas al sistema están marcadas con la etiqueta `asmlinkage`, por lo que todas buscan en la pila en busca de argumentos. Por supuesto, en el caso de `sys_ni_syscall`, esto no hace ninguna diferencia, porque _sys_ni_syscall_ no acepta ningún argumento, pero es un problema para la mayoría de las otras system call.

### 5. ¿Para qué sirve la herramienta strace?, ¿Cómo se usa?

`strace` es una herramienta que permite corraborar errores del sistema operativo GNU/Linux. Permite monitorear las system calls utilizadas por un determinado programa y las señales que este recibe. Su funcionamiento es posible por una característica del kernel de Linux llamada _ptrace_.

> Monitoreando System Calls - Modulos y Drivers

### 1. ¿Cómo se denomina en Gnu/Linux a la porción de código que se agrega al kernel en tiempo de ejecución? ¿Es necesario reiniciar el sistema al cargarlo?. Si no se pudiera utilizar esto. ¿Cómo deberíamos hacer para proveer la misma funcionalidad en Gnu/Linux?

Estas porciones de código son los denominados _kernel modules_ los cuales son compilados sin estar incluidos en el código del kernel evitando que el mismo sea un kernel monolítico, en el cual los módulos formarían parte de su código.

### 2. ¿Qué es un driver? ¿para que se utiliza?

Un driver es un software que conecta el OS directamente con las componentes de hardware de la PC. El driver le da instrucciones al sistema operativo sobre cómo debe funcionar determinado hardware y de que forma el sistema debe trabajar en conjunto para suministrarte los mejores resultados.

### 3. ¿Porque es necesario escribir drivers?

La actualización de hardware y existencia de nuevas necesidades de forma constante son la razón por la cual siempre existe la necesidad de definir nuevos drivers logrando que nuevos productos sean compatibles con OSs existentes y permitiendo que el mismo llegue a más y más usuarios.

### 4. ¿Cuál es la relación entre modulo y driver en Gnu/Linux?

_See [post](https://unix.stackexchange.com/questions/47208/what-is-the-difference-between-kernel-drivers-and-kernel-modules) at Stack Exchange._

A kernel module is a bit of compiled code that can be inserted into the kernel at run-time, such as with insmod or modprobe.

A driver is a bit of code that runs in the kernel to talk to some hardware device. It "drives" the hardware. Most every bit of hardware in your computer has an associated driver. A large part of a running kernel is driver code.

A driver may be built statically into the kernel file on disk. A driver may also be built as a kernel module so that it can be dynamically loaded later. (And then maybe unloaded.)

Standard practice is to build drivers as kernel modules where possible, rather than link them statically to the kernel, since that gives more flexibility. There are good reasons not to, however:

Sometimes a given driver is absolutely necessary to help the system boot up. That doesn't happen as often as you might imagine, due to the initrd feature.

Statically built drivers may be exactly what you want in a system that is statically scoped, such as an embedded system. That is to say, if you know in advance exactly which drivers will always be needed and that this will never change, you have a good reason not to bother with dynamic kernel modules.

If you build your kernel statically and disable Linux's dynamic module loading feature, you prevent run-time modification of the kernel code. This provides additional security and stability at the expense of flexibility.

Not all kernel modules are drivers. For example, a relatively recent feature in the Linux kernel is that you can load a different process scheduler. Another example is that the more complex types of hardware often have multiple generic layers that sit between the low-level hardware driver and userland, such as the USB HID driver, which implements a particular element of the USB stack, independent of the underlying hardware.

### 5. ¿Qué implicancias puede tener un bug en un driver o módulo?

_This design makes it faster to load the Kernel (no need to load and initialize un-needed Modules), as well as developing Drivers (if you have a bug, just unload the Module, fix it, recompile and load it again)._

[kernel-modules-drivers](http://www.haifux.org/lectures/86-sil/kernel-modules-drivers/kernel-modules-drivers.html)

### 7. ¿Qué tipos de drivers existen en Gnu/Linux?

The `/dev` directory is the standard location for all Device files in the system but one can create Device files in other directories (e.g. in RedHat's installation process, the device files for the hard disks are created in the `/tmp` directory).

### 8. ¿Para qué sirven el archivos /lib/modules/\<version\>/modules.dep utilizado por el comando modprobe

**modprobe** - Add and remove modules from the Linux Kernel

`modprobe` looks in the module directory `/lib/modules/$(uname -r)` for all the
modules and other files, except for the optional configuration files in
the `/etc/modprobe.d` directory (_see modprobe.d(5) in man pages_).  modprobe will also
use module options specified on the kernel command line in the form of
`<module>.<option>` and blacklists in the form of `modprobe.blacklist=<module>`.
