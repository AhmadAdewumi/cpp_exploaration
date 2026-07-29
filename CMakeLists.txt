cmake_minimum_required(VERSION 4.1)
project(C_projects)

set(CMAKE_CXX_STANDARD 20)

add_executable(C_projects PQs/schoolStuffs/main.cpp
        learnCpp/PrintStandard.cpp
        learnCpp/practice.cpp
        learnCpp/MultiplicationCalculator.cpp
        learnCpp/chapter1/SimpleCalc.cpp
        learnCpp/chapter1/SecConv.cpp
        learnCpp/chapter2/functions.cpp
        learnCpp/chapter2/calculatorValidation.cpp
        learnCpp/chapter4/dt.cpp
        learnCpp/chapter4/isPrime.cpp
        learnCpp/chapter4/burrito.cpp
        learnCpp/chapter4/printASCII.cpp
        learnCpp/chapter4/data_type_explorer/main.cpp
        learnCpp/chapter4/data_type_explorer/data_types.cpp
        learnCpp/chapter4/data_type_explorer/io.cpp
        learnCpp/chapter4/data_type_explorer/io.h
        learnCpp/chapter4/data_type_explorer/data_types.h
        learnCpp/chapter5/stringStuff.cpp
        learnCpp/chapter5/decoder.cpp
        learnCpp/chapter6/quantityPhrases.cpp
        learnCpp/chapter00/permissions.cpp)
