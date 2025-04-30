
# Preface

The purpose of this document is to provide an introduction to members of the CTF team, and others who are just interested in the topic, into Reverse Engineering (REV). This is a collaborative work in progress, written by the members of the MaaSec team that are specializing in this field. This document covers many topics that do not seem immediately related with REV but at a deeper level serve as the basis of the field (Numerical bases, computer architecture, forward engineering etc.). Because of this, aspects of this document will also prove very useful to people interested in Binary Exploitation (PWN). 

If you find any missing/wrong/confusing information in this document, make sure to us know so that we can modify it. The contact information of the authors can be found in the "Contact Us" chapter.


# Introduction

Reverse Engineering (REV) is the art of taking a binary file, and through disassembly, decompilation and debugging, understanding the underlying logic. REV is most commonly used in the field of Malware Analysis, but anyone can reverse anything, as long as they have access to the bytes. 

The REV category of challenges in CTF competitions is usually the most difficult one. This is because obfuscation techniques have been heavily researched ever since the commercialization of computers, since their profits depend on their software being closed-source. You don't need to look for long to find an example, piracy for example is one of the main things that Music, Film and Video Game companies worry about when releasing their products. The producers don't have enough knowledge to implement good anti-piracy measures themselves, so they hire specialized companies, such as Denuvo, to do the work for them, and since their financial success depends on the effectiveness of their solutions, they have to make sure that nobody can bypass them. 

With enough effort anything can be understood or get cracked, and some of the most well-known methods will be covered in the following chapters. 

# Data and Numerical Bases/Systems

All programs are made up of data. It's up to us to give the data meaning and turn it into information. The data that makes up computer programs is in its purest form in the binary format. 

Binary as you probably already know is the simplest numerical base, consisting of just 2 digits, 0 (zero) and 1 (one). 

The amount of possible elements that are able to make up a valid number inside an arbitrary system , determines the base of that specific numerical system. The binary system has a base of 2 (two) since |{0,1}| = 2.

Binary data is impossible for humans to read at a large scale, so other systems are usually used. Base 10 (Decimal) (|{0,1,2,3,4,5,6,7,8,9}| = 10) has been the cornerstone of mathematics ever since the beginning. It's not really [the best base](https://youtu.be/rDDaEVcwIJM) but we have used it extensively, since it maps unto the amount of fingers that the median person has. 

Base 16 (HEXadecimal) ( |{0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F}| = 16 ) is a golden standard in the sphere of computing, since two HEX characters are able to represent an entire byte.

	Ex. 0x00 = 0 / 0x05 = 5 / 0x0F = 15/ 0x10 = 16 / 0xAB = 171 / 0xFF = 255


There are an infinite amount of numerical systems, as long as you are able to represent an infinite amount of symbols. One of the best known big bases is Base-64 but Base-128, Base-256 and Base-518 are also theoretically possible.

Base-128 (AKA ASCII) is technically one of the most used bases, since all keyboards with the English alphabet depend on it, but using it for computations and mathematics is not ideal. 
## Translating from Base-X to Base-Y

Since numerical bases are just different ways to represent numbers, we must also be able to turn numbers from an arbitrary base into numbers of another arbitrary base. There is a simple formula that is able to do this:

$$ N_{B} = \sum_{i=0}^{n} d_i \cdot A^i $$
- $N_{B}$: Number in new base  
- **$d_i$**: Digit at position \( i \) (starting from the rightmost digit, \( i = 0 \))  
- A: The original base  
- n: Highest position index (leftmost digit)


No data is lost or gained when using a certain system over another. The only thing that changes is the amount of symbols that the reader must know to interpret the data and the amount of indexes required to form the number.

This process of translating bases is best known as encoding, which is wholly different from encryption, where the original form of the data is only recoverable using a secret.

## Data Sizes

Since the size of primitive data types, such as int, char and float are system dependent, we use different terms to represent the size of a type. In the binary numerical system a bit is the smallest possible unit, with which we can represent a number (0 or 1).

A collection of 8 bits is called a byte and has a maximum value of 255 (0-255, meaning 256 possible numbers). Byte notation is usually preferred over bit notation, since in larger data types/structures it is difficult for a human to interpret.

A half-word is a data type of 16 bits (2 bytes, max 65_535), single words (WORDS) of 32 bits (4 bytes, max 4_294_967_295) and Double Words (DWORDS) 64-bits (8 bytes, max 18_446_744_073_709_551_616). 

