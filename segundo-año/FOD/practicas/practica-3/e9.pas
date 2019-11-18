PROGRAM e9;
USES Crt;

TYPE
	MedicineT = record
        name: String;
        description: String;
        stock: Integer;
    end;

    MedicinesFileT = file;

procedure Create(var a: MedicinesFileT);
var
    rec: MedicineT;
    fieldDelimiter, recDelitimier:char;
begin
    fieldDelimiter := '@';
    recDelitimier := '#';
    Rewrite(a, 1);

    Write('Ingrese nombre: ');
    ReadLn(rec.name);

    repeat
        Write('Descripcion: '); ReadLn(rec.description);
        Write('Stock: '); ReadLn(rec.stock);
        Writeln;
        
        BlockRead(a, rec.name, Length(rec.name) + 1);
        BlockRead(a, fieldDelimiter, 1);
        BlockRead(a, rec.description, Length(rec.description) + 1); 
        BlockRead(a, fieldDelimiter, 1);
        BlockRead(a, rec.stock, SizeOf(rec.stock) + 1); 
        BlockRead(a, recDelitimier, 1);
        
        Write('Ingrese name: ');
        ReadLn(rec.name);
    until rec.name = '';

    Close(a);
end;

procedure Iterate(var a: MedicinesFileT);
var
    buffer, field: String;
begin
    Reset(a,1);

    while NOT EOF(a) do begin
        BlockRead(a, buffer, 1);
        Write(buffer);

        while (buffer <> '#') AND (NOT EOF(a)) do begin
            field := '';
            while (buffer <> '@') AND (buffer <> '#') AND (NOT EOF(a)) do
            begin
                field := field + buffer;
                BlockRead(a, buffer, 1);
            end;

            Write(field, ' ');
            if NOT EOF(a) then BlockRead(a, buffer, 1);
        end;
    end;

    Close(a);
end;


VAR
	a: MedicinesFileT;
    option: Byte;
BEGIN
    Assign(a, 'medicines.txt');
    Write('Ingrese opción: ');
    ReadLn(option);

    case option of
        1: Create(a);
        2: Iterate(a);
    end;
END.