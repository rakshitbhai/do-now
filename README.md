

- How it work ?
You need to first git clone in your desired Directory
Then notice that c is installed in your machine
if it's not installed follow the documentation 

if it's installed 
Go to your directory where you have cloned this repository 
then cd into src file 
then copy paste this code on terminal it will complie the program :

gcc -c util.c -o util.o
gcc -c main.c -o main.o
gcc -c colors.c -o colors.o
gcc -c changehere.c -o changehere.o
gcc util.o main.o changehere.o colors.c -o run

Then to run the program use this command given below
./run         # Run the program

Now your are ready
use this command from your desired directory where git is ignored and cd src 

NOw when your run this program 
It will prompt you to continue with default list or not
IF you want to continue with default list type 'n'

default list is there in src/changehere.c
you can change the default list as you desired

IF you don't want to continue with default list type 'y'
here you can add your task one by one 
THEN a task list will be generated in info.md file located in TIME LINE/(year)/(month)/(day)/info.md

As the 2 things will be created by this program a folder named "work" and a markdown file named "info.md" in this location TIME LINE/(year)/(month)/(day)/

Folder Structure:
├── TIME LINE
│   └── (Year)
│       └── (Month)
│           └── (Day)
│               ├── info.md   <-- markdown file
│               └── work      <-- work folder

Now create a repo for todo in TIME LINE folder
and do all the stuff to push or pull the git repo
