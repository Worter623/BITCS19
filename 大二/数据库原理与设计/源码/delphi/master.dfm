object masterform: Tmasterform
  Left = 0
  Top = 0
  ActiveControl = selectsells
  Caption = #31649#29702#21592#31383#21475
  ClientHeight = 318
  ClientWidth = 569
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
    Left = 112
    Top = 48
    Width = 330
    Height = 38
    Caption = #23562#36149#30340#31649#29702#21592#65292#24744#22909#65281
    Font.Charset = GB2312_CHARSET
    Font.Color = clOlive
    Font.Height = -32
    Font.Name = #26041#27491#21326#38582'_GBK'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object change: TButton
    Left = 384
    Top = 216
    Width = 113
    Height = 41
    Caption = #20462#25913#23494#30721
    Font.Charset = GB2312_CHARSET
    Font.Color = clBlack
    Font.Height = -16
    Font.Name = #26041#27491#20848#20141#32454#40657'_GBK'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = changeClick
  end
  object logshow: TButton
    Left = 64
    Top = 216
    Width = 113
    Height = 41
    Caption = #24405#20837#28436#20986#20449#24687
    Font.Charset = GB2312_CHARSET
    Font.Color = clBlack
    Font.Height = -16
    Font.Name = #26041#27491#20848#20141#32454#40657'_GBK'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = logshowClick
  end
  object selectifo: TButton
    Left = 224
    Top = 128
    Width = 113
    Height = 41
    Caption = #26597#35810#28436#20986#20449#24687
    Font.Charset = GB2312_CHARSET
    Font.Color = clBlack
    Font.Height = -16
    Font.Name = #26041#27491#20848#20141#32454#40657'_GBK'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = selectifoClick
  end
  object selectsells: TButton
    Left = 64
    Top = 128
    Width = 113
    Height = 41
    Caption = #31649#29702#24050#26377#28436#20986
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = #26041#27491#20848#20141#32454#40657'_GBK'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = selectsellsClick
  end
  object Button1: TButton
    Left = 224
    Top = 216
    Width = 113
    Height = 41
    Caption = #24405#20837#26032#28436#21592
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = #26041#27491#20848#20141#32454#40657'_GBK'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 384
    Top = 128
    Width = 113
    Height = 41
    Caption = #31649#29702#24050#26377#28436#21592
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = #26041#27491#20848#20141#32454#40657'_GBK'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    OnClick = Button2Click
  end
end
