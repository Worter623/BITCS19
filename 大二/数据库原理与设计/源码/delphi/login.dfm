object loginform: Tloginform
  Left = 0
  Top = 0
  ActiveControl = Button1
  Caption = #27426#36814#20351#29992#33073#21475#31168#28436#20986#31080#21153#31995#32479
  ClientHeight = 260
  ClientWidth = 472
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Visible = True
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 80
    Top = 79
    Width = 66
    Height = 25
    Caption = #36134#21495#65306
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 80
    Top = 129
    Width = 66
    Height = 25
    Caption = #23494#30721#65306
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object GroupBox1: TGroupBox
    Left = 48
    Top = 41
    Width = 377
    Height = 153
    Caption = #36755#20837#23494#30721#30331#24405
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object Button1: TButton
    Left = 128
    Top = 208
    Width = 97
    Height = 33
    Caption = #30331#24405
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
  object Button2: TButton
    Left = 288
    Top = 208
    Width = 97
    Height = 33
    Caption = #27880#20876
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = #26041#27491#20848#20141#32454#40657'_GBK'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = Button2Click
  end
  object Edit1: TEdit
    Left = 168
    Top = 74
    Width = 217
    Height = 21
    TabOrder = 3
  end
  object Edit2: TEdit
    Left = 168
    Top = 124
    Width = 217
    Height = 21
    TabOrder = 4
  end
  object RadioGroup1: TRadioGroup
    AlignWithMargins = True
    Left = 142
    Top = -16
    Width = 187
    Height = 41
    Margins.Left = 70
    Margins.Top = 0
    Margins.Right = 70
    Margins.Bottom = 0
    BiDiMode = bdLeftToRight
    Columns = 2
    DoubleBuffered = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'Tahoma'
    Font.Style = []
    Items.Strings = (
      '  '#31649#29702#21592
      '  '#26222#36890#29992#25143)
    ParentBiDiMode = False
    ParentDoubleBuffered = False
    ParentFont = False
    ParentShowHint = False
    ShowHint = False
    TabOrder = 5
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
    Top = 24
  end
  object ADOTable1: TADOTable
    Connection = ADOConnection1
    CursorType = ctStatic
    MasterSource = DataSource1
    TableName = 'users'
    Left = 16
    Top = 96
  end
  object DataSource1: TDataSource
    Left = 16
    Top = 160
  end
  object ADOQuery1: TADOQuery
    Connection = ADOConnection1
    DataSource = DataSource1
    Parameters = <>
    Left = 432
    Top = 40
  end
end
