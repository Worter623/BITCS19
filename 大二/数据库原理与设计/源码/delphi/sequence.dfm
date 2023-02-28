object sequenceform: Tsequenceform
  Left = 0
  Top = 0
  Caption = #23433#25490#28436#20986#19978#22330#27425#24207
  ClientHeight = 471
  ClientWidth = 671
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 328
    Top = 296
    Width = 31
    Height = 13
    Caption = 'Label1'
  end
  object Label2: TLabel
    Left = 33
    Top = 121
    Width = 36
    Height = 13
    Caption = #28436#21592#34920
  end
  object Label3: TLabel
    Left = 314
    Top = 122
    Width = 60
    Height = 13
    Caption = #28436#20986#39034#24207#21333
  end
  object DBGrid1: TDBGrid
    Left = 33
    Top = 140
    Width = 264
    Height = 257
    DataSource = DataSource2
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
  end
  object DBGrid2: TDBGrid
    Left = 303
    Top = 141
    Width = 322
    Height = 257
    DataSource = DataSource3
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
  end
  object exitt: TButton
    Left = 405
    Top = 415
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
    OnClick = exittClick
  end
  object Button1: TButton
    Left = 189
    Top = 415
    Width = 80
    Height = 37
    Caption = #19978#22330#27425#24207
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = #26041#27491#20848#20141#32454#40657'_GBK'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = Button1Click
  end
  object GroupBox1: TGroupBox
    Left = 33
    Top = 21
    Width = 601
    Height = 95
    Caption = #24403#21069#27491#22312#24405#20837#30340#28436#20986
    TabOrder = 2
    object DBGrid3: TDBGrid
      Left = 13
      Top = 21
      Width = 577
      Height = 60
      DataSource = DataSource1
      TabOrder = 0
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -11
      TitleFont.Name = 'Tahoma'
      TitleFont.Style = []
    end
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
    Left = 560
    Top = 96
  end
  object DataSource1: TDataSource
    DataSet = adoqifo
    Left = 8
    Top = 24
  end
  object adoqifo: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    Left = 8
    Top = 72
  end
  object ADOQper: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    Left = 80
    Top = 384
  end
  object DataSource2: TDataSource
    DataSet = ADOQper
    Left = 32
    Top = 416
  end
  object ADOqse: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    Left = 560
    Top = 376
  end
  object DataSource3: TDataSource
    DataSet = myado
    Left = 496
    Top = 408
  end
  object myado: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    Left = 336
    Top = 304
  end
end
