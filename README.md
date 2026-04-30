#  Projet 2048 — Programmation Modulaire

> Université Paris-Saclay · Décembre 2024/25  
> **Auteurs :** Elena Vucenic & Bianca Oancea · MI-3

---

## Description

Recréation du célèbre jeu **2048** en C++, développée de manière progressive selon une architecture modulaire. Le projet évolue d'une interface console minimaliste vers une version graphique complète avec la bibliothèque **SFML**.

---

##  Structure du projet

```
Game2048/
├── modele.hpp          # Logique du jeu (plateau, déplacements, score)
├── ncurses_min.cpp     # Interface console avec ncurses
├── sfml_game.cpp       # Interface graphique avec SFML
├── Makefile            # Compilation automatisée
└── README.md
```

---

##  Niveaux réalisés

### Niveau 0 — Logique de jeu (`modele.hpp`)
Implémentation complète de la logique du jeu :

| Fonction | Description |
|---|---|
| `tireDeuxOuQuatre()` | Génère un 2 (90%) ou un 4 (10%) aléatoirement |
| `plateauVide()` | Crée une grille 4×4 initialisée à zéro |
| `plateauInitial()` | Génère le plateau de départ avec 2 tuiles |
| `Nouvelletuille()` | Ajoute une tuile après chaque mouvement |
| `déplacementGauche/Droite/Haut/Bas()` | Déplace et fusionne les tuiles dans chaque direction |
| `déplacement()` | Dispatcher central (0=gauche, 1=droite, 2=haut, 3=bas) |
| `dessine()` | Retourne le plateau formaté sous forme de chaîne |
| `estTerminé()` | Vérifie si aucun mouvement n'est possible |
| `estGagnant()` | Vérifie si une tuile 2048 est atteinte |

**Bibliothèques utilisées :** `<iostream>`, `<cstdlib>`, `<ctime>`, `<iomanip>`, `<vector>`, `<string>`

---

### Niveau 1 — Interface console (`ncurses_min.cpp`)
Interface interactive dans le terminal avec la bibliothèque **ncurses** :

-  **Couleurs** — texte blanc sur fond bleu (`init_pair`, `attron`)
-  **Flèches directionnelles** — détection native via `keypad(stdscr, TRUE)`
-  **Rafraîchissement** — `clear()` + `refresh()` pour un affichage propre sans défilement
-  **Score local** — calculé par référence (`int& score`) sans variable globale

---

### Niveau 2 — Makefile & GitHub

**Makefile :**
```makefile
CPPFLAGS = -Wall -g
LDFLAGS  = -lncurses
SRC      = ncurses_min.cpp
EXEC     = ncurses_min

all:     $(EXEC)
clean:   rm -f $(EXEC)
rebuild: clean all
```

**Compilation :**
```bash
make        # Compiler
make clean  # Nettoyer
make rebuild # Recompiler depuis zéro
```

**Dépôts GitHub :**
- 🔗 [elenavucenic/Game2048](https://github.com/elenavucenic/Game2048/tree/main)
- 🔗 [biancaoan/2048_project](https://github.com/biancaoan/2048_project.git)

---

### Niveau 3 — Interface graphique SFML

Version graphique développée sous **Visual Studio** par Bianca :

**Fenêtre :** 640×800 px — 4 colonnes × 5 lignes de tuiles (160×160 px chacune)

```cpp
sf::RenderWindow window(sf::VideoMode(4 * 160, 5 * 160), "2048 - par Bianca et Elena");
```

**Fonctionnalités graphiques :**
-  Tuiles colorées en RGB avec nuances progressives
-  Tuile dorée pour la victoire (2048 atteint)
-  Texte centré dynamiquement dans chaque tuile
-  Affichage du score au-dessus du plateau
-  Lignes de séparation dessinées en dernier (pour rester visibles)

**Gestion des entrées :**
```cpp
if (dircurrent != -1)     { moved = true; }
if (KeyReleased)          { moved = false; }  // Évite les répétitions involontaires
```

**Police :** `C:\Windows\Fonts\arial.ttf` (chemin système Windows)

---

##  Installation & Exécution

### Version console (ncurses)
```bash
# Prérequis : ncurses
sudo apt install libncurses5-dev   # Debian/Ubuntu

# Compilation & lancement
make
./ncurses_min
```

### Version graphique (SFML)
```bash
# Prérequis : SFML, Visual Studio (Windows)
# Télécharger SFML sur https://www.sfml-dev.org/

# Compiler et lancer depuis Visual Studio
```

---

##  Contrôles

| Touche | Action |
|---|---|
| `←` | Déplacer à gauche |
| `→` | Déplacer à droite |
| `↑` | Déplacer vers le haut |
| `↓` | Déplacer vers le bas |

**Objectif :** Fusionner les tuiles pour atteindre **2048** !

---

##  Organisation du travail

| Membre | Environnement | Rôle principal |
|---|---|---|
| **Elena Vucenic** | Jupyter / terminal | Logique de jeu, interface ncurses |
| **Bianca Oancea** | Visual Studio | Interface graphique SFML |

- Réunions régulières en présentiel pour la synchronisation
- Revue croisée du code : chaque membre teste le travail de l'autre
- Utilisation de **GitHub** (branches, résolution de conflits, suivi des changements)
- **Durée totale :** ~60 heures

---

##  Bibliothèques utilisées

| Bibliothèque | Usage |
|---|---|
| `<vector>`, `<string>`, `<iostream>` | Structure de données & affichage |
| `<cstdlib>`, `<ctime>` | Génération aléatoire |
| `<iomanip>` | Formatage de l'affichage console |
| `ncurses` | Interface texte interactive |
| `SFML` | Interface graphique 2D |

---

## Ce que nous avons appris

- Architecture modulaire en C++ (séparation modèle / vue)
- Gestion d'affichage en mode texte avec **ncurses**
- Développement d'une interface graphique avec **SFML**
- Collaboration avec **Git/GitHub** (branches, conflits, pull requests)
- Passage par référence (`&`) pour éviter les variables globales

---

*Projet réalisé dans le cadre du cours de **Programmation Modulaire** — Université Paris-Saclay, MI-3*
