object CompareFiles: TCompareFiles
  Left = 533
  Top = 83
  Width = 387
  Height = 580
  BiDiMode = bdLeftToRight
  BorderIcons = [biSystemMenu]
  Caption = 'Compare/Merge DAT Files'
  Color = clBtnFace
  Constraints.MinHeight = 378
  Constraints.MinWidth = 375
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  ParentBiDiMode = False
  Position = poMainFormCenter
  OnKeyDown = FormKeyDown
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object CompareFilesBox: TGroupBox
    Left = 0
    Top = 0
    Width = 379
    Height = 235
    Align = alTop
    Caption = 'Settings:'
    TabOrder = 0
    object LabelFile1: TLabel
      Left = 6
      Top = 42
      Width = 28
      Height = 13
      Caption = 'File 1:'
    end
    object LabelFile2: TLabel
      Left = 6
      Top = 100
      Width = 28
      Height = 13
      Caption = 'File 2:'
    end
    object Label1: TLabel
      Left = 56
      Top = 64
      Width = 75
      Height = 13
      Caption = 'Load File1 from:'
    end
    object Label2: TLabel
      Left = 56
      Top = 122
      Width = 75
      Height = 13
      Caption = 'Load File2 from:'
    end
    object Bevel1: TBevel
      Left = 46
      Top = 90
      Width = 300
      Height = 2
    end
    object BrowseFile1: TButton
      Left = 285
      Top = 62
      Width = 75
      Height = 21
      Caption = 'Browse...'
      TabOrder = 6
      OnClick = BrowseFileClick
    end
    object FileName1: TEdit
      Tag = -1
      Left = 36
      Top = 40
      Width = 325
      Height = 21
      Color = clBlack
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      OEMConvert = True
      ParentFont = False
      TabOrder = 3
    end
    object BrowseFile2: TButton
      Left = 285
      Top = 120
      Width = 75
      Height = 21
      Caption = 'Browse...'
      TabOrder = 10
      OnClick = BrowseFileClick
    end
    object ActionButton: TButton
      Left = 285
      Top = 12
      Width = 75
      Height = 25
      Caption = 'Compare!'
      TabOrder = 2
      OnClick = ActionButtonClick
    end
    object SetFile1ToCurrent: TButton
      Left = 132
      Top = 62
      Width = 75
      Height = 21
      Caption = 'Current DATs'
      TabOrder = 4
      OnClick = SetFile
    end
    object FileName2: TEdit
      Tag = -1
      Left = 36
      Top = 98
      Width = 325
      Height = 21
      Color = clBlack
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 7
    end
    object SetFile2ToDefault: TButton
      Left = 208
      Top = 120
      Width = 75
      Height = 21
      Caption = 'Default DATs'
      TabOrder = 9
      OnClick = SetFile
    end
    object SetFile2ToCurrent: TButton
      Left = 132
      Top = 120
      Width = 75
      Height = 21
      Caption = 'Current DATs'
      TabOrder = 8
      OnClick = SetFile
    end
    object SetFile1ToDefault: TButton
      Left = 208
      Top = 62
      Width = 75
      Height = 21
      Caption = 'Default DATs'
      TabOrder = 5
      OnClick = SetFile
    end
    object ActionCompare: TRadioButton
      Left = 36
      Top = 18
      Width = 87
      Height = 17
      Caption = 'Compare files'
      Checked = True
      TabOrder = 0
      TabStop = True
      OnClick = ActionCompareClick
    end
    object ActionMerge: TRadioButton
      Left = 132
      Top = 18
      Width = 73
      Height = 17
      Caption = 'Merge files'
      TabOrder = 1
      OnClick = ActionMergeClick
    end
    object MergeOptions: TGroupBox
      Left = 36
      Top = 144
      Width = 171
      Height = 84
      Caption = 'If both files have custom data:'
      TabOrder = 11
      object SourceDefault: TRadioButton
        Left = 8
        Top = 48
        Width = 109
        Height = 17
        Caption = 'Use default data'
        TabOrder = 2
      end
      object SourceAsk: TRadioButton
        Left = 8
        Top = 65
        Width = 79
        Height = 17
        Caption = 'Always ask'
        Checked = True
        TabOrder = 3
        TabStop = True
      end
      object SourceFile1: TRadioButton
        Left = 8
        Top = 14
        Width = 113
        Height = 17
        Caption = 'Use data from File1'
        TabOrder = 0
      end
      object SourceFile2: TRadioButton
        Left = 8
        Top = 31
        Width = 113
        Height = 17
        Caption = 'Use data from File2'
        TabOrder = 1
      end
    end
    object MergeResult: TGroupBox
      Left = 217
      Top = 144
      Width = 143
      Height = 71
      Caption = 'Merge output:'
      TabOrder = 12
      object TargetOther: TRadioButton
        Left = 8
        Top = 48
        Width = 123
        Height = 17
        Caption = 'Save as separate file'
        Checked = True
        TabOrder = 2
        TabStop = True
      end
      object TargetFile1: TRadioButton
        Left = 8
        Top = 14
        Width = 113
        Height = 17
        Caption = 'Overwrite File1'
        TabOrder = 0
      end
      object TargetFile2: TRadioButton
        Left = 8
        Top = 31
        Width = 113
        Height = 17
        Caption = 'Overwrite File2'
        TabOrder = 1
      end
    end
  end
  object CompareResult: TListView
    Left = 0
    Top = 237
    Width = 379
    Height = 315
    Align = alBottom
    Anchors = [akLeft, akTop, akRight, akBottom]
    Color = clBlack
    Columns = <
      item
        AutoSize = True
        Caption = 'Property Info'
        MinWidth = 200
      end
      item
        AutoSize = True
        Caption = 'File1'
        MinWidth = 50
      end
      item
        AutoSize = True
        Caption = 'File2'
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
    RowSelect = True
    ParentFont = False
    SmallImages = ImageList1
    StateImages = ImageList1
    TabOrder = 1
    ViewStyle = vsReport
  end
  object OpenDialog: TOpenDialog
    Tag = -1
    Filter = 'DAT files (*.dat)|*.dat|All files (*.*)|*.*'
    Title = 'Load File...'
    OnCanClose = OpenDialogCanClose
    Left = 44
    Top = 470
  end
  object ImageList1: TImageList
    Height = 1
    Width = 1
    Left = 12
    Top = 470
  end
  object List: TPopupMenu
    Tag = -1
    AutoPopup = False
    OnPopup = ListPopup
    Left = 76
    Top = 470
    object Units1: TMenuItem
      Tag = -1
      Caption = 'Units'
      RadioItem = True
      OnClick = DATListClickExecute
    end
    object Weapons1: TMenuItem
      Tag = -1
      Caption = 'Weapons'
      RadioItem = True
      OnClick = DATListClickExecute
    end
    object Flindy1: TMenuItem
      Tag = -1
      Caption = 'Flingy'
      RadioItem = True
      OnClick = DATListClickExecute
    end
    object Sprites1: TMenuItem
      Tag = -1
      Caption = 'Sprites'
      RadioItem = True
      OnClick = DATListClickExecute
    end
    object Images1: TMenuItem
      Tag = -1
      Caption = 'Images'
      RadioItem = True
      OnClick = DATListClickExecute
    end
    object Upgrades1: TMenuItem
      Tag = -1
      Caption = 'Upgrades'
      RadioItem = True
      OnClick = DATListClickExecute
    end
    object Tech1: TMenuItem
      Tag = -1
      Caption = 'Techs'
      RadioItem = True
      OnClick = DATListClickExecute
    end
    object Sounds1: TMenuItem
      Tag = -1
      Caption = 'Sounds'
      RadioItem = True
      OnClick = DATListClickExecute
    end
    object Portraits1: TMenuItem
      Tag = -1
      Caption = 'Portraits'
      RadioItem = True
      OnClick = DATListClickExecute
    end
    object Map1: TMenuItem
      Tag = -1
      Caption = 'Campaign'
      RadioItem = True
      OnClick = DATListClickExecute
    end
    object Orders1: TMenuItem
      Tag = -1
      Caption = 'Orders'
      RadioItem = True
      OnClick = DATListClickExecute
    end
  end
  object ActionList1: TActionList
    Left = 108
    Top = 470
    object DATListClick: TAction
      Caption = 'DATListClick'
      OnExecute = DATListClickExecute
    end
  end
  object SaveMergeResult: TSaveDialog
    Filter = 'DAT files (*.dat)|*.dat|All files (*.*)|*.*'
    Title = 'Save DAT merge result as...'
    OnCanClose = SaveMergeResultCanClose
    Left = 44
    Top = 502
  end
end
