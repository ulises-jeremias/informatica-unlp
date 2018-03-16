# Práctica 1 - Introducción

### ¿Qué es una red? ¿Cuál es el principal objetivo para construir una red?

Definimos una red como un conjunto de Computadores u otros dispositivos, con placa de red y su correspondiente software, interconectados por medio de dispositivos físicos con el objetivo de compartir recursos tales como archivos, dispositivos, servicios, etc.
 
---- 
 
### ¿Qué es internet? Describa los principales componentes que permiten su funcionamiento.

Internet es un conjunto descentralizado de redes de comunicación, en otras palabras una red de redes de computadoras, las cuales, interconectadas mediante la familia de protocolos TCP/IP logran formar una red lógica de alcance mundial y publico.

El hecho de que internet sea descentralizado y publico refiere a que su filosofía es la de una red que no dependa de servidores controlados por empresas privadas, gobiernos, etc.

----

### ¿Qué son las RFCs?

**Request For Comment** (mas conocido como RFC _o Petición De Comentarios, en español_) son una familia de publicaciones realizadas por el grupo de trabajo de ingeniería de internet que describen diversos aspectos del funcionamiento de internet y otras rede de computadoras, como protocolos, procedimientos, etc. Además cuentan con comentarios o ideas sobre los mismos.

Cada RFC constituye un monográfico _ó memorando_ que ingenieros, o expertos en la materia, han enviado al IETF (consorcio de colaboración técnica mas importante de internet) para que el mismo sea evaluado y valorado por el resto de la comunidad. 

----

### ¿Qué es un protocolo?

Un protocolo es un conjunto de conductas y normas a conocer, respetar y cumplir no solo en el medio oficial ya establecido sino también en el medio social, laboral...
	
Define el formato y orden de los mensajes enviados y acciones a realizar.

Un **Protocolo de Red** es un conjunto de reglas las cuales permiten que dos o mas dispositivos, que dispongan de una placa de red y el software necesario, se comuniquen entre si para transmitir información por medio de cualquier tipo de variación de una magnitud física. Se trata de las reglas o el estándar que define la sintaxis, semántica, y sincronización de la comunicación, así como los posibles métodos de recuperación de errores. 

Cabe aclarar que estos protocolos pueden estar implementados tanto mediante Hardware, Software o ambos y que los mismos protocolos pueden ser combinables.

----

### ¿Por qué dos máquinas con distintos sistemas operativos pueden formar parte de una misma red?

A principios de los 80', las compañías comenzaron a implementar redes propias (privadas y cerradas). Estas primeras redes propietarias trajeron como consecuencia problemas ya que cada red tenía sus especificaciones propias (protocolos). Esto conllevó a tener problemas de incompatibilidad, por lo cual la comunicación entre redes era muy difícil, la evolución era muy lenta. Estos problemas de compatibilidad se fueron solucionando con la aparición de distintos estándares que facilitaron estas tareas. Por ejemplo se definieron modelos de organización divididos en capas, lo cual permite dividir la complejidad en componentes reusables. Estas estrategias de abstracción permitieron facilitar el desarrollo y evolución de las componentes de red asegurando interoperabilidad. Este tipo de estándares son los que permiten por ejemplo que dos máquinas con distintos sistemas operativos puedan formar parte de una misma red.

El hecho de que dos o mas dispositivos con distintos sistemas operativos puedan formar parte de una misma red es debido a que estos sistemas operativos respetan los mismos protocolos (tanto de Hardware como de Software) y saben comunicarse mediante ellos independientemente de como funcione el resto del sistema.

----

### ¿Cuáles son las 2 categorías en las que pueden clasificarse a los sistemas finales o End Systems? Dé un ejemplo del rol de cada uno en alguna aplicación distribuida que corra sobre Internet.

Las dos categorías son: cliente y servidor. Un ejemplo del rol del lado del servidor es: un servidor Web y del lado del cliente un browser.

----

### 7. ¿Cuál es la diferencia entre una red conmutada de paquetes de una red conmutada de circuitos?

La conmutación se considera la acción de establecer una vía o camino de extremo a extremo entre dos puntos. Un emisor y un receptor, a través de nodos o equipos de transmisión. La conmutación permite la entrega de la señal desde el origen hasta el destino requerido.

* Conmutación de circuitos: Los equipos de conmutación deben establecer un camino físico entre los medios de comunicación previo a la conexión entre usuarios. Este camino permanece activo durante la comunicación entre los usuarios, liberándose al terminar. ej: llamada telefónica. Son ideales para cuando se requiere que los datos sean transmitidos en tiempo real.

* Conmutación de paquetes: El emisor divide los mensajes a enviar en un número arbitrario de paquetes del mismo tamaño, donde adjunta una cabecera, dirección de origen y dirección de destino, así como datos de control que luego serán transmitidos por diferentes medios de conexión entre nodos temporales hasta llegar a su destino donde los paquetes son re ensamblados. Este método de comunicación es el que más se utiliza en las redes de computadoras actuales.

