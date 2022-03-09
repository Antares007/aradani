#include "arsi.h"
#include "gotgod.h"
// clang-format off
IBS(                L)IN(L,
nar,                L)IN(L,
os_ls,              L)IN(L,
os_new,             L)IN(L,
os_queue,           L)IN(L,
os_wordump,         L)IN(L,
//
and,                L)IN(L,
and2,               L)IN(L,
and3,               L)IN(L,
and4,               L)IN(L,
and5,               L)IN(L,
and6,               L)IN(L,
and7,               L)IN(L,
andor,              L)IN(L,
andor2,             L)IN(L,
not,                L)IN(L,
not2and,            L)IN(L,
not2and2or2,        L)IN(L,
or,           imports);

#define ο5 ο[15].cs
#define ο6 ο[16].Q
#define ο7 ο[17].Q
Q_t cslen(const char* cs) { Q_t len = 0; while(cs[len]) len++; return len; }
#define U8CP_UM(Name, Mask, Check, Unmask, Ray) \
  S(Name){R(Q_t, v);(v & Mask)==Check?(A(v & Unmask)C(1)):(A(v)C(Ray));}
U8CP_UM(um0xxxxxxx, 0x80, 0x00, 0xff, 0)
U8CP_UM(um10xxxxxx, 0xc0, 0x80, 0x3f, 2)
U8CP_UM(um110xxxxx, 0xe0, 0xc0, 0x1f, 0)
U8CP_UM(um1110xxxx, 0xf0, 0xe0, 0x0f, 0)
U8CP_UM(um11110xxx, 0xf8, 0xf0, 0x07, 0)

S(lookahead)       { A((Q_t)ο5[ο7]) C(1); }
S(shift)           { if (ο7 < ο6) ο7++, C(1); else C(2); }
S(bin_lsh)         { R(Q_t, r); R(Q_t, l); A(l << r) C(1); }
S(bin_or)          { R(Q_t, r); R(Q_t, l); A(l |  r) C(1); }
S(lookahead_shift) { A3(lookahead, shift,  and) O; }

Sar(u8cp_b1)(um0xxxxxxx)
Sar(u8cp_b2)(um110xxxxx,       6, bin_lsh, and2, lookahead_shift, and,
             um10xxxxxx, and, bin_or, and)
Sar(u8cp_b3)(um1110xxxx,      12, bin_lsh, and2, lookahead_shift, and,
             um10xxxxxx, and,  6, bin_lsh, and2, lookahead_shift, and,
             um10xxxxxx, and,  bin_or, and, bin_or, and)
Sar(u8cp_b4)(um11110xxx,      18, bin_lsh, and2, lookahead_shift, and,
             um10xxxxxx, and, 12, bin_lsh, and2, lookahead_shift, and,
             um10xxxxxx, and,  6, bin_lsh, and2, lookahead_shift, and,
             um10xxxxxx, and,  bin_or, and, bin_or, and, bin_or, and)
Sar(u8cp)(lookahead_shift, u8cp_b1, and, u8cp_b2, or, u8cp_b3, or, u8cp_b4, or)
S(Μ) {
  R(n_t, nar);
  AS(nar, nar, Μ, and2, god, or) O;
}
S(testuni) {
  ο5 = "aŠა𓅪 α𓅨";
  ο6 = cslen(ο5);
  ο7 = 0;
  print("\ncs:\t%s\nlen:\t%lu\n\n", ο5, ο6);
  AS(u8cp, Μ, god, not, os_wordump, and) O;
}
Nar(მთავარი)(testuni)
S(init) { C(1); }

