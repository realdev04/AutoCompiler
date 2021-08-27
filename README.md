# AutoCompiler
## Introduction
 An Auto Compiling tool for MinGw C/C++ which Compiles your C/C++ Code once it's changes are Saved.
## Download Binaries
 You can Download Binaries from our [Website Downloads](https://realdev04.github.io/index.html#features4-b)
## Installation
 Go and Read our [Website Docs](https://realdev04.github.io/index.html#features3-8)
## Configuration
 Go and Read our [Website Docs](https://realdev04.github.io/index.html#features3-8)
## Usage
 **Auto compiler is a Very easy to use Tool.**
 <br>
 <br>
If you would like to pass the Names of the Files as a CMD Argument, the Syntax will look like similar to this.
 <br>
  **`autocmp [.c/.cpp/.h and .hpp File Names] -o [Output Name] += [Compiler Arguments(Optional)] +=`**
 <br>
 <br>
 A simplest example using autocmp.
 <br>
 Example: 
 ```
 autocmp main.cpp -o main
 ```
 <br>
 <br>
 
 In autocmp, you can directly pass Compiler Arguments to the Compiler(in between  `+=`  symbol). Such as, Include Path, Library Directory, Libraies to Link ,etc. Instead of `-c` and `-o`.
 <br>
 Example: 
 
 ```
 autocmp main.cpp src/test.cpp header/test.h -o main += -Iinclude -Llibs -lmyLib +=
 ```
 <br>
 <br>
 If you would like to pass the Names of the Files as a File, the Syntax will look like similar to this.
 <br>
 
 `autocmp -f [File Name contains file list] -o [Output Name] += [Compiler Arguments(Optional)] +=`
 
 <br>
 <br>
 An Example for passing the Name of the File which Contains the File List.
 <br>
 
 Example: 
 ``` shell
 autocmp -f fileList.atc -o main += -Iinclude -Llibs -lmylib +=
 ```
 <br>
 <br>
 
 The file `fileList.atc` will look like something like this.
 ```
 main.cpp
 src/test.cpp
 header/test.h
 ```
 
 ## Support
 Please feel free to Support Me.
 <br>
 PayPal: https://www.paypal.com/donate?hosted_button_id=XWDYWBW5RJ5DJ
 <br>
 Patreon: https://www.patreon.com/realdev04
 <br>
 Thank You!
