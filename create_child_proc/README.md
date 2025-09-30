# Create Child Processes
This project is dedicated to create child processes and terminate all children created by the parent.

## QuickStart
```bash
# go into the directory of this project before executing the following commands
cmake -G Ninja -B build .; cd ./build; ninja; ./create_child_proc; cd ..; 

# Output:
# Hello, Parent!
# Process ID: 22845
# Parent Process ID: 4440

# Greeting program started with PID: 22846, PPID: 22845
# Hello, Child!
# Hello, Child!
# Hello, Child!
# Hello, Child!
# Hello, Child!
# Child process exited with status 0
# Press ENTER to exit...