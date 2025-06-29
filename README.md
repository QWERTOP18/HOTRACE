# HOTRACE

HOTRACEは、キー・バリューペアを格納し、検索するためのシンプルなデータベースプログラムです。

## 概要

このプログラムは、標準入力からキー・バリューペアを読み取り、データベースに格納した後、指定されたキーに対応する値を検索して出力します。

## 機能

- キー・バリューペアの格納
- キーによる値の検索
- 複数のデータ構造実装（配列、マップ、AVL木）
- 高性能な検索機能

## 使用方法

### 基本的な使用方法

```bash
./hotrace < input_file
```

### 入力形式

入力ファイルは以下の形式で記述します：

```
keyword-1
value-1
keyword-2
value-2

keyword-1
keyword-2
```

- 最初の部分：キー・バリューペアの格納
- 空行：格納モードから検索モードへの切り替え
- 後半部分：検索したいキー

### 出力

検索モードで指定されたキーに対応する値が出力されます：

```
value-1
value-2
```

## ビルド

### 必要な環境

- CC コンパイラ
- Make

### ビルド方法

```bash
# デフォルト（v1-map）でビルド
make

# 特定のバリアントでビルド
make VARIANT=v0  # 配列実装
make VARIANT=v1  # マップ実装
make VARIANT=v2  # AVL木実装

# デバッグビルド
make debug

# クリーンアップ
make clean
make fclean
```

## 実装バリアント

このプロジェクトには3つの異なるデータ構造実装が含まれています：

- **v0-array**: 配列ベースの実装
- **v1-map**: マップベースの実装
- **v2-avl**: AVL木ベースの実装

## テスト

プロジェクトには包括的なテストスイートが含まれています：

```bash
# 基本的なテスト
./test/simple-test.sh

# パフォーマンステスト
./test/performance-test.sh

# Pythonテストスクリプト
python3 test/test_positive.py
python3 test/test_performance.py
```

## プロジェクト構造

```
HOTRACE/
├── srcs/
│   ├── main.c          # メインエントリーポイント
│   ├── interface.h     # インターフェース定義
│   ├── parse/          # パーサー実装
│   ├── _utils/         # ユーティリティ関数
│   ├── v0-array/       # 配列実装
│   ├── v1-map/         # マップ実装
│   └── v2-avl/         # AVL木実装
├── test/               # テストファイル
├── cache/              # ビルドキャッシュ
├── example.htr         # サンプル入力ファイル
└── Makefile           # ビルド設定
```
