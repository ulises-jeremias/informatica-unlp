# Práctica 5

### 1. ¿Cuál es la función de la capa de transporte?

Un **protocolo de la capa de transporte proporciona una comunicación lógica entre procesos de aplicación que se ejecutan en hosts diferentes**. Por comunicación lógica queremos decir que, desde la perspectiva de la aplicación, es como si los hosts que ejecutan los procesos estuvieran conectados directamente.

Internet tiene dos protocolos: TCP y UDP. Cada uno de estos protocolos proporciona un conjunto diferente de servicios para la capa de transporte a la aplicación que lo haya invocado.

La responsabilidad principal de UDP y TCP es ampliar el servicio de entrega de IP entre dos sistemas terminales a un servicio de entrega entre dos procesos que estén ejecutándose en los sistemas terminales. Extender la entrega host a host a una entrega proceso a proceso es lo que se denomina multiplexación y demultiplexación de la capa de transporte. UDP y TCP también proporcionan servicios de comprobación de la integridad de los datos al incluir campos de detección de errores en las cabeceras de sus segmentos. Estos dos servicios de la capa de transporte (entrega de datos proceso a proceso y comprobación de errores) son los dos únicos servicios que ofrece UDP. En particular, al igual que IP, UDP es un servicio no fiable, que no garantiza que los datos enviados por un proceso lleguen intactos al proceso de destino.

TCP, por el contrario, ofrece a las aplicaciones varios servicios adicionales. El primero y más importante es que proporciona una transferencia de datos fiable. Utilizando técnicas de control de flujo, números de secuencia, mensajes de reconocimiento y temporizadores. TCP garantiza que los datos transmitidos por el proceso emisor sean entregados al proceso receptor, correctamente y en orden. De este modo, TCP convierte el servicio no fiable de IP entre sistemas terminales en un servicio de transporte de datos fiable entre procesos. TCP también proporciona mecanismos de control de congestión.

* * *

### 2. Describa la estructura del segmento TCP y UDP.

En el lado emisor, la capa de transporte convierte los mensajes que recibe, procedentes de un proceso de aplicación emisor, en paquetes de la capa de transporte, conocidos como segmentos de la capa de transporte. Muy posiblemente, esto se hace dividiendo los mensajes de la aplicación en fragmentos más pequeños y añadiendo una cabecera de la capa de transporte a cada fragmento, con el fin de crear el segmento de la capa de transporte.

**UDP**

La cabecera UDP consta de 4 campos de los cuales 2 son opcionales. Los campos de los puertos origen y destino son campos de 16 bits que identifican el proceso de emisión y recepción. Ya que UDP carece de un servidor de estado y el origen UDP no solicita respuestas, el puerto origen es opcional. En caso de no ser utilizado, el puerto origen debe ser puesto a cero. A los campos del puerto destino le sigue un campo obligatorio que indica el tamaño en bytes del datagrama UDP incluidos los datos. El valor mínimo es de 8 bytes. El campo de la cabecera restante es una suma de comprobación de 16 bits que abarca una pseudo-cabecera IP (con las IP origen y destino, el protocolo y la longitud del paquete UDP), la cabecera UDP, los datos y 0's hasta completar un múltiplo de 16. El checksum también es opcional en IPv4, aunque generalmente se utiliza en la práctica (en IPv6 su uso es obligatorio).

**TCP**

El segmento TCP consta de campos de cabecera y un campo de datos. El campo de datos contiene un fragmento de los datos de la aplicación. El MSS limita el tamaño máximo del campo de datos de un segmento.  Cuando TCP envía un archivo grande, normalmente divide el archivo en fragmentos de tamaño MSS.

TCP. Al igual que con UDP, la cabecera incluye los número de puerto de origen y de destino, que se utilizan para multiplexar y demultiplexar los datos de y para las aplicaciones de la capa superior. También, al igual que UDP, la cabecera incluye un campo de suma de comprobación. La cabecera de un segmento TCP también contiene los siguientes campos:

-   El campo número de secuencia de 32 bits y el campo número de reconocimiento también de 32 bits son utilizados por el emisor y el receptor de TCP para implementar un servicio de transferencia de datos fiable.

