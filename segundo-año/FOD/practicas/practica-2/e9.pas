PROGRAM e9;
USES Crt;
CONST BIG_VALUE = 999;
TYPE
    EmployeeT = record
        apartment: Integer;
        division: Integer;
        number: Integer;
        category: Integer;
        hours: Integer;
    end;

    HourValueArrayT = array [1..15] of Real;
    EmployeesFileT = file of EmployeeT;

procedure Import(var a: EmployeesFileT; var t: Text);
var
    rec: EmployeeT;
begin
    Reset(t);
    Rewrite(a);

    while NOT EOF(t) do
    begin
        ReadLn(t, rec.apartment, rec.division, rec.number, rec.category, rec.hours);
        Write(a, rec);
    end;

    Close(a);
    Close(t);
end;

procedure LoadArray(var hours: HourValueArrayT; var arrayFileText: Text);
var
    i: Integer;
    value: Real;
begin
    Reset(arrayFileText);

    for i := 1 to 15 do
    begin
        ReadLn(arrayFileText, value);
        hours[i] := value;
    end;

    Close(arrayFileText);
end;

procedure ReadEmployee(var employeesFile: EmployeesFileT; var rec: EmployeeT);
begin
    if NOT EOF(employeesFile) then Read(employeesFile, rec)
    else rec.apartment := BIG_VALUE;
end;

procedure List(var a: EmployeesFileT; var hours: HourValueArrayT);
var
    rec: EmployeeT;
    division, totalHoursDiv: Integer;
    totalAmountDiv, totalAmountApartment: Real;
    apartment, totalHoursApartment: Integer;
    amount: Real; 
begin
    Reset(a);
    ReadEmployee(a, rec);

    while rec.apartment <> BIG_VALUE do
    begin
        apartment := rec.apartment;
        totalHoursApartment := 0;
        totalAmountApartment := 0;

        WriteLn('APARTMENT ', apartment);
        while (apartment = rec.apartment) AND (rec.apartment <> BIG_VALUE) do
        begin
            division := rec.division;
            totalAmountDiv := 0;
            totalHoursDiv := 0;

            WriteLn('Division ', division);

            while (division = rec.division) AND (apartment = rec.apartment) AND (rec.apartment <> BIG_VALUE) do
            begin
                amount := rec.hours * hours[rec.category];
                WriteLn('Employee: ', rec.number: 10, '      Total hours: ', rec.hours: 6, '     Amount: ', amount:2:2);
                totalHoursDiv := totalHoursDiv + rec.hours;
                totalAmountDiv := totalAmountDiv + amount;
                ReadEmployee(a, rec);
            end;

            Writeln('Total division hours: ', totalHoursDiv);
            writeln('Total amount per division: ', totalAmountDiv:2:2);
            totalHoursApartment := totalHoursApartment + totalHoursDiv;
            totalAmountApartment := totalAmountApartment + totalAmountDiv;
        end;

        Writeln('Total apartment hours: ', totalHoursApartment);
        Writeln('Total apartment amount: ', totalAmountApartment:2:2);
    end;

    Close(a);
end;

VAR
    fileName: String;
    arrayFileText, employeesFileText: Text;
    employeesFile: EmployeesFileT;
    hours: HourValueArrayT;
BEGIN
    Write('Name of array txt file: ');
    ReadLn(fileName);
	Assign(arrayFileText, fileName);
	LoadArray(hours , arrayFileText);
	
	Write('Name of employees txt file: ');
    ReadLn(fileName);
	Assign(employeesFileText,fileName);
	Assign(employeesFile, 'empleados.bin');
	
    Import(employeesFile, employeesFileText);
	List(employeesFile, hours);
END.