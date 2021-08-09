# レポート置き場

## 後輩向け

- 参考にしてもいいけど丸パクリするなよ
  - 基本的にこっちの単位が確定したものしか上げないが，君たちが提出してカンニングとして扱われれば単位がどうなるか知らないよ
    - ~~最も去年分も含めて剽窃チェックしてないかもしれないけど~~

## 自分用

- PDFは残さない（身バレ防止の為）
- .envは当然ignore
- `\author{}` に直書きしない
  - `\directlua{tex.print(os.getenv("AUTHOR_NAME"))}`

### TODO

- pre-commitのHOOKを作って `*.pdf` を `git restore --staged` する
  - 念の為logとかauxとかも消そう
