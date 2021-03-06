object Form1: TForm1
  Tag = -1
  Left = 679
  Top = 155
  Width = 882
  Height = 645
  HorzScrollBar.Margin = 465
  HorzScrollBar.Tracking = True
  VertScrollBar.Margin = 500
  VertScrollBar.Smooth = True
  VertScrollBar.Tracking = True
  Caption = 'Datedit'
  Color = clBtnFace
  Constraints.MinHeight = 200
  Constraints.MinWidth = 300
  DefaultMonitor = dmPrimary
  DragMode = dmAutomatic
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter: TSplitter
    Tag = -1
    Left = 318
    Top = 0
    Width = 2
    Height = 566
    Cursor = crHSplit
    AutoSnap = False
    Color = clBtnFace
    MinSize = 100
    ParentColor = False
    ResizeStyle = rsUpdate
  end
  object EditorsPanel: TPanel
    Tag = -1
    Left = 320
    Top = 0
    Width = 546
    Height = 566
    Align = alClient
    Alignment = taLeftJustify
    BevelOuter = bvNone
    FullRepaint = False
    PopupMenu = PopupMenu
    TabOrder = 1
    object Editors: TPageControl
      Tag = -1
      Left = 0
      Top = 0
      Width = 546
      Height = 390
      ActivePage = WeapEdit
      Align = alClient
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      HotTrack = True
      MultiLine = True
      ParentFont = False
      TabIndex = 1
      TabOrder = 0
      OnChange = ChangeTabExecute
      object UnitEdit: TTabSheet
        Tag = -1
        Caption = 'Units'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = 15
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ImageIndex = -1
        ParentFont = False
        object UnitTabs: TPageControl
          Tag = -1
          Left = 0
          Top = 0
          Width = 538
          Height = 362
          ActivePage = UnitAdv
          Align = alClient
          RaggedRight = True
          Style = tsFlatButtons
          TabIndex = 1
          TabOrder = 0
          OnChange = UnitTabsChange
          object UnitBasic: TTabSheet
            Tag = -1
            Caption = 'Basic'
            OnShow = UnitBasicShow
            object UnitWeapons: TGroupBox
              Tag = -1
              Left = 0
              Top = 104
              Width = 456
              Height = 102
              Caption = 'Weapons:'
              TabOrder = 2
              object LabelUnitWeaponGround: TLabel
                Tag = -1
                Left = 16
                Top = 18
                Width = 38
                Height = 13
                Caption = 'Ground:'
              end
              object LabelUnitGroundMax: TLabel
                Tag = -1
                Left = 10
                Top = 40
                Width = 44
                Height = 13
                Caption = 'Max Hits:'
              end
              object LabelUnitAirMax: TLabel
                Tag = -1
                Left = 10
                Top = 80
                Width = 44
                Height = 13
                Caption = 'Max Hits:'
              end
              object LabelUniWeaponAir: TLabel
                Tag = -1
                Left = 39
                Top = 60
                Width = 15
                Height = 13
                Caption = 'Air:'
              end
              object LabelEqUnits8: TLabel
                Tag = -1
                Left = 116
                Top = 16
                Width = 6
                Height = 13
                Caption = '='
              end
              object LabelEqUnits9: TLabel
                Tag = -1
                Left = 116
                Top = 58
                Width = 6
                Height = 13
                Caption = '='
              end
              object UnitWeaponGroundList: TComboBox
                Tag = -1
                Left = 125
                Top = 14
                Width = 249
                Height = 21
                AutoComplete = False
                Style = csDropDownList
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ItemHeight = 13
                ParentFont = False
                TabOrder = 1
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitWeaponAirList: TComboBox
                Tag = -1
                Left = 125
                Top = 56
                Width = 249
                Height = 21
                AutoComplete = False
                Style = csDropDownList
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ItemHeight = 13
                ParentFont = False
                TabOrder = 5
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitWeaponGroundJump: TButton
                Tag = 1
                Left = 378
                Top = 14
                Width = 55
                Height = 19
                Caption = 'Jump ->'
                TabOrder = 2
                OnClick = JumpToDATExecute
                OnEnter = LoadHintExecute
              end
              object UnitWeaponAirJump: TButton
                Tag = 1
                Left = 378
                Top = 56
                Width = 55
                Height = 19
                Caption = 'Jump ->'
                TabOrder = 6
                OnClick = JumpToDATExecute
                OnEnter = LoadHintExecute
              end
              object UnitWeaponGround: TEdit
                Tag = 17
                Left = 56
                Top = 14
                Width = 60
                Height = 21
                BevelInner = bvLowered
                BevelOuter = bvRaised
                BiDiMode = bdLeftToRight
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentBiDiMode = False
                ParentFont = False
                TabOrder = 0
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
                OnExit = ExitEditExecute
              end
              object UnitWeaponAir: TEdit
                Tag = 19
                Left = 56
                Top = 56
                Width = 60
                Height = 21
                BevelInner = bvLowered
                BevelOuter = bvRaised
                BiDiMode = bdLeftToRight
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentBiDiMode = False
                ParentFont = False
                TabOrder = 4
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
                OnExit = ExitEditExecute
              end
              object UnitGroundMax: TEdit
                Tag = 18
                Left = 56
                Top = 34
                Width = 60
                Height = 21
                BevelInner = bvLowered
                BevelOuter = bvRaised
                BiDiMode = bdLeftToRight
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentBiDiMode = False
                ParentFont = False
                TabOrder = 3
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
                OnExit = ExitEditExecute
              end
              object UnitAirMax: TEdit
                Tag = 20
                Left = 56
                Top = 76
                Width = 60
                Height = 21
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentFont = False
                TabOrder = 7
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
                OnExit = ExitEditExecute
              end
            end
            object UnitVitals: TGroupBox
              Tag = -1
              Left = 0
              Top = 5
              Width = 249
              Height = 101
              Caption = 'Vital Statistics:'
              TabOrder = 0
              object LabelUnitArmorUpgrade: TLabel
                Tag = -1
                Left = 12
                Top = 77
                Width = 44
                Height = 13
                Caption = 'Upgrade:'
              end
              object LabelUnitHP: TLabel
                Tag = -1
                Left = 8
                Top = 22
                Width = 48
                Height = 13
                Caption = 'Hit Points:'
              end
              object LabelUnitSP: TLabel
                Tag = -1
                Left = 19
                Top = 40
                Width = 37
                Height = 13
                Caption = 'Shields:'
              end
              object LabelUnitArmor: TLabel
                Tag = -1
                Left = 26
                Top = 58
                Width = 30
                Height = 13
                Caption = 'Armor:'
              end
              object UnitShieldEnable: TCheckBox
                Tag = 6
                Left = 122
                Top = 36
                Width = 57
                Height = 17
                Caption = 'Enable'
                TabOrder = 0
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitHP: TEdit
                Tag = 256008
                Left = 58
                Top = 20
                Width = 60
                Height = 21
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentFont = False
                TabOrder = 1
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
                OnExit = ExitEditExecute
              end
              object UnitSP: TEdit
                Tag = 7
                Left = 58
                Top = 38
                Width = 60
                Height = 21
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentFont = False
                TabOrder = 2
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
                OnExit = ExitEditExecute
              end
              object UnitArmor: TEdit
                Tag = 27
                Left = 58
                Top = 56
                Width = 60
                Height = 21
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentFont = False
                TabOrder = 3
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
                OnExit = ExitEditExecute
              end
              object UnitArmorUpgrade: TComboBox
                Tag = 25
                Left = 58
                Top = 76
                Width = 180
                Height = 21
                AutoComplete = False
                Style = csDropDownList
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ItemHeight = 13
                ParentFont = False
                TabOrder = 4
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
            end
            object UnitCost: TGroupBox
              Tag = -1
              Left = 252
              Top = 5
              Width = 204
              Height = 101
              Caption = 'Build Cost:'
              TabOrder = 1
              object LabelUnitTime: TLabel
                Tag = -1
                Left = 30
                Top = 60
                Width = 26
                Height = 13
                Caption = 'Time:'
              end
              object LabelUnitVespene: TLabel
                Tag = -1
                Left = 11
                Top = 42
                Width = 45
                Height = 13
                Caption = 'Vespene:'
              end
              object LabelUnitMinerals: TLabel
                Tag = -1
                Left = 14
                Top = 22
                Width = 42
                Height = 13
                Caption = 'Minerals:'
              end
              object LabelEqUnits10: TLabel
                Tag = -1
                Left = 118
                Top = 60
                Width = 6
                Height = 13
                Caption = '='
              end
              object LabelSecUnits: TLabel
                Tag = -1
                Left = 179
                Top = 60
                Width = 20
                Height = 13
                Caption = 'sec.'
              end
              object UnitIsBW: TCheckBox
                Tag = 57
                Left = 2
                Top = 78
                Width = 69
                Height = 17
                Alignment = taLeftJustify
                Caption = 'Brood War'
                TabOrder = 5
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitMinerals: TEdit
                Tag = 45
                Left = 58
                Top = 20
                Width = 60
                Height = 21
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentFont = False
                TabOrder = 0
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
                OnExit = ExitEditExecute
              end
              object UnitVespene: TEdit
                Tag = 46
                Left = 58
                Top = 38
                Width = 60
                Height = 21
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentFont = False
                TabOrder = 1
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
                OnExit = ExitEditExecute
              end
              object UnitTime: TEdit
                Tag = 47
                Left = 58
                Top = 56
                Width = 60
                Height = 21
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentFont = False
                TabOrder = 2
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
                OnExit = ExitEditExecute
              end
              object UnitTimeSec: TEdit
                Tag = 15047
                Left = 125
                Top = 56
                Width = 34
                Height = 21
                Color = clBlack
                Enabled = False
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentFont = False
                TabOrder = 3
              end
              object UnitTimeSecUpDown: TUpDown
                Tag = -1
                Left = 159
                Top = 56
                Width = 17
                Height = 21
                Min = 0
                Max = 32767
                Position = 16383
                TabOrder = 4
                TabStop = True
                Wrap = True
                OnChangingEx = UnitTimeSecUpDownChangingEx
              end
            end
            object UnitSpace: TGroupBox
              Tag = -1
              Left = 185
              Top = 206
              Width = 125
              Height = 62
              Caption = 'Space:'
              TabOrder = 4
              object LabelUnitSpaceReq: TLabel
                Tag = -1
                Left = 9
                Top = 19
                Width = 46
                Height = 13
                Caption = 'Required:'
              end
              object LabelUnitSpaceProv: TLabel
                Tag = -1
                Left = 9
                Top = 37
                Width = 45
                Height = 13
                Caption = 'Provided:'
              end
              object UnitSpaceReq: TEdit
                Tag = 52
                Left = 56
                Top = 16
                Width = 60
                Height = 21
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentFont = False
                TabOrder = 0
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
                OnExit = ExitEditExecute
              end
              object UnitSpaceProv: TEdit
                Tag = 53
                Left = 56
                Top = 34
                Width = 60
                Height = 21
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentFont = False
                TabOrder = 1
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
                OnExit = ExitEditExecute
              end
            end
            object UnitSupply: TGroupBox
              Tag = -1
              Left = 0
              Top = 206
              Width = 183
              Height = 77
              Caption = 'Supply:'
              TabOrder = 3
              object LabelUnitSupReq: TLabel
                Tag = -1
                Left = 8
                Top = 19
                Width = 46
                Height = 13
                Caption = 'Required:'
              end
              object LabelUnitSupProv: TLabel
                Tag = -1
                Left = 9
                Top = 37
                Width = 45
                Height = 13
                Caption = 'Provided:'
              end
              object UnitSupReq: TEdit
                Tag = 2051
                Left = 56
                Top = 16
                Width = 60
                Height = 21
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentFont = False
                TabOrder = 0
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
                OnExit = ExitEditExecute
              end
              object UnitSupProv: TEdit
                Tag = 2050
                Left = 56
                Top = 34
                Width = 60
                Height = 21
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentFont = False
                TabOrder = 2
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
                OnExit = ExitEditExecute
              end
              object UnitSEGroupProtoss: TCheckBox
                Tag = 49002
                Left = 120
                Top = 57
                Width = 57
                Height = 16
                Caption = 'Protoss'
                TabOrder = 6
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitSEGroupTerran: TCheckBox
                Tag = 49001
                Left = 64
                Top = 57
                Width = 51
                Height = 16
                Caption = 'Terran'
                TabOrder = 5
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitSEGroupZerg: TCheckBox
                Tag = 49000
                Left = 8
                Top = 57
                Width = 49
                Height = 16
                Caption = 'Zerg'
                TabOrder = 4
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitSupReq05: TCheckBox
                Tag = -1
                Left = 120
                Top = 17
                Width = 43
                Height = 17
                Caption = '+0.5'
                TabOrder = 1
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitSupProv05: TCheckBox
                Tag = -1
                Left = 120
                Top = 35
                Width = 43
                Height = 17
                Caption = '+0.5'
                TabOrder = 3
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
            end
            object UnitScore: TGroupBox
              Tag = -1
              Left = 313
              Top = 206
              Width = 143
              Height = 62
              Caption = 'Score:'
              TabOrder = 5
              object LabelUnitScoreBuild: TLabel
                Tag = -1
                Left = 29
                Top = 20
                Width = 26
                Height = 13
                Caption = 'Build:'
              end
              object LabelUnitScoreDestroy: TLabel
                Tag = -1
                Left = 15
                Top = 38
                Width = 39
                Height = 13
                Caption = 'Destroy:'
              end
              object UnitScoreBuild: TEdit
                Tag = 54
                Left = 56
                Top = 16
                Width = 60
                Height = 21
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentFont = False
                TabOrder = 0
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
                OnExit = ExitEditExecute
              end
              object UnitScoreDestroy: TEdit
                Tag = 55
                Left = 56
                Top = 34
                Width = 60
                Height = 21
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentFont = False
                TabOrder = 1
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
                OnExit = ExitEditExecute
              end
            end
            object UnitOther: TGroupBox
              Tag = -1
              Left = 0
              Top = 282
              Width = 456
              Height = 40
              Caption = 'Other Properties:'
              TabOrder = 6
              object LabelUnitSize: TLabel
                Tag = -1
                Left = 8
                Top = 18
                Width = 45
                Height = 13
                Caption = 'Unit Size:'
              end
              object LabelUnitSight: TLabel
                Tag = -1
                Left = 158
                Top = 18
                Width = 27
                Height = 13
                Caption = 'Sight:'
              end
              object LabelUnitTAR: TLabel
                Tag = -1
                Left = 247
                Top = 18
                Width = 123
                Height = 13
                Caption = 'Target Acquisition Range:'
              end
              object UnitSize: TComboBox
                Tag = 26
                Left = 56
                Top = 14
                Width = 99
                Height = 21
                Style = csDropDownList
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ItemHeight = 13
                ParentFont = False
                TabOrder = 0
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitSight: TEdit
                Tag = 24
                Left = 187
                Top = 14
                Width = 60
                Height = 21
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentFont = False
                TabOrder = 1
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
                OnExit = ExitEditExecute
              end
              object UnitTAR: TEdit
                Tag = 23
                Left = 371
                Top = 14
                Width = 60
                Height = 21
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentFont = False
                TabOrder = 2
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
                OnExit = ExitEditExecute
              end
            end
          end
          object UnitAdv: TTabSheet
            Tag = -1
            Caption = 'Advanced'
            ImageIndex = 2
            OnShow = UnitAdvShow
            object UnitAdvProp: TGroupBox
              Tag = -1
              Left = 0
              Top = 5
              Width = 529
              Height = 202
              Caption = 'Advanced Properties:'
              TabOrder = 0
              object UnitAdvBuilding: TCheckBox
                Tag = 22000
                Left = 12
                Top = 20
                Width = 140
                Height = 16
                Caption = 'Building'
                TabOrder = 22
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitAdvAddon: TCheckBox
                Tag = 22001
                Left = 12
                Top = 36
                Width = 140
                Height = 16
                Caption = 'Addon'
                TabOrder = 23
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitAdvFlyer: TCheckBox
                Tag = 22002
                Left = 12
                Top = 52
                Width = 140
                Height = 16
                Caption = 'Flyer'
                TabOrder = 0
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitAdvWorker: TCheckBox
                Tag = 22003
                Left = 12
                Top = 68
                Width = 140
                Height = 16
                Caption = 'Worker'
                TabOrder = 13
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitAdvRegenerate: TCheckBox
                Tag = 22007
                Left = 12
                Top = 132
                Width = 140
                Height = 16
                Caption = 'Regeneration'
                TabOrder = 2
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitAdvHero: TCheckBox
                Tag = 22006
                Left = 12
                Top = 116
                Width = 140
                Height = 16
                Caption = 'Hero'
                TabOrder = 1
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitAdvFlyBuilding: TCheckBox
                Tag = 22005
                Left = 12
                Top = 100
                Width = 140
                Height = 16
                Caption = 'Flying Building'
                TabOrder = 24
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitAdvSubunit: TCheckBox
                Tag = 22004
                Left = 12
                Top = 84
                Width = 140
                Height = 16
                Caption = 'Subunit'
                TabOrder = 10
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitAdvSingleEntity: TCheckBox
                Tag = 22011
                Left = 158
                Top = 36
                Width = 140
                Height = 16
                Caption = 'Neutral Accessories'
                TabOrder = 17
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitAdvTwoInEgg: TCheckBox
                Tag = 22010
                Left = 158
                Top = 20
                Width = 140
                Height = 16
                Caption = '2 Units in 1 Egg'
                TabOrder = 16
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitAdvCloak: TCheckBox
                Tag = 22009
                Left = 12
                Top = 164
                Width = 140
                Height = 16
                Caption = 'Cloakable'
                TabOrder = 19
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitAdvAnimIdle: TCheckBox
                Tag = 22008
                Left = 12
                Top = 148
                Width = 140
                Height = 16
                Caption = 'Animated Idle(?)'
                TabOrder = 29
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitAdvDetector: TCheckBox
                Tag = 22015
                Left = 158
                Top = 100
                Width = 140
                Height = 16
                Caption = 'Detector'
                TabOrder = 9
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitAdvProducesUnits: TCheckBox
                Tag = 22031
                Left = 340
                Top = 180
                Width = 140
                Height = 16
                Caption = 'Produces Units'
                TabOrder = 28
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitAdvMechanical: TCheckBox
                Tag = 22030
                Left = 340
                Top = 164
                Width = 140
                Height = 16
                Caption = 'Mechanical'
                TabOrder = 7
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitAdvInvincible: TCheckBox
                Tag = 22029
                Left = 340
                Top = 148
                Width = 140
                Height = 16
                Caption = 'Invincible'
                TabOrder = 5
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitAdvAutoAttack: TCheckBox
                Tag = 22028
                Left = 340
                Top = 132
                Width = 140
                Height = 16
                Caption = 'Attack'
                TabOrder = 21
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitAdvBattleReactions: TCheckBox
                Tag = 22027
                Left = 340
                Top = 116
                Width = 140
                Height = 16
                Caption = 'Auto Move And Attack'
                TabOrder = 20
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitAdvOverlayLarge: TCheckBox
                Tag = 22026
                Left = 340
                Top = 100
                Width = 140
                Height = 16
                Caption = 'Large Overlay'
                TabOrder = 26
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitAdvOverlayMed: TCheckBox
                Tag = 22025
                Left = 340
                Top = 84
                Width = 140
                Height = 16
                Caption = 'Medium Overlay'
                TabOrder = 25
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitAdvIgnoreSupply: TCheckBox
                Tag = 22024
                Left = 340
                Top = 68
                Width = 140
                Height = 16
                Caption = 'Morph From Other Unit'
                TabOrder = 27
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitAdvBurrow: TCheckBox
                Tag = 22020
                Left = 158
                Top = 180
                Width = 140
                Height = 16
                Caption = 'Burrowable'
                TabOrder = 18
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitAdvSpellcaster: TCheckBox
                Tag = 22021
                Left = 340
                Top = 20
                Width = 140
                Height = 16
                Caption = 'Spellcaster'
                TabOrder = 3
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitAdvPermaCloak: TCheckBox
                Tag = 22022
                Left = 340
                Top = 36
                Width = 140
                Height = 16
                Caption = 'Permanent Cloak'
                TabOrder = 4
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitAdvPickup: TCheckBox
                Tag = 22023
                Left = 340
                Top = 52
                Width = 181
                Height = 16
                Caption = 'Npc/Accessories'
                TabOrder = 30
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitAdvOrganic: TCheckBox
                Tag = 22016
                Left = 158
                Top = 116
                Width = 140
                Height = 16
                Caption = 'Organic'
                TabOrder = 6
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitAdvReqCreep: TCheckBox
                Tag = 22017
                Left = 158
                Top = 132
                Width = 163
                Height = 16
                Caption = 'Creeping Building'
                TabOrder = 15
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitAdvUnused: TCheckBox
                Tag = 22018
                Left = 158
                Top = 148
                Width = 140
                Height = 16
                Caption = 'Unused'
                TabOrder = 31
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitAdvReqPsi: TCheckBox
                Tag = 22019
                Left = 158
                Top = 164
                Width = 140
                Height = 16
                Caption = 'Requires Psi'
                TabOrder = 14
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitAdvResDepot: TCheckBox
                Tag = 22012
                Left = 158
                Top = 52
                Width = 140
                Height = 16
                Caption = 'Resource Depot'
                TabOrder = 12
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitAdvResContainer: TCheckBox
                Tag = 22013
                Left = 158
                Top = 68
                Width = 140
                Height = 16
                Caption = 'Resource Container'
                TabOrder = 11
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitAdvRobotic: TCheckBox
                Tag = 22014
                Left = 158
                Top = 84
                Width = 140
                Height = 16
                Caption = 'Robotic'
                TabOrder = 8
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
            end
            object UnitVariousProperties: TGroupBox
              Tag = -1
              Left = 0
              Top = 210
              Width = 529
              Height = 109
              Caption = 'Other Properties:'
              TabOrder = 1
              object LabelUnitUnk1: TLabel
                Tag = -1
                Left = 5
                Top = 84
                Width = 49
                Height = 13
                Caption = 'Unknown:'
              end
              object LabelUnitSub1: TLabel
                Tag = -1
                Left = 6
                Top = 42
                Width = 48
                Height = 13
                Caption = 'Subunit 1:'
              end
              object LabelUnitSub2: TLabel
                Tag = -1
                Left = 6
                Top = 64
                Width = 48
                Height = 13
                Caption = 'Subunit 2:'
              end
              object LabelUnitInfestation: TLabel
                Tag = -1
                Left = 2
                Top = 20
                Width = 52
                Height = 13
                Caption = 'Infestation:'
              end
              object LabelEqUnits14: TLabel
                Tag = -1
                Left = 101
                Top = 20
                Width = 6
                Height = 13
                Caption = '='
              end
              object UnitMov01: TCheckBox
                Tag = 10
                Left = 280
                Top = 38
                Width = 89
                Height = 16
                Caption = '0x01 (Ground)'
                TabOrder = 6
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitMov02: TCheckBox
                Tag = 10001
                Left = 280
                Top = 54
                Width = 89
                Height = 16
                Caption = '0x02'
                TabOrder = 7
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitMov08: TCheckBox
                Tag = 10003
                Left = 280
                Top = 86
                Width = 89
                Height = 16
                Caption = '0x08'
                TabOrder = 9
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitMov04: TCheckBox
                Tag = 10002
                Left = 280
                Top = 70
                Width = 89
                Height = 16
                Caption = '0x04 (Air)'
                TabOrder = 8
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitMov20: TCheckBox
                Tag = 10005
                Left = 376
                Top = 54
                Width = 100
                Height = 14
                Caption = '0x20'
                TabOrder = 11
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitMov10: TCheckBox
                Tag = 10004
                Left = 376
                Top = 38
                Width = 100
                Height = 16
                Caption = '0x10'
                TabOrder = 10
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitMov80: TCheckBox
                Tag = 10007
                Left = 376
                Top = 86
                Width = 100
                Height = 16
                Caption = '0x80 (Mine-safe)'
                TabOrder = 13
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitMov40: TCheckBox
                Tag = 10006
                Left = 376
                Top = 70
                Width = 100
                Height = 16
                Caption = '0x40'
                TabOrder = 12
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitUnk1: TEdit
                Tag = 48
                Left = 56
                Top = 80
                Width = 73
                Height = 21
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentFont = False
                TabOrder = 5
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
                OnExit = ExitEditExecute
              end
              object UnitSub1: TComboBox
                Tag = 1
                Left = 56
                Top = 38
                Width = 215
                Height = 21
                AutoComplete = False
                Style = csDropDownList
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ItemHeight = 13
                ParentFont = False
                TabOrder = 3
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitSub2: TComboBox
                Tag = 2
                Left = 56
                Top = 59
                Width = 215
                Height = 21
                AutoComplete = False
                Style = csDropDownList
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ItemHeight = 13
                ParentFont = False
                TabOrder = 4
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitInfestation: TEdit
                Tag = 3
                Left = 56
                Top = 16
                Width = 45
                Height = 21
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentFont = False
                TabOrder = 0
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
                OnExit = ExitEditExecute
              end
              object UnitInfestationList: TComboBox
                Tag = -1
                Left = 109
                Top = 16
                Width = 240
                Height = 21
                AutoComplete = False
                Style = csDropDownList
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ItemHeight = 13
                ParentFont = False
                TabOrder = 1
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitInfestationJump: TButton
                Left = 352
                Top = 16
                Width = 55
                Height = 19
                Caption = 'Jump ->'
                TabOrder = 2
                OnClick = JumpToDATExecute
              end
            end
          end
          object UnitSound: TTabSheet
            Tag = -1
            Caption = 'Sounds'
            ImageIndex = 1
            OnShow = UnitSoundShow
            object UnitSounds: TGroupBox
              Tag = -1
              Left = 0
              Top = 5
              Width = 456
              Height = 180
              Caption = 'Sounds:'
              TabOrder = 0
              object LabelUnitSndReady: TLabel
                Tag = -1
                Left = 46
                Top = 24
                Width = 34
                Height = 13
                Caption = 'Ready:'
              end
              object LabelUnitSndYesStart: TLabel
                Tag = -1
                Left = 31
                Top = 45
                Width = 49
                Height = 13
                Caption = 'Yes (First):'
              end
              object LabelUnitSndYesEnd: TLabel
                Tag = -1
                Left = 30
                Top = 66
                Width = 50
                Height = 13
                Caption = 'Yes (Last):'
              end
              object LabelUnitSndWhatStart: TLabel
                Tag = -1
                Left = 23
                Top = 87
                Width = 57
                Height = 13
                Caption = 'What (First):'
              end
              object LabelUnitSndWhatEnd: TLabel
                Tag = -1
                Left = 22
                Top = 108
                Width = 58
                Height = 13
                Caption = 'What (Last):'
              end
              object LabelUnitSndAnnStart: TLabel
                Tag = -1
                Left = 7
                Top = 129
                Width = 73
                Height = 13
                Caption = 'Annoyed (First):'
              end
              object LabelUnitSndAnnEnd: TLabel
                Tag = -1
                Left = 6
                Top = 150
                Width = 74
                Height = 13
                Caption = 'Annoyed (Last):'
              end
              object LabelEqUnits6: TLabel
                Tag = -1
                Left = 143
                Top = 128
                Width = 6
                Height = 13
                Caption = '='
              end
              object LabelEqUnits5: TLabel
                Tag = -1
                Left = 143
                Top = 107
                Width = 6
                Height = 13
                Caption = '='
              end
              object LabelEqUnits4: TLabel
                Tag = -1
                Left = 143
                Top = 86
                Width = 6
                Height = 13
                Caption = '='
              end
              object LabelEqUnits3: TLabel
                Tag = -1
                Left = 143
                Top = 65
                Width = 6
                Height = 13
                Caption = '='
              end
              object LabelEqUnits2: TLabel
                Tag = -1
                Left = 143
                Top = 44
                Width = 6
                Height = 13
                Caption = '='
              end
              object LabelEqUnits1: TLabel
                Tag = -1
                Left = 143
                Top = 23
                Width = 6
                Height = 13
                Caption = '='
              end
              object LabelEqUnits7: TLabel
                Tag = -1
                Left = 143
                Top = 149
                Width = 6
                Height = 13
                Caption = '='
              end
              object UnitSndReady: TEdit
                Tag = 29
                Left = 82
                Top = 20
                Width = 60
                Height = 21
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentFont = False
                TabOrder = 0
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
                OnExit = ExitEditExecute
              end
              object UnitSndYesStart: TEdit
                Tag = 34
                Left = 82
                Top = 41
                Width = 60
                Height = 21
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentFont = False
                TabOrder = 3
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
                OnExit = ExitEditExecute
              end
              object UnitSndYesEnd: TEdit
                Tag = 35
                Left = 82
                Top = 62
                Width = 60
                Height = 21
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentFont = False
                TabOrder = 6
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
                OnExit = ExitEditExecute
              end
              object UnitSndWhatStart: TEdit
                Tag = 30
                Left = 82
                Top = 83
                Width = 60
                Height = 21
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentFont = False
                TabOrder = 9
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
                OnExit = ExitEditExecute
              end
              object UnitSndReadyJump: TButton
                Tag = 7
                Left = 391
                Top = 20
                Width = 55
                Height = 19
                Caption = 'Jump ->'
                TabOrder = 2
                OnClick = JumpToDATExecute
              end
              object UnitSndYesStartJump: TButton
                Tag = 7
                Left = 391
                Top = 41
                Width = 55
                Height = 19
                Caption = 'Jump ->'
                TabOrder = 5
                OnClick = JumpToDATExecute
              end
              object UnitSndYesEndJump: TButton
                Tag = 7
                Left = 391
                Top = 62
                Width = 55
                Height = 19
                Caption = 'Jump ->'
                TabOrder = 8
                OnClick = JumpToDATExecute
              end
              object UnitSndWhatStartJump: TButton
                Tag = 7
                Left = 391
                Top = 83
                Width = 55
                Height = 19
                Caption = 'Jump ->'
                TabOrder = 11
                OnClick = JumpToDATExecute
              end
              object UnitSndWhatEndJump: TButton
                Tag = 7
                Left = 391
                Top = 104
                Width = 55
                Height = 19
                Caption = 'Jump ->'
                TabOrder = 14
                OnClick = JumpToDATExecute
              end
              object UnitSndAnnStartJump: TButton
                Tag = 7
                Left = 391
                Top = 125
                Width = 55
                Height = 19
                Caption = 'Jump ->'
                TabOrder = 17
                OnClick = JumpToDATExecute
              end
              object UnitSndAnnEndJump: TButton
                Tag = 7
                Left = 391
                Top = 146
                Width = 55
                Height = 19
                Caption = 'Jump ->'
                TabOrder = 20
                OnClick = JumpToDATExecute
              end
              object UnitSndReadyList: TComboBox
                Tag = -1
                Left = 152
                Top = 20
                Width = 237
                Height = 21
                AutoComplete = False
                Style = csDropDownList
                Color = clBlack
                DropDownCount = 10
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ItemHeight = 13
                ParentFont = False
                TabOrder = 1
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitSndYesStartList: TComboBox
                Tag = -1
                Left = 152
                Top = 41
                Width = 237
                Height = 21
                AutoComplete = False
                Style = csDropDownList
                Color = clBlack
                DropDownCount = 10
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ItemHeight = 13
                ParentFont = False
                TabOrder = 4
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitSndYesEndList: TComboBox
                Tag = -1
                Left = 152
                Top = 62
                Width = 237
                Height = 21
                AutoComplete = False
                Style = csDropDownList
                Color = clBlack
                DropDownCount = 10
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ItemHeight = 13
                ParentFont = False
                TabOrder = 7
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitSndWhatStartList: TComboBox
                Tag = -1
                Left = 152
                Top = 83
                Width = 237
                Height = 21
                AutoComplete = False
                Style = csDropDownList
                Color = clBlack
                DropDownCount = 10
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ItemHeight = 13
                ParentFont = False
                TabOrder = 10
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitSndWhatEndList: TComboBox
                Tag = -1
                Left = 152
                Top = 104
                Width = 237
                Height = 21
                AutoComplete = False
                Style = csDropDownList
                Color = clBlack
                DropDownCount = 10
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ItemHeight = 13
                ParentFont = False
                TabOrder = 13
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitSndAnnStartList: TComboBox
                Tag = -1
                Left = 152
                Top = 125
                Width = 237
                Height = 21
                AutoComplete = False
                Style = csDropDownList
                Color = clBlack
                DropDownCount = 10
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ItemHeight = 13
                ParentFont = False
                TabOrder = 16
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitSndWhatEnd: TEdit
                Tag = 31
                Left = 82
                Top = 104
                Width = 60
                Height = 21
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentFont = False
                TabOrder = 12
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
                OnExit = ExitEditExecute
              end
              object UnitSndAnnStart: TEdit
                Tag = 32
                Left = 82
                Top = 125
                Width = 60
                Height = 21
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentFont = False
                TabOrder = 15
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
                OnExit = ExitEditExecute
              end
              object UnitSndAnnEnd: TEdit
                Tag = 33
                Left = 82
                Top = 146
                Width = 60
                Height = 21
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentFont = False
                TabOrder = 18
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
                OnExit = ExitEditExecute
              end
              object UnitSndAnnEndList: TComboBox
                Tag = -1
                Left = 152
                Top = 146
                Width = 237
                Height = 21
                AutoComplete = False
                Style = csDropDownList
                Color = clBlack
                DropDownCount = 10
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ItemHeight = 13
                ParentFont = False
                TabOrder = 19
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
            end
          end
          object UnitGraphics: TTabSheet
            Tag = -1
            Caption = 'Graphics'
            ImageIndex = 3
            OnShow = UnitGraphicsShow
            object UnitSpriteProp: TGroupBox
              Tag = -1
              Left = 0
              Top = 5
              Width = 456
              Height = 112
              Caption = 'Sprite Properties:'
              TabOrder = 0
              object LabelUnitGfx: TLabel
                Tag = -1
                Left = 47
                Top = 24
                Width = 45
                Height = 13
                Caption = 'Graphics:'
              end
              object LabelUnitConstruction: TLabel
                Tag = -1
                Left = 30
                Top = 45
                Width = 62
                Height = 13
                Caption = 'Construction:'
              end
              object LabelUnitPortrait: TLabel
                Tag = -1
                Left = 56
                Top = 66
                Width = 36
                Height = 13
                Caption = 'Portrait:'
              end
              object LabelUnitElevationLevel: TLabel
                Tag = -1
                Left = 16
                Top = 87
                Width = 76
                Height = 13
                Caption = 'Elevation Level:'
              end
              object LabelUnitDirection: TLabel
                Tag = -1
                Left = 273
                Top = 88
                Width = 45
                Height = 13
                Caption = 'Direction:'
              end
              object LabelEqUnits12: TLabel
                Tag = -1
                Left = 139
                Top = 24
                Width = 6
                Height = 13
                Caption = '='
              end
              object LabelEqUnits13: TLabel
                Tag = -1
                Left = 139
                Top = 45
                Width = 6
                Height = 13
                Caption = '='
              end
              object LabelEqUnits15: TLabel
                Tag = -1
                Left = 139
                Top = 66
                Width = 6
                Height = 13
                Caption = '='
              end
              object LabelEqUnits16: TLabel
                Tag = -1
                Left = 139
                Top = 87
                Width = 6
                Height = 13
                Caption = '='
              end
              object UnitGfxList: TComboBox
                Tag = -1
                Left = 147
                Top = 20
                Width = 240
                Height = 21
                AutoComplete = False
                Style = csDropDownList
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ItemHeight = 13
                ParentFont = False
                TabOrder = 1
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitConstructionList: TComboBox
                Tag = -1
                Left = 147
                Top = 41
                Width = 240
                Height = 21
                AutoComplete = False
                Style = csDropDownList
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ItemHeight = 13
                ParentFont = False
                TabOrder = 4
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitPortraitList: TComboBox
                Tag = -1
                Left = 147
                Top = 62
                Width = 240
                Height = 21
                AutoComplete = False
                Style = csDropDownList
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ItemHeight = 13
                ParentFont = False
                TabOrder = 7
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitElevationLevelList: TComboBox
                Tag = -1
                Left = 147
                Top = 83
                Width = 122
                Height = 21
                Style = csDropDownList
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ItemHeight = 13
                ParentFont = False
                TabOrder = 10
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitDirection: TEdit
                Tag = 5
                Left = 320
                Top = 83
                Width = 66
                Height = 21
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentFont = False
                TabOrder = 11
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
                OnExit = ExitEditExecute
              end
              object UnitPortraitJump: TButton
                Tag = 8
                Left = 390
                Top = 62
                Width = 55
                Height = 19
                Caption = 'Jump ->'
                TabOrder = 8
                OnClick = JumpToDATExecute
              end
              object UnitConstructionJump: TButton
                Tag = 4
                Left = 390
                Top = 41
                Width = 55
                Height = 19
                Caption = 'Jump ->'
                TabOrder = 5
                OnClick = JumpToDATExecute
              end
              object UnitGfxJump: TButton
                Tag = 2
                Left = 390
                Top = 20
                Width = 55
                Height = 19
                Caption = 'Jump ->'
                TabOrder = 2
                OnClick = JumpToDATExecute
              end
              object UnitGfx: TEdit
                Left = 94
                Top = 20
                Width = 45
                Height = 21
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentFont = False
                TabOrder = 0
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
                OnExit = ExitEditExecute
              end
              object UnitConstruction: TEdit
                Tag = 4
                Left = 94
                Top = 41
                Width = 45
                Height = 21
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentFont = False
                TabOrder = 3
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
                OnExit = ExitEditExecute
              end
              object UnitPortrait: TEdit
                Tag = 44
                Left = 94
                Top = 62
                Width = 45
                Height = 21
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentFont = False
                TabOrder = 6
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
                OnExit = ExitEditExecute
              end
              object UnitElevationLevel: TEdit
                Tag = 9
                Left = 94
                Top = 83
                Width = 45
                Height = 21
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentFont = False
                TabOrder = 9
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
                OnExit = ExitEditExecute
              end
            end
            object UnitAddonPos: TGroupBox
              Tag = -1
              Left = 0
              Top = 226
              Width = 145
              Height = 70
              Caption = 'Addon Position:'
              TabOrder = 2
              object LabelUnitAddPosX: TLabel
                Tag = -1
                Left = 6
                Top = 22
                Width = 66
                Height = 13
                Alignment = taRightJustify
                Caption = 'Horizontal (X):'
              end
              object LabelUnitAddPosY: TLabel
                Tag = -1
                Left = 18
                Top = 42
                Width = 54
                Height = 13
                Alignment = taRightJustify
                Caption = 'Vertical (Y):'
              end
              object UnitAddPosX: TEdit
                Tag = 38
                Left = 74
                Top = 18
                Width = 60
                Height = 21
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentFont = False
                TabOrder = 0
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
                OnExit = ExitEditExecute
              end
              object UnitAddPosY: TEdit
                Tag = 39
                Left = 74
                Top = 38
                Width = 60
                Height = 21
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentFont = False
                TabOrder = 1
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
                OnExit = ExitEditExecute
              end
            end
            object UnitDims: TGroupBox
              Tag = -1
              Left = 0
              Top = 117
              Width = 145
              Height = 107
              Caption = 'Unit Dimensions:'
              TabOrder = 1
              object LabelUnitDimLeft: TLabel
                Tag = -1
                Left = 48
                Top = 24
                Width = 21
                Height = 13
                Caption = 'Left:'
              end
              object LabelUnitDimRight: TLabel
                Tag = -1
                Left = 41
                Top = 44
                Width = 28
                Height = 13
                Caption = 'Right:'
              end
              object LabelUnitDimUp: TLabel
                Tag = -1
                Left = 52
                Top = 62
                Width = 17
                Height = 13
                Caption = 'Up:'
              end
              object LabelUnitDimDown: TLabel
                Tag = -1
                Left = 38
                Top = 80
                Width = 31
                Height = 13
                Caption = 'Down:'
              end
              object UnitDimLeft: TEdit
                Tag = 40
                Left = 74
                Top = 22
                Width = 60
                Height = 21
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentFont = False
                TabOrder = 0
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
                OnExit = ExitEditExecute
              end
              object UnitDimRight: TEdit
                Tag = 42
                Left = 74
                Top = 40
                Width = 60
                Height = 21
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentFont = False
                TabOrder = 1
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
                OnExit = ExitEditExecute
              end
              object UnitDimUp: TEdit
                Tag = 41
                Left = 74
                Top = 60
                Width = 60
                Height = 21
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentFont = False
                TabOrder = 2
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
                OnExit = ExitEditExecute
              end
              object UnitDimDown: TEdit
                Tag = 43
                Left = 74
                Top = 78
                Width = 60
                Height = 21
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentFont = False
                TabOrder = 3
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
                OnExit = ExitEditExecute
              end
            end
            object UnitDimView: TPanel
              Tag = -1
              Left = 145
              Top = 118
              Width = 311
              Height = 205
              BevelOuter = bvNone
              TabOrder = 3
              object SizeGRPPrev: TImage
                Tag = -1
                Left = 107
                Top = 38
                Width = 256
                Height = 256
                Align = alCustom
              end
              object SizeRect: TShape
                Tag = -1
                Left = 82
                Top = 72
                Width = 20
                Height = 20
                Brush.Style = bsClear
                Pen.Color = clLime
                Visible = False
              end
              object SizeRefPoint: TShape
                Tag = -1
                Left = 72
                Top = 110
                Width = 2
                Height = 2
                Visible = False
              end
              object LabelSizePreview: TLabel
                Tag = -1
                Left = 2
                Top = 0
                Width = 41
                Height = 13
                Caption = 'Preview:'
              end
            end
          end
          object UnitSE: TTabSheet
            Tag = -1
            Caption = 'StarEdit'
            ImageIndex = 4
            OnShow = UnitSEShow
            object UnitSEFlags: TGroupBox
              Tag = -1
              Left = 0
              Top = 5
              Width = 285
              Height = 156
              Caption = 'Availability Flags:'
              TabOrder = 0
              object UnitSENonNeutral: TCheckBox
                Tag = 58000
                Left = 14
                Top = 18
                Width = 135
                Height = 16
                Caption = 'Non-Neutral'
                TabOrder = 0
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitSEUnitHero: TCheckBox
                Tag = 58007
                Left = 14
                Top = 130
                Width = 135
                Height = 16
                Caption = 'Unit && Hero Settings'
                TabOrder = 7
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitSEListing: TCheckBox
                Tag = 58001
                Left = 14
                Top = 34
                Width = 135
                Height = 16
                Caption = 'Unit Listing && Palette'
                TabOrder = 1
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitSEBriefing: TCheckBox
                Tag = 58002
                Left = 14
                Top = 50
                Width = 135
                Height = 16
                Caption = 'Mission Briefing'
                TabOrder = 2
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitSEPlayerSet: TCheckBox
                Tag = 58003
                Left = 14
                Top = 66
                Width = 135
                Height = 16
                Caption = 'Player Settings'
                TabOrder = 3
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitSEAllRaces: TCheckBox
                Tag = 58004
                Left = 14
                Top = 82
                Width = 135
                Height = 16
                Caption = 'All Races'
                TabOrder = 4
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitSEDoodadState: TCheckBox
                Tag = 58005
                Left = 14
                Top = 98
                Width = 135
                Height = 16
                Caption = 'Set Doodad State'
                TabOrder = 5
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitSENonLoc: TCheckBox
                Tag = 58006
                Left = 14
                Top = 114
                Width = 135
                Height = 16
                Caption = 'Non-Location Triggers'
                TabOrder = 6
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitSEBW: TCheckBox
                Tag = 58009
                Left = 152
                Top = 34
                Width = 130
                Height = 16
                Caption = 'Brood War Only'
                TabOrder = 9
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitSELoc: TCheckBox
                Tag = 58008
                Left = 152
                Top = 18
                Width = 130
                Height = 16
                Caption = 'Location Triggers'
                TabOrder = 8
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitSE0x0400: TCheckBox
                Tag = 58010
                Left = 152
                Top = 50
                Width = 130
                Height = 16
                Caption = 'Unused'
                TabOrder = 10
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitSE0x0800: TCheckBox
                Tag = 58011
                Left = 152
                Top = 66
                Width = 130
                Height = 16
                Caption = 'Unused'
                TabOrder = 11
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitSE0x1000: TCheckBox
                Tag = 58012
                Left = 152
                Top = 82
                Width = 130
                Height = 16
                Caption = 'Unused'
                TabOrder = 12
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitSE0x2000: TCheckBox
                Tag = 58013
                Left = 152
                Top = 98
                Width = 130
                Height = 16
                Caption = 'Unused'
                TabOrder = 13
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitSE0x4000: TCheckBox
                Tag = 58014
                Left = 152
                Top = 114
                Width = 130
                Height = 16
                Caption = 'Unused'
                TabOrder = 14
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitSE0x8000: TCheckBox
                Tag = 58015
                Left = 152
                Top = 130
                Width = 130
                Height = 16
                Caption = 'Unused'
                TabOrder = 15
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
            end
            object UnitSEGroupFlags: TGroupBox
              Tag = -1
              Left = 292
              Top = 5
              Width = 115
              Height = 110
              Caption = 'Group Flags:'
              TabOrder = 1
              object UnitSEGroupMen: TCheckBox
                Tag = 49003
                Left = 10
                Top = 18
                Width = 100
                Height = 16
                Caption = 'Men'
                TabOrder = 0
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitSEGroupNeutral: TCheckBox
                Tag = 49007
                Left = 10
                Top = 82
                Width = 100
                Height = 16
                Caption = 'Neutral'
                TabOrder = 4
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitSEGroupInd: TCheckBox
                Tag = 49006
                Left = 10
                Top = 66
                Width = 100
                Height = 16
                Caption = 'Independent'
                TabOrder = 3
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitSEGroupFactory: TCheckBox
                Tag = 49005
                Left = 10
                Top = 50
                Width = 100
                Height = 16
                Caption = 'Factory'
                TabOrder = 2
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitSEGroupBuilding: TCheckBox
                Tag = 49004
                Left = 10
                Top = 34
                Width = 100
                Height = 16
                Caption = 'Building'
                TabOrder = 1
                OnClick = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
            end
            object UnitSEStringProp: TGroupBox
              Tag = -1
              Left = 0
              Top = 166
              Width = 407
              Height = 69
              Caption = 'String Properties:'
              TabOrder = 2
              object LabelUnitSublabel: TLabel
                Tag = -1
                Left = 6
                Top = 22
                Width = 75
                Height = 13
                Alignment = taRightJustify
                Caption = 'Rank/Sublabel:'
              end
              object LabelUnitMapString: TLabel
                Tag = -1
                Left = 27
                Top = 42
                Width = 54
                Height = 13
                Alignment = taRightJustify
                Caption = 'Map String:'
              end
              object LabelUnitSublabel2: TLabel
                Tag = -1
                Left = 143
                Top = 22
                Width = 6
                Height = 13
                Caption = '='
              end
              object UnitRank: TEdit
                Tag = 11
                Left = 82
                Top = 18
                Width = 60
                Height = 21
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentFont = False
                TabOrder = 0
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
                OnExit = ExitEditExecute
              end
              object UnitMapString: TEdit
                Tag = 56
                Left = 82
                Top = 38
                Width = 60
                Height = 21
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentFont = False
                TabOrder = 2
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
                OnExit = ExitEditExecute
              end
              object UnitRankList: TComboBox
                Tag = -1
                Left = 151
                Top = 18
                Width = 246
                Height = 21
                AutoComplete = False
                Style = csDropDownList
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ItemHeight = 13
                ParentFont = False
                TabOrder = 1
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
            end
            object UnitSEPlaceBox: TGroupBox
              Tag = -1
              Left = 0
              Top = 236
              Width = 158
              Height = 69
              Caption = 'Placement Box (pixels):'
              TabOrder = 3
              object LabelUnitSEPlaceHeight: TLabel
                Tag = 37
                Left = 47
                Top = 22
                Width = 34
                Height = 13
                Alignment = taRightJustify
                Caption = 'Height:'
              end
              object LabelUnitSEPlaceWidth: TLabel
                Tag = 36
                Left = 50
                Top = 42
                Width = 31
                Height = 13
                Alignment = taRightJustify
                Caption = 'Width:'
              end
              object UnitSEPlaceHeight: TEdit
                Tag = 37
                Left = 82
                Top = 18
                Width = 60
                Height = 21
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentFont = False
                TabOrder = 0
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
                OnExit = ExitEditExecute
              end
              object UnitSEPlaceWidth: TEdit
                Tag = 36
                Left = 82
                Top = 38
                Width = 60
                Height = 21
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentFont = False
                TabOrder = 1
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
                OnExit = ExitEditExecute
              end
            end
          end
          object UnitAI: TTabSheet
            Tag = -1
            Caption = 'AI Actions'
            ImageIndex = 5
            OnShow = UnitAIShow
            object UnitAIActions: TGroupBox
              Tag = -1
              Left = 0
              Top = 5
              Width = 513
              Height = 300
              Caption = 'AI Actions'
              TabOrder = 0
              object LabelUnitAICompIdle: TLabel
                Tag = -1
                Left = 22
                Top = 24
                Width = 68
                Height = 13
                Caption = 'Computer Idle:'
              end
              object LabelUnitAIHumanIdle: TLabel
                Tag = -1
                Left = 33
                Top = 44
                Width = 57
                Height = 13
                Caption = 'Human Idle:'
              end
              object LabelUnitAIAttackUnit: TLabel
                Tag = -1
                Left = 34
                Top = 84
                Width = 56
                Height = 13
                Caption = 'Attack Unit:'
              end
              object LabelUnitAIAttackMove: TLabel
                Tag = -1
                Left = 26
                Top = 104
                Width = 64
                Height = 13
                Caption = 'Attack Move:'
              end
              object LabelUnitAIReturn: TLabel
                Tag = -1
                Left = 23
                Top = 64
                Width = 67
                Height = 13
                Caption = 'Return to Idle:'
              end
              object LabelUnitAIRightClick: TLabel
                Tag = -1
                Left = 4
                Top = 138
                Width = 86
                Height = 13
                Caption = 'Right-click Action:'
              end
              object LabelUnitAIInternal: TLabel
                Tag = -1
                Left = 39
                Top = 158
                Width = 51
                Height = 13
                Caption = 'AI Internal:'
              end
              object UnitAICompIdle: TComboBox
                Tag = 12
                Left = 92
                Top = 20
                Width = 355
                Height = 21
                AutoComplete = False
                Style = csDropDownList
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ItemHeight = 13
                ParentFont = False
                TabOrder = 0
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitAIHumanIdle: TComboBox
                Tag = 13
                Left = 92
                Top = 41
                Width = 355
                Height = 21
                AutoComplete = False
                Style = csDropDownList
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ItemHeight = 13
                ParentFont = False
                TabOrder = 2
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitAIRightClick: TComboBox
                Tag = 28
                Left = 92
                Top = 134
                Width = 323
                Height = 21
                AutoComplete = False
                Style = csDropDownList
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ItemHeight = 13
                ParentFont = False
                TabOrder = 10
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitAIReturn: TComboBox
                Tag = 14
                Left = 92
                Top = 62
                Width = 355
                Height = 21
                AutoComplete = False
                Style = csDropDownList
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ItemHeight = 13
                ParentFont = False
                TabOrder = 4
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitAIAttackUnit: TComboBox
                Tag = 15
                Left = 92
                Top = 83
                Width = 355
                Height = 21
                AutoComplete = False
                Style = csDropDownList
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ItemHeight = 13
                ParentFont = False
                TabOrder = 6
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitAIAttackMove: TComboBox
                Tag = 16
                Left = 92
                Top = 104
                Width = 355
                Height = 21
                AutoComplete = False
                Style = csDropDownList
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ItemHeight = 13
                ParentFont = False
                TabOrder = 8
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
              end
              object UnitAIInternal: TEdit
                Tag = 21
                Left = 92
                Top = 154
                Width = 60
                Height = 21
                Color = clBlack
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWhite
                Font.Height = 15
                Font.Name = 'MS Sans Serif'
                Font.Style = []
                ParentFont = False
                TabOrder = 11
                OnChange = ChangeDataBoxExecute
                OnEnter = LoadHintExecute
                OnExit = ExitEditExecute
              end
              object UnitAICompIdleJump: TButton
                Tag = 10
                Left = 450
                Top = 20
                Width = 55
                Height = 19
                Caption = 'Jump ->'
                TabOrder = 1
                OnClick = JumpToDATExecute
              end
              object UnitAIHumanIdleJump: TButton
                Tag = 10
                Left = 450
                Top = 41
                Width = 55
                Height = 19
                Caption = 'Jump ->'
                TabOrder = 3
                OnClick = JumpToDATExecute
              end
              object UnitAIReturnJump: TButton
                Tag = 10
                Left = 450
                Top = 62
                Width = 55
                Height = 19
                Caption = 'Jump ->'
                TabOrder = 5
                OnClick = JumpToDATExecute
              end
              object UnitAIAttackUnitJump: TButton
                Tag = 10
                Left = 450
                Top = 83
                Width = 55
                Height = 19
                Caption = 'Jump ->'
                TabOrder = 7
                OnClick = JumpToDATExecute
              end
              object UnitAIAttackMoveJump: TButton
                Tag = 10
                Left = 450
                Top = 104
                Width = 55
                Height = 19
                Caption = 'Jump ->'
                TabOrder = 9
                OnClick = JumpToDATExecute
              end
            end
          end
        end
      end
      object WeapEdit: TTabSheet
        Tag = -1
        Caption = 'Weapons'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = 15
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ImageIndex = -1
        ParentFont = False
        OnShow = WeapEditShow
        object WeapDamageProperties: TGroupBox
          Tag = -1
          Left = 4
          Top = 15
          Width = 345
          Height = 126
          Caption = 'Damage Properties:'
          TabOrder = 0
          object LabelWeapDamageAmount: TLabel
            Tag = -1
            Left = 17
            Top = 24
            Width = 39
            Height = 13
            Caption = 'Amount:'
          end
          object LabelWeapDamageBonus: TLabel
            Tag = -1
            Left = 23
            Top = 42
            Width = 33
            Height = 13
            Caption = 'Bonus:'
          end
          object LabelWeapDamageFactor: TLabel
            Tag = -1
            Left = 23
            Top = 60
            Width = 33
            Height = 13
            Caption = 'Factor:'
          end
          object LabelWeapDamageCooldown: TLabel
            Tag = -1
            Left = 6
            Top = 78
            Width = 50
            Height = 13
            Caption = 'Cooldown:'
          end
          object LabelWeapDamageUpgrade: TLabel
            Tag = -1
            Left = 12
            Top = 100
            Width = 44
            Height = 13
            Caption = 'Upgrade:'
          end
          object LabelWeapDamageType: TLabel
            Tag = -1
            Left = 166
            Top = 24
            Width = 27
            Height = 13
            Caption = 'Type:'
          end
          object LabelWeapUnused: TLabel
            Tag = -1
            Left = 153
            Top = 64
            Width = 40
            Height = 13
            Caption = 'Unused:'
          end
          object LabelWeapDamageExplosion: TLabel
            Tag = -1
            Left = 145
            Top = 44
            Width = 32
            Height = 13
            BiDiMode = bdLeftToRight
            Caption = 'Effect:'
            ParentBiDiMode = False
          end
          object WeapDamageAmount: TEdit
            Tag = 14
            Left = 58
            Top = 22
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object WeapDamageBonus: TEdit
            Tag = 15
            Left = 58
            Top = 38
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 1
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object WeapDamageFactor: TEdit
            Tag = 17
            Left = 58
            Top = 56
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 2
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object WeapDamageCooldown: TEdit
            Tag = 16
            Left = 58
            Top = 74
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 3
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object WeapDamageUpgrade: TComboBox
            Tag = 6
            Left = 58
            Top = 96
            Width = 220
            Height = 21
            AutoComplete = False
            Style = csDropDownList
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ItemHeight = 13
            ParentFont = False
            TabOrder = 4
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object WeapDamageType: TComboBox
            Tag = 7
            Left = 195
            Top = 20
            Width = 142
            Height = 21
            AutoComplete = False
            Style = csDropDownList
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ItemHeight = 13
            ParentFont = False
            TabOrder = 6
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object WeapDamageExplosion: TComboBox
            Tag = 10
            Left = 195
            Top = 40
            Width = 142
            Height = 21
            AutoComplete = False
            Style = csDropDownList
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ItemHeight = 13
            ParentFont = False
            TabOrder = 7
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object WeapDamageUpgradeJump: TButton
            Tag = 5
            Left = 280
            Top = 96
            Width = 55
            Height = 19
            Caption = 'Jump ->'
            TabOrder = 5
            OnClick = JumpToDATExecute
          end
          object WeapUnused: TComboBox
            Tag = 2
            Left = 195
            Top = 60
            Width = 142
            Height = 21
            AutoComplete = False
            Style = csDropDownList
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ItemHeight = 13
            ParentFont = False
            TabOrder = 8
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
        end
        object WeapRange: TGroupBox
          Tag = -1
          Left = 352
          Top = 15
          Width = 110
          Height = 68
          Caption = 'Weapon Range:'
          TabOrder = 3
          object LabelWeapRangeMin: TLabel
            Tag = -1
            Left = 22
            Top = 24
            Width = 20
            Height = 13
            Caption = 'Min:'
          end
          object LabelWeapRangeMax: TLabel
            Tag = -1
            Left = 20
            Top = 42
            Width = 23
            Height = 13
            Caption = 'Max:'
          end
          object WeapRangeMin: TEdit
            Tag = 16004
            Left = 44
            Top = 20
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object WeapRangeMax: TEdit
            Tag = 16005
            Left = 44
            Top = 38
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 1
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
        end
        object WeapSplashRads: TGroupBox
          Tag = -1
          Left = 352
          Top = 85
          Width = 110
          Height = 85
          Caption = 'Splash Radii:'
          TabOrder = 4
          object LabelWeapSplashInner: TLabel
            Tag = -1
            Left = 16
            Top = 22
            Width = 27
            Height = 13
            Caption = 'Inner:'
          end
          object LabelWeapSplashMed: TLabel
            Tag = -1
            Left = 3
            Top = 40
            Width = 40
            Height = 13
            Caption = 'Medium:'
          end
          object LabelWeapSplashOuter: TLabel
            Tag = -1
            Left = 14
            Top = 58
            Width = 29
            Height = 13
            Caption = 'Outer:'
          end
          object WeapSplashInner: TEdit
            Tag = 11
            Left = 44
            Top = 18
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object WeapSplashMed: TEdit
            Tag = 12
            Left = 44
            Top = 36
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 1
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object WeapSplashOuter: TEdit
            Tag = 13
            Left = 44
            Top = 54
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 2
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
        end
        object WeapTarget: TGroupBox
          Tag = -1
          Left = 352
          Top = 173
          Width = 110
          Height = 173
          Caption = 'Target Flags:'
          TabOrder = 5
          object WeapTarget001: TCheckBox
            Tag = 3000
            Left = 8
            Top = 22
            Width = 100
            Height = 16
            Caption = 'Air'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = 14
            Font.Name = 'Microsoft Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
            OnClick = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object WeapTarget002: TCheckBox
            Tag = 3001
            Left = 8
            Top = 38
            Width = 100
            Height = 16
            Caption = 'Ground'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = 14
            Font.Name = 'Microsoft Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 1
            OnClick = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object WeapTarget004: TCheckBox
            Tag = 3002
            Left = 8
            Top = 54
            Width = 100
            Height = 16
            Caption = 'Mechanical'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = 14
            Font.Name = 'Microsoft Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 2
            OnClick = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object WeapTarget008: TCheckBox
            Tag = 3003
            Left = 8
            Top = 70
            Width = 100
            Height = 16
            Caption = 'Organic'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = 14
            Font.Name = 'Microsoft Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 3
            OnClick = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object WeapTarget010: TCheckBox
            Tag = 3004
            Left = 8
            Top = 86
            Width = 100
            Height = 16
            Caption = 'non-Building'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = 14
            Font.Name = 'Microsoft Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 4
            OnClick = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object WeapTarget020: TCheckBox
            Tag = 3005
            Left = 8
            Top = 102
            Width = 100
            Height = 16
            Caption = 'non-Robotic'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = 14
            Font.Name = 'Microsoft Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 5
            OnClick = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object WeapTarget040: TCheckBox
            Tag = 3006
            Left = 8
            Top = 118
            Width = 100
            Height = 16
            Caption = 'Terrain'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = 14
            Font.Name = 'Microsoft Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 6
            OnClick = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object WeapTarget080: TCheckBox
            Tag = 3007
            Left = 8
            Top = 134
            Width = 100
            Height = 16
            Caption = 'Org. or Mech.'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = 14
            Font.Name = 'Microsoft Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 7
            OnClick = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object WeapTarget100: TCheckBox
            Tag = 3008
            Left = 8
            Top = 150
            Width = 100
            Height = 16
            Caption = 'Own'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = 14
            Font.Name = 'Microsoft Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 8
            OnClick = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
        end
        object WeapDisplay: TGroupBox
          Tag = -1
          Left = 4
          Top = 144
          Width = 345
          Height = 70
          Caption = 'Weapon Display:'
          TabOrder = 1
          object LabelWeapLabel: TLabel
            Tag = -1
            Left = 26
            Top = 24
            Width = 29
            Height = 13
            Alignment = taRightJustify
            Caption = 'Label:'
          end
          object LabelWeapError: TLabel
            Tag = -1
            Left = 7
            Top = 45
            Width = 48
            Height = 13
            Caption = 'Error Msg:'
          end
          object WeapLabel: TComboBox
            Left = 58
            Top = 20
            Width = 279
            Height = 21
            AutoComplete = False
            BevelEdges = [beLeft, beRight]
            Style = csDropDownList
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ItemHeight = 13
            ParentFont = False
            TabOrder = 0
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object WeapError: TComboBox
            Tag = 22
            Left = 58
            Top = 41
            Width = 279
            Height = 21
            AutoComplete = False
            BevelEdges = [beLeft, beRight]
            Style = csDropDownList
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ItemHeight = 13
            ParentFont = False
            TabOrder = 1
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
        end
        object WeapGraphical: TGroupBox
          Tag = -1
          Left = 4
          Top = 217
          Width = 345
          Height = 132
          Caption = 'Graphical Properties:'
          TabOrder = 2
          object LabelWeapGraphics: TLabel
            Tag = -1
            Left = 10
            Top = 45
            Width = 45
            Height = 13
            Caption = 'Graphics:'
          end
          object LabelWeapAttackAngle: TLabel
            Tag = -1
            Left = 208
            Top = 91
            Width = 64
            Height = 13
            Caption = 'Attack Angle:'
          end
          object LabelWeapForwardOffset: TLabel
            Tag = -1
            Left = 107
            Top = 91
            Width = 41
            Height = 13
            Caption = 'X Offset:'
          end
          object LabelWeapUpwardOffset: TLabel
            Tag = -1
            Left = 107
            Top = 110
            Width = 41
            Height = 13
            Caption = 'Y Offset:'
          end
          object LabelWeapLaunchSpin: TLabel
            Tag = -1
            Left = 208
            Top = 110
            Width = 63
            Height = 13
            Caption = 'Launch Spin:'
          end
          object LabelWeapRemoveAfter: TLabel
            Tag = -1
            Left = 208
            Top = 25
            Width = 67
            Height = 13
            Caption = 'Remove after:'
          end
          object LabelWeapBehaviour: TLabel
            Tag = -1
            Left = 4
            Top = 25
            Width = 51
            Height = 13
            Caption = 'Behaviour:'
          end
          object LabelWeapIcon: TLabel
            Tag = -1
            Left = 31
            Top = 67
            Width = 24
            Height = 13
            Caption = 'Icon:'
          end
          object LabelEqWeapons1: TLabel
            Tag = -1
            Left = 99
            Top = 46
            Width = 6
            Height = 13
            Caption = '='
          end
          object LabelEqWeapons2: TLabel
            Tag = -1
            Left = 99
            Top = 68
            Width = 6
            Height = 13
            Caption = '='
          end
          object WeapGraphicsList: TComboBox
            Tag = -1
            Left = 106
            Top = 43
            Width = 185
            Height = 21
            AutoComplete = False
            BevelEdges = [beLeft, beRight]
            Style = csDropDownList
            Color = clBlack
            DropDownCount = 10
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ItemHeight = 13
            ParentFont = False
            TabOrder = 3
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object WeapAttackAngle: TEdit
            Tag = 18
            Left = 274
            Top = 86
            Width = 45
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 9
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object WeapLaunchSpin: TEdit
            Tag = 19
            Left = 274
            Top = 106
            Width = 45
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 10
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object WeapBehaviour: TComboBox
            Tag = 8
            Left = 58
            Top = 21
            Width = 149
            Height = 21
            AutoComplete = False
            Style = csDropDownList
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ItemHeight = 13
            ParentFont = False
            TabOrder = 0
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object WeapIconPrevBox: TPanel
            Tag = -1
            Left = 58
            Top = 86
            Width = 42
            Height = 42
            BevelInner = bvRaised
            BevelOuter = bvLowered
            TabOrder = 11
            object WeapIconPrevBG: TPanel
              Tag = -1
              Left = 2
              Top = 2
              Width = 36
              Height = 36
              Align = alCustom
              Caption = 'UpIconPrevBG'
              Color = clBlack
              TabOrder = 0
              object WeapIconPrev: TImage
                Tag = -1
                Left = 2
                Top = 2
                Width = 32
                Height = 32
                Transparent = True
              end
            end
          end
          object WeapIconList: TComboBox
            Tag = -1
            Left = 106
            Top = 65
            Width = 230
            Height = 21
            AutoComplete = False
            BevelEdges = [beLeft, beRight]
            Style = csDropDownList
            Color = clBlack
            DropDownCount = 10
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ItemHeight = 13
            ParentFont = False
            TabOrder = 6
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object WeapOffsetForward: TEdit
            Tag = 20
            Left = 150
            Top = 86
            Width = 45
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 7
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object WeapOffsetUpward: TEdit
            Tag = 21
            Left = 150
            Top = 106
            Width = 45
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 8
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object WeapGraphics: TEdit
            Tag = 1
            Left = 58
            Top = 43
            Width = 43
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 2
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object WeapIcon: TEdit
            Tag = 23
            Left = 58
            Top = 65
            Width = 43
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 5
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object WeapRemoveAfter: TEdit
            Tag = 9
            Left = 278
            Top = 21
            Width = 57
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 1
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object WeapGraphicsJump: TButton
            Tag = 2
            Left = 291
            Top = 43
            Width = 44
            Height = 19
            Caption = 'Jump ->'
            TabOrder = 4
            OnClick = JumpToDATExecute
          end
        end
      end
      object FlingyEdit: TTabSheet
        Tag = -1
        Caption = 'Flingy'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = 15
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ImageIndex = -1
        ParentFont = False
        OnShow = FlingyEditShow
        object FlingyGenProp: TGroupBox
          Tag = -1
          Left = 4
          Top = 15
          Width = 458
          Height = 168
          Caption = 'General Properties:'
          TabOrder = 0
          object LabelFlingySprite: TLabel
            Tag = -1
            Left = 21
            Top = 22
            Width = 49
            Height = 13
            Caption = 'Sprite File:'
          end
          object LabelFlingyMoveControl: TLabel
            Tag = -1
            Left = 4
            Top = 118
            Width = 66
            Height = 13
            Caption = 'Move Control:'
          end
          object LabelFlingySpeed: TLabel
            Tag = -1
            Left = 14
            Top = 42
            Width = 56
            Height = 13
            Caption = 'Top Speed:'
          end
          object LabelFlingyHaltDist: TLabel
            Tag = -1
            Left = 3
            Top = 80
            Width = 67
            Height = 13
            Caption = 'Halt Distance:'
          end
          object LabelFlingyDir: TLabel
            Tag = -1
            Left = 133
            Top = 22
            Width = 6
            Height = 13
            Caption = '='
          end
          object LabelFlingyAcceleration: TLabel
            Tag = -1
            Left = 8
            Top = 62
            Width = 62
            Height = 13
            Caption = 'Acceleration:'
          end
          object LabelFlingyTurnRad: TLabel
            Tag = -1
            Left = 9
            Top = 100
            Width = 61
            Height = 13
            Caption = 'Turn Radius:'
          end
          object LabelFlingyUnused: TLabel
            Tag = -1
            Left = 30
            Top = 138
            Width = 40
            Height = 13
            Caption = 'Unused:'
          end
          object FlingySprite: TEdit
            Left = 72
            Top = 20
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object FlingySpeed: TEdit
            Tag = 1
            Left = 72
            Top = 39
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 3
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object FlingySpriteJump: TButton
            Tag = 3
            Left = 394
            Top = 20
            Width = 55
            Height = 19
            Caption = 'Jump ->'
            TabOrder = 2
            OnClick = JumpToDATExecute
          end
          object FlingySpriteList: TComboBox
            Tag = -1
            Left = 142
            Top = 20
            Width = 250
            Height = 21
            AutoComplete = False
            Style = csDropDownList
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ItemHeight = 13
            ParentFont = False
            TabOrder = 1
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object FlingyAcceleration: TEdit
            Tag = 2
            Left = 72
            Top = 58
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 4
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object FlingyHaltDist: TEdit
            Tag = 3
            Left = 72
            Top = 76
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 5
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object FlingyTurnRad: TEdit
            Tag = 4
            Left = 72
            Top = 94
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 6
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object FlingyMoveControl: TComboBox
            Tag = 6
            Left = 72
            Top = 114
            Width = 175
            Height = 21
            Style = csDropDownList
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ItemHeight = 13
            ParentFont = False
            TabOrder = 7
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object FlingyUnused: TEdit
            Tag = 5
            Left = 72
            Top = 134
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 8
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
        end
      end
      object SpriteEdit: TTabSheet
        Tag = -1
        Caption = 'Sprites'
        ImageIndex = -1
        OnShow = SpriteEditShow
        object SpriteProperties: TGroupBox
          Tag = -1
          Left = 4
          Top = 15
          Width = 458
          Height = 334
          Caption = 'Sprite Properties:'
          TabOrder = 0
          object LabelSpriteImage: TLabel
            Tag = -1
            Left = 21
            Top = 22
            Width = 51
            Height = 13
            Caption = 'Image File:'
          end
          object LabelSpriteDir: TLabel
            Tag = -1
            Left = 133
            Top = 22
            Width = 6
            Height = 13
            Caption = '='
          end
          object LabelSpriteCircleOff: TLabel
            Tag = -1
            Left = 7
            Top = 108
            Width = 65
            Height = 13
            Caption = 'Vert. Position:'
          end
          object Label1: TLabel
            Tag = -1
            Left = 133
            Top = 86
            Width = 6
            Height = 13
            Caption = '='
          end
          object LabelSpriteSelCircle: TLabel
            Tag = -1
            Left = 22
            Top = 66
            Width = 50
            Height = 13
            Caption = 'Sel. Circle:'
          end
          object LabelCircleDir: TLabel
            Tag = -1
            Left = 133
            Top = 64
            Width = 6
            Height = 13
            Caption = '='
          end
          object LabelSpriteHPBar: TLabel
            Tag = -1
            Left = 19
            Top = 86
            Width = 53
            Height = 13
            Caption = 'Health Bar:'
          end
          object Label2: TLabel
            Left = 196
            Top = 88
            Width = 28
            Height = 13
            Caption = 'boxes'
          end
          object SpriteImage: TEdit
            Left = 72
            Top = 20
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object SpriteUnk1: TCheckBox
            Tag = 2
            Left = 142
            Top = 41
            Width = 249
            Height = 19
            Caption = 'Unknown1'
            TabOrder = 4
            OnClick = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object SpriteVisible: TCheckBox
            Tag = 3
            Left = 72
            Top = 41
            Width = 69
            Height = 19
            BiDiMode = bdRightToLeftNoAlign
            Caption = 'Is Visible'
            ParentBiDiMode = False
            TabOrder = 3
            OnClick = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object SpriteImageJump: TButton
            Tag = 4
            Left = 394
            Top = 20
            Width = 55
            Height = 19
            Caption = 'Jump ->'
            TabOrder = 2
            OnClick = JumpToDATExecute
          end
          object SpriteImageList: TComboBox
            Tag = -1
            Left = 142
            Top = 20
            Width = 250
            Height = 21
            AutoComplete = False
            Style = csDropDownList
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ItemHeight = 13
            ParentFont = False
            TabOrder = 1
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object CircleView: TPanel
            Tag = -1
            Left = 142
            Top = 104
            Width = 313
            Height = 228
            BevelOuter = bvNone
            TabOrder = 5
            object LabelSpritePrev: TLabel
              Tag = -1
              Left = 0
              Top = 4
              Width = 41
              Height = 13
              Caption = 'Preview:'
            end
            object CirclePrev: TImage
              Tag = -1
              Left = 67
              Top = 11
              Width = 256
              Height = 256
              Align = alCustom
              Transparent = True
            end
            object CircleUnitPrev: TImage
              Left = 16
              Top = 58
              Width = 256
              Height = 256
              Transparent = True
            end
            object HPBarPrevPanel: TPanel
              Left = 8
              Top = 22
              Width = 49
              Height = 19
              BevelOuter = bvNone
              TabOrder = 0
              object HPBarPrev: TPaintBox
                Left = 0
                Top = 0
                Width = 49
                Height = 19
                Align = alClient
                OnPaint = HPBarPrevPaint
              end
            end
          end
          object SpriteCircleOff: TEdit
            Tag = 5
            Left = 72
            Top = 104
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 6
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object SpriteHPBarbox: TEdit
            Tag = 15004
            Left = 142
            Top = 83
            Width = 34
            Height = 21
            Color = clBlack
            Enabled = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 7
          end
          object SpriteHPBarboxUpDown: TUpDown
            Tag = -1
            Left = 176
            Top = 85
            Width = 17
            Height = 17
            AlignButton = udLeft
            Min = 1
            Max = 84
            Position = 1
            TabOrder = 8
            TabStop = True
            Thousands = False
            Wrap = False
            OnClick = SpriteHPBarboxUpDownClick
          end
          object SpriteSelCircle: TEdit
            Tag = 4
            Left = 72
            Top = 62
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 9
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object SpriteSelCircleList: TComboBox
            Tag = -1
            Left = 142
            Top = 62
            Width = 153
            Height = 21
            AutoComplete = False
            Style = csDropDownList
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ItemHeight = 13
            ParentFont = False
            TabOrder = 10
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object SpriteSelCircleJump: TButton
            Tag = 561004
            Left = 298
            Top = 62
            Width = 55
            Height = 19
            Caption = 'Jump ->'
            TabOrder = 11
            OnClick = JumpToDATExecute
          end
          object SpriteHPBar: TEdit
            Tag = 1
            Left = 72
            Top = 83
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 12
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
        end
      end
      object ImageEdit: TTabSheet
        Tag = -1
        Caption = 'Images'
        ImageIndex = -1
        OnShow = ImageEditShow
        object ImgGenProp: TGroupBox
          Tag = -1
          Left = 4
          Top = 92
          Width = 196
          Height = 70
          Caption = 'General Properties:'
          TabOrder = 1
          DesignSize = (
            196
            70)
          object ImgDrawCloaked: TCheckBox
            Tag = 4
            Left = 2
            Top = 41
            Width = 98
            Height = 21
            Alignment = taLeftJustify
            Anchors = [akLeft]
            Caption = 'Draw If Cloaked'
            TabOrder = 1
            OnClick = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object ImgGfxTurns: TCheckBox
            Tag = 1
            Left = 2
            Top = 20
            Width = 98
            Height = 21
            Alignment = taLeftJustify
            Anchors = [akLeft]
            Caption = 'Graphics Turns'
            TabOrder = 0
            OnClick = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object ImgClickable: TCheckBox
            Tag = 2
            Left = 104
            Top = 20
            Width = 89
            Height = 21
            Anchors = [akLeft]
            Caption = 'Clickable'
            TabOrder = 2
            OnClick = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object ImgUseFullIscript: TCheckBox
            Tag = 3
            Left = 104
            Top = 41
            Width = 90
            Height = 21
            Anchors = [akLeft]
            Caption = 'Use Full Iscript'
            TabOrder = 3
            OnClick = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
        end
        object ImgAnim: TGroupBox
          Tag = -1
          Left = 4
          Top = 168
          Width = 401
          Height = 175
          Caption = 'Extra overlays placement:'
          TabOrder = 3
          object LabelImgOL1: TLabel
            Tag = -1
            Left = 36
            Top = 21
            Width = 34
            Height = 13
            Caption = 'Attack:'
          end
          object LabelEqImg3: TLabel
            Tag = -1
            Left = 133
            Top = 19
            Width = 6
            Height = 13
            Caption = '='
          end
          object LabelImgOL2: TLabel
            Tag = -1
            Left = 27
            Top = 42
            Width = 43
            Height = 13
            Caption = 'Damage:'
          end
          object LabelImgOL3: TLabel
            Tag = -1
            Left = 32
            Top = 63
            Width = 38
            Height = 13
            Caption = 'Special:'
          end
          object LabelImgOL4: TLabel
            Tag = -1
            Left = 4
            Top = 84
            Width = 66
            Height = 13
            Caption = 'Landing Dust:'
          end
          object LabelImgOL5: TLabel
            Tag = -1
            Left = 13
            Top = 105
            Width = 57
            Height = 13
            Caption = 'Lift-off Dust:'
          end
          object LabelShieldOL: TLabel
            Tag = -1
            Left = 19
            Top = 126
            Width = 51
            Height = 13
            Caption = 'Shield Gfx:'
          end
          object LabelEqImg8: TLabel
            Tag = -1
            Left = 133
            Top = 124
            Width = 6
            Height = 13
            Caption = '='
          end
          object LabelEqImg7: TLabel
            Tag = -1
            Left = 133
            Top = 103
            Width = 6
            Height = 13
            Caption = '='
          end
          object LabelEqImg6: TLabel
            Tag = -1
            Left = 133
            Top = 82
            Width = 6
            Height = 13
            Caption = '='
          end
          object LabelEqImg5: TLabel
            Tag = -1
            Left = 133
            Top = 61
            Width = 6
            Height = 13
            Caption = '='
          end
          object LabelEqImg4: TLabel
            Tag = -1
            Left = 133
            Top = 40
            Width = 6
            Height = 13
            Caption = '='
          end
          object ImgOL1: TEdit
            Tag = 9
            Left = 72
            Top = 17
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object ImgOL1List: TComboBox
            Tag = -1
            Left = 142
            Top = 17
            Width = 250
            Height = 21
            AutoComplete = False
            Style = csDropDownList
            Color = clBlack
            DropDownCount = 10
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ItemHeight = 13
            ParentFont = False
            TabOrder = 1
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object ImgOL2: TEdit
            Tag = 10
            Left = 72
            Top = 38
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 2
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object ImgOL3: TEdit
            Tag = 11
            Left = 72
            Top = 59
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 4
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object ImgOL4: TEdit
            Tag = 12
            Left = 72
            Top = 80
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 6
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object ImgOL5: TEdit
            Tag = 13
            Left = 72
            Top = 101
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 8
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object ImgShield: TEdit
            Tag = 8
            Left = 72
            Top = 122
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 10
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object ImgShieldOL: TComboBox
            Tag = -1
            Left = 72
            Top = 143
            Width = 78
            Height = 21
            AutoComplete = False
            Style = csDropDownList
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ItemHeight = 13
            ParentFont = False
            TabOrder = 12
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object ImgOL2List: TComboBox
            Tag = -1
            Left = 142
            Top = 38
            Width = 250
            Height = 21
            AutoComplete = False
            Style = csDropDownList
            Color = clBlack
            DropDownCount = 10
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ItemHeight = 13
            ParentFont = False
            TabOrder = 3
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object ImgOL3List: TComboBox
            Tag = -1
            Left = 142
            Top = 59
            Width = 250
            Height = 21
            AutoComplete = False
            Style = csDropDownList
            Color = clBlack
            DropDownCount = 10
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ItemHeight = 13
            ParentFont = False
            TabOrder = 5
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object ImgOL4List: TComboBox
            Tag = -1
            Left = 142
            Top = 80
            Width = 250
            Height = 21
            AutoComplete = False
            Style = csDropDownList
            Color = clBlack
            DropDownCount = 10
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ItemHeight = 13
            ParentFont = False
            TabOrder = 7
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object ImgOL5List: TComboBox
            Tag = -1
            Left = 142
            Top = 101
            Width = 250
            Height = 21
            AutoComplete = False
            Style = csDropDownList
            Color = clBlack
            DropDownCount = 10
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ItemHeight = 13
            ParentFont = False
            TabOrder = 9
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object ImgShieldList: TComboBox
            Tag = -1
            Left = 142
            Top = 122
            Width = 250
            Height = 21
            AutoComplete = False
            Style = csDropDownList
            Color = clBlack
            DropDownCount = 10
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ItemHeight = 13
            ParentFont = False
            TabOrder = 11
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
        end
        object ImgDrawProp: TGroupBox
          Tag = -1
          Left = 202
          Top = 92
          Width = 260
          Height = 70
          Caption = 'Drawing Properties:'
          TabOrder = 2
          object LabelImgDrawFunction: TLabel
            Tag = -1
            Left = 16
            Top = 24
            Width = 44
            Height = 13
            Caption = 'Function:'
          end
          object LabelImgRemap: TLabel
            Tag = -1
            Left = 3
            Top = 43
            Width = 57
            Height = 13
            Caption = 'Remapping:'
          end
          object LabelEqImg9: TLabel
            Tag = -1
            Left = 89
            Top = 24
            Width = 6
            Height = 13
            Caption = '='
          end
          object LabelEqImg10: TLabel
            Tag = -1
            Left = 89
            Top = 42
            Width = 6
            Height = 13
            Caption = '='
          end
          object ImgRemap: TEdit
            Tag = 6
            Left = 61
            Top = 40
            Width = 30
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 2
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object ImgDrawFunction: TEdit
            Tag = 5
            Left = 61
            Top = 20
            Width = 30
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object ImgRemapList: TComboBox
            Tag = -1
            Left = 96
            Top = 41
            Width = 160
            Height = 21
            AutoComplete = False
            Style = csDropDownList
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ItemHeight = 13
            ParentFont = False
            TabOrder = 3
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object ImgDrawFunctionList: TComboBox
            Tag = -1
            Left = 96
            Top = 20
            Width = 160
            Height = 21
            AutoComplete = False
            Style = csDropDownList
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ItemHeight = 13
            ParentFont = False
            TabOrder = 1
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
        end
        object ImgFile: TGroupBox
          Tag = -1
          Left = 4
          Top = 15
          Width = 458
          Height = 74
          Caption = 'Image File:'
          TabOrder = 0
          object LabelImgGRP: TLabel
            Tag = -1
            Left = 24
            Top = 24
            Width = 45
            Height = 13
            Caption = 'GRP File:'
          end
          object LabelImgIscriptID: TLabel
            Tag = -1
            Left = 24
            Top = 45
            Width = 45
            Height = 13
            Caption = 'Iscript ID:'
          end
          object LabelEqImg2: TLabel
            Tag = -1
            Left = 133
            Top = 43
            Width = 6
            Height = 13
            Caption = '='
          end
          object LabelEqImg1: TLabel
            Tag = -1
            Left = 133
            Top = 22
            Width = 6
            Height = 13
            Caption = '='
          end
          object ImgIscriptID: TEdit
            Tag = 7
            Left = 72
            Top = 41
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 3
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object ImgGRP: TEdit
            Left = 72
            Top = 20
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object ImgGRPList: TComboBox
            Tag = -1
            Left = 142
            Top = 20
            Width = 250
            Height = 21
            AutoComplete = False
            Style = csDropDownList
            Color = clBlack
            DropDownCount = 10
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ItemHeight = 13
            ParentFont = False
            TabOrder = 1
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object ImgIscriptIDList: TComboBox
            Tag = -1
            Left = 142
            Top = 41
            Width = 250
            Height = 21
            AutoComplete = False
            Style = csDropDownList
            Color = clBlack
            DropDownCount = 10
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ItemHeight = 13
            ParentFont = False
            TabOrder = 4
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object ImgIscriptRef: TButton
            Tag = -1
            Left = 394
            Top = 40
            Width = 55
            Height = 20
            Caption = 'Check ->'
            TabOrder = 5
            OnClick = ImgReferenceExecute
          end
          object ImgGRPRef: TButton
            Tag = -1
            Left = 394
            Top = 20
            Width = 55
            Height = 20
            Caption = 'Check ->'
            TabOrder = 2
            OnClick = ImgReferenceExecute
          end
        end
      end
      object UpgradeEdit: TTabSheet
        Tag = -1
        Caption = 'Upgrades'
        ImageIndex = -1
        OnShow = UpgradeEditShow
        object UpgBaseCost: TGroupBox
          Tag = -1
          Left = 4
          Top = 92
          Width = 221
          Height = 89
          Caption = 'Base Cost:'
          TabOrder = 1
          object LabelUpgMinerals: TLabel
            Tag = -1
            Left = 28
            Top = 24
            Width = 42
            Height = 13
            Caption = 'Minerals:'
          end
          object LabelUpgVespene: TLabel
            Tag = -1
            Left = 24
            Top = 41
            Width = 45
            Height = 13
            Caption = 'Vespene:'
          end
          object LabelUpgTime: TLabel
            Tag = -1
            Left = 42
            Top = 58
            Width = 26
            Height = 13
            Caption = 'Time:'
          end
          object LabelEqUpg3: TLabel
            Tag = -1
            Left = 132
            Top = 60
            Width = 6
            Height = 13
            Caption = '='
          end
          object LabelSecUpg: TLabel
            Tag = -1
            Left = 193
            Top = 62
            Width = 20
            Height = 13
            Caption = 'sec.'
          end
          object UpgMinerals: TEdit
            Left = 72
            Top = 20
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object UpgVespene: TEdit
            Tag = 2
            Left = 72
            Top = 38
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 1
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object UpgTime: TEdit
            Tag = 4
            Left = 72
            Top = 56
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 2
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object UpgTimeSec: TEdit
            Tag = 15004
            Left = 139
            Top = 56
            Width = 34
            Height = 21
            Color = clBlack
            Enabled = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 3
          end
          object UpgTimeSecUpDown: TUpDown
            Tag = -1
            Left = 173
            Top = 56
            Width = 17
            Height = 21
            Min = 0
            Max = 32767
            Position = 16383
            TabOrder = 4
            TabStop = True
            Wrap = True
            OnChangingEx = UnitTimeSecUpDownChangingEx
          end
        end
        object UpgFactCost: TGroupBox
          Tag = -1
          Left = 230
          Top = 92
          Width = 200
          Height = 89
          Caption = 'Factor Cost:'
          TabOrder = 2
          object LabelUpgFactorMinerals: TLabel
            Tag = -1
            Left = 8
            Top = 24
            Width = 42
            Height = 13
            Caption = 'Minerals:'
          end
          object LabelUpgFactorVespene: TLabel
            Tag = -13
            Left = 5
            Top = 41
            Width = 45
            Height = 13
            Caption = 'Vespene:'
          end
          object LabelUpgFactorTime: TLabel
            Tag = -1
            Left = 24
            Top = 58
            Width = 26
            Height = 13
            Caption = 'Time:'
          end
          object LabelEqUpg4: TLabel
            Tag = -1
            Left = 112
            Top = 60
            Width = 6
            Height = 13
            Caption = '='
          end
          object LabelSecUpg2: TLabel
            Tag = -1
            Left = 173
            Top = 60
            Width = 20
            Height = 13
            Caption = 'sec.'
          end
          object UpgFactorMinerals: TEdit
            Tag = 1
            Left = 52
            Top = 20
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object UpgFactorVespene: TEdit
            Tag = 3
            Left = 52
            Top = 38
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 1
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object UpgFactorTime: TEdit
            Tag = 5
            Left = 52
            Top = 56
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 2
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object UpgFactorTimeSec: TEdit
            Tag = 15005
            Left = 119
            Top = 56
            Width = 34
            Height = 21
            Color = clBlack
            Enabled = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 3
          end
          object UpgFactorTimeSecUpDown: TUpDown
            Tag = -1
            Left = 153
            Top = 56
            Width = 17
            Height = 21
            Min = 0
            Max = 32767
            Position = 16383
            TabOrder = 4
            TabStop = True
            Wrap = True
            OnChangingEx = UnitTimeSecUpDownChangingEx
          end
        end
        object UpgDisplay: TGroupBox
          Tag = -1
          Left = 4
          Top = 15
          Width = 450
          Height = 73
          Caption = 'Upgrade Display:'
          TabOrder = 0
          object LabelUpgIcon: TLabel
            Tag = -1
            Left = 46
            Top = 24
            Width = 24
            Height = 13
            Caption = 'Icon:'
          end
          object LabelUpgLabel: TLabel
            Tag = -1
            Left = 41
            Top = 44
            Width = 29
            Height = 13
            Alignment = taRightJustify
            Caption = 'Label:'
          end
          object LabelEqUpg1: TLabel
            Tag = -1
            Left = 133
            Top = 22
            Width = 6
            Height = 13
            Caption = '='
          end
          object LabelEqUpg2: TLabel
            Tag = -1
            Left = 133
            Top = 43
            Width = 6
            Height = 13
            Caption = '='
          end
          object UpgIconList: TComboBox
            Tag = -1
            Left = 142
            Top = 20
            Width = 250
            Height = 21
            AutoComplete = False
            BevelEdges = [beLeft, beRight]
            Style = csDropDownList
            Color = clBlack
            DropDownCount = 10
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ItemHeight = 13
            ParentFont = False
            TabOrder = 1
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object UpgLabelList: TComboBox
            Tag = -1
            Left = 142
            Top = 41
            Width = 250
            Height = 21
            AutoComplete = False
            BevelEdges = [beLeft, beRight]
            Style = csDropDownList
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ItemHeight = 13
            ParentFont = False
            TabOrder = 3
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object UpgIconPrevBox: TPanel
            Tag = -1
            Left = 395
            Top = 20
            Width = 42
            Height = 42
            BevelInner = bvRaised
            BevelOuter = bvLowered
            TabOrder = 4
            object UpgIconPrevBG: TPanel
              Tag = -1
              Left = 2
              Top = 2
              Width = 36
              Height = 36
              Align = alCustom
              Caption = 'UpIconPrevBG'
              Color = clBlack
              TabOrder = 0
              object UpgIconPrev: TImage
                Tag = -1
                Left = 2
                Top = 2
                Width = 32
                Height = 32
                Transparent = True
              end
            end
          end
          object UpgIcon: TEdit
            Tag = 7
            Left = 72
            Top = 20
            Width = 60
            Height = 21
            BevelInner = bvLowered
            BevelOuter = bvRaised
            BiDiMode = bdLeftToRight
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentBiDiMode = False
            ParentFont = False
            TabOrder = 0
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object UpgLabel: TEdit
            Tag = 8
            Left = 72
            Top = 41
            Width = 60
            Height = 21
            BevelInner = bvLowered
            BevelOuter = bvRaised
            BiDiMode = bdLeftToRight
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentBiDiMode = False
            ParentFont = False
            TabOrder = 2
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
        end
        object UpgProp: TGroupBox
          Tag = -1
          Left = 4
          Top = 186
          Width = 180
          Height = 101
          Caption = 'Upgrade Properties:'
          TabOrder = 3
          object LabelUpgRace: TLabel
            Tag = 9
            Left = 41
            Top = 58
            Width = 29
            Height = 13
            Caption = 'Race:'
          end
          object LabelUpgRepeats: TLabel
            Tag = -1
            Left = 4
            Top = 24
            Width = 66
            Height = 13
            Caption = 'Max Repeats:'
          end
          object LabelUpgUnk: TLabel
            Tag = -1
            Left = 21
            Top = 41
            Width = 49
            Height = 13
            Caption = 'Unknown:'
          end
          object UpgRepeats: TEdit
            Tag = 10
            Left = 72
            Top = 20
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object UpgUnk: TEdit
            Tag = 6
            Left = 72
            Top = 38
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 1
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object UpgIsBW: TCheckBox
            Tag = 11
            Left = 72
            Top = 78
            Width = 105
            Height = 17
            Caption = 'Brood War'
            TabOrder = 3
            OnClick = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object UpgRace: TComboBox
            Tag = 9
            Left = 72
            Top = 56
            Width = 77
            Height = 21
            AutoComplete = False
            Style = csDropDownList
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ItemHeight = 13
            ParentFont = False
            TabOrder = 2
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
        end
      end
      object TechEdit: TTabSheet
        Tag = -1
        Caption = 'Tech'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = 15
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ImageIndex = -1
        ParentFont = False
        OnShow = TechEditShow
        object TechCost: TGroupBox
          Tag = -1
          Left = 4
          Top = 92
          Width = 226
          Height = 105
          Caption = 'Technology Cost:'
          TabOrder = 1
          object LabelTechMinerals: TLabel
            Tag = -1
            Left = 29
            Top = 22
            Width = 42
            Height = 13
            Caption = 'Minerals:'
          end
          object LabelTechVespene: TLabel
            Tag = -1
            Left = 26
            Top = 40
            Width = 45
            Height = 13
            Caption = 'Vespene:'
          end
          object LabelTechTime: TLabel
            Tag = -1
            Left = 45
            Top = 60
            Width = 26
            Height = 13
            Caption = 'Time:'
          end
          object LabelTechEnergy: TLabel
            Tag = -1
            Left = 35
            Top = 78
            Width = 36
            Height = 13
            Caption = 'Energy:'
          end
          object LabelEqTech3: TLabel
            Tag = -1
            Left = 132
            Top = 60
            Width = 6
            Height = 13
            Caption = '='
          end
          object LabelSecTech: TLabel
            Tag = -1
            Left = 193
            Top = 60
            Width = 20
            Height = 13
            Caption = 'sec.'
          end
          object TechMinerals: TEdit
            Left = 72
            Top = 20
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object TechVespene: TEdit
            Tag = 1
            Left = 72
            Top = 38
            Width = 60
            Height = 21
            BevelEdges = [beLeft, beRight]
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            MaxLength = 5
            ParentFont = False
            TabOrder = 1
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object TechTime: TEdit
            Tag = 2
            Left = 72
            Top = 56
            Width = 60
            Height = 21
            BevelEdges = [beLeft, beRight]
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            MaxLength = 5
            ParentFont = False
            TabOrder = 2
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object TechEnergy: TEdit
            Tag = 3
            Left = 72
            Top = 74
            Width = 60
            Height = 21
            BevelEdges = [beLeft, beRight]
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            MaxLength = 5
            ParentFont = False
            TabOrder = 5
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object TechTimeSec: TEdit
            Tag = 15002
            Left = 139
            Top = 56
            Width = 34
            Height = 21
            Color = clBlack
            Enabled = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 3
          end
          object TechTimeSecUpDown: TUpDown
            Tag = -1
            Left = 173
            Top = 56
            Width = 17
            Height = 21
            Min = 0
            Max = 32767
            Position = 16383
            TabOrder = 4
            TabStop = True
            Wrap = True
            OnChangingEx = UnitTimeSecUpDownChangingEx
          end
        end
        object TechProperties: TGroupBox
          Tag = -1
          Left = 236
          Top = 92
          Width = 160
          Height = 105
          Caption = 'Technology Properties:'
          TabOrder = 2
          object LabelRace: TLabel
            Tag = -1
            Left = 32
            Top = 22
            Width = 29
            Height = 13
            Caption = 'Race:'
          end
          object LabelTechUnk: TLabel
            Tag = -1
            Left = 12
            Top = 80
            Width = 49
            Height = 13
            Caption = 'Unknown:'
          end
          object TechUnk: TEdit
            Tag = 4
            Left = 64
            Top = 78
            Width = 80
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 3
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object TechRace: TComboBox
            Tag = 7
            Left = 64
            Top = 18
            Width = 80
            Height = 21
            AutoComplete = False
            Style = csDropDownList
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ItemHeight = 13
            ParentFont = False
            TabOrder = 0
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object TechUnused: TCheckBox
            Tag = 8
            Left = 64
            Top = 40
            Width = 91
            Height = 19
            Caption = 'Unused'
            TabOrder = 1
            OnClick = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object TechBW: TCheckBox
            Tag = 9
            Left = 64
            Top = 58
            Width = 91
            Height = 17
            Caption = 'BroodWar'
            TabOrder = 2
            OnClick = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
        end
        object TechDisplay: TGroupBox
          Tag = -1
          Left = 4
          Top = 15
          Width = 450
          Height = 73
          Caption = 'Technology Display:'
          TabOrder = 0
          object LabelTechIcon: TLabel
            Tag = -1
            Left = 46
            Top = 24
            Width = 24
            Height = 13
            Caption = 'Icon:'
          end
          object LabelTechLabel: TLabel
            Tag = -1
            Left = 41
            Top = 44
            Width = 29
            Height = 13
            Alignment = taRightJustify
            Caption = 'Label:'
          end
          object LabelTechEq1: TLabel
            Tag = -1
            Left = 133
            Top = 22
            Width = 6
            Height = 13
            Caption = '='
          end
          object LabelTechEq2: TLabel
            Tag = -1
            Left = 133
            Top = 43
            Width = 6
            Height = 13
            Caption = '='
          end
          object TechIconList: TComboBox
            Tag = -1
            Left = 142
            Top = 20
            Width = 250
            Height = 21
            AutoComplete = False
            BevelEdges = [beLeft, beRight]
            Style = csDropDownList
            Color = clBlack
            DropDownCount = 10
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ItemHeight = 13
            ParentFont = False
            TabOrder = 1
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object TechLabelList: TComboBox
            Tag = -1
            Left = 142
            Top = 41
            Width = 250
            Height = 21
            AutoComplete = False
            BevelEdges = [beLeft, beRight]
            Style = csDropDownList
            Color = clBlack
            DropDownCount = 10
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ItemHeight = 13
            ParentFont = False
            TabOrder = 3
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object TechIconPrevBox: TPanel
            Tag = -1
            Left = 395
            Top = 20
            Width = 42
            Height = 42
            BevelInner = bvRaised
            BevelOuter = bvLowered
            TabOrder = 4
            object TechIconPrevBG: TPanel
              Tag = -1
              Left = 2
              Top = 2
              Width = 36
              Height = 36
              Align = alCustom
              Caption = 'UpIconPrevBG'
              Color = clBlack
              TabOrder = 0
              object TechIconPrev: TImage
                Tag = -1
                Left = 2
                Top = 2
                Width = 32
                Height = 32
                Transparent = True
              end
            end
          end
          object TechLabel: TEdit
            Tag = 6
            Left = 72
            Top = 41
            Width = 60
            Height = 21
            BevelInner = bvLowered
            BevelOuter = bvRaised
            BiDiMode = bdLeftToRight
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentBiDiMode = False
            ParentFont = False
            TabOrder = 2
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object TechIcon: TEdit
            Tag = 5
            Left = 72
            Top = 20
            Width = 60
            Height = 21
            BevelInner = bvLowered
            BevelOuter = bvRaised
            BiDiMode = bdLeftToRight
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentBiDiMode = False
            ParentFont = False
            TabOrder = 0
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
        end
      end
      object SoundEdit: TTabSheet
        Tag = -1
        Caption = 'Sounds'
        ImageIndex = -1
        OnShow = SoundEditShow
        object SoundGenProp: TGroupBox
          Tag = -1
          Left = 4
          Top = 76
          Width = 151
          Height = 109
          Caption = 'General Properties:'
          TabOrder = 1
          object LabelSoundUnk1: TLabel
            Tag = -1
            Left = 10
            Top = 22
            Width = 58
            Height = 13
            Caption = 'Unknown 1:'
          end
          object LabelSoundUnk2: TLabel
            Tag = -1
            Left = 10
            Top = 40
            Width = 58
            Height = 13
            Caption = 'Unknown 2:'
          end
          object LabelSoundUnk3: TLabel
            Tag = -1
            Left = 10
            Top = 58
            Width = 58
            Height = 13
            Caption = 'Unknown 3:'
          end
          object LabelSoundUnk4: TLabel
            Tag = -1
            Left = 13
            Top = 76
            Width = 55
            Height = 13
            Caption = 'Unknown4:'
          end
          object SoundUnk1: TEdit
            Tag = 1
            Left = 74
            Top = 18
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object SoundUnk2: TEdit
            Tag = 2
            Left = 74
            Top = 36
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 1
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object SoundUnk3: TEdit
            Tag = 3
            Left = 74
            Top = 54
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 2
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object SoundUnk4: TEdit
            Tag = 4
            Left = 74
            Top = 72
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 3
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
        end
        object SoundFileProp: TGroupBox
          Tag = -1
          Left = 4
          Top = 15
          Width = 420
          Height = 55
          Caption = 'Sound:'
          TabOrder = 0
          object LabelSoundFile: TLabel
            Tag = -1
            Left = 18
            Top = 24
            Width = 53
            Height = 13
            Caption = 'Sound File:'
          end
          object LabelSoundDir: TLabel
            Tag = -1
            Left = 133
            Top = 22
            Width = 6
            Height = 13
            Caption = '='
          end
          object SoundFile: TEdit
            Left = 72
            Top = 20
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object SoundFileList: TComboBox
            Tag = -1
            Left = 142
            Top = 20
            Width = 250
            Height = 21
            AutoComplete = False
            Style = csDropDownList
            Color = clBlack
            DropDownCount = 10
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ItemHeight = 13
            ParentFont = False
            TabOrder = 1
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
        end
      end
      object PortEdit: TTabSheet
        Tag = -1
        Caption = 'Portraits'
        ImageIndex = -1
        OnShow = PortEditShow
        object PortDirProp: TGroupBox
          Tag = -1
          Left = 4
          Top = 15
          Width = 420
          Height = 55
          Caption = 'Portrait:'
          TabOrder = 0
          object LabelPortFile: TLabel
            Tag = -1
            Left = 18
            Top = 24
            Width = 52
            Height = 13
            Caption = 'Portrait Dir:'
          end
          object LabelPortEq: TLabel
            Tag = -1
            Left = 133
            Top = 22
            Width = 6
            Height = 13
            Caption = '='
          end
          object PortFile: TEdit
            Left = 72
            Top = 20
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object PortFileList: TComboBox
            Tag = -1
            Left = 142
            Top = 20
            Width = 250
            Height = 21
            AutoComplete = False
            Style = csDropDownList
            Color = clBlack
            DropDownCount = 10
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ItemHeight = 13
            ParentFont = False
            TabOrder = 1
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
        end
        object PortGenProp: TGroupBox
          Tag = -1
          Left = 4
          Top = 76
          Width = 150
          Height = 81
          Caption = 'General Properties:'
          TabOrder = 1
          object LabelPortUnk1: TLabel
            Tag = -1
            Left = 13
            Top = 48
            Width = 58
            Height = 13
            Caption = 'Unknown 1:'
          end
          object LabelPortSMK: TLabel
            Tag = -1
            Left = 5
            Top = 30
            Width = 65
            Height = 13
            Caption = 'SMK change:'
          end
          object PortSMKChange: TEdit
            Tag = 1
            Left = 72
            Top = 26
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object PortUnk1: TEdit
            Tag = 2
            Left = 72
            Top = 44
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 1
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
        end
      end
      object MapEdit: TTabSheet
        Tag = -1
        Caption = 'Campaign'
        ImageIndex = -1
        OnShow = MapEditShow
        object MapData: TGroupBox
          Tag = -1
          Left = 4
          Top = 15
          Width = 420
          Height = 55
          Caption = 'Campaign Properties:'
          TabOrder = 0
          object LabelMapFile: TLabel
            Tag = -1
            Left = 16
            Top = 24
            Width = 54
            Height = 13
            Caption = 'Mission Dir:'
          end
          object LabelMapEq: TLabel
            Tag = -1
            Left = 133
            Top = 22
            Width = 6
            Height = 13
            Caption = '='
          end
          object MapFile: TEdit
            Left = 72
            Top = 20
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object MapFileList: TComboBox
            Tag = -1
            Left = 142
            Top = 20
            Width = 250
            Height = 21
            AutoComplete = False
            Style = csDropDownList
            Color = clBlack
            DropDownCount = 10
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ItemHeight = 13
            ParentFont = False
            TabOrder = 1
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
        end
      end
      object OrderEdit: TTabSheet
        Tag = -1
        Caption = 'Orders'
        ImageIndex = -1
        OnShow = OrderEditShow
        object OrdFlags: TGroupBox
          Tag = -1
          Left = 4
          Top = 204
          Width = 420
          Height = 93
          Caption = 'Flags:'
          TabOrder = 1
          object OrdWeapTarg: TCheckBox
            Tag = 1
            Left = 8
            Top = 20
            Width = 135
            Height = 17
            Caption = 'Use Weapon Targeting'
            TabOrder = 0
            OnClick = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object OrdUnk2: TCheckBox
            Tag = 2
            Left = 8
            Top = 36
            Width = 135
            Height = 17
            Caption = 'Secondary Order'
            TabOrder = 1
            OnClick = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object OrdUnk5: TCheckBox
            Tag = 5
            Left = 147
            Top = 20
            Width = 135
            Height = 17
            Caption = 'Unknown5'
            TabOrder = 4
            OnClick = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object OrdInterrupt: TCheckBox
            Tag = 6
            Left = 147
            Top = 36
            Width = 135
            Height = 17
            Caption = 'Can Be Interrupted'
            TabOrder = 5
            OnClick = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object OrdUnk9: TCheckBox
            Tag = 9
            Left = 282
            Top = 20
            Width = 135
            Height = 17
            Caption = 'Unknown9'
            TabOrder = 8
            OnClick = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object OrdUnk10: TCheckBox
            Tag = 10
            Left = 282
            Top = 36
            Width = 135
            Height = 17
            Caption = 'Unknown10'
            TabOrder = 9
            OnClick = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object OrdUnk11: TCheckBox
            Tag = 11
            Left = 282
            Top = 52
            Width = 135
            Height = 17
            Caption = 'Unknown11'
            TabOrder = 10
            OnClick = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object OrdUnk12: TCheckBox
            Tag = 12
            Left = 282
            Top = 68
            Width = 135
            Height = 17
            Caption = 'Unknown12'
            TabOrder = 11
            OnClick = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object OrdUnk7: TCheckBox
            Tag = 7
            Left = 147
            Top = 52
            Width = 135
            Height = 17
            Caption = 'Unknown7'
            TabOrder = 6
            OnClick = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object OrdQueue: TCheckBox
            Tag = 8
            Left = 147
            Top = 68
            Width = 135
            Height = 17
            Caption = 'Can be Queued'
            TabOrder = 7
            OnClick = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object OrdUnk3: TCheckBox
            Tag = 3
            Left = 8
            Top = 52
            Width = 135
            Height = 17
            Caption = 'Unknown3'
            TabOrder = 2
            OnClick = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object OrdUnk4: TCheckBox
            Tag = 4
            Left = 8
            Top = 68
            Width = 135
            Height = 17
            Caption = 'Unknown4'
            TabOrder = 3
            OnClick = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
        end
        object OrdProp: TGroupBox
          Tag = -1
          Left = 4
          Top = 15
          Width = 420
          Height = 186
          Caption = 'Order Properties:'
          TabOrder = 0
          object LabelOrdLabel: TLabel
            Tag = -1
            Left = 19
            Top = 87
            Width = 41
            Height = 13
            Alignment = taRightJustify
            Caption = 'Label(?):'
          end
          object LabelOrdObscured: TLabel
            Tag = -1
            Left = 11
            Top = 66
            Width = 49
            Height = 13
            Alignment = taRightJustify
            Caption = 'Obscured:'
          end
          object LabelOrdAnimation: TLabel
            Tag = -1
            Left = 11
            Top = 108
            Width = 49
            Height = 13
            Alignment = taRightJustify
            Caption = 'Animation:'
          end
          object LabelOrdTargeting: TLabel
            Tag = -1
            Left = 12
            Top = 24
            Width = 48
            Height = 13
            Alignment = taRightJustify
            Caption = 'Targeting:'
          end
          object LabelOrdEnergy: TLabel
            Tag = -1
            Left = 24
            Top = 45
            Width = 36
            Height = 13
            Alignment = taRightJustify
            Caption = 'Energy:'
          end
          object LabelOrdHighlight: TLabel
            Tag = -1
            Left = 16
            Top = 129
            Width = 44
            Height = 13
            Caption = 'Highlight:'
          end
          object OrdEq1: TLabel
            Tag = -1
            Left = 118
            Top = 127
            Width = 6
            Height = 13
            Caption = '='
          end
          object LabelOrdUnk13: TLabel
            Tag = -1
            Left = 11
            Top = 150
            Width = 49
            Height = 13
            Caption = 'Unknown:'
          end
          object OrdLabel: TComboBox
            Left = 60
            Top = 83
            Width = 249
            Height = 21
            AutoComplete = False
            BevelEdges = [beLeft, beRight]
            Style = csDropDownList
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ItemHeight = 13
            ParentFont = False
            TabOrder = 5
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object OrdObscured: TComboBox
            Tag = 18
            Left = 60
            Top = 62
            Width = 249
            Height = 21
            AutoComplete = False
            BevelEdges = [beLeft, beRight]
            Style = csDropDownList
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ItemHeight = 13
            ParentFont = False
            TabOrder = 4
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object OrdAnimation: TComboBox
            Tag = 15
            Left = 60
            Top = 104
            Width = 249
            Height = 21
            AutoComplete = False
            BevelEdges = [beLeft, beRight]
            Style = csDropDownList
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ItemHeight = 13
            ParentFont = False
            TabOrder = 6
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object OrdTargeting: TComboBox
            Tag = 13
            Left = 60
            Top = 20
            Width = 249
            Height = 21
            AutoComplete = False
            BevelEdges = [beLeft, beRight]
            Style = csDropDownList
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ItemHeight = 13
            ParentFont = False
            TabOrder = 0
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object OrdEnergy: TComboBox
            Tag = 14
            Left = 60
            Top = 41
            Width = 249
            Height = 21
            AutoComplete = False
            BevelEdges = [beLeft, beRight]
            Style = csDropDownList
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ItemHeight = 13
            ParentFont = False
            TabOrder = 2
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object OrdEnergyJump: TButton
            Tag = 6
            Left = 312
            Top = 41
            Width = 55
            Height = 19
            Caption = 'Jump ->'
            TabOrder = 3
            OnClick = JumpToDATExecute
          end
          object OrdTargetingJump: TButton
            Tag = 1
            Left = 312
            Top = 20
            Width = 55
            Height = 19
            Caption = 'Jump ->'
            TabOrder = 1
            OnClick = JumpToDATExecute
          end
          object OrdHighlight: TEdit
            Tag = 16
            Left = 60
            Top = 125
            Width = 60
            Height = 21
            BevelInner = bvLowered
            BevelOuter = bvRaised
            BiDiMode = bdLeftToRight
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentBiDiMode = False
            ParentFont = False
            TabOrder = 7
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object OrdHighlightList: TComboBox
            Tag = -1
            Left = 126
            Top = 125
            Width = 227
            Height = 21
            AutoComplete = False
            BevelEdges = [beLeft, beRight]
            Style = csDropDownList
            Color = clBlack
            DropDownCount = 10
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ItemHeight = 13
            ParentFont = False
            TabOrder = 8
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
          end
          object OrdHighlistPrevBox: TPanel
            Tag = -1
            Left = 310
            Top = 82
            Width = 42
            Height = 42
            BevelInner = bvRaised
            BevelOuter = bvLowered
            TabOrder = 10
            object OrdHighlightBG: TPanel
              Tag = -1
              Left = 2
              Top = 2
              Width = 36
              Height = 36
              Align = alCustom
              Caption = 'UpIconPrevBG'
              Color = clBlack
              TabOrder = 0
              object OrdHighlightPrev: TImage
                Tag = -1
                Left = 2
                Top = 2
                Width = 32
                Height = 32
                Transparent = True
              end
            end
          end
          object OrdUnk13: TEdit
            Tag = 17
            Left = 60
            Top = 146
            Width = 60
            Height = 21
            Color = clBlack
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWhite
            Font.Height = 15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 9
            OnChange = ChangeDataBoxExecute
            OnEnter = LoadHintExecute
            OnExit = ExitEditExecute
          end
          object OrdHighlightClear: TButton
            Tag = 6
            Left = 356
            Top = 125
            Width = 60
            Height = 19
            Caption = 'Clear'
            TabOrder = 11
            OnClick = OrdHighlightClearClick
          end
        end
      end
    end
    object InfoTab: TTabControl
      Left = 0
      Top = 390
      Width = 546
      Height = 176
      Align = alBottom
      Anchors = [akLeft, akTop, akRight, akBottom]
      Constraints.MaxHeight = 176
      TabOrder = 1
      object InfoBox: TGroupBox
        Tag = -1
        Left = 4
        Top = 6
        Width = 538
        Height = 166
        Align = alClient
        Caption = 'Info:'
        Constraints.MaxHeight = 176
        TabOrder = 0
        object LabelUsed: TLabel
          Tag = -1
          Left = 210
          Top = 0
          Width = 43
          Height = 13
          Caption = 'Used by:'
          Visible = False
        end
        object InfoboxSplitter: TSplitter
          Left = 207
          Top = 15
          Width = 2
          Height = 149
          Cursor = crHSplit
          ResizeStyle = rsUpdate
          OnMoved = InfoboxSplitterMoved
        end
        object InfoText: TMemo
          Tag = -1
          Left = 2
          Top = 15
          Width = 205
          Height = 149
          Align = alLeft
          Color = clBlack
          Constraints.MinWidth = 40
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          ReadOnly = True
          ScrollBars = ssVertical
          TabOrder = 0
          WantReturns = False
        end
        object UsedList: TListBox
          Tag = -1
          Left = 209
          Top = 15
          Width = 327
          Height = 149
          Align = alClient
          Color = clBlack
          ExtendedSelect = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ItemHeight = 13
          ParentFont = False
          TabOrder = 1
          OnDblClick = UsedListDblClick
        end
      end
    end
  end
  object ElGrandoListos: TPanel
    Tag = -1
    Left = 0
    Top = 0
    Width = 318
    Height = 566
    Align = alLeft
    BevelOuter = bvNone
    Caption = 'Entry listings are created programmatically'
    Constraints.MinWidth = 65
    FullRepaint = False
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWhite
    Font.Height = -11
    Font.Name = 'Microsoft Sans Serif'
    Font.Style = []
    ParentFont = False
    PopupMenu = PopupMenu
    TabOrder = 0
    object SearchPanel: TPanel
      Tag = -1
      Left = 0
      Top = 544
      Width = 318
      Height = 22
      Align = alBottom
      Alignment = taLeftJustify
      BevelOuter = bvNone
      Constraints.MaxHeight = 22
      Constraints.MinWidth = 100
      Font.Charset = EASTEUROPE_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      object JumpToIDLabel: TLabel
        Tag = -1
        Left = 210
        Top = 4
        Width = 42
        Height = 13
        Caption = 'ID Jump:'
      end
      object SearchButton: TButton
        Tag = -1
        Left = 2
        Top = 0
        Width = 50
        Height = 20
        Caption = 'Search'
        Font.Charset = EASTEUROPE_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Microsoft Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        OnClick = SearchButtonClick
      end
      object SearchText: TComboBox
        Tag = -1
        Left = 54
        Top = 0
        Width = 153
        Height = 21
        Color = clBlack
        Font.Charset = EASTEUROPE_CHARSET
        Font.Color = clWhite
        Font.Height = -11
        Font.Name = 'Microsoft Sans Serif'
        Font.Style = []
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
        OnKeyDown = SearchTextKeyDown
      end
      object JumpToID: TEdit
        Tag = -1
        Left = 253
        Top = 0
        Width = 44
        Height = 21
        Color = clBlack
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = 15
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        OnKeyDown = JumpToIDKeyDown
      end
      object JumpToIDButton: TButton
        Left = 296
        Top = 0
        Width = 20
        Height = 20
        Caption = '->'
        TabOrder = 3
        OnClick = JumpToIDButtonClick
      end
    end
  end
  object StatusBar: TStatusBar
    Tag = -1
    Left = 0
    Top = 566
    Width = 866
    Height = 20
    Anchors = [akBottom]
    Panels = <
      item
        Width = 600
      end>
    SimplePanel = False
  end
  object PopupMenu: TPopupMenu
    Tag = -1
    AutoHotkeys = maManual
    OnPopup = PopupMenuPopup
    Left = 40
    Top = 160
    object QuickBM: TMenuItem
      Tag = -1
      AutoHotkeys = maManual
      Caption = 'Quick Bookmarks'
      Visible = False
    end
    object Bookmarkentry1: TMenuItem
      Tag = -1
      Action = BookmarkEntry
    end
    object Erasebookmark1: TMenuItem
      Tag = -1
      Action = BookmarkErase
    end
    object N8: TMenuItem
      Tag = -1
      AutoHotkeys = maManual
      Caption = '-'
    end
    object CopyEntry1: TMenuItem
      Tag = -1
      Action = Copy
    end
    object PasteEntry1: TMenuItem
      Tag = -1
      Action = Paste
    end
    object N15: TMenuItem
      Tag = -1
      Caption = '-'
    end
    object ClipCopy2: TMenuItem
      Caption = '&Copy to Clipboard'
      ShortCut = 49219
      OnClick = ClipCopyClick
    end
    object ClipPaste2: TMenuItem
      Caption = 'Paste from Clipboard'
      ShortCut = 49238
      OnClick = ClipPasteClick
    end
    object N13: TMenuItem
      Tag = -1
      Caption = '-'
    end
    object ReloadEntry1: TMenuItem
      Tag = -1
      Action = ReloadEntry
    end
  end
  object Actions: TActionList
    Tag = -1
    Left = 100
    Top = 160
    object Exit: TFileExit
      Tag = -1
      Category = 'File'
      Caption = 'E&xit'
      Hint = 'Exit|Quits the application'
      ImageIndex = 43
      ShortCut = 32883
    end
    object Open: TAction
      Tag = -1
      Category = 'File'
      Caption = 'Open File...'
      ShortCut = 16463
      OnExecute = OpenExecute
    end
    object Save: TAction
      Tag = -1
      Category = 'File'
      Caption = '&Save'
      ShortCut = 16467
      OnExecute = SaveExecute
    end
    object ExitEdit: TAction
      Tag = -1
      Category = 'ChangeUI'
      Caption = 'ExitEdit'
      OnExecute = ExitEditExecute
    end
    object ChangeTab: TAction
      Tag = -1
      Category = 'ChangeUI'
      Caption = 'ChangeTab'
      OnExecute = ChangeTabExecute
    end
    object ChangeDataBox: TAction
      Tag = -1
      Category = 'ChangeUI'
      Caption = 'ChangeDataBox'
      OnExecute = ChangeDataBoxExecute
    end
    object BookmarkClick: TAction
      Tag = -1
      Category = 'Other'
      OnExecute = BookmarkClickExecute
    end
    object BookmarkEntry: TAction
      Tag = -1
      Category = 'Other'
      Caption = 'Bookmark entry'
      ShortCut = 24642
      OnExecute = BookmarkEntryExecute
    end
    object BookmarkErase: TAction
      Category = 'Other'
      Caption = '&Erase bookmark'
      ShortCut = 24645
      Visible = False
      OnExecute = BookmarkEraseExecute
    end
    object ClearAllBookmarks: TAction
      Tag = -1
      Category = 'Other'
      Caption = 'Clear All Bookmarks'
      OnExecute = ClearAllBookmarksExecute
    end
    object ClearBookmarks: TAction
      Tag = -1
      Category = 'Other'
      Caption = 'Clear Bookmarks'
      OnExecute = ClearBookmarksExecute
    end
    object ClearHistory: TAction
      Tag = -1
      Category = 'Other'
      Caption = 'Clear History'
      OnExecute = ClearHistoryExecute
    end
    object ImgReference: TAction
      Tag = -1
      Category = 'Other'
      OnExecute = ImgReferenceExecute
    end
    object JumpToDAT: TAction
      Tag = -1
      Category = 'Other'
      Caption = 'Jump ->'
      OnExecute = JumpToDATExecute
    end
    object LoadHistoryItem: TAction
      Tag = -1
      Category = 'Other'
      OnExecute = LoadHistoryItemExecute
    end
    object LoadHint: TAction
      Tag = -1
      Category = 'Other'
      OnExecute = LoadHintExecute
    end
    object SaveAs: TAction
      Tag = -1
      Category = 'File'
      Caption = 'Save &As...'
      ShortCut = 16449
      OnExecute = SaveAsExecute
    end
    object OpenDir: TAction
      Tag = -1
      Category = 'File'
      Caption = 'Open &Directory...'
      ShortCut = 16452
      OnExecute = OpenDirExecute
    end
    object ReloadEntry: TAction
      Tag = -1
      Category = 'File'
      Caption = 'Reload ent&ry'
      ShortCut = 16466
      OnExecute = ReloadEntryExecute
    end
    object FileExport: TAction
      Tag = -1
      Category = 'File'
      Caption = 'Expor&t to MPQ/EXE...'
      ShortCut = 16468
      OnExecute = FileExportExecute
    end
    object Copy: TAction
      Tag = -1
      Category = 'Edit'
      Caption = '&Copy entry'
      ShortCut = 24643
      OnExecute = CopyExecute
    end
    object CopyTab: TAction
      Tag = -1
      Category = 'Edit'
      Caption = 'Cop&y Tab'
      ShortCut = 16473
      OnExecute = CopyTabExecute
    end
    object Paste: TAction
      Tag = -1
      Category = 'Edit'
      Caption = 'Paste entry'
      ShortCut = 24662
      OnExecute = PasteExecute
    end
    object PasteTab: TAction
      Tag = -1
      Category = 'Edit'
      Caption = 'Paste Ta&b'
      ShortCut = 16450
      OnExecute = PasteTabExecute
    end
    object PasteMixed: TAction
      Tag = -1
      Category = 'Edit'
      Caption = 'Past&e Mixed'
      ShortCut = 16453
      OnExecute = PasteMixedExecute
    end
    object ReloadDefault: TAction
      Tag = -1
      Category = 'Edit'
      Caption = 'Re&load Default'
      ShortCut = 16460
      OnExecute = ReloadDefaultExecute
    end
    object ReadConfig: TAction
      Tag = -1
      Category = 'Config'
      OnExecute = ReadConfigExecute
    end
    object SaveConfig: TAction
      Tag = -1
      Category = 'Config'
      OnExecute = SaveConfigExecute
    end
    object ReadConfigOptions: TAction
      Tag = -1
      Category = 'Config'
      OnExecute = ReadConfigOptionsExecute
    end
    object SaveConfigOptions: TAction
      Tag = -1
      Category = 'Config'
      OnExecute = SaveConfigOptionsExecute
    end
    object SetSorting: TAction
      Tag = -1
      Category = 'Other'
      OnExecute = SetSortingExecute
    end
    object SearchList: TAction
      Tag = -1
      Category = 'Other'
      OnExecute = SearchListExecute
    end
    object PropertySort: TAction
      Tag = -1
      Category = 'Other'
      OnExecute = PropertySortExecute
    end
    object ReadBookmarks: TAction
      Tag = -1
      Category = 'Config'
      Caption = 'ReadBookmarks'
      OnExecute = ReadBookmarksExecute
    end
    object FAQClick: TAction
      Category = 'FAQ'
      Caption = 'FAQClick'
      OnExecute = FAQClickExecute
    end
    object LoadFAQ: TAction
      Category = 'FAQ'
      Caption = 'LoadFAQ'
      OnExecute = LoadFAQExecute
    end
    object ExternalProgramsChange: TAction
      Category = 'Other'
      Caption = 'ExternalProgramsChange'
      OnExecute = ExternalProgramsChangeExecute
    end
    object LoadExternalProgram: TAction
      Category = 'Other'
      Caption = 'LoadExternalProgram'
      OnExecute = LoadExternalProgramExecute
    end
    object ReadLabels: TAction
      Category = 'Config'
      Caption = 'ReadLabels'
      OnExecute = ReadLabelsExecute
    end
  end
  object OpenDialog: TOpenDialog
    Tag = -1
    DefaultExt = 'dat'
    Filter = 'DAT and MPQ files (*.dat, *.mpq)|*.dat;*.mpq|All Files (*.*)|*.*'
    Options = [ofOverwritePrompt, ofHideReadOnly, ofPathMustExist, ofFileMustExist, ofNoReadOnlyReturn, ofEnableSizing]
    OnCanClose = OpenDialogCanClose
    Left = 130
    Top = 160
  end
  object FileSaveDialog: TSaveDialog
    Tag = -1
    DefaultExt = 'dat'
    Filter = 'DAT files (*.dat)|*.dat|All Files (*.*)|*.*'
    OnCanClose = FileSaveDialogCanClose
    Left = 160
    Top = 160
  end
  object ExportSaveDialog: TSaveDialog
    Tag = -1
    DefaultExt = 'mpq'
    Filter = 
      'MPQ archives (*.mpq)|*.mpq|Executable files (*.exe)|*.exe|All Fi' +
      'les (*.*)|*.*'
    OnCanClose = ExportSaveDialogCanClose
    Left = 190
    Top = 160
  end
  object MainMenu: TMainMenu
    Tag = -1
    AutoHotkeys = maManual
    Left = 70
    Top = 160
    object FileMenu: TMenuItem
      Tag = -1
      AutoHotkeys = maAutomatic
      Caption = '&File'
      OnClick = FileMenuClick
      object OpenFile: TMenuItem
        Tag = -1
        Action = Open
      end
      object OpenDirectory: TMenuItem
        Tag = -1
        Action = OpenDir
      end
      object MRUD: TMenuItem
        Tag = -1
        AutoHotkeys = maManual
        Caption = 'History'
      end
      object N10: TMenuItem
        Tag = -1
        Caption = '-'
      end
      object OptionsMenu: TMenuItem
        Tag = -1
        Caption = 'Options...'
        OnClick = OptionsMenuClick
      end
      object N4: TMenuItem
        Tag = -1
        Caption = '-'
      end
      object FileCompareMerge: TMenuItem
        Tag = -1
        Caption = 'Co&mpare/Merge Files...'
        ShortCut = 16461
        OnClick = FileCompareMergeClick
      end
      object N1: TMenuItem
        Tag = -1
        Caption = '-'
      end
      object FileSave: TMenuItem
        Tag = -1
        Action = Save
      end
      object FileSaveAs: TMenuItem
        Tag = -1
        Action = SaveAs
      end
      object FileExportButton: TMenuItem
        Action = FileExport
        Caption = 'Expor&t file(s)...'
      end
      object N2: TMenuItem
        Tag = -1
        Caption = '-'
      end
      object Exit1: TMenuItem
        Tag = -1
        Action = Exit
      end
    end
    object EditMenu: TMenuItem
      Tag = -1
      Caption = '&Edit'
      OnClick = EditMenuClick
      object Copy1: TMenuItem
        Tag = -1
        Action = Copy
      end
      object Paste1: TMenuItem
        Tag = -1
        Action = Paste
      end
      object N5: TMenuItem
        Tag = -1
        Caption = '-'
      end
      object ClipCopy: TMenuItem
        Caption = '&Copy to Clipboard'
        ShortCut = 49219
        OnClick = ClipCopyClick
      end
      object ClipPaste: TMenuItem
        Caption = 'Paste from Clipboard'
        ShortCut = 49238
        OnClick = ClipPasteClick
      end
      object N11: TMenuItem
        Caption = '-'
      end
      object CopyTab1: TMenuItem
        Tag = -1
        Action = CopyTab
      end
      object PasteTab1: TMenuItem
        Tag = -1
        Action = PasteTab
      end
      object N6: TMenuItem
        Tag = -1
        Caption = '-'
      end
      object PasteMixed1: TMenuItem
        Tag = -1
        Action = PasteMixed
      end
      object N14: TMenuItem
        Tag = -1
        Caption = '-'
      end
      object LoadDefault: TMenuItem
        Tag = -1
        Action = ReloadDefault
        Caption = 'Re&load Default File'
      end
    end
    object ViewMenu: TMenuItem
      Tag = -1
      AutoHotkeys = maManual
      Caption = '&View'
      OnClick = ViewMenuClick
      object SortbyData: TMenuItem
        Tag = -1
        Caption = 'Data Sort'
        RadioItem = True
        ShortCut = 32817
        OnClick = SetSortingExecute
      end
      object SortbyOrigin: TMenuItem
        Tag = -1
        Caption = 'Origin Sort'
        RadioItem = True
        ShortCut = 32818
        OnClick = SetSortingExecute
      end
      object SortbyID: TMenuItem
        Tag = -1
        Caption = 'ID Sort'
        RadioItem = True
        ShortCut = 32819
        OnClick = SetSortingExecute
      end
      object N7: TMenuItem
        Tag = -1
        Caption = '-'
      end
      object SortbyProperty: TMenuItem
        Tag = -1
        Caption = 'Property Sort'
        RadioItem = True
      end
    end
    object Bookmarks: TMenuItem
      Tag = -1
      AutoHotkeys = maManual
      AutoLineReduction = maManual
      Caption = '&Bookmarks'
      object N9: TMenuItem
        Tag = -1
        Caption = '-'
        GroupIndex = 10
      end
      object ClearCurrentBookmarks1: TMenuItem
        Tag = -1
        Action = ClearBookmarks
        Caption = 'Clear Current Bookmarks'
        GroupIndex = 10
      end
      object N12: TMenuItem
        Tag = -1
        Caption = '-'
        GroupIndex = 10
      end
      object ClearBookmarks1: TMenuItem
        Tag = -1
        Action = ClearAllBookmarks
        GroupIndex = 10
      end
    end
    object ExternalProgMenu: TMenuItem
      Caption = '&Links'
    end
    object AboutMenu: TMenuItem
      Tag = -1
      Caption = '&Help'
      object FAQMenu: TMenuItem
        Caption = 'FA&Q'
      end
      object DoodadsInfo1: TMenuItem
        Tag = -1
        Caption = 'Doodads Info'
        OnClick = DoodadsInfo1Click
      end
      object N3: TMenuItem
        Tag = -1
        Caption = '-'
      end
      object Credits: TMenuItem
        Tag = -1
        Caption = 'Credits...'
        OnClick = CreditsClick
      end
      object AboutDatEdit: TMenuItem
        Tag = -1
        Caption = 'About DatEdit...'
        ShortCut = 112
        OnClick = AboutClick
      end
    end
  end
  object BookmarkImage: TImageList
    Tag = -1
    Left = 220
    Top = 160
    Bitmap = {
      494C010102000400040010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000001000000001002000000000000010
      000000000000000000000000000000000000000000000F0F0F00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000F1600000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000007272720019191900050505000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000719E0000044A00000012000000
      0100000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000727272003B3B3B001F1F1F000909
      0900020202000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000005CC7000000C600000068000000
      1F00000008000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000007B7B7B00444444003F3F3F002626
      2600161616000E0E0E000E0E0E000E0E0E000E0E0E000E0E0E000C0C0C000202
      020000000000000000000000000000000000005CE4000000E2000000D3000000
      7F000000480000002F0000002F0000002F0000002F0000002F00000027000000
      0800000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000007B7B7B0044444400444444004444
      44003939390032323200323232003232320032323200323232002C2C2C001717
      170008080800020202000000000000000000005CE4000000E2000000E2000000
      E2000000BD000000A5000000A5000000A5000000A5000000A500000093000000
      4B00000019000000050000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000007B7B7B0044444400444444004444
      4400444444004444440044444400444444004444440044444400434343003F3F
      3F0025252500141414000303030000000000005CE4000000E2000000E2000000
      E2000000E2000000E2000000E2000000E2000000E2000000E2000000DF000000
      D30000007B000000440000000900000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000007B7B7B0044444400444444004444
      4400444444004444440044444400444444004444440044444400444444004444
      440044444400383838001515150002020200005CE4000000E2000000E2000000
      E2000000E2000000E2000000E2000000E2000000E2000000E2000000E2000000
      E2000000E2000000B90000004500000006000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000007B7B7B0044444400444444004444
      4400444444004444440044444400444444004444440044444400444444004444
      440044444400444444003D3D3D0012121200005CE4000000E2000000E2000000
      E2000000E2000000E2000000E2000000E2000000E2000000E2000000E2000000
      E2000000E2000000E2000000CC0000003B000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000007B7B7B0044444400444444004444
      4400444444004444440044444400444444004444440044444400444444004444
      44004444440044444400444444002D2D2D00005CE4000000E2000000E2000000
      E2000000E2000000E2000000E2000000E2000000E2000000E2000000E2000000
      E2000000E2000000E2000000E200000096000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000007B7B7B0044444400444444004444
      4400444444004444440044444400444444004444440044444400444444003E3E
      3E003535350035353500353535001D1D1D00005CE4000000E2000000E2000000
      E2000000E2000000E2000000E2000000E2000000E2000000E2000000E2000000
      CE000000AF000000AF000000AF00000062000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000007B7B7B0044444400444444004444
      44004444440044444400444444004444440044444400404040002F2F2F001D1D
      1D0010101000101010001010100006060600005CE4000000E2000000E2000000
      E2000000E2000000E2000000E2000000E2000000E2000000D60000009E000000
      6000000036000000360000003600000014000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000007B7B7B0044444400444444004444
      440044444400444444004444440044444400393939001C1C1C000E0E0E000505
      050000000000000000000000000000000000005CE4000000E2000000E2000000
      E2000000E2000000E2000000E2000000E2000000BD0000005D0000002D000000
      0F00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000007B7B7B0044444400444444004444
      4400444444004444440042424200313131001616160005050500010101000000
      000000000000000000000000000000000000005CE4000000E2000000E2000000
      E2000000E2000000E2000000DD000000A4000000480000000F00000003000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000007B7B7B0044444400444444004444
      4400444444003B3B3B00292929000F0F0F000202020000000000000000000000
      000000000000000000000000000000000000005CE4000000E2000000E2000000
      E2000000E2000000C60000008A00000033000000080000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000007979790039393900393939003939
      390028282800161616000A0A0A00010101000000000000000000000000000000
      0000000000000000000000000000000000000065CC000000BE000000BE000000
      BE00000085000000480000002000000002000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000004E4E4E0014141400141414001414
      14000B0B0B000303030000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000053610000004200000042000000
      42000000250000000A0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000040000000100000000100010000000000800000000000000000000000
      000000000000000000000000FFFFFF0080008000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000}
  end
end
