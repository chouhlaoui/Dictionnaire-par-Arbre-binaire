- Création d’un dictionnaire vide
- Ajouts de mots au dictionnaire existant
- Affichage du contenu du dictionnaire (avec les occurrences de chaque mot)
- Test d’existence d’un mot dans le dictionnaire (avec son nombre d’occurences le cas échéant)
- Statistiques : nombre total de mots, nombre de mots différents, etc...
- Suppression de toutes les entrées du dictionnaire

Les entetes : 

- void dicoAfficher(TArbre a);

Afficher le contenu d’un dictionnaire

- void dicoInsererMot(char mot[], TArbre *pa);

Insérer un nouveau mot (ou incrémenter son nombre d’occurrences si ce mot existe déjà dans le dictionnaire)

- int dicoNbOcc(char mot[], TArbre a);

Retourne le nombre d’apparitions d’un mot (et nous permet également de savoir si ce mot est présent ou non dans le dictionnaire)

- int dicoNbMotsDifferents(TArbre a); 

Retourne le nombre de mots differents dans ce dictionnaire

- int dicoNbMotsTotal(TArbre a);

Retourne le nombre de mots total dans ce dictionnaire

