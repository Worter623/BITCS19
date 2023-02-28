unit purchase;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, Buttons, Grids, DBGrids, DB, ADODB;

type
  Tpurchaseform = class(TForm)
    Label1: TLabel;
    ADOConnection1: TADOConnection;
    MyADOq: TADOQuery;
    DataSource1: TDataSource;
    DBGrid1: TDBGrid;
    BitBtn1: TBitBtn;
    exitt: TButton;
    procedure BitBtn1Click(Sender: TObject);
    procedure exittClick(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  purchaseform: Tpurchaseform;

implementation
uses common;

{$R *.dfm}

procedure Tpurchaseform.BitBtn1Click(Sender: TObject);
begin
   myadoq.Close;
   myadoq.SQL.Clear;
   myadoq.SQL.Text:='select username as "用户名",place as "演出地点",showtime as "演出时间",title as "演出名称",price as "演出票价",number as "购票数量" from sells left join users on aid=users.id left join shows on pid=shows.id where buystatus=1 and aid=:ehhh';
   MYADOQ.Parameters.ParamByName('ehhh').Value:=accountid;
   myadoq.Open;
   myadoq.First;
end;

procedure Tpurchaseform.exittClick(Sender: TObject);
begin
  self.Close;
end;

end.
