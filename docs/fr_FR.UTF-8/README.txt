                                   Tux Paint
                                version 0.9.31

                     Un programme simple pour les enfants

       Copyright © 2002-2023 by divers contributeurs; voir AUTHORS.txt.
                             https://tuxpaint.org/

                               juillet 20, 2023

+-------------------------------------------------------+
|                  Table des matières                   |
|-------------------------------------------------------|
|  I. À propos de Tux Paint                             |
| II. Utiliser Tux Paint                                |
|      A. Lancement de Tux Paint                        |
|      B. Écran titre                                   |
|      C. Écran principal                               |
|      D. Outils disponibles                            |
|          1. Outils de dessin                          |
|              a. Outil "Peinture" (pinceau)            |
|              b. Outil "Tampon" (tampon de caoutchouc) |
|              c. Outil "Lignes"                        |
|              d. Outil "Formes"                        |
|              e. Outils "Texte" et "Étiquette"         |
|              f. Outil "Remplir"                       |
|              g. Outil "Magie" (Effets spéciaux)       |
|              h. Outil "Gomme"                         |
|          2. Autres contrôles                          |
|              a. Commandes "Défaire" et "Refaire"      |
|              b. Commande "Nouveau"                    |
|              c. Commande "Ouvrir"                     |
|              d. Commande "Sauvegarder"                |
|              e. Commande "Imprimer"                   |
|              f. Commande "Diapos" (sous "Ouvrir")     |
|              g. Commande "Quitter"                    |
|              h. Coupure du son                        |
|      E. Contrôle de Tux Paint                         |
| III. Chargement d'autres images dans Tux Paint        |
| IV. Lectures complémentaires                          |
|  V. Comment obtenir de l'aide                         |
| VI. Comment participer                                |
+-------------------------------------------------------+

I. À propos de Tux Paint

A. Qu'est-ce que "Tux Paint" ?

Tux Paint est un programme de dessin gratuit conçu pour les jeunes enfants
(enfants de 3 ans et plus). Il possède une interface simple et facile à
utiliser, des effets sonores amusants et une mascotte de dessin animé pour
encourager et guider les enfants lorsqu'ils utilisent le programme. Sont
fournis une toile vierge et un ensemble d'outils de dessin pour aider votre
enfant à être créatif.

B. Objectifs

Facile et amusant
    Tux Paint se veut un simple programme de dessin pour les jeunes enfants. Il
    ne s'agit pas d'un programme de dessin à usage général. Il se veut amusant
    et facile à utiliser. Les effets sonores et un personnage de dessin animé
    permettent à l'utilisateur de savoir ce qui se passe tout en le
    divertissant. Il existe également des pointeurs de souris, de style dessin
    animé, extra-larges.

Flexibilité
    Tux Paint est extensible. Les brosses et les formes de "tampon en
    caoutchouc" peuvent être déposées et retirées. Par exemple, un enseignant
    peut apporter une collection de formes animales et demander à ses élèves de
    dessiner un écosystème. Chaque forme peut avoir un son qui l'accompagne et
    un texte est affiché lorsque l'enfant sélectionne la forme.

Portabilité
    Tux Paint est portable sur diverses plates-formes informatiques: Windows,
    Macintosh, Linux, etc. L'interface est la même sur toutes. Tux Paint
    fonctionne correctement sur les systèmes plus anciens (comme un Pentium
    133), et peut être modifié pour mieux fonctionner sur des systèmes lents.

Simplicité
    Il n'y a pas d'accès direct à la complexité sous-jacente de l'ordinateur.
    L'image en cours est conservée lorsque le programme se ferme et réapparaît
    au redémarrage. L'enregistrement d'images ne nécessite pas la création de
    noms de fichiers ou l'utilisation du clavier. L'ouverture d'une image se
    fait en la sélectionnant dans une collection de vignettes. L'accès à
    d'autres fichiers sur l'ordinateur est restreint.

Accessibilité
    Tux Paint offers a number of accessibility options, including increasing
    the size of control buttons, changing the UI font, options to control the
    cursor (mouse pointer) using the keyboard or other input devices (joystick,
    gamepad, etc.), an on-screen keyboard, and "stick" mouse clicks.


C. Licence

Tux Paint est un projet Open Source, un logiciel libre publié sous la licence
publique générale GNU (GPL). Il est gratuit et le «code source» du programme
est disponible. (Cela permet à d'autres d'ajouter des fonctionnalités, de
corriger des bogues et d'utiliser des parties du programme dans leur propre
logiciel sous GPL.)

Voir COPYING.txt pour le texte complet de la licence GPL.

D. Qu'y a-t-il de neuf dans la version 0.9.31 de Tux Paint ?

Gomme floue
    Fuzzy-edged round erasers have been added to the Eraser tool

Nouveaux outils Magie
    Loops, Ribbon, Smooth, and Squiggles

Create templates from Open dialog
    Saved drawings can be turned into templates (used to make new drawings) via
    a new option in the Open dialog. (This feature may be deactivated using the
    "notemplateexport" simplification option.)

User interface font may be overridden
    The font used for the user interface (button labels, dialog pop-ups, and
    instructions) can be overridden from its default ("DejaVu Sans"). (See the
    "uifont" configuration option. Use "--listfonts" to see a list of available
    fonts.)

L'effacement de fichier peut être désactivé

    Controls to erase saved work — saved drawings (via the Open dialog) and
    exported templates (via the New dialog) — can be disabled. (See the
    "noerase" configuration option.)

Documentation sur "Contrôler Tux Paint"

    A brief overview of how Tux Paint can be controlled — mouse, tablet,
    touchscreen, joystick, and keyboard — has been added to the README
    documentation.


Voir CHANGES.txt pour la liste complète des changements.

II. Utiliser Tux Paint

A. Lancement de Tux Paint

1. Utilisateurs de Linux/Unix

Tux Paint devrait avoir mis une icône de lanceur dans vos menus KDE et/ou
GNOME, sous «Graphiques».

Autrement, vous pouvez exécuter la commande suivante à une invite du shell (par
exemple, "$") :

    $ tuxpaint

Si des erreurs se produisent, elles seront affichées sur le terminal
("stderr").

2. Utilisateurs de Windows

[Icône pour Tux Paint]
      Tux Paint

Si vous avez installé Tux Paint sur votre ordinateur en utilisant le 'Tux Paint
Installer', il vous aura demandé si vous vouliez un raccourci de menu
'Démarrer' et / ou un raccourci sur le bureau. Si vous avez accepté, vous
pouvez simplement exécuter Tux Paint à partir de la section 'Tux Paint' de
votre menu 'Démarrer' (par exemple, sous «Tous les programmes» sous Windows
XP), ou en double-cliquant sur l'icône «Tux Paint» sur votre bureau .

Si vous avez installé Tux Paint en utilisant le téléchargement 'ZIP-file', ou
si vous avez utilisé 'Tux Paint Installer', mais que vous avez choisi de ne pas
installer de raccourcis, vous devrez double-cliquer sur l'icône "tuxpaint.exe"
dans le dossier "Tux Paint" de votre ordinateur.

Par défaut, le 'Tux Paint Installer' mettra le dossier de Tux Paint dans "C:\
Program Files\",ou bien vous avez pu changer cela lors de l'exécution du
programme d'installation.

