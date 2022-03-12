const { Readable } = require("stream");

class Counter extends Readable {
  constructor(opt) {
    super(opt);
    this._max = 10;
    this._index = 1;
  }

  _read() {
    const i = this._index++;
    if (i > this._max) this.push(null);
    else {
      const str = String(i);
      const buf = Buffer.from(str, "ascii");
      this.push(buf);
      this.push(buf);
    }
  }
}
const c = new Counter();
c.on("data", (chunk) => console.log(chunk.toString()));
