const { printf, opt, oneof } = require("./grammar_funs");
printf(unary_expression);
function unary_expression(o) {
  o(postfix_expression);
  o("&", unary_expression);
  o("*", unary_expression);
  o("+", unary_expression);
  o("-", unary_expression);
  o("~", unary_expression);
  o("!", unary_expression);
}
function postfix_expression(o) {
  o(identifier);
  o(decimal_floating_constant);
  o(string_literal);
  o("(", expression, ")");
  o(postfix_expression, "[", expression, "]");
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
function decimal_floating_constant(o) {
  o(fractional_constant);
  o(fractional_constant, exponent_part);
  o(digit_sequence, exponent_part);
}
function fractional_constant(o) {
  o(digit_sequence, ".", digit_sequence);
  o(digit_sequence, ".");
}
function digit_sequence(o) {
  o(digit);
  o(digit_sequence, digit);
}
function exponent_part(o) {
  o("e", digit_sequence);
  o("E", digit_sequence);
  o("e", sign, digit_sequence);
  o("E", sign, digit_sequence);
}
function sign(o) {
  o("+");
  o("-");
}
function string_literal(o) {
  o('""');
  o('"', s_char_sequence, '"');
}
function s_char_sequence(o) {
  o(s_char);
  o(s_char_sequence, s_char);
}
function s_char(o) {
  o('^\\"\n');
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
function expression(o) {
  o(conditional_expression);
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
  o(unary_expression);
  o(multiplicative_expression, "*", unary_expression);
  o(multiplicative_expression, "/", unary_expression);
  o(multiplicative_expression, "%", unary_expression);
}