Si vous avez utilisé le téléchargement de 'ZIP-file', le dossier de Tux Paint
sera là où vous l'avez placé lorsque vous avez décompressé le fichier ZIP.

3. Utilisateurs de macOS

Double-cliquez simplement sur l'icône "Tux Paint".

[Écran-titre]

B. Écran titre

Lors du premier chargement de Tux Paint, un écran avec titre et crédits
apparaîtra.

Une fois le chargement terminé, appuyez sur une touche ou cliquez sur la souris
pour continuer. (Ou, après environ 30 secondes, l'écran-titre disparaîtra
automatiquement.)

C. Écran principal

L'écran principal est divisé en plusieurs sections :

[Outils : Peindre, Tampon, Lignes, Formes, Texte, Magie, Étiquette, Défaire,
    Refaire, Gomme, Nouveau, Ouvrir, Sauvegarder, Imprimer, Quitter]
Côté gauche : la barre d'outils

    La barre d'outils contient les commandes pour dessiner et éditer.



    [Toile]
Milieu : Toile pour Dessiner

    La plus grande partie de l'écran, au centre, est la toile de dessin. C'est
    évidemment là que vous dessinerez !

    💡 Remarque: la taille de la toile de dessin dépend de la taille de Tux
    Paint. Vous pouvez modifier la taille de Tux Paint à l'aide de l'outil de
    configuration tuxpaint-config, ou par d’autres moyens. Consultez la
    documentation OPTIONS pour plus de détails.



    [Sélecteurs - Pinceaux, Lettres, Formes, Tampons]
Côté droit : sélecteur

    En fonction de l'outil en cours d'utilisation, le sélecteur affiche
    différentes choses. Par exemple, lorsque l'outil Pinceau est sélectionné,
    il affiche les différents pinceaux disponibles. Lorsque l'outil Tampon en
    caoutchouc est sélectionné, il affiche les différentes formes que vous
    pouvez utiliser.



    [Couleurs - Noir, Blanc, Rouge, Rose, Orange, Jaune, Vert, Cyan, Bleu,
    Pourpre, Brun, Gris]
En bas : couleurs

    When the active tool supports colors, a palette of colors choices will be
    shown near the bottom of the screen. Click one to choose a color, and it
    will be used by the active tool. (For example, the "Paint" tool will use it
    as the color to draw with the chosen brush, and the "Fill" tool will use it
    as the color to use when flood-filling an area of the picture.)

    On the far right are three special color options:
      + Sélecteur de couleur
        Le "sélecteur de couleurs" (qui ressemble à un compte-gouttes) vous
        permet de choisir une couleur trouvée dans votre dessin.
        (A shortcut key is available to access this feature quickly; see
        below.)
      + Palette de l'Arc-en-ciel
        The rainbow palette allows you to pick any color by choosing the hue,
        saturation, and value of the color you want. A box on the left displays
        hundreds of hues — from red at the top through to violet at the bottom
        — at hundreds of saturation/intensity levels — from pale & washed-out
        on the left through to pure on the right. A grey vertical bar provides
        access to hundreds of value levels — from lighest at the top through to
        darkest at the bottom.
        Click the green checkbox button to select the color, or the "Back"
        button to dismiss the pop-up without picking a new color.
        You may also set this tool's color to that of other color choices:
          o Whichever built-in color is selected, if any
          o Couleur actuelle du Sélecteur de couleur
          o Couleur actuelle du mélangeur de couleurs
      + Mélangeur de couleurs
        The "color mixer" (which has silhouette of a paint palette) allows you
        to create colors by blending primary additive colors — red, yellow, and
        blue — along with white (to "tint"), grey (to "tone"), and black (to
        "shade").
        You may click any button multiple times (for example, red + red +
        yellow results in a red-orange color). The ratios of colors added are
        shown at the bottom.
        You can start over (reset to no colors in your picture) by clicking the
        "Clear" button. You can also undo or redo multiple steps of mixing, in
        case you made a mistake (without having to start over).
        Click the green checkbox button to select the color, or the "Back"
        button to dismiss the pop-up without picking a new color.

    ⌨ When the active tool supports colors, a shortcut may be used for quick
    access to the "color picker" option. Hold the [Control] key while clicking,
    and the color under the mouse cursor will be shown at the bottom. You may
    drag around to canvas to find the color you want. When you release the
    mouse button, the color under the cursor will be selected. If you release
    the mouse outside of the canvas (e.g., over the "Tools" area), the color
    selection will be left unchanged. (This is similar to clicking the "Back"
    button that's available when bringing up the "color picker" option via its
    button the color palette.)

    ⚙ Note : Vous pouvez définir vos propres couleurs. Voir la documentation "
    Options" .



    (Par exemple : Choisis une forme. Clique pour démarrer le dessin , fais
    glisser et continue jusqu'à la taille désirée. Déplace-toi pour la faire
    tourner, et clique pour dessiner.)
En bas : zone d'aide

    Tout en bas de l'écran, Tux, le pingouin Linux, fournit des conseils et
    d'autres informations pendant que vous dessinez.




D. Outils disponibles

1. Outils de dessin

a. Outil "Peinture" (pinceau)

    L'outil Pinceau vous permet de dessiner à main levée, en utilisant
    différents pinceaux (choisis dans le sélecteur à droite) et couleurs
    (choisis dans la palette de couleurs qui est en bas).

    Si vous maintenez le bouton de la souris enfoncé et déplacez la souris,
    elle dessine au fur et à mesure que vous vous déplacez.

    Cerains pinceaux sont animés — ils changent de forme lorsque vous dessinez.
    Un bon exemple est le pinceau 'grappe' livré avec Tux Paint. Ces pinceaux
    ont une icône avec une petite pellicule dessinée sur le bouton de
    sélection.

    D'autres pinceaux sont directionnels — leur forme dépend de la direction
    dans laquelle vous dessinez. Un exemple est le pinceau flèche livré avec
    Tux Paint. Ces pinceaux ont une petite étoile à 8 branches sur leur icône
    du bouton de sékection.

    Et enfin, certains pinceaux peuvent être = la fois directionnels et animés.
    Des exemples sont les pinceaux 'chat' et 'écureuil' livrés avec Tux Paint.
    Ces pinceaux ont à la fois une pellicule et une étoile à 8 branches sur
    leur icône.

    Pendant que vous dessinez, un son est joué. Plus la brosse est grosse, plus
    le son est grave.

    Espacement des pinceaux


        The space between each position where a brush is applied to the canvas
        can vary. Some brushes (such as the footprints and flower) are spaced,
        by default, far enough apart that they don't overlap. Other brushes
        (such as the basic circular ones) are spaced closely, so they make a
        continuous stroke.

        L'espacement des coups de pinceau peut être changé en cliquant dans
        l'ensemble de barres (de forme triangulaire) en bas à droite; plus la
        barre est grande, plus l'espacement est grand. Le réglage de
        l'espacement des coups de pinceaux affecte deux outils utilisant les
        pinceaux ! l'outil "Peindre" et l'outil "Ligne".

        ⚙ Note: Si l'option "nobrushspacing" est définie, Tux Paint n'affichera
        pas les contrôles d'espacement des coups de pinceaux. Voir la
        documentation "Options".



