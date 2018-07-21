**description : ligne 1**
* nombre de ligne
* char vide
* char obstacle
* char plein
e..g `9.ox`

**carte valide**
* lignes de meme longeur
* au moins une ligne se longueur > 0
* `\n` a la fin de chaque ligne
* correspond a la description

**target**
```
bsq [<file> [<file> ...]]
```
* solution suivi de `\n` si solution
* `map error` suivi de `\n` si map invalide
* lis `stdin` lorsqu'il n'y a pas d'argument
* lorsqu'il y a plusieurs solution, choisir la solution en haut a gauche

**compile**
```
Makefile
```

**bibli**

 `exit`  `open`  `clone`  `write`  `read`  `malloc`
