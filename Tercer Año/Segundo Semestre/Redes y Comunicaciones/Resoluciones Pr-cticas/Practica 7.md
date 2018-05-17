# Práctica 7 - Capa de red - Direccionamiento

## Introducción

### 1. ¿Qué servicios presta la capa de red? ¿Cuál es la PDU en esta capa? ¿Qué dispositivo es considerado sólo de la capa de red?

La función de la capa de red es tremendamente simple: transporta paquetes desde un host emisor a un host receptor. En la realización de esta tarea podemos identificar dos importantes funciones de la capa de red:

-   Reenvío (forwarding). Cuando un paquete llega al enlace de entrada de un router, éste tiene que pasar el paquete al enlace de salida apropiado.

-   Enrutamiento (routing). La capa de red tiene que determinar la ruta o camino que deben seguir los paquetes a medida que fluyen de un emisor a un receptor. Los algoritmos que calculan estas rutas se conocen como algoritmos de enrutamiento.

Todo router tiene una tabla de reenvio. Un router reenvia un paquete examinando el valor de un campo de la cabecera del paquete entrante y utilizando después ese valor para indexarlo dentro de la tabla de reenvio del router. El resultado de la tabla de reenvío indica a cuál de las interfaces del enlace de salida del router será reenviado el paquete.  El algoritmo de enrutamiento determina los valores que se introducen en las tablas de reenvío de los routers. Este algoritmo puede estar centralizado o descentralizado (en cada router).

La capa de red de Internet proporciona un único servicio conocido como servicio de mejor esfuerzo (best-effort service). Al decir servicio de mejor esfuerzo estamos utilizando un eufemismo por no decir que no proporciona ningún servicio en absoluto. Con un servicio de mejor esfuerzo, la temporización relativa entre paquetes no está garantizada, tampoco está garantizado que los paquetes se reciban en el orden que fueron emitidos y tampoco se garantiza la entrega de los paquetes transmitidos. Por tanto, teniendo en cuenta esta definición, una red que no entregara los paquetes al destino satisfaría la definición de servicio de entrega de mejor esfuerzo.

Al PDU asociado a esta capa se lo conoce como `datagrama` o `paquete`.

El dispositivo que solo es considerado de la capa de red es el router (que en realidad es un conmutador de paquetes, como el switch, pero este último se basa en la cabecera de la capa de enlace ya que pertenece a esta). El router no implementa las capas superiores a la capa de red.

* * *

### 2. ¿Cuántas redes clase A, B y C hay? ¿Cuántos hosts como máximo pueden tener cada una?

#### Redes clase A

-   Cantidad de redes: `126`
-   Cantidad de hosts: `16777214`

#### Redes clase B

-   Cantidad de redes: `16384`
-   Cantidad de hosts: `65534`

#### Redes clase C

-   Cantidad de redes: `2097152`
-   Cantidad de hosts: `254`

* * *

### 3. ¿Qué son las subredes? ¿Por qué es importante siempre especificar la máscara de subred asociada?

En redes de computadoras, una subred es un rango de direcciones lógicas. Cuando una red de computadoras se vuelve muy grande, conviene dividirla en subredes, por los siguientes motivos:

-   Reducir el tamaño de los dominios de broadcast.
-   Hacer la red más manejable, administrativamente. Entre otros, se puede controlar el tráfico entre diferentes subredes mediante ACLs.

Existen diversas técnicas para conectar diferentes subredes entre sí. Se pueden conectar:

-   a nivel físico _(capa 1 OSI)_ mediante repetidores o concentradores (hubs),
-   a nivel de enlace _(capa 2 OSI)_ mediante puentes o conmutadores (switches),
-   a nivel de red _(capa 3 OSI)_ mediante routers,
-   a nivel de transporte _(capa 4 OSI)_,
-   aplicación _(capa 7 OSI)_ mediante pasarelas.

También se pueden emplear técnicas de encapsulación _(tunneling)_.

