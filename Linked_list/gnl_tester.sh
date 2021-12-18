#!/bin/bash
echo -e "\033[32;1m"NORM"\033[m"
read $a
norminette ./*.c ./*.h
echo -e "\033[32;1m"gnlTester"\033[m"
read $a
git clone https://github.com/Tripouille/gnlTester.git
cd gnlTester/
make b
cd ..
echo -e "\033[32;1m"gnl_difflen_multi_fd_Tester"\033[m"
read $a
git clone git@github.com:kohkubo/gnl_tester.git
cd gnl_tester/
zsh test.sh
cd ..
rm -rf gnlTester/
rm -rf gnl_tester/
echo -e "\033[32;1m"DONE"\033[m"