-   El campo ventana de recepción de 16 bits se utiliza para el control de flujo. Se emplea para indicar el número de bytes que un receptor está dispuesto a aceptar.

-   El campo longitud de cabecera de 4 bits especifica la longitud de la cabecera TCP en palabras de 32 bits. La cabecera TCP puede tener una longitud variable a causa del campo opciones de TCP (normalmente, este campo está vacío, por lo que la longitud de una cabecera TCP típica es de 20 bytes).

-   El campo opciones es opcional y de longitud variable. Se utiliza cuando un emisor y un receptor negocian el tamaño máximo de segmento (MSS) o como un factor de escala de la ventana en las redes de alta velocidad. También se define una opción de marca temporal.

-   El campo indicador tiene 6 bits. El bit ACK se utiliza para indicar que el valor transportado en el campo de reconocimiento es válido; es decir, el segmento contiene un reconocimiento para un segmento que ha sido recibido correctamente. Los bits RST, SYN y FIN se utilizan para el establecimiento y cierre de conexiones. La activación del bit PSH indica que el receptor deberá pasar los datos a la capa superior de forma inmediata. Por último, el bit URG se utiliza para indicar que hay datos en este segmento que la entidad de la capa superior del lado emisor ha marcado como “urgentes”. La posición de este último byte de estos datos urgentes se indica mediante el campo puntero de datos urgentes de 16 bits. TCP tiene que informar a la entidad de la capa superior del lado receptor si existen datos urgentes y pasarle un puntero a la posición donde finalizan los datos urgentes. En la práctica, PSH, URG y el puntero a datos urgentes no se utilizan.

* * *

### 3. ¿Cuál es el objetivo del uso de puertos en el modelo TCP/IP?

En primer lugar, recordemos que un proceso puede tener uno o más sockets, puertas por las que pasan los datos de la red al proceso, y viceversa. Por tanto, la capa de transporte del host receptor realmente no entrega los datos directamente a un proceso, sino a un socket intermedio, que a su vez tiene un identificador único (ya que puede haber más de uno por host).

Cada segmento de la capa de transporte contiene un conjunto de campos destinados para identificar el socket apropiado (entre otros). En el extremo receptor, la capa de transporte examina estos campos para identificar el socket receptor y, a continuación, envía el segmento a dicho socket. Esta tarea de entregar los datos contenidos en un segmento de la capa de transporte al socket correcto es lo que se demultiplexación. La tarea de reunir los fragmentos de datos en el host de origen desde los diferentes sockets, encapsulando cada fragmento de datos con la información de cabecera (el cual se utilizará después en el proceso de demultiplexación) para crear los segmentos y pasarlos a la capa de red es lo que se denomina multiplexación. Es importante darse cuenta de que estas técnicas son necesarias siempre que un único protocolo en una capa (cualquiera) sea utilizado por varios protocolos de la capa inmediatamente superior.

Sabemos que la operación de multiplexación que se lleva a cabo en la capa de transporte requiere (1) que los sockets tengan identificadores únicos y (2) que cada segmento tenga campos especiales que indiquen el socket al que tiene que entregarse el segmento. Estos campos especiales, son el campo número de puerto origen y número de puerto destino.  

Cada número de puerto es un número de 16 bits comprendido en el rango de 0 a 65535. Los números de puerto pertenecientes al rango de 0 a 1023 se conocen como números de puertos bien conocidos y son restringidos, lo que significa que están reservados para ser empleados por los protocolos de aplicación bien conocidos (ej. HTTP que utiliza el puerto 80 y FTP que utiliza el puerto 21).

* * *

### 4. Compare TCP y UDP en cuanto a:

#### a. Confiabilidad.

El protocolo IP proporciona una comunicación lógica entre hosts. El modelo de servicio de IP es un servicio de entrega de mejor esfuerzo (best effort). Esto quiere decir que IP hace todo lo que puede por entregar los segmentos entre los hosts que se están comunicando, pero no garantiza la entrega. En particular, no garantiza la entrega de segmentos, ni que los segmentos se entreguen en orden y tampoco la integridad de los contenidos en los segmentos. Por lo tanto, IP es un servicio NO FIABLE.

