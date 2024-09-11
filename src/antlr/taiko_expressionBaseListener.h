
// Generated from taiko_expression.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "taiko_expressionListener.h"


/**
 * This class provides an empty implementation of taiko_expressionListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  taiko_expressionBaseListener : public taiko_expressionListener {
public:

  virtual void enterExpression(taiko_expressionParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(taiko_expressionParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterExpr(taiko_expressionParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(taiko_expressionParser::ExprContext * /*ctx*/) override { }

  virtual void enterTerm(taiko_expressionParser::TermContext * /*ctx*/) override { }
  virtual void exitTerm(taiko_expressionParser::TermContext * /*ctx*/) override { }

  virtual void enterFactor(taiko_expressionParser::FactorContext * /*ctx*/) override { }
  virtual void exitFactor(taiko_expressionParser::FactorContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

