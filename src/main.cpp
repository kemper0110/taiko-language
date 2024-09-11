#include <iostream>
#include <fstream>
#include <any>
#include <map>
#include <variant>
#include <string>
#include <spanstream>
#include <span>
#include "ClassFile/bytecode.h"
#include "ClassFile/ClassFile.h"
#include "ClassFile/CodeAttribute.h"
#include "Expression/compileToString.h"
#include "Expression/compileToBytecode.h"

#include "antlr4-runtime.h"
#include "antlr/taiko_expressionLexer.h"
#include "antlr/taiko_expressionParser.h"


int main() {

    std::ifstream stream;
    stream.open(argv[1]);
    ANTLRInputStream input(stream);
    taiko_expressionLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    taiko_expressionParser parser(&tokens);

    tree::ParseTree *tree = parser.key();
    TreeShapeListener listener;
    tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);



    const std::string prefix = "C:\\Users\\Danil\\IdeaProjects\\compile-java\\target\\classes\\org\\danil\\";


//    auto input = std::ifstream(prefix + "Expression.class", std::ios::binary);
//    if(!input) {
//        std::cout << "file can't be opened\n";
//        return 1;
//    }
//
//    const auto cf = ClassFile::fromStream(input);
//
//    const auto code_id = distance(cf.constant_pool.begin(), std::find_if(cf.constant_pool.begin(), cf.constant_pool.end(), [](const cp_info &info) {
//        const auto string = get_if<utf8_info>(&info);
//        return string && string->str == "Code";
//    })) + 1;
//
//    for (const auto &method : cf.methods) {
//        const auto bytes = std::find_if(method.attributes.begin(), method.attributes.end(), [code_id](const attribute_info &info) {
//            return info.attribute_name_index == code_id;
//        })->info;
//        std::span<char> span((char*)bytes.data(), bytes.size());
//        std::ispanstream bytecode(span, std::ios::in | std::ios::binary);
//
//        const auto code_attribute = Code_attribute::fromStream(bytecode);
//
//        for(auto byte : code_attribute.code) {
//            switch((opcode)byte) {
//                case opcode::bipush:
//                    std::cout << "bipush\n";
//                    break;
//                case opcode::iload_0:
//                    std::cout << "iload_0\n";
//                    break;
//                case opcode::iload_1:
//                    std::cout << "iload_1\n";
//                    break;
//                case opcode::iload_2:
//                    std::cout << "iload_2\n";
//                    break;
//                case opcode::iload_3:
//                    std::cout << "iload_3\n";
//                    break;
//                case opcode::iadd:
//                    std::cout << "iadd\n";
//                    break;
//                case opcode::imull:
//                    std::cout << "imull\n";
//                    break;
//                case opcode::iconst_1:
//                    std::cout << "iconst_1\n";
//                    break;
//                case opcode::iconst_5:
//                    std::cout << "iconst_5\n";
//                    break;
//                case opcode::ireturn:
//                    std::cout << "ireturn\n";
//                    break;
//                default:
//                    std::cout << "unknown opcode " << std::hex << (int) byte << "\n";
//                    break;
//            }
//        }
//    }


//
//    auto start = new char[0xe2];
//    input.read(start, 0xe2);
//
//    auto initial_bytecode = new char[4 + 6];
//    input.read(initial_bytecode, 4 + 6);
//
//    auto end = new char[26];
//    input.read(end, 26);
//
//    auto output = std::ofstream(
//            prefix + "Expr2.class",
//            std::ios::binary | std::ios::trunc);
//    if (!output) {
//        std::cout << "file can't be opened\n";
//        std::exit(1);
//    }
//
//    output.write(start, 0xe2);
//
//
//    const auto expression_tokens = std::vector<token>{
//            Argument{1}, Plus{}, Number{5}, Plus{}, Number{2}, Mul{}, Number{3}, Mul{}, Argument{2},
//    };
//
//    auto bytecode = compileToBytecode(expression_tokens);
//    bytecode.push_back(opcode::ireturn);
//    const auto str = compileToString(expression_tokens);
//    std::cout << str << "\n";
//
//    const u4 len = swap_endian((u4) bytecode.size());
//    output.write(reinterpret_cast<const char *>(&len), 4);
//    output.write(reinterpret_cast<const char *>(bytecode.data()), bytecode.size());
//    output.write(end, 26);
//
    return 0;
}
