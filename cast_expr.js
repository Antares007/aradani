function cast_expression(o) {
  o(unary_expression);
}
function unary_expression(o) {
  o(postfix_expression);
  o("++", unary_expression);
  o("--", unary_expression);
  o(unary_operator, cast_expression);
  o("sizeof", unary_expression);
}
function postfix_expression(o) {
  o(primary_expression);
  o(postfix_expression, "[", expression, "]");
  o(postfix_expression, "(", argument_expression_list_opt, ")");
  o(postfix_expression, ".", identifier);
  o(postfix_expression, "->", identifier);
  o(postfix_expression, "++");
  o(postfix_expression, "--");
}
function primary_expression(o) {
  o(identifier);
  o(constant);
  o(string_literal);
  o("(", expression, ")");
}
function identifier(o) {
  o(identifier_nondigit);
  o(identifier, identifier_nondigit);
  o(identifier, digit);
}
function identifier_nondigit(o) {
  o(nondigit);
  o(universal_character_name);
}
function nondigit(o) {
  o("_");
  o("a"); o("b"); o("c"); o("d"); o("e"); o("f"); o("g"); o("h"); o("i"); o("j"); o("k"); o("l"); o("m");
  o("A"); o("B"); o("C"); o("D"); o("E"); o("F"); o("G"); o("H"); o("I"); o("J"); o("K"); o("L"); o("M");
  o("n"); o("o"); o("p"); o("q"); o("r"); o("s"); o("t"); o("u"); o("v"); o("w"); o("x"); o("y"); o("z");
  o("N"); o("O"); o("P"); o("Q"); o("R"); o("S"); o("T"); o("U"); o("V"); o("W"); o("X"); o("Y"); o("Z");
}
function universal_character_name(o) {
  o("\\u", hex_quad);
  o("\\U", hex_quad, hex_quad);
}
function hex_quad(o) {
  o(hexadecimal_digit, hexadecimal_digit, hexadecimal_digit, hexadecimal_digit);
}
function hexadecimal_digit(o) {
  o("0"); o("1"); o("2"); o("3"); o("4"); o("5"); o("6"); o("7"); o("8"); o("9");
  o("a"); o("b"); o("c"); o("d"); o("e"); o("f");
  o("A"); o("B"); o("C"); o("D"); o("E"); o("F");
}
function digit(o) {
  o("0"); o("1"); o("2"); o("3"); o("4"); o("5"); o("6"); o("7"); o("8"); o("9");
}
function constant(o) {
  o(floating_constant);
  o(character_constant);
}
function floating_constant(o) {
  o(decimal_floating_constant);
  o(hexadecimal_floating_constant);
}
function decimal_floating_constant(o) {
  o(fractional_constant, exponent_part_opt, floating_suffix_opt);
  o(digit_sequence, exponent_part, floating_suffix_opt);
}
function fractional_constant(o) {
  o(digit_sequence_opt, ".", digit_sequence);
  o(digit_sequence, ".");
}
function digit_sequence_opt(o) {
  o(digit_sequence);
  o("");
}
function digit_sequence(o) {
  o(digit);
  o(digit_sequence, digit);
}
function exponent_part_opt(o) {
  o(exponent_part);
  o("");
}
function exponent_part(o) {
  o("e", sign_opt, digit_sequence);
  o("E", sign_opt, digit_sequence);
}
function sign_opt(o) {
  o(sign);
  o("");
}
function sign(o) {
  o("+");
  o("-");
}
function floating_suffix_opt(o) {
  o(floating_suffix);
  o("");
}
function floating_suffix(o) {
  o("f");
  o("l");
  o("F");
  o("L");
}
function hexadecimal_floating_constant(o) {
  o(
    hexadecimal_prefix,
    hexadecimal_fractional_constant,
    binary_exponent_part,
    floating_suffix_opt
  );
  o(
    hexadecimal_prefix,
    hexadecimal_digit_sequence,
    binary_exponent_part,
    floating_suffix_opt
  );
}
function hexadecimal_prefix(o) {
  o("0x");
  o("0X");
}
function hexadecimal_fractional_constant(o) {
  o(hexadecimal_digit_sequence_opt, ".", hexadecimal_digit_sequence);
  o(hexadecimal_digit_sequence, ".");
}
function hexadecimal_digit_sequence_opt(o) {
  o(hexadecimal_digit_sequence);
  o("");
}
function hexadecimal_digit_sequence(o) {
  o(hexadecimal_digit);
  o(hexadecimal_digit_sequence, hexadecimal_digit);
}
function binary_exponent_part(o) {
  o("p", sign_opt, digit_sequence);
  o("P", sign_opt, digit_sequence);
}
function character_constant(o) {
  o("'", c_char_sequence, "'");
  o("L'", c_char_sequence, "'");
  o("u'", c_char_sequence, "'");
  o("U'", c_char_sequence, "'");
}
function c_char_sequence(o) {
  o(c_char);
  o(c_char_sequence, c_char);
}
function c_char(o) {
  o(escape_sequence);
}
function escape_sequence(o) {
  o(simple_escape_sequence);
  o(octal_escape_sequence);
  o(hexadecimal_escape_sequence);
  o(universal_character_name);
}
function simple_escape_sequence(o) {
  o("\\'");
  o('\\"');
  o("\\?");
  o("\\\\");
  o("\\a");
  o("\\b");
  o("\\f");
  o("\\n");
  o("\\r");
  o("\\t");
  o("\\v");
}
function octal_escape_sequence(o) {
  o("\\", octal_digit);
  o("\\", octal_digit, octal_digit);
  o("\\", octal_digit, octal_digit, octal_digit);
}
function octal_digit(o) {
  o("0");
  o("1");
  o("2");
  o("3");
  o("4");
  o("5");
  o("6");
  o("7");
}
function hexadecimal_escape_sequence(o) {
  o("\\x", hexadecimal_digit);
  o(hexadecimal_escape_sequence, hexadecimal_digit);
}
function string_literal(o) {
  o(encoding_prefix_opt, '"', s_char_sequence_opt, '"');
}
function encoding_prefix_opt(o) {
  o(encoding_prefix);
  o("");
}
function encoding_prefix(o) {
  o("u8");
  o("u");
  o("U");
  o("L");
}
function s_char_sequence_opt(o) {
  o(s_char_sequence);
  o("");
}
function s_char_sequence(o) {
  o(s_char);
  o(s_char_sequence, s_char);
}
function s_char(o) {
  o(escape_sequence);
}
function expression(o) {
  o(assignment_expression);
  o(expression, ",", assignment_expression);
}
function assignment_expression(o) {
  o(conditional_expression);
  o(unary_expression, assignment_operator, assignment_expression);
}
function conditional_expression(o) {
  o(logical_OR_expression);
  o(logical_OR_expression, "?", expression, ":", conditional_expression);
}
function logical_OR_expression(o) {
  o(logical_AND_expression);
  o(logical_OR_expression, "||", logical_AND_expression);
}
function logical_AND_expression(o) {
  o(inclusive_OR_expression);
  o(logical_AND_expression, "&&", inclusive_OR_expression);
}
function inclusive_OR_expression(o) {
  o(exclusive_OR_expression);
  o(inclusive_OR_expression, "|", exclusive_OR_expression);
}
function exclusive_OR_expression(o) {
  o(AND_expression);
  o(exclusive_OR_expression, "^", AND_expression);
}
function AND_expression(o) {
  o(equality_expression);
  o(AND_expression, "&", equality_expression);
}
function equality_expression(o) {
  o(relational_expression);
  o(equality_expression, "==", relational_expression);
  o(equality_expression, "!=", relational_expression);
}
function relational_expression(o) {
  o(shift_expression);
  o(relational_expression, "<", shift_expression);
  o(relational_expression, ">", shift_expression);
  o(relational_expression, "<=", shift_expression);
  o(relational_expression, ">=", shift_expression);
}
function shift_expression(o) {
  o(additive_expression);
  o(shift_expression, "<<", additive_expression);
  o(shift_expression, ">>", additive_expression);
}
function additive_expression(o) {
  o(multiplicative_expression);
  o(additive_expression, "+", multiplicative_expression);
  o(additive_expression, "-", multiplicative_expression);
}
function multiplicative_expression(o) {
  o(cast_expression);
  o(multiplicative_expression, "*", cast_expression);
  o(multiplicative_expression, "/", cast_expression);
  o(multiplicative_expression, "%", cast_expression);
}
function assignment_operator(o) {
  o("=");
  o("*=");
  o("/=");
  o("%=");
  o("+=");
  o("-=");
  o("<<=");
  o(">>=");
  o("&=");
  o("^=");
  o("|=");
}
function argument_expression_list_opt(o) {
  o(argument_expression_list);
  o("");
}
function argument_expression_list(o) {
  o(assignment_expression);
  o(argument_expression_list, ",", assignment_expression);
}
function unary_operator(o) {
  o("&");
  o("*");
  o("+");
  o("-");
  o("~");
  o("!");
}
