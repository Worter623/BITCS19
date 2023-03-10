unit changepw;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ADODB, DB;

type
  Tchangepwform = class(TForm)
    Label2: TLabel;
    Edit2: TEdit;
    Edit3: TEdit;
    Label1: TLabel;
    Label3: TLabel;
    Edit4: TEdit;
    Button1: TButton;
    ADOConnection1: TADOConnection;
    DataSource1: TDataSource;
    MyADOq: TADOQuery;
    procedure Button1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  changepwform: Tchangepwform;

implementation
uses common;
{$R *.dfm}

procedure Tchangepwform.Button1Click(Sender: TObject);
begin
  MYADOQ.SQL.Clear;//清空SQL
  MYADOQ.SQL.Text:='select * from users where id = :admid' ;
  MYADOQ.Parameters.ParamByName('admid').Value:=Edit2.Text;
  MYADOQ.Open;
  if MyAdoq['pw']=null then
   ShowMessage('您输入的账号不存在，请重新输入')
  else
    begin
      if MyAdoq['pw']<>Edit3.Text then ShowMessage('原密码不对，请重新输入')
      else
      begin
        if Edit3.Text = Edit4.Text then ShowMessage('新密码不可以跟原密码设置一样')
        else
          if Edit4.Text <> Edit3.text then
          begin
            MYADOQ.close;
            MYADOQ.SQL.Clear;
            MYADOQ.SQL.Text:='update users set pw = '''+Edit4.text+''' where id ='''+Edit2.text+''' and pw = '''+Edit3.text+'''';
            MYADOQ.ExecSQL;
            if MessageDlg('重置成功，是否关闭窗口',mtConfirmation,[mbYes,mbno],0)=mryes then
            Self.Close;
          end;
      end;
    end;

  MYADOQ.SQL.Clear;
  self.CloseQUERY;
  edit2.Clear;
  edit3.Clear;
  edit4.Clear;
end;

end.
