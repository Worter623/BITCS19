unit logshow;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, ADODB, DB, StdCtrls;

type
  Tlogshowform = class(TForm)
    showtime: TEdit;
    Label2: TLabel;
    Label1: TLabel;
    showplace: TEdit;
    Label3: TLabel;
    Label4: TLabel;
    Edit4: TEdit;
    Label5: TLabel;
    showticket: TEdit;
    Button1: TButton;
    ADOConnection1: TADOConnection;
    DataSource1: TDataSource;
    MyADOq: TADOQuery;
    showprice: TEdit;
    exitt: TButton;
    procedure Button1Click(Sender: TObject);
    procedure exittClick(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  logshowform: Tlogshowform;

implementation

{$R *.dfm}
var
  showid:integer;
procedure Tlogshowform.Button1Click(Sender: TObject);
begin
  MYADOQ.SQL.Clear;//清空SQL
  MYADOQ.SQL.Text:='select max(id) from shows' ;
  MYADOQ.Open;
  showid:=MyADOq.Fields[0].Asinteger+1;
  MYADOQ.close;
  MYADOQ.SQL.Clear;//清空SQL
  MYADOQ.SQL.Text:='insert into shows values( :ehhh,'''+showtime.Text+''','''+showplace.Text+''','''+showprice.Text+''','''+Edit4.Text+''','''+showticket.Text+''')';
  MYADOQ.Parameters.ParamByName('ehhh').Value:=showid;
  MYADOQ.ExecSQL;
  if MessageDlg('录入成功，关闭界面。',mtConfirmation,[mbYes,mbno],0)=mryes then
  Self.Close;
  MYADOQ.SQL.Clear;
  self.CloseQUERY;
  showtime.Clear;
  showplace.Clear;
  showticket.Clear;
  showprice.Clear;
  edit4.Clear;
end;

procedure Tlogshowform.exittClick(Sender: TObject);
begin
  self.Close;
end;

end.
