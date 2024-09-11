grammar taiko_expression;

expression
    : NUMBER
    | expr
    ;

expr: expr (PLUS | MINUS) term
    | term
    ;

term: term (MULTIPLY | DIVIDE) factor
    | factor
    ;

factor: OPEN_PAREN expr CLOSE_PAREN
      | MINUS factor
      | NUMBER
      ;

//methodCall
//    : methodName '(' methodCallArguments ')'
//    ;
//
//methodName
//    : NAME
//    ;
//
//methodCallArguments
//    : // No arguments
//    | expression (',' expression)*  // Some arguments
//    ;

NAME: [a-zA-Z][a-zA-Z0-9]*;

NUMBER: [0-9]+ ('.' [0-9]+)?;

STRING: '"' ~('"')* '"';

TRUE: 'true';

FALSE: 'false';

OR: '||';

AND: '&&';

NOT: '!';

EQUAL: '==';

NOT_EQUAL: '!=';

GREATER: '>';

LESS: '<';

GREATER_EQUAL: '>=';

LESS_EQUAL: '<=';

SPACESHIP: '<=>';

PLUS: '+';

MINUS: '-';

MULTIPLY: '*';

DIVIDE: '/';

POWER: '^';

MODULO: '%';

OPEN_PAREN: '(';

CLOSE_PAREN: ')';

OPEN_BRACKET: '[';

CLOSE_BRACKET: ']';

OPEN_BRACE: '{';

CLOSE_BRACE: '}';

AT: '@';

WS: [ \t\u000C\r\n]+ -> skip;