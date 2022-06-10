for (let i = 0; i < 01000; i++) print_junction(i);
function print_junction(i) {
  const nc = (i >> 6) & 07;
  const ac = (i >> 3) & 07;
  const oc = (i >> 0) & 07;
  const name =
    (nc ? "not" + nc : "") + (ac ? "and" + ac : "") + (oc ? "or" + oc : "");
  const body = Array(nc + ac + oc).fill("σ[--ρ].v = σ[--α].v;");
  body.unshift("N(" + name + ") {");
  body.push(`σ[--ρ].Q = 0${i.toString(8)};`);
  body.push("dot(ο, α, ρ, σ);");
  body.push("}");
  const nar = body.join("");
  console.log(nar);
}
