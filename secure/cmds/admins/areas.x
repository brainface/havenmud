#include <lib.h>
inherit LIB_DAEMON;

mixed cmd() {
  string *d;
  string *a;
  
  d = get_dir("/domains/");
  foreach(string dm in d) {
    a = get_dir("/domains/" + dm + "/areas/");
    if (!a) a = ({ });
    foreach(string ar in a) {
      write_file("/log/areas", "(a) " + dm + " " + ar + "\n");
    }
    a = 0;
    a = get_dir("/domains/" + dm + "/towns/");
    if (!a) a = ({ });
    foreach(string ar in a) {
      log_file("areas", "(t) " + dm + " " + ar + "\n");
    }
  }
  return 1;
}

        