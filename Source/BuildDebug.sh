#!/bin/bash

# Set your compiler and compiler flags
CXX=i686-elf-g++
CXXFLAGS="-ffreestanding -g -c -nostdlib"
DEBUG_DIR="../Bin/Debug"

GREEN='\033[0;32m'  # Green text
RED='\033[0;31m'  # Red text
NC='\033[0m'        # No color (reset)

echo "==================="
echo "Build started..."

build_status=1
echo "$build_status" > build_error.txt

# Compile all .cpp files found in the Source directory and its subdirectories
# Loop over all regular .cpp files
find Kernel -name "*.cpp" -print0 | while IFS= read -r -d $'\0' source_file; do
    base_name=$(basename -- "$source_file")
    object_file="${base_name%.cpp}.o"

    $CXX $CXXFLAGS "$source_file" -o $DEBUG_DIR/$object_file

    if [ $? -ne 0 ]; then
        echo -e "${RED} Error compiling: $base_name${NC}"
        build_status=2
        echo "$build_status" > build_error.txt
    else
        echo -e "${GREEN} Compiling: $base_name${NC}"
    fi
done

build_status_file=$(cat build_error.txt)

if [ "$build_status_file" -eq 2 ]; then
    echo -e "${RED} CPPBuild completed with errors!${NC}"
else
    echo -e "${GREEN} CPPBuild completed successfully!${NC}"
fi
echo "==================="

o_files=$DEBUG_DIR/*.o

echo "Linking Kernel.. i686-elf-ld -r -o $DEBUG_DIR/Kernel.o" $o_files 

i686-elf-ld -r -o $DEBUG_DIR/Kernel.o $DEBUG_DIR/*.o

if [ $? -ne 0 ]; then
    echo -e "${RED} Linking failed!${NC}"
    exit 1
else
    echo -e "${GREEN} Linking completed successfully!${NC}"
fi


echo "==================="

rm build_error.txt