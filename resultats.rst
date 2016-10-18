Correction du TP1
~~~~~~~~~~~~~~~~~

Étudiant
========

Jean-Lou Hallée (HALJ05129309)

Résultat
========

+-------------------------+-----------------------------+-----------+-----------+
| Critère                 | Description                 | Note      | Sur       |
+=========================+=============================+===========+===========+
|                         | Affichage de la montagne,   |           |           |
| Fonctionnabilité        | affichage de l'eau,         | 40        | 40        |
|                         | validation                  |           |           |
+-------------------------+-----------------------------+-----------+-----------+
|                         | Modularité fonctionnelle    | 10        | 10        |
| Qualité du code         +-----------------------------+-----------+-----------+
|                         | Style et documentation      | 14        | 15        |
+-------------------------+-----------------------------+-----------+-----------+
|                         | Respect du format Markdown, |           |           |
| Fichier README          | qualité du contenu          | 10        | 10        |
|                         |                             |           |           |
+-------------------------+-----------------------------+-----------+-----------+
|                         | Compilation et nettoyage    |           |           |
| Makefile                | (``make`` et                | 10        | 10        |
|                         | ``make clean``)             |           |           |
+-------------------------+-----------------------------+-----------+-----------+
|                         | *Commits* liés à une tâche  |           |           |
| Utilisation de Git      | spécifique, message clair   | 14        | 15        |
|                         | et pertinent                |           |           |
+-------------------------+-----------------------------+-----------+-----------+
| Pénalité                |                             |           |           |
+-------------------------+-----------------------------+-----------+-----------+
| **Total**                                             | **98**    | **100**   |
+-------------------------+-----------------------------+-----------+-----------+

Commentaires
============

- Tous les tests passent sur Mac OS. Compilation sans avertissement.
- Excellente modularité.
- Code de bonne qualité. Peut-être ajouter davantage d'aération autour des
  parenthèses/accolades ainsi que des opérateurs.
- Excellente documentation.
- Quelques valeurs magiques (utiliser des constantes, même pour les chaînes de
  caractères).
- Excellent fichier README. J'ai fait quelques modifications mineures
  d'amélioration, mais dans l'ensemble, c'est très bien. Peu de fautes.
- Makefile impeccable.
- Bonne utilisation de Git. Cependant, le fichier ``.gitignore`` devrait
  ignorer les fichiers ``*.o`` ainsi que l'exécutable.
