PROGRAM e910;
USES Crt;

TYPE
    Product = record
        code: Integer;
        name: String;
        currentStock: Integer;
        minStock: Integer;
        price: Real;
    end;

    ProductsFileT = file of Product;

procedure PrintProduct(var rec: Product);
begin
    with rec do
        WriteLn(code: 10, name: 20, currentStock: 10, minStock: 10, price: 10);
end; 

procedure ReadProduct(var rec: Product);
begin
    with rec do begin
        Write('Enter code: ');
        ReadLn(code);
        Write('Enter name: ');
        ReadLn(name);
        Write('Enter currentStock: ');
        ReadLn(currentStock);
        Write('Enter minStock: ');
        ReadLn(minStock);
        Write('Enter price: ');
        ReadLn(price);
        WriteLn();
    end;
end;

procedure CreateAndFillFile(var productsFile: ProductsFileT);
var
    rec: Product;
begin
    Rewrite(productsFile);

    ReadProduct(rec);
    while rec.code <> 0 do
    begin
        Write(productsFile, rec);
        ReadProduct(rec);
    end;

    Close(productsFile);
end;

procedure List(var productsFile: ProductsFileT);
var
    rec: Product;
begin
    Reset(productsFile);

    while NOT EOF(productsFile) do
    begin
        Read(productsFile, rec);
        if rec.currentStock < rec.minStock then PrintProduct(rec);
    end;

    Close(productsFile);
end;

procedure IncrementProducts(var productsFile: ProductsFileT);
var
    rec: Product;
begin
    Reset(productsFile);

    while NOT EOF(productsFile) do
    begin
        Read(productsFile, rec);
        if rec.currentStock < rec.minStock then
        begin
            Seek(productsFile, filepos(productsFile) - 1);
            rec.price := rec.price * 0.15;
            Write(productsFile, rec);
        end;
    end;

    Close(productsFile);
end;

VAR
    productsFile: ProductsFileT;
    fileName: String;
    option: Byte;
BEGIN
    Write('Enter the file name: ');
    ReadLn(fileName);
    Assign(productsFile, fileName);

    ClrScr;
    WriteLn('1. Create file'); 
    WriteLn('2. List products with stock under min stock');
    WriteLn('3. Increment 15%');
    WriteLn();
    Write('Option: ');
    ReadLn(option);

    case option of 
        1: CreateAndFillFile(productsFile);
        2: List(productsFile);
        3: IncrementProducts(productsFile);
    end;
END.