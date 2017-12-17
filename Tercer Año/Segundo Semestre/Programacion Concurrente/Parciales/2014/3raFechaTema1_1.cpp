sem countAccess = 1;
int counter = 128;

process Empleado[int i = 1..5]
{
        p(countAccess);
        while (counter) {
                counter--;
                v(countAccess);
                // trabajar
                p(countAccess);
        }
        v(countAccess);
}
