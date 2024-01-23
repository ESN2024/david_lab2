# Introduction
L'objectif de ce TP est de faire suite au TP présenté dans __"ESN2024/david_lab3"__. Il s'agissait d'apprendre la conception conjointe par la conception d'un système minimal composés d'un processeur soft-core câblé sur FPGA.

Nous allons ici approfondir la conception de ce système en ajoutant un *timer* et des afficheurs *7-segments*.
Nous aimerions à terme avoir un compteur qui s'affiche sur les *7-segments* et que ce comptage soit opéré par le CPU sur réveil toutes les secondes par le *timer*.
# 1. Présentation du système
Est présenté figure 1 le synoptique du système qui sera conçu. Il reprend la base du système TP1.
![image](https://github.com/ESN2024/david_lab2/assets/124572489/a3678179-6dea-48c9-86f9-d2d4e5e4e3da)
*Figure 1. Description du système.*
Nous mettrons l'accent sur les nouveaux blocs. Premièrement le *Timer*, il permettra d'envoyer des interruptions au processeur périodiquement, ce qui permettra d'effectuer des fonctions d'attentes sans charger le provesseur. 

Ensuite, nous voulons afficher un compteur sur des afficheurs 7-segments, et cela implique l'instanciation d'un bloc de décodage BCD.

Ce bloc de décodage BCD est conçu en langage *HDL* et sa fonction est de convertir un signal BCD vers un signal 7 segments, signal qui est directement connecté aux afficheurs 7-segments. Cette opération est réalisée sur Quartus.

Nous devons ensuite faire la conversion d'un nombre binaire en BCD, pour cela deux modes de conception sont possibles :
**1.** Conçue en VHDL. Cette méthode est à priori à plébisciter car elle permettra de soulager le processeur de cette charge de travail, mais elle est longue à concevoir. L'option de se fournir un bloc IP est toujours possible mais sous quelles conditions ?
**2.** Conçue en C. Cette méthode est la plus simple à mettre en oeuvre mais présente le défaut de demander au CPU chaque seconde de mettre en pause ce qu'il fait pour réaliser un affichage. Cette solution a été choisi pour le gain de temps qu'elle occasionne.

La figure 2 présente la configuration Qsys du système.
![image](https://github.com/ESN2024/david_lab2/assets/124572489/d7eac2f8-202f-4c62-bce0-6deec8312aeb)
*Figure 2. Configuration Qsys.*
# 2. Résultats
Les afficheurs 7-segments sont fonctionnels et affichent bien un compteur mis à jour chaque seconde grâce à l'intervention d'un timer, commme escompté.

La vidéo 1 présente le système en fonctionnement.

*Vidéo 1. Affichage du compteur sur les afficheurs 7-segments.*
# Conclusion
A l'issue de cette séance de TP, nous avons pu apprendre à gérer les interruptions d'un *timer* et nous avons surtout pu apprendre qu'un système SPS sur FPGA a l'avantage de présenter des fonctions classiques de calcul et de gestion temps-réel d'un ordinateur/micro-contrôleur mais en plus de celà présente l'avantage d'avoir accès à des accélérations matérielles qui peuvent être très modulables (dans notre cas le décodeur BCD).
