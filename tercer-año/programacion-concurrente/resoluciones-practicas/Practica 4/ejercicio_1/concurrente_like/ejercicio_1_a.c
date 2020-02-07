#define N 105
#define TIME 10

chan request_n(int*);
chan request_c(int*);
chan request_a(int*);

chan renturn_request(char*);

chan response_n[1..N](char*);
chan response_c[1..N](char*);
chan response_a[1..N](char*);

Process Abuela
{
        int c = 10, n = 15;
        int child;
        while (true) {
                if (!empty(request_c) && c--) -> {
                        receive request_c(&child);
                        send response_c[child]("C");
                } [](!empty(request_n) && n--) -> {
                        receive request_n(&child);
                        send response_n[child]("N");
                } [](!empty(request_a) && (c + n)) -> {
                        char pencil = get_any_pencil();
                        receive request_a(&child);
                        send response_a[child](&char);
                        pencil == 'C' ? c-- : n--;
                } [](!empty(return_request)) -> {
                        char pencil;
                        receive return_request(&pencil);
                        pencil == 'C' ? c++ : n++
                }
        }
}

Process Child_N[i = 1..N]
{
        char pencil;
        while (true) {
                send request_n(&i);
                recieve response_n[i](&pencil);
                delay(TIME * 60);
                return_request(pencil);
        }
}

Process Child_C[i = 1..N]
{
        char pencil;
        while (true) {
                send request_c(&i);
                recieve response_c[i](&pencil);
                delay(TIME * 60);
                return_request(pencil);
        }
}

Process Child_A[i = 1..N]
{
        char pencil;
        while (true) {
                send request_a(&i);
                recieve response_a[i](&pencil);
                delay(TIME * 60);
                return_request(&pencil);
        }
}
