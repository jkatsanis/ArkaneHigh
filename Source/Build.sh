#!/bin/bash
# Set your compiler and compiler flags
BUILD_TYPE=$1
CXX="x86_64-elf-gcc"
CXXFLAGS="-ffreestanding -c -nostdlib"
OUTPUT_DIR="../Bin/$BUILD_TYPE"
INCLUDE_PATHS="-IKernel/Standard 
               -IKernel/Standard/String 
               -IKernel/Data 
               -IKernel/TextRenderer 
               -IKernel/Driver/Interrupts
               -IKernel/Driver/Keyboard
               -IPrograms"

# Colors
GREEN='\033[0;32m'              # Green text
RED='\033[0;31m'                # Red text
NC='\033[0m'                    # No color (reset)

echo "==================="
echo "Build started, you are compiling for $BUILD_TYPE..."

build_status=1
echo "$build_status" > build_error.txt

# Compile all .cpp files found in the Source directory and its subdirectories
find Kernel Programs -name "*.cpp" -print0 | while IFS= read -r -d $'\0' source_file; do
    base_name=$(basename -- "$source_file")
    object_file="${base_name%.cpp}.o"

    if [ "$BUILD_TYPE" = "Release" ]; then
        $CXX $CXXFLAGS $INCLUDE_PATHS "$source_file" -o $OUTPUT_DIR/$object_file
    elif [ "$BUILD_TYPE" = "Debug" ]; then
        $CXX $CXXFLAGS $INCLUDE_PATHS -g "$source_file" -o $OUTPUT_DIR/$object_file
    fi

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
rm build_error.txt