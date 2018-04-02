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

-   \-I, --head: Recupera únicamente el header de HTTP en el request.
-   \-H, --header: Sirve para agregar información al header del request que se va a realizar (además sirve para reemplazar los valores por defecto que utilizará curl, de esta forma también se pueden limpiar algunos valores predeterminados. Ej. –H “Host:” ; así se limpia el dato Host del header).
-   \-X, --request: Especifica un método de request específico para usar en la comunicación (el default es GET).
-   \-s, --silent: Modo silencio. No muestra los mensajes de error.

* * *

### 8. Ejecute el comando curl sin ningún parámetro adicional y acceda a www.redes.unlp.edu.ar. Luego responda:

#### a. ¿Cuántos requerimientos realizó y qué recibió? Pruebe redirigiendo la salida del comando curl a un archivo con extensión html y abrirlo con un navegador.

Se realizó un único request y se recibió el contenido HTML de la página solicitada.

#### b. ¿Cómo funcionan los atributos href de los tags link e img en html?

-   La etiqueta `<link>` define una relación entre un documento y un recurso externo.

-   La etiqueta `<img>` define una imagen en una página HTML.

El atributo `href` del elemento link especifica la URL del recurso en cuestión.
El atributo `src` del elemento img especifica la URL de la imagen.

La mayoría de los navegadores cuando encuentran estos elementos en el documento HTML realizan una _solicitud automática al servidor_ para obtenerlos.

#### c. Para visualizar la página completa con imágenes como en un navegador, ¿alcanza con realizar un único requerimiento?

No, no alcanza. Será necesario hacer cada una de las request correspondientes a los recursos necesarios.

### 9. Ejecute a continuación los siguientes comandos:

`curl -v -s www.redes.unlp.edu.ar > /dev/null`

`curl -I -v -s www.redes.unlp.edu.ar`

#### a. ¿Qué diferencias nota entre cada uno?

El primer comando esta haciendo un request a la URL con los atributos de verbose y silent, y luego está redireccionando la respuesta de la petición a /dev/null.

El segundo comando hace un request a la misma URL con los mismoas atributos, ademas del ´-I´ el cual hara que solamente se muestren los headers.

Es por esto que ambos comandos devuelven salidas muy parecidas.

#### b. ¿Qué ocurre si en el primer comando quita la redirección a /dev/null? ¿Por qué no es necesaria en el segundo comando?

Si en el primer comando se quita la redirección a /dev/null lo que sucederá es que se mostrará en la consola el contenido de la respuesta obtenida luego de realizar el request. En el segundo comando no es necesaria esta redirección ya que el parámetro ´-I´ hace que curl devuelva solamente los headers.

#### c. ¿Cuántas cabeceras viajaron en el requerimiento? ¿Y en la respuesta?

Cabeceras del request:

-   User-Agent
-   Host
-   Accept

Cabeceras del response:

-   Date
-   Server
-   Last-Modified
-   ETag
-   Accept-Ranges
-   Content-Length
-   Content-Type

* * *

### 10. Ejecute una vez más el comando curl www.redes.unlp.edu.ar pero sólo muestre los encabezados y luego responda:

Ejecutamos `curl -I www.redes.unlp.edu.ar`

#### a. ¿Es posible determinar qué servidor web se utiliza para servir la página?

Si, es posible saber esto observando el header `Server`, el cual en este caso toma el valor `Apache/2.4.7 (Ubuntu)`.

#### b. ¿Cuál es el código de respuesta que devolvió el servidor? ¿Qué otros códigos existen y qué significan? Investigue genéricamente los tipos de error 2XX, 3XX, 4XX y 5XX.

El código de respuesta que devolvió el servidor es el 200.

| Código | Significado          |
| ------ | -------------------- |
| 2XX    | Peticiones correctas |
| 3XX    | Redirecciones        |
| 4XX    | Errores del cliente  |
| 5XX    | Errores del servidor |

#### c. ¿Cuándo fue la última vez que se modificó la página?

