object selectsellsform: Tselectsellsform
  Left = 0
  Top = 0
  ActiveControl = BitBtn1
  Caption = #26597#35810#21806#31080#24773#20917
  ClientHeight = 424
  ClientWidth = 732
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
    Left = 80
    Top = 26
    Width = 119
    Height = 19
    Caption = #26597#35810#26102#38388#26202#20110#65306
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object DBGrid1: TDBGrid
    Left = 8
    Top = 65
    Width = 716
    Height = 274
    DataSource = DataSource1
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
  end
  object BitBtn1: TBitBtn
    Left = 503
    Top = 20
    Width = 80
    Height = 37
    Caption = #24320#22987#26597#35810
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
  object time: TEdit
    Left = 205
    Top = 25
    Width = 260
    Height = 25
    Hint = #21487#19981#22635#65292#22635#20889#26684#24335#20026#24180'-'#26376'-'#26085
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -14
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 2
  end
  object exitt: TButton
    Left = 503
    Top = 359
    Width = 113
    Height = 41
    Caption = #36864#20986
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = #26041#27491#20848#20141#32454#40657'_GBK'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = exittClick
  end
  object changeperform: TButton
    Left = 304
    Top = 359
    Width = 113
    Height = 41
    Caption = #21024#38500#27492#26465#28436#20986
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = #26041#27491#20848#20141#32454#40657'_GBK'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = changeperformClick
  end
  object Button1: TButton
    Left = 112
    Top = 359
    Width = 113
    Height = 41
    Caption = #23433#25490#19978#22330#27425#24207
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = #26041#27491#20848#20141#32454#40657'_GBK'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    OnClick = Button1Click
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
    Left = 664
    Top = 24
  end
  object MyADOq: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    Left = 24
    Top = 96
  end
  object DataSource1: TDataSource
    DataSet = MyADOq
    Left = 24
    Top = 16
  end
  object ADOTable1: TADOTable
    Connection = ADOConnection1
    MasterSource = DataSource1
    TableName = 'shows'
    Left = 624
    Top = 216
  end
  object myado: TADOQuery
    Connection = ADOConnection1
    DataSource = DataSource1
    Parameters = <>
    Left = 160
    Top = 176
  end
end
