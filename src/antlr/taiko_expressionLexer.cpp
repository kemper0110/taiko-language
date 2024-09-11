
// Generated from taiko_expression.g4 by ANTLR 4.13.2


#include "taiko_expressionLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct Taiko_expressionLexerStaticData final {
  Taiko_expressionLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  Taiko_expressionLexerStaticData(const Taiko_expressionLexerStaticData&) = delete;
  Taiko_expressionLexerStaticData(Taiko_expressionLexerStaticData&&) = delete;
  Taiko_expressionLexerStaticData& operator=(const Taiko_expressionLexerStaticData&) = delete;
  Taiko_expressionLexerStaticData& operator=(Taiko_expressionLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag taiko_expressionlexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<Taiko_expressionLexerStaticData> taiko_expressionlexerLexerStaticData = nullptr;

void taiko_expressionlexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (taiko_expressionlexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(taiko_expressionlexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<Taiko_expressionLexerStaticData>(
    std::vector<std::string>{
      "NAME", "NUMBER", "STRING", "TRUE", "FALSE", "OR", "AND", "NOT", "EQUAL", 
      "NOT_EQUAL", "GREATER", "LESS", "GREATER_EQUAL", "LESS_EQUAL", "SPACESHIP", 
      "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "POWER", "MODULO", "OPEN_PAREN", 
      "CLOSE_PAREN", "OPEN_BRACKET", "CLOSE_BRACKET", "OPEN_BRACE", "CLOSE_BRACE", 
      "AT", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,29,160,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,1,0,1,0,5,0,62,8,0,10,0,12,0,65,9,0,1,1,4,1,68,8,1,11,1,12,1,69,
  	1,1,1,1,4,1,74,8,1,11,1,12,1,75,3,1,78,8,1,1,2,1,2,5,2,82,8,2,10,2,12,
  	2,85,9,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,4,1,5,1,5,
  	1,5,1,6,1,6,1,6,1,7,1,7,1,8,1,8,1,8,1,9,1,9,1,9,1,10,1,10,1,11,1,11,1,
  	12,1,12,1,12,1,13,1,13,1,13,1,14,1,14,1,14,1,14,1,15,1,15,1,16,1,16,1,
  	17,1,17,1,18,1,18,1,19,1,19,1,20,1,20,1,21,1,21,1,22,1,22,1,23,1,23,1,
  	24,1,24,1,25,1,25,1,26,1,26,1,27,1,27,1,28,4,28,155,8,28,11,28,12,28,
  	156,1,28,1,28,0,0,29,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,
  	11,23,12,25,13,27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,
  	45,23,47,24,49,25,51,26,53,27,55,28,57,29,1,0,5,2,0,65,90,97,122,3,0,
  	48,57,65,90,97,122,1,0,48,57,1,0,34,34,3,0,9,10,12,13,32,32,165,0,1,1,
  	0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,
  	13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,
  	0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,
  	0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,
  	45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,
  	0,0,0,0,57,1,0,0,0,1,59,1,0,0,0,3,67,1,0,0,0,5,79,1,0,0,0,7,88,1,0,0,
  	0,9,93,1,0,0,0,11,99,1,0,0,0,13,102,1,0,0,0,15,105,1,0,0,0,17,107,1,0,
  	0,0,19,110,1,0,0,0,21,113,1,0,0,0,23,115,1,0,0,0,25,117,1,0,0,0,27,120,
  	1,0,0,0,29,123,1,0,0,0,31,127,1,0,0,0,33,129,1,0,0,0,35,131,1,0,0,0,37,
  	133,1,0,0,0,39,135,1,0,0,0,41,137,1,0,0,0,43,139,1,0,0,0,45,141,1,0,0,
  	0,47,143,1,0,0,0,49,145,1,0,0,0,51,147,1,0,0,0,53,149,1,0,0,0,55,151,
  	1,0,0,0,57,154,1,0,0,0,59,63,7,0,0,0,60,62,7,1,0,0,61,60,1,0,0,0,62,65,
  	1,0,0,0,63,61,1,0,0,0,63,64,1,0,0,0,64,2,1,0,0,0,65,63,1,0,0,0,66,68,
  	7,2,0,0,67,66,1,0,0,0,68,69,1,0,0,0,69,67,1,0,0,0,69,70,1,0,0,0,70,77,
  	1,0,0,0,71,73,5,46,0,0,72,74,7,2,0,0,73,72,1,0,0,0,74,75,1,0,0,0,75,73,
  	1,0,0,0,75,76,1,0,0,0,76,78,1,0,0,0,77,71,1,0,0,0,77,78,1,0,0,0,78,4,
  	1,0,0,0,79,83,5,34,0,0,80,82,8,3,0,0,81,80,1,0,0,0,82,85,1,0,0,0,83,81,
  	1,0,0,0,83,84,1,0,0,0,84,86,1,0,0,0,85,83,1,0,0,0,86,87,5,34,0,0,87,6,
  	1,0,0,0,88,89,5,116,0,0,89,90,5,114,0,0,90,91,5,117,0,0,91,92,5,101,0,
  	0,92,8,1,0,0,0,93,94,5,102,0,0,94,95,5,97,0,0,95,96,5,108,0,0,96,97,5,
  	115,0,0,97,98,5,101,0,0,98,10,1,0,0,0,99,100,5,124,0,0,100,101,5,124,
  	0,0,101,12,1,0,0,0,102,103,5,38,0,0,103,104,5,38,0,0,104,14,1,0,0,0,105,
  	106,5,33,0,0,106,16,1,0,0,0,107,108,5,61,0,0,108,109,5,61,0,0,109,18,
  	1,0,0,0,110,111,5,33,0,0,111,112,5,61,0,0,112,20,1,0,0,0,113,114,5,62,
  	0,0,114,22,1,0,0,0,115,116,5,60,0,0,116,24,1,0,0,0,117,118,5,62,0,0,118,
  	119,5,61,0,0,119,26,1,0,0,0,120,121,5,60,0,0,121,122,5,61,0,0,122,28,
  	1,0,0,0,123,124,5,60,0,0,124,125,5,61,0,0,125,126,5,62,0,0,126,30,1,0,
  	0,0,127,128,5,43,0,0,128,32,1,0,0,0,129,130,5,45,0,0,130,34,1,0,0,0,131,
  	132,5,42,0,0,132,36,1,0,0,0,133,134,5,47,0,0,134,38,1,0,0,0,135,136,5,
  	94,0,0,136,40,1,0,0,0,137,138,5,37,0,0,138,42,1,0,0,0,139,140,5,40,0,
  	0,140,44,1,0,0,0,141,142,5,41,0,0,142,46,1,0,0,0,143,144,5,91,0,0,144,
  	48,1,0,0,0,145,146,5,93,0,0,146,50,1,0,0,0,147,148,5,123,0,0,148,52,1,
  	0,0,0,149,150,5,125,0,0,150,54,1,0,0,0,151,152,5,64,0,0,152,56,1,0,0,
  	0,153,155,7,4,0,0,154,153,1,0,0,0,155,156,1,0,0,0,156,154,1,0,0,0,156,
  	157,1,0,0,0,157,158,1,0,0,0,158,159,6,28,0,0,159,58,1,0,0,0,7,0,63,69,
  	75,77,83,156,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  taiko_expressionlexerLexerStaticData = std::move(staticData);
}

}

taiko_expressionLexer::taiko_expressionLexer(CharStream *input) : Lexer(input) {
  taiko_expressionLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *taiko_expressionlexerLexerStaticData->atn, taiko_expressionlexerLexerStaticData->decisionToDFA, taiko_expressionlexerLexerStaticData->sharedContextCache);
}

taiko_expressionLexer::~taiko_expressionLexer() {
  delete _interpreter;
}

std::string taiko_expressionLexer::getGrammarFileName() const {
  return "taiko_expression.g4";
}

const std::vector<std::string>& taiko_expressionLexer::getRuleNames() const {
  return taiko_expressionlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& taiko_expressionLexer::getChannelNames() const {
  return taiko_expressionlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& taiko_expressionLexer::getModeNames() const {
  return taiko_expressionlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& taiko_expressionLexer::getVocabulary() const {
  return taiko_expressionlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView taiko_expressionLexer::getSerializedATN() const {
  return taiko_expressionlexerLexerStaticData->serializedATN;
}

const atn::ATN& taiko_expressionLexer::getATN() const {
  return *taiko_expressionlexerLexerStaticData->atn;
}




void taiko_expressionLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  taiko_expressionlexerLexerInitialize();
#else
  ::antlr4::internal::call_once(taiko_expressionlexerLexerOnceFlag, taiko_expressionlexerLexerInitialize);
#endif
}
