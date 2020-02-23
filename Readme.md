# Makegenius

Here to help you setup your new C project !

Originally designed for 42 students, it's correction proof !


## Getting Started

* ```make init```
  * Will guide you through the initialization
  * You will be able to customize a couple of variables
  * it will finish with ```make init_git``` to link this fresh project with your newly created git repo
* ```init.mk```
  * This file will contain all your parameters for this project
  * As well as a couple of advanced options

## Features


* ```make file```  Will call both of these rules
  1. ```make sources```
   * Generate all the Makefile sources needed to compile what's inside your srcs/ folder
   * Will allow compilation relink for whatever is your folder architecture  in srcs/
  2. ```make prototypes```
    * Each function declared inside your srcs/ folder will have her prototype created and added in includes/auto/auto_*.h


* ```make run```
 1. During development of your project, it will make sure to recompile what's
 needed before launching your program !
 2. ```make run ARG="your argument"``` Allow you set up your first argument if you need it.


* ```Compilation Flags```
 During compilation you can specify different flags:
 1. ```make``` will compile with **-Wall -Werror -Wextra**
 2. ```make f=n``` will compile **without falgs**
 3. ```make f=f``` will compile with **fsanitize** and **-g3**
 4. ```make f=v``` will compile with **-g3**
   * when used with ```make run```  
    It will launch the program inside **Valgrind** to check for leaks !
 5. ```make f=h``` will compile with as much flags as possible !


* ```make git MSG="your commit message"```  
 Will ```git add``` all your modifications  
 After showing you the ```git status``` for you to confirm  
 this command will ```git push``` all your changes for you !

* ```make big n_times=1000```  
 Will launch ```make unit_test``` ```n_times```  
 Pretty useful for testing programs which highly relies on inputs like _push_swap_, _lem-in_ or _Corewar_


## Contributing

Feel free to open issues or to offer pull request !

I will be glad to make it perfect for you !

## Acknowledgments

Thank you for using my project !
