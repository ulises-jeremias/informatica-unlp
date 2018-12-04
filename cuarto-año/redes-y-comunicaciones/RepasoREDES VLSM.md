2^0 1

2^1 2

2^2 4

2^3 8

2^4 16

2^5 32

2^6 64

2^7 128

2^8 256

2^9 512

2^10 1024

2^11 2048

RED A - 100 hosts
RED B - 70 hosts
RED D - 16 hosts
RED C - 14 hosts

* * *

Tomamos la RED A
NO HAY CONDICIONES SOBRE ESTA IP, PUEDE SER PUBLICA O PRIVADA DE CUALQUIER CLASE DE REDES

Siendo que necesitamos 100 hosts, la cantidad de bits de hosts necesarias seran 7 bits de host,
32 - 7 = 25, mascara

Entonces tomamos como bloque alguna IP con mascara menor a 25, tomamos 192.168.10.0/24

7 bh y 1 bs,

192.168.10. |0|0000000 /25

-   Rango de RED [192.168.10.0/25, 192.168.10.127/25]

-   Rango de IPs asignables [192.168.10.1/25, 192.168.10.126/25]

=> **RED A - 192.168.10.0/25**

Libre 192.168.10.128/25

* * *

Tomamos la RED B
NO HAY CONDICIONES SOBRE ESTA IP, PUEDE SER PUBLICA O PRIVADA DE CUALQUIER CLASE DE REDES

Necesitamos 70 hosts, la cantidad de bits de hosts necesaria es 7, por lo que la mascara es nuevamente 25,
por lo que utilizamos la RED libre 192.168.10.128/25,

=> **RED B - 192.168.10.128/25**

-   Rango de RED [192.168.10.128/25, 192.168.10.255/25]

-   Rango de IPs asignables [192.168.10.129/25, 192.168.10.254/25]

* * *

Tomamos la RED D
RED PÚBLICA

Necesitamos 16 hosts, pero no alcanza con 4 bits, CHAN CHAN CHAAAAN!!
Pues las IP de subred y broadcast no son asignables, entonces asignamos utilizando 5 bh
32 - 5 = 27, mascara

Vamos a buscar una IP de bloque con mascara menor a 27, por ejemplo, 200.30.55.64/26, IP PUBLICA.

200.30.55.01|0| 00000 /27

=> **RED D - 200.30.55.64/27**

-   Rango de RED [200.30.55.64/27, 200.30.55.95/27]

-   Rango de IPs asignables [200.30.55.65/27, 200.30.55.94/27]

Libre 200.30.55.01.96/27

* * *

Tomamos la RED C
RED PUBLICA

Necesitamos 14 hosts, nos alcanza con 4 bh, por eso tomamos la RED libre anterior y subneteamos a partir de esa IP
Libre 200.30.55.01.96/27

32 - 4 = 28, mascara

200.30.55.011|0| 0000 /28

=> **RED C - 200.30.55.96/28**

-   Rango de RED [200.30.55.96/28, 200.30.55.111/28]

-   Rango de IPs asignables [200.30.55.97/28, 200.30.55.110/28]

Libre 200.30.55.112/28

* * *

ENLACE IZQUIERDO
Los enlaces entre routers deben utilizar redes privadas.

Necesitamos 3 hosts, por lo que buscamos 3bh, y necesitamos una mascara menor 32 - 3 = 29,

Utilizamos la IP de bloque 10.10.10.0/27 y el rango de 10.10.10.0 a 10.10.10.15 está utilizado

10.10.10.000 |10| 000 /29

=> **ENLACE ENTRE ROUTERS ABE - 10.10.10.16/29**

-   Rango de RED [10.10.10.16/29, 10.10.10.23/29]

-   Rango de IPs asignables [10.10.10.17/29, 10.10.10.22/29]

Libres 10.10.10.24/29

* * *

ENLACE DERECHO
Los enlaces entre routers deben utilizar redes privadas.

Necesitamos 2 hosts, por lo que nos alcanza con 2 bits teniendo en cuenta IPs de subred y broadcast,
32 - 2 = 30, mascara

Utilizamos la IP Libre 10.10.10.24/29

10.10.10.00011 |0| 00/30

=> **ENLACE ENTRE ROUTERS CD - 10.10.10.24/30**

-   Rango de RED [10.10.10.24/30, 10.10.10.27/30]

-   Rango de IPs asignables [10.10.10.25/30, 10.10.10.26/30]

Libre 10.10.10.28/30

* * *


## Realice las tablas de rutas de RouterE y BORDER considerando

-   Siempre se deberá tomar la ruta más corta.

-   Sumarizar siempre que sea posible.

-   El tráfico de Internet a la Red D y viceversa debe atravesar el RouterC.

-   Todos los hosts deben poder conectarse entre sí y a Internet.


### Border

Destination, Gateway, Genmask, ..., Iface

-   Dst: 200.30.55.96, Genmask: /28, Gtw: 10.10.10.9, Iface: eth0
-   Dst: 200.30.55.64, Genmask: /27, Gtw: 10.10.10.9, Iface: eth0
-   Dst: 192.68.10.0, Genmask: /25, Gtw: 10.10.10.5, Iface: eth2
-   Dst: 192.68.10.128, Genmask: /25, Gtw: 10.10.10.5, Iface: eth2
-   Dst: 10.10.10.16, Genmask: /29, Gtw: 10.10.10.5, Iface: eth2
-   Dst: 10.10.10.12, Genmask: /30, Gtw: 10.10.10.5, Iface: eth2
-   Dst: 10.10.10.0, Genmask: /30, Gtw: 10.10.10.5, Iface: eth2
-   Dst: 10.10.10.24, Genmask: /30, Gtw: 10.10.10.9, Iface: eth0

**Enlaces propios de la RED del Router BORDER**

-   Dst: 10.10.10.4, Genmask: /30, Gtw: 0.0.0.0, Iface: eth2
-   Dst: 10.10.10.8, Genmask: /30, Gtw: 0.0.0.0, Iface: eth0
-   Dst: 172.16.0.0, Genmask: /24, Gtw: 0.0.0.0, Iface: eth1

### Router E

Destination, Gateway, Genmask, ..., Iface

-   Dst: 172.16.0.0, Genmask: /24, Gtw: 10.10.10.6, Iface: eth3
-   Dst: 200.30.55.96, Genmask: /28, Gtw: 10.10.10.14, Iface: eth1
-   Dst: 200.30.55.64, Genmask: /27, Gtw: 10.10.10.2, Iface: eth2
-   Dst: 192.68.10.0, Genmask: /25, Gtw: 10.10.10.18, Iface: eth0
-   Dst: 192.68.10.128, Genmask: /25, Gtw: 10.10.10.17, Iface: eth0
-   Dst: 172.16.0.0, Genmask: /24, Gtw: 10.10.10.6, Iface: eth3
-   Dst: 10.10.10.8, Genmask: /30, Gtw: 10.10.10.6, Iface: eth3
-   Dst: 10.10.10.24, Genmask: /30, Gtw: 10.10.10.12, Iface: eth1

**Enlaces propios de la RED del Router E**

-   Dst: 10.10.10.16, Genmask: /29, Gtw: 0.0.0.0, Iface: eth0
-   Dst: 10.10.10.12, Genmask: /30, Gtw: 0.0.0.0, Iface: eth1
-   Dst: 10.10.10.0, Genmask: /30, Gwt: 0.0.0.0, Iface: eth2
-   Dst: 10.10.10.4, Genmask: /30, Gwt: 0.0.0.0, Iface: eth3
