unit users;
     //1
interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls;

type
  Tusersform = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Label1: TLabel;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  usersform: Tusersform;

implementation
uses buy,changepw,purchase;
{$R *.dfm}

procedure Tusersform.Button1Click(Sender: TObject);
begin
  buyform.Show;
end;

procedure Tusersform.Button2Click(Sender: TObject);
begin
  changepwform.Show;
end;

procedure Tusersform.Button3Click(Sender: TObject);
begin
  purchaseform.Show;
end;

end.
