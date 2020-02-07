PROGRAM exer4;
USES crt;
TYPE
    NumbersFileT = file of Real;

function avg(sum: Real; count: Integer): Real;
begin
    if count = 0 then
        avg := 0
    else
        avg := sum / count;
end;

procedure CreateAndFillFile(var numbersFile: NumbersFileT);
var
    total, i: Integer;
    number: Real;
begin
    repeat
        Write('Enter a positive number: ');
        ReadLn(total);
        if total < 0 then WriteLn('the input value is lower than zero');
    until (total >= 0);

    Rewrite(numbersFile);
    
    for i := total downto 0 do
    begin
        Write('Enter a Real number: ');
        ReadLn(number);
        Write(numbersFile, number);
    end;

    Close(numbersFile);
end;

procedure ShowFileContent(var numbersFile: NumbersFileT);
var
    number: Real;
    i: Integer;
begin
    Reset(numbersFile);

    while NOT EOF(numbersFile) do
    begin
        for i := 1 to 10 do
        begin
            if NOT EOF(numbersFile) then
            begin
                Read(numbersFile, number);
                Write(number:2:3, ' ');
            end;

            WriteLn();
        end;
    end;

    Close(numbersFile);
end;

procedure ShowStats(var numbersFile: NumbersFileT);
var
    number, negativesSum, positivesSum: Real;
    negativesCount, positivesCount: Integer;
begin
    negativesSum := 0; negativesCount := 0;
    positivesSum := 0; positivesCount := 0;

    Reset(numbersFile);

    while NOT EOF(numbersFile) do
    begin
        Read(numbersFile, number);

        if number < 0 then
        begin
            negativesSum := negativesSum + number;
            negativesCount := negativesCount + 1;
        end
        else begin
            positivesSum := positivesSum + number;
            positivesCount := positivesCount + 1;
        end;
    end;

    WriteLn('Negatives count: ', negativesCount, ' - mean: ', avg(negativesSum, negativesCount));
    WriteLn('Positives count: ', positivesCount, ' - mean: ', avg(positivesSum, positivesCount));
    WriteLn('Total count: ', negativesCount + positivesCount, ' - mean: ',
            avg(negativesSum + positivesSum, negativesCount + positivesCount));

    Close(numbersFile);
end;


VAR
    numbersFile: NumbersFileT;
    fileName: String;
    option: Byte;
BEGIN
    Write('Enter the file name: ');
    ReadLn(fileName);
    Assign(numbersFile, fileName);

    repeat
        ClrScr;
        WriteLn('1. Create file'); 
        WriteLn('2. List numbers. Group by 10'); 
        WriteLn('3. List negatives ammount, negatives mean and total mean');
        WriteLn();
        Write('Option: ');
        ReadLn(option);
        WriteLn ('');
        
        ClrScr;
        case option of 
            1: CreateAndFillFile(numbersFile);
            2: ShowFileContent(numbersFile);
            3: ShowStats(numbersFile);
        end;
        ClrScr;
    until (option = 0);
END.
