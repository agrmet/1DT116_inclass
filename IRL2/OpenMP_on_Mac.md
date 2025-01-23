# Mac OpenMP compilation

1. Install brew (If you haven't, go to brew.sh and follow instructions to install

2. Install llvm and libomp using following commands

```
brew install llvm
brew install libomp
```

3. In the Makefile change the -fopenmp to `-Xpreprocessor -fopenmp -lomp`
Also add `-L/opt/homebrew/opt/libomp/lib -I/opt/homebrew/opt/libomp/include`
to the LDFLAGS or CFLAGS.
  * If you are on a Mac with x86 processors, the paths will be `/usr/local/opt/libomp/lib` and `/usr/local/opt/libomp/include` instead.

https://gist.github.com/ijleesw/4f863543a50294e3ba54acf588a4a421
https://github.com/orgs/Homebrew/discussions/3223#discussioncomment-3176756
