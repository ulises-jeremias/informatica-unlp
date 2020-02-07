# Práctica/Laboratorio de SMTP

## Ejercicio 1

Para descargar el archivo `.pcap` se utiliza el siguiente comando:

```sh
$ curl -H "x-custom-redes2018: value" http://redes.catedras.linti.unlp.edu.ar/smtp/smtp.pcap --output smtp.pcap
```

## Ejercicio 2

Exportado como archivo `.csv`.

## Ejercicio 3

**a)** Mirando la primer consulta DNS realizada, podemos observar que el servidor
DNS recursivo al cual hace la consulta tiene como IP 163.10.5.78.

**b)**

Las consultas DNS realizadas son las siguientes:

1.  Primero se hace una consulta DNS al servidor con IP 163.10.5.78 para obtener el servidor de mail de `demo.demo.info.unlp.edu.ar` haciendo una consulta DNS de tipo MX.

En la respuesta de la misma se obtienen los datos de dos servidores de mail. Los mismos son `mail2.demo.info.unlp.edu.ar` y `mail.demo.info.unlp.edu.ar` con preferencias 5 y 10 respectivamente.

2.  Posteriormente, se pide conocer la IP del servidor de mail con mayor nivel de preferencia, 5. Entonces se hace una consulta DNS de tipo AAAA al mismo servidor que en el caso anterior para conocer la IPv6 del servidor de mail `mail2.demo.info.unlp.edu.ar`. Dado que la respuesta de la consulta es vacia y no existe ningun error en la conexión, podemos saber que el mismo no tiene una IPv6 asociada.

3.  Se procede a consultar por la IPv4 del servidor `mail2.demo.info.unlp.edu.ar` haciendo una consulta DNS de tipo A. En la respuesta de la consulta podemos ver que se obtiene la ip 163.10.20.254.

4.  Posteriormente, se pide conocer la IP del servidor de mail con nivel de preferencia 10. Entonces se hace una consulta DNS de tipo AAAA al mismo servidor que en el caso anterior para conocer la IPv6 del servidor de mail `mail.demo.info.unlp.edu.ar`. Dado que la respuesta de la consulta es vacia y no existe ningun error en la conexión, podemos saber que el mismo no tiene una IPv6 asociada.

5.  Se procede a consultar por la IPv4 del servidor `mail.demo.info.unlp.edu.ar` haciendo una consulta DNS de tipo A. En la respuesta de la consulta podemos ver que se obtiene la ip 163.10.20.18.

**c)**

Mirando el flag Authoritative de las respuestas de las consultas podemos ver que ninguna de ellas son de tipo autoritativo.

## Ejercicio 4

**a)** Observando la primer de los datos correspondientes a SMTP podemos ver que el servidor de mail con el que se logra establecer la conexión tiene ipv4 163.10.20.18, es decir, que se conecta con el servidor `mail.demo.info.unlp.edu.ar`.

**b)** **Dos comunicaciones SMTP??**

## Ejercicio 5

**a)** La información que envia el servidor como respuesta al EHLO es:

-   mail
-   PIPELINING
-   SIZE 10240000
-   VRFY
-   ETRN
-   STARTTLS
-   AUTH PLAIN LOGIN
-   AUTH=PLAIN LOGIN
-   ENHANCEDSTATUSCODES
-   8BITTIME
-   DSN
-   SMTPUTF8

**b)**

Se envia el mail de forma segura utilizando TLS.

## Ejercicio 6

**a)** El nombre del servidor de correo origen es `mail.linti.unlp.edu.ar` y lo sabemos dado que se envia como parámetro del comando EHLO.

      The first command we need to issue to the mail server is the EHLO or HELO.  This is a basic greeting that starts the communication between the telnet client and the SMTP server.  Also passed is the DNS PTR for the IP address from which we are connecting as determined previously.

**b)**
