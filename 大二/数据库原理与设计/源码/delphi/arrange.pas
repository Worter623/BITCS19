unit arrange;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, Grids, DBGrids, DB, ADODB;

type
  Tarrangeform = class(TForm)
    ComboBox1: TComboBox;
    exitt: TButton;
    ADOConnection1: TADOConnection;
    DataSource1: TDataSource;
    MyADOq: TADOQuery;
    DBGrid1: TDBGrid;
    Label1: TLabel;
    Button1: TButton;
    Button2: TButton;
    myado: TADOQuery;
    procedure exittClick(Sender: TObject);
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure FormCreate(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  arrangeform: Tarrangeform;

implementation

{$R *.dfm}

procedure Tarrangeform.Button1Click(Sender: TObject);
var
  t:integer;
begin
   myadoq.Close;
   myadoq.SQL.Clear;
   if combobox1.ItemIndex=-1 then
   begin
    application.MessageBox('未选择月份，将显示所有演员生日及年龄。','提示',mb_ok);
    myadoq.SQL.Text:='exec select_birthday_null';
    myadoq.Open;
   end
   else
   begin
    t:= combobox1.ItemIndex+1;
    myadoq.SQL.Text:='exec select_birthday :b';
    MYADOQ.Parameters.ParamByName('b').Value:=t;
    myadoq.Open;
   end;
end;

procedure Tarrangeform.Button2Click(Sender: TObject);
var
  bno,bname:string;
begin
  bno:=myadoq.FieldByName('标识id').AsString;
  if bno='' then
    application.MessageBox('请先选中一条记录','提示',mb_ok)
  else
  begin
    myado.SQL.Clear;
    myado.Close;
    myado.SQL.Text:='select * from performer where id= :ehh';
    MYADO.Parameters.ParamByName('ehh').Value:=bno;
    myado.Open;
    bname:=myado.Lookup('id',bno,'pname');
    showmessage('要删除的演员名字为： '+bname);
    if messagedlg('确定要删除他吗？',mtinformation,[mbyes,mbno],0)=mryes then
    begin
      myado.SQL.Clear;
      myado.SQL.Text:='delete from performer where id= :ehh';
      MYADO.Parameters.ParamByName('ehh').Value:=bno;
      myado.ExecSQL;
      MessageDlg('删除成功',mtConfirmation,[mbYes,mbno],0);
      myadoq.Close;
      myadoq.SQL.Clear;
      myadoq.SQL.Text:='exec select_birthday_null';
      myadoq.Open;
    end;
  end;
end;

procedure Tarrangeform.exittClick(Sender: TObject);
begin
  self.Close;
end;

procedure Tarrangeform.FormCreate(Sender: TObject);
begin
  myado.Close;
  myado.SQL.Clear;
  myado.SQL.Text:='exec select_birthday_null';
  myado.Open;
end;

end.