b.Outil "Tampon" (tampon de caoutchouc)

    L'outil Tampon montre un ensemble de tampons en caoutchouc ou
    d'autocollants. Il vous permet de coller des images pré-dessinées ou
    photographiques (comme l'image d'un cheval, d'un arbre ou de la lune) dans
    votre dessin.

    Lorsque vous déplacez la souris sur le canevas, une forme suit la souris,
    indiquant où le tampon sera placé, ainsi que sa taille. Cliquez sur le
    canevas à l'endroit où vous voulez placer le tampon.

    Catégories de tampons
        Il peut y avoir de nombreuses catégories de timbres (par ex. animaux,
        plantes, espace extra-atmosphérique, véhicules, personnes, etc.).
        Utilisez les flèches gauche et droite pour parcourir les différentes
        collections.

    Rotation des tampons

        Using the rotation toggle button near the bottom right, you can enable
        a rotation step when placing stamps. Once you've placed the stamp,
        choose the angle to rotate it by moving the mouse around the canvas.
        Click the mouse button again and the stamp will be added to the
        drawing.

        ⚙ Note : Si l'option de "rotation des tampons" est désactivée, le
        tampon sera mis sur le canevas quand vous relâchez le bouton de la
        souris (Il n'y a pas d'étape de rotation). Voir la documentation sur "
        Options" pour tout savoir sur l'option rotation d'un tampon"
        ("stamprotation").

        📜 Note : La possibilité de rotation des tampons a été incorporée dans
        Tux Paint avec la version 0.9.29.



    Contrôles des tampons

        Avant de `` tamponner '' une image sur votre dessin, différents effets
        peuvent parfois être appliqués (en fonction du tampon) :

          o Certains tampons peuvent être colorés ou teintés. Si la palette de
            couleurs sous le canevas est activée, vous pouvez cliquer sur les
            couleurs pour changer la teinte ou la couleur du tampon avant de le
            placer dans le dessin.
          o Les tampons peuvent être rétrécis et agrandis, en cliquant dans
            l'ensemble de barres (de forme triangulaire) en bas à droite; plus
            la barre est grande, plus le tampon apparaîtra grand sur votre
            dessin.
          o De nombreux tampons peuvent être retournés verticalement ou
            affichés sous forme d'image miroir à l'aide des boutons de commande
            en bas à droite.

        ⚙ Note: Si l'option "nostampcontrols" est définie, Tux Paint
        n'affichera pas les commandes Rotation, Miroir, Retourner, Réduire et
        Agrandir pour les tampons. Voir la documentation "Options".



    Effets sonores des tampons

        Les tampons peuvent avoir un effet sonore et / ou une description orale
        (parlés). Les boutons en bas à gauche (près de Tux, le pingouin Linux)
        vous permettent de rejouer les effets sonores et la description du
        tampon actuellement sélectionné.






c.Outil "Lignes"

    Cet outil vous permet de dessiner des lignes droites à l'aide des
    différents pinceaux et couleurs que vous utilisez habituellement.

    Click the mouse and hold it to choose the starting point of the line. As
    you move the mouse around, a thin 'rubber-band' line will show where the
    line will be drawn. At the bottom, you'll see the angle of your line, in
    degrees. A line going straight to the right is 0°, a line going straight up
    is 90°, a line going straight left is 180°, a line going straight down is
    270°, and so on.

    Relâchez la souris pour terminer la ligne. On entend alors le son "sproing
    !".

    Certains pinceaux sont animés, et montre un ensemble formes le long d'une
    ligne. D'autres sont directionnels et montre des formes différentes suivant
    l'angle du pinceau. Et enfin certains sont à la fois animés et
    directionnels. Voir "Paint", au-dessus, pour en savoir plus.

    Different brushes have different spacing, leaving either a series of
    individual shapes, or a continuous stroke of the brush shape. Brush spacing
    may be adjusted. See the brush spacing section of the "Paint" tool, above,
    to learn more.



d.Outil "Formes"

    Cet outil vous permet de dessiner des formes simples remplies ou non
    remplies.

    Choisissez une forme dans le sélecteur de droite (cercle, carré,ovale,
    etc.).

    Utilisez les options en bas à droite pour choisir le comportement de
    l'outil :

    Formes à partir du centre
        La forme se développe à partir de l'endroit où vous avez cliqué
        initialement et sera centrée autour de cette position.

        📜 This was Tux Paint's only behavior through version 0.9.24.)



    Formes à partir d'un coin
        La forme se développe à partir d'un coin depuis l'endroit où vous avez
        cliqué initialement. Il s'agit de la méthode par défaut de la plupart
        des autres logiciels de dessin traditionnels.

        📜 Cette option a été ajoutée en démarrant la version 0.9.25 de Tux
        Paint.




    ⚙ Remarque : si les contrôles de forme sont désactivés (par exemple, avec
    l'option "noshapecontrols"), il n'y aura pas de contrôle et la méthode
    "formes à partir du centre" sera utilisée.

    Dans le dessin, cliquez sur la souris et maintenez-la pour étirer la forme
    à partir de l'endroit où vous avez cliqué. Certaines formes peuvent changer
    de proportion (par exemple, le rectangle et l'ovale peuvent être plus
    larges que hauts ou plus hauts que larges), d'autres pas (par exemple,
    carré et cercle).

    For shapes that can change proportion, the aspect ratio of the shape will
    be shown at the bottom. For example: "1:1" will be shown if it is "square"
    (as tall as it is wide); "2:1" if it is either twice as wide as it is tall,
    or twice as tall as it is wide; and so on.

    Relâchez la souris lorsque vous avez terminé l'étirement.

    Mode normal

        Now you can move the mouse around the canvas to rotate the shape. The
        angle your shape is rotated will be shown at the bottom, in degrees
        (similar to the "Lines" tool, described above).

        Cliquez à nouveau sur le bouton de la souris et la forme sera dessinée
        avec la couleur en cours.



    Mode de Formes Simples
        Si l'option "formes simples" est activée, la forme sera dessinée sur le
        canevas lorsque vous relâcherez le bouton de la souris. (Il n'y a pas
        de rotation.)

        ⚙ Voir la documentation sur "Options" pour tout savoir sur l'option
        formes simples" ("simpleshapes").






e.Outils "Texte" et "Étiquette"

    Choisissez une police (parmi les «Lettres» disponibles sur la droite) et
    une couleur (dans la palette de couleurs en bas). Vous pouvez aussi
    appliquer des effets tels que caractère gras et/ou italique. Cliquez sur
    l'écran et un curseur apparaîtra. Tapez un texte et il apparaîtra à
    l'écran. (Vous pouvez changer la police, la couleur et le style en entrant
    le texte, avant de l'appliquer sur le canevas).

    Appuyez sur [Entrée] ou [Retour] et le texte sera inclus dans l'image et le
    curseur se déplacera d'une ligne vers le bas.

    Sinon, appuyez sur [Tab] et le texte sera inclus dans l'image, mais le
    curseur se déplacera vers la droite du texte, plutôt que vers le bas d'une
    ligne et vers la gauche. (Cela peut être utile pour créer une ligne de
    texte avec des couleurs, des polices, des styles et des tailles variés.)

    Cliquer ailleurs dans l'image alors que l'entrée de texte est toujours
    active entraîne le déplacement de la ligne de texte actuelle vers cet
    emplacement (et vous pouvez continuer à la modifier).

    "Texte" par rapport à "Étiquette"

        L' outil Texte est l'outil de saisie de texte original de Tux Paint. Le
        texte saisi à l'aide de cet outil ne peut pas être modifié ou déplacé
        ultérieurement, car il fait partie du dessin. Cependant, comme le texte
        fait partie de l'image, il peut être dessiné ou modifié à l'aide des
        effets de l'outil Magie (par exemple, taché, teinté, gaufré, etc.)

        Lors de l'utilisation de l' outil Étiquette (qui a été ajouté à Tux
        Paint dans la version 0.9.22), le texte `` flotte '' sur l'image, et
        les détails de l'étiquette (le texte, la position de l'étiquette, le
        choix de la police et la couleur ) sont stockés séparément. Cela permet
        à l'étiquette d'être repositionnée ou modifiée ultérieurement.

        To edit a label, click the label selection button. All labels in the
        drawing will appear highlighted. Click one — or use the [Tab] key to
        cycle through all the labels, and the [Entrée] or [Retour] key to
        select one — and you may then edit the label. (Use they [Retour
        arrière] key to erase characters, and other keys to add text to the
        label; click in the canvas to reposition the label; click in the
        palette to change the color of the text in the label; etc.)

        You may "apply" a label to the canvas, painting the text into the
        picture as if it had been added using the Text tool, by clicking the
        label application button. (This feature was added in Tux Paint version
        0.9.28.) All labels in the drawing will appear highlighted, and you
        select one just as you do when selecting a label to edit. The chosen
        label will be removed, and the text will be added directly to the
        canvas.

        ⚙ L' outil Étiquette peut être désactivé (par exemple, en sélectionnant
        "Désactiver l'outil 'Label'" dans Tux Paint Config ou bien en exécutant
        Tux Paint en ligne de commande avec l'option "nolabel").



    Saisie de caractères internationaux

        Tux Paint permet de saisir des caractères dans différentes langues. La
        plupart des caractères latins ( A - Z , ñ , è , etc...) peuvent être
        saisis directement. Certaines langues exigent que Tux Paint soit
        commuté dans un mode d'entrée alternatif avant la saisie, et certains
        caractères doivent être composés en utilisant plusieurs touches.

        Lorsque les paramètres régionaux de Tux Paint sont définis sur l'une
        des langues fournissant des modes de saisie alternatifs, une touche est
        utilisée pour parcourir le ou les modes soit normaux (caractère latin)
        soit spécifiques aux paramètres régionaux.

        Currently supported locales, the input methods available, and the key
        to toggle or cycle modes, are listed below.

          o Japonais -- Hiragana et Katakana romanisés — touche [Alt] droite ou
            touche [Alt] gauche
          o Korean — Hangul 2-Bul — touche [Alt] droite or touche [Alt] gauche
          o Chinois traditionnel — touche [Alt] droite or touche [Alt] gauche
          o Thai — touche [Alt] droite

        💡 Note : de nombreuses polices n'incluent pas tous les caractères pour
        toutes les langues, vous devriez donc parfois changer de police pour
        voir les caractères que vous essayez de saisir.



    Clavier virtuel sur écran

        Un clavier virtuel sur écran (optionnel) est disponible pour les outils
        "Texte" et "Étiquette", qui peut présenter une palette de dispositions
        et de création de caractères (par ex "a" et "e" pour "æ").

        ⚙ Voir les documents "Options" et "Extension de Tux Paint" pour plus
        d'informations.






