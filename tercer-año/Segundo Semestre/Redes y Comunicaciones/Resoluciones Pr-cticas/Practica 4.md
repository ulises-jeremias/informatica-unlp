# Práctica 4

### 1. ¿Qué protocolos se utilizan para el envío de mails entre el cliente y su servidor de correo? ¿Y entre servidores de correo?

Con el fin de enviar un correo a un destinatario, un usuario debe hacer uso de un agente de usuario para correo electrónico, que le permita enviar su correo hacia su servidor de correo. Esta transferencia de información se logra haciendo uso del protocolo SMTP.

* SMTP: El funcionamiento de este protocolo se da en línea, de manera que opera en los servicios de correo electrónico. Sin embargo, este protocolo posee algunas limitaciones en cuanto a la recepción de mensajes en el servidor de destino (cola de mensajes recibidos). Como alternativa a esta limitación se asocia normalmente a este protocolo con otros, como el POP o IMAP, otorgando a SMTP la tarea específica de enviar correo, y recibirlos empleando los otros protocolos antes mencionados (POP O IMAP).

SMTP además se utiliza para la comunicación entre los servidores de correo.

---

### 2.  ¿Qué protocolos se utilizan para la recepción de mails? ¿Incluiría a HTTP en dichos protocolos? Enumere y explique características y diferencias entre las alternativas posibles.

Cuando un usuario desea leer los correos que se almacenan en su servidor de correo, éste debe utilizar su agente de usuario el cual se comunicará con el servidor de correo a traves de alguno de los siguientes protocolos con el fin de recibir los correos:

* POP3: (Post Office Protocol -- Version 3) es un protocolo de acceso de correo extremadamente simple. Se define en la RFC 1939, la cual es corta y bastante fácil de entender. Debido a que el protocolo es muy simple, su funcionalidad es bastante limitada. POP3 comienza cuando el agente de usuario abre una conexión TCP hacia el servidor de correo en el puerto 110. Con la conexión TCP establecida, POP3 avanza a lo largo de 3 fases: autorización, transacción y actualización. Durante la fase de autorización el agente de usuario envía un username y una contraseña para autenticar al usuario. Durante la segunda fase, el agente de usuario recibe mensajes; durante esta fase el usuario también puede marcar correos para borrado. La fase de actualización ocurre luego de que el usuario utiliza el comando `quit`, el ual finaliza la sesión POP3; en este momento el servidor de mail elimina los correos que fueron marcados para su eliminación.

* IMAP: Como POP3, IMAP es un protocolo de acceso de correo. Tiene muchas mas características que POP3, pero también es significativamente mas complejo. Un servidor IMAP asociará cada mensaje con una carpeta; cuando un mensaje arriba al servidor por primera vez, este es asociado con la carpeta INBOX del receptor. Este último puede mover el mensaje a una nueva carpeta, leer el mensaje, eliminarlo y muchas cosas mas. Otra característica importante que posee IMAP es que tiene comandos que le permiten al usuario obtener componentes de mensajes. Por ejemplo, un agente de usuario podría solamente obtener el header del mensaje o solamente una parte de un mensaje MIME. Esta característica es muy útil cuando hay una conexión con un pequeño ancho de banda entre el agente de usuario y su servidor de correo.

* HTTP: Cuando el usuario utiliza su navegador web como agente de usuario para la recepción de correos, en realidad en el servidor qeb que atiende estas peticiones, por detrás utilizará uno de los protocolos mencionados anteriormente.

---

### 3j. Con el rol de administrador del sistema (root), ejecute el cliente de correos. Para esto, abra una consola de comandos y ejecute: sudo icedove De esta forma, iniciará el cliente de correo con el perfil del superusuario (diferente del usuario con el que configuró las cuentas antes mencionadas).  Luego configure las cuentas POP e IMAP de los usuarios alumnopop y alumnoimap como se describió anteriormente pero desde el cliente de correos del usuario root. Luego responda:

