# Do-Now: How It Works

## Getting Started

### Clone the Repository
To get started, clone the repository to your desired directory using the following command:

```sh
git clone https://github.com/rakshitbhai/do-now.git
```

### Ensure C is Installed
Make sure that the C compiler (GCC) is installed on your machine. If it is not installed, refer to the documentation for installation instructions.

### Navigate to the Directory
Once cloned, navigate to the directory where you have cloned the repository:

```sh
cd do-now
```

### Compile the Program
Change to the `src` directory before running the following commands in your terminal to compile the program:

```sh
cd src
gcc -c util.c -o util.o
gcc -c main.c -o main.o
gcc -c colors.c -o colors.o
gcc -c changehere.c -o changehere.o
gcc util.o main.o changehere.o colors.o -o run
```

### Run the Program
To execute the program, use the following command inside the `src` directory:

```sh
./run
```

## Using the Program
Now that you have successfully compiled and run the program, follow these steps:

### Default List Option
When you run the program, it will prompt you to choose whether to continue with the default task list or create a new one.

- **To use the default list**, type `n`.
  
![Screenshot 2025-02-16 at 1 04 30 PM](https://github.com/user-attachments/assets/3bda30af-8cdf-4e38-96c6-a54daa45fd86)

  
  Upon pressing `n`, the following screen will appear:
  
![Screenshot 2025-02-16 at 1 05 03 PM](https://github.com/user-attachments/assets/2af33340-507c-427f-a24a-18518280c32f)

  
  The default list is located in `src/changehere.c`. You can modify it as needed.

---

- **To create a new list**, type `y`.
  
  Here, you can add your tasks one by one:
  
![Screenshot 2025-02-16 at 5 38 58 PM](https://github.com/user-attachments/assets/607b6c37-3f39-4494-8c7e-a7d128cd246e)

  
### Task Storage
Once tasks are entered, the program will generate a task list stored in an `info.md` file located at:

```
TIME LINE/(year)/(month)/(day)/info.md
```

Additionally, a folder named `work` will be created in the same location to manage related files.

### Folder Structure
The `work` folder is where you can store any coding work you have done today or leave it blank.

The generated folder structure will look like this:

```
├── TIME LINE
│   └── (Year)
│       └── (Month)
│           └── (Day)
│               ├── info.md   <-- Markdown file
│               └── work      <-- Work folder
```

## Version Control
To maintain a record of your tasks and progress, first, create a repository in your GitHub account. Then, follow these steps to push your changes:

```sh
cd TIME LINE
git init
git add .
git commit -m "Initial commit"
git remote add origin <your-repo-url>
git push -u origin main
```

Now, your to-do list and task records are properly managed and version-controlled!

---

Happy Task Management! 🎯

