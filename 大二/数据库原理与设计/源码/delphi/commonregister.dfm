object commonregisterform: Tcommonregisterform
  Left = 0
  Top = 0
  ActiveControl = Edit1
  Caption = #29992#25143#27880#20876#39029#38754
  ClientHeight = 231
  ClientWidth = 401
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
    Left = 48
    Top = 32
    Width = 51
    Height = 19
    Caption = #36134#21495#65306
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label1: TLabel
    Left = 48
    Top = 69
    Width = 68
    Height = 19
    Caption = #36134#25143#21517#65306
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 48
    Top = 109
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
  object Label4: TLabel
    Left = 48
    Top = 143
    Width = 51
    Height = 19
    Caption = #23494#30721#65306
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Button1: TButton
    Left = 168
    Top = 182
    Width = 73
    Height = 33
    Caption = #30830#23450
    DoubleBuffered = False
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = #26041#27491#20848#20141#32454#40657'_GBK'
    Font.Style = []
    ParentDoubleBuffered = False
    ParentFont = False
    TabOrder = 0
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 128
    Top = 31
    Width = 217
    Height = 25
    Hint = #36755#20837'10'#20301#25968#23383
    BiDiMode = bdLeftToRight
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -14
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentBiDiMode = False
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 1
  end
  object Edit2: TEdit
    Left = 128
    Top = 68
    Width = 217
    Height = 25
    Hint = #20165#25903#25345'12'#20301#21450#20197#19979#20013'/'#33521#25991#23383#31526
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
  object Edit3: TEdit
    Left = 128
    Top = 108
    Width = 217
    Height = 25
    Hint = #36755#20837#26684#24335#20026#24180'-'#26376'-'#26085
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -14
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 3
  end
  object Edit4: TEdit
    Left = 128
    Top = 143
    Width = 217
    Height = 25
    Hint = '6'#20301'-12'#20301#65292#20165#25903#25345#33521#25991#23383#31526#21644#29305#27530#23383#31526
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -14
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 4
  end
  object MyADOq: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    Left = 360
    Top = 136
  end
  object DataSource1: TDataSource
    DataSet = MyADOq
    Left = 72
    Top = 184
  end
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=SQLOLEDB.1;Password=supreme,;Persist Security Info=True' +
      ';User ID=sa;Initial Catalog=bit_pc;Data Source=LAPTOP-7O733H1T\B' +
      'ITPC;Use Procedure for Prepare=1;Auto Translate=True;Packet Size' +
      '=4096;Workstation ID=LAPTOP-7O733H1T;Use Encryption for Data=Fal' +
      'se;Tag with column collation when possible=False'
    LoginPrompt = False
    Provider = 'SQLOLEDB.1'
    Left = 16
    Top = 176
  end
  object ADOTable1: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    MasterSource = DataSource1
    TableName = 'users'
    Left = 312
    Top = 184
  end
end