#### UDP

-   Al igual que IP es un servicio no fiable.
-   No garantiza que los segmentos lleguen al proceso destino.
-   Tampoco garantiza que lleguen en orden y estén libres de errores.
-   La comprobación de errores es responsabilidad de la aplicación.

#### TCP

-   Proporciona una transferencia de datos fiable. Utilizando técnicas de control de flujo, números de secuencia, mensajes de reconocimiento y temporizadores.
-   Garantiza que los datos transmitidos por el proceso emisor sean entregados al proceso receptor, correctamente y en orden. Continuará reenviando un segmento hasta que la recepción del mismo haya sido confirmada por el destino.

#### b. Multiplexación.

#### UDP

-   Utiliza multiplexación y demultiplexación SIN conexión.
-   Creamos sockets indicando el número de puerto.
-   El segmento (de UDP + IP) identifica el socket destino mediante dos campos de cabecera: Dirección IP Destino y Nro. Puerto Destino.
-   Ademas el segmento tiene una “dirección de retorno”. Por si el receptor desea devolver un segmento al emisor.
-   Si dos segmentos UDP con diferentes sockets de origen (Direccion IP y/o Nro. Puerto) poseen la misma dirección IP destino y el mismo nro. de puerto de destino, entonces los dos segmentos se enviarán al mismo proceso de destino a través del mismo socket de destino.
-   Cabeceras de 8 bytes. Más pequeñas.

#### TCP

-   Utiliza multiplexación y demultiplexación orientada a la conexión.
-   El socket, en TCP se identifica por una tupla de cuatro elementos: Dirección IP Origen, Nro. Puerto Origen, Dirección IP Destino, Nro. Puerto Destino.
-   Dos segmentos TCP entrantes con direcciones IP de origen o números de puerto de origen diferentes (con la excepción de un segmento TCP que transporte la solicitud original de establecimiento de conexión) serán dirigidos a dos sockets distintos.
-   Cuando un proceso cliente se quiere comunicar con un servidor por un socket TCP. Este debe enviar una solicitud en un puerto de destino (ej. 6789) y un conjunto especial de bits de establecimiento de conexión en la cabecera TCP. Cuando el SO del host que está ejecutando el proceso servidor recibe el segmento de entrada de solicitud de conexión con el puerto de destino (6789), localiza el proceso de servidor que está esperando para aceptar una conexión en el número de puerto 6789. El proceso de servidor entonces crea un nuevo puerto. Además, la capa de transporte toma nota de los cuatro valores contenidos en el segmento de solicitud de conexión (IPO, PO, IPD/su propia IP, PD). El socket de conexión recién creado queda identificado por estos cuatro valores, así, todos los segmentos que lleguen después con esta tupla de valores serán enviados a este socket.  Una vez establecida la conexión TCP, el cliente y el servidor podrán enviarse datos entre sí.
-   Cabecera de 20 bytes (es variable). Más del doble que UDP.

#### c. Orientado a la conexión.

#### UDP

-   Es un protocolo sin conexión. No tiene lugar una fase de establecimiento de la conexión entre las entidades de la capa de transporte emisora y receptora previa al envío del segmento.
-   Inicia la transmisión sin formalidades preliminares. Por tanto, UDP no añade ningún retarde a causa del establecimiento de una conexión.
-   No mantiene información del estado de la conexión.
-   Suele soportar más clientes activos cuando la aplicación se ejecuta sobre UDP.

#### TCP

-   Lleva a cabo un proceso de establecimiento de la conexión en tres fases antes de iniciar la transferencia de datos.
-   Mantiene información acerca del estado de la conexión en los sistemas terminales.
-   El estado de la conexión reside completamente en los sistemas terminales y no en los elementos intermedios de la red (routers y switches de la capa de enlace).
-   La conexión proporciona un servicio full-dupex: si existe una conexión entre el proceso A que se ejecuta en un host y el proceso B que se ejecuta en otro host, entonces los datos de la capa de aplicación pueden fluir desde el proceso A al proceso B en el mismo instante que los datos de la capa de aplicación fluyen del proceso B al proceso A.
-   Conexión (casi siempre) punto a punto, es decir, entre un único emisor y un único receptor. La “multidifusión” (multicasting sección 4.7), la transferencia de datos desde un emisor a muchos receptores en una única operación, no es posible con TCP.
-   Handshaking (intercambio de mensajes de control). Inicializa ambos procesos antes del intercambio de datos.
-   Cada lado de la conexión tiene su propio buffer de emisión y su propio buffer de recepción.
-   Consta de buffers, variables y un socket de conexión a un proceso en un host, y otro conjunto de buffers, variables y un socket de conexión a un proceso en otro host.