#### ¿Qué correos ve en el buzón de entrada de ambas cuentas? ¿Están marcados como leídos o como no leídos? ¿Por qué? ¿Qué pasó con las carpetas POP e IMAP que creó en el paso anterior? 
 
En la cuenta POP3 se ven los correos como no leidos y no se visualizan las carpetas. En cambio en la cuenta IMAP los correos estan como leidos y se visualizan las carpetas personales.

Esto se debe a que IMAP, a diferencia de POP3, mantiene el estado en el servidor.

---

### 4. En base a lo observado. ¿Qué protocolo le parece mejor? ¿POP o IMAP? ¿Por qué? ¿Qué protocolo considera que utiliza más recursos del servidor? ¿Por qué?

A la hora de elegir qué protocolo utilizar para recuperar los mails de nuestro servidor de correo, hay que considerar las ventajas y desventajas que cada protocolo presenta. Es verdad que hoy en día es mucho mas viable utilizar IMAP sobre POP3, debido a las características que este presenta.


#### IMAP

* Ventajas:

  * Comunicación bidireccional entre el servidor de correo y el cliente de correo electrónico, lo que permite que varios dispositivos trabajen con una misma cuenta viendo los cambios realizados por todos.
  * Los correos están en todo momento en el servidor, por lo que se puede acceder a ellos desde cualquier lugar, teniendo un dispositivo con acceso a internet.
  * En caso de una avería en el ordenador en el que esté configurado el buzón, o si por cualquier razón se elimina la cuenta, siempre es posible recuperar los correos.
  * Al no descargarse los correos directamente en el dispositivo que accede al servidor de correo, no consume espacio local.
  * Es posible gestionar carpetas locales y archivos desde el servidor.
  * Permite la búsqueda de mensajes por medio de palabras clave.

* Desventajas:

  * No es posible acceder a los correos sin acceso a internet.
  * En caso de hacer un uso intensivo del servicio de correo, es necesaria una gran cantidad de espacio de almacenamiento en el servidor.
  * Las carpetas que se hayan creado con IMAP no podrán ser leídas usando POP (la única excepción es la carpeta de la Bandeja de entrada).

#### POP3

* Ventajas:

  * Poder utilizar un cliente de correo para descargarlos en un dispositivo u ordenador, y poder leerlos posteriormente, aún sin tener conexión a internet.
  * No es necesario tener un gran espacio de almacenamiento en el servidor de correo, ya que al descargar los correos se borran del mismo.

* Desventajas:

  * Si el dispositivo donde están almacenados los correos descargados tiene una avería, es extraviado, o robado se pierden los correos.
  * Enviar un mensaje desde el cliente puede tardar el doble del tiempo.
  * Dependiendo del mensaje, puede consumir recursos del sistema.

---

### 5. Suponga que el servidor de correo mail1.example.com tiene para enviar un correo a pepe@gmail.com.  Indique y justifique en todos los casos:

#### a. Primer consulta de DNS que debe hacer mail1.example.com.

La primer consuta DNS que se debe hacer es por los registros MX del dominio gmail.com.

#### b. Suponiendo que la consulta anterior devuelve varios resultados, ¿de qué forma elegiría mail1.example.com el servidor al cuál entregar el correo? ¿Y si ese servidor no estuviera disponible?

Si la consulta anterior devuelve varios resultados se debe elegir el que tiene menor numero de preferencia. Si este servidor no esta disponible se debe intentar con otro.

#### c. Considerando que la consulta anterior retorna un listado de nombres de servidores de correo para gmail.com, ¿será necesario realizar una consulta adicional? En caso de responder afirmativamente, indique el registro por el cuál será la consulta.

Se debe consultar por el registro `A` del dominio del correo obtenido.

#### d. El protocolo de aplicación y de transporte, junto con el puerto correspondiente, que deberá utilizar el servidor mail1.example.com para entregar el correo a pepe@gmail.com.

* Protocolo de aplicación: SMTP
* Protocolo de transporte: TCP
* Puerto: 25

