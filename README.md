# Minishell

<h1 align="center">Hi 👋,this is my Minishell Project</h1>


---Minishell  is a 42-school project that aims to introduce as the world of shells by recoding out mini bash, a program that can parse, execute, and        launch exécutables along with some built-in commands.

---------------------------------------------------------------------------
🌱 This shell does:


• Afficher un prompt en l’attente d’une nouvelle commande.

• Posséder un historique fonctionnel.

• Chercher et lancer le bon exécutable (en se basant sur la variable d’environnement
       PATH, ou sur un chemin relatif ou absolu).
      
• Ne pas utiliser plus d’une variable globale. Réfléchissez-y car vous devrez justifier
        son utilisation.
      
• Ne pas interpréter de quotes (guillemets) non fermés ou de caractères spéciaux non
         demandés dans le sujet, tels que \ (le backslash) ou ; (le point-virgule).
      
• Gérer ’ (single quote) qui doit empêcher le shell d’interpréter les méta-caractères
        présents dans la séquence entre guillemets.
     
• Gérer " (double quote) qui doit empêcher le shell d’interpréter les méta-caractères
         présents dans la séquence entre guillemets sauf le $ (signe dollar).
      
• Implémenter les redirections :
        _ < doit rediriger l’entrée.
        _ > doit rediriger la sortie.
        _ << doit recevoir un délimiteur et lire l’input donné jusqu’à rencontrer une ligne
                 contenant le délimiteur. Cependant, l’historique n’a pas à être mis à jour !
        _ >> doit rediriger la sortie en mode append.
• Implémenter les pipes (caractère |). La sortie de chaque commande de la pipeline
        est connectée à l’entrée de la commande suivante grâce à un pipe.
      
• Gérer les variables d’environnement (un $ suivi d’une séquence de caractères)
             qui doivent être substituées par leur contenu.
       
• Gérer $? qui doit être substitué par le statut de sortie de la dernière pipeline
        exécutée au premier plan.
           
• Gérer ctrl-C, ctrl-D et ctrl-\ qui doivent fonctionner comme dans bash.

• En mode interactif :
     _ ctrl-C affiche un nouveau prompt sur une nouvelle ligne.
     _ ctrl-D quitte le shell.
     _ ctrl-\ ne fait rien.
     
• Votre shell doit implémenter les builtins suivantes :
      _ echo et l’option -n
      _ cd uniquement avec un chemin relatif ou absolu
      _ pwd sans aucune option
      _ export sans aucune option
      _ unset sans aucune option
      _ env sans aucune option ni argument
      _ exit sans aucune option

---------------------------------------------------------------

--La fonction readline() peut causer des fuites de mémoire. Vous n’avez pas à les
gérer. Attention, cela ne veut pas pour autant dire que votre code, oui celui que
vous avez écrit, peut avoir des fuites de mémoire.

----------------------------------------------------------------

The UNIX shell program interprets user commands, which are either directly entered by the user, or which can be read from a file called the shell script or shell program. Shell scripts are interpreted, not compiled. The shell reads commands from the script line per line and searches for those commands on the system while a compiler converts a program into machine readable form, an executable file - which may then be used in a shell script.
Apart from passing commands to the kernel, the main task of a shell is providing a user environment, which can be configured individually using shell resource configuration files.

 	What is shell :
-----------------------------------------------------------------
Shell is an environment in which we can run our commands, programs, and shell scripts. There are different flavors of a shell, just as there are different flavors of operating systems. Each flavor of shell has its own set of recognized commands and functions.

*👨‍💻 Parts of a Shell Program :

The shell implementation is divided into two parts: The Parser, The Execution:

    📫 The Parser: reads the command line and puts it into a data structure called Command Table that will store the commands. Then every command will puts it into a table called line_commande, Then we will split the line_commande by using space and puts it into data structure called arguments that will be executed.
    📫 The Execution: takes the arguments Table and for every SimpleCommand in the array it creates a new process; also, if necessary, it creates pipes to communicate the output of one process to the input of the next one; additionally, it redirects the standard input, standard output, and standard error if there are any redirections.


