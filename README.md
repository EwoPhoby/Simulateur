ABELLI Mickael BAUP WALSH Mathieu

# Projet Langages Avancés


1. Pour installer les outils necessaire à la compilation utiliser les commandes suivantes: 

```
 $ make install
```

Par défaut la version de Raylib sera statique pour en choisir une autre:

```
 $ git clone https://github.com/raysan5/raylib.git raylib
 $ cd raylib/src/
 $ make PLATFORM=PLATFORM_DESKTOP # Version Statique .
 $ make PLATFORM=PLATFORM_DESKTOP RAYLIB_LIBTYPE=SHARED # Version Dynamique
 $ make PLATFORM=PLATFORM_WEB # Version Web
```

Rendez vous [ici](https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux) et suivez les instructions si l'installation a échouée ou si vous souhaitez changer le type


2. Pour executer le simulateur:

```
 $ make run
```
3. Un listing des principales methodes

```
 $ make listing
```