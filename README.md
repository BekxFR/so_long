# so_long
## so_long 42project

Le projet consiste à créer un jeu en 2D en vue de profil ou du dessus.  
Avec un personnage qui doit récupérer les consommables présents sur la map avant de pouvoir prendre la sortie pour finir la partie.  
Le thème est libre en ce qui concerne l'ensemble des éléments présents.  
Nous devons respecter plusieurs règles dans ce projet que l'on peut découpé en deux partie.  
La première est le parsing de la map avec la vérification de lancement des règles définies dans le sujet.  
Puis la deuxième partie est l'affichage que nous devons réaliser grâce à la [Minilibx](https://github.com/42Paris/minilibx-linux)  (librairie utilisant les ressources X11, mise à disposition des étudiants de 42).

## Le parsing de la map

### La map
Tout d'avord nous devons vérifier la map, fichier au format .ber envoyé en argument lors du lancement du programme appelé so_long.  
Celle-ci doit respecter les conditions suivantes :
* Etre rectangulère (h et w > 2; h != w, toutes les lignes de même taille)
* Des murs (1) doivent être présents sur tous les bords de la map
* Etre composé de : 1 player (P), 1 sortie (E), au moins 1 consommable (C), N murs (1) et N chemins (0) et rien d'autres
* Doit être playable : le player doit pouvoir récupérer l'ensemble des C avant de pouvoir sortir

Après toutes les vérifications de bases je vérifie donc la jouabilité de la map.

### Le pathfinding
Pour vérifier que la map est playable, j'ai :
* Récupéré la map dans un char ** grâce à GNL
* Je parcours ma map pour localiser mon P
* Tant qu'il n'y a pas de 1 ou de E je change les 0 et C en P dans les 4 directions (avec un compteur pour les C trouvé)
* Je termine une fois de parcourir la map en continuant de modifier la map à partir de chaque P trouvé
* Si il reste un P avec un 0 ou C a cote de lui je relance ma fonction qui parcours la map et la modifie selon les conditions ci-dessus
* Pour finir, je vérifie qu'il y a bien un E à coté d'un P et que j'ai bien récupéré tous les consommables

## L'affichage avec la Minilibx
Pour ce projet j'ai réalisé l'ensemble des sprites sauf les arbres disponibles librement sur internet.  
Seule règle concernant la minilibx est de ne pas utiliser la fonction mlx_pixel_put.
Je vous remercie donc de ne pas récupérer les éléments autres que les arbres pour vos projets.  
Je précise , le code également. Je ne doute pas que vous n'aurez pas de mal à réaliser vous même l'ensemble des fonctions nécessaires au parsing.  
Et pour l'affichage, de nombreux sites vous proposes gratuiement des sprites libres de droit si vous ne vous sentez pas de réaliser vos propres dessins.  

## Le Lore
Le sujet nous laissant une totale liberté en ce qui concerne le choix des éléments graphiques je me suis pris au jeu et j'ai créé un univers particulier.
Pour vous présenter cet univers, plongé vous dans un monde ou un mouton décide de partir faire un séance de sport en foret.
Lors de sa séance de sport, il doit récuper une tenue (un C) et des fleurs (d'autres C).  
Mais le mouton ne se contente pas de seulement récuper la tenie de sport car il l'enfile et il voit alors la vie en rose.  
Une fois qu'il a récupéré l'ensembles des fleurs et/ou la tenue, il a la satisfaction d'avoir fini sa séance de sport,  
et peut se diriger vers la douche présente dans la foret, ce qui lui permet de mettre fin à sa séance.  

![](https://github.com/BekxFR/so_long/blob/main/gif/PinkLife.gif)

Bien evidement pour la partie technique le mouton ne peut passer à travers les murs et ne peut pas prendre la sortie si il n'a pas collecté sa tenue et les fleurs sur son passage.  

### Les Bonus
Pour ceux qui connaissent le sujet j'ai également réalisé les bonus.  
Bonus que je vous conseille car ils apportent du dynamisne au jeu et ne sont pas très compliqué à mettre en place grâce à mlx_loop_hook.
Les bonus consiste à :
* Intégrer un compteur de mouvement dans la fenêtre de jeu alors que celui-ci doit être affiché dans le terminal pour la partie normale
* ajouter un ennemi, pas directement dans le fichier .ber mais après le parsing
* ajouter des animations

Personnellement pour l'ennemi j'ai placé celui-ci après le parsing dans des endroits ou il ne rendait pas la map non jouable.  

L'ajout d'animation m'a permis d'ajouter à mon mouton une animation de squat, car je vous le rappel celui-ci est un sportif.
Il profite donc de sa randonnée pour faire des squats.
Les consommables, la sortie et le(s) ennemi(s) profitent égelement des ces ajouts.

J'en profite pour vous présenter l'ennmi, que peut-être certain auront reconnu.  
Celui-ci est incarné par norminet, le chat de l'école 42 Paris.
En effet lors de sa randonnée, le mouton peut être distrait par norminet dans ce cas il perd la partie.

C'est le bon moment pour vous présenter un ajout qui n'est pas demandé dans le sujet mais que j'ai intégré dans la partie normale,  
et que j'ai fait évolué dans la partie bonus.
La scène de fin!

En effet après avoir fini sa randonnée sportive et avoir utilisé la douche qui est la sortie, une scène de fin apparait.
Le mouton est heureux, il continu de faire ses squats pour la partie bonus et il est alors représenté au centre devant un fond arc en ciel.
La taille du mouton étant adaptée à la taille de la map.

![](https://github.com/BekxFR/so_long/blob/main/gif/SheepWin.gif)

Dans le cas ou le mouton est distrait par norminet, c'est alors norminet qui apparait dans la scène de fin et qui fait des squats à la place du mouton.

![](https://github.com/BekxFR/so_long/blob/main/gif/NorminetWin.gif)

Voila j'espère que cette création vous plaira et que les petits détails techniques vous permettront d'appréhender le projet.
J'espère que vous apprécierez autant que moi la réalisation de celui-ci et que vous n'hésiterez pas à faire les bonus.
D'ailleurs petit gif bonus pour alors lu le readme jusqu'au bout avec une map plus grande.

Amusez-vous bien!

![](https://github.com/BekxFR/so_long/blob/main/gif/Extra-LargMap.gif)
