object DoodadInfoBox: TDoodadInfoBox
  Left = 398
  Top = 203
  BorderStyle = bsDialog
  Caption = 'Information about Doodads'
  ClientHeight = 417
  ClientWidth = 747
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = True
  Position = poScreenCenter
  OnKeyDown = FormKeyDown
  PixelsPerInch = 96
  TextHeight = 13
  object DoodadInfoPanel: TPanel
    Left = 0
    Top = 0
    Width = 747
    Height = 417
    Align = alClient
    BevelInner = bvRaised
    BevelOuter = bvLowered
    ParentColor = True
    TabOrder = 0
    DesignSize = (
      747
      417)
    object Label1: TLabel
      Left = 14
      Top = 16
      Width = 481
      Height = 13
      Caption = 
        'Tileset doodad entries are handled in a particular way in DatEdi' +
        't. The following format is used for them:'
    end
    object Label2: TLabel
      Left = 26
      Top = 36
      Width = 246
      Height = 13
      Caption = 'Doodad_Group/Doodad_Number + Doodad_Tileset'
    end
    object Label3: TLabel
      Left = 14
      Top = 320
      Width = 195
      Height = 13
      Caption = 'For example, images.dat entry #609 says:'
    end
    object Label4: TLabel
      Left = 14
      Top = 360
      Width = 290
      Height = 26
      Caption = 
        'Which means it is the 27th Doodad of the 9th Doodad Group (calle' +
        'd "Plating") of the Platform tileset.'
      WordWrap = True
    end
    object Label5: TLabel
      Left = 26
      Top = 340
      Width = 74
      Height = 13
      Caption = '"9/27 Platform"'
    end
    object Label6: TLabel
      Left = 14
      Top = 58
      Width = 35
      Height = 13
      Caption = 'Where:'
    end
    object Label7: TLabel
      Left = 26
      Top = 104
      Width = 184
      Height = 13
      Caption = '-Doodad_Group is one of the following:'
    end
    object Label8: TLabel
      Left = 26
      Top = 88
      Width = 451
      Height = 13
      Caption = 
        '-Doodad_Number is the successive doodad number in its Doodad Gro' +
        'up (counting from the top)'
    end
    object Label9: TLabel
      Left = 26
      Top = 72
      Width = 159
      Height = 13
      Caption = '-Doodad_Tileset is a terrain tileset'
    end
    object OKButton: TButton
      Left = 659
      Top = 378
      Width = 75
      Height = 25
      Caption = 'OK'
      Default = True
      ModalResult = 1
      TabOrder = 0
      OnClick = OKButtonClick
    end
    object Memo1: TMemo
      Left = 72
      Top = 126
      Width = 91
      Height = 185
      BevelEdges = []
      BevelInner = bvNone
      BevelOuter = bvNone
      BorderStyle = bsNone
      Color = clBtnFace
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Lines.Strings = (
        'Badlands:'
        '1 - Asphalt'
        '2 - Bridges'
        '3 - Cliff'
        '4 - Coastal Cliff'
        '5 - Dirt'
        '6 - Grass'
        '7 - High Dirt'
        '8 - High Grass'
        '9 - Rocky Ground'
        '10 - Structure'
        '11 - Structure Wall'
        '12 - Water')
      ParentFont = False
      ReadOnly = True
      TabOrder = 1
      WantReturns = False
      WordWrap = False
    end
    object Memo2: TMemo
      Left = 18
      Top = 124
      Width = 53
      Height = 79
      Anchors = [akLeft, akTop, akBottom]
      BevelEdges = []
      BevelInner = bvNone
      BevelOuter = bvNone
      BorderStyle = bsNone
      Lines.Strings = (
        'Ash:'
        '1-Cliff'
        '2-Dirt'
        '3-High Dirt'
        '4-Shale')
      ParentColor = True
      ReadOnly = True
      TabOrder = 2
      WantReturns = False
      WordWrap = False
    end
    object Memo3: TMemo
      Left = 166
      Top = 124
      Width = 129
      Height = 195
      BevelEdges = []
      BevelInner = bvNone
      BevelOuter = bvNone
      BorderStyle = bsNone
      Color = clBtnFace
      Lines.Strings = (
        'Desert:'
        '1 - Bridges'
        '2 - Cliff'
        '3 - Compound'
        '4 - Dirt'
        '5 - High Compound'
        '6 - High Dirt'
        '7 - High Sand Dunes'
        '8 - High Sandy Sunken Pit'
        '9 - Rocky Ground'
        '10 - Sand Dunes'
        '11 - Sandy Sunken Pit'
        '12 - Tar'
        '13 - Tar Cliff')
      ReadOnly = True
      TabOrder = 3
      WantReturns = False
      WordWrap = False
    end
    object Memo4: TMemo
      Left = 294
      Top = 124
      Width = 81
      Height = 197
      BevelEdges = []
      BevelInner = bvNone
      BevelOuter = bvNone
      BorderStyle = bsNone
      Color = clBtnFace
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Lines.Strings = (
        'Ice:'
        '1 - Bridges'
        '2 - Cliff'
        '3 - Coastal Cliff'
        '4 - Dirt'
        '5 - Grass'
        '6 - High Dirt'
        '7 - High Grass'
        '8 - High Outpost'
        '9 - High Snow'
        '10 - Ice'
        '11 - Outpost'
        '12 - Snow'
        '13 - Water')
      ParentFont = False
      ReadOnly = True
      TabOrder = 4
      WantReturns = False
      WordWrap = False
    end
    object Memo5: TMemo
      Left = 376
      Top = 124
      Width = 103
      Height = 91
      BevelEdges = []
      BevelInner = bvNone
      BevelOuter = bvNone
      BorderStyle = bsNone
      Color = clBtnFace
      Lines.Strings = (
        'Installation:'
        '1 - Floor'
        '2 - Plating'
        '3 - Substructure'
        '4 - Substructure Wall'
        '5 - Wall')
      ReadOnly = True
      TabOrder = 5
      WantReturns = False
      WordWrap = False
    end
    object Memo6: TMemo
      Left = 376
      Top = 212
      Width = 101
      Height = 195
      BevelEdges = []
      BevelInner = bvNone
      BevelOuter = bvNone
      BorderStyle = bsNone
      Color = clBtnFace
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Lines.Strings = (
        'Jungle:'
        '1 - Bridges'
        '2 - Cliff'
        '3 - Coastall Cliff'
        '4 - Dirt'
        '5 - High Dirt'
        '6 - High Jungle'
        '7 - High Ruins'
        '8 - High Temple Wall'
        '9 - Jungle'
        '10 - Rocky Ground'
        '11 - Ruins'
        '12 - Temple Wall'
        '13 - Water')
      ParentFont = False
      ReadOnly = True
      TabOrder = 6
      WantReturns = False
      WordWrap = False
    end
    object Memo7: TMemo
      Left = 478
      Top = 124
      Width = 137
      Height = 195
      BevelEdges = []
      BevelInner = bvNone
      BevelOuter = bvNone
      BorderStyle = bsNone
      Color = clBtnFace
      Lines.Strings = (
        'Platform'
        '1 - Bridges'
        '2 - Dark Platform'
        '3 - Elevated Catwalk Ramps'
        '4 - High Plating'
        '5 - Low Platform'
        '6 - Low Platform Wall'
        '7 - Platform'
        '8 - Platform Wall'
        '9 - Plating'
        '10 - Rusty Pit'
        '11 - Rusty Pit Wall'
        '12 - Solar Array')
      ReadOnly = True
      TabOrder = 7
      WantReturns = False
      WordWrap = False
    end
    object Memo8: TMemo
      Left = 618
      Top = 124
      Width = 121
      Height = 231
      BevelEdges = []
      BevelInner = bvNone
      BevelOuter = bvNone
      BorderStyle = bsNone
      Color = clBtnFace
      Lines.Strings = (
        'Twilight:'
        '1 - Basilica'
        '2 - Bridges'
        '3 - Cliff'
        '4 - Coastal Cliff'
        '5 - Crevices'
        '6 - Crushed Rock'
        '7 - Dirt'
        '8 - Flagstones'
        '9 - High Basilica'
        '10 - High Crushed Rock'
        '11 - High Dirt'
        '12 - High Flagstones'
        '13 - High Sunken Ground'
        '14 - Sunken Ground'
        '15 - Water')
      ReadOnly = True
      TabOrder = 8
      WantReturns = False
      WordWrap = False
    end
    object Memo9: TMemo
      Left = 18
      Top = 124
      Width = 23
      Height = 15
      Anchors = [akLeft, akTop, akBottom]
      BevelEdges = []
      BevelInner = bvNone
      BevelOuter = bvNone
      BorderStyle = bsNone
      Color = clMenuBar
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsUnderline]
      Lines.Strings = (
        'Ash:')
      ParentFont = False
      ReadOnly = True
      TabOrder = 9
      WantReturns = False
    end
    object Memo10: TMemo
      Left = 166
      Top = 124
      Width = 35
      Height = 15
      Anchors = [akLeft, akTop, akBottom]
      BevelEdges = []
      BevelInner = bvNone
      BevelOuter = bvNone
      BorderStyle = bsNone
      Color = clMenuBar
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsUnderline]
      Lines.Strings = (
        'Desert:')
      ParentFont = False
      ReadOnly = True
      TabOrder = 10
      WantReturns = False
    end
    object Memo11: TMemo
      Left = 478
      Top = 124
      Width = 47
      Height = 15
      Anchors = [akLeft, akTop, akBottom]
      BevelEdges = []
      BevelInner = bvNone
      BevelOuter = bvNone
      BorderStyle = bsNone
      Color = clMenuBar
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsUnderline]
      Lines.Strings = (
        'Platform:')
      ParentFont = False
      ReadOnly = True
      TabOrder = 11
      WantReturns = False
    end
    object Memo12: TMemo
      Left = 376
      Top = 124
      Width = 55
      Height = 15
      Anchors = [akLeft, akTop, akBottom]
      BevelEdges = []
      BevelInner = bvNone
      BevelOuter = bvNone
      BorderStyle = bsNone
      Color = clMenuBar
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsUnderline]
      Lines.Strings = (
        'Installation:')
      ParentFont = False
      ReadOnly = True
      TabOrder = 12
      WantReturns = False
    end
    object Memo13: TMemo
      Left = 376
      Top = 212
      Width = 39
      Height = 15
      Anchors = [akLeft, akTop, akBottom]
      BevelEdges = []
      BevelInner = bvNone
      BevelOuter = bvNone
      BorderStyle = bsNone
      Color = clMenuBar
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsUnderline]
      Lines.Strings = (
        'Jungle:')
      ParentFont = False
      ReadOnly = True
      TabOrder = 13
      WantReturns = False
    end
    object Memo14: TMemo
      Left = 294
      Top = 124
      Width = 23
      Height = 15
      Anchors = [akLeft, akTop, akBottom]
      BevelEdges = []
      BevelInner = bvNone
      BevelOuter = bvNone
      BorderStyle = bsNone
      Color = clMenuBar
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsUnderline]
      Lines.Strings = (
        'Ice:')
      ParentFont = False
      ReadOnly = True
      TabOrder = 14
      WantReturns = False
    end
    object Memo15: TMemo
      Left = 618
      Top = 124
      Width = 43
      Height = 15
      Anchors = [akLeft, akTop, akBottom]
      BevelEdges = []
      BevelInner = bvNone
      BevelOuter = bvNone
      BorderStyle = bsNone
      Color = clMenuBar
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsUnderline]
      Lines.Strings = (
        'Twilight:')
      ParentFont = False
      ReadOnly = True
      TabOrder = 15
      WantReturns = False
    end
    object Memo16: TMemo
      Left = 72
      Top = 124
      Width = 47
      Height = 15
      Anchors = [akLeft, akTop, akBottom]
      BevelEdges = []
      BevelInner = bvNone
      BevelOuter = bvNone
      BorderStyle = bsNone
      Color = clMenuBar
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsUnderline]
      Lines.Strings = (
        'Badlands:')
      ParentFont = False
      ReadOnly = True
      TabOrder = 16
      WantReturns = False
    end
  end
end
