PROGRAM e7;
USES Crt;

type 
	Car = record
		linea: Integer;
		car: Integer;
		recaudacionMes: Integer;
    end;
	   
    CarsFileT = file of Car;


procedure Import(var a: CarsFileT; var t: text);
var 
    rec: Car;
begin
    Reset(t);
    Rewrite(a);
    
    while NOT EOF(t) do
    begin
        ReadLn(t, rec.linea, rec.car, rec.recaudacionMes);
        Write(a, rec);
    end;

    Close(a);
    Close(t);
end;

procedure Report(var a: CarsFileT);
var
    rec: Car;
    cocheMayorRecaudacion, mayorRecaudacion, linea: Integer;
    lineaMayorRecaudacion, lineaRecaudacion: Integer;
    totalLinea, totalCoches, totalEmpresa, cantLineas: Integer;
begin
    cantLineas := 0;
    lineaRecaudacion := 0;
    totalEmpresa := 0;

    Reset(a);
    Read(a, rec);
    while rec.linea <> -1 do begin
        mayorRecaudacion := 0;
        totalLinea := 0;
        totalCoches := 0;
        linea := rec.linea;
        Writeln;
        Writeln('Numero de Linea: ', linea);
        
        while (rec.linea = linea) AND (rec.linea <> -1) do
        begin
            if rec.recaudacionMes > mayorRecaudacion then
            begin
                mayorRecaudacion := rec.recaudacionMes;
                cocheMayorRecaudacion := rec.car;
            end;

            totalCoches := totalCoches + 1;
            totalLinea := totalLinea + rec.recaudacionMes;
            Read(a, rec);
        
        end;
        
        if totalLinea > lineaRecaudacion then
        begin
            lineaRecaudacion := totalLinea;
            lineaMayorRecaudacion := linea;
        end;
        
        totalEmpresa := totalEmpresa + totalLinea;
        cantLineas := cantLineas + 1;
        
        Writeln('Total recaudado por la linea: $', totalLinea);
        Writeln('Promedio de recaudacion: $', totalLinea DIV totalCoches);
        Writeln('Coche de mayor recaudacion n°: ', cocheMayorRecaudacion, ' $', mayorRecaudacion);
    end;

    Writeln;
    Writeln('La Linea con mayor recaudacion es: ', lineaMayorRecaudacion, ' $', lineaRecaudacion);
    Writeln('Total recaudado por la empresa $', totalEmpresa);
    Writeln('Recaudacion promedio de las lineas: $', totalEmpresa DIV cantLineas);
end;

VAR	
	fileName: String;
	t: text;
	a: CarsFileT ;
BEGIN
	Writeln;
	Write('Enter the file name: ');
    ReadLn(fileName);
	Assign(t, fileName);
	Assign(a, 'Car.bin');
	Import(a, t);
	Report(a);
END.