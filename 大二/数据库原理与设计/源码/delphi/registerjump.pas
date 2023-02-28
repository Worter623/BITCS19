unit registerjump;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls;

type
  Tregisterjumpform = class(TForm)
    ComboBox1: TComboBox;
    Button1: TButton;
    procedure Button1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  registerjumpform: Tregisterjumpform;

implementation
uses masterregister,commonregister;
{$R *.dfm}

procedure Tregisterjumpform.Button1Click(Sender: TObject);
begin
  case combobox1.ItemIndex of
      -1:
          application.MessageBox('请选择注册用户类型！','提示',mb_ok);
      0:
          masterregisterform.show;
      1:
          commonregisterform.show;
    end;
end;

end.
