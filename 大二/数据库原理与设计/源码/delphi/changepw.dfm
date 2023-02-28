object changepwform: Tchangepwform
  Left = 0
  Top = 0
  Caption = #23494#30721#20462#25913#31383#21475
  ClientHeight = 256
  ClientWidth = 423
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
    Left = 80
    Top = 56
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
    Left = 80
    Top = 96
    Width = 68
    Height = 19
    Caption = #26087#23494#30721#65306
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 80
    Top = 136
    Width = 68
    Height = 19
    Caption = #26032#23494#30721#65306
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Edit2: TEdit
    Left = 145
    Top = 55
    Width = 208
    Height = 25
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -14
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object Edit3: TEdit
    Left = 145
    Top = 95
    Width = 208
    Height = 25
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -14
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
  end
  object Edit4: TEdit
    Left = 145
    Top = 135
    Width = 208
    Height = 25
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -14
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
  end
  object Button1: TButton
    Left = 176
    Top = 179
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
    TabOrder = 3
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
    Left = 24
    Top = 40
  end
  object DataSource1: TDataSource
    Left = 32
    Top = 184
  end
  object MyADOq: TADOQuery
    Connection = ADOConnection1
    DataSource = DataSource1
    Parameters = <>
    Left = 376
    Top = 40
  end
end
