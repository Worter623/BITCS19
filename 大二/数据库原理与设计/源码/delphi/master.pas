unit master;
  //1
interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls;

type
  Tmasterform = class(TForm)
    change: TButton;
    logshow: TButton;
    selectifo: TButton;
    selectsells: TButton;
    Label1: TLabel;
    Button1: TButton;
    Button2: TButton;
    procedure logshowClick(Sender: TObject);
    procedure selectifoClick(Sender: TObject);
    procedure selectsellsClick(Sender: TObject);
    procedure changeClick(Sender: TObject);
    procedure exittClick(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button1Click(Sender: TObject);
    private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  masterform: Tmasterform;

implementation
uses logshow,selectshow,selectsells,changepw,logactor,arrange;
{$R *.dfm}


procedure Tmasterform.logshowClick(Sender: TObject);
begin
  logshowform.Show;
end;

procedure Tmasterform.changeClick(Sender: TObject);
begin
  changepwform.Show;
end;

procedure Tmasterform.Button1Click(Sender: TObject);
begin
  logactorform.Show;
end;

procedure Tmasterform.Button2Click(Sender: TObject);
begin
   arrangeform.Show;
end;

procedure Tmasterform.exittClick(Sender: TObject);
begin
  application.Terminate;
end;

procedure Tmasterform.selectifoClick(Sender: TObject);
begin
  selectshowform.Show;
end;

procedure Tmasterform.selectsellsClick(Sender: TObject);
begin
  selectsellsform.Show;
end;


end.
