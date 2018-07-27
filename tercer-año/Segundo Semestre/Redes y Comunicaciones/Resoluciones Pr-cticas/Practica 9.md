# Práctica 9 - Capa de Red - IPv6

## IPv6

### 1. ¿Qué es IPv6? ¿Por qué es necesaria su implementación?

A principios de la década de 1990, el Internet Engineering Task Force comenzó a desarrollar un sucesor para el protocolo IPv4. La principal motivación de esta iniciativa fue que se dieron cuenta de que el espacio de direcciones IP de 32 bits estaba comenzando a agotarse, a causa de las nuevas subredes y nodos IP que estaban conectándose a Internet (a los que se les estaban asignando direcciones IP únicas) a una velocidad sobrecogedora. Para responder a esta necesidad de un espacio de direcciones IP más grande, se desarrolló un nuevo protocolo IP, el protocolo IPv6. Los diseñadores de IPv6 también vieron aquí la oportunidad de ajustar y aumentar otros aspectos de IPv4, basándose en la experiencia acumulada sobre el funcionamiento de IPv4.

Este agotamiento de direcciones IPv4 generó un conjunto de mecanismos para poder seguir
agregando subredes a la Internet. Por ejempo, NAT y NAPT, con los cuales se perdía el
principio end-to- end del protocolo IP.

Problemas de IPv4:

-   Direcciones IPv4 no disponibles, uso de NAT.
-   Tablas de ruteo muy grandes en el backbone de Internet.
-   Congestión en los routers, demasiado procesamiento.

Otras cuestiones no contempladas desde el inicio:

-   Seguridad a nivel L3, IP.
-   Extensiones al modelo de Calidad de Servicio (QoS).
-   Fácil auto-configuración y re-numeración de direcciones.
-   Movilidad a nivel de red no contemplada en el diseño del protocolo.

Es importante decir que IPv4 e IPv6 no son versiones del mismo protocolo, sino que son protocolos diferentes.

-   Mayor espacio de direcciones
-   128 bits: 340.282.366.920.938.463.463.374.607.431.768.211.456 direcciones.
-   Formato de cabecera simplificado. Menor overhead de procesamiento.
-   Ordenar las tablas de enrutamiento.
-   Conectar todo, usar auto-configuración de direcciones (plug and play).
-   Arquitectura de red jerárquica para un ruteo eficiente.
-   Seguridad a nivel IP (IPSec obligatorio).
-   Jumbogramas, size(datagrama) > 64KB.
-   Movilidad y más direcciones de multicast.

* * *

### 2. ¿Por qué no es necesario el campo Header Length en IPv6?

Porque IPv6 tiene una cabecera de 40 bytes simplificada. Algunos de los campos de IPv4 se han eliminado o se han hecho opcionales. La cabecera de longitud fija de 40 bytes permite un procesamiento más rápido del datagrama IP. Una nueva codificación de las opciones permite un procesamiento más flexible de las mismas. Es decir, la eliminación del campo opciones que fue reemplazado por cabeceras adicionales y opcionales, permitió tener una cabecera de IPv6 de tamaño fijo.

* * *

### 3. ¿En qué se diferencia el checksum de IPv4 e IPv6? Y en cuánto a los campos checksum de TCP y UDP, ¿sufren alguna modificación?

En IPv6 se eliminó. Y se delegó a la capa de transporte. En UDP, con esta modificación, la funcionalidad de comprobación de errores será obligatoria.
Suma de comprobación (checksum) de cabecera. Puesto que los protocolos de transporte (Ej. TCP y UDP) y de la capa de enlace de datos (ej. Ethernet) en las capas de Internet realizan sumas de comprobación, los diseñadores de IP probablemente pensaron que esta funcionalidad ya era suficientemente redundante en la capa de red y podía eliminarse. Una vez más, el procesamiento rápido de los paquetes IP era la preocupación principal. En IPv4 dado que la cabecera tiene un campo TTL (similar al campo límite de saltos de IPv6), la suma de comprobación de la cabecera de IPv4 necesitaba ser calculada en cada router. Al igual que la fragmentación y el reensamblado, esta también era una operación muy costosa en IPv4 que fue eliminada en IPv6.

* * *

