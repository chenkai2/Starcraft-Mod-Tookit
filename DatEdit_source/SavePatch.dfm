object PatchSaveForm: TPatchSaveForm
  Left = 425
  Top = 180
  BorderIcons = []
  BorderStyle = bsSingle
  Caption = 'Self-Executing Patch Setup...'
  ClientHeight = 251
  ClientWidth = 362
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 7
    Top = 5
    Width = 300
    Height = 13
    Caption = 
      'Plugins used:   (if you don'#39't know what they are, just click "OK' +
      '")'
  end
  object QDPList: TListBox
    Left = 9
    Top = 51
    Width = 348
    Height = 164
    AutoComplete = False
    Color = clBlack
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ItemHeight = 13
    ParentFont = False
    TabOrder = 3
  end
  object AddQDP: TButton
    Left = 8
    Top = 22
    Width = 75
    Height = 27
    Caption = 'Add'
    TabOrder = 0
    OnClick = AddQDPClick
  end
  object ConfigQDP: TButton
    Left = 85
    Top = 22
    Width = 75
    Height = 27
    Caption = 'Configure'
    TabOrder = 1
    OnClick = ConfigQDPClick
  end
  object RemoveQDP: TButton
    Left = 162
    Top = 22
    Width = 75
    Height = 27
    Caption = 'Remove'
    TabOrder = 2
    OnClick = RemoveQDPClick
  end
  object PatchSetupOK: TButton
    Left = 140
    Top = 221
    Width = 75
    Height = 25
    Caption = 'OK'
    ModalResult = 1
    TabOrder = 4
    OnClick = PatchSetupOKClick
  end
  object OFD: TOpenDialog
    Left = 317
    Top = 48
  end
end
