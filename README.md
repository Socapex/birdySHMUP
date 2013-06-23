birdyShmup
==========
## Description
...

## Todo
- Player
    - Nice movement controls *phil*
    - Death sequence (explosion-->check lives-->3 second invulnerability etc)
    - Points and multipliers
    - Upgrades
    - Pixel perfect collision detection (or close).
- Background
    - scrolling *Ju*
    - parallax
    - other stuff???
- Bullets *Antoine*
- Particle systeme
    - Different movement presets.
    - Attach x, y to moving player.
    - Transparency levels
    - Rotation
- Enemies
    - Scriptable movement.
    - Scriptable events (bullets)
- Audio
    - Music
    - SFX


## Guidelines pour git

Bonjour tout le monde, voici un petit resumé du fonctionnement git de notre projet. Lors de la prochaine rencontre, je vous offre mon aide pour tout initialiser. Au cours du projet, si vous avez des problèmes et/ou questions, je serai toujours disponible. Finalement, je peu vous aidez sur skype s'il y a un problème majeur :)

#### Général
Chaque memebre de l'équipe fork ce projet. Comme-ça il va apparaitre sur votre page github.
Ensuite, vous cloner votre propre projet (et non celui-ci) sur votre ordinateur. Des instructions super claires sont disponibles ici: https://help.github.com/articles/fork-a-repo
Assurez-vous de rajouter l'adresse du projet upstream (Celui-ci). C'est essentiel.

Vous avez maintenant la branche master sur votre disque dur locale. Pour voir les branches presentes, tapez:

    git branch

Vous **ne devez pas travailler sur votre master**. 
Je repète, **il ne faut jamais travailler sur son master!**

Il y a plusieurs raisons pour cela:
- Vous allez toujours avoir une version fonctionnelle du projet au bout des doigts.
- Vous pouvez voir a tout moment ou l'equipe est rendu.
- Vous pouvez rapidement montrer une version stable du projet a quelqu'un (très encouragé pour recuellir des commentaires).
- Si vous avez un bug, et vous travaillez sur le master, vous ne pouvez pas etre sur que c'est vous ou si c'est quelqun d'autre qui l'a causé.
- Si votre master ne compile pas ou si il-y-a un bug sur celui-ci, *c'est immédiatement un problème top priorité.*


Bon, j'espère que vous etes convaincus :)

#### Démarche

Tout d'abord vous creez une branch:

    git branch nomDeLaBranche
    
Ensuite pour travailler dessus:

    git checkout nomDeLaBranche
    
Le reste ressemble pas mal a SVN. Pour des commits:

    git add fichier
    git add . (pour tout rajouter)
    git commit -m "Message pas trop descriptif sinon c'est trop facile pour l'equipe."
    
Pour voir vos changements sur github:

    git push -u origin nomDeLaBranche (seulement requis la premiere foi)
    
Dorénavant, vous pouvez simplement faire:
    
    git push
    
La vue "Network" va beaucoup vous aider pour visualiser les branches, je vous conseille de la regarder souvent. Tranquillement ca va devenir naturel.

#### Merge et Pull Requests

Lorsque vous etes confiant de votre travail et que vous voulez le partager avec les autres, il faut m'envoier un "pull request". Il y des instructions completes ici: https://help.github.com/articles/using-pull-requests. En résumé, vous m'avertisser que votre travaille est pret, compile et n'a pas de bugs (haha!). Ca n'a pas besoin d'etre beaucoup de nouvelles "features". Une nouvelle fonction, un bug éliminé, une nouvelle classe ou une petite modification d'animation sont des raison valables pour partager votre travail.

Je me charge du merge avec le master upstream, s'il y a des merge conflicts je vous contacterai. Une fois que j'ai accepté le request, vous allez p-e vouloir tester les changements sur le master. En fait, vous devriez updater votre master local **le plus souvent possible**, mais n'etes pas oubliger de rajouter les nouveaux changements dans votre branche instantanément.

Pour mettre votre master à jour:

    git checkout master
    git fetch upstream
    git merge upstream/master
    
Vous devriez pouvoir taper make, et joué! Si vous voulez incorporer les changements de l'équipe à votre branche:

    git checkout nomDeLaBranche
    git merge master
    
Sinon, un simple "git checkout nomDeLaBranche" vous ramène à votre travail actuel.




N.B.
Pour editer se fichier, vous pouvez suivre les instructions ici,
https://help.github.com/articles/github-flavored-markdown