### 4. ¿Es necesario el protocolo ICMP en IPv6? ¿Cumple las mismas funciones que en IPv4?

Los nodos IP utilizan el protocolo ICMP para informar de condiciones de error y proporcionar información limitada (por ejemplo, la respuesta de eco de un mensaje ping) a un sistema terminal.

En el documento RFC 4443 se ha definido una nueva versión de ICMP para IPv6. Además de reorganizar las definiciones de tipos y códigos ICMP existentes, ICMPv6 también añadió nuevos tipos y códigos requeridos por la nueva funcionalidad de IPv6, entre los que se incluyen el tipo “Paquete demasiado grande” y el código de error “Opciones IPv6 no reconocidas”. Además, ICMPv6 incluye la funcionalidad del Protocolo de gestión de grupos de Internet (IGMP, Internet Group Management Protocol) que se emplea para gestionar el modo en que un host se une a un grupo de multidifusión y lo abandona, anteriormente era un protocolo separado de ICMP en IPv4.

Resuelve:

-   Multicast Listener Discovery (MLD), reemplazo de IGMP.
-   Neighbor Discovery Protocol (NDP), reemplazo de ARP y mensajes Router Discovery, Redirect.
-   Mensajes de control de ICMP: informativos (ping), errores.

* * *

### 5. Transforme las siguientes direcciones MACs en Identificadores de Interfaces de 64 bits.

-   00:1b:77:b1:49:a1 --> fe80::21b:77ff:feb1:49a1
-   e8:1c:23:a3:21:f4 --> fe80::ea1c:23ff:fea3:21f4

* * *

### 6. ¿Cuál de las siguientes direcciones IPv6 no son válidas?

-   2001:0:1019:afde::1 --> `si`
-   2001::1871::4 --> `no`
-   3ffg:8712:0:1:0000:aede:aaaa:1211 --> `no`
-   3::1 --> `si`
-   :: --> `si`
-   2001:: --> `si`
-   3ffe:1080:1212:56ed:75da:43ff:fe90:affe --> `si`
-   3ffe:1080:1212:56ed:75da:43ff:fe90:affe:1001 --> `no`

* * *

### 7. ¿Cuál sería una abreviatura correcta de 3f80:0000:0000:0a00:0000:0000:0000:0845?

`3f80:0:0:a00::845`

* * *

### 8. Si quisiese que IPv6 soporte una nueva funcionalidad, ¿cómo lo haría?

Habría que basarse las cabeceras opcionales (campo Next Header, que indica el tipo del siguiente header) para extender el protocolo IPv6. Pero previamente, habría que desarrollar un RFC y que este se apruebe como estándar (para que lo implementen todos los dispositivos que soportan IPv6). O implementarlo dentro de todos los dispositivos del sistema autónomo (pero solo funcionaría dentro de este).

* * *

### 9. Indique si las siguientes direcciones son de link-local, global-address, multicast, etc.

-   fe80::1/64 --> `link-local`
-   3ffe:4543:2:100:4398::1/64 --> `6Bone`
-   :: --> `Any (direccion indefinida)`
-   ::1 --> `Loopback/Localhost`
-   ff02::2 --> `multicast`
-   2818:edbc:43e1::8721:122 --> `GLOBAL-ADDRESS, UNICAST`
-   ff02::9 --> `multicast`

* * *

### 10. Dado el siguiente diagrama, ¿qué direcciones IPv6 será capaz de autoconfigurar el nodo A en cada una de sus interfaces?

-   Primero genera la fe80::021b:77ff:feb1:49a1 /64 (LINK-LOCAL)
    Manda el router solicitation a la dirección de multicast ff02::2
    Recibe los prefijos de red y arma: 3ffe:8070:1011:100:021b:77ff:feb1:49a1 /64 (GLOBAL)
    El router le puede mandar más de un prefijo.

-   Primero genera la fe80::c225:eeff:feba:93e1 /64 (LINK-LOCAL)
    Manda el router solicitation a la dirección de multicast ff02::2
    Recibe los prefijos de red y arma: 2818:4fde:5100::c225:eeff:feba:93e1 /64 (GLOBAL)
    El router le puede mandar más de un prefijo.

* * *
