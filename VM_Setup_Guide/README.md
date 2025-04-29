Virtual Machines are the best way to handle custom environments without the need for multiple OSes under a single system (which is difficult to maintain), or multiple systems (which is quite expensive). 

## Prerequisites

There are two main components to hosting a VM.
1. The VM manager
2. The .iso file of the operating system we wish to emulate

## Virtual Machine Manager Choice

For most people [VirtualBox](https://www.virtualbox.org/) will be more than enough feature wise, and it is free. The installation process is simple and the usage of the application is too.


## Operating System Choice

Windows and OSX are both rarely used in this field. The choice pool excludes them and our focus is on the linux family. Kali Linux is advertised as a great choice, but it contains a lot of tools that will be useless to the vast majority of users. We prefer distributions of the Debian family and specifically Ubuntu, although this might change, because they are lightweight, versatile and can be customized extensively. The Ubuntu .iso file can be found online [here](https://ubuntu.com/download). The server version can be downloaded and a custom desktop environment created from there, but I have not done that before and don't know the difficulties and implications that come with it.


## Creating a VM

After downloading VirtualBox and the Ubuntu .iso you are ready to create your first VM. Open the VirtualBox application and Click on "New". The application does a good job at guiding you through the necessary steps. Be sure to give the Machine enough cores and space, because performance will suffer with the bare minimum. I recommend giving it at least 25 Gigabytes and half the available cores and RAM. You can now press "Start" in the menu to start your VM.

## Installing the OS

We are not ready yet. We have added the OS to the VM but not installed it yet. Luckily the process is also simple, and the system itself does most of the work. The Ubuntu OS will ask you if you want to install it or keep trying it. Follow along with its directions to install it, and input the appropriate data where it is required. When creating a user make sure to have a simple name and password. This goes contrary to the teachings of Computer Security but assuming that you don't store any personal information on the VM, a long password will just frustrate you, as it is requested each time you ask for sudo privileges in a terminal. The system will install a lot of packages and this might take a while if you have a slow internet connection. 

## Post-Installation

You will be asked to restart your VM and log in, you will now be able to use Ubuntu to its full potential. Go to the [Tools](https://github.com/MaaSecLab/Tools) repository of the MaaSecLab Github account and download the tools-maasec.sh script. Follow the steps detailed in the README file and allow the installer to finish executing. You will now be able to start your CTF journey. Go to TryHackMe and HackTheBox and make an account. You are now ready. 

Happy Hacking!


## Notes 

You might need to manually add the Ubuntu Image to the VM instance in VirtualBox. This is done by selecting the instance in the VirtualBox menu and clicking on "Settings", then going to "Storage" and selecting the entry under "Controller: IDE". Then on the right side of the screen you will see a disc with an arrow next to it. Click on the "Choose a Disk file" submenu and select the Ubuntu .iso file.

Have a great day :)
github.com/johnnnathan
