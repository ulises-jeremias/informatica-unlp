# Práctica 2

### 2. ¿Cuál es la función de la capa de aplicación?

La capa de aplicación ofrece a las aplicaciones (de usuario o no) la posibilidad de acceder a los servicios de las demás capas y define los protocolos que utilizan las aplicaciones para intercambiar datos, como correo electrónico (_POP_ y _SMTP_), gestores de bases de datos y protocolos de transferencia de archivos (_FTP_).

Cabe aclarar que el usuario normalmente no interactúa directamente con el nivel de aplicación. Suele interactuar con programas que a su vez interactúan con el nivel de aplicación pero ocultando la complejidad subyacente.

* * *

### 3. ¿Cómo podrían comunicarse dos procesos si están en diferentes máquinas?

Los procesos de dos sistemas terminales diferentes se comunican entre ellos intercambiando mensajes a través de la red de computadoras. Un proceso emisor crea y envía mensajes a la red; un proceso receptor recibe estos mensajes y posiblemente responda devolviendo mensajes.

Ambos procesos hacen uso de la capa de aplicación para enviar y recibir datos.

* * *

### 4. Explique brevemente cómo es el modelo Cliente/Servidor. De un ejemplo de un sistema Cliente/Servidor en la “vida cotidiana” y un ejemplo de un sistema informático que siga el modelo Cliente/Servidor. ¿Conoce algún otro modelo de comunicación?

El término ordenador local se utiliza para referirse al ordenador que el usuario utiliza para entrar en la red Internet. Desde ese ordenador el usuario establece conexiones con otros ordenadores, denominados ordenadores remotos, a los que solicita algún servicio. Estos ordenadores remotos que ofrecen servicios reciben también el nombre de servidores o host.

La utilización de las diferentes aplicaciones o servicios de Internet se lleva a cabo respondiendo al llamado modelo cliente-servidor.

Cuando se utiliza un servicio en Internet, como consultar una base de datos, transferir un fichero o participar en un foro de discusión, se establece un proceso en el que entran en juego dos partes. Por un lado, el usuario, quien ejecuta una aplicación en el ordenador local: el denominado programa cliente. Este programa cliente se encarga de ponerse en contacto con el ordenador remoto para solicitar el servicio deseado. El ordenador remoto por su parte responderá a lo solicitado mediante un programa que está ejecutando. Este último se denomina programa servidor. Los términos cliente y servidor se utilizan tanto para referirse a los programas que cumplen estas funciones, como a los ordenadores donde son ejecutados esos programas.

El programa o los programas cliente que el usuario utiliza para acceder a los servicios de Internet realizan dos funciones distintas. Por una parte, se encargan de gestionar la comunicación con el ordenador servidor, de solicitar un servicio concreto y de recibir los datos enviados por éste; y por otra, es la herramienta que presenta al usuario los datos en pantalla y que le ofrece los comandos necesarios para utilizar las prestaciones que ofrece el servidor.

Algunos ejemplos de aplicaciones computacionales que usen el modelo cliente-servidor son el Correo electrónico, un Servidor de impresión y la World Wide Web.

Ejemplo de otro modelo de comunicación: En una arquitectura P2P existe una mínima (o ninguna) dependencia de una infraestructura de servidores siempre activos. En su lugar, la aplicación explota la comunicación directa entre parejas de host conectados de forma intermitente, conocidos como peers (pares). Los pares no son propiedad del proveedor del servicio, sino que son las computadoras de escritorio y portátiles controlados por usuarios, encontrándose la mayoría de los pares en domicilios, universidades y oficinas.

* * *

### 5. Describa la funcionalidad de la entidad genérica “Agente de usuario” o “User agent”.

Un agente de usuario es una aplicación informática que funciona como cliente en un protocolo de red; el nombre se aplica generalmente para referirse a aquellas aplicaciones que acceden a la World Wide Web. Los agentes de usuario que se conectan a la Web pueden ser desde navegadores web hasta los web crawler de los buscadores, pasando por teléfonos móviles, lectores de pantalla y navegadores en Braille usados por personas con discapacidades.

Cuando un usuario accede a una página web, la aplicación generalmente envía una cadena de texto que identifica al agente de usuario ante el servidor. Este texto forma parte del pedido a través de HTTP, llevando como prefijo User-agent: o User-Agent: y generalmente incluye información como el nombre de la aplicación, la versión, el sistema operativo, y el idioma. Los bots, como los web crawlers, a veces incluyen también una URL o una dirección de correo electrónico para que el administrador del sitio web pueda contactarse con el operador del mismo.

* * *

### 6. ¿Qué son y en qué se diferencian HTML y HTTP?

HTML, sigla en inglés de Hyper Text MarkupLanguage _(lenguaje de marcas de hipertexto)_, hace referencia al lenguaje de marcado para la elaboración de páginas web. Es un estándar que sirve de referencia del software que conecta con la elaboración de páginas web en sus diferentes versiones, define una estructura básica y un código (denominado código HTML) para la definición de contenido de una página web, como texto, imágenes, videos, juegos, entre otros.

HTTP (Hyper Text Transfer Protocol) es un protocolo de la capa de aplicación de la Web para la transferencia de hipertexto. Está definido en los documentos [RFC 1945] y [RFC 2616]. HTTP se implementa en dos programas: un programa cliente y un programa servidor. Ambos se ejecutan en sistemas terminales diferentes, y se comunican entre sí intercambiando mensajes HTTP. HTTP define la estructura de estos mensajes y cómo, el cliente y el servidor, los intercambian.

* * *

### 7. Investigue sobre el comando curl y analice para qué sirven los siguientes parámetros (-I, -H, -X, -s).

Curl es una herramienta para transferir datos desde o hacia un servidor, usando uno de los protocolos soportados (FTP, FTPS, HTTP, HTTPS, SFTP, SMTP, TELNET, etc). El comando está diseñado para funcionar sin interacción del usuario.

* -I, --head: Recupera únicamente el header de HTTP en el request.
* -H, --header: Sirve para agregar información al header del request que se va a realizar (además sirve para reemplazar los valores por defecto que utilizará curl, de esta forma también se pueden limpiar algunos valores predeterminados. Ej. –H “Host:” ; así se limpia el dato Host del header).
* -X, --request: Especifica un método de request específico para usar en la comunicación (el default es GET).
* -s, --silent: Modo silencio. No muestra los mensajes de error.

* * *

### 8. Ejecute el comando curl sin ningún parámetro adicional y acceda a www.redes.unlp.edu.ar. Luego responda:

#### a. ¿Cuántos requerimientos realizó y qué recibió? Pruebe redirigiendo la salida del comando curl a un archivo con extensión html y abrirlo con un navegador.

Se realizó un único request y se recibió el contenido HTML de la página solicitada.

#### b. ¿Cómo funcionan los atributos href de los tags link e img en html?

* La etiqueta `<link>` define una relación entre un documento y un recurso externo.

* La etiqueta `<img>` define una imagen en una página HTML.

El atributo `href` del elemento link especifica la URL del recurso en cuestión.
El atributo `src` del elemento img especifica la URL de la imagen.

La mayoría de los navegadores cuando encuentran estos elementos en el documento HTML realizan una *solicitud automática al servidor* para obtenerlos.

#### c. Para visualizar la página completa con imágenes como en un navegador, ¿alcanza con realizar un único requerimiento?

No, no alcanza. Será necesario hacer cada una de las request correspondientes a los recursos necesarios.
