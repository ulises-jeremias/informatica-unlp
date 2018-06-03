# Práctica 6

### 1. Utilizando la máquina virtual, use Wireshark para capturar paquetes enviados y recibidos en cada uno de los siguientes casos. Para ello, arranque la captura en la interfaz con IP 172.28.0.1 antes de realizar los incisos A, B, C y D.

#### a. Abra un navegador e ingrese a la URL: www.redes.unlp.edu.ar. Analice la secuencia de segmentos TCP que permiten la apertura del canal de comunicación por el cual posteriormente viajarán los mensajes HTTP intercambiados. ¿Con qué nombre se conoce a dicha secuencia? ¿Qué flags se utilizan en cada uno de los segmentos intercambiados? ¿Qué indica cada uno de estos flags?

Dicha secuencia se conoce con el nombre de `three-way hanshake`.

-   El cliente envía un segmento SYN con el flag SYN = 1 (indica que se quiere iniciar conexión).
-   El servidor responde con el flag SYN = 1 y ACK=1 (indica conexión concedida).
-   El cliente confirma con el flag ACK = 1 (el flag SYN = 0).

#### b. Cierre el navegador. Analice la secuencia de segmentos TCP que ocurren al hacerlo ¿Cuál es el objetivo éstos? ¿Qué flags se utilizan en cada uno de dichos segmentos? ¿Qué indica cada uno de estos flags?

El objetivo de estos flags es el de cerrar la conexión entre el cliente y el servidor.

-   El cliente envía un segmento con los flags FIN = 1 y ACK = 1.
-   El servidor también responde con un segmento similar, FIN= 1 y ACK = 1.
-   El cliente confirma con ACK.

Se utilizan los flags de FIN y ACK:

-   FIN indica que se quiere cerrar la conexión.
-   ACK es el flag de reconocimiento del segmento (en este caso se usa para reconocer el segmento de finalización de conexión).

#### c. Para este ejercicio debe usar tanto el navegador Chromium como Iceweasel. Utilice Chromium para ingresar a la URL: www.redes.unlp.edu.ar y seguidamente utilice Iceweasel para ingresar nuevamente a la URL: www.redes.unlp.edu.ar

**Observe la información de Puerto Origen y Puerto destino de cada una de las comunicaciones.  En base a lo observado, responda ¿Es posible conectarse 2 veces en forma simultánea al mismo lugar? ¿Qué distingue una conexión de otra? Capture el tráfico de red si considera necesario para observar dicha información.**

Es posible conectarse dos veces en forma simultánea al mismo lugar ya que estas dos conexiones TCP se diferenciarán por el puerto origen.

#### e. ¿Qué diferencias encuentra en cuánto a mensajes intercambiados entre los puntos A, B respecto del punto D?

El intercambio de mensajes es distinto ya que en el punto D el protocolo que se utiliza corre sobre UDP, por ende no existen los paquetes relacionados al handshake ni al cierre de conexión.

#### f. ¿Qué diferencias encuentra en el punto D respecto a los anteriores respecto a utilización de puertos y protocolo de transporte utilizado?

TFTP:

-   Utiliza UDP (en el puerto 69) como protocolo de transporte (a diferencia de FTP que utiliza los puertos 20 y 21 TCP).
-   No puede listar el contenido de los directorios.
-   No existen mecanismos de autenticación o cifrado.
-   Se utiliza para leer o escribir archivos de un servidor remoto.
-   Soporta tres modos diferentes de transferencia, "netascii", "octet" y "mail", de los que los dos primeros corresponden a los modos "ascii" e "imagen" (binario) del protocolo FTP.

Ya que TFTP utiliza UDP, no hay una definición formal de sesión, cliente y servidor, aunque se considera servidor a aquel que abre el puerto 69 en modo UDP, y cliente a quien se conecta.

Sin embargo, cada archivo transferido vía TFTP constituye un intercambio independiente de paquetes, y existe una relación cliente-servidor informal entre la máquina que inicia la comunicación y la que responde.

-   La máquina A, que inicia la comunicación, envía un paquete RRQ (read request/petición de lectura) o WRQ (write request/petición de escritura) a la máquina B, conteniendo el nombre del archivo y el modo de transferencia.
-   B responde con un paquete ACK (acknowledgement/confirmación), que también sirve para informar a A del puerto de la máquina B al que tendrá que enviar los paquetes restantes.
-   La máquina origen envía paquetes de datos numerados a la máquina destino, todos excepto el último conteniendo 512 bytes de datos. La máquina destino responde con paquetes ACK numerados para todos los paquetes de datos.
-   El paquete de datos final debe contener menos de 512 bytes de datos para indicar que es el último. Si el tamaño del archivo transferido es un múltiplo exacto de 512 bytes, el origen envía un paquete final que contiene 0 bytes de datos.

* * *

### 2. Investigue los distintos tipos de estado que puede tener una conexión TCP.

Estados TCP:

-   CLOSED : No hay conexión activa ni pendiente.

-   LISTEN: El servidor espera una llamada.

-   SYN RCVD: Llegó una solicitud de conexión; espera ACK.

-   SYN SENT: La aplicación comenzó a abrir una conexión.

-   ESTABLISHED: Estado normal de transferencia de datos.

-   FIN WAIT 1: La aplicación dijo que ya terminó.

-   FIN WAIT 2: El otro lado acordó liberar.

-   TIMED WAIT: Espera a que todos los paquetes mueran.

-   CLOSING: Ambos lados intentaron cerrar simultáneamente.

-   CLOSE WAIT: El otro lado inició una liberación.

-   LAST ACK: Espera a que todos los paquetes mueran.

Más info: <http://tcpipguide.com/free/t_TCPOperationalOverviewandtheTCPFiniteStateMachineF-2.htm>

* * *

### 3. Dada la siguiente salida del comando ss, responda:
