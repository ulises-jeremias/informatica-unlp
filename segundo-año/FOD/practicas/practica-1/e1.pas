PROGRAM exer1;
USES crt;

TYPE

IntegersFileT = file of Integer; 

VAR
    fileName: String;
    number: Integer;
    integersFile: IntegersFileT;
BEGIN
    ClrScr;
    Write('Enter the file name: ');
    ReadLn(fileName);
    Assign(integersFile, fileName);
    Reset(integersFile);
    
    Write('Enter a number: ');
    ReadLn(number);
    while number <> 0 do
    begin
        Write(integersFile, number);
        Write('Enter a number: ');
        ReadLn(number);
    end;

    Close(integersFile);
END.