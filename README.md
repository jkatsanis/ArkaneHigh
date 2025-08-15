# HOW TO RUN
- Clone it into ubuntu subsystem or linux
- navigate in the folder and run **chmod +x SETUP.sh**
- then ./SETUP.sh
- cd Source
- **chmod +x Build.sh**
- make compile
    - if you get **make: ./Build.sh: No such file or directory**
    - run 
        - sudo apt install dos2unix
        - Build.sh
- make run
- and press keys and have fun :)

# ArkaneOS
A very small operating system working only in kernel lol.

## Tools used
- Programming language: Assembly, C++
- Makefile
- GDB (debug)

## Technical info

- 64 BIT
- Qeemu for the .bin file

## Some shit
So the idea is to have a os with alot of kernel features, and you can create programs that even directly use those features without sys calls or whatever so for example you can subscribe to a OnKeyboardPress function that gets called directly from the idt ye

## Some info
- The Kernel folder is the literal kernel but also contains helper functions
- The program folder is the os programs like terminal but also user programs that just use the kernel like a static