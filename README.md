# simple_parser
Simple Parser


#Parser for grammar:
<non-zero-digit>         ::= 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
<letter>                 ::= A | B | C | x | y | z
<group>                  ::= <letter> | <letter><group>
<variable-identifier>    ::= <non-zero-digit><group>
