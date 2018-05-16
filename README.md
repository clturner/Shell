<img src="https://www.holbertonschool.com/assets/holberton-logo-1cc451260ca3cd297def53f2250a9794810667c7ca7b5fa5879a569a457bf16f.png" alt="Holberton Logo" style="width:205px;height:64px;">
<h1>Simple_Shell</h1>
<h2>Simple implementation of a shell in c</h2>
<h3>Description</h3>
<h5>Simple implementation of a shell written in c for the Holberton School</h5>
<h4>The purpose of this project is to:</h4>
<ul>
  <li>Understand the basics of a shell</li>
  <li>Learn to code the basic functionality for a simple shell in c</li>
  <li>Understand process id, pid and ppid</li>
  <li>Learn to manipulate and use the environment for processes</li>
  <li>Understand sys calls</li>
  <li>Create code for taking and storing user input</li>
  <li>Parsing user input inot usable strings</li>
  <li>Understand Aliases. Builtins and the PATH</li>
  <li>Parsing of the PATH to create strings of absolute paths</li>
  <li>Concatonating parsed user commands to parsed values of the PATH values to\
 create absolute paths for searching</li>
  <li>Forking and waiting for child and parent processes</li>
</ul>
  <h3>The Requirements</h3>
<ul>
  <li>Comply with Betty style guidelines created by Holberton school</li>
  <li>All code is complied with -Wall -Werror -Wextra -pedantic flags</li>
  <li>All files end with a new line</li>
  <li>Include no more than five functions per file</li>
  <li>Programs should have the same output as sh along with exact same error ou\
tput</li>
</ul>
<h3>Environment</h3>
<h5>The simple_shell was designed to be compiled with gcc 4.84 and run on Ubunt\
u 14.04 LTS</h5>

File | Description
------------ | -------------
main.c | Main file
shell2.h | Header file with prototypes
helperfunctions.c | _strlen(), _strdup(), strcmp(). _strcpy and pathcat
_getenv.c | returns colon deliminated value of PATH environmental variable
accesscheck.c | checks for file access
add_node_end.c | Adds node to the end of a linked list
envcopy.c | Creates a copy of the environment
findpath.c | Creates an absolute path from PATH value and user command
fork.c | Creates a child process to execute a file
freepath.c | free_path, free's a linked list: free_pointers, free pointers
_memset | Set all bytes in a buffer to a constant
strcat.c | Concatenates one string to another
tokenize.c |  Function to tokenize a line

<h3>How to use the simple shell</h3>

Instruction | Command
------------ | -------------
Clone repo | git clone https://github.com/NamoDawn/simple_shell.git
Complile all files | gcc -Wall -Werror -Wextra -pedantic *.c -o simple_shell
Run the executable | ./simple_shell
Type commands | $ ls -l

<h3>System Calls</h3>
<h4>access, execve, fork, free, getline, perror, wait, write</h4>
<h3>Limitations</h3>
<ul>
   <li>No quoting arguments or escaping characters</li>
   <li>Does not support piping or input/output redirection</li>
</ul>

<h3>Resources</h3>
<h4>The Linux Programming Interface by Michael Kerrisk</h4>
<h4>GNU Project Documentation</h4>
<h4>The C Programming Language by Brian Kernighan and Dennis Ritchie </h4>
<h4>Programming in C Stephen Kochan</h4>
<h4>Linux Manual Pages</h4>
<h4>Corbin Coleman Twitter: @corbinmcoleman </h4>

<h3>Bugs</h3>
<h4>Theree are some memory leaks when the simple_shell receives unexecutable arguments</h4>
<h3>Authors</h3>
<h4>Chris Turner - <a href="https://github.com/clturner">Github</a> || <a href=\
"mailto:christopher.turner@holbertonschool.com?Subject=Hello%20again" target="_\
top">Email</a></h4>
<h4>Naomi Sorrell - <a href="https://github.com/NamoDawn">Github</a> || <a href=\
"mailto:naomi.sorrell@holbertonschool.com?Subject=Hello%20again" target="_\
top">Email</a></h4>
