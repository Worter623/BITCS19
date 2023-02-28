object logactorform: Tlogactorform
  Left = 0
  Top = 0
  Caption = #24405#20837#26032#28436#21592
  ClientHeight = 231
  ClientWidth = 471
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 64
    Top = 64
    Width = 85
    Height = 19
    Caption = #28436#21592#22995#21517#65306
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 64
    Top = 122
    Width = 85
    Height = 19
    Caption = #20986#29983#26085#26399#65306
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object name: TEdit
    Left = 155
    Top = 63
    Width = 217
    Height = 25
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -14
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ParentShowHint = False
    ShowHint = False
    TabOrder = 0
  end
  object Button1: TButton
    Left = 124
    Top = 172
    Width = 81
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
    TabOrder = 1
    OnClick = Button1Click
  end
  object birthday: TEdit
    Left = 155
    Top = 121
    Width = 217
    Height = 25
    Hint = #21487#19981#22635#65292#36755#20837#26684#24335#20026#24180'-'#26376'-'#26085
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
    Left = 277
    Top = 172
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
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=SQLOLEDB.1;Password=supreme,;Persist Security Info=True' +
      ';User ID=sa;Initial Catalog=bit_pc;Data Source=LAPTOP-7O733H1T\B' +
      'ITPC'
    LoginPrompt = False
    Provider = 'SQLOLEDB.1'
    Left = 24
    Top = 160
  end
  object DataSource1: TDataSource
    Left = 96
    Top = 160
  end
  object MyADOq: TADOQuery
    Connection = ADOConnection1
    DataSource = DataSource1
    Parameters = <>
    Left = 408
    Top = 104
  end
end
