cmake_minimum_required(VERSION 3.28)
project(parse_bytecode)

set(CMAKE_CXX_STANDARD 23)

include_directories(include)
add_executable(parse_bytecode src/main.cpp
        src/utils.cpp
        src/ClassFile/bytecode.cpp
        src/ClassFile/ClassFile.cpp
        src/ClassFile/ConstantPool.cpp
        src/ClassFile/FieldInfo.cpp
        src/ClassFile/MethodInfo.cpp
        src/ClassFile/AttributeInfo.cpp
        src/ClassFile/CodeAttribute.cpp
        src/Expression/ExpressionCompiler.cpp
        src/Expression/StringExpressionCompiler.cpp
        src/Expression/BytecodeExpressionCompiler.cpp
        src/Expression/compileToString.cpp
        src/Expression/compileToBytecode.cpp
        src/antlr/taiko_expressionLexer.cpp
        src/antlr/taiko_expressionParser.cpp
        src/antlr/taiko_expressionBaseListener.cpp
        src/antlr/taiko_expressionListener.cpp
)
