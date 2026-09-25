# ⚛️ High-Energy Physics Experimental Analysis

## 📖 Description

Ce projet est une **chaîne d'analyse complète en physique des hautes énergies** (High-Energy Physics, HEP) qui couvre l'ensemble du pipeline expérimental, depuis la **simulation d'événements de collisions** jusqu'à l'**extraction de distributions physiques** exploitables pour la comparaison théorie/expérience.

Il repose sur quatre piliers technologiques majeurs :

- **ROOT** — framework de référence en physique des particules pour l'analyse de données, la gestion des arbres (TTrees), des histogrammes et des fichiers de données.
- **TMVA** — *Toolkit for Multivariate Analysis*, intégré à ROOT, utilisé pour la classification multivariée (BDT, MLP, SVM, Likelihood, etc.).
- **WHIZARD** — générateur d'événements Monte-Carlo pour la simulation de collisions à haute énergie (processus e⁺e⁻, pp, etc.).
- **C++** — langage principal pour le traitement, le filtrage, la reconstruction et l'orchestration du pipeline d'analyse.

---

## 🎯 Objectif

**But principal :** Construire une chaîne d'analyse complète permettant de :

1. **Simuler** des événements de collisions à l'aide de WHIZARD.
2. **Reconstruire** les particules produites et calculer les variables cinématiques (masses, énergies, angles).
3. **Appliquer des coupes** de sélection pour isoler le signal du bruit de fond.
4. **Entraîner un classifieur multivarié** avec TMVA pour améliorer la discrimination signal/background.
5. **Extraire des distributions physiques** : sections efficaces (cross sections), spectres en énergie, distributions angulaires.

L'objectif final est d'obtenir une **mesure précise** des observables physiques et de comparer les résultats expérimentaux aux prédictions théoriques.

---

## 🛠️ Technologies utilisées

| Outil | Version | Rôle |
|-------|---------|------|
| **ROOT** | ≥ 6.x | Analyse de données, TTrees, histogrammes, I/O |
| **TMVA** | intégré à ROOT | Classification multivariée (BDT, MLP, SVM, Likelihood, FDA, etc.) |
| **WHIZARD** | ≥ 3.x | Génération d'événements Monte-Carlo |
| **C++** | C++17+ | Traitement, filtrage, reconstruction, pipeline |
| **CMake / Make** | — | Système de build |
| **Python** *(optionnel)* | ≥ 3.8 | Scripts auxiliaires, visualisation |

---

## 📂 Structure du projet
