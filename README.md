# Firefighter
An action/puzzle game where we control a firefighter in a labyrinth of flame
## Compiler sur window

First of all know that the compiler used is g++ (11.2.0) + MinGW-w64 9.0.0 (MSVCRT). You can download this compiler with [winlibs.com](https://winlibs.com/).
You must install make, here is a [link](https://stackoverflow.com/questions/32127524/how-to-install-and-use-make-in-windows) presenting different method to install make.

__Visual studio code__

1. We recommend installing vscode C/C++ extensions
2. Download the repository or clone it via git.
3. Open the folder with visual studio code
4. To compile and debug the project: F5

__Make__

1. Download the repository or clone it via git.
2. Open the folder in a command prompt and run this command:
```
make debug-window
```

## Compiler sur linux

The project uses the g++ 11.2.0 compiler. To download and use this compiler for the project, please run these commands on Debian/Ubuntu
```
sudo apt-get install g++-11
alias g++='g++-11'
```
You need to install make. To install make on Ubuntu/Debian, here is the command:
```
sudo apt-get install make
```
You need to install SFML. To install SFML on Ubuntu/Debian, here is the command:
```
sudo apt-get install libsfml-dev
```
__Visual studio code__

1. We recommend installing vscode C/C++ extensions
2. Download the repository or clone it via git.
3. Open the folder with visual studio code
4. To compile and debug the project: F5

__Make__

1. Download the repository or clone it via git.
2. Open the folder in a command prompt and run this command:
```
make debug-linux
```
