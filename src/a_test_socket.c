#include "arsi.h"
// clang-format off
IN(0,
ls_export,                  L)IN(L,
os_new,                     L)int(*print)(const char*, ...);I(L,
printf, print,              L)IN(L,
//
os_queue,                   L)IN(L,
//
and,                        L)IN(L,
and2,                       L)IN(L,
and3,                       L)IN(L,
and3or,                     L)IN(L,
and4,                       L)IN(L,
not,                        L)IN(L,
notand,                     L)IN(L,
or,                         L)IN(L,
//
mkdrain,                    L)IN(L,
os_bind,                    L)IN(L,
os_listen,                  L)IN(L,
os_next,                    L)IN(L,
os_socket,                  L)IN(L,
//
s_pith,                import);

NP(on_data) {
  R(Q_t, nread);
  print("drain_and - α:%ld nread:%ld\n", α, nread);
  α = 0, os_next(T());
}
N(gor) { C(0); }
NP(on_connection) {
  R(p_t*, cσ);
  print("events: %p\n", cσ);
  A7(on_data, mkdrain,
     gor, cσ, 2, os_queue, and4) X;
}

struct sink_state_s {
  p_t *uσ;
};

//The sink MUST be greeted back with a callbag payload
//that is either the source itself
//or another callbag (known as the "talkback"). 
NP(sink_or ) {
  R(p_t*, sσ);
  struct sink_state_s *s = S(struct sink_state_s, sσ);
  s->uσ = sσ;

}
//Window of valid deliveries:
//A callbag MUST NOT be delivered data before it has been greeted
//A callbag MUST NOT be delivered data after it has been terminated
//A sink MUST NOT be delivered data after it terminates its source
NP(sink_and) { 
}
//A callbag is terminated when the first argument is 2 and the
//second argument is either undefined (signalling termination
//due to success) or any truthy value (signalling termination
//due to failure).
NP(sink_not) { 
}
NP(sink    ) {
  A6(sink_or, sink_and, sink_not, 0x1000, wordCountOf(struct sink_state_s), os_new) O;
}
NP(მთავარი) {
  A10(os_socket,
      "127.0.0.1", 7000, os_bind, and3,
      on_connection, mkdrain,     and2,
      os_listen,                  and) X;
}

N(updater) { A2(მთავარი, and) C(1); }
void init() { updateσ(s_pith, updater); }

// clang-format off
EN(tail,          
s_pith,                export);
