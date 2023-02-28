unit masterregister;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, DB, ADODB;

type
  Tmasterregisterform = class(TForm)
    Edit1: TEdit;
    Label2: TLabel;
    Label1: TLabel;
    Edit2: TEdit;
    Label3: TLabel;
    Label4: TLabel;
    Edit4: TEdit;
    Label5: TLabel;
    Edit5: TEdit;
    Button1: TButton;
    ADOConnection1: TADOConnection;
    MyADOq: TADOQuery;
    Edit3: TEdit;
    ADOTable1: TADOTable;
    DataSource1: TDataSource;
    procedure Button1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  masterregisterform: Tmasterregisterform;

implementation
uses common;
{$R *.dfm}
var
  key:string='admin';
procedure Tmasterregisterform.Button1Click(Sender: TObject);
begin
  if not SameStr(Edit5.Text,key) then
  Application.MessageBox('抱歉，许可密钥错误。','提示',mb_ok)
  else
  begin
    MYADOQ.SQL.Clear;//清空SQL
    MYADOQ.SQL.Text:='select * from users where id = :admid' ;
    MYADOQ.Parameters.ParamByName('admid').Value:=Edit1.Text;
    MYADOQ.Open;
    if ADOTable1.Locate('id',edit1.Text,[loCaseInsensitive]) then
     Application.MessageBox('此账号已经存在，请重新输入。','提示',mb_ok)
    else
    begin
      MYADOQ.close;
      MYADOQ.SQL.Clear;
      MYADOQ.SQL.Text:='insert into users values( '''+Edit1.text+''',1,'''+Edit2.Text+''','''+Edit4.text+''','''+Edit3.text+''')';
      MYADOQ.ExecSQL;
      if MessageDlg('注册成功，请关闭窗口，返回登录界面进行登录',mtConfirmation,[mbYes,mbno],0)=mryes then
      Self.Close;
    end
  end;
  MYADOQ.SQL.Clear;
  self.CloseQUERY;
  edit1.Clear;
  edit2.Clear;
  edit3.Clear;
  edit4.Clear;
  edit5.Clear;
end;

end.
