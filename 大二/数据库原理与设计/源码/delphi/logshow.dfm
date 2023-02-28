object logshowform: Tlogshowform
  Left = 0
  Top = 0
  Caption = #24405#20837#28436#20986#20449#24687
  ClientHeight = 276
  ClientWidth = 439
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label2: TLabel
    Left = 56
    Top = 24
    Width = 85
    Height = 19
    Caption = #28436#20986#26102#38388#65306
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label1: TLabel
    Left = 56
    Top = 61
    Width = 85
    Height = 19
    Caption = #28436#20986#22320#28857#65306
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 56
    Top = 98
    Width = 51
    Height = 19
    Caption = #31080#20215#65306
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 56
    Top = 135
    Width = 85
    Height = 19
    Caption = #28436#20986#21517#31216#65306
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label5: TLabel
    Left = 56
    Top = 172
    Width = 68
    Height = 19
    Caption = #24635#31080#25968#65306
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object showtime: TEdit
    Left = 136
    Top = 23
    Width = 217
    Height = 25
    Hint = #36755#20837#26684#24335#20026#24180'-'#26376'-'#26085' '#26102':'#20998#65292#27880#24847#20351#29992#33521#25991#23383#31526
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -14
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 0
  end
  object showplace: TEdit
    Left = 136
    Top = 60
    Width = 217
    Height = 25
    Hint = #36755#20837#22478#24066
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -14
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 1
  end
  object Edit4: TEdit
    Left = 136
    Top = 135
    Width = 217
    Height = 25
    Hint = #21487#19981#22635
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
  object showticket: TEdit
    Left = 136
    Top = 171
    Width = 217
    Height = 25
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -14
    Font.Name = 'Tahoma'
    Font.Style = []
    NumbersOnly = True
    ParentFont = False
    TabOrder = 3
  end
  object Button1: TButton
    Left = 120
    Top = 217
    Width = 80
    Height = 37
    Caption = #30830#23450
    DoubleBuffered = False
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = #26041#27491#20848#20141#32454#40657'_GBK'
    Font.Style = []
    ParentDoubleBuffered = False
    ParentFont = False
    TabOrder = 4
    OnClick = Button1Click
  end
  object showprice: TEdit
    Left = 136
    Top = 97
    Width = 217
    Height = 25
    Hint = #25972#25968
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -14
    Font.Name = 'Tahoma'
    Font.Style = []
    NumbersOnly = True
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 5
  end
  object exitt: TButton
    Left = 273
    Top = 217
    Width = 80
    Height = 37
    Caption = #36864#20986
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = #26041#27491#20848#20141#32454#40657'_GBK'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
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
    Left = 24
    Top = 96
  end
  object DataSource1: TDataSource
    Left = 56
    Top = 216
  end
  object MyADOq: TADOQuery
    Connection = ADOConnection1
    DataSource = DataSource1
    Parameters = <>
    Left = 400
    Top = 104
  end
end
