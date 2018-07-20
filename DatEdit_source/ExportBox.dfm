object ExportBox: TExportBox
  Left = 386
  Top = 88
  BorderStyle = bsDialog
  Caption = 'Export files...'
  ClientHeight = 285
  ClientWidth = 306
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
  PixelsPerInch = 96
  TextHeight = 13
  object Label3: TLabel
    Left = 6
    Top = 12
    Width = 162
    Height = 13
    Caption = 'Select the files you want to export:'
  end
  object Label1: TLabel
    Left = 6
    Top = 28
    Width = 34
    Height = 13
    Caption = 'File list:'
  end
  object Label2: TLabel
    Left = 193
    Top = 28
    Width = 48
    Height = 13
    Caption = 'Export list:'
  end
  object ExportOK: TButton
    Left = 73
    Top = 254
    Width = 75
    Height = 25
    Caption = '&OK'
    TabOrder = 4
    OnClick = ExportOKClick
  end
  object ExportCancel: TButton
    Left = 154
    Top = 254
    Width = 75
    Height = 25
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 5
  end
  object FileList: TListBox
    Left = 4
    Top = 42
    Width = 110
    Height = 149
    Color = clBlack
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ItemHeight = 13
    MultiSelect = True
    ParentFont = False
    TabOrder = 0
  end
  object ExportList: TListBox
    Left = 193
    Top = 42
    Width = 110
    Height = 149
    Color = clBlack
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ItemHeight = 13
    MultiSelect = True
    ParentFont = False
    TabOrder = 3
  end
  object AddToExportList: TButton
    Left = 116
    Top = 42
    Width = 75
    Height = 25
    Caption = 'Add ->'
    TabOrder = 1
    OnClick = AddToExportListClick
  end
  object RemoveFromExportList: TButton
    Left = 116
    Top = 70
    Width = 75
    Height = 25
    Caption = '<- Remove'
    TabOrder = 2
    OnClick = AddToExportListClick
  end
  object ExportOptions: TGroupBox
    Left = 4
    Top = 194
    Width = 300
    Height = 53
    Caption = 'Export As:'
    TabOrder = 6
    object Label4: TLabel
      Left = 180
      Top = 0
      Width = 70
      Height = 13
      Caption = 'Export options:'
    end
    object ExportAsMPQ: TRadioButton
      Left = 8
      Top = 14
      Width = 69
      Height = 17
      Caption = 'MPQ file'
      Checked = True
      TabOrder = 0
      TabStop = True
      OnClick = ExportAsMPQClick
    end
    object ExportAsEXE: TRadioButton
      Left = 8
      Top = 30
      Width = 169
      Height = 17
      Caption = 'Self-executable StarCraft patch'
      TabOrder = 1
      OnClick = ExportAsMPQClick
    end
    object KeepExportList: TCheckBox
      Left = 180
      Top = 16
      Width = 111
      Height = 17
      Caption = 'Keep the export list'
      TabOrder = 2
    end
  end
end
