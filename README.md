# doxybook2-bin

Doxybook2 1.6.1 のコンパイル済みバイナリ配布レポジトリ

source: [Antonz0/doxybook2](https://github.com/Antonz0/doxybook2)

## 概要

このレポジトリは、Doxybook2 1.6.1 をビルドした実行バイナリを提供します。GitHub Actions によって自動的にビルドされ、Oracle Linux 8 / 10 (x64) プラットフォームに対応しています。

Doxybook2 は、Doxygen の XML 出力を Markdown (または JSON) に変換するツールです。MkDocs、Hugo、VuePress、GitBook などの静的サイトジェネレータと組み合わせて、C++ API ドキュメントを生成できます。

## ディレクトリ構造

```
doxybook2-bin/
+-- bin/
    +-- linux-el8-x64/     # Linux (Oracle Linux 8 x64) バイナリ
    |   +-- doxybook2       # 実行ファイル
    +-- linux-el10-x64/    # Linux (Oracle Linux 10 x64) バイナリ
        +-- doxybook2       # 実行ファイル
```

## 配布バイナリ

### Linux (Oracle Linux 8 x64)

**ビルド設定:**
- ビルドタイプ: MinSizeRel (サイズ最適化)
- 静的リンク (stdlib)
- strip 済み

### Linux (Oracle Linux 10 x64)

**ビルド設定:**
- ビルドタイプ: MinSizeRel (サイズ最適化)
- 静的リンク (stdlib)
- strip 済み

## 使用方法

### 基本的な使用例

```bash
# Doxygen XML 出力から Markdown を生成 (Oracle Linux 8 の場合)
/path/to/doxybook2-bin/bin/linux-el8-x64/doxybook2 \
  --input ./doxygen-output/xml \
  --output ./docs/api

# Oracle Linux 10 の場合
/path/to/doxybook2-bin/bin/linux-el10-x64/doxybook2 \
  --input ./doxygen-output/xml \
  --output ./docs/api

# 設定ファイルを指定
/path/to/doxybook2-bin/bin/linux-el8-x64/doxybook2 \
  --input ./doxygen-output/xml \
  --output ./docs/api \
  --config .doxybook/config.json
```

### PATH に追加

```bash
# Oracle Linux 8 の場合
export PATH="/path/to/doxybook2-bin/bin/linux-el8-x64:$PATH"

# Oracle Linux 10 の場合
export PATH="/path/to/doxybook2-bin/bin/linux-el10-x64:$PATH"

doxybook2 --help
```

## ビルド方法 (CI/CD)

このレポジトリのバイナリは、GitHub Actions によって自動的にビルドされます。

**ワークフロー:** `.github/workflows/build-doxybook2.yml`

**ビルドプロセス:**
1. Doxybook2 1.6.1 のソースコードを clone
2. vcpkg で依存ライブラリをインストール
3. Linux (Oracle Linux 8 / 10) でビルド (MinSizeRel, 静的リンク)
4. ビルド成果物を `bin/` に配置
5. main ブランチへの push 時に自動的にコミット

## バイナリバージョン

- Doxybook2: 1.6.1
- ビルド環境: Oracle Linux 8 / 10

## ライセンス

Doxybook2 は MIT License の下で配布されています。詳細は [LICENSE](LICENSE) ファイルを参照してください。

## 参考リンク

- [Doxybook2 GitHub リポジトリ](https://github.com/Antonz0/doxybook2)
- [Doxygen 公式サイト](https://www.doxygen.nl/)
