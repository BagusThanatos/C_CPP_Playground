mkdir -p build/linux/
clang $1 $(< flags_linux.txt) -o build/linux/$2