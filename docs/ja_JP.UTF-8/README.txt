                                   Tux Paint
                                  バージョン 0.9.28

                              子供向けのシンプルなお絵かきプログラム

        Copyright © 2002-2022 by various contributors; see AUTHORS.txt.
                             https://tuxpaint.org/
                           @TuxPaintTweets on Twitter

                                   2022年3月 1日

               +-----------------------------------------------+
               |目次                                             |
               |-----------------------------------------------|
               |  * Tux Paint について                             |
               |  * Tux Paint の使い方                             |
               |       * Tux Paint の起動                         |
               |       * 起動画面                                  |
               |       * メインの画面                                |
               |       * 各種のツール                                |
               |            * 描画ツール                            |
               |                 * ペイントブラシ「ふで」                 |
               |                 * 「はんこ」ツール                    |
               |                 * 「せん」ツール                     |
               |                 * 「かたち」ツール                    |
               |                 * 「もじ」ツール、「ラベル」ツール            |
               |                 * 「ぬる」ツール                     |
               |                 * 「まほう」ツール（特殊効果）              |
               |                 * けしゴム                        |
               |            * そのほかの操作                          |
               |                 * "Undo" and "Redo" Commands  |
               |                 * 「さいしょから」                    |
               |                 * 「ひらく」                       |
               |                 * 「セーブ」                       |
               |                 * 「いんさつ」                      |
               |                 * 「スライドショー」                   |
               |                 * プログラムの終了                    |
               |                 * 効果音を消すには                    |
               |  * 他の画像の Tux Paint への読み込み                     |
               |  * その他のドキュメント                                 |
               |  * お問い合わせ先                                    |
               |  * プロジェクトへの参加                                 |
               +-----------------------------------------------+

                                 Tux Paint について

"Tux Paint" とは？

   Tux Paint
   は、３歳以上の小さな子供向けにデザインされたフリーのお絵かきソフトです。シンプルで使いやすい操作方法と楽しい効果音を備え、マスコットキャラクターが子供たちの案内役を務めます。空っぽのキャンバスと様々な描画ツールが、子供たちの創造力をかき立てます。

著作権

   Tux Paint
   は、オープンソースのプロジェクトで、GNUの一般公衆利用許諾（GPL）基づき公開されているフリーソフトウェアです。このソフトウェアは無料で、プログラムのソースコードが利用可能です。（これにより、誰でも、機能を追加したり、不具合を修正したり、プログラムの一部を自分のGPLソフトウェアに使用することができます。）

   ライセンスの全文は、COPYING.txtをお読みください。

Objectives

   簡単に、そして楽しく
           Tux Paint
           は、一般向けの描画ツールではなく、小さな子供のためのシンプルなお絵かきソフトとなることを目指して、楽しく容易に使えるように作られています。効果音とマスコットキャラクターが、プログラムの操作をわかりやすく教えてくれるとともに、ユーザーを楽しませてくれます。また、大きくて見やすいイラスト調のマウスポインターを採用しています。

   拡張性
           Tux Paint
           は、機能を拡張することができます。「ふで」や「はんこ」は、追加や削除が可能です。例えば、授業では、様々な生き物の画像を追加しておいて、生徒に生態系を描かせるといったことができます。それぞれの「はんこ」には、選択時に流れる音声、表示される説明文を設定できます。

   移植性
           Tux Paint は、Windows, Macintosh, Linux
           など、様々なプラットフォームに移植されており、どのプラットフォームでも見た目や使い方は変わりません。Tux Paint
           は、Pentium 133のような旧式のシステムでもうまく動作し、さらに遅いシステムでも動作するように構築することもできます。

   簡単な操作
           ユーザーは、コンピューターの複雑な機能に直接触れる必要がありません。描画中の作品は、プログラム終了時に保存され、再開時に表示されます。作品を保存するために、ファイル名をつけたりキーボードを使う必要はありません。保存された作品は、縮小画像の一覧から選択するだけで読み込むことができ、コンピューターの他のファイルにアクセスすることはありません。

                                 Tux Paint の使い方

Tux Paint の起動

  Linux または Unix のユーザー

   KDE あるいは GNOME のメニューの「グラフィックス」以下に、起動アイコンが設定されているはずです。

   その他、シェルプロンプト（例："$"）で次のコマンドを実行する方法があります：

     $ tuxpaint

   エラーが発生した場合は、端末にその内容が表示されます。（標準エラー出力）

  Windows のユーザー

                                                            [Tux Paint アイコン]  
                                                               Tux Paint      

   インストーラーを用いて Tux Paint
   をインストールする際、スタート・メニューやデスクトップにショートカットを作成するかどうかが選択できます。ショートカットを作成していれば、これらのアイコンから簡単に
   Tux Paint を起動できます。

   ポータブル版（ZIPファイル版）をダウンロードして Tux Paint
   をインストールした場合や、インストーラーでショートカットを作成しなかった場合は、"Tux Paint"のフォルダにある "tuxpaint.exe"
   のアイコンをダブルクリックします。

   インストーラーを用いた場合、「Tux Paint」のフォルダは、通常、"C:\Program Files\"
   に配置されます。（インストール時に、これを変更することもできます）

   ZIP ファイルを用いた場合、「Tux Paint」のフォルダは、任意の場所に配置できます。

  macOS のユーザー

   "Tux Paint" のアイコンをダブルクリックします。

   [起動画面]