//N(Ο);                      
//
//N(doctypedecl);
//N(XMLDecl);
//N(Misc);
//
//// STag         ::= '<' Name (S Attribute)* S? '>'
//// EmptyElemTag ::= '<' Name (S Attribute)* S? '/>'
//// element      ::= EmptyElemTag | STag content ETag
//N(element);
//
//// prolog ::= XMLDecl? Misc* (doctypedecl Misc*)?
//N(prolog_n) { A4(doctypedecl, Misc, Μ, and2) O; }
//N(prolog  ) { A8(XMLDecl, Ο, Misc, Μ, and2, prolog_n, Ο, and2) O; }
//
//// document ::= prolog element Misc*
//N(document) { A6(prolog, element, and, Misc, Μ, and2) O; }
// Char ::= #x9 | #xA | #xD | [#x20-#xD7FF] | [#xE000-#xFFFD] | [#x10000-#x10FFFF]
// S ::= (#x20 | #x9 | #xD | #xA)+
// NameChar ::= Letter | Digit | '.' | '-' | '_' | ':' | CombiningChar | Extender
// Name ::= (Letter | '_' | ':') (NameChar)*
// Names ::= Name (S Name)*
// Nmtoken ::= (NameChar)+
// Nmtokens ::= Nmtoken (S Nmtoken)*
// EntityValue ::= '"' ([^%&"] | PEReference | Reference)* '"' |  "'" ([^%&'] | PEReference | Reference)* "'"
// AttValue ::= '"' ([^<&"] | Reference)* '"' |  "'" ([^<&'] | Reference)* "'"
// SystemLiteral ::= ('"' [^"]* '"') | ("'" [^']* "'") 
// PubidLiteral ::= '"' PubidChar* '"' | "'" (PubidChar - "'")* "'"
// PubidChar ::= #x20 | #xD | #xA | [a-zA-Z0-9] | [-'()+,./:=?;!*#@$_%]
// CharData ::= [^<&]* - ([^<&]* ']]>' [^<&]*)
// Comment ::= '<!--' ((Char - '-') | ('-' (Char - '-')))* '-->'
// PI ::= '<?' PITarget (S (Char* - (Char* '?>' Char*)))? '?>'
// PITarget ::= Name - (('X' | 'x') ('M' | 'm') ('L' | 'l'))
// CDSect ::= CDStart CData CDEnd
// CDStart ::= '<![CDATA['
// CData ::= (Char* - (Char* ']]>' Char*)) 
// CDEnd ::= ']]>'
// XMLDecl ::= '<?xml' VersionInfo EncodingDecl? SDDecl? S? '?>'
// VersionInfo ::= S 'version' Eq (' VersionNum ' | " VersionNum ")
// Eq ::= S? '=' S?
// VersionNum ::= ([a-zA-Z0-9_.:] | '-')+
// Misc ::= Comment | PI |  S
// doctypedecl ::= '<!DOCTYPE' S Name (S ExternalID)? S? ('[' (markupdecl | PEReference | S)* ']' S?)? '>'
// markupdecl ::= elementdecl | AttlistDecl | EntityDecl | NotationDecl | PI | Comment 
// extSubset ::= TextDecl? extSubsetDecl
// extSubsetDecl ::= ( markupdecl | conditionalSect | PEReference | S )*
// SDDecl ::= S 'standalone' Eq (("'" ('yes' | 'no') "'") | ('"' ('yes' | 'no') '"')) 
// LanguageID ::= Langcode ('-' Subcode)*
// Langcode ::= ISO639Code |  IanaCode |  UserCode
// ISO639Code ::= ([a-z] | [A-Z]) ([a-z] | [A-Z])
// IanaCode ::= ('i' | 'I') '-' ([a-z] | [A-Z])+
// UserCode ::= ('x' | 'X') '-' ([a-z] | [A-Z])+
// Subcode ::= ([a-z] | [A-Z])+
// Attribute ::= Name Eq AttValue
// ETag ::= '</' Name S? '>'
// content ::= (element | CharData | Reference | CDSect | PI | Comment)*
// elementdecl ::= '<!ELEMENT' S Name S contentspec S? '>'
// contentspec ::= 'EMPTY' | 'ANY' | Mixed | children 
// children ::= (choice | seq) ('?' | '*' | '+')?
// cp ::= (Name | choice | seq) ('?' | '*' | '+')?
// choice ::= '(' S? cp ( S? '|' S? cp )* S? ')'
// seq ::= '(' S? cp ( S? ',' S? cp )* S? ')'
// Mixed ::= '(' S? '#PCDATA' (S? '|' S? Name)* S? ')*' | '(' S? '#PCDATA' S? ')' 
// AttlistDecl ::= '<!ATTLIST' S Name AttDef* S? '>'
// AttDef ::= S Name S AttType S DefaultDecl
// AttType ::= StringType | TokenizedType | EnumeratedType 
// StringType ::= 'CDATA'
// TokenizedType ::= 'ID' | 'IDREF' | 'IDREFS' | 'ENTITY' | 'ENTITIES' | 'NMTOKEN' | 'NMTOKENS'
// EnumeratedType ::= NotationType | Enumeration 
// NotationType ::= 'NOTATION' S '(' S? Name (S? '|' S? Name)* S? ')' 
// Enumeration ::= '(' S? Nmtoken (S? '|' S? Nmtoken)* S? ')'
// DefaultDecl ::= '#REQUIRED' | '#IMPLIED' | (('#FIXED' S)? AttValue)
// conditionalSect ::= includeSect | ignoreSect 
// includeSect ::= '<![' S? 'INCLUDE' S? '[' extSubsetDecl ']]>' 
// ignoreSect ::= '<![' S? 'IGNORE' S? '[' ignoreSectContents* ']]>'
// ignoreSectContents ::= Ignore ('<![' ignoreSectContents ']]>' Ignore)*
// Ignore ::= Char* - (Char* ('<![' | ']]>') Char*) 
// CharRef ::= '&#' [0-9]+ ';' | '&#x' [0-9a-fA-F]+ ';'
// Reference ::= EntityRef | CharRef
// EntityRef ::= '&' Name ';'
// PEReference ::= '%' Name ';'
// EntityDecl ::= GEDecl | PEDecl
// GEDecl ::= '<!ENTITY' S Name S EntityDef S? '>'
// PEDecl ::= '<!ENTITY' S '%' S Name S PEDef S? '>'
// EntityDef ::= EntityValue | (ExternalID NDataDecl?)
// PEDef ::= EntityValue | ExternalID
// ExternalID ::= 'SYSTEM' S SystemLiteral | 'PUBLIC' S PubidLiteral S SystemLiteral 
// NDataDecl ::= S 'NDATA' S Name
// TextDecl ::= '<?xml' VersionInfo? EncodingDecl S? '?>'
// extParsedEnt ::= TextDecl? content
// extPE ::= TextDecl? extSubsetDecl
// EncodingDecl ::= S 'encoding' Eq ('"' EncName  '"' |  "'" EncName "'" )
// EncName ::= [A-Za-z] ([A-Za-z0-9._] | '-')*
// NotationDecl ::= '<!NOTATION' S Name S (ExternalID |  PublicID) S? '>'
// PublicID ::= 'PUBLIC' S PubidLiteral 
// Letter ::= BaseChar | Ideographic
// BaseChar ::= [#x0041-#x005A] | [#x0061-#x007A] | [#x00C0-#x00D6] | [#x00D8-#x00F6] | [#x00F8-#x00FF] | [#x0100-#x0131] | [#x0134-#x013E] | [#x0141-#x0148] | [#x014A-#x017E] | [#x0180-#x01C3] | [#x01CD-#x01F0] | [#x01F4-#x01F5] | [#x01FA-#x0217] | [#x0250-#x02A8] | [#x02BB-#x02C1] | #x0386 | [#x0388-#x038A] | #x038C | [#x038E-#x03A1] | [#x03A3-#x03CE] | [#x03D0-#x03D6] | #x03DA | #x03DC | #x03DE | #x03E0 | [#x03E2-#x03F3] | [#x0401-#x040C] | [#x040E-#x044F] | [#x0451-#x045C] | [#x045E-#x0481] | [#x0490-#x04C4] | [#x04C7-#x04C8] | [#x04CB-#x04CC] | [#x04D0-#x04EB] | [#x04EE-#x04F5] | [#x04F8-#x04F9] | [#x0531-#x0556] | #x0559 | [#x0561-#x0586] | [#x05D0-#x05EA] | [#x05F0-#x05F2] | [#x0621-#x063A] | [#x0641-#x064A] | [#x0671-#x06B7] | [#x06BA-#x06BE] | [#x06C0-#x06CE] | [#x06D0-#x06D3] | #x06D5 | [#x06E5-#x06E6] | [#x0905-#x0939] | #x093D | [#x0958-#x0961] | [#x0985-#x098C] | [#x098F-#x0990] | [#x0993-#x09A8] | [#x09AA-#x09B0] | #x09B2 | [#x09B6-#x09B9] | [#x09DC-#x09DD] | [#x09DF-#x09E1] | [#x09F0-#x09F1] | [#x0A05-#x0A0A] | [#x0A0F-#x0A10] | [#x0A13-#x0A28] | [#x0A2A-#x0A30] | [#x0A32-#x0A33] | [#x0A35-#x0A36] | [#x0A38-#x0A39] | [#x0A59-#x0A5C] | #x0A5E | [#x0A72-#x0A74] | [#x0A85-#x0A8B] | #x0A8D | [#x0A8F-#x0A91] | [#x0A93-#x0AA8] | [#x0AAA-#x0AB0] | [#x0AB2-#x0AB3] | [#x0AB5-#x0AB9] | #x0ABD | #x0AE0 | [#x0B05-#x0B0C] | [#x0B0F-#x0B10] | [#x0B13-#x0B28] | [#x0B2A-#x0B30] | [#x0B32-#x0B33] | [#x0B36-#x0B39] | #x0B3D | [#x0B5C-#x0B5D] | [#x0B5F-#x0B61] | [#x0B85-#x0B8A] | [#x0B8E-#x0B90] | [#x0B92-#x0B95] | [#x0B99-#x0B9A] | #x0B9C | [#x0B9E-#x0B9F] | [#x0BA3-#x0BA4] | [#x0BA8-#x0BAA] | [#x0BAE-#x0BB5] | [#x0BB7-#x0BB9] | [#x0C05-#x0C0C] | [#x0C0E-#x0C10] | [#x0C12-#x0C28] | [#x0C2A-#x0C33] | [#x0C35-#x0C39] | [#x0C60-#x0C61] | [#x0C85-#x0C8C] | [#x0C8E-#x0C90] | [#x0C92-#x0CA8] | [#x0CAA-#x0CB3] | [#x0CB5-#x0CB9] | #x0CDE | [#x0CE0-#x0CE1] | [#x0D05-#x0D0C] | [#x0D0E-#x0D10] | [#x0D12-#x0D28] | [#x0D2A-#x0D39] | [#x0D60-#x0D61] | [#x0E01-#x0E2E] | #x0E30 | [#x0E32-#x0E33] | [#x0E40-#x0E45] | [#x0E81-#x0E82] | #x0E84 | [#x0E87-#x0E88] | #x0E8A | #x0E8D | [#x0E94-#x0E97] | [#x0E99-#x0E9F] | [#x0EA1-#x0EA3] | #x0EA5 | #x0EA7 | [#x0EAA-#x0EAB] | [#x0EAD-#x0EAE] | #x0EB0 | [#x0EB2-#x0EB3] | #x0EBD | [#x0EC0-#x0EC4] | [#x0F40-#x0F47] | [#x0F49-#x0F69] | [#x10A0-#x10C5] | [#x10D0-#x10F6] | #x1100 | [#x1102-#x1103] | [#x1105-#x1107] | #x1109 | [#x110B-#x110C] | [#x110E-#x1112] | #x113C | #x113E | #x1140 | #x114C | #x114E | #x1150 | [#x1154-#x1155] | #x1159 | [#x115F-#x1161] | #x1163 | #x1165 | #x1167 | #x1169 | [#x116D-#x116E] | [#x1172-#x1173] | #x1175 | #x119E | #x11A8 | #x11AB | [#x11AE-#x11AF] | [#x11B7-#x11B8] | #x11BA | [#x11BC-#x11C2] | #x11EB | #x11F0 | #x11F9 | [#x1E00-#x1E9B] | [#x1EA0-#x1EF9] | [#x1F00-#x1F15] | [#x1F18-#x1F1D] | [#x1F20-#x1F45] | [#x1F48-#x1F4D] | [#x1F50-#x1F57] | #x1F59 | #x1F5B | #x1F5D | [#x1F5F-#x1F7D] | [#x1F80-#x1FB4] | [#x1FB6-#x1FBC] | #x1FBE | [#x1FC2-#x1FC4] | [#x1FC6-#x1FCC] | [#x1FD0-#x1FD3] | [#x1FD6-#x1FDB] | [#x1FE0-#x1FEC] | [#x1FF2-#x1FF4] | [#x1FF6-#x1FFC] | #x2126 | [#x212A-#x212B] | #x212E | [#x2180-#x2182] | [#x3041-#x3094] | [#x30A1-#x30FA] | [#x3105-#x312C] | [#xAC00-#xD7A3] Ideographic ::= [#x4E00-#x9FA5] | #x3007 | [#x3021-#x3029] 
// CombiningChar ::= [#x0300-#x0345] | [#x0360-#x0361] | [#x0483-#x0486] | [#x0591-#x05A1] | [#x05A3-#x05B9] | [#x05BB-#x05BD] | #x05BF | [#x05C1-#x05C2] | #x05C4 | [#x064B-#x0652] | #x0670 | [#x06D6-#x06DC] | [#x06DD-#x06DF] | [#x06E0-#x06E4] | [#x06E7-#x06E8] | [#x06EA-#x06ED] | [#x0901-#x0903] | #x093C | [#x093E-#x094C] | #x094D | [#x0951-#x0954] | [#x0962-#x0963] | [#x0981-#x0983] | #x09BC | #x09BE | #x09BF | [#x09C0-#x09C4] | [#x09C7-#x09C8] | [#x09CB-#x09CD] | #x09D7 | [#x09E2-#x09E3] | #x0A02 | #x0A3C | #x0A3E | #x0A3F | [#x0A40-#x0A42] | [#x0A47-#x0A48] | [#x0A4B-#x0A4D] | [#x0A70-#x0A71] | [#x0A81-#x0A83] | #x0ABC | [#x0ABE-#x0AC5] | [#x0AC7-#x0AC9] | [#x0ACB-#x0ACD] | [#x0B01-#x0B03] | #x0B3C | [#x0B3E-#x0B43] | [#x0B47-#x0B48] | [#x0B4B-#x0B4D] | [#x0B56-#x0B57] | [#x0B82-#x0B83] | [#x0BBE-#x0BC2] | [#x0BC6-#x0BC8] | [#x0BCA-#x0BCD] | #x0BD7 | [#x0C01-#x0C03] | [#x0C3E-#x0C44] | [#x0C46-#x0C48] | [#x0C4A-#x0C4D] | [#x0C55-#x0C56] | [#x0C82-#x0C83] | [#x0CBE-#x0CC4] | [#x0CC6-#x0CC8] | [#x0CCA-#x0CCD] | [#x0CD5-#x0CD6] | [#x0D02-#x0D03] | [#x0D3E-#x0D43] | [#x0D46-#x0D48] | [#x0D4A-#x0D4D] | #x0D57 | #x0E31 | [#x0E34-#x0E3A] | [#x0E47-#x0E4E] | #x0EB1 | [#x0EB4-#x0EB9] | [#x0EBB-#x0EBC] | [#x0EC8-#x0ECD] | [#x0F18-#x0F19] | #x0F35 | #x0F37 | #x0F39 | #x0F3E | #x0F3F | [#x0F71-#x0F84] | [#x0F86-#x0F8B] | [#x0F90-#x0F95] | #x0F97 | [#x0F99-#x0FAD] | [#x0FB1-#x0FB7] | #x0FB9 | [#x20D0-#x20DC] | #x20E1 | [#x302A-#x302F] | #x3099 | #x309A 
// Digit ::= [#x0030-#x0039] | [#x0660-#x0669] | [#x06F0-#x06F9] | [#x0966-#x096F] | [#x09E6-#x09EF] | [#x0A66-#x0A6F] | [#x0AE6-#x0AEF] | [#x0B66-#x0B6F] | [#x0BE7-#x0BEF] | [#x0C66-#x0C6F] | [#x0CE6-#x0CEF] | [#x0D66-#x0D6F] | [#x0E50-#x0E59] | [#x0ED0-#x0ED9] | [#x0F20-#x0F29] 
// Extender ::= #x00B7 | #x02D0 | #x02D1 | #x0387 | #x0640 | #x0E46 | #x0EC6 | #x3005 | [#x3031-#x3035] | [#x309D-#x309E] | [#x30FC-#x30FE] 

// clang-format off
EN(tail,
მთავარი,      exports);
