object OptionsBox: TOptionsBox
  Left = 404
  Top = 84
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Options'
  ClientHeight = 306
  ClientWidth = 432
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnCreate = FormCreate
  OnKeyDown = FormKeyDown
  OnShow = FormShow
  DesignSize = (
    432
    306)
  PixelsPerInch = 96
  TextHeight = 13
  object OptionsTabs: TPageControl
    Left = 0
    Top = 0
    Width = 432
    Height = 306
    ActivePage = SettingsTab
    Align = alClient
    MultiLine = True
    RaggedRight = True
    TabIndex = 0
    TabOrder = 0
    object SettingsTab: TTabSheet
      Caption = 'Settings'
      object Label3: TLabel
        Left = 2
        Top = 198
        Width = 419
        Height = 39
        AutoSize = False
        Caption = 
          'Here you set various options (hover mouse for hints), clear the ' +
          'History list, reset the program'#39's window size to default or asso' +
          'ciate *.DAT files with DatEdit. You can also determine an extern' +
          'al MPQ archive to load the GRP Preview graphics from.'
        Color = clBtnFace
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentColor = False
        ParentFont = False
        WordWrap = True
      end
      object GenOptionsPanel: TGroupBox
        Left = 1
        Top = 1
        Width = 422
        Height = 134
        Caption = 'General Options:'
        TabOrder = 0
        object StartEditorLabel: TLabel
          Left = 8
          Top = 23
          Width = 36
          Height = 13
          Caption = 'Start in:'
        end
        object UnitSizeLabel: TLabel
          Left = 8
          Top = 115
          Width = 83
          Height = 13
          Caption = 'Unit size preview:'
        end
        object ConfirmOnExit: TCheckBox
          Left = 296
          Top = 50
          Width = 93
          Height = 17
          Hint = 'Display a confirmation box when closing the program.'
          Caption = 'Confirm on exit'
          Checked = True
          ParentShowHint = False
          ShowHint = True
          State = cbChecked
          TabOrder = 10
          OnClick = ConfirmOnExitClick
        end
        object UseBackwardReporting: TCheckBox
          Left = 162
          Top = 50
          Width = 113
          Height = 17
          Hint = 
            'Check for which other entries point to the currently selected en' +
            'try.'
          Caption = 'Use back-reporting'
          Checked = True
          Color = clBtnFace
          ParentColor = False
          ParentShowHint = False
          ShowHint = True
          State = cbChecked
          TabOrder = 7
          OnClick = UseBackwardReportingClick
        end
        object StartEditor: TComboBox
          Left = 46
          Top = 20
          Width = 107
          Height = 21
          AutoComplete = False
          Style = csDropDownList
          Color = clBlack
          DropDownCount = 11
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ItemHeight = 13
          ItemIndex = 0
          ParentFont = False
          TabOrder = 0
          Text = 'Units Editor'
          OnChange = StartEditorChange
          Items.Strings = (
            'Units Editor'
            'Weapons Editor'
            'Flingy Editor'
            'Sprites Editor'
            'Images Editor'
            'Upgrades Editor'
            'Tech Editor'
            'Sounds Editor'
            'Portraits Editor'
            'Campaign Editor'
            'Orders Editor')
        end
        object ShowHints: TCheckBox
          Left = 8
          Top = 50
          Width = 79
          Height = 17
          Hint = 'Display property hints in the Hint Box.'
          Caption = 'Show hints'
          Checked = True
          ParentShowHint = False
          ShowHint = True
          State = cbChecked
          TabOrder = 4
          OnClick = ShowHintsClick
        end
        object ShowSplash: TCheckBox
          Left = 8
          Top = 72
          Width = 123
          Height = 17
          Hint = 'Show the splash image upon program'#39's startup.'
          Caption = 'Show splash-screen'
          Checked = True
          ParentShowHint = False
          ShowHint = True
          State = cbChecked
          TabOrder = 5
          OnClick = ShowSplashClick
        end
        object UseCustomLabels: TCheckBox
          Left = 162
          Top = 72
          Width = 117
          Height = 17
          Hint = 
            'Load entry names for Units, Weapons, Upgrades and Tech Editors f' +
            'rom a Custom "stat_txt" TBL file.'
          Caption = 'Use custom labels'
          Color = clBtnFace
          ParentColor = False
          ParentShowHint = False
          ShowHint = True
          TabOrder = 8
          OnClick = UseCustomLabelsClick
        end
        object ShowSelCirclePreview: TCheckBox
          Left = 8
          Top = 94
          Width = 153
          Height = 17
          Hint = 
            'Show the preview of sprite'#39's GRP, the selection circle and the H' +
            'P bar in the Sprites Editor.'
          Caption = 'Show Sprites editor preview'
          Checked = True
          ParentShowHint = False
          ShowHint = True
          State = cbChecked
          TabOrder = 6
          OnClick = ShowSelCirclePreviewClick
        end
        object UseOldOpenDirectory: TCheckBox
          Left = 162
          Top = 94
          Width = 135
          Height = 17
          Hint = 
            'Use an old-style, custom-made Load Directory dialog, instead of ' +
            'the default system one.'
          Caption = 'Use old Open Directory'
          Color = clBtnFace
          ParentColor = False
          ParentShowHint = False
          ShowHint = True
          TabOrder = 9
          OnClick = UseOldOpenDirectoryClick
        end
        object DefaultSize: TButton
          Left = 243
          Top = 19
          Width = 85
          Height = 24
          Caption = 'Reset Window'
          TabOrder = 2
          OnClick = DefaultSizeClick
        end
        object AssociateDAT: TButton
          Left = 331
          Top = 19
          Width = 85
          Height = 24
          Caption = 'Associate DATs'
          TabOrder = 3
          OnClick = AssociateDATClick
        end
        object ClearHistory: TButton
          Left = 155
          Top = 19
          Width = 85
          Height = 24
          Action = Form1.ClearHistory
          TabOrder = 1
        end
        object SizePrevOff: TRadioButton
          Left = 96
          Top = 114
          Width = 37
          Height = 17
          Caption = 'Off'
          TabOrder = 11
          OnClick = SizePrevClick
        end
        object SizePrevSimple: TRadioButton
          Left = 136
          Top = 114
          Width = 55
          Height = 17
          Caption = 'Simple'
          TabOrder = 12
          OnClick = SizePrevClick
        end
        object SizePrevGRP: TRadioButton
          Left = 194
          Top = 114
          Width = 93
          Height = 17
          Caption = 'GRP preview'
          Checked = True
          TabOrder = 13
          TabStop = True
          OnClick = SizePrevClick
        end
      end
      object UnitGRPPrevBox: TGroupBox
        Left = 1
        Top = 135
        Width = 422
        Height = 60
        Caption = 'GRP Preview source:'
        TabOrder = 1
        object ExtGRPSourceLabel: TLabel
          Left = 8
          Top = 36
          Width = 104
          Height = 13
          Caption = 'External GRP Source:'
        end
        object ExtGRPSourceLoad: TButton
          Left = 387
          Top = 34
          Width = 30
          Height = 21
          Caption = '...'
          TabOrder = 0
          OnClick = ExtGRPSourceLoadClick
        end
        object LoadGRPFromMPQ: TCheckBox
          Left = 8
          Top = 16
          Width = 183
          Height = 17
          Hint = 'Display property hints in the Hint Box.'
          Caption = 'Load GRPs from opened archives'
          Checked = True
          State = cbChecked
          TabOrder = 1
          OnClick = LoadGRPFromMPQClick
        end
        object ExtGRPSourcePath: TEdit
          Left = 114
          Top = 34
          Width = 271
          Height = 21
          Color = clBlack
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          OnChange = OptionsPathChange
        end
      end
    end
    object CustomPathsTab: TTabSheet
      Caption = 'Custom Files'
      ImageIndex = 1
      object Label2: TLabel
        Left = 2
        Top = 198
        Width = 419
        Height = 39
        AutoSize = False
        Caption = 
          'Here you can make DatEdit load labels from specific TBL files in' +
          'stead of the default ones. Changes are applied instantaneously a' +
          'nd are also supported when exporting to MPQ/EXE. (which means th' +
          'at you can export files set here together with your DAT files)'
        WordWrap = True
      end
      object CustomIcons: TGroupBox
        Left = 1
        Top = 145
        Width = 422
        Height = 50
        Caption = 'Custom Icons:'
        TabOrder = 1
        object cmdiconsLabel: TLabel
          Left = 4
          Top = 20
          Width = 66
          Height = 13
          Caption = 'cmdicons.grp:'
        end
        object IconsDefault: TButton
          Left = 351
          Top = 18
          Width = 59
          Height = 21
          Caption = 'Default'
          TabOrder = 2
        end
        object IconsLoad: TButton
          Left = 314
          Top = 18
          Width = 30
          Height = 21
          Caption = '...'
          TabOrder = 1
          OnClick = IconsLoadClick
        end
        object IconsPath: TEdit
          Left = 74
          Top = 18
          Width = 235
          Height = 21
          Color = clBlack
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          OnChange = OptionsPathChange
        end
      end
      object CustomTBLs: TGroupBox
        Left = 1
        Top = 1
        Width = 422
        Height = 140
        Caption = 'Custom TBLs:'
        TabOrder = 0
        object PortdataLabel: TLabel
          Left = 12
          Top = 64
          Width = 57
          Height = 13
          Caption = 'Portdata.tbl:'
        end
        object ImagesLabel: TLabel
          Left = 18
          Top = 42
          Width = 51
          Height = 13
          Caption = 'Images.tbl:'
        end
        object StatLabel: TLabel
          Left = 16
          Top = 20
          Width = 53
          Height = 13
          Caption = 'Stat_txt.tbl:'
        end
        object SfxLabel: TLabel
          Left = 16
          Top = 86
          Width = 53
          Height = 13
          Caption = 'Sfxdata.tbl:'
        end
        object MapdataLabel: TLabel
          Left = 10
          Top = 108
          Width = 59
          Height = 13
          Caption = 'Mapdata.tbl:'
        end
        object StatPath: TEdit
          Left = 72
          Top = 16
          Width = 235
          Height = 21
          Color = clBlack
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          OnChange = OptionsPathChange
        end
        object ImagesPath: TEdit
          Left = 72
          Top = 38
          Width = 235
          Height = 21
          Color = clBlack
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 3
          OnChange = OptionsPathChange
        end
        object PortdataPath: TEdit
          Left = 72
          Top = 60
          Width = 235
          Height = 21
          Color = clBlack
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 6
          OnChange = OptionsPathChange
        end
        object SfxPath: TEdit
          Left = 72
          Top = 82
          Width = 235
          Height = 21
          Color = clBlack
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 9
          OnChange = OptionsPathChange
        end
        object MapdataPath: TEdit
          Left = 72
          Top = 104
          Width = 235
          Height = 21
          Color = clBlack
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 12
          OnChange = OptionsPathChange
        end
        object StatLoad: TButton
          Left = 314
          Top = 16
          Width = 30
          Height = 21
          Caption = '...'
          TabOrder = 1
          OnClick = OptionsCustomFileLoad
        end
        object ImagesLoad: TButton
          Left = 314
          Top = 38
          Width = 30
          Height = 21
          Caption = '...'
          TabOrder = 4
          OnClick = OptionsCustomFileLoad
        end
        object PortdataLoad: TButton
          Left = 314
          Top = 60
          Width = 30
          Height = 21
          Caption = '...'
          TabOrder = 7
          OnClick = OptionsCustomFileLoad
        end
        object SfxLoad: TButton
          Left = 314
          Top = 82
          Width = 30
          Height = 21
          Caption = '...'
          TabOrder = 10
          OnClick = OptionsCustomFileLoad
        end
        object MapdataLoad: TButton
          Left = 314
          Top = 104
          Width = 30
          Height = 21
          Caption = '...'
          TabOrder = 13
          OnClick = OptionsCustomFileLoad
        end
        object StatDefault: TButton
          Left = 351
          Top = 16
          Width = 59
          Height = 21
          Caption = 'Default'
          TabOrder = 2
          OnClick = OptionsDefaultClick
        end
        object ImagesDefault: TButton
          Left = 351
          Top = 38
          Width = 59
          Height = 21
          Caption = 'Default'
          TabOrder = 5
          OnClick = OptionsDefaultClick
        end
        object PortdataDefault: TButton
          Left = 351
          Top = 60
          Width = 59
          Height = 21
          Caption = 'Default'
          TabOrder = 8
          OnClick = OptionsDefaultClick
        end
        object SfxDefault: TButton
          Left = 351
          Top = 82
          Width = 59
          Height = 21
          Caption = 'Default'
          TabOrder = 11
          OnClick = OptionsDefaultClick
        end
        object MapdataDefault: TButton
          Left = 351
          Top = 104
          Width = 59
          Height = 21
          Caption = 'Default'
          TabOrder = 14
          OnClick = OptionsDefaultClick
        end
      end
    end
    object ExternalProgramsTab: TTabSheet
      Caption = 'External Links'
      ImageIndex = 2
      object Label1: TLabel
        Left = 2
        Top = 198
        Width = 419
        Height = 39
        AutoSize = False
        Caption = 
          'Here you can set shortcuts to any external files or programs, li' +
          'ke other modding tools, but you can for example also link to Sta' +
          'rCraft itself. Links are available under "Links" in the main men' +
          'u. I'#39'm sorry, but there is no support for parameters.'
        WordWrap = True
      end
      object ExternalProgsPanel: TGroupBox
        Left = 1
        Top = 1
        Width = 422
        Height = 194
        Align = alCustom
        Caption = 'External Links:'
        TabOrder = 0
        object AddExternalProg: TButton
          Left = 6
          Top = 158
          Width = 75
          Height = 25
          Caption = 'Add...'
          TabOrder = 1
          OnClick = AddExternalProgClick
        end
        object RemExternalProg: TButton
          Left = 82
          Top = 158
          Width = 75
          Height = 25
          Caption = 'Remove'
          TabOrder = 2
          OnClick = RemExternalProgClick
        end
        object ExternalProgList: TListBox
          Left = 6
          Top = 20
          Width = 409
          Height = 135
          Color = clBlack
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ItemHeight = 13
          ParentFont = False
          TabOrder = 0
        end
        object RemAllExternalProgs: TButton
          Left = 340
          Top = 158
          Width = 75
          Height = 25
          Caption = 'Remove All'
          TabOrder = 3
          OnClick = RemAllExternalProgsClick
        end
      end
    end
  end
  object OptionsBoxOK: TButton
    Left = 166
    Top = 271
    Width = 75
    Height = 25
    Anchors = [akLeft, akBottom]
    Caption = '&OK'
    ModalResult = 1
    TabOrder = 1
    OnClick = OptionsBoxOKClick
  end
  object LoadFile: TOpenDialog
    OnCanClose = LoadFileCanClose
    Left = 348
    Top = 6
  end
end
