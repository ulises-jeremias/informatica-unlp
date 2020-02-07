# Sea M una máquina de Turing del modelo "D-I-S". ¿Existe una máquina de Turing M' equivalente a M que comience con el cabezal apuntando a cualquier celda de la cinta? Note que M' puede apuntar a una celda no ocupada por el input. ¿Qué puede decir al respecto si se sabe que λ ∉ L(M)? Justifique su respuesta.

Si, es posible. Habiendo estados iniciales que reemplacen al estado q0 siendo q'0 y ql0 qr0.

La idea es que tenga unos estados previos a q0 que estén en cualquier posición de la cinta y vayan leyendo de izquierda a derecha, marcando los blancos con una señal como un caracter de la cinta, "#", hasta llegar a la cadena w.

Primero see lee el cabezal; si es blanco entonces lo marca con # y se mueve a la izquierda tantas veces como encuentre algo distinto a #. Si encuentra un blanco lo marca con otro #. Luego, cambia su dirección leyendo todo hacia la derecha. Llegado un blanco, se reemplaza por un · y así sucesivamente hasta encontrar la entrada w.

1. Ya que el camino fue marcado con #, una vez que llegue a la entrada w hay que borrar toda la huella de # y direccionarse a la entrada.

2. La entrada puede estar a izquierda o derecha.

3. Si el primer estado de todos q'0 lee la entrada (es decir, no un blanco) se moverá a la izquierda tantas veces como sea necesario para llegar al principio de la entrada.

# Probar que para toda máquina de Turing M del modelo original, existe una máquina de Turing M' equivalente con la restricción que no puede cambiar el símbolo de la cinta y mover el cabezal simultáneamente, es decir:

δ'(qi , ak) = (qj, al, X), si ak ≠ al entonces X=S

Dada una MT (M) existe M=< Q, Σ, Γ, g , q0, F > una MT arbitraria del modelo estándar. M' se contruye tal que L(M) es igual a L(M')

M' = < q', Σ, Γ, g' , q0, f > Q' = Q U {q'0, q'1, q'n} o todos los estados intermedios de Q. de forma que g: Q' x Γ --> Q' x Γ x {R, L ,S}

si δ(qi, ak) => (qj, al, X) con ak, al ∈ Γ : ak = al; X ∈ {R, L, S}<br>
se define tanto en M como en M'

ahora si δ'(qi, ak) => (qj, al, X) siendo ak != al y X ∈ {R, L} le agregamos las transiciones:

δ'(qi, ak) => (q'i, al, X) siendo X ∈ {S}

δ'(q'i, al )=> (qj, al , Y ) siendo Y ∈ {D I} donde es equivalente a la MT M