f.Outil "Remplir"

    L'outil «Remplir» «remplit» une zone contiguë de votre dessin avec une
    couleur unie de votre choix. Trois options de remplissage sont offertes :
      + Uni — cliquez une fois pour remplir une zone avec une couleur unie.
      + Pinceau — cliquez et glissez pour remplir une zone avec une couleur
        unie, lorsque l'on fait de la peinture à main levée.
      + Linéaire—cliquez et faites glisser pour remplir une zone avec une
        couleur qui s'atténue au fur et à mesure dans la direction où vous
        déplacez la souris.
      + Radial—cliquez une fois pour remplir une zone avec une couleur qui
        s'atténue graduellement, à partir de l'endroit où vous avez cliqué.
      + Radial—cliquez une fois pour remplir une zone avec une couleur qui
        s'atténue graduellement, à partir de l'endroit où vous avez cliqué.

    📜 Note : Avant Tux Paint 0.9.24, "Remplir" était un outil "magique" (voir
    ci-dessous). Avant Tux Paint 0.9.26, l'outil "Remplir" n'offrait que la
    méthode 'Uni' pour le remplissage. 'Shaped' fill was introduced in Tux
    Paint 0.9.29.



g.Outil "Magie" (Effets spéciaux)

    L'outil «Magie» est en fait un ensemble d'outils spéciaux. Sélectionnez
    l'un des effets «magiques» dans le sélecteur de droite. Ensuite, selon
    l'outil, vous pouvez soit cliquer et faire glisser dans l'image, et / ou
    simplement cliquer une fois sur l'image pour appliquer l'effet.

    Contrôles des outils Magie


        Si l'outil peut être utilisé en cliquant et en faisant glisser, un
        bouton «peinture» sera disponible sur la gauche, sous la liste des
        outils «magiques» sur le côté droit de l'écran. Si l'outil peut
        affecter toute l'image en entier, un bouton «Image entière» sera
        disponible sur la droite.

        ⚙ Note: Si l'option "nomagiccontrols" est définie, Tux Paint
        n'affichera pas les contrôles pour peindre. Voir la documentation de "
        Options" .

        💡 If the magic controls are disabled, the Magic plugin may make
        separate tools available, one for painting and one that affects the
        entire pictre.

    Magic Sizing


        Some tools offer different sizing options. If so, a slider will appear
        at the bottom right side of the screen. This may affect the radius of a
        special effect (e.g., Darken) or painted object (e.g., Patterns), or
        other attributes (e.g., large versus small Brick shapes).

        ⚙ Note : Si l'option "nomagicsizes" est définie, Tux Paint n'affichera
        pas les contrôles de dimension. Voir la documentations sur "Options" .

        💡 If the sizing option is disabled, the Magic plugin may simply offer a
        default size (e.g., Patterns), or it may make separate tools available
        with different pre-set sizes (e.g., Bricks and Googly Eyes).

        📜 Cette option a été ajoutée en démarrant la version 0.9.30 de Tux
        Paint.

    Voir les instructions pour chaque outil 'Magie' (dans le dossier
    'magic-docs').



h.Outil "Gomme"

    Cet outil est similaire au pinceau. Partout où vous cliquez (ou cliquez et
    faites glisser), l'image sera effacée. (Cela peut être du blanc, une autre
    couleur ou une image d'arrière-plan, selon l'image.)

    Un certain nombre de tailles de gommes sont disponibles, soit rondes soit
    carrées. Des formes rondes avec contour flou sont aussi disponibles.

    Lorsque vous déplacez la souris, un contour carré suit le pointeur,
    indiquant quelle partie de l'image sera effacée en blanc.

    Au fur et à mesure que vous effacez, un grincement est émis.

    ⌨ Hold the [X] key while clicking for quick access to a small sharp round
    eraser (not available when the Text or Label tools are selected, when
    you're in the process of rotating a stamp or shape, or when using an
    interactive magic tool). Release the mouse to return to your
    currently-selected tool.