Mientras que la conmutación de circuitos asigna un canal único para cada sesión, en los sistemas de conmutación de paquetes el canal es compartido por muchos usuarios simultáneamente. La conmutación de paquetes es más eficiente y robusta para datos que pueden ser enviados con retraso en la transmisión (no en tiempo real), tales como el correo electrónico, paginas web, etc.
En el caso de aplicaciones como voz o video, la conmutación de paquetes no es muy recomendable a menos que se garantice un ancho de banda adecuado para enviar la información. Pero el canal que se establece no garantiza esto, debido a que puede existir tráfico y nodos caídos durante el recorrido de los paquetes.

---

### 8. Analice qué tipo de red es una red de telefonía y qué tipo de red es Internet

* Red telefónica: Red conmutada de circuitos.
* Internet: Red conmutada de paquetes.

---

### 9. Describa brevemente las distintas alternativas que conoce para acceder a Internet en su hogar.

Para poder tener acceso a Internet desde un hogar lo que se suele hacer es contratar un servicio de Internet a una empresa conocida como ISP (Internet service provider), la cual nos garantiza una conexión a nuestro hogar a través de diferentes tipos de conexiones. Éstas pueden ser por cable coaxial, fibra óptica, ADSL, etc. Normalmente se suele instalar un módem que convertirá las señales digitales en analógicas y viceversa. Éste permite así la comunicación entre las computadoras a través de las distintas conexiones. Finalmente los dispositivos para poder tener acceso a Internet, se deben conectar al módem ya sea de forma directa por Ethernet, o utilizando un router o distintos dispositivos que permiten la conexión a éste (ya sea de manera cableada o wireless).

---

### 10. ¿Qué ventajas tiene una implementación basada en capas o niveles?

La cantidad de componentes de red a interactuar genera complejidad, se requiere una organización de las mismas.

Un modelo en capas divide la complejidad en componentes reusables. Algunas de las ventajas que estos modelos proveen son:

* Reduce complejidad en componente más pequeñas.
* Las capas de abajo ocultan la complejidad a las de arriba abstracción.
* Las capas de arriba utilizan servicios de las de abajo:
Interfaces, similar a APIs.
* Los cambios en una capa no deberían afectar a las demás
si la interfaz se mantiene.
* Facilita el desarrollo, evolución de las componentes de red
asegurando interoperabilidad.
* Facilita aprendizaje, diseño y administración de las redes.

---

### 11. ¿Cómo se llama la PDU de cada una de las siguientes capas: Aplicación, Transporte, Red y Enlace?

Cada capa define su PDU: Protocol Data Unit.

| Capa | PDU |
| ------------- | ------------- |
| Aplicación | Datos |
| Transporte | Segmento |
| Red | Paquete |
| Enlace | Trama |
| Física | Bit |

---

### 12. . ¿Qué es la encapsulación? Si una capa realiza la encapsulación de datos, ¿qué capa del nodo receptor realizará el proceso inverso?

Encapsulación o encapsulamiento se refiere al proceso por el cual, cada capa de la pila de protocolos (excepto la de aplicación), añade información adicional (denominada información de cabecera) al PDU recibido de la capa superior, formando así, el PDU correspondiente a la capa receptora. Los PDUs sirven para gobernar el comportamiento completo del protocolo en sus funciones de establecimiento y unión de la conexión, control de flujo, control de errores, etc.

En cada capa, un paquete está formado por dos tipos de campos: un campo de cabecera y un campo de carga útil. Normalmente, la carga útil es un paquete de la capa superior.

Si una capa X realiza el encapsulamiento en el nodo emisor. La misma capa X será la encargada de hacer el proceso inverso en el nodo receptor.

---

### 13. Describa cuáles son las funciones de cada una de las capas del stack TCP/IP o protocolo de Internet.

Capas del stack TCP/IP o protocolo de Internet:

* Capa de Aplicación
* Capa de Transporte
* Capa de Red
* Capa de Enlace
* Capa Física

**Capa de Aplicación**

