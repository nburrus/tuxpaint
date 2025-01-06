                                   Tux Paint
                                version 0.9.35

                  ## Un programme simple pour les enfants ##

       Copyright © 2002-2025 by divers contributeurs; voir AUTHORS.txt.
                             https://tuxpaint.org/

                                janvier 6, 2025

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

                    ### A. Qu'est-ce que "Tux Paint" ? ###

Tux Paint est un programme de dessin gratuit conçu pour les jeunes enfants
(enfants de 3 ans et plus). Il possède une interface simple et facile à
utiliser, des effets sonores amusants et une mascotte de dessin animé pour
encourager et guider les enfants lorsqu'ils utilisent le programme. Sont
fournis un canevas vierge et un ensemble d'outils de dessin pour aider votre
enfant à être créatif.

                             ### B. Objectifs ###

→ Facile et amusant ←
    Tux Paint se veut un simple programme de dessin pour les jeunes enfants. Il
    ne s'agit pas d'un programme de dessin à usage général. Il se veut amusant
    et facile à utiliser. Les effets sonores et un personnage de dessin animé
    permettent à l'utilisateur de savoir ce qui se passe tout en le
    divertissant. Il existe également des pointeurs de souris, de style dessin
    animé, extra-larges.
     
→ Flexibilité ←
    Tux Paint est extensible. Les brosses et les formes de "tampon en
    caoutchouc" peuvent être déposées et retirées. Par exemple, un enseignant
    peut apporter une collection de formes animales et demander à ses élèves de
    dessiner un écosystème. Chaque forme peut avoir un son qui l'accompagne et
    un texte est affiché lorsque l'enfant sélectionne la forme.
     
→ Portabilité ←
    Tux Paint est portable sur diverses plates-formes informatiques: Windows,
    Macintosh, Linux, etc. L'interface est la même sur toutes. Tux Paint
    fonctionne correctement sur les systèmes plus anciens (comme un Pentium
    133), et peut être modifié pour mieux fonctionner sur des systèmes lents.
     
→ Simplicité ←
    Il n'y a pas d'accès direct à la complexité sous-jacente de l'ordinateur.
    L'image en cours est conservée lorsque le programme se ferme et réapparaît
    au redémarrage. L'enregistrement d'images ne nécessite pas la création de
    noms de fichiers ou l'utilisation du clavier. L'ouverture d'une image se
    fait en la sélectionnant dans une collection de vignettes. L'accès à
    d'autres fichiers sur l'ordinateur est restreint.
     
→ Accessibilité ←
    Tux Paint offre un grand nombre d'options pour l'accessibilité, comprenant
    l'augmentation de la taille des boutons de contrôle, le changement des
    fontes utilisateur, des options pour contrôler le pointeur de souris en
    utilisant le clavier ou d'autres dispostifs d'entrée (joystick, manette de
    jeu, etc ..), un clavier virtuel, et des clics de souris "collants".
     

                              ### C. Licence ###

Tux Paint est un projet Open Source, un logiciel libre publié sous la licence
publique générale GNU (GPL). Il est gratuit et le «code source» du programme
est disponible. (Cela permet à d'autres d'ajouter des fonctionnalités, de
corriger des bogues et d'utiliser des parties du programme dans leur propre
logiciel sous GPL.)

Voir COPYING.txt pour le texte complet de la licence GPL.

     ### D. Qu'y a-t-il de neuf dans la version 0.9.35 de Tux Paint ? ###

→ Improved color picker ←
    Better behavior when clicking/tapping and dragging hue/saturation box and
    value slider.
     
→ Text clipboard paste support ←
    The "Text" and "Label" tools support pasting the copy/paste clipboard.
     
