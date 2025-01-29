# Compile Instructions

* **[Requirements](#requirements)**
* **[Compile the game](#compile-the-game)**
* **[Compile the unit tests](#compile-the-unit-tests)**

## Requirements

To compile this project you will need three things:

* CMake
* Makefile
* C++ compiler (g++)

All must be added to the system path to be able to execute the next commands.

## Compile the game

First, in the main project folder, create a new folder with the name of your choice, I chose 'build'.

```
mkdir build
```

Then go to this folder.

```
cd build
```

Run 'cmake' command from inside your created directory on SnakeCPP folder.

```
cmake ../SnakeCPP
```

Then execute the 'make' command.

```
make
```

The SnakeCPP.exe executable file will be created and is ready to be run. The remaining files and folders that were created as a result of the 'cmake' command can be discarded as they are not needed for running the .exe file.

## Compile the unit tests

As with compiling the game, first create a new folder and go to it. Again, I chose the name 'build'.

```
mkdir build
cd build
```

Run 'cmake' command from inside your created directory on Tests folder.

```
cmake ../Tests
```

Then execute the 'make' command.

```
make
```

The SnakeCPPTests.exe executable will be created and ready to run. It is important to run it from the command line because it is a console application. The rest of the files and folders that were created during the 'cmake' command can be discarded, just like it was in the case of compiling the game, because they are not used when running the executable.