#### d. Controles de congestión.

#### UDP

-   No implementa control de congestión.

#### TCP

-   Dispone de un mecanismo de control de congestión que regula el flujo del emisor TCP de la capa de transporte cuando uno o más de los enlaces existentes entre los hosts de origen y de destino están excesivamente congestionados.
-   Proporciona un servicio de control de flujo a sus aplicaciones para eliminar la posibilidad de que el emisor desborde el buffer del receptor. Por lo tanto, un servicio de adaptación de velocidades (adapta la velocidad a la que el emisor está transmitiendo frente a la velocidad a la que la aplicación receptora está leyendo).
-   El emisor dispone (y determina el tamaño) de una ventana de recepción. Se emplea para proporcionar al emisor una idea de cuánto espacio libre hay disponible en el buffer del receptor. Debido a que la conexión es full dúplex, cada proceso dispone de una ventana de recepción diferente.

#### e. Utilización de puertos.

Los sockets pueden verse como las puertas de los procesos.

#### UDP

-   El socket está definido por el número de puerto destino y la dirección IP del destino.
-   Muchos clientes pueden enviar datos por un mismo socket.

#### TCP

-   El socket está definido para cada extremo de la conexión. Es decir, por los cuatro campos (IPOrigen, PuertoOrigen, IPDestino, PuertoDestino). Esto quiere decir que por cada socket pueden intercambiar datos únicamente dos procesos (conexión punto a punto).

#### f. ¿Cuál es el campo del datagrama IP y los valores que se utilizan en este para diferenciar que se transporta TCP o UDP?

El campo de cabecera de IP es el campo `protocolo` de 8 bits.

`TCP es el 6`.

`UDP es el 17`

* * *

### 5. La PDU de la capa de transporte es el segmento. Sin embargo, en algunos contextos suele utilizarse el término datagrama. Indique cuándo.

En el contexto de Internet los paquetes de la capa de transporte se definen como segmentos. No obstante, tenemos que decir que, en textos dedicados a Internet, como por ejemplo los RFC, también se emplea el término segmento para hacer referencia a los paquetes de la capa de transporte en el caso de TCP, pero a menudo a los paquetes de UDP se los denomina datagrama. Pero resulta que estos mismos textos dedicados a Internet también utilizan el término datagrama para referirse a los paquetes de la capa de red.

* * *

### 6. Describa el saludo de tres vías de TCP.

Supongamos que hay un proceso en ejecución en un host (cliente) que desea iniciar una conexión con otro proceso que se ejecuta en otro host (servidor). El proceso de aplicación cliente informa en primer lugar al cliente TCP que desea establecer una conexión con un proceso servidor. A continuación, el protocolo TCP en el cliente establece una conexión TCP con el protocolo TCP en el servidor de la siguiente manera:

-   **Paso 1** En primer lugar, TCP del lado del cliente envía un segmento TCP especial al TCP del lado servidor. Este segmento especial no contiene datos de la capa de aplicación. Pero uno de los bits indicadores de la cabecera del segmento, el bit SYN, se pone a 1. Por esta razón, este segmento especial se referencia como un segmento SYN. Además, el cliente selecciona de forma aleatoria un número de secuencia inicial y lo coloca en el campo número de secuencia del segmento TCP inicial SYN. Este segmento se encapsula dentro de un datagrama IP y se envía al servidor.