En el caso más simple, se puede dividir una red en subredes de tamaño fijo (todas las subredes tienen el mismo tamaño). Sin embargo, por la escasez de direcciones IP, hoy en día frecuentemente se usan subredes de tamaño variable.

**Máscara de una subred**

La máscara de subred o subneting señala qué bytes (o qué porción) de su dirección es el identificador de la red. La máscara consiste en una secuencia de unos seguidos de una secuencia de ceros con el mismo tamaño que una dirección IP (32 bits, o lo que es lo mismo 4 bytes), por ejemplo, una máscara de 20 bits se escribiría 255.255.240.0, es decir como una dirección IP con 20 bits en 1 seguidos por 12 bits en 0, pero para facilitar su lectura se escribe separando bloques de 8 bits (1 byte) con puntos y escribiéndolos en decimal. La máscara determina todos los parámetros de una subred: dirección de red, dirección de difusión (broadcast) y direcciones asignables a nodos de red (hosts).

Los routers constituyen los límites entre las subredes. La comunicación desde y hasta otras subredes es hecha mediante un puerto específico de un router específico, por lo menos momentáneamente.

Una subred típica es una red física hecha con un router, por ejemplo: una Red Ethernet o una "red de área local virtual" (Virtual Local Area Network, VLAN). Sin embargo, las subredes permiten a la red ser dividida lógicamente a pesar del diseño físico de la misma, por cuanto es posible dividir una red física en varias subredes configurando diferentes computadores host que utilicen diferentes routers. La dirección de todos los nodos en una subred comienzan con la misma secuencia binaria, que es su ID de red e ID de subred. En IPv4, las subredes deben ser identificadas por la base de la dirección y una máscara de subred.

Las subredes simplifican el enrutamiento, ya que cada subred típicamente es representada como una fila en las tablas de ruteo en cada router conectado. Las subredes fueron utilizadas antes de la introducción de las direcciones IPv4, para permitir a una red grande tener un número importante de redes más pequeñas dentro, controladas por varios routers. Las subredes permiten el enrutamiento entre dominios sin clases (CIDR). Para que las computadoras puedan comunicarse con una red, es necesario contar con números IP propios, pero si tenemos dos o más redes, es fácil dividir una dirección IP entre todos los hosts de la red. De esta forma se pueden partir redes grandes en redes más pequeñas.

Es necesario para el funcionamiento de una subred calcular los bits de una IP y quitarle los bits de host, y agregárselos a los bits de network mediante el uso de una operación lógica.

El concepto de máscara indica en una dirección IP qué bits son de red y qué bits son de host. Con el uso de redes con clases, la máscara estaba implícita en la dirección de clase, pues se conocía a priori los bits para red y los bits para host. Cuando se creó el concepto de subredes también se les asoció una máscara de subred, que resultó de utilizar algunos bits de hosts para crear subredes y de esta manera obtener varias subredes con menos hosts cada una. La subred se obtiene aplicando un “AND” lógico entra la IP y la máscara de subred.

* * *

### 4. Describa qué es y para qué sirve el protocolo ICMP.

Los hosts y los routers utilizan ICMP, especificado en [RFC 792], para intercambiarse información acerca de la capa de red. El uso más típico de ICMP es la generación de informes de error. Por ejemplo, al ejecutar una sesión Telnet, FTP o HTTP, puede encontrarse con un mensaje de error como “Red de destino inalcanzable”. Este mensaje tiene su origen en ICMP. En algún momento, un router IP no ha podido encontrar una ruta hasta el host especificado en su aplicación Telnet, FTP o HTTP, y dicho router ha creado y enviado un mensaje ICMP de tipo 3 a su host para informarle del error.

ICMP a menudo se considera parte de IP pero, en sentido arquitectónico, se encuentra justo encima de IP, ya que los mensajes ICMP son transportados dentro de los datagramas IP. Es decir, los mensajes ICMP son transportados como carga útil de IP, al igual que los segmentos TCP o UDP son transportados como carga útil de IP. De forma similar, cuando un host recibe un datagrama IP con ICMP especificado como el protocolo de la capa superior, demultiplexa el contenido del datagrama para ICMP, al igual que demultiplexaría el contenido de un datagrama para TCP o UDP.