Esto se puede observar en el header `Last-Modified`, el cual en este caso toma el valor `Wed, 16 Mar 2016 20:41:34 GTM`.

#### d. Solicite la página nuevamente con curl usando GET, pero esta vez indique que quiere obtenerla sólo si la misma fue modificada en una fecha posterior a la que efectivamente fue modificada. ¿Cómo lo hace? ¿Qué resultado obtuvo? ¿Puede explicar por qué y para qué sirve?

Se puede realizar de las siguientes dos formas:

-   `curl -I -H 'If-Modified-Since: Wed, 17 Sep 2017' www.redes.unlp.edu.ar`

-   `curl –z 'Wed, 17 Sep 2017' www.redes.unlp.edu.ar`

Como era de esperar no se obtuvo resultado alguno.

#### e. ¿Qué significa el encabezado ETag?

Es uno de los varios mecanismos que HTTP proporciona para la validación de caché web, y que permite a un cliente realizar peticiones condicionales. Esto permite que las cachés sean más eficientes y ahorra ancho de banda, puesto que un servidor web no necesita enviar una respuesta completa si el contenido no ha cambiado. Los ETags también pueden ser usados para el control de concurrencia optimista, como una manera de ayudar a prevenir que actualizaciones simultáneas de un recurso se sobrescriban entre sí.

#### f. Investigue el encabezado If-Modified-Since. ¿Para qué cree que pueden servir los tres encabezados anteriores?

Un cache web, también denominada como servidor proxy, en una entidad de red que satisface solicitudes HTTP en nombre de un servidor web de origen. La caché web dispone de su propio almacenamiento en disco y mantiene en él copias de los objetos solicitados recientemente. La cache web es un servidor y un cliente. Esto permite reducir el tráfico y el trabajo del servidor web. Típicamente es un ISP quien adquiere e instala un cache web.

Estos encabezados sirven para implementar el GET condicional, y de esta forma da lugar a la incorporación de un cache web.

* * *

### 12. En base a lo obtenido en el ejercicio anterior, responda

#### a. ¿Qué está haciendo al ejecutar el comando telnet?

El comando Telnet es una interfaz de usuario para el protocolo Telnet. Este comando es usado para comunicarse interactivamente con otro host, usando el protocolo Telnet. Comienza en modo comando, donde se imprime un prompt Telnet. Si telnet es invocado con un host de argumento, se realiza un comando open de manera implícita.

#### b. ¿Qué comando HTTP utilizó? ¿Qué recurso solicitó?

Se utilizó el comando `GET`, y se solicitó el recurso `/http/HTTP-1.x/`.

#### c. ¿Qué diferencias notó entre los dos casos? ¿Puede explicar por qué?

Al hacer el request utilizando el protocolo HTTP 1.0, luego de obtener la respuesta, la conexión se cerró inmediatamente, en cambio al utilizar HTTP 1.1, luego de obtener la respuesta, la conexión se mantiene abierta por un momento, dando lugar así a realizar nuevas consultas.

#### d. ¿Cuál de los dos casos le parece más eficiente? Piense en el ejercicio donde analizó la cantidad de requerimientos necesarios para obtener una página con estilos, javascripts e imágenes. El caso elegido, ¿puede traer asociado algún problema?

HTTP 1.1 permite tener conexiones persistentes, lo cual significa que se puede realizar mas de un request en la misma conexión TCP.

En cambio en HTTP 1.0 se debe abrir una nueva conexión por cada request. Y luego de cada respuesta la conexión debería ser cerrada. Esto claramente lleva a claros problemas de eficiencia.

* * *

* * *

### 13. La página www.redes.unlp.edu.ar/http/idioma.php tiene soporte para visualizarse en inglés y en español. Manipule los encabezados de HTTP para visualizar la página en los diferentes idiomas.

-   Español:

`curl -H "Accept-Language: es" www.redes.unlp.edu.ar/http/idioma.php`

-   Inglés:

`curl -H "Accept-Language: en" www.redes.unlp.edu.ar/http/idioma.php`

* * *
