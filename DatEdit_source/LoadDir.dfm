object OpenDirBox: TOpenDirBox
  Left = 762
  Top = 323
  BorderStyle = bsDialog
  Caption = 'Load Directory'
  ClientHeight = 275
  ClientWidth = 274
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poScreenCenter
  OnKeyDown = FormKeyDown
  OnShow = FormShow
  DesignSize = (
    274
    275)
  PixelsPerInch = 96
  TextHeight = 13
  object OpenDirText: TLabel
    Left = 4
    Top = 9
    Width = 188
    Height = 13
    Caption = 'Select a directory with DAT files to load:'
  end
  object OpenDirView: TDirectoryListBox
    Left = 4
    Top = 48
    Width = 260
    Height = 165
    ItemHeight = 16
    TabOrder = 1
    OnChange = OpenDirViewChange
  end
  object OpenDirOK: TButton
    Left = 57
    Top = 241
    Width = 75
    Height = 25
    Anchors = []
    Caption = '&OK'
    TabOrder = 3
    OnClick = OpenDirOKClick
  end
  object OpenDirCancel: TButton
    Left = 150
    Top = 241
    Width = 75
    Height = 25
    Anchors = []
    Caption = '&Cancel'
    TabOrder = 4
    OnClick = OpenDirCancelClick
  end
  object OpenDirDrive: TDriveComboBox
    Left = 4
    Top = 26
    Width = 260
    Height = 19
    DirList = OpenDirView
    TabOrder = 0
  end
  object OpenDirLabel: TEdit
    Left = 4
    Top = 216
    Width = 260
    Height = 21
    TabOrder = 2
  end
end
