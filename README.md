# turismo-dias-core

## Requisitos del proyecto

El proyecto funciona con la version de > C++14 y usa el soporte de std=c++17.

## Compilar el proyecto

Para compilar el proyecto se usa el siguiente comando:

```bash
g++ -g $(find ./src -type f -iregex ".*\.cpp") -o program.exe -std=c++17
```

## Iniciar la aplicación

Luego de compilar la aplicación se puede correr el comando 

```bash
./program.exe

// o se puede iniciar el archivo .sh que contiene el codigo para compilar y levantar la aplicación con un solo comando:
sh launch.sh
``` 