These terms are usually used when talking about the architecture of a computer. Older computers used 32-bit registers which meant that the maximum amount of bits that a register could hold was a WORD. The address space is also dependent on the architecture, since a register holds the Instruction Pointer.
# Compilation

When source code is written by a programmer (or LLM), the computer is not able to parse the source code in any meaningful way. This is because source code is no different than any other text document to the processor. The process of turning source code into executable code is called compilation but it really consists of multiple steps. 

## Compilation (Again)

The compilation step involves turning source code into assembly code. Assembly code is a lower-level language than most others, but is not the lowest-level that we can reach. 

Turning source code into assembly code requires a Compiler, since doing it manually would be impossible for big applications. Each language has its own library of compilers, and interpreters (we will cover this later), so we will take the C language as an example. 

The LLVM and CLANG are examples of programs that parse the source code in such a way that it allows for easier translation to assembly. Provided a C source code file, these programs look at code patterns, such as memory allocation or mathematical operations, and are able to logically create a sequence of assembly instructions that perform the given functions. Simple compilers can be written in a couple hundred lines of code, but the specifics are outside the scope of this document.

During the process of compilation, the functionality of the program is preserved, but unique identifiers of variables and functions are lost. This makes reading assembly more challenging, since we can only use the instructions as reference. Assembly uses registers to store and operate upon data, so C code like:

```c
int money = 123;
```

is translated to:

```asm
MOV EAX, 123
```

Here, the identifier of the "money" variable is lost, and the value of it is stored in a memory register of the compiler's choice. 
### Basic introduction to ISAs and Assembly

There are many different flavors of assembly, such as x86-64 which is the standard in modern computers, ARM which has many benefits over x86-64 but still has not caught on in the mainstream, and MIPS which is not talked about much. These flavors are called Instruction Set Architectures (ISAs) in more formal language and list what operations are available to a system, how to use them, and what they do. The ISA of a computer is determined by the processor. Intel is the creator of the x86 ISA so most of their processors use it. Many of the Apple products used to use ARM CPUs, before they switched to producing their own processors.

---
**R/CISC Tangent - Optional Information**

Another way to differentiate between ISAs is by looking at the complexity of their Instruction Sets. Reduced Instruction Set Computers (RISC) use fewer and simpler instructions, which makes them simpler and faster, but makes code more verbose, since every single step needs to be written by the developer or the compiler. Complex Instruction Set Computers (CISC) use more, and more complicated instructions. As a result, many functions can be represented in a single operation, making the code more readable, but increasing the complexity of the architecture and requiring more clock cycles to perform certain operations. 

---

Assembly instructions consist of operations and operands, and the amount of operands depends on the operation itself. The maximum amount of operands an instruction can have, in the x86-64 ISA, is 3, but most use 1 or 2.


	MNEMONIC DESTINATION_OPERAND SOURCE_OPERAND OPTIONAL_OPERAND



## Assembly

The Assembly stage of compilation is the second stage, and it uses as input the assembly code generated by the compiler to produce object code. Object code is a lower level version of the assembly code in binary format, which will be used to produce the executable.

In this stage the assembly instructions are turned into their binary representations.

## Linker

The Linker stage uses the object file that was generated during the Assembly stage and combines it with other object files and libraries to produce the final executable file. The final product will be a .exe file or an ELF file and can be used by the operating system to perform the functionalities determined in the source code.

Linking can either be dynamic or static. This determines the amount of external resources that are included alongside the application's source code. 

Dynamic linking includes references to included files that have to be present on the system during runtime. The burden of having the files present is on the user, so it requires more effort on their end, while keeping file sizes low.

Static linking includes the files themselves into the executable. As a result file sizes are greater but allow users to immediately execute the program, without a need for additional work.

When reversing programs, static linking causes many problems to us reversers. Golang compilers for example, statically compile programs by default, meaning that analysis and debugging is much slower and much more arduous. 


# Computer Memory

Data and a program's code both need to be stored on the system to allow the processor to perform operations. Computers use a multi-layer system of caches and cold memory to improve performance, with the fastest memory type being CPU registers. 










# Contact Us


| Name                | Social-Media HyperLinks                                                                                                                   |
| ------------------- | ----------------------------------------------------------------------------------------------------------------------------------------- |
| Dimitrios Tsiplakis | [GitHub](https://github.com/johnnnathan) \| [LinkedIn](https://www.linkedin.com/in/dimitris-tsiplakis-4b0b15359) \| johnnnathan@proton.me |


# Notes

When talking about specifics of assembly, and the ISA is not specified assume that it is x86-64. In the first few chapters we specify it, but this is not the case in further chapters.