/*                       Notandor / არადანი
                                  ο       
                            σρ         ρα
                              .   |   .
                                . | .
                          σδ ----------- ρδ
                                . | .
                              .   |   .
                            σα    |     ρρ
                                  α             */
const log = (...a) => console.log(...a);
for (let g = 0531; g < 01000; g++) {
  const nc = (g >> 6) & 7;
  const ac = (g >> 3) & 7;
  const oc = (g >> 0) & 7;
  const mc = ac < nc ? (nc < oc ? oc : nc) : ac < oc ? oc : ac;
  log(
    `N(${nc ? "ara" + (nc > 1 ? nc : "") : ""}${
      ac ? "da" + (ac > 1 ? ac : "") : ""
    }${oc ? "an" + (oc > 1 ? oc : "") : ""}) {`
  );
  for (let i = 0; i < nc; i++) log(`  σρ[--ρρ].v = ο[--α].v;`);
  for (let i = 0; i < ac; i++) log(`  σδ[--ρδ].v = ο[--α].v;`);
  for (let i = 0; i < oc; i++) log(`  σα[--ρα].v = ο[--α].v;`);
  log(`  ο[α - 1].c(ο, α - 1, ρρ, σρ, ρδ, σδ, ρα, σα);`);
  log(`}`);
  break;
}
