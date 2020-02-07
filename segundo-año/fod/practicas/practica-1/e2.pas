PROGRAM exer2;
USES crt;
TYPE
    IntegersFileT = file of Integer;

procedure PrintEvenOddAmount(var integersFile: IntegersFileT);
var
    number, even, odd: Integer;
begin
    Reset(integersFile);

    even := 0; odd := 0;


    while NOT EOF(integersFile) do
    begin
        Read(integersFile, number);
        if number MOD 2 = 0 then
            even := even + 1
        else
            odd := odd + 1;
    end;

    WriteLn('Odd Integers: ', odd);
    WriteLn('Even Integers: ', even);

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
    PrintEvenOddAmount(integersFile);  
END.