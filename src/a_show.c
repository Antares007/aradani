#include "arsi.h"
#include "raylibfun.h"
#include "stdiofun.h"
rayfun_t *ρ;
stdiofun_t *σ;
n_t Got, God;
// clang-format off
                   I(Gor,
"God", God,      L)I(L,
"Got", Got,      L)I(L,
"ρ", ρ,          L)I(L,
"σ", σ,          ι);
// clang-format on
N(InitWindow) {
  const int screenWidth = 800;
  const int screenHeight = 450;
  ρ->InitWindow(screenWidth, screenHeight, "GUI Example!");
  ρ->SetTargetFPS(0);
  C(1);
}
N(WindowShouldNotClose) { C(!ρ->WindowShouldClose()); }
N(BeginDrawing) { ρ->BeginDrawing(); ρ->ClearBackground(RAYWHITE); C(1); }
N(EndDrawing) { ρ->EndDrawing(); C(1); }
N(Draw) { ρ->DrawText("aba mamao!", 240, 140, 44, GRAY); C(1); }
N(loop) {
  A11(                                            δ[0],
      WindowShouldNotClose, BeginDrawing, ψ[010], δ[3],
      Draw,                                       δ[1],
      EndDrawing,                                 δ[1],
      loop,                                       δ[1]) O;
}
N(xxx) {
  A3(InitWindow, loop, ψ[010]) O;
}
N(counter) {
  //(
  //  Δ.draw,
  //    Δ.draw,
  //    "+",
  //    Δ.text,
  //  Δ.button,
  //    Δ.draw,
  //    "-",
  //    Δ.text,
  //  Δ.button,
  //  "0",
  //  Δ.text,

  //  Σ.aba
  //) O;
}
N(treeasnumbers) {
  A17(
    δ[0],
      δ[0],
        God, God, ψ[0001],
      δ[3],
    δ[5],
      δ[0],
        God, God, ψ[0010],
      δ[3],
        Got, treeasnumbers, ψ[0100],
      δ[3],
    δ[9]
  ) O;
}
N(prn) { RN(Q_t, n); for(Q_t i = 0; i < n; i++) σ->printf(" "); σ->printf("%lu\n", n); C(1); }
N(term) {
  RN(const char*, str);
  RN(Q_t,         pos);
  RN(Q_t,         len);
  RN(const char*, in);
  if (pos < len && in[pos] == str[0]) 
    (in, len, pos + 1) O;
  else
    () O;
}
N(Aaa) {
  A6(           δ[0],
    "a", term,  δ[2],
    Aaa,        δ[2]) O; }
N(Baaax) {
  A9(                                          δ[0],
    "b", term, Aaa, ψ[010], "x", term, ψ[020], δ[7]) O; }
N(show) { A2("aaaa", 4, 0, Baaax) O; }
// ამომცნობი, რომელიც შეესაბამება p |-ს კონსტრუქციას q გრამატიკაში
// აგებულია p-ისა და q-ის ამომცნობიების კომბინაციით, პარსერის კომბინატორის
// "orelse" გამოყენებით.
// როდესაც კომპოზიტური ამომცნობი გამოიყენება j ინდექსზე, ის ვრცელდება
// p-ზე j-ზე, შემდეგ გამოიყენება q-ზე j-ზე და შემდგომში
// აერთიანებს მიღებულ სიმრავლეს.:
//    (p ‘orelse‘ q) j = unite (p j) (q j)
//    e.g, assuming that the input is "ssss", then
//    (empty ‘orelse‘ term_s) 2 => {2, 3}
// კომპოზიტური ამომცნობი, რომელიც შეესაბამება ამომცნობთა თანმიმდევრობას
// p q გრამატიკული წესის მარჯვენა მხარეს, აგებულია ამ ამომცნობთა კომბინაციით
// პარსერის კომბინატორის "thenS" გამოყენებით.
// როდესაც კომპოზიტური ამომცნობი გამოიყენება j ინდექსზე, ის ჯერ მიმართავს
// p-ს j-ს, შემდეგ ის მიმართავს q თითოეულ ინდექსს p-ით დაბრუნებული
// შედეგების სიმრავლეში. ის აბრუნებს q-ის ამ აპლიკაციების გაერთიანებას.
//    (p ‘thenS‘ q) j = union (map q (p j))
//    e.g., assuming that the input is "ssss", then
//    (term_s ‘thenS‘ term_s) 1 => {3}

// clang-format off
            EN(ζ,
show,     ε);
