cast_expression →
    unary_expression
unary_expression →
    postfix_expression
  | "++" unary_expression
  | "--" unary_expression
  | unary_operator cast_expression
  | "sizeof" unary_expression
postfix_expression →
    primary_expression
  | postfix_expression "[" expression "]"
  | postfix_expression "(" argument_expression_list_opt ")"
  | postfix_expression "." identifier
  | postfix_expression "->" identifier
  | postfix_expression "++"
  | postfix_expression "--"
primary_expression →
    identifier
  | constant
  | string_literal
  | "(" expression ")"
identifier →
    identifier_nondigit
  | identifier identifier_nondigit
  | identifier digit
identifier_nondigit →
    nondigit
  | universal_character_name
nondigit →
    "_"
  | "a"
  | "b"
  | "c"
  | "d"
  | "e"
  | "f"
  | "g"
  | "h"
  | "i"
  | "j"
  | "k"
  | "l"
  | "m"
  | "A"
  | "B"
  | "C"
  | "D"
  | "E"
  | "F"
  | "G"
  | "H"
  | "I"
  | "J"
  | "K"
  | "L"
  | "M"
  | "n"
  | "o"
  | "p"
  | "q"
  | "r"
  | "s"
  | "t"
  | "u"
  | "v"
  | "w"
  | "x"
  | "y"
  | "z"
  | "N"
  | "O"
  | "P"
  | "Q"
  | "R"
  | "S"
  | "T"
  | "U"
  | "V"
  | "W"
  | "X"
  | "Y"
  | "Z"
universal_character_name →
    "\\u" hex_quad
  | "\\U" hex_quad hex_quad
hex_quad →
    hexadecimal_digit hexadecimal_digit hexadecimal_digit hexadecimal_digit
hexadecimal_digit →
    "0"
  | "1"
  | "2"
  | "3"
  | "4"
  | "5"
  | "6"
  | "7"
  | "8"
  | "9"
  | "a"
  | "b"
  | "c"
  | "d"
  | "e"
  | "f"
  | "A"
  | "B"
  | "C"
  | "D"
  | "E"
  | "F"
digit →
    "0"
  | "1"
  | "2"
  | "3"
  | "4"
  | "5"
  | "6"
  | "7"
  | "8"
  | "9"
constant →
    floating_constant
  | character_constant
floating_constant →
    decimal_floating_constant
  | hexadecimal_floating_constant
decimal_floating_constant →
    fractional_constant exponent_part_opt floating_suffix_opt
  | digit_sequence exponent_part floating_suffix_opt
fractional_constant →
    digit_sequence_opt "." digit_sequence
  | digit_sequence "."
digit_sequence_opt →
    digit_sequence
  | ∈
digit_sequence →
    digit
  | digit_sequence digit
exponent_part_opt →
    exponent_part
  | ∈
exponent_part →
    "e" sign_opt digit_sequence
  | "E" sign_opt digit_sequence
sign_opt →
    sign
  | ∈
sign →
    "+"
  | "-"
floating_suffix_opt →
    floating_suffix
  | ∈
floating_suffix →
    "f"
  | "l"
  | "F"
  | "L"
hexadecimal_floating_constant →
    hexadecimal_prefix hexadecimal_fractional_constant binary_exponent_part floating_suffix_opt
  | hexadecimal_prefix hexadecimal_digit_sequence binary_exponent_part floating_suffix_opt
hexadecimal_prefix →
    "0x"
  | "0X"
hexadecimal_fractional_constant →
    hexadecimal_digit_sequence_opt "." hexadecimal_digit_sequence
  | hexadecimal_digit_sequence "."
hexadecimal_digit_sequence_opt →
    hexadecimal_digit_sequence
  | ∈
hexadecimal_digit_sequence →
    hexadecimal_digit
  | hexadecimal_digit_sequence hexadecimal_digit
binary_exponent_part →
    "p" sign_opt digit_sequence
  | "P" sign_opt digit_sequence
character_constant →
    "'" c_char_sequence "'"
  | "L'" c_char_sequence "'"
  | "u'" c_char_sequence "'"
  | "U'" c_char_sequence "'"
c_char_sequence →
    c_char
  | c_char_sequence c_char
c_char →
    escape_sequence
escape_sequence →
    simple_escape_sequence
  | octal_escape_sequence
  | hexadecimal_escape_sequence
  | universal_character_name
simple_escape_sequence →
    "\\'"
  | "\\\""
  | "\\?"
  | "\\\\"
  | "\\a"
  | "\\b"
  | "\\f"
  | "\\n"
  | "\\r"
  | "\\t"
  | "\\v"
octal_escape_sequence →
    "\\" octal_digit
  | "\\" octal_digit octal_digit
  | "\\" octal_digit octal_digit octal_digit
octal_digit →
    "0"
  | "1"
  | "2"
  | "3"
  | "4"
  | "5"
  | "6"
  | "7"
hexadecimal_escape_sequence →
    "\\x" hexadecimal_digit
  | hexadecimal_escape_sequence hexadecimal_digit
string_literal →
    encoding_prefix_opt "\"" s_char_sequence_opt "\""
encoding_prefix_opt →
    encoding_prefix
  | ∈
encoding_prefix →
    "u8"
  | "u"
  | "U"
  | "L"
s_char_sequence_opt →
    s_char_sequence
  | ∈
s_char_sequence →
    s_char
  | s_char_sequence s_char
s_char →
    escape_sequence
expression →
    assignment_expression
  | expression "," assignment_expression
assignment_expression →
    conditional_expression
  | unary_expression assignment_operator assignment_expression
conditional_expression →
    logical_OR_expression
  | logical_OR_expression "?" expression ":" conditional_expression
logical_OR_expression →
    logical_AND_expression
  | logical_OR_expression "||" logical_AND_expression
logical_AND_expression →
    inclusive_OR_expression
  | logical_AND_expression "&&" inclusive_OR_expression
inclusive_OR_expression →
    exclusive_OR_expression
  | inclusive_OR_expression "|" exclusive_OR_expression
exclusive_OR_expression →
    AND_expression
  | exclusive_OR_expression "^" AND_expression
AND_expression →
    equality_expression
  | AND_expression "&" equality_expression
equality_expression →
    relational_expression
  | equality_expression "==" relational_expression
  | equality_expression "!=" relational_expression
relational_expression →
    shift_expression
  | relational_expression "<" shift_expression
  | relational_expression ">" shift_expression
  | relational_expression "<=" shift_expression
  | relational_expression ">=" shift_expression
shift_expression →
    additive_expression
  | shift_expression "<<" additive_expression
  | shift_expression ">>" additive_expression
additive_expression →
    multiplicative_expression
  | additive_expression "+" multiplicative_expression
  | additive_expression "-" multiplicative_expression
multiplicative_expression →
    cast_expression
  | multiplicative_expression "*" cast_expression
  | multiplicative_expression "/" cast_expression
  | multiplicative_expression "%" cast_expression
assignment_operator →
    "="
  | "*="
  | "/="
  | "%="
  | "+="
  | "-="
  | "<<="
  | ">>="
  | "&="
  | "^="
  | "|="
argument_expression_list_opt →
    argument_expression_list
  | ∈
argument_expression_list →
    assignment_expression
  | argument_expression_list "," assignment_expression
unary_operator →
    "&"
  | "*"
  | "+"
  | "-"
  | "~"
  | "!"
