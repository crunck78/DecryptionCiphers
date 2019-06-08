LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_CPP_EXTENSION := .cpp .cc

LOCAL_SRC_FILES = main.cpp class/Decryptor/Decryptor.cpp class/CaesarCipher/CaesarCipher.cpp class/PolyalphabeticCipher/PolyalphabeticCipher.cpp class/PolybiusSquare/PolybiusSquare.cpp class/Clue4Cipher/Clue4Cipher.cpp class/Fibonacci/Fibonacci.cpp class/FileReader/FileReader.cpp class/FileWriter/FileWriter.cpp class/Menu/Menu.cpp

LOCAL_MODULE := main

LOCAL_CPP_FEATURES += exceptions 

ifeq ($(TARGET_ARCH_ABI),x86)
    LOCAL_CFLAGS += -ffast-math -mtune=atom -mssse3 -mfpmath=sse
endif

include $(BUILD_EXECUTABLE)
