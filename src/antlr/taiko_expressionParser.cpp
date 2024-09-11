
// Generated from taiko_expression.g4 by ANTLR 4.13.2


#include "taiko_expressionListener.h"

#include "taiko_expressionParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct Taiko_expressionParserStaticData final {
  Taiko_expressionParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  Taiko_expressionParserStaticData(const Taiko_expressionParserStaticData&) = delete;
  Taiko_expressionParserStaticData(Taiko_expressionParserStaticData&&) = delete;
  Taiko_expressionParserStaticData& operator=(const Taiko_expressionParserStaticData&) = delete;
  Taiko_expressionParserStaticData& operator=(Taiko_expressionParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag taiko_expressionParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<Taiko_expressionParserStaticData> taiko_expressionParserStaticData = nullptr;

void taiko_expressionParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (taiko_expressionParserStaticData != nullptr) {
    return;
  }
#else
  assert(taiko_expressionParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<Taiko_expressionParserStaticData>(
    std::vector<std::string>{
      "expression", "expr", "term", "factor"
    },
    std::vector<std::string>{
      "", "", "", "", "'true'", "'false'", "'||'", "'&&'", "'!'", "'=='", 
      "'!='", "'>'", "'<'", "'>='", "'<='", "'<=>'", "'+'", "'-'", "'*'", 
      "'/'", "'^'", "'%'", "'('", "')'", "'['", "']'", "'{'", "'}'", "'@'"
    },
    std::vector<std::string>{
      "", "NAME", "NUMBER", "STRING", "TRUE", "FALSE", "OR", "AND", "NOT", 
      "EQUAL", "NOT_EQUAL", "GREATER", "LESS", "GREATER_EQUAL", "LESS_EQUAL", 
      "SPACESHIP", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "POWER", "MODULO", 
      "OPEN_PAREN", "CLOSE_PAREN", "OPEN_BRACKET", "CLOSE_BRACKET", "OPEN_BRACE", 
      "CLOSE_BRACE", "AT", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,29,44,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,1,0,1,0,3,0,11,8,0,1,1,1,1,
  	1,1,1,1,1,1,1,1,5,1,19,8,1,10,1,12,1,22,9,1,1,2,1,2,1,2,1,2,1,2,1,2,5,
  	2,30,8,2,10,2,12,2,33,9,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,3,3,42,8,3,1,3,
  	0,2,2,4,4,0,2,4,6,0,2,1,0,16,17,1,0,18,19,44,0,10,1,0,0,0,2,12,1,0,0,
  	0,4,23,1,0,0,0,6,41,1,0,0,0,8,11,5,2,0,0,9,11,3,2,1,0,10,8,1,0,0,0,10,
  	9,1,0,0,0,11,1,1,0,0,0,12,13,6,1,-1,0,13,14,3,4,2,0,14,20,1,0,0,0,15,
  	16,10,2,0,0,16,17,7,0,0,0,17,19,3,4,2,0,18,15,1,0,0,0,19,22,1,0,0,0,20,
  	18,1,0,0,0,20,21,1,0,0,0,21,3,1,0,0,0,22,20,1,0,0,0,23,24,6,2,-1,0,24,
  	25,3,6,3,0,25,31,1,0,0,0,26,27,10,2,0,0,27,28,7,1,0,0,28,30,3,6,3,0,29,
  	26,1,0,0,0,30,33,1,0,0,0,31,29,1,0,0,0,31,32,1,0,0,0,32,5,1,0,0,0,33,
  	31,1,0,0,0,34,35,5,22,0,0,35,36,3,2,1,0,36,37,5,23,0,0,37,42,1,0,0,0,
  	38,39,5,17,0,0,39,42,3,6,3,0,40,42,5,2,0,0,41,34,1,0,0,0,41,38,1,0,0,
  	0,41,40,1,0,0,0,42,7,1,0,0,0,4,10,20,31,41
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  taiko_expressionParserStaticData = std::move(staticData);
}

}

taiko_expressionParser::taiko_expressionParser(TokenStream *input) : taiko_expressionParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

taiko_expressionParser::taiko_expressionParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  taiko_expressionParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *taiko_expressionParserStaticData->atn, taiko_expressionParserStaticData->decisionToDFA, taiko_expressionParserStaticData->sharedContextCache, options);
}

taiko_expressionParser::~taiko_expressionParser() {
  delete _interpreter;
}

const atn::ATN& taiko_expressionParser::getATN() const {
  return *taiko_expressionParserStaticData->atn;
}

std::string taiko_expressionParser::getGrammarFileName() const {
  return "taiko_expression.g4";
}

const std::vector<std::string>& taiko_expressionParser::getRuleNames() const {
  return taiko_expressionParserStaticData->ruleNames;
}

const dfa::Vocabulary& taiko_expressionParser::getVocabulary() const {
  return taiko_expressionParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView taiko_expressionParser::getSerializedATN() const {
  return taiko_expressionParserStaticData->serializedATN;
}


//----------------- ExpressionContext ------------------------------------------------------------------

taiko_expressionParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* taiko_expressionParser::ExpressionContext::NUMBER() {
  return getToken(taiko_expressionParser::NUMBER, 0);
}

taiko_expressionParser::ExprContext* taiko_expressionParser::ExpressionContext::expr() {
  return getRuleContext<taiko_expressionParser::ExprContext>(0);
}


size_t taiko_expressionParser::ExpressionContext::getRuleIndex() const {
  return taiko_expressionParser::RuleExpression;
}

void taiko_expressionParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<taiko_expressionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void taiko_expressionParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<taiko_expressionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}