→ "Hearts" Magic tool ←
    Draw a trail of floating hearts. ←
    → "Sparkles" Magic tool ←
        Draw a trail of falling sparkles. ←
        → "Stars" Magic tool ←
            Draw a trail of stars. ←

        Voir CHANGES.txt pour la liste complète des changements.

        II. Utiliser Tux Paint

                           ### A. Lancement de Tux Paint ###

        ## 1. Utilisateurs de Linux/Unix ##

        Tux Paint devrait avoir mis une icône de lanceur dans vos menus KDE et/
        ou GNOME, sous «Graphiques».

        Autrement, vous pouvez exécuter la commande suivante à une invite du
        shell (par exemple, "$") :

            $ tuxpaint

        Si des erreurs se produisent, elles seront affichées sur le terminal
        ("stderr").

        ## 2. Utilisateurs de Windows ##

        [Icône pour Tux Paint]
              Tux Paint

        Si vous avez installé Tux Paint sur votre ordinateur en utilisant le
        'Tux Paint Installer', il vous aura demandé si vous vouliez un
        raccourci de menu 'Démarrer' et / ou un raccourci sur le bureau. Si
        vous avez accepté, vous pouvez simplement exécuter Tux Paint à partir
        de la section 'Tux Paint' de votre menu 'Démarrer' (par exemple, sous
        «Tous les programmes» sous Windows XP), ou en double-cliquant sur
        l'icône «Tux Paint» sur votre bureau .

        Si vous avez installé Tux Paint en utilisant le téléchargement
        'ZIP-file', ou si vous avez utilisé 'Tux Paint Installer', mais que
        vous avez choisi de ne pas installer de raccourcis, vous devrez
        double-cliquer sur l'icône "tuxpaint.exe" dans le dossier "Tux Paint"
        de votre ordinateur.

        By default, the 'Tux Paint Installer' will put Tux Paint's folder in 
        "C:\Program Files\TuxPaint\", though you may have changed this when you
        ran the installer.

        Si vous avez utilisé le téléchargement de 'ZIP-file', le dossier de Tux
        Paint sera là où vous l'avez placé lorsque vous avez décompressé le
        fichier ZIP.

        ## 3. Utilisateurs de macOS ##

        Double-cliquez simplement sur l'icône "Tux Paint".

        [Écran-titre]
         

                                ### B. Écran titre ###

        Lors du premier chargement de Tux Paint, un écran avec titre et crédits
        apparaîtra.

        Une fois le chargement terminé, appuyez sur une touche ou cliquez sur
        la souris pour continuer. (Ou, après environ 30 secondes, l'écran-titre
        disparaîtra automatiquement.)

                              ### C. Écran principal ###

        L'écran principal est divisé en plusieurs sections :

        [Outils : Peindre, Tampon, Lignes, Formes, Texte, Magie, Étiquette,
        Défaire, Refaire, Gomme, Nouveau, Ouvrir, Sauvegarder, Imprimer,
        Quitter]
         
        → Côté gauche : la barre d'outils ←

            La barre d'outils contient les commandes pour dessiner et éditer.


             
        [Toile]
         
        → Milieu : Toile pour Dessiner ←

            La plus grande partie de l'écran, au centre, est le canevas pour
            dessiner. C'est évidemment là que vous dessinerez !

            💡 Remarque: la taille du canevas de dessin dépend de la taille de
            Tux Paint. Vous pouvez modifier la taille de Tux Paint à l'aide de
            l'outil de configuration tuxpaint-config, ou par d’autres moyens.
            Consultez la documentation OPTIONS pour plus de détails.


             
        [Sélecteurs - Pinceaux, Lettres, Formes, Tampons]
         
        → Côté droit : sélecteur ←

            En fonction de l'outil en cours d'utilisation, le sélecteur affiche
            différentes choses. Par exemple, lorsque l'outil Pinceau est
            sélectionné, il affiche les différents pinceaux disponibles.
            Lorsque l'outil Tampon en caoutchouc est sélectionné, il affiche
            les différentes formes que vous pouvez utiliser.


             
        [Couleurs - Noir, Blanc, Rouge, Rose, Orange, Jaune, Vert, Cyan, Bleu,
        Pourpre, Brun, Gris]
         
        → En bas : couleurs ←

            Quand l'outil en cours utilise des couleurs, une palette pour
            choisir des couleurs se trouve en bas de l'écran. Cliquez sur une
            pour choisir une couleur, et elle sera utilisée par l'outil en
            cours. (Par ex. l'outil "Peindre" utilisera cette couleur pour
            dessiner avec le piceau choisi, et l'outil "Remplir" utilisera
            cette couleur pour remplir une partie du dessin)

            Tout à fait à droite se trouvent trois options spéciales pour les
            couleurs :
              x Sélecteur de couleur
                Le "sélecteur de couleurs" (qui ressemble à un compte-gouttes)
                vous permet de choisir une couleur trouvée dans votre dessin.
                (Un raccourci clavier est disponible pour accéder à cet effet
                rapidement; voir ci-dessous)
              x Palette de l'Arc-en-ciel
                La palette de l'arc-en-ciel vous permet de prendre n'importe
                quelle couleur en choisissant la teinte, la saturation et la
                valeur de la couleur désirée. Une boîte sur le côté gauche
                montre des centaines de teinte &madsh; de rouge en haut
                jusqu'au violet en bas — à des centaines de niveaux de
                saturation/intensité — délavées sur la gauche à pures sur la
                droite. Une barre grise verticale donne accès à des centaines
                de niveaux — du plus clair en haut à plus sombre en bas.
                Cliquez sur le bouton vert pour selectionner la couleur, ou sur
                le bouton "Retour" pour abandonner sans prendre de nouvelle
                couleur.
                Vous pouvez aussi régler la couleur de cet outil avec une autre
                que l'on choisit :
                  % Peu importe la couleur intégrée choisie, si il y an a une
                  % Couleur actuelle du Sélecteur de couleur
                  % Couleur actuelle du mélangeur de couleurs
              x Mélangeur de couleurs
                Le "mélangeur de couleur" (qui ressemble à une palette de
                peintre) vous permet de créer des couleurs en mélangeant des
                couleurs primaires — rouge, jaune et bleu — en même temps que
                du blanc (pour "tinter"), gris (pour "harmoniser") et noir
                (pour "ombrer").
                Vous pouvez cliquer sur un bouton plusieurs fois (par ex. rouge
                + rouge + jaune donne une couleur rouge-orange). Le ratio des
                couleurs ajoutées est montré en bas.
                Vous pouvez revenir en arrière (reset avec aucune couleur dans
                le dessin) en cliquant sur le bouton "Effacer". Vous pouvez
                Défaire et Refaire des étapes de mélange, au cas où vous auriez
                fait une erreur (sans avoir à tout recommencer).
                Cliquez sur le bouton vert pour selectionner la couleur, ou sur
                le bouton "Retour" pour abandonner sans prendre de nouvelle
                couleur.

            ⌨ Quand l'outil qui est actif a besoin de couleurs, un raccourci
            clavier peut être utilisé pour un accès rapide à l'option
            "sélecteur de couleur". Maintenez enfoncée la touche [Control]
            pendant le clic, et la couleur sous le pointeur de souris
            apparaîtra en bas. Vous pouvez vous promener sur le canevas pour
            trouver la couleur qui vous convient. Lorsque vous relâchez le
            bouton de la souris, la couleur qui était sous le pointeur est
            sélectionnée. Si vous relâchez en dehors du canevas (par ex.
            au-dessus de la zone "Outils"), la sélection de la couleur restera
            inchangée. (C'est la même chose qu'en cliquant sur le bouton
            "Annuler" qui est disponible sur l'option "sélecteur de couleur"
            via la palette de couleur).

            ⚙ Note : Vous pouvez définir vos propres couleurs. Voir la
            documentation "Options" .


             
        (Par exemple : Choisis une forme. Clique pour démarrer le dessin , fais
        glisser et continue jusqu'à la taille désirée. Déplace-toi pour la
        faire tourner, et clique pour dessiner.)
         
        → En bas : zone d'aide ←

            Tout en bas de l'écran, Tux, le pingouin Linux, fournit des
            conseils et d'autres informations pendant que vous dessinez.


             
       
                             ### D. Outils disponibles ###

        ## 1. Outils de dessin ##

        a. Outil "Peinture" (pinceau) ←

            L'outil Pinceau vous permet de dessiner à main levée, en utilisant
            différents pinceaux (choisis dans le sélecteur à droite) et
            couleurs (choisis dans la palette de couleurs qui est en bas).

            Si vous maintenez le bouton de la souris enfoncé et déplacez la
            souris, elle dessine au fur et à mesure que vous vous déplacez.

            Certains pinceaux sont animés — ils changent de forme lorsque vous
            dessinez. Un bon exemple est le pinceau 'grappe' livré avec Tux
            Paint. Ces pinceaux ont une icône avec une petite pellicule
            dessinée sur le bouton de sélection.

            D'autres pinceaux sont directionnels — leur forme dépend de la
            direction dans laquelle vous dessinez. Un exemple est le pinceau
            flèche livré avec Tux Paint. Ces pinceaux ont une petite étoile à 8
            branches sur leur icône du bouton de sélection.

            Et enfin, certains pinceaux peuvent être = la fois directionnels et
            animés. Des exemples sont les pinceaux 'chat' et 'écureuil' livrés
            avec Tux Paint. Ces pinceaux ont à la fois une pellicule et une
            étoile à 8 branches sur leur icône.

            Pendant que vous dessinez, un son est joué. Plus la brosse est
            grosse, plus le son est grave.

            Espacement des pinceaux


                L'espace entre chaque position de coup de pinceau peut varier.
                Quelques pinceaux (tels que les empreintes de pas et les
                fleurs) sont espacés, par défaut, de manière suffisamment
                grande pour qu'elles ne se recouvrent pas. D'autres pineaux
                (tels que les circulaires basiques) sont espacés de près et
                font ainsi un coup de pinceau continu.

                L'espacement des coups de pinceau peut être changé en cliquant
                dans l'ensemble de barres (de forme triangulaire) en bas à
                droite; plus la barre est grande, plus l'espacement est grand.
                Le réglage de l'espacement des coups de pinceaux affecte deux
                outils utilisant les pinceaux ! l'outil "Peindre" et l'outil
                "Ligne".

                ⚙ Note: Si l'option "nobrushspacing" est définie, Tux Paint
                n'affichera pas les contrôles d'espacement des coups de
                pinceaux. Voir la documentation "Options".


             
        b.Outil "Tampon" (tampon de caoutchouc) ←

            L'outil Tampon montre un ensemble de tampons en caoutchouc ou
            d'autocollants. Il vous permet de coller des images pré-dessinées
            ou photographiques (comme l'image d'un cheval, d'un arbre ou de la
            lune) dans votre dessin.

            Lorsque vous déplacez la souris sur le canevas, une forme suit la
            souris, indiquant où le tampon sera placé, ainsi que sa taille.
            Cliquez sur le canevas à l'endroit où vous voulez placer le tampon.

            → Catégories de tampons ←
                Il peut y avoir de nombreuses catégories de timbres (par ex.
                animaux, plantes, espace extra-atmosphérique, véhicules,
                personnes, etc.). Utilisez les flèches gauche et droite pour
                parcourir les différentes collections.
                 
            → Rotation des tampons ←

                En utilisant le bouton de rotation en bas à droite, vous pouvez
                effectuer une rotation quand vous placez un tampon. Une fois le
                tampon placé, choisissez l'angle de rotation en bougeant la
                souris. Cliquez une fois de plus et le tampon sera ajouté au
                dessin.

                ⚙ Note : Si l'option de "rotation des tampons" est désactivée,
                le tampon sera mis sur le canevas quand vous relâchez le bouton
                de la souris (Il n'y a pas d'étape de rotation). Voir la
                documentation sur "Options" pour tout savoir sur l'option
                rotation d'un tampon" ("stamprotation").

                📜 Note : La possibilité de rotation des tampons a été
                incorporée dans Tux Paint avec la version 0.9.29.


                 
            → Contrôles des tampons ←

                Avant de `` tamponner '' une image sur votre dessin, différents
                effets peuvent parfois être appliqués (en fonction du tampon) :

                  * Certains tampons peuvent être colorés ou teintés. Si la
                    palette de couleurs sous le canevas est activée, vous
                    pouvez cliquer sur les couleurs pour changer la teinte ou
                    la couleur du tampon avant de le placer dans le dessin.
                  * Les tampons peuvent être rétrécis et agrandis, en cliquant
                    dans l'ensemble de barres (de forme triangulaire) en bas à
                    droite; plus la barre est grande, plus le tampon apparaîtra
                    grand sur votre dessin.
                  * De nombreux tampons peuvent être retournés verticalement ou
                    affichés sous forme d'image miroir à l'aide des boutons de
                    commande en bas à droite.

                ⚙ Note: Si l'option "nostampcontrols" est définie, Tux Paint
                n'affichera pas les commandes Rotation, Miroir, Retourner,
                Réduire et Agrandir pour les tampons. Voir la documentation "
                Options".


                 
            → Effets sonores des tampons ←

                Les tampons peuvent avoir un effet sonore et / ou une
                description orale (parlés). Les boutons en bas à gauche (près
                de Tux, le pingouin Linux) vous permettent de rejouer les
                effets sonores et la description du tampon actuellement
                sélectionné.


                 

             
        c.Outil "Lignes" ←

            Cet outil vous permet de dessiner des lignes droites à l'aide des
            différents pinceaux et couleurs que vous utilisez habituellement.

            Cliquez et maintenez appuyé pour choisir le départ de la ligne.
            Quand vous bouger la souris, un fin 'ruban élastique' montre les
            limites de la future ligne. Tout en bas, vous voyez l'angle de
            cette ligne en degrés. Une ligne qui va vers la droite est à 0°,
            une ligne droit vers le haut est à 90°, une ligne vers la gauche
            180°, une ligne vers le bas 270°, et ainsi de suite.

            Relâchez la souris pour terminer la ligne. On entend alors le son
            "sproing !".

            Certains pinceaux sont animés, et montre un ensemble formes le long
            d'une ligne. D'autres sont directionnels et montre des formes
            différentes suivant l'angle du pinceau. Et enfin certains sont à la
            fois animés et directionnels. Voir "Paint", au-dessus, pour en
            savoir plus.

            Différents pinceaux ont des espacements de coups de pinceaux
            différents, laissant derrière eux soit une série de formes
            individuelles, soit un coup de pinceau continu avec la forme du
            pinceau. L'espacement entre les coups de piceau peut être ajusté.
            Voir la section de l'outil "Peindre" espacement du pinceau,
            ci-dessus pour en savoir plus.


             
        d.Outil "Formes" ←

            Cet outil vous permet de dessiner des formes simples remplies ou
            non remplies.

            Choisissez une forme dans le sélecteur de droite (cercle,
            carré,ovale, etc.).

            Utilisez les options en bas à droite pour choisir le comportement
            de l'outil :

            → Formes à partir du centre ←
                La forme se développe à partir de l'endroit où vous avez cliqué
                initialement et sera centrée autour de cette position.

                📜 C'était le seul comportement de Tux Paint jusqu'à la version
                0.9.24.


                 
            → Formes à partir d'un coin ←
                La forme se développe à partir d'un coin depuis l'endroit où
                vous avez cliqué initialement. Il s'agit de la méthode par
                défaut de la plupart des autres logiciels de dessin
                traditionnels.

                📜 Cette option a été ajoutée en démarrant la version 0.9.25 de
                Tux Paint.


                 

            ⚙ Remarque : si les contrôles de forme sont désactivés (par
            exemple, avec l'option "noshapecontrols"), il n'y aura pas de
            contrôle et la méthode "formes à partir du centre" sera utilisée.

            Dans le dessin, cliquez sur la souris et maintenez-la pour étirer
            la forme à partir de l'endroit où vous avez cliqué. Certaines
            formes peuvent changer de proportion (par exemple, le rectangle et
            l'ovale peuvent être plus larges que hauts ou plus hauts que
            larges), d'autres pas (par exemple, carré et cercle).

            Pour les formes qui peuvent changer de proportions, le ration
            d'aspect se trouve en bas. Par exemple : "1:1" : sera mentionné si
            la forme est carrée; "2:1" si deux fois plus large que haut, ou
            deux fois plus haut que large ...

            Relâchez la souris lorsque vous avez terminé l'étirement.

            → Mode normal ←

                Maintenant vous pouvez bouger la souris autour du canevas pour
                faire tourner la forme. L'angle de rotation est indiqué en bas,
                en degrés (pareil que l'outil "Lignes" décrit ci-dessus).

                Cliquez à nouveau sur le bouton de la souris et la forme sera
                dessinée avec la couleur en cours.


                 
            → Mode de Formes Simples ←
                Si l'option "formes simples" est activée, la forme sera
                dessinée sur le canevas lorsque vous relâcherez le bouton de la
                souris. (Il n'y a pas de rotation.)

                ⚙ Voir la documentation sur "Options" pour tout savoir sur
                l'option formes simples" ("simpleshapes").


                 

             
        e.Outils "Texte" et "Étiquette" ←

            Choisissez une police (parmi les «Lettres» disponibles sur la
            droite) et une couleur (dans la palette de couleurs en bas). Vous
            pouvez aussi appliquer des effets tels que caractère gras et/ou
            italique. Cliquez sur l'écran et un curseur apparaîtra. Tapez un
            texte et il apparaîtra à l'écran. (Vous pouvez changer la police,
            la couleur et le style en entrant le texte, avant de l'appliquer
            sur le canevas).

            Appuyez sur [Entrée] ou [Retour] et le texte sera inclus dans
            l'image et le curseur se déplacera d'une ligne vers le bas.

            Sinon, appuyez sur [Tab] et le texte sera inclus dans l'image, mais
            le curseur se déplacera vers la droite du texte, plutôt que vers le
            bas d'une ligne et vers la gauche. (Cela peut être utile pour créer
            une ligne de texte avec des couleurs, des polices, des styles et
            des tailles variés.)

            Text from the clipboard (copy/paste buffer) can be inserted with
            the "Text" and "Label" tools by pressing the [Control] + [V] key
            combination on a physical keyboard, or clicking the "Paste" button
            in Tux Paint's on-screen keyboard. If the text would exceed the
            right edge of the canvas, it will wrap to a new line of text (going
            back to the previous space or dash ('-') if possible). If the text
            hits the bottom of the canvas, the pasting will abort, truncating
            the text.

            Cliquer ailleurs dans l'image alors que l'entrée de texte est
            toujours active entraîne le déplacement de la ligne de texte
            actuelle vers cet emplacement (et vous pouvez continuer à la
            modifier).

            → "Texte" par rapport à "Étiquette" ←

                L' outil Texte est l'outil de saisie de texte original de Tux
                Paint. Le texte saisi à l'aide de cet outil ne peut pas être
                modifié ou déplacé ultérieurement, car il fait partie du
                dessin. Cependant, comme le texte fait partie de l'image, il
                peut être dessiné ou modifié à l'aide des effets de l'outil
                Magie (par exemple, taché, teinté, gaufré, etc.)

                Lors de l'utilisation de l' outil Étiquette (qui a été ajouté à
                Tux Paint dans la version 0.9.22), le texte `` flotte '' sur
                l'image, et les détails de l'étiquette (le texte, la position
                de l'étiquette, le choix de la police et la couleur ) sont
                stockés séparément. Cela permet à l'étiquette d'être
                repositionnée ou modifiée ultérieurement.

                Pour éditer une étiquette, cliquez sur le bouton de sélection
                d'étiquette. Toutes les étiquettes du dessin apparaîtront en
                surbrillance. Cliquez sur une — ou utilisez la touche [Tab];
                pour aller de l'une à l'autre étiquette, et utilisez les
                touches [Entrée]; ou [Retour]; pour en sélectionner une, et
                vous éditez ainsi l'étiquette. (Utilisez la touche [Retour
                arrière]; pour effacer les caractères, et d'autres touches pour
                ajouter du texte; cliquez sur le canevas pour repositionner
                l'étiquette; cliquez sur la palette pour changer la couleur du
                texte, etc ...)

                Vous pouvez "plaquer" une étiquette sur le canevas, en peignant
                le texte sur le dessin comme si il avait été ajouté avec
                l'outil Texte, puis en cliquant sur le bouton "étiquette".
                (Cette possibilité a été ajoutée dans la version 0.9.28 de Tux
                Paint). Toutes les étiquettes du dessin apparaîtront en
                surbrillance, et vous en sélectionnez une seule comme si vous
                l'éditiez. L'étiquette choisie est enlevée et le texte sera
                ajouté directement sur le canevas.

                ⚙ L' outil Étiquette peut être désactivé (par exemple, en
                sélectionnant "Désactiver l'outil 'Label'" dans Tux Paint
                Config ou bien en exécutant Tux Paint en ligne de commande avec
                l'option "nolabel").

                📜 The ability to paste text from the clipboard was added in Tux
                Paint 0.9.35


                 
            → Saisie de caractères internationaux ←

                Tux Paint permet de saisir des caractères dans différentes
                langues. La plupart des caractères latins ( A - Z , ñ , è ,
                etc...) peuvent être saisis directement. Certaines langues
                exigent que Tux Paint soit commuté dans un mode d'entrée
                alternatif avant la saisie, et certains caractères doivent être
                composés en utilisant plusieurs touches.

                Lorsque les paramètres régionaux de Tux Paint sont définis sur
                l'une des langues fournissant des modes de saisie alternatifs,
                une touche est utilisée pour parcourir le ou les modes soit
                normaux (caractère latin) soit spécifiques aux paramètres
                régionaux.

                Les locales supportées, les méthodes d'entrée disponibles et la
                touche pour basculer de mode sont listées ci-dessous.

                  * Japonais -- Hiragana et Katakana romanisés — touche [Alt]
                    droite ou touche [Alt] gauche
                  * Korean — Hangul 2-Bul — touche [Alt] droite or touche [Alt]
                    gauche
                  * Chinois traditionnel — touche [Alt] droite or touche [Alt]
                    gauche
                  * Thai — touche [Alt] droite

                💡 Note : de nombreuses polices n'incluent pas tous les
                caractères pour toutes les langues, vous devriez donc parfois
                changer de police pour voir les caractères que vous essayez de
                saisir.


                 
            → Clavier virtuel sur écran ←

                An optional on-screen keyboard is available for the Text and
                Label tools, which can provide a variety of layouts and
                character composition (e.g., composing "a" and "e" into "æ").
                Run Tux Paint with the "--onscreen-keyboard" option, or enable
                that setting in Tux Paint's configuration file, to enable it.
                Multiple layouts are offered (currently "QWERTY" and "ABC"),
                which the user can switch between. Additional configuration
                options allow specifying a default layout, as well as
                preventing the layout from being changed.

                The on-screen keyboard appears at the bottom or top of the Tux
                Paint window, obscuring part of the canvas, depending on where
                the text insertion cursor is placed. Along with alphabetic,
                numeric, and some punctuation keys, the keyboard provides:
                  * A "Backspace" key (⇐) to remove the previous character
                  * A "Carriage Return" ("Return"/"Enter") key (⏎) to end the
                    current input and begin a new one on the following line
                    (below and to the left)
                  * A "Tab" key (⇔) to end the current input and begin a new
                    one at the current cursor position
                  * A "Shift" key (⇑) to shift alphabetic keys from lowercase
                    to uppercase, access more punctuation, etc.
                  * A "Caps Lock" key (⤒) to toggle permanent shifting of
                    alphabetic keys from lowercase to uppercase (click it again
                    to disable caps lock)
                  * A "Compose" key ("Cmp"), to initiate character composition
                    (e.g., click "Cmp", "a", "e" to produce an "æ" character)
                  * An "Alternate Graphics" key ("AltGr") to access additional
                    characters (e.g., "¿", "ß", etc.)
                  * An "Alternate" key ("Alt")
                  * A "Paste" key to paste the current clipboard's text into
                    the Text or Label tool
                  * Left and right arrows (← & →) to access different on-screen
                    keyboard layouts

                ⚙ Voir les documents "Options" et "Extension de Tux Paint" pour
                plus d'informations.


                 

             
        f.Outil "Remplir" ←

            L'outil «Remplir» «remplit» une zone contiguë de votre dessin avec
            une couleur unie de votre choix. Trois options de remplissage sont
            offertes :
              x Uni — cliquez une fois pour remplir une zone avec une couleur
                unie.
              x Pinceau — cliquez et glissez pour remplir une zone avec une
                couleur unie, lorsque l'on fait de la peinture à main levée.
              x Linéaire—cliquez et faites glisser pour remplir une zone avec
                une couleur qui s'atténue au fur et à mesure dans la direction
                où vous déplacez la souris.
              x Radial—cliquez une fois pour remplir une zone avec une couleur
                qui s'atténue graduellement, à partir de l'endroit où vous avez
                cliqué.
              x Radial—cliquez une fois pour remplir une zone avec une couleur
                qui s'atténue graduellement, à partir de l'endroit où vous avez
                cliqué.
              x Eraser — click once to erase an area, exposing the solid color
                background, or starter or template background image, upon which
                the drawing was based. (See Outils disponibles > Outils de
                dessin > Outil "Gomme" and Autres contrôles > Images de
                "Démarrage" et images "Modèle".)

            📜 Note : Avant Tux Paint 0.9.24, "Remplir" était un outil "magique"
            (voir ci-dessous). Avant Tux Paint 0.9.26, l'outil "Remplir"
            n'offrait que la méthode 'Uni' pour le remplissage. Le remplissage
            4radial' a été introduit dans la version 0.9.29 de Tux Paint.


             
        g.Outil "Magie" (Effets spéciaux) ←

            L'outil «Magie» est en fait un ensemble d'outils spéciaux.
            Sélectionnez l'un des effets «magiques» dans le sélecteur de
            droite. Ensuite, selon l'outil, vous pouvez soit cliquer et faire
            glisser dans l'image, et / ou simplement cliquer une fois sur
            l'image pour appliquer l'effet.

            The Magic Tools


                Voir les instructions pour chaque outil 'Magie' (dans le
                dossier 'magic-docs').

            Contrôles des outils Magie


                Si l'outil peut être utilisé en cliquant et en faisant glisser,
                un bouton «peinture» sera disponible sur la gauche, sous la
                liste des outils «magiques» sur le côté droit de l'écran. Si
                l'outil peut affecter l'image en entier, un bouton «Image
                entière» sera disponible sur la droite.

                ⚙ Note: Si l'option "nomagiccontrols" est définie, Tux Paint
                n'affichera pas les contrôles pour peindre. Voir la
                documentation de "Options" .

                💡 Si les contrôles de 'Magie' sont désactivés, le plugin
                'Magie' peut rendre des outils disponibles séparément, un pour
                peindre et l'autre affectant l'image entière.

            Dimensionnement magique


                Quelques outils offrent des options de dimensionnement. Si
                c'est le cas, un message apparaît en bas à droite de l'écran.
                Cela peut affecter la dimension d'un effet spécial (par ex.
                Assombrir) ou un objet peint (par ex.des Motifs) ou d'autres
                attributs (par ex. des formes de brique petites plutôt que
                grandes).

                ⚙ Note : Si l'option "nomagicsizes" est définie, Tux Paint
                n'affichera pas les contrôles de dimension. Voir la
                documentations sur "Options" .

                💡 Si l'option de dimensionnement est désactivée, le plugin
                Magie peut offrir simplement une taille par défaut (par ex.
                pour les Motifs), ou bien il peut faire des outils séparés avec
                des tailles prédéfinies (par ex. Briques et Yeux Écarquillés).

                📜 Cette option a été ajoutée en démarrant la version 0.9.30 de
                Tux Paint.

            ⚙ Note: If the "ungroupmagictools" option is set, Tux Paint won't
            split Magic tools into groups of related tools, and instead present
            them all as one large list. See the "Options" documentation.


             
        h.Outil "Gomme" ←

            This tool works similarly to the Paint Brush. Wherever you click
            (or click and drag), things you've added to your drawing will be
            erased, exposing the background that you chose when you started the
            drawing, be it a solid color, the background of a 'Starter' image,
            or a 'Template' image. (See Outils disponibles > Autres contrôles >
            Commande "Nouveau".)

            A number of eraser types are available, each offering multiple
            sizes are available:
              x Square — Square-shaped erasers that completely remove parts of
                your drawing.
              x Circle (solid) — Circle-shaped erasers that completely remove
                parts of your drawing.
              x Fuzzy-edged Circle — Circle-shaped erasers with soft edges that
                blend with the background.
              x Transparent Circle — Circle-shaped erasers that blend your
                drawing with the background. Release and click again to expose
                more and more of the background.

            As you move the mouse around, an outline follows the pointer,
            showing what part of the picture will be erased.

            Au fur et à mesure que vous effacez, un grincement est émis.

            ⌨ Tenez la touche [X] enfoncée en cliquant pour un accès rapide à
            une petite gomme ronde (non effectif avec les outils Texte et
            Étiquette, quand vous faites tourner un tampon ou une forme, ou
            bien quand vous utilisez un outil magique interactif). Relâchez la
            souris pour revenir à l'outil sélectionné.


             
       
        ## 2. Autres contrôles ##

        a.Commandes "Défaire" et "Refaire" ←

            Cliquer sur le bouton "Défaire" annulera la dernière action. Vous
            pouvez même annuler plus d'une fois !

            ⌨ Remarque : vous pouvez également appuyer [Control / ⌘] + [Z] sur
            le clavier pour Défaire.

            Cliquer sur le bouton "Refaire" annulera l'action que vous venez
            juste faire avec le bouton «Défaire».

            Tant que vous ne dessinez plus, vous pouvez refaire autant de fois
            que vous avez défait !

            ⌨ Remarque : vous pouvez également appuyer [Control / ⌘] + [R] sur
            le clavier pour Refaire.


             
        b.Commande "Nouveau" ←

            Clicking the 'New' button will start a new drawing. A dialog will
            appear where you may choose to start a new picture using a solid
            background color, or using a 'Starter' or 'Template' image (see
            below). You will first be asked whether you really want to do this.

            When you use the 'Eraser' tool things you've added to your drawing
            will be removed, exposing the background you chose when starting a
            new drawing. (See Outils disponibles > Outils de dessin > Outil
            "Gomme".)

            ⌨ Remarque : vous pouvez également appuyer [Control / ⌘] + [N] sur
            le clavier pour commencer un nouveau dessin.

            → Choix de couleurs unies en arrière plan ←
                Along with the preset solid colors, you can also choose colors
                using a rainbow palette or a "color mixer". These operate
                identically to the options found in the color palette shown
                below the canvas when drawing a picture. See Écran principal >
                En bas : couleurs > Special color options for details.
                 
            Images de "Démarrage" et images "Modèle" ←
                  * Les "Images de démarrage" se comportent comme une page d'un
                    livre de coloriage - un contour noir et blanc d'une image,
                    que vous pouvez ensuite colorier, et le contour noir reste
                    intact - ou comme une photographie 3D, où vous dessinez
                    entre une couche de premier plan et une d'arrière-plan.
                  * Les "Images modèle" sont semblables, mais fournissent
                    simplement un dessin d'arrière-plan sur lequel travailler.
                    Contrairement aux «Images de démarrage», rien de ce que
                    vous dessinerez ne restera au premier plan.

                When using the 'Eraser' tool or the 'Eraser' mode of the 'Fill'
                tool, the original image from the 'Starter' or 'Template' will
                reappear. (See Outils disponibles > Outils de dessin > Outil
                "Gomme" and Outil "Remplir".)

                The 'Flip' and 'Mirror' Magic tools affect the orientation of
                the 'Starter' or 'Template', as well. (See Outils disponibles >
                Outil "Magie" (Effets spéciaux) > Renverser and Miroir.)

                Lorsque vous chargez une 'Image modèle' ou 'image modèle',
                dessinez dessus, puis cliquez sur 'Sauvegarder', cela crée un
                nouveau fichier image - il n'écrase pas l'original, vous pouvez
                donc l'utiliser à nouveau plus tard (en y accédant depuis la
                boîte de dialogue 'Nouveau').

                ⚙ Vous pouvez vos propres "Images de démarrage" et Modèles
                d'Image. Voir la section de la documentation concernant les
                Extensions pour Tux Paint , avec 'Images de démarrages' et
                Images Modèles.

                💡 Vous pouvez aussi convertir vos dessins sauvegardés en
                Modèles directement dans Tux Paint à partir de la boîte de
                dialogue 'Ouvrir'. Voir "Ouvrir", ci-dessous.


                 
            → Effacement des images Modèles exportées ←

                Si vous avez sélectionner une Image Modèle dans votre
                répertoire personnel, et qu'il a été créé à partir de Tux Paint
                (en utilisant le bouton "Modèles" la boîte de dialogue "Ouvrir"
                , vous pouvez l'enlever à partir de Tux Paint également. Un
                bouton 'Effacer' (Corbeille) apparaît en bas à droite de la
                liste. Cliquez pour effacer l'image sélectionnée. (On vous
                demandera de confirmer.)

                💡 Note : Pour Linux, Windows, et macOS , l'image sera placée
                dans la corbeille de votre bureau (où vous pourrez le restaurer
                si vous changez d'avis).

                ⚙ Note :: Le bouton 'Effacer' peut être désactivé via l'option
                "noerase".


                 

            ⚙ Note : Les couleurs unies peuvent être placées à la fin de la
            boîte de dialogue 'Nouveau' (dessous les Images de démarrage et
            Modèles), via l'option "newcolorslast".


             
        c.Commande "Ouvrir" ←

            Cela vous montre une liste de toutes les images que vous avez
            enregistrées. S'il y en a plus que ce que peut contenir l'écran,
            utilisez les flèches «Haut» et «Bas» en haut et en bas de la liste
            pour faire défiler la liste des images.

            Cliquez sur une image pour la sélectionner, puis ...
              x Cliquez sur le bouton vert "Ouvrir" en bas à gauche de la liste
                pour charger l'image sélectionnée. Vous pourrez alors l'éditer.

                (Vous pouvez également double-cliquer sur l'icône d'une image
                pour la charger.)

                💡 Si vous choisissez d'ouvrir une image et que votre dessin en
                cours n'a pas été enregistré, il vous sera demandé si vous
                souhaitez l'enregistrer ou non. (Voir "Sauvegarder,"
                ci-dessous.)

              x Cliquez sur le bouton marron "Effacer" (poubelle) en bas à
                droite de la liste pour effacer l'image sélectionnée. (Il vous
                sera demandé de confirmer.)

                📜 Note : Pour Linux (à partir de la version 0.9.22), Windows (à
                partir de la vaersion 0.9.27), et macOS (à partir de la version
                0.9.29), l'image sera placée dans la corbeille de votre bureau
                (où vous pourrez le restaurer si vous changez d'avis).

                ⚙ Note :: Le bouton 'Effacer' peut être désactivé via l'option
                "noerase".

              x Cliquez sur le bouton 'Exporter' près du coin inférieur droit
                pour exporter l'image vers votre dossier d'exportation. (par
                ex. "~/Pictures/TuxPaint/")

            Depuis l'écran "Ouvrir" vous pouvez aussi :
              x Cliquez sur le bouton bleu "Diapositives" (projecteur de
                diapositives) en bas à gauche pour passer en mode diaporama.
                Voir "Diaporama", ci-dessous, pour les détails.

              x Cliquez sur le bouton bleu 'Modèle' en bas à gauche pour
                convertir l'image sélectionnée en nouveau Modèle, qui pourra
                vous servir de base pour de nouveaux dessins.

                📜 Note : La possibilité de création de Modèles a été ajouté
                avec la version 0.9.31 de Tux Paint. Pour savoir comment créer
                des Modèles hors de Tux Paint, voyez Extensions pour Tux Paint

                ⚙ La possibilité de création de Modèle peut être désactivée
                (par ex. en choisissant "Désactiver 'Fabriquer un Modèle' dans
                Tux Paint Config. ou en lançant em>Tux Paint avec l'option
                "notemplateexport").

              x Ou cliquez sur le bouton fléché rouge «Retour» en bas à droite
                de la liste pour annuler et revenir à l'image que vous étiez en
                train de dessiner.

            ⌨ Remarque : vous pouvez également appuyer [Control / ⌘] + [O] sur
            le clavier pour afficher la boîte de dialogue "Ouvrir".


             
        d.Commande "Sauvegarder" ←

            Pour sauvegarder votre image en cours.

            Si vous ne l'avez pas enregistré auparavant, il créera une nouvelle
            entrée dans la liste des images enregistrées. (c'est-à-dire qu'il
            créera un nouveau fichier)

            💡 Remarque : il ne vous demandera rien (par exemple, un nom de
            fichier). Il enregistrera simplement l'image et fera le bruit d'un
            obturateur d'appareil photographique.

            Si vous avez déjà enregistré l'image, ou s'il s'agit d'une image
            que vous venez de charger à l'aide de la commande "Ouvrir", il vous
            sera d'abord demandé si vous voulez écraser l'ancienne version ou
            bien créer une nouvelle entrée (un nouveau fichier).

            ⚙ Remarque : si les options " saveover" ou " saveovernew" sont déjà
            définies, il ne sera rien demandé avant de sauvegarder. Voir la
            documentation Options.

            ⌨ Remarque : vous pouvez également appuyer [Control / ⌘] + [S] sur
            le clavier pour sauvegarde.


             
        e.Commande "Imprimer" ←

            Cliquez sur ce bouton et votre image sera imprimée !

            Sur la plupart des plates-formes, vous pouvez également maintenir
            la touche [Alt] (appelée [Option] sur Mac) tout en cliquant sur le
            bouton «Imprimer» pour obtenir une boîte de dialogue d'impression.
            Notez que cela pourrait ne pas fonctionner si vous exécutez Tux
            Paint en mode plein écran. Voir ci-dessous.

            → Désactivation de l'impression ←

                On peut définir une option "noprint", ce qui entraînera la
                désactivation du bouton "Imprimer".

                ⚙ Voir la documentation sur "Options".


                 
            → Restreindre l'impression ←

                Si l'option "printdelay" a été utilisée, vous ne pouvez
                imprimer — qu'une fois toutes les x secondes, tel que vous
                l'avez défini.

                Par exemple, avec "printdelay=60" dans le fichier de
                configuration de Tux Paint, vous ne pouvez imprimer qu'une fois
                par minute.

                ⚙ Voir la documentation sur "Options".


                 
            → Commandes d'impression ←

                (Linux et Unix uniquement)

                Tux Paint imprime en générant une représentation PostScript du
                dessin et en l'envoyant à un programme externe. Par défaut, le
                programme est :

                    lpr

                Cette commande peut être modifiée en définissant la valeur
                "printcommand" dans le fichier de configuration de Tux Paint.

                Si la touche "[Alt]" du clavier est enfoncée tout en cliquant
                sur le bouton «Imprimer», et tant que vous n'êtes pas en mode
                plein écran, un programme alternatif est exécuté. Par défaut,
                le programme est la boîte de dialogue d'impression graphique de
                KDE :

                    kprinter

                Cette commande peut être modifiée en définissant la valeur
                "altprintcommand" dans le fichier de configuration de Tux
                Paint.

                ⚙ Voir la documentation sur "Options".


                 
            → Réglages pour l'impression ←

                (Windows et macOS)

                Par défaut, Tux Paint imprime simplement sur l'imprimante par
                défaut avec les paramètres par défaut lorsque le bouton
                «Imprimer» est enfoncé.

                Cependant, si vous maintenez la touche [Alt] (ou [Option]) du
                clavier tout en appuyant sur le bouton "Imprimer, et ceci tant
                que vous n'êtes pas en mode plein écran, la boîte de dialogue
                de l'imprimante de votre système d'exploitation apparaît, et
                vous pouvez modifier les réglages.

                Vous pouvez stocker les changements de configuration, entre les
                sessions de Tux Paint, en paramétrant l'option "printcfg".

                Si l'option "printcfg" est utilisée, les réglages d'impression
                seront chargés à partir du fichier "printcfg.cfg" de votre
                répertoire personnel (voir ci-dessous). Tout changement y sera
                ernregistré.

                ⚙ Voir la documentation sur "Options".


                 
            → Options de la boîte de dialogue de l'imprimante ←

                Par défaut, Tux Paint affiche uniquement la boîte de dialogue
                de l'imprimante (ou, sous Linux / Unix, exécute
                "altprintcommand", par exemple, "kprinter" au lieu de "lpr") si
                la touche [Alt] (ou [Option] ) est maintenue pendant en
                cliquant sur le bouton «Imprimer».

                Cependant, ce comportement peut être modifié. Vous pouvez
                toujours faire apparaître la boîte de dialogue de l'imprimante
                en utilisant "--altprintalways" sur la ligne de commande ou
                "altprint=always" dans le fichier de configuration de Tux
                Paint. Inversement vous pouvez empêcher la touche [Alt] /
                [Option] d'avoir un effet en utilisant "--altprintnever" ou
                "altprint=never".

                ⚙ Voir la documentation sur "Options".


                 

             
        f.Commande "Diapos" (sous "Ouvrir") ←

            Le bouton "Diapositives" est disponible dans la boîte de dialogue
            "Ouvrir". Il peut être utilisé pour lire une simple animation dans
            Tux Paint, ou un diaporama. Il peut également exporter un GIF animé
            basé sur les images choisies.

            → Choisir des images ←

                Lorsque vous entrez dans la section "Diapos" de Tux Paint, il
                affiche une liste de vos fichiers enregistrés, tout comme la
                boîte de dialogue "Ouvrir".

                Cliquez sur chacune des images que vous souhaitez afficher dans
                une présentation de style diaporama, une par une. Un chiffre
                apparaîtra sur chaque image, vous indiquant dans quel ordre
                elles seront affichées.

                Vous pouvez cliquer sur une image sélectionnée pour la
                désélectionner (la retirer de votre diaporama). Cliquez à
                nouveau dessus si vous souhaitez l'ajouter à la fin de la
                liste.


                 
            → Régler la vitesse de lecture ←

                Une échelle mobile en bas à gauche de l'écran (à côté du bouton
                "Lecture") peut être utilisée pour régler la vitesse du
                diaporama ou du GIF animé, du plus lent au plus rapide.
                Choisissez le paramètre le plus à gauche pour désactiver
                l'avancement automatique pendant la lecture dans Tux Paint -
                vous devrez appuyer sur une touche ou cliquer pour passer à la
                diapositive suivante (voir ci-dessous).

                💡 Remarque : le paramètre le plus lent ne fait pas
                automatiquement avancer les diapositives. Utilisez-le lorsque
                vous souhaitez les parcourir manuellement. (Cela ne s'applique
                pas à un GIF animé exporté.)


                 
            → Lecture dans Tux Paint ←

                Pour démarrer un diaporama dans Tux Paint, cliquez sur le
                bouton 'Jouer'.

                💡 Note : si vous n'avez sélectionné aucune image, toutes vos
                images enregistrées seront mises dans le diaporama !)

                Pendant le diaporama, appuyez sur [Espace], [Entrée] ou
                [Retour] , ou sur [Flèche droite] - ou cliquez sur le bouton
                "Suivant" en bas à gauche - pour passer manuellement à la
                diapositive suivante. Appuyez sur [Flèche gauche] pour revenir
                à la diapositive précédente.

                Appuyez sur [Escape] , ou cliquez sur le bouton "Retour" en bas
                à droite, pour quitter le diaporama et revenir à l'écran de
                sélection d'image du diaporama.


                 
            → Exporter un GIF animé ←

                Cliquez sur le bouton "Exporter GIF" en bas à droite pour que
                Tux Paint génère un fichier GIF animé basé sur les images
                sélectionnées.

                💡 Note : On doit sélectionner au moins deux images. (Pour
                exporter une seule image, utilisez l'option "Exporter" de la
                boîte de dialogue "Ouvrir".) Si aucune image n'est
                sélectionnée, Tux Paint n'essaiera PAS de générer un GIF basé
                sur toutes les images enregistrées.

                Appuyer sur [Escape] pendant l'exportation annulera le
                processus et vous ramènera à la boîte de dialogue "Diaporama".


                 

            Cliquez sur "Retour" dans l'écran de sélection d'image du diaporama
            pour revenir à la boîte de dialogue "Ouvrir".


             
        g.Commande "Quitter" ←

            Cliquez sur le bouton "Quitter", fermez la fenêtre de Tux Paint ou
            appuyez sur la touche [Escape] pour quitter Tux Paint.

            On vous demandera d'abord si vous voulez vraiment arrêter.

            Si vous choisissez de quitter et que vous n'avez pas enregistré
            l'image actuelle, il vous sera d'abord demandé si vous souhaitez
            l'enregistrer. S'il ne s'agit pas d'une nouvelle image, il vous
            sera alors demandé si vous souhaitez écraser l'ancienne version ou
            créer une nouvelle entrée. (Voir "Sauvegarder" aci-dessus.)

            ⚙ Remarque :: Si l'image est enregistrée, elle sera rechargée
            automatiquement la prochaine fois que vous exécuterez Tux Paint --
            à moins que l'option"startblank" ait été activée.

            ⚙ Remarque :: Le bouton "Quitter" et la touche [Escape] peuvent
            être désactivés par le biais de option "noquit".

            Dans ce cas, le bouton "Fermer la fenêtre" sur la barre de titre de
            Tux Paint (si vous n'êtes pas en mode plein écran) ou la touche
            [Alt] + [F4] peut être utilisée pour quitter.

            Si aucune de ces options n'est possible, la séquence de touches
            [Shift] + [Control / ⌘] + [Escape] peut être utilisée pour quitter.

            ⚙ Voir la documentation sur "Options".


             
        h.Coupure du son ←

            Il n'y a pas de bouton de commande à l'écran pour le moment, mais
            en appuyant sur les touches [Alt] + [S] , les effets sonores
            peuvent être désactivés et réactivés pendant que le programme est
            en cours d'exécution.

            Notez que si les sons sont complètement désactivés via l'option
            "nosound, la combinaison des touches [Alt] + [S] n'a pas d'effet
            (c'est-à-dire qu'il ne peut pas être utilisé pour activer les sons
            lorsque le parent / enseignant veut qu'ils soient désactivés.)

            ⚙ Voir la documentation sur "Options".


             
       
                           ### E. Contrôle de Tux Paint ###

        ## 1. Utiliser une Souris ou une Boule de pointage ##

        Le mode principal de travail pour Tux Paint est avec tout dispositif
        reconnu par votre système d'exploitation tel que la souris, soit
        standard, soit boule de commande, soit pavé tactile aussi bien tablette
        graphique (en général avec un stylet) et les écrans tactiles (opérés
        soit avec un doigt, soit avec un stylet) (voir "Utiliser une tablette
        ou un écran tactile" ci-dessous pour plus d'information).

        Pour dessiner et contrôler Tux Paint, un seul bouton de souris suffit —
        typiquement, sur les souris avec plusiers boutons, c'est le bouton
        gauche, on peut changer ceci à l'aide du système d'exploitation. Par
        défaut, Tux Paint ignore les entrées par les autres boutons. Si un
        utilisateur essaie d'utiliser le(s) autre(s) bouton(s), un
        avertissement apparaîtra lui rappelant que Tux Paint ne reconnaît qu'un
        seul bouton. Cependant vous pouvez configurer Tux Paint pour accepter
        un autre bouton comme entrée (voir la Options documentation).

        # a. Défilement #

        Beaucoup de dispositifs d'entrée offre un moyen d'effectuer un
        défilement rapide — beaucoup de souris ont une roulette de défilement,
        les boules de commande ont des anneaux de défilement, et les pavés
        tactiles reconnaissent des gestes pour faire défiler (par ex. un
        mouvement vertical avec deux doigts, ou un mouvement vertical sur les
        bords du pavé. Tux Paint support le défilement avec certaines listes
        (par ex. les Tampons, les outils 'Magie', les boîtes de dialogue
        Nouveau et Ouvrir).

        Vous pouvez avoir un défilement automatique en cliquant et en
        maintenant enfoncé sur un bouton de défilement — les flèches "haut" et
        "bas" apparaissant au-dessus et en-dessous de la liste.

        # b. Accessibilité de la souris #

        Yous dispositf ressemblant à une souris peut être utilisé pour
        contrôler Tux Paint. Par exemple :
          - Dispositifs de pointage/suivi avec la tête
          - Dispositifs de suivi du regard
          - Souris de pied

        Tux Paint possède un réglage d'accessibilité "clic collant", où un
        simple clic permet de faire "cliquer et glisser", et autre clic
        l'arrête. ( (Voir la Options documentation.)

        ## 2. Utiliser une Tablette ou un Écran tactile ##

        Comme indiqué précédemment, Tux Paint reconnaît tout dispositif
        ressemblant à une souris. Ce qui veut dire que les tablettes graphiques
        et les écrans tactiles sont utilisables. Cependant ces dispositifs
        offrent aussi d'autres fonctionnalités que les mouvements X/Y, les
        clics et la roulette de défilement. Aujourd'hui, ces fonctionnalités
        additionnelles ne sont pas supportées par Tux Paint. Quelques examples
        :
          - Pression et angle
          - Conseil pour la Gomme
          - Gestes avec plusieurs doigts

        ## 3. Utiliser un dispositif de type joystick ##

        Tux Paint peut être configuré pour reconnaître l'entrée de tout
        contrôleur de jeu qui apparaît dans votre système dexploitation tel
        qu'un joystick. Ceci comprend même les consomes modernes connectées par
        USB ou Bluetooth (par ex. les manettes de jeu Nintendo Switch ou
        Microsoft Xbox) !

        Beaucoup d'options de configuration existent pour s'adapter au mieux
        aux dispositifs utilisés, et aux besoins de l'utilisateur. Une entrée
        analogique sera utilisée pour des mouvements grossiers, et un
        dispositif digital pour les mouvements fins. Les boutons du contrôleurs
        peuvent être adaptés pour différents contrôles de Tux Paint (par ex.
        pour actionner la touche [Escape], pour invoquer les opérations Faire
        et Défaire, etc ...). Voir la documentation pour plus de détails
        Options .

        ## 4. Utiliser le clavier ##

        Tux Paint fournit une option pour permettre d'utiliser le clavier pour
        contrôler le pointeur de souris. Cela inclut le mouvement et le clic,
        aussi bien que les raccourcis pour naviguer entre et à l'intérieur de
        certaines parties de l'interface. Voir la documentation pour plus de
        détails Options.

        III. Chargement d'autres images dans Tux Paint

                                   ### A. Aperçu ###

        Étant donné que la boîte de dialogue «Ouvrir» de Tux Paint n'affiche
        que les images que vous avez créées avec Tux Paint, que se passe-t-il
        si vous souhaitez charger une autre image ou photo dans Tux Paint pour
        les éditer et dessiner par-dessus ?

        Pour ce faire, il vous suffit de convertir l'image dans le format
        utilisé par Tux Paint, qui est —PNG (Portable Network Graphic), et de
        la placer dans le répertoire "saved" de Tux Paint. C'est là où on les
        trouve (par défaut) :

        → Windows Windows 7, Windows 8, Windows 10, Windows 11 ←
            In the user's "AppData" folder:
            e.g., "C:\Users\nom d'utilisateur\AppData\Roaming\TuxPaint\saved\"
             
        → macOS ←
            In the user's "Application Support" folder:
            e.g., 
            "/Users/nom d'utilisateur/Library/Application Support/TuxPaint/saved/"
             
        → Linux / Unix ←
            In the user's "home directory" folder:
            e.g., "/home/nom d'utilisateur/.tuxpaint/saved/"
             
        → Haiku ←
            In the user's "settings" folder:
            e.g., "/boot/home/config/settings/TuxPaint/saved/"
             

        💡 Remarque : C'est également à partir de ce dossier que vous pouvez
        copier ou ouvrir des images dessinées dans Tux Paint à l'aide d'autres
        applications, ainsi l'option 'Export' de la boîte de dialogue 'Ouvrir'
        de Tux Paint peut être utilisée pour les copier dans un endroit plus
        facile d'accès plus sûr.

           ### B. Utilisation du script d'importation "tuxpaint-import" ###

        Les utilisateurs Linux et Unix peuvent utiliser script shell
        "tuxpaint-import" qui s'installe lorsque vous installez Tux Paint. Il
        utilise certains outils NetPBM pour convertir l'image ("anytopnm"), la
        redimensionner pour qu'elle tienne dans le canevas de Tux Paint
        ("pnmscale") et la convertir en PNG ("pnmtopng").

        Il utilise également la commande "date" pour obtenir l'heure et la date
        actuelles, qui sont la convention de dénomination des fichiers utilisée
        par Tux Paint pour les fichiers enregistrés. (N'oubliez pas que vous
        n'êtes jamais invité à entrer un "nom de fichier " lorsque vous allez
        enregistrer ou ouvrir des images !)

        Pour utiliser ce script, exécutez simplement la commande à partir d'une
        invite de ligne de commande et indiquez-lui le (s) nom (s) du ou des
        fichiers que vous voulez convertir.

        Ils seront convertis et placés dans votre répertoite Tux Paint "saved".

        💡 Note : si vous faites cela pour un autre utilisateur (par ex. votre
        enfant) vous devrez vous assurer d'exécuter la commande sous son
        compte.)

        Exemple :

            $ tuxpaint-import grandma.jpg
            grandma.jpg -> /home/username/.tuxpaint/saved/20211231012359.png
            jpegtopnm: WRITING A PPM FILE

        La première ligne ("tuxpaint-import grandma.jpg") est la commande à
        exécuter. Les deux lignes suivantes sont les sorties du programme
        pendant qu'il fonctionne.

        Vous pouvez maintenant charger Tux Paint, et une version de cette image
        originale sera disponible dans la boîte de dialogue «Ouvrir».
        Double-cliquez simplement sur son icône !

                      ### C. Importer des images manuellement ###

        Les utilisateurs de Windows, macOS et Haiku désirant importer des
        images dans Tux Paint doivent le faire manuellement.

        Chargez un programme graphique capable à la fois de charger votre image
        et d'enregistrer un fichier au format PNG. (Voir le fichier de
        documentation "PNG.html" pour une liste des logiciels suggérés et
        d'autres références.)

        Lorsque Tux Paint charge une image qui n'a pas la même taille que son
        canevas de dessin, il met à l'échelle (et parfois en coloriant les
        bords) l'image pour qu'elle tienne dans le canevas.

        Pour éviter que l'image ne soit étirée ou maculée, vous pouvez la
        redimensionner à la taille du canevas de Tux Paint. Cette taille dépend
        de la taille de la fenêtre Tux Paint, ou de la résolution à laquelle
        Tux Paint est exécuté, si il est en plein écran. (Remarque : la
        résolution par défaut est de 800x600.) Voir "Calculer les dimensions
        des images" ci-dessous.

        ## 1. Nom du fichier ##

        Sauvegarder l'image au format PNG. Il est fortement recommandé que vous
        nommiez le fichier en utilisant la date et l'heure courante, puisque
        c'est ce que Tux Paint utilise :

            YYYYMMDDhhmmss.png

          - YYYY = Year
          - MM = Mois (deux chiffres, "01"-"12")
          - DD = Jour du mois (deux chiffres, "01"-"31")
          - HH = Heure (deux chiffres,au format 24h, "00"-"23")
          - mm = Minute (deux chiffres, "00"-"59")
          - ss = Secondes (deux chiffres, "00"-"59")

        Exemple: "20210731110500.png",pour le 31 juillet 2021 à 11:05 du matin.

        Mettez cd fichier PNG dans votre répertoire Tux Paint "saved". (Voir
        ci-dessus)

        ## 2. Calculer les dimensions des images ##

        Cette partie de documentation doit être réécrite puisque la nouvelle
        option "buttonsize" a été ajoutée. Pour l'heure, essayer de dessiner et
        de sauvegarder l'image dans Tux Paint, et ensuite déterminer quelle
        taille (largeur et hauteur en pixels) elle possède, et essayez de
        l'adapter lors de la mise à l'échelle en l'important dans Tux Paint.

        IV.Lectures complémentaires

        Les autres documents inclus avec Tux Paint (dans le répertoire "docs")
        incluent :
        → Utiliser Tux Paint : ←
              x OPTIONS.html
                Instructions détaillées sur les options en ligne de commande et
                les fichiers de configuration, pour ceux qui ne veulent pas
                utiliser l'outil Tux Paint Config.
              x Documentation sur l'outil 'Magie' ("magic-docs")
                Documentation pour chacun des outils "Magic" actuellement
                installés.
              x Frequently Asked Questions ("FAQs") about Tux Paint
                Answers to, and solutions for, some common questions about, and
                problems with, using Tux Paint.

             
        → Extensions pour Tux Paint : ←
              x EXTENDING.html
                Des instructions détaillées sur la création de pinceaux, de
                tampons, d'images de démarrage et de modèles; et l'ajout de
                polices; et créer un nouveau clavier virtuel et des méthodes de
                saisie.
              x PNG.html
                Remarques sur la création d'images bitmap au format PNG à
                utiliser dans Tux Paint.
              x SVG.html
                Remarques sur la création d'images vectorielles au format SVG à
                utiliser dans Tux Paint.

             
        → Information technique : ←
              x INSTALL.html
                Instructions pour compiler et installer Tux Paint, le cas
                échéant.
              x SIGNALS.html
                Informations sur les signaux POSIX auxquels répond Tux Paint.
              x MAGIC-API.html
                Créer de nouveaux outils Magie avec le plugin API de Tux Paint.

             
        → Historique du développement et licence : ←
              x AUTHORS.txt
                Liste des auteurs et contributeurs.
              x CHANGES.txt
                Résumé des changements entre chaque version de Tux Paint.
              x COPYING.txt
                Licence du programme Tux Paint, la GNU General Public License
                (GPL)

             

        V.Comment obtenir de l'aide

        Si vous avez besoin d'aide, il existe de nombreux moyens d'interagir
        avec les développeurs de Tux Paint et les autres utilisateurs :
          - Mentionner des bogues, ou demander de nouvelles fonctionnalités via
            le système de suivi des bogues
          - Participer aux nombreuses listes de diffusion de Tux Paint
          - Contacter les développeurs directement

        Pour en savoir plus, visitez la page "Contact" du site officiel de Tux
        Paint : https://tuxpaint.org/contact/

        VI.Comment participer

        Tux Paint est un projet mené par des volontaires, et nous serions
        heureux d'accepter votre aide dans des tas de domaines :
          - Traduire Tux Paint dans une autre langue
          - Améliorer les traductions existantes
          - Créer des oeuvres (tampons, images de démarrage, modèles, pinceaux)
          - Ajouter ou améliorer des caractéristiques ou bien des outils
            "Magie"
          - Créer un programme d'étude en classe
          - Promouvoir ou aider ceux qui utilisent Tux Paint

        Pour en savoir plus, visitez la page "Nous aider" du site officiel de
        Tux Paint : https://tuxpaint.org/help/

        VII.Suivez le projet Tux Paint sur les réseaux sociaux

        Tux Paint est présent sur de nombreux media sociaux, où nous annonçons
        les mises à jour et les oeuvres d'art.
          - Suivre @tuxpaint@bsky.social sur Bluesky
          - Suivez Tux Paint sur Facebook
          - Suivre @TuxPaintDevs sur Instagram
          - Suivre @tuxpaint@floss.social sur Mastodon
          - Suivre u/TuxPaintDevs sur Reddit
          - Suivre @TuxPaintDevs sur Threads
          - Suivre @TuxPaintDevs sur TikTok
          - Suivre Tux Paint sur Tumblr
          - Souscrivez à @TuxPaintOfficial sur YoUTube

        VIII. Mentions concernant les marques déposées

          - "Linux" est marque déposée par Linus Torvalds.
          - "Microsoft" et "Windows" sont des marques déposées par Microsoft
            Corp.
          - "Apple" et "macOS" sont des marques déposées par Apple Inc.
          - "Haiku" est une marque déposée par Haiku, Inc.
          - "Facebook" et "Instagram" sont des marques déposées par Meta
            Platforms, Inc.
          - "Mastodon" est une marque déposée par Mastodon gGmbH.
          - "Reddit" est une marque déposée par Reddit, Inc.
          - "TIK TOK" est une marque déposée de Bytedance Ltd.
          - "Tumblr" est une marque déposée par Tumblr, Inc.
          - "YouTube" est une marque déposée de Alphabet, Inc.
