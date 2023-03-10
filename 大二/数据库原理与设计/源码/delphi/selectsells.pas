unit selectsells;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, Buttons, DB, ADODB, Grids, DBGrids;

type
  Tselectsellsform = class(TForm)
    DBGrid1: TDBGrid;
    ADOConnection1: TADOConnection;
    MyADOq: TADOQuery;
    DataSource1: TDataSource;
    BitBtn1: TBitBtn;
    time: TEdit;
    Label1: TLabel;
    exitt: TButton;
    changeperform: TButton;
    ADOTable1: TADOTable;
    myado: TADOQuery;
    Button1: TButton;
    procedure BitBtn1Click(Sender: TObject);
    procedure changeperformClick(Sender: TObject);
    procedure exittClick(Sender: TObject);
    procedure Button1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  selectsellsform: Tselectsellsform;

implementation
uses sequence,common;
{$R *.dfm}

procedure Tselectsellsform.BitBtn1Click(Sender: TObject);
var truetime:string;
begin
   myadoq.Close;
   myadoq.SQL.Clear;
   if time.Text='' then
    truetime:='1991.1.1'
   else
    truetime:=time.Text;
   myadoq.SQL.Text:='exec select_sells :ehhh';
   MYADOQ.Parameters.ParamByName('ehhh').Value:=truetime;
   myadoq.Open;
   myadoq.First;
end;

procedure Tselectsellsform.Button1Click(Sender: TObject);
var
  bno:integer;
begin
  bno:=myadoq.FieldByName('标识id').AsInteger;
  ppid:=bno;
  if ppid=0 then
    application.MessageBox('请先选中一条记录','提示',mb_ok)
  else
    sequenceform.show;
end;

procedure Tselectsellsform.changeperformClick(Sender: TObject);
var
  bname:variant;
  bno,truetime:string;
begin
  bno:=myadoq.FieldByName('标识id').AsString;
  if bno='' then
    application.MessageBox('请先选中一条记录','提示',mb_ok)
  else
  begin
    myado.SQL.Clear;
    myado.Close;
    myado.SQL.Text:='select * from shows where id= :ehh';
    MYADO.Parameters.ParamByName('ehh').Value:=bno;
    myado.Open;
    bname:=myado.Lookup('id',bno,'title');
    showmessage('此场演出名称为： '+bname);
    if messagedlg('确定要删除它吗？',mtinformation,[mbyes,mbno],0)=mryes then
    begin
      myado.SQL.Clear;
      myado.SQL.Text:='delete from shows where id= :ehh';
      MYADO.Parameters.ParamByName('ehh').Value:=bno;
      myado.ExecSQL;
      MessageDlg('删除成功',mtConfirmation,[mbYes,mbno],0);
      myadoq.Close;
      myadoq.SQL.Clear;
      if time.Text='' then
        truetime:='1991.1.1'
      else
        truetime:=time.Text;
      myadoq.SQL.Text:='exec select_sells :ehhh';
      MYADOQ.Parameters.ParamByName('ehhh').Value:=truetime;
      myadoq.Open;
      myadoq.First;
    end;
  end;
end;

procedure Tselectsellsform.exittClick(Sender: TObject);
begin
  self.Close;
end;

end.
