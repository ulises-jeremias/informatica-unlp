PROGRAM exer2;
USES crt;
TYPE
    IntegersFileT = file of Integer;

procedure PrintFile(var integersFile: IntegersFileT);
var
    number: Integer;
begin
    Reset(integersFile);

    while NOT EOF(integersFile) do
    begin
        Read(integersFile, number);
        WriteLn(number);
    end;

    Close(integersFile);
end;

VAR
    integersFile: IntegersFileT;
    fileName: String;
BEGIN
    ClrScr;
    Write('Enter the file name: ');
    ReadLn(fileName);
    Assign(integersFile, fileName);
    PrintFile(integersFile);  
END.