起動画面

   Tux Paint を起動すると、タイトル画面が表示されます。

   プログラムの読み込みが完了すると、何かキーを押すかマウスのクリックにより次に進みます。（タイトル画面は、約5秒後に自動的に閉じます）

メインの画面

   メインの画面は、次の各部に分けられます：

   [どうぐ: ふで, はんこ, せん, かたち, もじ, まほう, ラベル, とりけし, やりなおし, けしゴム, さいしょから, ひらく, セーブ,
   いんさつ, やめる]

   左側: ツールバー「どうぐ」

           ツールバーには、描画や編集を行うためのアイコンがあります。

           [描画キャンバス]

   中央部: 描画キャンバス

           中央部の最も広い領域が描画キャンバスです。ここが絵を描く部分になります！

           💡 注: 描画キャンバスのサイズは、Tux Paint のウィンドウサイズに応じて変わります。Tux Paint
           のウィンドウサイズは、Tux Paint
           設定ツールを用いて変更できます。その他の方法については、各種設定についてのドキュメントを参照してください。

           [セレクタ - ふで、もじ、かたち、はんこ]

   右側: セレクタ

           セレクタに表示される内容は、使用しているツールに応じて変わります。例えば、「ふで」ツールでは、様々な種類の筆が表示され、「はんこ」ツールでは、はんこの画像が表示されます。

           [いろ - いろ - くろ、しろ、あか、ぴんく、おれんじ、きいろ、みどり、みずいろ、あお、むらさき、ちゃいろ、はいいろ]

   下部: カラーパレット「いろ」

           When the active tool supports colors, a palette of colors choices
           will be shown near the bottom of the screen. Click one to choose a
           color, and it will be used by the active tool. (For example, the
           "Paint" tool will use it as the color to draw with the chosen
           brush, and the "Fill" tool will use it as the color to use when
           flood-filling an area of the picture.)

           On the far right are three special color options:
              * Color Picker
                The "color picker" (which has an outline of an eye-dropper)
                allows you to pick a color found within your drawing.
                (A shortcut key is available to access this feature quickly;
                see below.)
              * Rainbow Palette
                The rainbow palette allows you to pick any color by choosing
                the hue, saturation, and value of the color you want. A box
                on the left displays hundreds of hues — from red at the top
                through to violet at the bottom — at hundreds of
                saturation/intensity levels — from pale & washed-out on the
                left through to pure on the right. A grey vertical bar
                provides access to hundreds of value levels — from lighest at
                the top through to darkest at the bottom.
                Click the green checkbox button to select the color, or the
                "Back" button to dismiss the pop-up without picking a new
                color.
              * Color Mixer
                The "color mixer" (which has silhouette of a paint palette)
                allows you to create colors by blending primary additive
                colors — red, yellow, and blue — along with white (to
                "tint"), grey (to "tone"), and black (to "shade").
                You may click any button multiple times (for example, red +
                red + yellow results in a red-orange color). The ratios of
                colors added are shown at the bottom.
                You can start over (reset to no colors in your picture) by
                clicking the "Clear" button. You can also undo or redo
                multiple steps of mixing, in case you made a mistake (without
                having to start over).
                Click the green checkbox button to select the color, or the
                "Back" button to dismiss the pop-up without picking a new
                color.

           ⌨ When the active tool supports colors, a shortcut may be used to
           access the "color picker" option more quickly. Hold the [Control]
           key while clicking, and the color under the mouse cursor will be
           shown at the bottom. You may drag around to canvas to find the
           color you want. When you release the mouse button, the color under
           the cursor will be selected. If you release the mouse outside of
           the canvas (e.g., over the "Tools" area), the color selection will
           be left unchanged. (This is similar to clicking the"Back" button
           that's available when bringing up the "color picker" option via
           its button the color palette.)

           ⚙ Note: You can define your own colors for Tux Paint. See the
           "Options" documentation.

           (「かたち」ツールの使い方を説明している例)

   最下部: ヘルプエリア

           画面の一番下の部分では、Linux ペンギンの Tux が、様々なヒントや関連情報をご提供します。

