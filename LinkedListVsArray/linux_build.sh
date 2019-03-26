mkdir -p ../build/LinkedListIsBad/linux/
time clang $1 $(< flags_linux.txt) -o ../build/LinkedListIsBad/linux/$2