2. Autres contrôles

a.Commandes "Défaire" et "Refaire"

    Cliquer sur le bouton "Défaire" annulera la dernière action. Vous pouvez
    même annuler plus d'une fois !

    ⌨ Remarque : vous pouvez également appuyer [Control / ⌘] + [Z] sur le
    clavier pour Défaire.

    Cliquer sur le bouton "Refaire" annulera l'action que vous venez juste
    faire avec le bouton «Défaire».

    Tant que vous ne dessinez plus, vous pouvez refaire autant de fois que vous
    avez défait !

    ⌨ Remarque : vous pouvez également appuyer [Control / ⌘] + [R] sur le
    clavier pour Refaire.



b.Commande "Nouveau"

    Cliquez sur le bouton "Nouveau" pour démarrer un nouveau dessin. Une boîte
    de dialogue apparaîtra, avec laquelle vous pouvez choisir de commencer une
    nouvelle image en utilisant une couleur d'arrière-plan unie, ou en
    utilisant une image 'Starter' ou 'Template' (voir ci-dessous). On vous
    demandera d'abord si vous voulez vraiment faire cela.

    ⌨ Remarque : vous pouvez également appuyer [Control / ⌘] + [N] sur le
    clavier pour commencer un nouveau dessin.

    Choix de couleurs unies en arrière plan
        Along with the preset solid colors, you can also choose colors using a
        rainbow palette or a "color mixer". These operate identically to the
        options found in the color palette shown below the canvas when drawing
        a picture. See Main Screen > Lower: Colors > Special color options for
        details.

    Images de "Démarrage" et images "Modèle"
          o Les "Images de démarrage" se comportent comme une page d'un livre
            de coloriage - un contour noir et blanc d'une image, que vous
            pouvez ensuite colorier, et le contour noir reste intact - ou comme
            une photographie 3D, où vous dessinez entre une couche de premier
            plan et une d'arrière-plan.
          o Les "Images modèle" sont semblables, mais fournissent simplement un
            dessin d'arrière-plan sur lequel travailler. Contrairement aux
            «Images de démarrage», rien de ce que vous dessinerez ne restera au
            premier plan.

        Lorsque vous utiliserez l'outil «Gomme», l'image d'origine du
        «Démarrage» ou du «Modèle» réapparaîtra. Les outils magiques
        "Retourner" et "Miroir" affecteront aussi bien l'orientation de
        "l'image de démarrage" que celle de "l'image Modèle".

        Lorsque vous chargez une 'Image modèle' ou 'image modèle', dessinez
        dessus, puis cliquez sur 'Sauvegarder', cela crée un nouveau fichier
        image - il n'écrase pas l'original, vous pouvez donc l'utiliser à
        nouveau plus tard (en y accédant depuis la boîte de dialogue
        'Nouveau').

        ⚙ You can create your own 'Starter' and Template images. See the
        Extending Tux Paint documentation's sections on 'Starters' and
        Templates.

        💡 You can also convert your saved drawings into Templates directly
        within Tux Paint, from the 'Open' dialog. See "Open", below.



    Effaçage des images Modèles exportées

        If you've selected a Template in your personal templates folder, and it
        was created from within Tux Paint (using the "Template" button in the
        "Open" dialog), you may remove it from within Tux Paint, too. An
        'Erase' (trash can) button will appear at the lower right of the list.
        Click it to erase the selected template. (You will be asked to
        confirm.)

        💡 Note : Pour Linux, Windows, et macOS , l'image sera placée dans la
        corbeille de votre bureau (où vous pourrez le restaurer si vous changez
        d'avis).

        ⚙ Note :: Le bouton 'Effacer' peut être désactivé via l'option
        "noerase".




    ⚙ Note: The solid colors can be placed at the end of the 'New' dialog
    (below the Starters and Templates), via the "newcolorslast" option.



c.Commande "Ouvrir"

    Cela vous montre une liste de toutes les images que vous avez enregistrées.
    S'il y en a plus que ce que peut contenir l'écran, utilisez les flèches
    «Haut» et «Bas» en haut et en bas de la liste pour faire défiler la liste
    des images.

    Cliquez sur une image pour la sélectionner, puis ...
      + Cliquez sur le bouton vert "Ouvrir" en bas à gauche de la liste pour
        charger l'image sélectionnée. Vous pourrez alors l'éditer.

        (Vous pouvez également double-cliquer sur l'icône d'une image pour la
        charger.)

        💡 Si vous choisissez d'ouvrir une image et que votre dessin en cours
        n'a pas été enregistré, il vous sera demandé si vous souhaitez
        l'enregistrer ou non. (Voir "Sauvegarder," ci-dessous.)

      + Cliquez sur le bouton marron "Effacer" (poubelle) en bas à droite de la
        liste pour effacer l'image sélectionnée. (Il vous sera demandé de
        confirmer.)

        📜 Note : Pour Linux (à partir de la version 0.9.22), Windows (à partir
        de la vaersion 0.9.27), et macOS (à partir de la version 0.9.29),
        l'image sera placée dans la corbeille de votre bureau (où vous pourrez
        le restaurer si vous changez d'avis).

        ⚙ Note :: Le bouton 'Effacer' peut être désactivé via l'option
        "noerase".

      + Cliquez sur le bouton 'Exporter' près du coin inférieur droit pour
        exporter l'image vers votre dossier d'exportation. (par ex. "~/Pictures
        /TuxPaint/")

    From the "Open" screen you can also:
      + Cliquez sur le bouton bleu "Diapositives" (projecteur de diapositives)
        en bas à gauche pour passer en mode diaporama. Voir "Diaporama",
        ci-dessous, pour les détails.

      + Click the blue 'Template' button at the lower left to go to convert the
        selected picture into a new template, which can be used as the basis
        for new drawings.

        📜 Note : La possibilité de création de Modèles a été ajouté avec la
        version 0.9.31 de Tux Paint. To learn how to create Templates outside
        of Tux Paint, see Extending Tux Paint

        ⚙ La possibilité de création de Modèle peut être désactivée (par ex. en
        choisissant "Désactiver 'Fabriquer un Modèle' dans Tux Paint Config. ou
        en lançant em>Tux Paint avec l'option "notemplateexport").

      + Ou cliquez sur le bouton fléché rouge «Retour» en bas à droite de la
        liste pour annuler et revenir à l'image que vous étiez en train de
        dessiner.

    ⌨ Remarque : vous pouvez également appuyer [Control / ⌘] + [O] sur le
    clavier pour afficher la boîte de dialogue "Ouvrir".



d.Commande "Sauvegarder"

    Pour sauvegarder votre image en cours.

    Si vous ne l'avez pas enregistré auparavant, il créera une nouvelle entrée
    dans la liste des images enregistrées. (c'est-à-dire qu'il créera un
    nouveau fichier)

    💡 Remarque : il ne vous demandera rien (par exemple, un nom de fichier). Il
    enregistrera simplement l'image et fera le bruit d'un obturateur d'appareil
    photographique.

    Si vous avez déjà enregistré l'image, ou s'il s'agit d'une image que vous
    venez de charger à l'aide de la commande "Ouvrir", il vous sera d'abord
    demandé si vous voulez écraser l'ancienne version ou bien créer une
    nouvelle entrée (un nouveau fichier).

    ⚙ Remarque : si les options " saveover" ou " saveovernew" sont déjà
    définies, il ne sera rien demandé avant de sauvegarder. Voir la
    documentation Options.

    ⌨ Remarque : vous pouvez également appuyer [Control / ⌘] + [S] sur le
    clavier pour sauvegarde.



e.Commande "Imprimer"

    Cliquez sur ce bouton et votre image sera imprimée !

    Sur la plupart des plates-formes, vous pouvez également maintenir la touche
    [Alt] (appelée [Option] sur Mac) tout en cliquant sur le bouton «Imprimer»
    pour obtenir une boîte de dialogue d'impression. Notez que cela pourrait ne
    pas fonctionner si vous exécutez Tux Paint en mode plein écran. Voir
    ci-dessous.

    Désactivation de l'impression

        On peut définir une option "noprint", ce qui entraînera la
        désactivation du bouton "Imprimer".

        ⚙ Voir la documentation sur "Options".



    Restreindre l'impression

        Si l'option "printdelay" a été utilisée, vous ne pouvez imprimer —
        qu'une fois toutes les x secondes, tel que vous l'avez défini.

        Par exemple, avec "printdelay=60" dans le fichier de configuration de
        Tux Paint, vous ne pouvez imprimer qu'une fois par minute.

        ⚙ Voir la documentation sur "Options".



    Commandes d'impression

        (Linux et Unix uniquement)

        Tux Paint imprime en générant une représentation PostScript du dessin
        et en l'envoyant à un programme externe. Par défaut, le programme est :

            lpr

        Cette commande peut être modifiée en définissant la valeur
        "printcommand" dans le fichier de configuration de Tux Paint.

        Si la touche "[Alt]" du clavier est enfoncée tout en cliquant sur le
        bouton «Imprimer», et tant que vous n'êtes pas en mode plein écran, un
        programme alternatif est exécuté. Par défaut, le programme est la boîte
        de dialogue d'impression graphique de KDE :

            kprinter

        Cette commande peut être modifiée en définissant la valeur
        "altprintcommand" dans le fichier de configuration de Tux Paint.

        ⚙ Voir la documentation sur "Options".



    Réglages pour l'impression

        (Windows et macOS)

        Par défaut, Tux Paint imprime simplement sur l'imprimante par défaut
        avec les paramètres par défaut lorsque le bouton «Imprimer» est
        enfoncé.

        Cependant, si vous maintenez la touche [Alt] (ou [Option]) du clavier
        tout en appuyant sur le bouton "Imprimer, et ceci tant que vous n'êtes
        pas en mode plein écran, la boîte de dialogue de l'imprimante de votre
        système d'exploitation apparaît, et vous pouvez modifier les réglages.

        Vous pouvez stocker les changements de configuration, entre les
        sessions de Tux Paint, en paramétrant l'option "printcfg".

        Si l'option "printcfg" est utilisée, les réglages d'impression seront
        chargés à partir du fichier "printcfg.cfg" de votre répertoire
        personnel (voir ci-dessous). Tout changement y sera ernregistré.

        ⚙ Voir la documentation sur "Options".



    Options de la boîte de dialogue de l'imprimante

        Par défaut, Tux Paint affiche uniquement la boîte de dialogue de
        l'imprimante (ou, sous Linux / Unix, exécute "altprintcommand", par
        exemple, "kprinter" au lieu de "lpr") si la touche [Alt] (ou [Option] )
        est maintenue pendant en cliquant sur le bouton «Imprimer».

        Cependant, ce comportement peut être modifié. Vous pouvez toujours
        faire apparaître la boîte de dialogue de l'imprimante en utilisant
        "--altprintalways" sur la ligne de commande ou "altprint=always" dans
        le fichier de configuration de Tux Paint. Inversement vous pouvez
        empêcher la touche [Alt] / [Option] d'avoir un effet en utilisant
        "--altprintnever" ou "altprint=never".

        ⚙ Voir la documentation sur "Options".






f.Commande "Diapos" (sous "Ouvrir")

    Le bouton "Diapositives" est disponible dans la boîte de dialogue "Ouvrir".
    Il peut être utilisé pour lire une simple animation dans Tux Paint, ou un
    diaporama. Il peut également exporter un GIF animé basé sur les images
    choisies.

    Choisir des images

        Lorsque vous entrez dans la section "Diapos" de Tux Paint, il affiche
        une liste de vos fichiers enregistrés, tout comme la boîte de dialogue
        "Ouvrir".

        Cliquez sur chacune des images que vous souhaitez afficher dans une
        présentation de style diaporama, une par une. Un chiffre apparaîtra sur
        chaque image, vous indiquant dans quel ordre elles seront affichées.

        Vous pouvez cliquer sur une image sélectionnée pour la désélectionner
        (la retirer de votre diaporama). Cliquez à nouveau dessus si vous
        souhaitez l'ajouter à la fin de la liste.



    Régler la vitesse de lecture

        Une échelle mobile en bas à gauche de l'écran (à côté du bouton
        "Lecture") peut être utilisée pour régler la vitesse du diaporama ou du
        GIF animé, du plus lent au plus rapide. Choisissez le paramètre le plus
        à gauche pour désactiver l'avancement automatique pendant la lecture
        dans Tux Paint - vous devrez appuyer sur une touche ou cliquer pour
        passer à la diapositive suivante (voir ci-dessous).

        💡 Remarque : le paramètre le plus lent ne fait pas automatiquement
        avancer les diapositives. Utilisez-le lorsque vous souhaitez les
        parcourir manuellement. (Cela ne s'applique pas à un GIF animé
        exporté.)



    Lecture dans Tux Paint

        To play a slideshow within Tux Paint, click the 'Play' button.

        💡 Note : si vous n'avez sélectionné aucune image, toutes vos images
        enregistrées seront mises dans le diaporama !)

        Pendant le diaporama, appuyez sur [Espace], [Entrée] ou [Retour] , ou
        sur [Flèche droite] - ou cliquez sur le bouton "Suivant" en bas à
        gauche - pour passer manuellement à la diapositive suivante. Appuyez
        sur [Flèche gauche] pour revenir à la diapositive précédente.

        Appuyez sur [Escape] , ou cliquez sur le bouton "Retour" en bas à
        droite, pour quitter le diaporama et revenir à l'écran de sélection
        d'image du diaporama.



    Exporter un GIF animé

        Cliquez sur le bouton "Exporter GIF" en bas à droite pour que Tux Paint
        génère un fichier GIF animé basé sur les images sélectionnées.

        💡 Note : On doit sélectionner au moins deux images. (Pour exporter une
        seule image, utilisez l'option "Exporter" de la boîte de dialogue
        "Ouvrir".) Si aucune image n'est sélectionnée, Tux Paint n'essaiera PAS
        de générer un GIF basé sur toutes les images enregistrées.

        Appuyer sur [Escape] pendant l'exportation annulera le processus et
        vous ramènera à la boîte de dialogue "Diaporama".




    Cliquez sur "Retour" dans l'écran de sélection d'image du diaporama pour
    revenir à la boîte de dialogue "Ouvrir".