La capa de aplicación es donde aplicaciones de red y sus protocolos de la capa de aplicación residen. Esta capa incluye muchos protocolos, como el protocolo HTTP (el cual provee servicios para peticiones de documentos Web y transferencias,y FTP (el cual se utiliza para la transferencia de archivos entre dos sistemas finales). Otro ejemplo de protocolo que se ubica en esta capa es el de DNS, el cual sirve para traducir nombres de dominio.

Un protocolo de la capa de aplicación es distribuido sobre múltiples sistemas finales, con la aplicación en un sistema final usando el protocolo para intercambiar paquetes de información con la aplicación en otro sistema final. A menudo, en la capa de aplicación se refiere a este paquete de información como 'mensaje'.

**Capa de Transporte**

La capa de transporte de Internet transporta mensajes de la capa de aplicación entre distintos puntos. En Internet hay dos protocolos de transporte, TCP y UDP, ambos de los cuales pueden transportar mensajes de la capa de aplicación. TCP provee un servicio orientado a conexiones a sus aplicaciones. Este servicio incluye garantía en la distribución de mensajes de la capa de aplicación a sus destinos. TCP también 'rompe' mensajes largos en segmentos mas pequeños y provee un mecanismo de control de congestión. El protocolo UDP provee un servicio libre de conexiones a sus aplicaciones. Este es un servicio que no provee confiabilidad, ni control de flujo ni control de congestión. A menudo, en la capa de transporte se refiere a un paquete como un segmento.

**Capa de Red**

La capa de red es responsable de mover paquetes de la capa de red, conocidos como datagramas, de un host a otro. El protocolo de la capa de transporte (TCP o UDP) en un host fuente, pasa un segmento de la capa de transporte y una dirección de destino a la capa de red. La capa de red luego provee el servicio de distribuir el segmento a la capa de transporte en el host destino.

La capa de red incluye al protocolo IP, el cual define los campos en los datagramas, así como también la forma en que los sistemas finales y los routers actúan sobre estos campos. Existe un unico protocolo IP, y todos los componentes de Internet que tienen una capa de red, deben correr el protocolo IP. La capa de red también contiene protocolos de ruteo que determinan las rutas que los datagramas toman entre orígenes y destinos. Internet tiene muchos protocolos de ruteo. Como ya se sabe Internet es una red de redes, y dentro de una red el administrador de la red puede correr cualquier protocolo de ruteo deseado. Aunque la capa de red contiene tanto el protocolo IP como los protocolos de ruteo, a menudo simplemente se la refiere como la capa IP, reflejando el hecho de que IP es el 'pegamento' que une a Internet.

**Capa de Enlace**

La capa de red rutea un datagrama a través de una serie de routers entre el origen y el destino. Para mover un paquete de un nodo (host o router) al siguiente nodo en la ruta, la capa de red depende de los servicios de la capa de enlace. En particular, en cada nodo, la capa de red pasa el datagrama a la capa de enlace, la cual distribuye el datagrama al siguiente nodo a lo largo de la ruta. En este siguiente nodo, la capa de enlace pasa el datagrama a la capa de red.

Los servicios provistos por la capa de enlace dependen en el protocolo especifico que es empleado por el enlace. Por ejemplo, algunos protocolos de la capa de enlace proveen una distribución garantizada para la transición sobre un enlace. Vale aclarar que este servicio de distribución fiable es diferente a la fiabilidad del servicio TCP, el cual provee seguridad desde un sistema final a otro sistema. Ejemplos de protocolos de la capa de enlace son: Ethernet, WiFi, y PPP. Como los datagramas normalmente necesitan atravesar una gran cantidad de enlaces desde un origen a un destino, un datagrama puede llegar a ser manejado por diferentes protocolos de la capa de enlace en los diferentes enlaces a lo largo de la ruta. La capa de red recibirá diferentes servicios por cada uno de los diferentes protocolos de la capa de enlace. A menudo, en esta capa se referencian a los paquetes como frames.

**Capa Física**

Mientras que el trabajo de la capa de enlace es mover frames enteros de un elemento de red a otro adyacente, el trabajo de la capa física es mover los bits individuales que están dentro del frame de un nodo al próximo. Los protocolos en esta capa son dependientes al enlace y por ende también del medio actual de transición del enlace (por ejemplo cable de cobre, fibra óptica, etc). Por ejemplo, Ethernet tiene muchos protocolos de la capa física: uno para cables de cobre, otro para cable coaxial, otro para fibra óptica, etc. En cada caso, un bit es movido a través del enlace de una manera distinta.

---

### 14. Compare el modelo OSI con la implementación TCP/IP.

El modelo OSI se compone de 7 capas:

* Capa de Aplicación
* Capa de Presentación
* Capa de Sesión
* Capa de Transporte
* Capa de Red
* Capa de Enlace de Datos
* Capa Física

La funcionalidad de cinco de estas capas es aproximadamente la misma que las que se ven en el stack TCP/IP. El rol de la capa de presentación es proveer servicios que permiten a aplicaciones de comunicación interpretar el significado de datos intercambiados. Estos servicios incluyen compresión, encriptación y descripción de datos. La capa de sesión proporciona los mecanismos para controlar el diálogo entre las aplicaciones de los sistemas finales. En muchos casos, los servicios de la capa de sesión son parcialmente, o incluso, totalmente prescindibles.

Es responsabilidad del desarrollador de la aplicación decidir si un servicio es importante, y si lo es, depende del desarrollador construir esa funcionalidad en la aplicación.
