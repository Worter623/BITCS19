object purchaseform: Tpurchaseform
  Left = 0
  Top = 0
  ActiveControl = BitBtn1
  Caption = #29992#25143#36141#31080#35760#24405#26597#35810
  ClientHeight = 385
  ClientWidth = 712
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnShow = BitBtn1Click
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 248
    Top = 128
    Width = 36
    Height = 13
    Caption = #35831#36755#20837
  end
  object DBGrid1: TDBGrid
    Left = 8
    Top = 8
    Width = 696
    Height = 313
    DataSource = DataSource1
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
  end
  object BitBtn1: TBitBtn
    Left = 204
    Top = 340
    Width = 80
    Height = 37
    Caption = #26597#35810
    DoubleBuffered = True
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = #26041#27491#20848#20141#32454#40657'_GBK'
    Font.Style = []
    ParentDoubleBuffered = False
    ParentFont = False
    TabOrder = 1
    OnClick = BitBtn1Click
  end
  object exitt: TButton
    Left = 416
    Top = 340
    Width = 80
    Height = 37
    Caption = #36864#20986
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = #26041#27491#20848#20141#32454#40657'_GBK'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = exittClick
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
    Left = 392
    Top = 192
  end
  object MyADOq: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    Left = 400
    Top = 104
  end
  object DataSource1: TDataSource
    DataSet = MyADOq
    Left = 16
    Top = 80
  end
end
