
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


# Compilation

When source code is written by a programmer (or LLM), the computer is not able to parse the 













# Contact Us


| Name                | Social-Media HyperLinks                                                                                                                   |
| ------------------- | ----------------------------------------------------------------------------------------------------------------------------------------- |
| Dimitrios Tsiplakis | [GitHub](https://github.com/johnnnathan) \| [LinkedIn](https://www.linkedin.com/in/dimitris-tsiplakis-4b0b15359) \| johnnnathan@proton.me |