-   **Paso 2** Una vez que el datagrama IP que contiene el segmento SYN TCP llega al host servidor, el servidor extrae dicho segmento SYN del datagrama, asigna los buffers y variables TCP a la conexión y envía un segmento de conexión concedida al cliente TCP. Este segmento de conexión concedida tampoco contiene datos de la capa de aplicación. Sin embargo, contiene tres fragmentos de información importantes de la cabecera del segmento. El primero, el bit SYN se pone a 1. El segundo, el campo reconocimiento de la cabecera del segmento TCP se hace igual a cliente_nsi+1. Por último, el servidor elige su propio número de secuencia inicial (servidor_nsi) y almacena este valor en el campo número de secuencia de la cabecera del segmento TCP. Este segmento de conexión concedida está diciendo, en efecto, “He recibido tu paquete SYN para iniciar una conexión con tu número de secuencia inicial, cliente_nsi. Estoy de acuerdo con establecer esta conexión. Mi número de secuencia inicial es servidor_nsi”. El segmento de conexión concedida se conoce como segmento SYNACK.

-   **Paso 3** Al recibir el segmento SYNACK, el cliente también asigna buffers y variables a la conexión. El host cliente envía entonces al servidor otro segmento; este último segmento confirma el segmento de conexión concedida del servidor (el cliente hace esto almacenando el valor servidor_nsi+1 en el campo de reconocimiento de la cabecera del segmento TCP). El bit SYN se pone a cero, ya que la conexión está establecida. Esta tercera etapa del proceso de acuerdo en tres fases puede transportar datos del cliente al servidor dentra de la carga útil del segmento.

Una vez completados estos tres pasos, los hosts cliente y servidor pueden enviarse segmentos que contengan datos el uno al otro. En cada uno de estos segmentos futuros, el valor del bit SYN será cero.

* * *

### 7. Utilice el comando ss (reemplazo de netstat) para obtener la siguiente información de su PC:

#### a. Para listar las comunicaciones TCP establecidas.

`ss -t`

#### b. Para listar las comunicaciones UDP establecidas.

`ss -u`

#### c. Obtener sólo los servicios TCP que están esperando comunicaciones.

`ss -t -l`

#### d. Obtener sólo los servicios UDP que están esperando comunicaciones.

`ss -u -l`

#### e. Repetir los anteriores para visualizar el proceso del sistema asociado a la conexión.

ej: `ss -t -l -p`

#### f. Obtenga la misma información planteada en los items anteriores usando el comando netstat.

  a. `netstat -t -p`

  b. `netstat -u -p`

  c. `netstat -t -l -p`

  d. `netstat -u -l -p`

* * *

### 8. ¿Qué sucede si llega un segmento TCP a un host que no tiene ningún proceso esperando en el puerto destino de dicho segmento (es decir, que dicho puerto no está en estado LISTEN)?

Consideremos lo que ocurre cuando un host recibe un segmento TCP cuyo número de puerto o cuya dirección IP de origen no se corresponde con ninguno de los sockets activos en el host. Por ejemplo, suponiendo que un host recibe un paquete TCP SYN cuyo puerto de destino es el número 80, pero el host no está aceptando conexiones en dicho puerto (es decir, no está ejecutando un servidor web en el puerto 80). Entonces, el host enviará al origen un segmento especial de reinicio. Este segmento TCP tiene el bit indicador RST puesto a 1. Por tanto, cuando un host envía un segmento de reinicio, le está diciendo al emisor “No tengo un socket para ese segmento. Por favor, no reenvies el segmento.” Cuando un host recibe un paquete UDP en el que el número de puerto de destino no se corresponde con un socket UDP activo, el host envía un datagrama ICMP especial.

#### a. Utilice hping3 para enviar paquetes TCP al puerto destino 22 de la máquina virtual con el flag SYN activado.

`hping3 -p 22 -S localhost`

#### b. Utilice hping3 para enviar paquetes TCP al puerto destino 40 de la máquina virtual con el flag SYN activado.

`hping3 -p 40 -S localhost`

#### c. ¿Qué diferencias nota en las respuestas obtenidas en los dos casos anteriores? ¿Puede explicar a qué se debe? (Ayuda: utilice el comando ss visto anteriormente).

