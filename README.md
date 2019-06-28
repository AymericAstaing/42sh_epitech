# 42sh_epitech (TECH 1 2017-2018)

The goal of this project is to develop a Unix SHELL.

The project consists of two sections:
- a mandatory section, which MUST be completed: display a prompt, parse and execute some commands (see below),
- an optional section, which will only be evaluated if the mandatory section is fully functionnal.

(Authorized functions: all functions included in the libC or the ncurses library.)

EPITECH MANDATORY
    
    This section must be COMPLETELY FUNCTIONAL. Otherwise your grade will be 0.
    Concerning command parsing and execution, you must handle:
    - spaces and tabs,
    - $PATH and environment,
    - errors and return value,
    - redirections (‘<’, ‘>’, ‘<<’ and ‘>>’),
    - pipes (‘|’),
    - builtins: cd, echo, exit, setenv, unsetenv,
    - separators: ‘;’, ‘&&’, ‘||’.

to build:
    
    make / make re
      
to launch:

    ./42sh

Aymeric Astaing - EPITECH PARIS PROMO 2022
