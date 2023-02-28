unit login;
  //1
interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, DB, ADODB, StdCtrls, ExtCtrls;

type
  Tloginform = class(TForm)
    GroupBox1: TGroupBox;
    ADOConnection1: TADOConnection;
    ADOTable1: TADOTable;
    RadioGroup1: TRadioGroup;
    DataSource1: TDataSource;
    Button1: TButton;
    Button2: TButton;
    Label1: TLabel;
    Label2: TLabel;
    Edit1: TEdit;
    Edit2: TEdit;
    ADOQuery1: TADOQuery;
    procedure Button2Click(Sender: TObject);
    procedure Button1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  loginform: Tloginform;

implementation
uses registerjump,master,users,common;
{$R *.dfm}
var
  time:Integer=0;
procedure Tloginform.Button1Click(Sender: TObject);
  var
    str,temp:string;
    results:variant;
begin
    ADOTable1.Active:=true;
    Adoquery1.SQL.Clear;//清空SQL
    Adoquery1.SQL.Add('Select * from users ');//添加SQL
    Adoquery1.Open;
    ADOquery1.Active:=true;
    str:=Edit1.Text;
    results:=ADOTable1.Lookup('id',edit1.Text,'pw');
    if edit1.Text='' then
      begin
        Application.MessageBox('账号不能为空！','提示',mb_ok);
        edit1.SetFocus;
      end
    else if not ADOTable1.Locate('id',str,[loCaseInsensitive]) then
    begin
        application.MessageBox('账号不存在！','提示',mb_ok);
        edit1.Text:='';
        edit2.Text:='';
        edit1.SetFocus;
    end
    else if edit2.Text='' then application.MessageBox('密码不能为空！','提示',mb_ok)
    else if (results=edit2.Text) then
    begin
      case RadioGroup1.ItemIndex of    //RadioGroup的使用方法
        -1:
            application.MessageBox('请选择用户类型！','提示',mb_ok);
        0:
            begin
            temp:=ADOQuery1.Lookup('id',edit1.Text,'typeid');
            if temp='1' then
            begin
              accounttype:=temp;
              common.accountid:=Edit1.Text;  //记录当前账号1551！！！
              masterform.show;
            end
            else
              application.MessageBox('您不是管理员','提示',mb_ok)
            end;
        1:
            begin
            temp:=ADOQuery1.Lookup('id',edit1.Text,'typeid');
            if temp='2' then
            begin
              accounttype:=temp;
              common.accountid:=Edit1.Text;  //记录当前账号1551！！！
              usersform.show;
            end
            else
              application.MessageBox('您不是普通用户','提示',mb_ok)
            end;
      end;
    end
    else
      begin
        time:=time+1;
        if time<3 then
          begin
            showmessage('密码错误，请重新输入！');
            edit2.Text:='';
            edit2.SetFocus;
          end
        else
        begin
          messageDlg('对不起，密码输入错误达到3次！退出系统。',mtInformation,[mbok],0);
          application.Terminate;
        end;
    end;


end;

procedure Tloginform.Button2Click(Sender: TObject);
begin
  registerjumpform.Show;
end;


end.
