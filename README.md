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
![Image](https://cdn.discordapp.com/attachments/1130868842197962864/1143532681271971840/Capture_decran_2023-08-22_a_15.10.15.png)
## File Usage

| Name File | Description |
| -------- | -------- |
| .gitignore   | File used for ignore some file when whe push into GitHub.   |
| main.h   | Header File. Lists the standard libraries used and integrates the prototypes we need to run the program properly. If one. If a necessary library or a used prototyp is missing in the file, the program will not be able to compile and therefore will not be executed.    |
| main.c   | Row 3    |
| execute.c    | Row 3    |
| tokenize.c    | Row 3    |
| trimInput.c    | Row 3    |
| getPathEnv.c    | Row 3    |
| man_1_simple_shell    | File that recreates a man page and explains how the shell we've created works.    |
| AUTHORS   | File containing the names of the developers who worked on this project.    |
| LICENSE   | This file gives users express permission to re-use the code for any purpose, even if it is part of proprietary software. As long as users include the original copy of the MIT licence in their distribution, they can make any changes to the code they wish to suit their needs.    |

## Compilation

You can compile your program using the following command.

`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`
## Returns

## Man Page

## Check Memory Leaks

You can check memory leaks using the follewing command.

`valgrind ./hsh`

## Testing the programm

## Output Check
## Bugs

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
