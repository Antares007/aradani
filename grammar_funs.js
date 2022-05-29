const opt_fun_map = {};
module.exports = { printf, printa, opt, oneof };
function opt(nar) {
  const name = get_name(nar);
  return opt_fun_map[name]
    ? opt_fun_map[name]
    : (opt_fun_map[name] = new Function(
        "const nar=arguments[0];return function " +
          nar.name +
          "_opt(o){o(nar);o('');}"
      )(nar));
}
function oneof(...terms) {
  return (o) => terms.forEach((t) => o(t));
}
function get_name(f) {
  if (typeof f.name !== "string") throw new Error("f.name");
  return f.name;
}
function print(g, visited = []) {
  if (visited.indexOf(g) !== -1) return;
  visited.push(g);
  const defered = [];
  console.log(get_name(g), "→");
  const prods = [];
  g(function pith(...args) {
    const prod = args
      .map((x) => {
        if ("function" === typeof x) {
          defered.push(x);
          return get_name(x);
        } else {
          return x ? JSON.stringify(x) : "∈";
        }
      })
      .join(" ");
    prods.push(prod);
  });
  console.log("    " + prods.join("\n  | "));
  defered.forEach((f) => print(f, visited));
}
function printf(g, visited = []) {
  if (visited.indexOf(g) !== -1) return;
  visited.push(g);
  const defered = [];
  console.log("function " + get_name(g) + "(o) {");
  const prods = [];
  g(function pith(...args) {
    const prod = args
      .map((x) => {
        if ("function" === typeof x) {
          defered.push(x);
          return get_name(x);
        } else {
          return x ? JSON.stringify(x) : '""';
        }
      })
      .join(", ");
    prods.push("  o(" + prod + ")");
  });
  console.log(prods.join("\n"));
  console.log("}");
  defered.forEach((f) => printf(f, visited));
}
function write_prod(prod) {
  if (prod.length === 0) return process.stdout.write("\n")
  const s = prod[prod.length - 1];
  process.stdout.write(`${typeof s === "string" ? JSON.stringify(s) + ", Term" : get_name(s)}`)
  if (prod.length > 1)
    process.stdout.write(`, ${typeof s === "string" ? 2 : 1}, ThenS_n`)
}
function printa(g, visited = []) {
  if (visited.indexOf(g) !== -1) return;
  visited.push(g);
  const defered = [];
  console.log("function " + get_name(g) + "(o) {");
  const prods = [];
  g(function pith(...args) {
    console.log(args)
    write_prod(args)
    const prod = args
      .map((x) => {
        if ("function" === typeof x) {
          defered.push(x);
          return get_name(x);
        } else {
          return x ? JSON.stringify(x) : null;
        }
      })
    prods.push("  o(" + prod.join(", ") + ")");
  });
prods.forEach(write_prod)
  console.log(prods.join("\n"));
  console.log("      }");
  defered.forEach((f) => printa(f, visited));
}
