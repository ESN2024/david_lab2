# Introduction
L'objectif de ce TP est de faire suite au TP présenté dans __"ESN2024/david_lab3"__. Il s'agissait d'apprendre la conception conjointe par la conception d'un système minimal composés d'un processeur soft-core câblé sur FPGA.

Nous allons ici approfondir la conception de ce système en ajoutant un *timer* et des afficheurs *7-segments*.
# 2. Présentation du système
Est présenté figure 1 le synoptique du système qui sera conçu. Il reprend la base du système TP1.
![image](https://github.com/ESN2024/david_lab2/assets/124572489/92ceeed7-63f2-4c7f-a43a-a4ff30319435)
*Figure 1. Description du système.*
Nous mettrons l'accent sur les nouveaux blocs. Premièrement le *Timer*, il permettra d'envoyer des interruptions au processeur périodiquement, ce qui permettra d'effectuer des fonctions d'attentes sans charger le provesseur. 

Ensuite, nous voulons afficher un compteur sur des afficheurs 7-segments, et cela implique l'instanciation d'un bloc d'encodage BCD.

La figure 2 présente la configuration Qsys du système.
![image](https://github.com/ESN2024/david_lab2/assets/124572489/d7eac2f8-202f-4c62-bce0-6deec8312aeb)
*Figure 2. Configuration Qsys.*
# 3. Résultats



# Conclusion
