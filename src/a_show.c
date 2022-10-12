#include "arsi.h"
#include "raylibfun.h"
#include "stdiofun.h"
#define LOG σ->printf("%s(%lu)\n", __FUNCTION__, τ)
rayfun_t *ρ;
stdiofun_t *σ;
n_t Got, God;
// clang-format off
                   I(Gor,
"God", God,      L)I(L,
"Got", Got,      L)I(L,
"ρ", ρ,          L)I(L,
"σ", σ,          ι);
// clang-format off
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
N(Zro) { σ->printf("0\n"); C(0); }
N(One) { σ->printf("1\n"); C(1); }
N(Two) { σ->printf("2\n"); C(2); }
N(treeasnumbers_0) {
  A13(
    God,
      God,
        Zro, One, ψ[0001],
      ψ[0030],
    ψ[0050],
      God,
        One, One, ψ[0010],
      ψ[0030],
    ψ[0050]
  ) O;
}
N(treeasnumbers_1) {
  A13(
    δ[0],
      δ[0],
        Zro, One, ψ[0001],
      δ[3],
    δ[5],
      δ[0],
        One, One, ψ[0010],
      δ[3],
    δ[5]
  ) O;
}
N(treeasnumbers) { treeasnumbers_0(T); }
N(prn) { RN(Q_t, n); for(Q_t i = 0; i < n; i++) σ->printf(" "); σ->printf("%lu\n", n); C(1); }
//N(Baaax) { A9(                                            δ[0],
//              "b", term, Sa, ψ[010], "x", term, ψ[020],  δ[7]) O; }
N(term) {LOG;
  RN(const char*, str);
  RN(Q_t,         pos);
  RN(Q_t,         len);
  RN(const char*, in);
  if (pos < len && in[pos] == str[0])
        σ->printf("aTerm %lu\n", pos + 1), A3(in, len, pos + 1) C(1);
  else  σ->printf("bTerm %lu\n", pos    ), A3(in, len, pos    ) C(2); }
Q_t i = 0;
N(redu) {LOG; RN(Q_t, pos); τ -= 2; σ->printf("R:%lu\n", pos); C(1); }
N(da2 ) {LOG; ((n_t)ψ[020])(T); }
N(Sa  ) {LOG; if(i++ > 10) return;
  RN(Q_t,         pos);
  RN(Q_t,         len);
  RN(const char*, in );
  σ->printf("%s %lu %lu\n", in, len, pos);
  A15(                                δ[0],
    in, len, pos,     "a", term,      δ[5],
    in, len, pos, Sa, "a", term, da2, δ[7]) O; }
N(show) {LOG; 
  A4("aaaa", 4, 0, Sa) O; }
// როდესაც კომპოზიტური ამომცნობი გამოიყენება j ინდექსისთვის,
// ის ვრცელდება p-ზე j-თი, შემდეგ გამოიყენება q-ზე j-თი და შემდგომში
// აერთიანებს მიღებულ სიმრავლეს.:
//    (p ‘orelse‘ q) j = unite (p j) (q j)
//    e.g, assuming that the input is "ssss", then
//    (empty ‘orelse‘ term_s) 2 => {2, 3}
// როდესაც კომპოზიტური ამომცნობი გამოიყენება j ინდექსზე, ის ჯერ მიმართავს
// p-ს j ინდექსისთვის, შემდეგ ის მიმართავს q თითოეული p-თი დაბრუნებული ინდექსისათვის
// შედეგების სიმრავლეში. ის q-სთვის აბრუნებს ამ აპლიკაციების გაერთიანებას.
//    (p ‘thenS‘ q) j = union (map q (p j))
//    e.g., assuming that the input is "ssss", then
//    (term_s ‘thenS‘ term_s) 1 => {3}
//  არადანში ყველაფერი განისაზღვრება სიტყვების საშუალებით
//  ჩვენ შემთხვევაში orelse ამომცნობი არის δ სიტყვით გამოხატული.
//  δ ისტყვა ამოახვევს სიგმადან წინადადების q მხარეს
//
//  σ განზომილება. ο განზომილება.
//  

// clang-format off
            EN(ζ,
treeasnumbers,     ε);
