object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = #1056#1110#1096#1077#1085#1085#1103' '#1057#1051#1056' '#1084#1077#1090#1086#1076#1086#1084' '#1086#1073#1077#1088#1085#1077#1085#1086#1111' '#1084#1072#1090#1088#1080#1094#1110
  ClientHeight = 724
  ClientWidth = 1140
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object PnFirstMatrix: TPanel
    Left = 0
    Top = 73
    Width = 585
    Height = 303
    TabOrder = 0
    Visible = False
    object LBNameMatrix: TLabel
      Left = 16
      Top = 24
      Width = 26
      Height = 23
      Caption = 'A: '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object LBx: TLabel
      Left = 95
      Top = 27
      Width = 8
      Height = 19
      Caption = 'x'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 16
      Top = 53
      Width = 156
      Height = 23
      Caption = #1055#1077#1088#1096#1072' '#1084#1072#1090#1088#1080#1094#1103
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object ComboBox1: TComboBox
      Left = 48
      Top = 21
      Width = 41
      Height = 31
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = []
      ItemIndex = 0
      ParentFont = False
      TabOrder = 0
      Text = '3'
      OnChange = ComboBox1Change
      Items.Strings = (
        '3'
        '2'
        '4'
        '5'
        '6'
        '7'
        '8')
    end
    object ComboBox2: TComboBox
      Left = 109
      Top = 21
      Width = 41
      Height = 31
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = []
      ItemIndex = 0
      ParentFont = False
      TabOrder = 1
      Text = '3'
      OnChange = ComboBox2Change
      Items.Strings = (
        '3'
        '2'
        '4'
        '5'
        '6'
        '7'
        '8')
    end
    object StringGrid1: TStringGrid
      Left = 16
      Top = 82
      Width = 201
      Height = 87
      ColCount = 3
      FixedCols = 0
      RowCount = 3
      FixedRows = 0
      Options = [goVertLine, goHorzLine, goRangeSelect, goRowSizing, goColSizing, goRowMoving, goColMoving, goEditing, goTabs]
      TabOrder = 2
    end
  end
  object PnSecondMatrix: TPanel
    Left = 583
    Top = 79
    Width = 772
    Height = 297
    Align = alCustom
    TabOrder = 1
    Visible = False
    object Label2: TLabel
      Left = 8
      Top = 47
      Width = 147
      Height = 23
      Caption = #1044#1088#1091#1075#1072' '#1084#1072#1090#1088#1080#1094#1103
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object StringGrid2: TStringGrid
      Left = 0
      Top = 76
      Width = 201
      Height = 87
      ColCount = 3
      FixedCols = 0
      RowCount = 3
      FixedRows = 0
      Options = [goVertLine, goHorzLine, goRangeSelect, goRowSizing, goColSizing, goRowMoving, goColMoving, goEditing, goTabs]
      TabOrder = 0
    end
  end
  object PnResult: TPanel
    Left = 8
    Top = 382
    Width = 1126
    Height = 339
    TabOrder = 2
    Visible = False
    object LBInfo: TLabel
      Left = 14
      Top = 104
      Width = 81
      Height = 29
      Caption = 'LBInfo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -24
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object LBHint: TLabel
      Left = 8
      Top = 17
      Width = 54
      Height = 19
      Caption = 'LBHint'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      Visible = False
    end
    object StringGrid3: TStringGrid
      Left = 552
      Top = 135
      Width = 138
      Height = 82
      ColCount = 2
      FixedCols = 0
      RowCount = 3
      FixedRows = 0
      Options = [goVertLine, goHorzLine, goRangeSelect, goRowSizing, goColSizing, goRowMoving, goColMoving, goEditing, goTabs]
      TabOrder = 0
    end
    object BtnCount: TBitBtn
      Left = 256
      Top = 56
      Width = 265
      Height = 33
      Caption = #1056#1072#1093#1091#1074#1072#1090#1080
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
      Visible = False
      OnClick = BtnCountClick
    end
    object BtnClear: TBitBtn
      Left = 704
      Top = 56
      Width = 265
      Height = 33
      Caption = #1054#1095#1080#1089#1090#1080#1090#1080' '#1076#1072#1085#1110' '#1084#1072#1090#1088#1080#1094#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 2
      Visible = False
      OnClick = BtnClearClick
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 1140
    Height = 88
    Align = alTop
    Color = clMaroon
    ParentBackground = False
    TabOrder = 3
    object BtnGaussMatrix: TSpeedButton
      Left = 236
      Top = 23
      Width = 245
      Height = 44
      GroupIndex = 1
      Caption = #1054#1073#1077#1088#1085#1077#1085#1072' '#1084#1072#1090#1088#1080#1094#1103
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -24
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      OnClick = BtnGaussMatrixClick
    end
    object BtnSLR: TSpeedButton
      Left = 35
      Top = 23
      Width = 150
      Height = 44
      GroupIndex = 1
      Caption = #1057#1051#1040#1056
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -24
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      OnClick = BtnSLRClick
    end
    object BtnTransMatrix: TSpeedButton
      Left = 520
      Top = 23
      Width = 329
      Height = 44
      GroupIndex = 1
      Caption = #1058#1088#1072#1085#1089#1087#1086#1085#1091#1074#1072#1085#1085#1103' '#1084#1072#1090#1088#1080#1094#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -24
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      OnClick = BtnTransMatrixClick
    end
  end
  object MainMenu1: TMainMenu
    Left = 416
    Top = 168
    object N1: TMenuItem
      Caption = #1030#1085#1089#1090#1088#1091#1082#1094#1110#1103' '#1076#1083#1103' '#1082#1086#1088#1080#1089#1090#1091#1074#1072#1095#1072
      OnClick = N1Click
    end
    object N2: TMenuItem
      Caption = #1030#1085#1089#1090#1088#1091#1082#1094#1110#1103' '#1076#1083#1103' '#1088#1086#1079#1088#1086#1073#1085#1080#1082#1072
      OnClick = N2Click
    end
  end
end