各種のツール

  描画ツール

   ペイントブラシ「ふで」

           右側のセレクタから筆の種類を、下のパレットから色を選んで、フリーハンドで描画します。

           ボタンを押したままマウスを動かすと、描画できます。

           アニメーションブラシ —
           描画中に形状が変化します。例として、ブドウ形のブラシが挙げられます。このタイプのブラシの選択ボタンには、小さなフィルムのアイコンが付いています。

           向きのあるブラシ — 描いている方向によって異なる形を描きます。 例として、Tux Paint に含まれる矢印ブラシがあります。
           これらのブラシの選択ボタンには、小さな8方向の矢印のアイコンが付いています。

           また、いくつかのブラシは、方向とアニメーションを併せ持ちます。例として、猫やリスのブラシがあります。このタイプのブラシの選択ボタンには、小さなフィルムと８方向の矢印のアイコンが付いています。

           描画中にはサウンドが流れます。筆の大きさが大きいほど、低い音になります。

           Brush Spacing

             The space between each position where a brush is applied to the
             canvas can vary. Some brushes (such as the footprints and
             flower) are spaced, by default, far enough apart that they don't
             overlap. Other brushes (such as the basic circular ones) are
             spaced closely, so they make a continuous stroke.

             The default spacing of brushes may be overridden using by
             clicking within the triangular-shaped series of bars at the
             bottom right; the larger the bar, the wider the spacing. Brush
             spacing affects both tools that use the brushes: the "Paint"
             tool and the "Lines" tool.

             ⚙ Note: If the "nobrushspacing" option is set, Tux Paint won't
             display the brush spacing controls. See the "Options"
             documentation.

   「はんこ」ツール

           「はんこ」ツールは、スタンプやステッカーを集めたようなものです。馬や木、月など、あらかじめ用意された様々な写真やイラストを絵に貼り付けることができます。

           マウスのカーソル動きに応じて画像の輪郭が表示され、貼り付け位置と大きさがわかります。

           スタンプは、動物、植物、宇宙、乗り物、人物といった多くのカテゴリに分類されています。セレクタの左右の矢印のボタンを使ってカテゴリを切り替えることができます。

           スタンプを絵に貼り付ける前に、以下の様々な効果を適用することができます（スタンプの種類によって異なります）：

              * スタンプには色をつけることができるものがあります。その場合、カラーパレットが有効になり、スタンプを絵に貼り付ける前に色を選ぶことができます。
              * スタンプは、右下の三角形のバーの中をクリックすることで、縮小・拡大することができます。
              * 多くのスタンプは、右下の操作ボタンを使って、上下・左右に反転させることができます。

           個々のスタンプごとに効果音を設定することができます。画面下部の左側のヘルプエリア（Linux ペンギン
           "Tux"の近く）にあるボタンを押すと、効果音を再生することができます。

           ⚙ Note: If the "nostampcontrols" option is set, Tux Paint won't
           display the Mirror, Flip, Shrink and Grow controls for stamps. See
           the "Options" documentation.

   「せん」ツール

           様々な種類の筆と好きな色を使って直線を描くツールです。

           線を引き始めたい場所でクリックして、そのままマウスを動かすと、描かれる線の位置が細い「ゴムバンド」のような線で示され、画面の下には、線の角度が表示されます。右にまっすぐ伸びる線は0度、上にまっすぐ伸びる線は90度、左にまっすぐ伸びる線は180度、下にまっすぐ伸びる線は270度、という具合です。

           マウスを放すと、バネのような効果音とともに線が描画されます。

           アニメーション対応のブラシでは、線に沿って形が変化します。 指向性のブラシでは、線の角度に応じて異なる形状を表示します。
           さらに、アニメーションと指向性の両方を備えたブラシもあります。 詳しくは、上記の「ふで」の項をご覧ください。

           Different brushes have different spacing, leaving either a series
           of individual shapes, or a continuous stroke of the brush shape.
           Brush spacing may be adjusted. See "Paint", above, to learn more.

   「かたち」ツール

           簡単な図形を描きます。

           まず、円、正方形、楕円など、描きたい図形を、右側のセレクタから選択します。

           右下のオプションボタンで「かたち」ツールの動作を選択します：

                真ん中から広げる
                        The shape will expand from where you initially
                        clicked, and will be centered around that position.

                        📜 This was Tux Paint's only behavior through version
                        0.9.24.)

                角から広げる
                        The shape will extend with one corner starting from
                        where you initially clicked. This is the default
                        method of most other traditional drawing software.

                        📜 This option was added starting with Tux Paint
                        version 0.9.25.)

           ⚙ 注: "noshapecontrols"
           オプションをつけて起動するなどして、「かたち」ツールの動作の制御を無効にした場合、オプションボタンは表示されず、真ん中から図形を広げる動作になります。

           図形を描くには、キャンバス上でマウスをクリックし、そのままマウスを動かして図形を広げます。楕円や長方形のように縦横比を変えられる図形と、正方形や円のように縦横比を変えられない図形があります。

           For shapes that can change proportion, the aspect ratio of the
           shape will be shown at the bottom. For example: "1:1" will be
           shown if it is "square" (as tall as it is wide); "2:1" if it is
           either twice as wide as it is tall, or twice as tall as it is
           wide; and so on.

           図形を広げ終わったらマウスを放します。

                通常の動作

                        ここで、キャンバス上でマウスを動かして図形を回転させることができます。回転した図形の角度は画面の下に表示されます（「せん」ツールと同様）。

                        最後にもう一度マウスをクリックして、図形が完成します。

                簡易描画モード
                        If the "simple shapes" option is enabled, the shape
                        will be drawn on the canvas when you let go of the
                        mouse button. (There's no rotation step.)

                        ⚙ See the "Options" documentation to learn about the
                        "simple shapes" ("simpleshapes") option.

   「もじ」ツール、「ラベル」ツール

           Choose a font (from the 'Letters' available on the right) and a
           color (from the color palette near the bottom). You may also apply
           a bold, and/or an italic styling effect to the text. Click on the
           screen and a cursor will appear. Type text and it will show up on
           the screen. (You can change the font, color, and styling while
           entering the text, before it is applied to the canvas.)

           [Enter]キー、または[Return]キーを押すと文字が描画され、カーソルが次の行に下がります。

           また、[Tab]キーを押すと、文字が描画された後、カーソルは、次の行ではなく、右側に移動します。これは、１行の中で異なったフォント、字体、フォントサイズ、色などを混在させたい場合に便利な方法です。

           文字の入力中に別の場所をクリックすると、入力内容を維持したまま、文字を貼り付ける位置をクリックした位置に移動させ、文字入力を続けることができます。

                「もじ」ツールと「ラベル」ツールの違い

                        「もじ」ツールは、Tux Paint
                        に以前からある文字入力ツールです。このツールで入力した文字列は絵と一体化するため、後から文字列の内容を編集したり、動かしたりすることはできません。一方、絵と一体化することで、上から塗りつぶしたり、「よごす」「そめる」「うきぼり」といった「まほう」ツールの効果で修正を加えることができます。

                        Tux Paint バージョン 0.9.22
                        で追加された「ラベル」ツールでは、文字は絵から「浮いて」おり、文字列の内容、位置、フォント、色などの情報は個別に記録されます。これにより、「ラベル」は後から移動や編集が可能です。

                        To edit a label, click the label selection button.
                        All labels in the drawing will appear highlighted.
                        Click one — or use the [Tab] key to cycle through all
                        the labels, and the [Enter] or [Return] key to select
                        one — and you may then edit the label. (Use they
                        [Backspace] key to erase characters, and other keys
                        to add text to the label; click in the canvas to
                        reposition the label; click in the palette to change
                        the color of the text in the label; etc.)

                        You may "apply" a label to the canvas, painting the
                        text into the picture as if it had been added using
                        the Text tool, by clicking the label application
                        button. (This feature was added in Tux Paint version
                        0.9.28.) All labels in the drawing will appear
                        highlighted, and you select one just as you do when
                        selecting a label to edit. The chosen label will be
                        removed, and the text will be added directly to the
                        canvas.

                        ⚙ 「ラベル」ツールは、Tux Paint
                        設定ツールや、"nolabel"オプションにより、無効にすることができます。

                多言語文字入力

                        Tux Paint では、様々な言語の文字を入力することができます。たいていのラテン文字（A-Z, ñ,
                        è
                        など）は、直接入力できます。また、いくつかの言語では、入力モードを切り替えて、複数のキーの組み合わせを用いて文字を入力する必要があります。

                        Tux Paint
                        が、個別の入力モードがサポートされている言語に設定されている場合、特定のキーを押下することで、入力モードを切り替えることができます。

                        Currently supported locales, the input methods
                        available, and the key to toggle or cycle modes, are
                        listed below.

                           * 日本語— ローマ字入力方式のひらがな、カタカナ— 右[Alt] キー
                           * ハングル— 2-Bul入力方式— 右[Alt] キー または 左[Alt] キー
                           * 繁体中文— 右[Alt] キー または 左[Alt] キー キー
                           * タイ語— 右[Alt] キー

                        💡 Note: Many fonts do not include all characters for
                        all languages, so sometimes you'll need to change
                        fonts to see the characters you're trying to type.

                画面キーボード

                        An optional on-screen keyboard is available for the
                        Text and Label tools, which can provide a variety of
                        layouts and character composition (e.g., composing
                        "a" and "e" into "æ").

                        ⚙ See the "Options" and "Extending Tux Paint"
                        documentation for more information.

   「ぬる」ツール

           「ぬる」ツールは、描画の連続した領域を好きな色で塗りつぶします。以下の3 つの塗りつぶしオプションが用意されています：
              * たんしょく — 領域を一つの色で塗りつぶします。
              * ふで — フリーハンドでドラッグして、領域を一つの色で塗りつぶします。
              * せんけい —
                領域をクリックしてからドラッグすると、ドラッグした方向に向かって色が薄くなるようにグラデーションをつけて塗りつぶします。
              * ほうしゃ — クリックした場所を中心に周りに向かって放射状に色が薄くなるようにグラデーションをつけて塗りつぶします。

           📜 Note: Prior to Tux Paint 0.9.24, "Fill" was a Magic tool (see
           below). Prior to Tux Paint 0.9.26, the "Fill" tool only offered
           the 'Solid' method of filling.

   「まほう」ツール（特殊効果）

           「まほう」ツールは、様々な特殊なツールを集めたものです。右側のセレクタで、「まほう」の効果を選択することができます。効果を適用する方法は、クリック＋ドラッグ、単なるクリックなど、ツールごとに様々です。

           クリック＋ドラッグを使用するツールの場合、右側のセレクタの下部左側にある「描画」を表すボタンが有効になります。１クリックで画面全体に効果を及ぼすツールの場合、右側の「画面全体」を表すボタンが有効になります。

           「magic-docs」フォルダ内のドキュメント「まほう」ツールの一覧もお読みください。

   けしゴム

           このツールは「ふで」ツールに似ています。クリック（または、クリック＋ドラッグ）をした部分が消されます。（消した部分は、白あるいはその他の色、また、レイヤーキャンバスなど、絵によって異なる状態に戻ります。）

           いくつもの大きさの正方形と円形の消しゴムがあります。

           正方形の輪郭がマウスカーソルの位置に表示され、絵のどの部分が消されるかを示します。

           消している間、「キュッキュッ」と擦って消す効果音が流れます。

  そのほかの操作

   "Undo" and "Redo" Commands

           Clicking the "Undo" button will undo (revert) the last drawing
           action. You can even undo more than once!

           ⌨ 注: キーボードで [Control / ⌘] + [Z] を押しても取り消しできます。

           Clicking the "Redo" button will redo the drawing action you just
           un-did via the "Undo" command.

           「とりけし」操作の後、描画を行っていなければ、取り消した全ての操作を元に戻せます！

           ⌨ 注: キーボードで [Control / ⌘] + [R] を押してもやりなおしできます。

   「さいしょから」

           「さいしょから」のボタンを押すと、新規に絵を描き始めることができます。ダイアログ画面が表示され、キャンバスの背景色やレイヤー画像（後述）を選べます。

           ⌨ 注: キーボードで [Control / ⌘] + [N] を押しても新規作成ができます。

           Special Solid Background Color Choices

             Along with the preset solid colors, you can also choose colors
             using a rainbow palette or a "color mixer". These operate
             identically to the options found in the color palette shown
             below the canvas when drawing a picture. See Main Screen >
             Lower: Colors > Special color options for details.

           レイヤー画像

             レイヤー画像には、塗り絵のページのようなもの（白黒の線で描かれ、色を塗ることができる）や、前景レイヤーと背景レイヤーに挟まれた部分に絵を描ける３Ｄ画像のようなものがあります。

             また、このほかに、背景レイヤーだけの画像も用意されています。

             「消しゴム」ツールを使用すると、元のレイヤー画像が消されずに残ります。また、マジックツールの「反転」と「ミラー」は、レイヤー画像も反転させます。

             レイヤー画像は、その上に絵を描いて保存すると新しい絵として保存され、元々のレイヤー画像自体は上書きされないので、後で（「さいしょから」ダイアログからアクセスして）何度でも使うことができます。

   「ひらく」

           「ひらく」をクリックすると、保存されている全ての作品のリストが表示されます。リストが画面に収まりきらない場合は、上下の矢印のボタンでリストをスクロールできます。

           まず、絵をクリックして選択します…
              * 左下にある緑色の「ひらく」ボタンで、選択した作品を読み込みます。

                (または、開きたい作品をダブルクリックします）

                💡 If choose to open a picture, and your current drawing
                hasn't been saved, you will be prompted as to whether you
                want to save it or not. (See "Save," below.)

              * 右下にある茶色の「けす」(ゴミ箱) ボタンで、選択した作品を削除します。(本当に削除して良いか確認されます)

                📜 注: Linux（バージョン 0.9.22以降）、Windows（バージョン
                0.9.27以降）では、削除した作品は、デスクトップのゴミ箱に移動するので、後で元に戻すことができます。

              * 「かきだす」のボタンをクリックすると、ユーザーの標準の画像フォルダ（例："~/Pictures/TuxPaint/")に画像を出力します。

           From the "Open" screen you can also:
              * Click the blue 'Slides' (slide projector) button at the lower
                left to go to slideshow mode. See "Slides", below, for
                details.

              * 右下にある赤色の「もどる」ボタンを押すと、絵を描く画面に戻ります。

           ⌨ 注: キーボードで [Control / ⌘] + [O] を押しても「ひらく」ダイアログを表示できます。

   「セーブ」

           描画中の作品を保存します。

           一度も保存していない作品の場合、作品のリストに新しく追加されます。(つまり、新しいファイルを作成します)

           💡 注: ファイル名の入力などを求めることはなく、カメラのシャッター音の効果音とともに、単に作品を保存します。

           一度保存操作をした後や、「ひらく」コマンドで読みこんだ作品の場合、以前のバージョンを上書きするか、新しく追加して保存するかを確認します。

           ⚙ 注: "saveover" オプション、または "saveovernew"
           オプションのどちらかが設定されている場合は、確認なしに保存されます。詳しくは"各種設定について"のドキュメントを参照してください。)

           ⌨ 注: キーボードで [Control / ⌘] + [S] を押しても作品を保存できます。

   「いんさつ」

           このボタンを押して作品を印刷します！

           多くのプラットフォームでは、[Alt] key (Mac では [Option] キー)
           を押しながら「いんさつ」ボタンを押すと、プリンターの設定画面が開きます。この機能は、フルスクリーンモードでは動作しない点に注意して下さい。

                印刷の無効化

                        オプションで "noprint" を設定すれば、「いんさつ」のボタンを無効にすることができます。

                        ⚙ 詳細は "各種設定について" のドキュメントを参照して下さい。

                印刷機能の制限

                        オプションで "printdelay"
                        を設定すれば、設定に応じた一定の時間ごとに１回だけしか印刷できなくなります。

                        例えば、設定ファイルで "printdelay=602" と設定すれば、1分間に1回だけ印刷ができます。

                        ⚙ 詳細は "各種設定について" のドキュメントを参照して下さい。

                印刷コマンド

                        (Linux 及び Unix の場合のみ)

                        Tux Paint は、PostScript
                        形式の印刷データを作成し、外部プログラムに渡して印刷を行います。標準の設定では、以下のコマンドが使用されます：

                          lpr

                        このコマンドは、設定ファイルの "printcommand" オプションを設定することで変更できます。

                        フルスクリーンモードでなければ "[Alt]"
                        キーを押しながら「いんさつ」ボタンを押すと、別の印刷プログラムを起動することができます。標準の設定では、KDE
                        のグラフィカルな印刷ダイアログである、以下のプログラムが使用されます：

                          kprinter

                        このコマンドは、設定ファイルの "altprintcommand"
                        オプションを設定することで変更できます。

                        ⚙ 詳細は "各種設定について" のドキュメントを参照して下さい。

                プリンターの設定

                        (Windows 及び macOS)

                        標準の設定では、「いんさつ」ボタンを押すと、通常使うプリンターに出力されます。

                        フルスクリーンモードでなければ、[Alt] (または [Option])
                        キーを押しながら「いんさつ」ボタンを押すと、オペレーションシステム標準の印刷ダイアログが表示され、出力先などの設定を変更することができます。

                        "printcfg" オプションを設定すれば、プリンターの設定の変更を保存することができます。

                        "printcfg" オプションを設定すると、プリンターの設定は、ユーザーの個人フォルダの
                        "printcfg.cfg" から読み込まれ、変更した設定はこのファイルに保存されます。

                        ⚙ 詳細は "各種設定について" のドキュメントを参照して下さい。

                印刷ダイアログのオプション

                        標準の設定では、印刷ダイアログは、[Alt] (または [Option])
                        キーを押しながら「いんさつ」ボタンを押した場合にのみ表示されます（Linux/Unixでは、"lpr"
                        の代わりに "altprintcommand"; すなわち "kprinter" が起動します。）

                        この印刷ダイアログの動作は、設定により変更できます。毎回必ず印刷ダイアログを表示させるには、コマンドラインで
                        "--altprintalways" を指定するか、設定ファイルで "altprint=always"
                        を指定します。反対に、"--altprintnever" または "altprint=never"
                        を指定することで、"[Alt]" (または "[Option]2) キーの効果を無効にできます。

                        ⚙ 詳細は "各種設定について" のドキュメントを参照して下さい。

   「スライドショー」

           「スライドショー」の機能は、「ひらく」ダイアログから利用できます。タックスペイントの中で、簡単なアニメーションや画像のスライドショーを再生することができます。また、選択した画像を元にアニメーションGIFを書き出すこともできます。

                画像を選ぶ

                        「スライド」セクションに入ると、「ひらく」ダイアログと同じように、保存したファイルの一覧が表示されます。

                        次に、スライドショーで表示したい作品を、一つずつクリックして選択します。それぞれの画像の上に、スライドショーで表示される順番を表す数字が示されます。

                        選択された画像をもう一度クリックすると、選択を解除し、スライドショーから除外します。同じ画像もう一度クリックすると、をリストの最後に追加できます。

                再生スピードの設定

                        画面左下「かいし」の隣にあるのスライドバーで、スライドショーやアニメーションGIFのスピードを調節できます。
                        スライドバーを一番左に設定すると、スライドショーの自動進行が無効になり、次のスライドに進むにはクリックが必要になります。（以下をご確認下さい）

                        💡 注:
                        最も遅いスピードに設定するとスライドの自動進行が無効になります。１枚ずつ手動でスライドを進めたい場合に、この設定を用いてください。（この動作はアニメーションGIFには適用されません）

                Tux Paint 上での再生

                        To play a slideshow within Tux Paint, click the
                        'Play' button.

                        💡 Note: If you hadn't selected any images, then all
                        of your saved images will be played in the slideshow!

                        スライドショーの実行中は、[Space] キー、[Enter] キー、[Return] キー、[右矢印]
                        キーのいずれかを押すか、または、画面左下の "つぎへ"
                        ボタンのクリックすれば、手動で次のスライドに進みます。[左矢印] キーを押すと前のスライドに戻ります。

                        [Escape]
                        キーを押すか、右下の「もどる」ボタンをクリックすると、スライドショーを終了し、作品選択の画面に戻ります。

                アニメーションGIFの書き出し

                        右下の「かきだす」ボタンをクリックすると、選択した画像を元にアニメーションGIFファイルを生成します。

                        💡 Note: At least two images must be selected. (To
                        export a single image, use the 'Export' option from
                        the main 'Open' dialog.) If no images are selected,
                        Tux Paint will not attempt to generate a GIF based on
                        all saved images.

                        アニメーションGIFの生成中に [Escape]
                        キーを押すと、処理を中断して「スライドショー」ダイアログに戻ります。

           さらに「もどる」ボタンをクリックすれば、「ひらく」ダイアログに戻ります。

   プログラムの終了

           「やめる」ボタンを押すか、Tux Paint のウィンドウを閉じるか、[Escape] キーを押せば、Tux Paint
           が終了します。

           その際、本当に終了するかどうかを確認されます。

           If you choose to quit, and you haven't saved the current picture,
           you will first be asked if wish to save it. If it's not a new
           image, you will then be asked if you want to save over the old
           version, or create a new entry. (See "Save" above.)

           ⚙ 注: "startblank" オプションが設定されている場合を除き、終了時に保存した作品は、次に Tux Paint
           を起動するときに自動的に読み込まれます。

           ⚙ 注: 「やめる」ボタンと [Escape] キーによるプログラム終了は、"noquit" オプションで無効にできます。

           この場合、タイトルバーの「閉じる」ボタンか、[Alt] + [F4] キーで終了することができます。

           また、上記のどちらの方法も使えない場合、[Shift] + [Control / ⌘] + [Escape]
           のキーの組み合わせで終了できます。

           ⚙ 詳細は "各種設定について" のドキュメントを参照して下さい。

   効果音を消すには

           今のところ画面上には消音のためのボタンはありませんが、[Alt] + [S]
           キーを押すと効果音は無効になり、もう一度押すと有効になります。

           なお、"nosound" オプションによって効果音が無効にされている場合は、[Alt] + [S]
           キーによる効果音の操作はできません。（親や先生が効果音を無効にすれば、この操作で音を出すことはできないということです）

           ⚙ 詳細は "各種設定について" のドキュメントを参照して下さい。

                             他の画像の Tux Paint への読み込み

   Tux Paint の「ひらく」ダイアログでは、Tux Paint
   で作成した画像だけが表示されます。その他の画像や写真を読み込んで編集するにはどのようにすれば良いでしょうか？

   そのための方法は簡単で、画像ファイルを PNG (Portable Network Graphic) 形式に変換して、Tux Paint
   で作成した画像が保存されている "saved" フォルダにコピーします。（標準では以下のフォルダ）：

   Windows 10, 8, 7, Vista
           各ユーザーの "AppData" フォルダ。例:
           "C:\Users\username\AppData\Roaming\TuxPaint\saved\"。

   Windows 2000, XP
           各ユーザーの "Application Data" フォルダ。例: "C:\Documents and
           Settings\username\Application Data\TuxPaint\saved\"。

   macOS
           各ユーザーの "Library" フォルダ。例: "/Users/username/Library/Application
           Support/Tux Paint/saved/"。

   Linux/Unix
           各ユーザーのホームディレクトリ("$HOME")の隠しディレクトリ ".tuxpaint" 以下 ― 例:
           "/home/username/.tuxpaint/saved/"。

   💡 注: Tux Paint
   で作成した画像を他のアプリケーションを使って開く場合も、これらのフォルダからになります。しかしながら、「ひらく」ダイアログの「かきだす」の機能を使えば、Tux
   Paint で作成した画像を、もっと簡単で安全にアクセスできるフォルダにコピーすることができます。

"tuxpaint-import" スクリプトを使う

     Linux と Unix では、Tux Paint と同時に、シェルスクリプト "tuxpaint-import"
     がインストールされています。このスクリプトは、NetPBM のツール ("anytopnm") を用いて画像を変換し、 Tux Paint
     のキャンバスに合うように画像サイズを変更 ("pnmscale") し、PNG 形式に変換 ("pnmtopng") します。

     また、このスクリプトは、"date" コマンドを使用して、Tux Paint
     が保存するファイル名に用いる日付と時刻を取得します。(作品を保存したり開いたりするときに、ファイル名を聞かれることはない、ということを思い出してください！)

     スクリプトの使用法は簡単で、コマンドプロンプトで、取り込みたい画像のファイル名を引数として実行するだけです。

     They will be converted and placed in your Tux Paint "saved" directory.

     💡 Note: If you're doing this for a different user (e.g., your child)
     you'll need to make sure to run the command under their account.)

     Example:

       $ tuxpaint-import おばあちゃん.jpg
       おばあちゃん.jpg -> /home/username/.tuxpaint/saved/20211231012359.png
       jpegtopnm: WRITING A PPM FILE

     1行目 ("tuxpaint-import おばあちゃん.jpg") が実行するコマンドで、続く2行がプログラムの実行中の出力です。

     これで、Tux Paint を起動して、「ひらく」ダイアログから変換した画像を開くことができます。後は、アイコンをダブルクリックするだけです！

手動での取り込み

     Windows、MacOS、BeOS、そして Haiku のユーザーは、手動で変換作業を行う必要があります。

     変換したい画像ファイルの読み込み、PNG
     形式ファイルでの保存に対応した画像処理プログラムを起動します。(推奨されるソフトウェア、その他の情報については、"PNG.html"
     をお読みください。)

     Tux Paint で、描画キャンパスと異なる大きさの画像を読み込む場合、キャンバスに合うように拡大・縮小されます。

     画像が引き伸ばされたりぼやけたりしないようにするには、キャンパスの大きさに合うようにサイズを変更します。キャンパスの大きさは、Tux Paint
     のウィンドウサイズや、フルスクリーン動作時の画面解像度に依存します。(注: 標準の解像度は 800x600 です)。 以下の
     "イメージサイズの計算方法" をごらんください。

     画像は PNG 形式で保存してください。また、以下のように、Tux Paint
     における命名規則である、現在の日付と時刻を用いたファイル名を使用することを強くお勧めします。

       YYYYMMDDhhmmss.png

       * YYYY = 年
       * MM = 月 (2桁, "01"-"12")
       * DD = 日 (2桁, "01"-"31")
       * HH = 時 (2桁, 24時間表示, "00"-"23")
       * mm = 分 (2桁, "00"-"59")
       * ss = 秒 (2桁, "00"-"59")

     例：2021年7月31日 午前11時5分であれば、20210731110500.png のようになります。

     PNG ファイルを Tux Paint の "saved" ディレクトリにコピーします。（上記参照）

  イメージサイズの計算方法

       This part of the documentation needs to be rewritten, since the new
       "buttonsize" option was added. For now, try drawing and saving an
       image within Tux Paint, then determine what size (pixel width and
       height) it came out to, and try to match that when scaling the
       picture(s) you're importing into Tux Paint.

                                   その他のドキュメント

   このドキュメントの他、"docs" フォルダには、次のようなドキュメントがあります：

   Using Tux Paint:
              * OPTIONS.html
                コマンドライン、設定ファイルのオプションに関する詳細な情報。Tux Paint Config を使用したくない人向け。
              * 「まほう」ツールに関するドキュメント ("magic-docs")
                インストールされている、それぞれの「まほう」ツールに関する説明。

   How to extend Tux Paint:
              * EXTENDING.html
                ブラシ、はんこ、背景画像の作成方法、フォントを追加する方法、追加のスクリーンキーボードの作成、言語入力の追加など、Tux
                Paint の拡張についての詳細説明。
              * PNG.html
                PNG 形式の画像を作成する方法。
              * SVG.html
                SVG 形式のヴェクタ画像を作成する方法。

   Technical information:
              * INSTALL.html
                コンパイル、インストールの手順.
              * SIGNALS.html
                Tux Paint が応答する POSIX シグナルに関する情報。

   Development history and license:
              * AUTHORS.txt
                作者と協力者のリスト.
              * CHANGES.txt
                リリース毎の変更点の概要.
              * COPYING.txt
                Tux Paint's software license, the GNU General Public License
                (GPL)

                                    お問い合わせ先

   If you need help, there are numerous ways to interact with Tux Paint
   developers and other users:
     * バグを発見した場合や機能追加の要望については、プロジェクトの バグトラッキングシステムから報告できます
     * プロジェクトに関する様々なメーリングリストに参加できます
     * 開発者へ直接連絡することもできます

   もっとお知りになりたい場合、Tux Paint のウェブサイト の "連絡先" のページ
   (https://tuxpaint.org/contact/) をごらん下さい

                                   プロジェクトへの参加

   Tux Paint is a volunteer-driven project, and we're happy to accept your
   help in a variety of ways:
     * Tux Paint の翻訳の作成
     * 既存の翻訳の改善
     * アートワークの作成 (スタンプ、背景画像、ペイントブラシなど)
     * 機能の追加や改良、「まほう」ツールの作成
     * 学習教材の作成
     * 宣伝や、他の Tux Paint ユーザーのサポート

   もっとお知りになりたい場合、Tux Paint のウェブサイト の "私たちにご協力を" のページ
   (https://tuxpaint.org/help/) をごらん下さい

                               Trademark notices

     * "Linux" is a registered trademark of Linus Torvalds.
     * "Microsoft" and "Windows" are registered trademarks of Microsoft Corp.
     * "Apple" and "macOS" are registered trademarks of Apple Inc.
     * "Twitter" is a registered trademark of Twitter, Inc.