La diferencia está en los flags de las respuestas, para el primer comando se recibe `SA` mientras que el segundo `RA`. Esto se debe a que un flag SA quiere decir que corresponde con SYN/ACK, es decir, que la comunicación ha sido aceptada, o lo que es lo mismo, que el puerto está abierto. De lo contrario, si el valor es RA corresponde a RST/ACK o lo que es lo mismo, que la comunicación no se ha realizado correctamente porque el puerto está cerrado o filtrado.

Al utilizar el comando `ss` podemos ver que hay un socket escuchando en el puerto 22, y no el en 44.

* * *

### 9. ¿Qué sucede si llega un datagrama UDP a un host que no tiene a ningún proceso esperando en el puerto destino de dicho datagrama (es decir, que dicho puerto no está en estado LISTEN)?

Cuando un host recibe un paquete UDP en el que el número de puerto de destino no se corresponde con un socket UDP activo, el host envía un datagrama ICMP especial.

#### a. Utilice hping3 para enviar datagramas UDP al puerto destino 68 de la máquina virtual.

`hping3 -2 -p 68 -S localhost`

#### b. Utilice hping3 para enviar datagramas UDP al puerto destino 40 de la máquina virtual.

`hping3 -2 -p 40 -S localhost`

#### c. ¿Qué diferencias nota en las respuestas obtenidas en los dos casos anteriores? ¿Puede explicar a qué se debe? (Ayuda: utilice el comando ss visto anteriormente).

La diferencia es que como hay un socket escuchando en el puerto 68, no se recibe respuesta alguna debido a que UDP no manda segmentos ACK. En cambio como no hay socket escuchando en el puerto 40, se recibe el paquete ICMP.

* * *

### 10. Investigue qué es multicast. ¿Sobre cuál de los protocolos de capa de transporte funciona? ¿Se podría adaptar para que funcione sobre el otro protocolo de capa de transporte? ¿Por qué?

Múlticast es un tipo de comunicación donde la transmición de datos es enviada a un grupo de computadoras destino simultaneamente. Funciona sobre el protocolo UDP, ya que este no es orientado a la conexión (lo que constituye una conexión punto a punto), y no ejecuta los controles de flujo y congestión.

No se podría utilizar bajo el protocolo TCP ya que éste es un protocolo para comunicación entre exactamente dos puntos. Comparado con UDP, TCP realiza un transporte fiable, lo que significa que los paquetes no son solamente enviados sino que se espera además por los paquetes de reconocimiento. Debido a que Multicast solamente envía pero nunca recibe datos, la fiabilidad de TCP no puede ser implementada sobre este protocolo.

* * *

### 11. Use CORE para armar una topología como la siguiente, sobre la cual deberá realizar:

#### d. Iniciar otra conexión desde CLIENTE1 de la misma manera que la anterior y verificar el estado de las conexiones. ¿De qué manera puede identificar cada conexión?

La conexión se identifica con la 4-tupla (source port, dest port, dource ip, dest ip).

#### e. En base a lo observado en el item anterior, ¿es posible iniciar más de una conexión desde el cliente al servidor en el mismo puerto destino? ¿Por qué? ¿Cómo se garantiza que los datos de una conexión no se mezclarán con los de la otra?

Es posible iniciar mas de una conexión desde el cliente al servidor en el mismo puerto destino ya que estas conexiones se diferenciarán por el puerto fuente del cliente. Así de esta manera no se "mezclarán" los datos de una conexión con los de la otra.

#### f. Cerrar la última conexión establecida desde CLIENTE1 y ver los estados de las conexiones en ambos equipos.

La conexión del lado del cliente quedará en `TIME-WAIT` y luego de un tiempo se cerrará, y del lado del servidor se cerrará.

#### g. Cortar el servicio de ncat en el servidor (Ctrl+C) y ver los estados de las conexiones en ambos equipos. Luego, cerrar la conexión en el cliente y verificar nuevamente los estados de las conexiones.

Al cortar el servicio en el servidor, este se quedará esperando en `FIN-WAIT-2`, es decir hasta que el cliente cierre su aplicación, lo cual se representa por el estado `CLOSE-WAIT`. Luego de cerrar la aplicacion del cliente, se terminarán de cerrar ambas conexiones.

* * *

### 12. De acuerdo a la captura de la siguiente figura, indique los valores de los campos borroneados.
