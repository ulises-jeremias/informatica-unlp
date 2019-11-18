PROGRAM e3;
USES Crt;
CONST BIG_VALUE = 9999;
TYPE
    ProductT = record
        code: Integer;
        name: String;
        amount: Integer;
        min: Integer;
        max: Integer;
        price: Real; 
    end;

    ProductsFileT = file of ProductT;

procedure ReadProduct(var a: ProductsFileT; var rec: ProductT);
begin
    if NOT EOF(a) then Read(a, rec)
    else rec.code := BIG_VALUE;
end;

procedure LoadProduct(var rec: ProductT);
begin
    with rec do
    begin
        Write('Nombre :');
        ReadLn(name);
        if name <> '' then
        begin
            Write('Codigo: ');
            ReadLn(code);
			Write('Cantidad actual: ');
            ReadLn(amount);
			Write('Cantidad minima: ');
            ReadLn(min);
			Write('Cantidad maxima: ');
            ReadLn(max);
			Write('Precio: ');
            ReadLn(price);
        end;
    end;
end;

procedure LoadWithHeader(var a: ProductsFileT);
var
    rec: ProductT;
begin
    ReWrite(a);
    rec.code := 0;
    Write(a, rec);
    ReadLn();
    LoadProduct(rec);

    while rec.name <> '' do
    begin
        Write(a, rec);
        LoadProduct(rec);
    end;

    Close(a);
end;

procedure PrintData(var a: ProductsFileT);
var
    rec: ProductT;
begin
    Reset(a);
    ReadProduct(a, rec);

    while rec.code <> BIG_VALUE do
    begin
        Write(rec.name, ' ');
        Write(rec.code, ' ');
        Write(rec.amount, '  ');
        Write(rec.min, '  ');
        Write(rec.price:2:2, '  ');
        WriteLn(rec.max);
        ReadProduct(a, rec);
    end;

    Close(a);
end;

procedure Add(var a: ProductsFileT);
var 
	rec: ProductT;
	newRec: ProductT;
begin
    Reset(a);
    LoadProduct(newRec);
    Read(a, rec);		
    if rec.code <= -1 then
    begin
        Seek(a, rec.code * -1);
        ReadProduct(a, rec);
        Seek(a, FilePos(a) - 1);
        Write(a, newRec);
        Seek(a, 0);
        Write(a, rec);		
    end
    else begin
            Seek(a, FileSize(a));
            Write(a, newRec);
    end;

    Close(a);
end;

procedure Remove(var a: ProductsFileT);
var
    rec, header: ProductT;
    code: Integer;
begin
    Reset(a);
    
    Write('Ingrese código a borrar: ');
    ReadLn(code);

    ReadProduct(a, rec);
    header := rec;
    while (rec.code <> code) AND (rec.code <> BIG_VALUE) do ReadProduct(a, rec);

    if rec.code <> BIG_VALUE then
    begin
        Seek(a, FilePos(a) - 1);
        rec.code := filepos(a) * -1;
        Write(a, header);
        Seek(a, 0);
        Write(a, rec);
    end
    else WriteLn('No se encontró el producto');

    Close(a);
end;

procedure Update(var a: ProductsFileT);
var
	newRec, rec: ProductT;
begin
	Reset(a);
	ClrScr;
	WriteLn('Codigo de producto a modificar: ');
    ReadLn(newRec.code);

	ReadProduct(a, rec);
	while (rec.code <> newRec.code) AND (rec.code <> BIG_VALUE) do ReadProduct(a, rec);
	
	if rec.code <> BIG_VALUE then
    begin
		Seek(a, FilePos(a) - 1);
		Write('Nombre: ');
        Read(rec.name);
		Write('cantidad actual: ');
        ReadLn(rec.amount);
		Write('cantidad minima: ');
        ReadLn(rec.min);
		Write('cantidad maxima: ');
        ReadLn(rec.max);
		Write('precio: ');
        ReadLn(rec.price);
		Write(a, rec);
    end
	else WriteLn('no se encontro el código');

	Close(a);
end;

VAR
    option: Byte;
    fileName: String;
    productsFile: ProductsFileT;
BEGIN
    WriteLn('Menu:');
	WriteLn('1) Crear archivo y cargarlo.');
	WriteLn('2) Mantenimiento de archivo.');
	WriteLn('3) Recorrer archivo.');

	repeat 
        Write('Opcion: ');
        ReadLn(option);

        case option of 
            1: begin
                ClrScr;
                WriteLn('Ingrese nombre del archivo: ');
                Read(fileName);
                Assign(productsFile, fileName);
                LoadWithHeader(productsFile);
            end;
            2: begin
                ClrScr;
                WriteLn('Ingrese nombre del archivo a abrir: ');
                Read(fileName);
                Assign(productsFile, fileName);
                ClrScr;
                WriteLn('Menu Mantenimiento: ');
                WriteLn('1) alta');
                WriteLn('2) modificar datos');
                WriteLn('3) borrar dato');
                Write('Opcion : ');
                ReadLn(option);

                case option of 
                    1: Add(productsFile);
                    2: Update(productsFile);
                    3: Remove(productsFile);
                end;
            end;
            3: begin
                ClrScr;
                WriteLn('Ingrese nombre del archivo a recorrer: ');
                Read(fileName);
                Assign(productsFile, fileName);
                PrintData(productsFile);
            end;			
        end;
        ReadKey;
        ClrScr;
        WriteLn('Menu:');
        WriteLn('1) Crear archivo y cargarlo.');
        WriteLn('2) Mantenimiento de archivo.');
        WriteLn('3) Recorrer archivo.');
	until option = 0;
END.