taiko_expressionParser::ExpressionContext* taiko_expressionParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 0, taiko_expressionParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(10);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(8);
      match(taiko_expressionParser::NUMBER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(9);
      expr(0);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

taiko_expressionParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

taiko_expressionParser::TermContext* taiko_expressionParser::ExprContext::term() {
  return getRuleContext<taiko_expressionParser::TermContext>(0);
}

taiko_expressionParser::ExprContext* taiko_expressionParser::ExprContext::expr() {
  return getRuleContext<taiko_expressionParser::ExprContext>(0);
}

tree::TerminalNode* taiko_expressionParser::ExprContext::PLUS() {
  return getToken(taiko_expressionParser::PLUS, 0);
}

tree::TerminalNode* taiko_expressionParser::ExprContext::MINUS() {
  return getToken(taiko_expressionParser::MINUS, 0);
}


size_t taiko_expressionParser::ExprContext::getRuleIndex() const {
  return taiko_expressionParser::RuleExpr;
}

void taiko_expressionParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<taiko_expressionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void taiko_expressionParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<taiko_expressionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


taiko_expressionParser::ExprContext* taiko_expressionParser::expr() {
   return expr(0);
}

taiko_expressionParser::ExprContext* taiko_expressionParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  taiko_expressionParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  taiko_expressionParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, taiko_expressionParser::RuleExpr, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(13);
    term(0);
    _ctx->stop = _input->LT(-1);
    setState(20);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpr);
        setState(15);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(16);
        _la = _input->LA(1);
        if (!(_la == taiko_expressionParser::PLUS

        || _la == taiko_expressionParser::MINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(17);
        term(0); 
      }
      setState(22);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

taiko_expressionParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

taiko_expressionParser::FactorContext* taiko_expressionParser::TermContext::factor() {
  return getRuleContext<taiko_expressionParser::FactorContext>(0);
}

taiko_expressionParser::TermContext* taiko_expressionParser::TermContext::term() {
  return getRuleContext<taiko_expressionParser::TermContext>(0);
}

tree::TerminalNode* taiko_expressionParser::TermContext::MULTIPLY() {
  return getToken(taiko_expressionParser::MULTIPLY, 0);
}

tree::TerminalNode* taiko_expressionParser::TermContext::DIVIDE() {
  return getToken(taiko_expressionParser::DIVIDE, 0);
}


size_t taiko_expressionParser::TermContext::getRuleIndex() const {
  return taiko_expressionParser::RuleTerm;
}

void taiko_expressionParser::TermContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<taiko_expressionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerm(this);
}

void taiko_expressionParser::TermContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<taiko_expressionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerm(this);
}


taiko_expressionParser::TermContext* taiko_expressionParser::term() {
   return term(0);
}

taiko_expressionParser::TermContext* taiko_expressionParser::term(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  taiko_expressionParser::TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, parentState);
  taiko_expressionParser::TermContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, taiko_expressionParser::RuleTerm, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(24);
    factor();
    _ctx->stop = _input->LT(-1);
    setState(31);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TermContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleTerm);
        setState(26);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(27);
        _la = _input->LA(1);
        if (!(_la == taiko_expressionParser::MULTIPLY

        || _la == taiko_expressionParser::DIVIDE)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(28);
        factor(); 
      }
      setState(33);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

taiko_expressionParser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* taiko_expressionParser::FactorContext::OPEN_PAREN() {
  return getToken(taiko_expressionParser::OPEN_PAREN, 0);
}

taiko_expressionParser::ExprContext* taiko_expressionParser::FactorContext::expr() {
  return getRuleContext<taiko_expressionParser::ExprContext>(0);
}

tree::TerminalNode* taiko_expressionParser::FactorContext::CLOSE_PAREN() {
  return getToken(taiko_expressionParser::CLOSE_PAREN, 0);
}

tree::TerminalNode* taiko_expressionParser::FactorContext::MINUS() {
  return getToken(taiko_expressionParser::MINUS, 0);
}

taiko_expressionParser::FactorContext* taiko_expressionParser::FactorContext::factor() {
  return getRuleContext<taiko_expressionParser::FactorContext>(0);
}

tree::TerminalNode* taiko_expressionParser::FactorContext::NUMBER() {
  return getToken(taiko_expressionParser::NUMBER, 0);
}


size_t taiko_expressionParser::FactorContext::getRuleIndex() const {
  return taiko_expressionParser::RuleFactor;
}

void taiko_expressionParser::FactorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<taiko_expressionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFactor(this);
}

void taiko_expressionParser::FactorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<taiko_expressionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFactor(this);
}

taiko_expressionParser::FactorContext* taiko_expressionParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 6, taiko_expressionParser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(41);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case taiko_expressionParser::OPEN_PAREN: {
        enterOuterAlt(_localctx, 1);
        setState(34);
        match(taiko_expressionParser::OPEN_PAREN);
        setState(35);
        expr(0);
        setState(36);
        match(taiko_expressionParser::CLOSE_PAREN);
        break;
      }

      case taiko_expressionParser::MINUS: {
        enterOuterAlt(_localctx, 2);
        setState(38);
        match(taiko_expressionParser::MINUS);
        setState(39);
        factor();
        break;
      }

      case taiko_expressionParser::NUMBER: {
        enterOuterAlt(_localctx, 3);
        setState(40);
        match(taiko_expressionParser::NUMBER);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool taiko_expressionParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);
    case 2: return termSempred(antlrcpp::downCast<TermContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool taiko_expressionParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool taiko_expressionParser::termSempred(TermContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void taiko_expressionParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  taiko_expressionParserInitialize();
#else
  ::antlr4::internal::call_once(taiko_expressionParserOnceFlag, taiko_expressionParserInitialize);
#endif
}