g.Commande "Quitter"

    Cliquez sur le bouton "Quitter", fermez la fenêtre de Tux Paint ou appuyez
    sur la touche [Escape] pour quitter Tux Paint.

    On vous demandera d'abord si vous voulez vraiment arrêter.

    Si vous choisissez de quitter et que vous n'avez pas enregistré l'image
    actuelle, il vous sera d'abord demandé si vous souhaitez l'enregistrer.
    S'il ne s'agit pas d'une nouvelle image, il vous sera alors demandé si vous
    souhaitez écraser l'ancienne version ou créer une nouvelle entrée. (Voir "
    Sauvegarder" aci-dessus.)

    ⚙ Remarque :: Si l'image est enregistrée, elle sera rechargée
    automatiquement la prochaine fois que vous exécuterez Tux Paint -- à moins
    que l'option"startblank" ait été activée.

    ⚙ Remarque :: Le bouton "Quitter" et la touche [Escape] peuvent être
    désactivés par le biais de option "noquit".

    Dans ce cas, le bouton "Fermer la fenêtre" sur la barre de titre de Tux
    Paint (si vous n'êtes pas en mode plein écran) ou la touche [Alt] + [F4]
    peut être utilisée pour quitter.

    Si aucune de ces options n'est possible, la séquence de touches [Shift] +
    [Control / ⌘] + [Escape] peut être utilisée pour quitter.

    ⚙ Voir la documentation sur "Options".



h.Coupure du son

    Il n'y a pas de bouton de commande à l'écran pour le moment, mais en
    appuyant sur les touches [Alt] + [S] , les effets sonores peuvent être
    désactivés et réactivés pendant que le programme est en cours d'exécution.

    Notez que si les sons sont complètement désactivés via l'option "nosound,
    la combinaison des touches [Alt] + [S] n'a pas d'effet (c'est-à-dire qu'il
    ne peut pas être utilisé pour activer les sons lorsque le parent /
    enseignant veut qu'ils soient désactivés.)

    ⚙ Voir la documentation sur "Options".




E. Contrôle de Tux Paint

1. Utiliser une Souris ou une Boule de pointage

Le mode principal de travail pour Tux Paint est avec tout dispositif reconnu
par votre système d'exploitation tel que la souris, soit standard, soit boule
de commande, soit pavé tactile aussi bien tablette graphique (en général avec
un stylet) et les écrans tactiles (opérés soit avec un doigt, soit avec un
stylet) (voir "Utiliser une tablette ou un écran tactile" ci-dessous pour plus
d'information).

Pour dessiner et contrôler Tux Paint, un seul bouton de souris suffit —
typiquement, sur les souris avec plusiers boutons, c'est le bouton gauche, on
peut changer ceci à l'aide du système d'exploitation. Par défaut, Tux Paint
ignore les entrées par les autres boutons. Si un utilisateur essaie d'utiliser
le(s) autre(s) bouton(s), un avertissement apparaîtra lui rappelant que Tux
Paint ne reconnaît qu'un seul bouton. Cependant vous pouvez configurer Tux
Paint pour accepter un autre bouton comme entrée (voir la Options
documentation).

a. Défilement

Beaucoup de dispositifs d'entrée offre un moyen d'effectuer un défilement
rapide — beaucoup de souris ont une roulette de défilement, les boules de
commande ont des anneaux de défilement, et les pavés tactiles reconnaissent des
gestes pour faire défiler (par ex. un mouvement vertical avec deux doigts, ou
un mouvement vertical sur les bords du pavé. Tux Paint support le défilement
avec certaines listes (par ex. les Tampons, les outils 'Magie', les boîtes de
dialogue Nouveau et Ouvrir).

Tux Paint will also automatically scroll if you click and hold the mouse down
on an scroll button — the "up" and "down" arrow buttons that appear above and
below scrolling lists.

b. Accessibilité de la souris

Other devices that appear as a mouse can be used to control Tux Paint. For
example:

  * Head pointing/tracking devices
  * Dispositifs de suivi du regard
  * Souris de pied

Tux Paint offers a "sticky mouse click" accessibility setting, where a single
click begins a click-and-drag operation, and a subsequent click ends it. (See
the Options documentation.)

2. Utiliser une Tablette ou un Écran tactile

As noted above, Tux Paint recognizes any device that appears as a mouse. This
means drawing tablets and touchscreens may be used. However, these devices
often support other features beyond X/Y motion, button clicks, and scroll-wheel
motion. Currently, those additional features are not supported by Tux Paint.
Some examples:

  * Pression et angle
  * Conseil pour la Gomme
  * Gestes avec plusieurs doigts

3. Utiliser un dispositif de type joystick

Tux Paint may be configured to recognize input from any game controller that
appears to your operating system as a joystick. That even includes modern game
console controllers connected via USB or Bluetooth (e.g., Nintendo Switch or
Microsoft Xbox game pads)!

Numerous configuration options are available to best suit the device being
used, and the user's needs. Analog input will be used for coarse movement, and
digital "hat" input for fine movement. Buttons on the controller can be mapped
to different Tux Paint controls (e.g., acting as the [Escape] key, switching to
the Paint tool, invoking Undo and Redo operations, etc.). See the Options
documentation for more details.

4. Utiliser le clavier

Tux Paint offers an option to allow the keyboard to be used to control the
mouse pointer. This includes motion and clicking, as well as shortcuts to
navigate between and within certain parts of the interface. See the Options
documentation for more details.

III. Chargement d'autres images dans Tux Paint

A. Aperçu

Étant donné que la boîte de dialogue «Ouvrir» de Tux Paint n'affiche que les
images que vous avez créées avec Tux Paint, que se passe-t-il si vous souhaitez
charger une autre image ou photo dans Tux Paint pour les éditer et dessiner
par-dessus ?

Pour ce faire, il vous suffit de convertir l'image dans le format utilisé par
Tux Paint, qui est —PNG (Portable Network Graphic), et de la placer dans le
répertoire "saved" de Tux Paint. C'est là où on les trouve (par défaut) :

Windows 10, 8, 7, Vista
    Dans le dossier utilisateurs "AppData", par ex. "C:\Users\nom d'utilisateur
    \AppData\Roaming\TuxPaint\saved\".

Windows 2000, XP
    Dans le dossier utilisateurs "Application Data", par ex. "C:\Documents and
    Settings\nom d'utilisateur\Application Data\TuxPaint\saved\".

macOS
    Dans le dossier utilisateurs "Library", par ex. "/Users/nom d'utilisateur/
    Library/Application Support/Tux Paint/saved/".

Linux/Unix
    Dans un répertoire caché ".tuxpaint" qui est dans le répertoire personnel
    de l'utilisateur ("$HOME"), par ex. "/home/nom d'utilisateur/.tuxpaint/
    saved/".


💡 Remarque : C'est également à partir de ce dossier que vous pouvez copier ou
ouvrir des images dessinées dans Tux Paint à l'aide d'autres applications,
ainsi l'option 'Export' de la boîte de dialogue 'Ouvrir' de Tux Paint peut être
utilisée pour les copier dans un endroit plus facile d'accès plus sûr.

B. Utilisation du script d'importation "tuxpaint-import"

Les utilisateurs Linux et Unix peuvent utiliser script shell "tuxpaint-import"
qui s'installe lorsque vous installez Tux Paint. Il utilise certains outils
NetPBM pour convertir l'image ("anytopnm"), la redimensionner pour qu'elle
tienne dans le canevas de Tux Paint ("pnmscale") et la convertir en PNG
("pnmtopng").

Il utilise également la commande "date" pour obtenir l'heure et la date
actuelles, qui sont la convention de dénomination des fichiers utilisée par Tux
Paint pour les fichiers enregistrés. (N'oubliez pas que vous n'êtes jamais
invité à entrer un "nom de fichier " lorsque vous allez enregistrer ou ouvrir
des images !)

Pour utiliser ce script, exécutez simplement la commande à partir d'une invite
de ligne de commande et indiquez-lui le (s) nom (s) du ou des fichiers que vous
voulez convertir.

Ils seront convertis et placés dans votre répertoite Tux Paint "saved".

💡 Note : si vous faites cela pour un autre utilisateur (par ex. votre enfant)
vous devrez vous assurer d'exécuter la commande sous son compte.)

Exemple :

    $ tuxpaint-import grandma.jpg
    grandma.jpg -> /home/username/.tuxpaint/saved/20211231012359.png
    jpegtopnm: WRITING A PPM FILE

La première ligne ("tuxpaint-import grandma.jpg") est la commande à exécuter.
Les deux lignes suivantes sont les sorties du programme pendant qu'il
fonctionne.

Vous pouvez maintenant charger Tux Paint, et une version de cette image
originale sera disponible dans la boîte de dialogue «Ouvrir». Double-cliquez
simplement sur son icône !

C. Importer des images manuellement

Les utilisateurs de Windows, macOS et Haiku désirant importer des images dans
Tux Paint doivent le faire manuellement.

Chargez un programme graphique capable à la fois de charger votre image et
d'enregistrer un fichier au format PNG. (Voir le fichier de documentation "
PNG.html" pour une liste des logiciels suggérés et d'autres références.)

Lorsque Tux Paint charge une image qui n'a pas la même taille que son canevas
de dessin, il met à l'échelle (et parfois en coloriant les bords) l'image pour
qu'elle tienne dans le canevas.

Pour éviter que l'image ne soit étirée ou maculée, vous pouvez la
redimensionner à la taille de la toile de Tux Paint. Cette taille dépend de la
taille de la fenêtre Tux Paint, ou de la résolution à laquelle Tux Paint est
exécuté, si il est en plein écran. (Remarque : la résolution par défaut est de
800x600.) Voir "Calculer les dimensions des images" ci-dessous.

1. Nom du fichier

Sauvegarder l'image au format PNG. Il est fortement recommandé que vous nommiez
le fichier en utilisant la date et l'heure courante, puisque c'est ce que Tux
Paint utilise :

    YYYYMMDDhhmmss.png

  * YYYY = Year
  * MM = Mois (deux chiffres, "01"-"12")
  * DD = Jour du mois (deux chiffres, "01"-"31")
  * HH = Heure (deux chiffres,au format 24h, "00"-"23")
  * mm = Minute (deux chiffres, "00"-"59")
  * ss = Secondes (deux chiffres, "00"-"59")

Exemple: "20210731110500.png",pour le 31 juillet 2021 à 11:05 du matin.

Mettez cd fichier PNG dans votre répertoire Tux Paint "saved". (Voir ci-dessus)

2. Calculer les dimensions des images

Cette partie de documentation doit être réécrite puisque la nouvelle option
"buttonsize" a été ajoutée. Pour l'heure, essayer de dessiner et de sauvegarder
l'image dans Tux Paint, et ensuite déterminer quelle taille (largeur et hauteur
en pixels) elle possède, et essayez de l'adapter lors de la mise à l'échelle en
l'important dans Tux Paint.

IV.Lectures complémentaires

Les autres documents inclus avec Tux Paint (dans le répertoire "docs") incluent
:

Utiliser Tux Paint :
      + OPTIONS.html
        Instructions détaillées sur les options en ligne de commande et les
        fichiers de configuration, pour ceux qui ne veulent pas utiliser
        l'outil Tux Paint Config.
      + Documentation sur l'outil 'Magie' ("magic-docs")
        Documentation pour chacun des outils "Magic" actuellement installés.


Extensions pour Tux Paint :
      + EXTENDING.html
        Des instructions détaillées sur la création de pinceaux, de tampons,
        d'images de démarrage et de modèles; et l'ajout de polices; et créer un
        nouveau clavier virtuel et des méthodes de saisie.
      + PNG.html
        Remarques sur la création d'images bitmap au format PNG à utiliser dans
        Tux Paint.
      + SVG.html
        Remarques sur la création d'images vectorielles au format SVG à
        utiliser dans Tux Paint.


Information technique :
      + INSTALL.html
        Instructions pour compiler et installer Tux Paint, le cas échéant.
      + SIGNALS.html
        Informations sur les signaux POSIX auxquels répond Tux Paint.
      + MAGIC-API.html
        Creating new Magic tools using Tux Paint's plugin API.


Historique du développement et licence :
      + AUTHORS.txt
        Liste des auteurs et contributeurs.
      + CHANGES.txt
        Résumé des changements entre chaque version de Tux Paint.
      + COPYING.txt
        Licence du programme Tux Paint, la GNU General Public License (GPL)



V.Comment obtenir de l'aide

Si vous avez besoin d'aide, il existe de nombreux moyens d'interagir avec les
développeurs de Tux Paint et les autres utilisateurs :

  * Mentionner des bogues, ou demander de nouvelles fonctionnalités via le
    système de suivi des bogues
  * Participer aux nombreuses listes de diffusion de Tux Paint
  * Contacter les développeurs directement

Pour en savoir plus, visitez la page "Contact" du site officiel de Tux Paint :
https://tuxpaint.org/contact/

VI.Comment participer

Tux Paint est un projet mené par des volontaires, et nous serions heureux
d'accepter votre aide dans des tas de domaines :

  * Traduire Tux Paint dans une autre langue
  * Améliorer les traductions existantes
  * Créer des oeuvres (tampons, images de démarrage, modèles, pinceaux)
  * Ajouter ou améliorer des caractéristiques ou bien des outils "Magie"
  * Créer un programme d'étude en classe
  * Promouvoir ou aider ceux qui utilisent Tux Paint

Pour en savoir plus, visitez la page "Nous aider" du site officiel de Tux Paint
: https://tuxpaint.org/help/

VII.Follow the Tux Paint project on social media

Tux Paint maintains a presence on a variety of social media networks, where we
post updates and artwork.

  * Suivez Tux Paint sur Facebook
  * Suivre @TuxPaintDevs sur Instagram
  * Suivre @tuxpaint@floss.social sur Mastodon
  * Suivre u/TuxPaintDevs sur Reddit
  * Suivre @TuxPaintDevs sur Threads
  * Suivre Tux Paint sur Tumblr
  * Suivre @TuxPaintTweets sur Twitter

VIII. Mentions concernant les marques déposées

  * "Linux" est marque déposée par Linus Torvalds.
  * "Microsoft" et "Windows" sont des marques déposées par Microsoft Corp.
  * "Apple" et "macOS" sont des marques déposées par Apple Inc.
  * "Facebook" et "Instagram" sont des marques déposées par Meta Platforms,
    Inc.
  * "Mastodon" est une marque déposée par Mastodon gGmbH.
  * "Reddit" est une marque déposée par Reddit, Inc.
  * "Tumblr" est une marque déposée par Tumblr, Inc.
  * "Twitter" est une marque déposée par X Corp.

