unit sequence;
//10.195.118.68          10.195.98.132
interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, Grids, DBGrids, DB, ADODB;

type
  Tsequenceform = class(TForm)
    ADOConnection1: TADOConnection;
    DataSource1: TDataSource;
    adoqifo: TADOQuery;
    DBGrid1: TDBGrid;
    DBGrid2: TDBGrid;
    exitt: TButton;
    Button1: TButton;
    GroupBox1: TGroupBox;
    DBGrid3: TDBGrid;
    Label1: TLabel;
    ADOQper: TADOQuery;
    DataSource2: TDataSource;
    ADOqse: TADOQuery;
    DataSource3: TDataSource;
    myado: TADOQuery;
    Label2: TLabel;
    Label3: TLabel;
    procedure exittClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure Button1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  sequenceform: Tsequenceform;

implementation
uses selectsells,common;
{$R *.dfm}
var
  bno:integer=0;
procedure Tsequenceform.Button1Click(Sender: TObject);
var
  temp:integer;
  seq,bname:string;
begin
    bno:=adoqper.FieldByName('标识id').AsInteger;
    if bno=0 then
    application.MessageBox('请先选中一条记录','提示',mb_ok)
  else
  begin
    adoqse.SQL.Clear;
    adoqse.Close;
    adoqse.SQL.Text:='select * from performer where id= :num';
    adoqse.Parameters.ParamByName('num').Value:=bno;
    adoqse.Open;
    bname:=adoqse.Lookup('id',bno,'pname');
    showmessage('要上场的演员名字为： '+bname);
    if messagedlg('确定他要上场吗？',mtinformation,[mbyes,mbno],0)=mryes then
    begin
      if inputquery('请输入他的上场次序','（整数）：',seq) then
      begin
        adoqse.Close;
        adoqse.SQL.Clear;
        adoqse.SQL.Text:= 'select * from who_onshow';
        adoqse.Open;
        if adoqse.Locate('pid',ppid,[]) then
          temp:=adoqse.Lookup('pid',ppid,'onsequence')
        else
          temp:=0;
        if IntToStr(temp)=seq then
          application.MessageBox('这个位置已经有人啦！','提示',mb_ok)
        else
        begin
          adoqse.Close;
          adoqse.SQL.Clear;
          adoqse.SQL.Text:='insert into who_onshow values(:i,:num,:se)';
          adoqse.Parameters.ParamByName('i').Value:=ppid;
          adoqse.Parameters.ParamByName('num').Value:=bno;
          adoqse.Parameters.ParamByName('se').Value:=seq;
          adoqse.ExecSQL;
          application.MessageBox('插入成功！','提示',mb_ok);
        end;
      end;
      myado.Close;
      myado.SQL.Clear;
      myado.SQL.Text:='exec arrange_se :current_show';
      myado.Parameters.ParamByName('current_show').Value:=ppid;
      myado.Open;
    end;
  end;
end;


procedure Tsequenceform.exittClick(Sender: TObject);
begin
  self.Close;
end;

procedure Tsequenceform.FormCreate(Sender: TObject);
begin
  adoqifo.Close;
  adoqifo.SQL.Clear;
  adoqifo.SQL.Text:='exec show_ifo :i';
  adoqifo.Parameters.ParamByName('i').Value:=common.ppid;
  adoqifo.Open;
  adoqper.Close;
  adoqper.SQL.Clear;
  adoqper.SQL.Text:='exec select_birthday_null';
  adoqper.Open;
  myado.Close;
  myado.SQL.Clear;
  myado.SQL.Text:='exec arrange_se :current_show';
  myado.Parameters.ParamByName('current_show').Value:=ppid;
  myado.Open;
end;

end.
