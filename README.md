precise_round(3) -- 丸め桁数指定つきの「正確な」round関数
=================

## DESCRIPTION

浮動小数点数とその10進表記の正確な相互変換を紹介するWilliam D Clingerの論文「How to Read Floating Point Numbers Accurately」の成果を利用して試作した、丸め桁数指定ができて精度を失わないようなround関数です。

```c
extern double precise_round(double x, int digits);
```

いわゆる四捨五入を行う関数です。第一引数`x`が丸め対象の浮動小数点数、第二引数`digits`が丸め桁数の指定で、小数点以下第`digits`位までに丸めます。digitsが負の場合は`10^(-digits)`の位までに丸めます。

実装としては、受け取った浮動小数点数から最短になる10進表記に変換し、浮動小数点をズラすことなく10進表記のまま四捨五入を行っています。

あくまで試作レベルだと考えていますので、（そんな人はいないと思いますが）このままプロダクトに組み込むのは避けるべきでしょう。たとえば`digits=0`の場合はもっと高速に同じ処理が実現できますので、この処理をそのまま使うと無駄が多いはずです。

本パッケージ中のdtoa.cはWilliam D Clingerの論文をもとにDavid M. Gayが実装したものをそのまま利用しています。オリジナルのソースコードは下記URLで配布されています。

*http://www.netlib.org/fp/dtoa.c

## LICENSE
#
The MIT License

Copyright (c) 2013 Yoshio HANAWA

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