Los mensajes ICMP tienen un campo de tipo y un campo de código, y contienen la cabecera y los 8 primeros bytes del datagrama IP que ha dado lugar a la generación del mensaje ICMP en primer lugar (de modo que el emisor puede determinar qué datagrama ha producido el error).

#### a. Analice cómo funciona el comando ping.

El programa ping envía un mensaje ICMP de tipo 8 y código 0 al host especificado. El host de destino, al ver la solicitud de eco, devuelve una respuesta de eco ICMP de tipo 0 y código 0. La mayoría de las implementaciones de TCP/IP soportan el servidor ping directamente en el sistema operativo; es decir, el servidor no es un proceso. El programa cliente necesita poder instruir al sistema operativo para generar un mensaje ICMP de tipo 8 y código 0.

#### b. Analice cómo funciona el comando traceroute (tracert en Windows) y cómo manipula el campo TTL de los paquetes IP.

El comando Traceroute nos permite trazar una ruta desde un host a cualquier otro host del mundo. Cada vez más frecuentemente, Traceroute se implementa con mensajes ICMP. Para determinar los nombres y las direcciones de los routers existentes entre el origen y el destino, Traceroute en el origen envía una serie de datagramas IP ordinarios al destino. Cada uno de estos datagramas transporta un segmento UDP con un número de puerto UDP poco probable. El primero de estos datagramas tiene un TTL de 1, el segundo de 2, el tercero de 3, y así sucesivamente. El origen también inicia los temporizadores para cada uno de los datagramas. Cuando el datagrama n-ésimo llega al router n-ésimo, éste observa que el TTL del datagrama acaba de caducar.  De acuerdo con las reglas del protocolo IP, el router descarta el datagrama y envía al origen un mensaje de advertencia ICMP (tipo 11, código 0). Este mensaje de advertencia incluye el nombre del router y su dirección IP. Cuando este mensaje ICMP llega de vuelta al origen, éste obtiene el tiempo de ida y vuelta del temporizador, y el nombre y la dirección IP del router n-ésimo del propio mensaje ICMP.

El origen incrementa el valor del campo TTL cada vez que envía un datagrama. Por tanto, uno de los datagramas terminará recorriendo el camino completo hasta el host de destino.  Dado que ese datagrama contiene un segmento UDP con un número de puerto improbable, el host de destino devuelve al origen un mensaje ICMP de puerto inalcanzable (tipo 3, código 3). Cuando el host de origen recibe este mensaje ICMP, sabe que no tiene que enviar más paquetes de prueba. (Realmente, el programa estándar Traceroute envía conjuntos de tres paquetes con el mismo TTL y, por tanto, la salida de Traceroute proporciona tres resultados para cada TTL.).

De esta forma, el host de origen obtiene el número y la identidad de los routers que existen entre él y el host de destino, así como el tiempo de ida y vuelta entre los dos hosts.  Observe que el programa cliente Traceroute tiene que poder instruir al sistema operativo para generar los datagramas UDP con valores TTL específicos y el sistema operativo también tiene que ser capaz de notificarle la llegada de mensajes ICMP.

#### c. Indique la cantidad de saltos realizados desde su computadora hasta el sitio info.unlp.edu.ar. En algunos de los saltos ¿muestra el nombre del dominio asociado al salto y su ip? Detalle los encontrados.

\-- inc --

#### d. Verifique el recorrido a dos de los servidores de mail de gmail.com y compare los saltos realizados.  ¿Realizaron la misma cantidad de saltos, hicieron el mismo camino?

\-- inc --

* * *

### 5. ¿Para que se usa el bloque 127.0.0.0/8? ¿Qué PC responde a los siguientes comandos?

