
// Generated from taiko_expression.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  taiko_expressionParser : public antlr4::Parser {
public:
  enum {
    NAME = 1, NUMBER = 2, STRING = 3, TRUE = 4, FALSE = 5, OR = 6, AND = 7, 
    NOT = 8, EQUAL = 9, NOT_EQUAL = 10, GREATER = 11, LESS = 12, GREATER_EQUAL = 13, 
    LESS_EQUAL = 14, SPACESHIP = 15, PLUS = 16, MINUS = 17, MULTIPLY = 18, 
    DIVIDE = 19, POWER = 20, MODULO = 21, OPEN_PAREN = 22, CLOSE_PAREN = 23, 
    OPEN_BRACKET = 24, CLOSE_BRACKET = 25, OPEN_BRACE = 26, CLOSE_BRACE = 27, 
    AT = 28, WS = 29
  };

  enum {
    RuleExpression = 0, RuleExpr = 1, RuleTerm = 2, RuleFactor = 3
  };

  explicit taiko_expressionParser(antlr4::TokenStream *input);

  taiko_expressionParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~taiko_expressionParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ExpressionContext;
  class ExprContext;
  class TermContext;
  class FactorContext; 

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBER();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExpressionContext* expression();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TermContext *term();
    ExprContext *expr();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExprContext* expr();
  ExprContext* expr(int precedence);
  class  TermContext : public antlr4::ParserRuleContext {
  public:
    TermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FactorContext *factor();
    TermContext *term();
    antlr4::tree::TerminalNode *MULTIPLY();
    antlr4::tree::TerminalNode *DIVIDE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TermContext* term();
  TermContext* term(int precedence);
  class  FactorContext : public antlr4::ParserRuleContext {
  public:
    FactorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPEN_PAREN();
    ExprContext *expr();
    antlr4::tree::TerminalNode *CLOSE_PAREN();
    antlr4::tree::TerminalNode *MINUS();
    FactorContext *factor();
    antlr4::tree::TerminalNode *NUMBER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FactorContext* factor();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool exprSempred(ExprContext *_localctx, size_t predicateIndex);
  bool termSempred(TermContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

