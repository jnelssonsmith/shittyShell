
# FIT2070 Assignment 1
##### Josh Nelsson-Smith
##### 02/09/2016
---
## Installing the program
Start by downloading and unzipping the file named `25954113_A1.zip`, once unzipped you should see the folder contains the following files:
```
25954113_A1/
├── README.md
├── README.pdf
├── advancedCLI
├── advancedCLI.c
├── basicCLI
├── basicCLI.c
├── compileScript.sh
├── lib
│   ├── cd.c
│   ├── clear.c
│   ├── cp.c
│   ├── dir.c
│   ├── echo.c
│   ├── find.c
│   ├── halt.c
│   ├── help.c
│   ├── new.c
│   ├── pause.c
│   ├── quit.c
│   ├── run.c
│   ├── validation.c
│   └── whereami.c
└── manuals
    ├── cd.txt
    ├── clear.txt
    ├── cp.txt
    ├── dir.txt
    ├── echo.txt
    ├── find.txt
    ├── halt.txt
    ├── help.txt
    ├── new.txt
    ├── pause.txt
    ├── quit.txt
    ├── run.txt
    ├── userManual.txt
    └── whereami.txt

2 directories, 34 files
```
You will see the project consists of the two versions of the CLI, the compile script (`compileScript.sh`) and `lib` and `manuals` folders. `lib` contains the function c files and `manuals` contains all the user manuals for the functions. The project already includes the two compiled versions of the program `advancedCLI` and `basicCLI`. However to ensure it is compiled correctly for your architecture I recommend re-compiling them beforehand. You can do this one of two ways:

a. Compile using included script ```compileScript.sh```
```sh
$ ./compileScript.sh
Compiling c program...
C programs compiled!
```
Note - you may need to alter permissions to allow the script to execute via something like:
```sh
$ chmod 777 compileScript.sh
```
b. Compile the program manually via:
```sh
$ gcc -o basicCLI basicCLI.c
$ gcc -o advancedCLI adancedCLI.c
```

Once the programs are compiled you can run either one via:

```sh
$ ./basicCLI
$ ./advancedCLI
```

---
## Using the Programs
After launching the program you will be presented with a traditional prompt for user input:
```sh
$
```

You can perform many functions that are available in the terminal you may be familiar with such as changing directory, creating files or dealing with processes. I suggest typing `help` to get started and better understand the commands included in the shell.
