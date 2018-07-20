object MergeDialog: TMergeDialog
  Left = 460
  Top = 82
  BorderIcons = []
  BorderStyle = bsDialog
  Caption = 'Merge source'
  ClientHeight = 123
  ClientWidth = 300
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 300
    Height = 123
    Align = alClient
    TabOrder = 0
    object Label1: TLabel
      Left = 8
      Top = 4
      Width = 241
      Height = 13
      Caption = 'Which file do you want the data to be loaded from?'
      WordWrap = True
    end
    object SourceOk: TButton
      Left = 216
      Top = 90
      Width = 75
      Height = 25
      Caption = 'OK'
      ModalResult = 6
      TabOrder = 4
    end
    object PropertyInfo: TListView
      Left = 8
      Top = 20
      Width = 284
      Height = 37
      Color = clBlack
      Columns = <
        item
          Caption = 'Property'
          MaxWidth = 130
          MinWidth = 130
          Width = 130
        end
        item
          Caption = 'File1'
          MaxWidth = 50
          MinWidth = 50
        end
        item
          Caption = 'File2'
          MaxWidth = 50
          MinWidth = 50
        end
        item
          Caption = 'Default'
          MaxWidth = 50
          MinWidth = 50
        end>
      ColumnClick = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      GridLines = True
      ReadOnly = True
      ParentFont = False
      TabOrder = 0
      ViewStyle = vsReport
    end
    object SourceFile1: TRadioButton
      Left = 8
      Top = 58
      Width = 113
      Height = 17
      Caption = 'Use data from File1'
      Checked = True
      TabOrder = 1
      TabStop = True
      OnClick = SourceFile1Click
    end
    object SourceFile2: TRadioButton
      Left = 8
      Top = 78
      Width = 113
      Height = 17
      Caption = 'Use data from File2'
      TabOrder = 2
      OnClick = SourceFile2Click
    end
    object SourceDefault: TRadioButton
      Left = 8
      Top = 98
      Width = 105
      Height = 17
      Caption = 'Use default data'
      TabOrder = 3
      OnClick = SourceDefaultClick
    end
  end
end