*👨‍ Shell Variables :
                  Bash keeps a list of two types of variables:
                  
•	Global / environment variables - are available in all shells. The env or printenv commands can be used to display environment variables.

•	Local variables - are only available in the current shell. Using the set built-in command without any options will display a list of all variables (including environment variables) and functions. Child processes of the current shell will not be aware of local variables.
Variables are case sensitive and capitalized by default. Giving local variables a lowercase name is a convention which is sometimes applied. However, you are free to use the names you want or to mix cases. Variables can also contain digits, but a name starting with a digit is not allowed.


💬 So for env we use : extern char **environ;
The variable environ points to an array of pointers to strings called the "environment".  The last pointer in this array has the value NULL.  This array of strings is made available to the process by the execve(2) call when a new program is started. When a child process is created via fork(2), it inherits a copy of its parent's environment.

*👨‍ Exporting variables:
1.	In order to pass variables to a subshell, we need to export them using the export built-in command. Variables that are exported are referred to as environment variables. A subshell can change variables it inherited from the parent, but the changes made by the child don't affect the parent.

2.	Setting and exporting is usually done in one step:

3.	export VARNAME="value".


*👨‍ Termination Signals:

These signals are all used to tell a process to terminate, in one way or another. They have different names because they’re used for slightly different 

purposes, and programs might want to handle them differently.

SIGINT - program interrupt signal (ctrl + C).

SIGQUIT - program interrupt signal (ctrl + \), produces a core dump when it terminates the process, just like a program error signal.

*****What is signal:***/

A signal is a software generated interrupt that is sent to a process by the OS because of when user press ctrl-c or another process tell something to 

this process.

There are fix set of signals that can be sent to a process. signal are identified by integers.


👨‍ Exit status (i use a global variable g_status):


	-Each command executed in a shell returns an g_status  (sometimes referred to as a return status or exit code). The exit status is often used in 
       
       shell scripts to display an error message or take an action.
	
       -Exit status fall between 0 and 255, though the shell may use values above 125 specially. For the shell's purposes, a command which exits with 
       
       a zero exit status has succeeded. A non-zero exit status indicates failure. This seemingly counter-intuitive scheme is used so there is one well-
       
       defined way to indicate success and a variety of ways to indicate various failure modes.

       -There is a special shell variable called $? that expands to the exit status of the most recently executed command.
 ___________________________________________________________________
 ***Lets explain this functions execve(), fork(), and pipe(), dup2():
 
📈1 -execve():
    
       La fonction execve() est une fonction assez utile qui va nous permettre d’exécuter un autre programme avec ses arguments dans un environnement          que l'on pourra spécifier.
        
	Cette fonction est prototypée de la façon suivante:
	---------------------------------------------------------------------------------
	Code C :
		int execve(const char *path, char *const argv[], char *const envp[]);
	---------------------------------------------------------------------------------
- Le premier paramètre: path est une chaîne de caractère définissant l'emplacement du binaire que l'on veut exécuter. Si vous voulez lancer la commande            bien connue "ls", il vous faudra taper tout le chemin jusqu'à celle-ci. Ce qui donnera par exemple: "/bin/ls".

- Le second paramètre représente les arguments qui sont passes au programme. Il contient la même chose que le paramètre "argv" que l'ont retrouve dans           la déclaration d'un main(). C'est un tableau de chaines de caractère qui se termine toujours par un pointeur a NULL.

- Le troisième paramètre, souvent moins connu représente l'environnement du programme.Le tableau de pointeur env fini lui aussi, comme argv par un pointeur a NULL. Lorsque vous tapez "ls" dans votre shell, c'est l'environnement du shell qui sera passe a "ls". Vous pouvez visualiser l'environnement en tapant la commande "env" dans votre shell (en tout cas sous bash et tcsh. Je ne sais si c'est différent dans d'autres shell).

