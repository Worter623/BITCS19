object selectshowform: Tselectshowform
  Left = 0
  Top = 0
  ActiveControl = Button2
  Caption = #26597#35810#28436#20986#20449#24687
  ClientHeight = 477
  ClientWidth = 708
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnShow = Button2Click
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 673
    Height = 97
    Caption = #26816#32034#26465#20214
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 26
      Width = 75
      Height = 14
      Caption = #28436#20986#22320#28857#65306
      Font.Charset = GB2312_CHARSET
      Font.Color = clOlive
      Font.Height = -14
      Font.Name = #23435#20307
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 429
      Top = 24
      Width = 105
      Height = 17
      Caption = #28436#20986#26102#38388#26202#20110#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clOlive
      Font.Height = -14
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label3: TLabel
      Left = 207
      Top = 24
      Width = 105
      Height = 17
      Caption = #28436#20986#26102#38388#26089#20110#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clOlive
      Font.Height = -14
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label4: TLabel
      Left = 207
      Top = 60
      Width = 105
      Height = 17
      Caption = #28436#20986#31080#20215#20302#20110#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clOlive
      Font.Height = -14
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label5: TLabel
      Left = 16
      Top = 60
      Width = 105
      Height = 17
      Caption = #28436#20986#31080#20215#39640#20110#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clOlive
      Font.Height = -14
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object showplace: TEdit
      Left = 97
      Top = 21
      Width = 96
      Height = 25
      TabOrder = 0
    end
    object earlytime: TEdit
      Left = 310
      Top = 21
      Width = 113
      Height = 25
      TabOrder = 1
    end
    object latetime: TEdit
      Left = 534
      Top = 21
      Width = 113
      Height = 25
      TabOrder = 2
    end
    object moreprice: TEdit
      Left = 118
      Top = 58
      Width = 75
      Height = 25
      TabOrder = 3
    end
    object lessprice: TEdit
      Left = 310
      Top = 58
      Width = 113
      Height = 25
      TabOrder = 4
    end
  end
  object GroupBox2: TGroupBox
    Left = 8
    Top = 122
    Width = 673
    Height = 295
    Caption = #26816#32034#32467#26524
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
  end
  object DBGrid1: TDBGrid
    Left = 24
    Top = 144
    Width = 641
    Height = 257
    DataSource = DataSource1
    TabOrder = 2
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
  end
  object Button1: TButton
    Left = 303
    Top = 432
    Width = 80
    Height = 37
    Caption = #36864#20986
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = #26041#27491#20848#20141#32454#40657'_GBK'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 528
    Top = 63
    Width = 80
    Height = 31
    Caption = #26597#35810
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = #26041#27491#20848#20141#32454#40657'_GBK'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = Button2Click
  end
  object MyADOq: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    Left = 232
    Top = 432
  end
  object ADOConnection1: TADOConnection
    ConnectionString = 
      'Provider=SQLOLEDB.1;Password=supreme,;Persist Security Info=True' +
      ';User ID=sa;Initial Catalog=bit_pc;Data Source=LAPTOP-7O733H1T\B' +
      'ITPC;Use Procedure for Prepare=1;Auto Translate=True;Packet Size' +
      '=4096;Workstation ID=LAPTOP-7O733H1T;Use Encryption for Data=Fal' +
      'se;Tag with column collation when possible=False'
    LoginPrompt = False
    Provider = 'SQLOLEDB.1'
    Left = 120
    Top = 416
  end
  object DataSource1: TDataSource
    DataSet = MyADOq
    Left = 616
    Top = 432
  end
end