El dispositivo de red loopback es una interfaz de red virtual. Las direcciones del rango '127.0.0.0/8' son direcciones de loopback, de las cuales se utiliza, de forma mayoritaria, la '127.0.0.1' por ser la primera de dicho rango, añadiendo '::1' para el caso de IPv6 ('127.0.0.1::1'). Las direcciones de loopback pueden ser redefinidas en los dispositivos, incluso con direcciones IP públicas, una práctica común en los routers. y son usualmente utilizadas para probar la capacidad de la tarjeta interna si se están enviando datos BGP.

Esta dirección se suele utilizar cuando una transmisión de datos tiene como destino el propio host. También se suele usar en tareas de diagnóstico de conectividad y validez del protocolo de comunicación.

La dirección de loopback es una dirección especial que los hosts utilizan para dirigir el tráfico hacia ellos mismos. La dirección de loopback crea un método de acceso directo para las aplicaciones y servicios TCP/IP que se ejecutan en el mismo dispositivo para comunicarse entre sí. Al utilizar la dirección de loopback, en lugar de la dirección host IPv4 asignada, dos servicios en el mismo host pueden desviar las capas inferiores del stack de TCP/IP. También es posible hacer ping a la dirección de loopback para probar la configuración de TCP/IP en el host local.

A pesar de que sólo se usa la dirección única '127.0.0.1', se reservan las direcciones desde la '127.0.0.0' hasta la '127.255.255.255'. Cualquier dirección dentro de este bloque producirá un loopback dentro del host local. Las direcciones dentro de este bloque no deben figurar en ninguna red.

#### a. ping 127.0.0.1

`Host local`

#### b. ping 127.0.54.43

`Host local`

* * *

### 6. Investigue para qué sirven los comandos ifconfig y route. ¿Qué comandos podría utilizar en su reemplazo? Inicie una topología con CORE, cree una máquina y utilice en ella los comandos anteriores para practicar sus diferentes opciones, mínimamente:

-   **Configurar y quitar una dirección IP en una interfaz.**
-   **Ver la tabla de ruteo de la máquina.**

-   **ifconfig**: Es un programa disponible en varias versiones del sistema operativo UNIX, que permite configurar o desplegar numerosos parámetros de las interfaces de red residentes en el núcleo, como la dirección IP (dinámica o estática), o la máscara de red. Si se llama sin argumentos suele mostrar la configuración vigente de las interfaces de red activas, con detalles como la dirección MAC o el tráfico que ha circulado por las mismas hasta el momento. Las interfaces de red en Linux se suelen denominar eth (eth0, eth1, etc.).

-   **route**: El comando route muestra la tabla de enrutamiento que reside en el kernel y también se usa para modificarla. La tabla que especifica cómo se enrutan los paquetes a un host se llama tabla de enrutamiento.

Actualmente los dos comandos mencionados anteriormente están obsoletos, en su reemplazo se utiliza el comando `ip`.

-   Agregar dirección ip a una interfaz: `ip addr add <ipdir> dev <interface>`.

-   Eliminar dirección ip de una interfaz: `ip addr del <ipdir> dev <interface>`.

-   Ver tabla de ruteo: `ip route`

* * *

### 7. Para cada una de las siguientes direcciones IP (172.16.58.223/26, 163.10.5.49/27, 128.10.1.0/23, 10.1.0.0/24, 8.40.11.179/12) determine:

-   a. ¿De qué clase de red es la dirección dada (Clase A, B o C)?
-   b. ¿Cuál es la dirección de subred?

La dirección de la subred se obtiene aplicando un "AND" lógico entra la IP y la máscara de subred.

-   c. ¿Cuál es la cantidad máxima de hosts que pueden estar en esa subred?

Cantidad de hosts utilizando bh bits para hosts => 2^(bh) − 2.

-   d. ¿Cuál es la dirección de broadcast de esa subred?

-   e. ¿Cuál es el rango de direcciones IP válidas dentro de la subred?

-   **172.16.58.223/26**

    -   clase B
    -   Direccion de la subred

    01010110 00001000 00111010 11011111 AND 11111111 11111111 11111111 11000000

    01010110 00001000 00111010 11000000

    -   Cantidad de hosts: 2^6 - 2 = 62