Voila pour les paramètres. Passons maintenant a la valeur de retour.

On le voit bien dans le prototype, execve() nous retourne un int. Mais cette fonction est un peu particulière. En effet, si l’exécution de la commande 

échoue, execve() renverra la valeur -1, et mettra la variable globale errno a la valeur convenu (voir le man d'execve() pour plus de précisions a ce sujet).

Dans le cas contraire, si l’exécution du binaire passé en paramètre s'effectue correctement, execve() ne retournera absolument rien puisqu'il "passe au 
programme appelé".

Ça peut paraître étrange, mais c'est très logique. Pour exécuter un binaire, le processeur garde un pointeur vers l'instruction en cours d’exécution, et 
est déplacé automatiquement vers la prochaine instruction. L'appel a execve() va permettre de déplacer se pointeur en allant a l'adresse de début du 
binaire a exécuter. Le binaire est ensuite exécuter. mais lorsqu'on arrive a la fin, le programme se ferme car le pointeur sur l'instruction en cours ne 
peut pas revenir tout seul a la position avant l’exécution.

Je ne sais pas si j'ai été très clair, mais voyons un exemple pour éclaircir un peu plus.
----------------------------------------
Code C :

#include <unistd.h>

#include <stdio.h>

int main(int argc, char *argv[], char *env[])

{ 
  
  if (argc > 1)
    
    if (execve(argv[1], argv + 1, env) == -1)
     	perror("execve");
  
  printf("My pid is: %d\n", getpid());

  return 0;

}

¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨^¨^¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨

Ce que l'on fait ici:

- on vérifie qu'il y a bien un argument au programme.

- si c'est le cas, on exécute tout en prenant tout comme argument.

- si execve() fail, on affiche un message d'erreur.

- a la suite de tout ça, le programme va afficher son propre pid.

Petite parenthèse sur le pid pour ce qui ne savent pas ce que c'est. Le pid est le numéro d'identification d'un processus. Chaque processus possède le sien. 

C'est un numéro qui s'incrémente jusqu'à atteindre une valeur seuil, après laquelle il va prendre la première plus petite valeur disponible. Cette valeur est toujours positive.


bien, donc on compile et on lance.

   Code :                                              
 ------------------------------------------------  
   $> gcc -o example1 example1.c                       
   
   $> ./example1 test                                  
   
   execve: No such file or directory                   
   
   My pid is: 17600                                    
   
   $> ./example1 /bin/ls -l                            
   
   total 56                                            
   
   -rwxr-xr-x 1 ark users 7119 Oct 21 10:50 example1   
   
  -rw-r--r-- 1 ark users  229 Oct 21 10:50 example1.c 
   
  -rw-r--r-- 1 ark users 3575 Oct 21 10:48 tuto  
  
---------------------------------------------------

Comme on peut le voir, la première fois, le programme est lance avec le paramètre "test". execve() fail car le binaire "test" n'existe pas, perror() fait bien 

son boulot et affiche un message d'erreur. Ensuite, le pid est affiche.

J'ai ensuite lance le programme avec des paramètres valides: "/bin/ls" et "-l". execve() lance bien le binaire "ls", situe dans le répertoire "/bin/", et lui passe bien l'option "-l". En revanche, après l’exécution de la commande, le pid n'est pas affiche.

C'est pas mal de savoir comment exécuter un programme, mais pour en exécuter plusieurs a la suite, il va falloir faire autrement. C'est ici qu'intervient cette 

magnifique fonction fork().

📈 2 -fork():
  
  on commence par le prototype:
     
     pid_t fork(void);
   
   Comme on peut le voir, fork() ne prends pas de paramètre. Mais ce qui va nous intéresser c'est surtout la valeur de retour. fork() renvoi une valeur de type 
   pid_t. 
  
  Le type pid_t est en réalité un typedef sur un type int. Et ne représente rien d'autre qu'un pid.

   Alors cette fonction magique fork(), ce qu'elle fait c'est qu'elle va dupliquer le processus courant.

Globalement, au lancement du programme, toutes les instructions vont être exécuter de manière classique. Lorsque l'ont va arriver au fork(), 
un nouveau processus identique au premier va être créer. C'est un peu comme si on se retrouvait a avoir lance deux fois le même programme. Sauf que fork() retourne un pid. Et c'est ici que c'est très avantageux: si le pid retourne est égal a 0, on est dans le processus qui vient d’être crée (processus fils). Sinon, le pid est égal au pid du processus fils.

📈 3: Pipe: transfert de données entre 2 processus:

Alors, un pipe en soi, c'est comme un tuyau, avec une entrée et une sortie par lequel on peut faire passer des données. Vous en avez peut être déjà utilise 

dans un shell, quand par exemple on fait un "ls -l | wc -l" pour compter le nombre de ligne qu'a écrit la commande "ls -l".

En fait, tout processus possède une entrée standard, et deux sorties: une sortie standard, et une sortie d'erreur. Ces entrées et sorties sont représentées par des nombres qu'on appelé des "file descriptor" (que j’abrégerais "fd").

A retenir:

0 = entre standard.

1 = sortie standard.

2 = sortie d'erreur.
 
Dans le cas de la commande "ls -l | wc -l", la sortie standard de "ls -l" est remplacée par le début du pipe. Et l’entrée standard de "wc -l" est remplacée par l'autre bout du pipe. Du coup, les données qu'affiche la commande "ls" sont redirigées vers le pipe et récupérées par "wc".

Bon, donc comme je le disais. on a besoin de deux processus. Et on va avoir besoin d’écrire et lire sur un pipe. Je vous montre comment utiliser pipe(), et ensuite je vous laisserais vous démerder un peu, une fois de plus.
 So, prototype (man pipe):
___________________________________
Code C :

int pipe(int pipefd[2]);
____________________________________

Valeur de retour, c'est facile, 0 si ça a réussi, -1 si ça a échoue.

Le plus intéressant reste le paramètre: int pipefd[2]. C'est un tableau d'int de 2 cases, qui va permettre de créer le pipe. On aura un file descriptor dans chaque case. Il faudra lire sur le pipefd[0] et écrire sur le pipefd[1].

Juste une dernière chose avant de vous lâcher dans le code comme des zombies enrages, vous devez impérativement fermer l’extrémité du pipe que vous n'utilisez pas dans un processus. Pour cela, il vous faudra utiliser la fonction close(), qui prends en paramètre le fd a fermer. Je ne suis pas encore sur exactement du "pourquoi" vous devez faire ça, mais j’éditerais quand je le saurais.

Encore une fois, forcez vous a chercher !

📈 4-dup() / dup2(): dupliquer, rediriger des flux:

La fontions dup() permet de dupliquer un file descriptor, voyons son prototype:

------------------------------------------------------------------
Code C :

int dup(int fildes);

-----------------------------------------------------

Le paramètre est un file descriptor indiquant le fd a dupliquer. La valeur de retour est -1 si un erreur est survenue xor un nombre entier qui indique le nouveau file descriptor crée.

-----------------------------------
Code C :

int dup2(int fildes, int fildes2);

-------------------------------- 

Donc, ici, attention a ne pas confondre les 2 paramètres. Le premier correspond au nouveau fd, le 2 eme est l'ancien, a remplacer.

La valeur renvoyer est celle de l'ancien file descriptor, ou -1 en cas d'erreur. (Pour plus de précision, voir le man)

Du coup, dans ce cas, le fildes2 est fermer par close(). Inutile me direz vous ? En effet on ne fait que remplacer un nombre par un autre... Mais cela va permettre de faire un lien, par exemple entre un pipe et une sortie standard, ou un pipe et une entrée standard, etc...

Ce qui fait que avec ça, on va pouvoir rediriger ce qu'écrit un programme vers une variable a nous, ou bien rediriger ce qu'écrit un programme vers l'entrée d'un autre. C'est ce qui permet de faire.

Finally, I finished Minishell.
