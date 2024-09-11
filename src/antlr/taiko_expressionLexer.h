
// Generated from taiko_expression.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  taiko_expressionLexer : public antlr4::Lexer {
public:
  enum {
    NAME = 1, NUMBER = 2, STRING = 3, TRUE = 4, FALSE = 5, OR = 6, AND = 7, 
    NOT = 8, EQUAL = 9, NOT_EQUAL = 10, GREATER = 11, LESS = 12, GREATER_EQUAL = 13, 
    LESS_EQUAL = 14, SPACESHIP = 15, PLUS = 16, MINUS = 17, MULTIPLY = 18, 
    DIVIDE = 19, POWER = 20, MODULO = 21, OPEN_PAREN = 22, CLOSE_PAREN = 23, 
    OPEN_BRACKET = 24, CLOSE_BRACKET = 25, OPEN_BRACE = 26, CLOSE_BRACE = 27, 
    AT = 28, WS = 29
  };

  explicit taiko_expressionLexer(antlr4::CharStream *input);

  ~taiko_expressionLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

