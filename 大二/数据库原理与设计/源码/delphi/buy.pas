unit buy;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, Grids, DBGrids, DB, ADODB;

type
  Tbuyform = class(TForm)
    MyADOq: TADOQuery;
    ADOConnection1: TADOConnection;
    DataSource1: TDataSource;
    GroupBox1: TGroupBox;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    Label5: TLabel;
    showplace: TEdit;
    earlytime: TEdit;
    latetime: TEdit;
    moreprice: TEdit;
    lessprice: TEdit;
    GroupBox2: TGroupBox;
    DBGrid1: TDBGrid;
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    adoqtemp: TADOQuery;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  buyform: Tbuyform;

implementation
 uses common,purchase;
{$R *.dfm}

procedure Tbuyform.Button1Click(Sender: TObject);
begin
  earlytime.Clear;
  latetime.Clear;
  moreprice.Clear;
  lessprice.Clear;
  showplace.Clear;
  self.Close;
end;

procedure Tbuyform.Button2Click(Sender: TObject);
var
  ssql:string;
begin
  ssql:='select "演出地点"=place,"演出时间"=showtime,"演出票价"=price,"总票数"=ticket,';
  ssql:=ssql+'"余票"=case when buystatus=1 then ticket-sum(number) else ticket end,"演出名称"=title,"标识id"=id';
  ssql:=ssql+'  from shows left join sells on pid=id  ';
  ssql:=ssql+' group by ticket,place,showtime,title,price,buystatus,id having 1=1 ';
  if not ((showplace.Text='') and (earlytime.Text='') and (latetime.Text='') and (moreprice.Text='') and (lessprice.Text='')) then
  begin
    if showplace.Text<>'' then
      ssql:=ssql+'and place='''+showplace.Text+''' ';
    if earlytime.Text<>'' then
      ssql:=ssql+'and showtime <='''+earlytime.Text+''' ';
    if latetime.Text<>'' then
      ssql:=ssql+'and showtime >='''+latetime.Text+''' ';
    if lessprice.Text<>'' then
      ssql:=ssql+'and price <='''+lessprice.Text+''' ';
    if moreprice.Text<>'' then
      ssql:=ssql+'and price >='''+moreprice.Text+''' ';
  end;
   ssql:=ssql+' order by showtime';
   myadoq.Close;
   myadoq.SQL.Clear;
   myadoq.SQL.Text:=ssql;
   myadoq.ExecSQL;
   myadoq.Open;
   myadoq.First;
end;

procedure Tbuyform.Button3Click(Sender: TObject);
var bno,left:integer;
    seq:string;
begin
  bno:=myadoq.FieldByName('标识id').AsInteger;
  left:=myadoq.FieldByName('余票').AsInteger;
  if bno=0 then
    application.MessageBox('请先选中一条记录','提示',mb_ok)
  else
  begin
    adoqtemp.close;
    adoqtemp.SQL.Clear;
    if inputquery('请输入购票数量','（整数）：',seq) then
    begin
      if strtoint(seq)<0 then
        messagedlg('你必须输入0以上的整数，购买失败。',mtinformation,[mbyes,mbno],0)
      else
      begin
        if strtoint(seq)>left then
            messagedlg('你购买的票超过了余票数，购买失败。',mtinformation,[mbyes,mbno],0)
        else
        begin
          adoqtemp.SQL.Text:='insert into sells values(:a,:p,:s,1)';
          adoqtemp.Parameters.ParamByName('a').Value:=common.accountid;
          adoqtemp.Parameters.ParamByName('p').Value:=bno;
          adoqtemp.Parameters.ParamByName('s').Value:=seq;
          adoqtemp.ExecSQL;
          if messagedlg('购票成功！是否要跳转到购票记录查询页面？',mtinformation,[mbyes,mbno],0)=mryes then
            purchaseform.Show;
        end;
      end;
    end;
  end;
end;

end.
