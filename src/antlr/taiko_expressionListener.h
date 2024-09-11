
// Generated from taiko_expression.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "taiko_expressionParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by taiko_expressionParser.
 */
class  taiko_expressionListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterExpression(taiko_expressionParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(taiko_expressionParser::ExpressionContext *ctx) = 0;

  virtual void enterExpr(taiko_expressionParser::ExprContext *ctx) = 0;
  virtual void exitExpr(taiko_expressionParser::ExprContext *ctx) = 0;

  virtual void enterTerm(taiko_expressionParser::TermContext *ctx) = 0;
  virtual void exitTerm(taiko_expressionParser::TermContext *ctx) = 0;

  virtual void enterFactor(taiko_expressionParser::FactorContext *ctx) = 0;
  virtual void exitFactor(taiko_expressionParser::FactorContext *ctx) = 0;


};

