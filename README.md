# SIMPLE SHELL 👋

## Description

The Simple Shell project consists of build a C language program, used as a Linux command line interpreter.

It is used to provide an interface between the user and the Kernel for executing given commands.

For example, if the user enters the command `ls` to display a list of files and directories, the program will execute the comment `ls`.
## Requirements
### General

* Allowed editors: vi, vim, emacs
* All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`
* All your files should end with a new line
* Your shell should not have any memory leaks
* No more than 5 functions per file

### About the Shell

* Display a prompt and wait for the user to type a command. A command line always ends with a new line.
* The prompt is displayed again each time a command has been executed.
* The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
* The command lines are made only of one word. No arguments will be passed to programs.
* If an executable cannot be found, print an error message and display the prompt again.
* Handle errors.
* You have to handle the “end of file” condition (`Ctrl+D`)
* Handle command lines with arguments
* Handle the `PATH`
* `fork` must not be called if the command doesn’t exist
* Implement the `exit` built-in, that exits the shell
* Usage: `exit`
* You don’t have to handle any argument to the built-in `exit`
* Implement the `env` **built-in**, that prints the current environment

## Flowchart
![Image](https://cdn.discordapp.com/attachments/1130868842197962864/1143963790002626681/Capture_decran_2023-08-23_a_19.43.04.png)
## File Usage

| Name File | Description |
| -------- | -------- |
| .gitignore   | File used for ignore some file when whe push into GitHub.   |
| main.h   | Header File. Lists the standard libraries used and integrates the prototypes we need to run the program properly. If one. If a necessary library or a used prototyp is missing in the file, the program will not be able to compile and therefore will not be executed.    |
| main.c   | Creates an infinit loop which displays a prompt and reads the input typed by the user.The shell will behave differently depending on what the user types: **exit**: the shell exits. **An existing command** (e.g. `ls`, `pwd`), the shell executes it and returns to the beginning of the loop. **The path of an existing command** (e.g. `/bin/ls`), the shell executes the command and returns to the start of the loop. **The command does not exist**, the shell displays an error message
| execute.c    | This function is used to separate each word of the user input and find the path to the command, then create a child process to execute it. If it does not exist, it will return an error.   |
| tokenize.c    | This function is used to separate each word from the user input and integrate them into a string array. It provides access to each word individually. It returns the array of strings created.    |
| trimInput.c    | This function returns the character string entered after removing spaces and tabs before the first character. It returns `NULL` if the first character entered is a new line or the end of a line of characters.     |
| getPathEnv.c    | This function retrieves the full path of the command. The function returns `NULL` if the command does not exist.   |
| man_1_simple_shell    | File that recreates a man page and explains how the shell we've created works.    |

## Compilation

You can compile your program using the following command :

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
## Man Page

You can access at our man page using the following command :
```bash
man ./man_1_simple_shell.1
```
## Check Memory Leaks

You can check memory leaks using the following command :

`valgrind ./hsh`

```bash
valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=valgrind-out.txt \
         ./hsh
```

## Testing the programm

### Interactive mode

```bash
ⓢ ls
AUTHORS                 getPathEnv.c            man_1_simple_shell.1
LICENSE                 hsh                     tokenize.c
README.md               main.c                  trimInput.c
execute.c               main.h
ⓢ
```
```bash
ⓢ /bin/pwd
/Users/username/Documents/holbertonschool-simple_shell
ⓢ exit
$
```
```bash
ⓢ program
./hsh: No such file or directory
ⓢ
```
### Non Interactive mode

```bash
$ echo “env” | ./hsh
SHELL=/bin/bash
PWD=/root
LOGNAME=root
HOME=/root
LANG=C.UTF-8
LESSOPEN=| /usr/bin/lesspipe %s
USER=root
SHLVL=1
XDG_DATADIRS=/usr/local/share:/usr/share:/var/lib/snapd/desktop
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
:/usr/games:/usr/local/games:/snap/bin
MAIL=/var/mail/root
=/usr/bin/env
$
```
```bash
$ echo “ls -la” | ./hsh
total 216
drwxr-xr-x@ 16 username  staff    512 24 aoû 13:40 .
drwxr-xr-x@ 11 username  staff    352 24 aoû 13:40 ..
-rw-r--r--@  1 username  staff   6148 24 aoû 10:08 .DS_Store
drwxr-xr-x@ 16 username  staff    512 24 aoû 13:40 .git
-rw-r--r--   1 username  staff     10 21 aoû 14:26 .gitignore
-rw-r--r--   1 username  staff    103 24 aoû 10:01 AUTHORS
-rw-r--r--   1 username  staff   1065 21 aoû 14:26 LICENSE
-rw-r--r--   1 username  staff   4720 24 aoû 12:53 README.md
-rw-r--r--   1 username  staff    722 24 aoû 10:01 execute.c
-rw-r--r--   1 username  staff    685 24 aoû 08:30 getPathEnv.c
-rwxr-xr-x   1 username  staff  50504 24 aoû 12:45 hsh
-rw-r--r--   1 username  staff    744 24 aoû 10:01 main.c
-rw-r--r--   1 username  staff    324 24 aoû 08:30 main.h
-rw-r--r--   1 username  staff   2922 24 aoû 12:53 man_1_simple_shell.1
-rw-r--r--   1 username  staff    494 24 aoû 08:30 tokenize.c
-rw-r--r--   1 username  staff    338 24 aoû 08:30 trimInput.c
$
```
```bash
$ echo ”     ” | ./hsh
$
```
## Exit

hsh  returns  the  exit status of the last command executed, unless asyntax error occurs, with zero indicating success and non-zero  indicating failure.\
All  builtins return 0 on success and 1 or 2 on failure (indicated by a corresponding error message).
## Bugs

Exit  status don't always have the good status number.

## 🙇 Authors
#### Cassandra BOUDIER
- Github: [@CassandraB670](https://github.com/CassandraB670)

#### Olivier T'SERVRANCX
- Github: [@electrikbox](https://github.com/electrikbox)
## License

« Copyright © <22/08/2023>, <copyright Cassandra BOUDIER & Olivier T'SERVRANCX> Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

The Software is provided “as is”, without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose and noninfringement. In no event shall the authors or copyright holders X be liable for any claim, damages or other liability, whether in an action of contract, tort or otherwise, arising from, out of or in connection with the software or the use or other dealings in the Software.

Except as contained in this notice, the name of the <copyright Cassandra BOUDIER & Olivier T'SERVRANCX> shall not be used in advertising or otherwise to promote the sale, use or other dealings in this Software without prior written authorization from the <copyright Cassandra BOUDIER & Olivier T'SERVRANCX>. »
