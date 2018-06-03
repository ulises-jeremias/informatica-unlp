#include <stdio.h>
#include <stdlib.h>


double dwalltime(){
        double sec;
        struct timeval tv;

        gettimeofday(&tv,NULL);
        sec = tv.tv_sec + tv.tv_usec/1000000.0;
        return sec;
}

void inicializar(double* v, unsigned long N){
        unsigned long i;
        for(i=1; i<(N+1); i++)
                v[i-1] = i*0.33;
}

double min(double* v, unsigned long N){
        unsigned long i;
        double min = v[0];

        for(i=1; i<N; i++) {
                if (v[i]<min)
                        min = v[i];
        }

        return min;
}

double max(double* v, unsigned long N){
        unsigned long i;
        double max = v[0];

        for(i=1; i<N; i++) {
                if (v[i]>max)
                        max = v[i];
        }

        return max;
}

double promedio(double* v, unsigned long N){
        unsigned long i;
        double suma = 0;

        for(i=0; i<N; i++)
                suma += v[i];

        return suma/N;
}



int main(int argc, char* argv[]){
        unsigned long N = atol(argv[1]);
        printf("Calculando para %lu \n",N);
        double* v;
        double resultado;
        double timetick;

        v = (double*)malloc(N*sizeof(double));

        inicializar(v,N);

        timetick = dwalltime();
        resultado = (max(v,N)-min(v,N))/promedio(v,N);
        printf("Tiempo en segundos %f\n", dwalltime() - timetick);
        printf("%f\n",resultado);

        free(v);
        return 0;
}
