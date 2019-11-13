PROGRAM exer4;
USES Crt;
TYPE
    Person = record
        name: String;
        surname: String;
        birthdate: Integer;
    end;

    PeopleFileT = file of Person;

procedure PrintPerson(var rec: Person);
begin
    with rec do
        WriteLn(name: 20, surname: 10, birthdate: 10);
end; 

procedure ReadPerson(var rec: Person);
begin
    with rec do begin
        Write('Enter surname: ');
        readln(surname);
        Write('Enter name: ');
        readln(name);
        Write('Enter birthdate `yyyymmdd`: ');
        readln(birthdate);
        WriteLn();
    end;
end;

procedure CreateAndFillFile(var peopleFile: PeopleFileT);
var
    rec: Person;
begin
    Rewrite(peopleFile);

    ReadPerson(rec);
    while rec.surname <> '' do
    begin
        Write(peopleFile, rec);
        ReadPerson(rec);
    end;

    Close(peopleFile);
end;

procedure List(var peopleFile: PeopleFileT);
var
    rec: Person;
    month: Integer;
begin
    repeat
        Write('List people birth on month: ');
        ReadLn(month);
        if (month < 1) OR (month > 12) then WriteLn('the input value is out of range');
    until ((month >= 1) AND (month <= 12));

    Reset(peopleFile);

    while NOT EOF(peopleFile) do
    begin
        Read(peopleFile, rec);

        if month = ((rec.birthdate MOD 10000) DIV 100) then
        begin
            Write('Birth on month: ');
        end
        else if rec.birthdate = 0 then
        begin
            Write('Birthdate is empty: ');
        end;
    end;

    Close(peopleFile);
end;

procedure AddPeople(var peopleFile: PeopleFileT);
var
    rec: Person;
begin
    Reset(peopleFile);

    ReadPerson(rec);
    while rec.surname <> '' do
    begin
        Write(peopleFile, rec);
        ReadPerson(rec);
    end;

    Close(peopleFile);
end;

procedure Export(var peopleFile: PeopleFileT; var peopleTxt: text);
var
    rec: Person;
begin
    Rewrite(peopleTxt);
    Reset(peopleFile);
    Seek(peopleFile, filesize(peopleFile));

    while NOT EOF(peopleFile) do
    begin
        ReadPerson(rec);
        WriteLn(peopleTxt, rec.name);
        WriteLn(peopleTxt, rec.surname);
        WriteLn(peopleTxt, rec.birthdate);
    end;

    Close(peopleFile);
    Close(peopleTxt);
end;

VAR
    peopleFile: PeopleFileT;
    peopleTxt:text;
    fileName: String;
    option: Byte;
BEGIN
    Write('Enter the file name: ');
    ReadLn(fileName);
    Assign(peopleFile, fileName);
    Assign(peopleTxt, 'people.txt');

    repeat
        ClrScr;
        WriteLn('1. Create file'); 
        WriteLn('2. List data');
        WriteLn('3. Append people');
        WriteLn('5. Export');
        WriteLn();
        Write('Option: ');
        ReadLn(option);
        WriteLn ('');
        
        ClrScr;
        case option of 
            1: CreateAndFillFile(peopleFile);
            2: List(peopleFile);
            3: AddPeople(peopleFile);
            4: Export(peopleFile, peopleTxt);
        end;
        ClrScr;
    until (option = 0);
END.