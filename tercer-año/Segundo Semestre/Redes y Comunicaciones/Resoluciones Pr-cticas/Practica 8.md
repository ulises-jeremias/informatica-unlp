# Práctica 8 - Capa de Red - Ruteo

### 2. En las redes IP el ruteo puede configurarse en forma estática o en forma dinámica. Indique ventajas y desventajas de cada método.

#### IP Estáticas

**Ventajas**

* Ofrecen conexiones más fiables y estables.
* Suelen permitir mayores velocidades de carga y descarga.
* Te dan un control exclusivo de tu IP. Nadie más puede usarla. Así evitas bloqueos o problemas por malos usos que no sean culpa tuya.
* Son ideales por ejemplo para jugadores online, proveedores o usuarios de telefonía y vídeo por Internet (VoIP) como Skype. También en servidores de todo tipo y servicios de alojamiento web. O en sistemas de redes privadas virtuales (VPN).

**Desventajas**

* En principio son menos seguras. Los hackers u otros atacantes tienen más tiempo y oportunidades para atacar equipos con IPs que sean siempre iguales. Obligan a tomar medidas de seguridad extra y más rigurosas.
* En general hay que pagar un precio adicional para tener una IP fija en Internet. Además no las ofrecen todos los proveedores de acceso. Tendrías que consultar al tuyo.
* Lo normal es que haya que configurarlas a mano. Quien las usa debe tener más conocimientos de informática.

#### IP Dinámicas

**Ventajas**

* No tienes que pagar más por ellas. La mayoría de los proveedores de Internet asignan IPs dinámicas a sus clientes como parte de su plan de acceso normal.
* En principio son más seguras. Es más díficil para un atacante rastrear y buscar debilidades en un equipo con una IP variable.
* Ofrecen mayor privacidad en Internet. A los sitios web les cuesta más rastrear lo que haces si tu IP va cambiando.
* Su configuración en la red suele ser automática. No necesitas hacerla tú. Se encarga de ello lo que se llama un servidor DHCP.
* Optimizan el uso de recursos y abaratan costos. Cuando un equipo se desconecta de Internet u otra red ya "no necesita" su IP. Así puede reutilizarse asignándosela a otro equipo que se conecte.

**Desventajas**

* Es más fácil que la conexión falle o se interrumpa.

---

### 3. Una máquina conectada a una red pero no a Internet, ¿tiene tabla de ruteo?

Sí, porque aunque sea una red local se utiliza la tabla de enrutamiento para comunicarse con los demás dispositivos de la red. Internet es una red con las mismas características que la red privada, simplemente que es pública. Además vimos que en la tabla de enrutamiento hay que tener una entrada por defecto (0.0.0.0) que devuelve a la interface conectada y una entrada para la red donde estamos conectado con el default gateway local (0.0.0.0).
