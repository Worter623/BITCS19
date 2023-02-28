unit logactor;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, ADODB, DB, StdCtrls;

type
  Tlogactorform = class(TForm)
    Label1: TLabel;
    name: TEdit;
    Label3: TLabel;
    Button1: TButton;
    ADOConnection1: TADOConnection;
    DataSource1: TDataSource;
    MyADOq: TADOQuery;
    birthday: TEdit;
    exitt: TButton;
    procedure Button1Click(Sender: TObject);
    procedure exittClick(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  logactorform: Tlogactorform;

implementation

{$R *.dfm}

var
  showid:integer;

procedure Tlogactorform.Button1Click(Sender: TObject);
begin
  MYADOQ.SQL.Clear;//清空SQL
  MYADOQ.SQL.Text:='select max(id) from performer' ;
  MYADOQ.Open;
  showid:=MyADOq.Fields[0].Asinteger+1;
  MYADOQ.close;
  MYADOQ.SQL.Clear;//清空SQL
  MYADOQ.SQL.Text:='insert into performer values( :ehhh,'''+name.Text+''','''+birthday.Text+''')';
  MYADOQ.Parameters.ParamByName('ehhh').Value:=showid;
  MYADOQ.ExecSQL;
  if MessageDlg('录入成功，关闭界面。',mtConfirmation,[mbYes,mbno],0)=mryes then
  Self.Close;
  MYADOQ.SQL.Clear;
  self.CloseQUERY;
  name.Clear;
  birthday.Clear;
end;

procedure Tlogactorform.exittClick(Sender: TObject);
begin
  self.Close;
end;

end.
