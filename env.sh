export CC=gcc
export CC_FLAGS="$(llvm-config --cflags)"
export CC_LINK_FLAGS="$(llvm-config --ldflags --libs all) -lpthread -ldl -lm -lstdc++"
