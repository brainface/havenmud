#include <lib.h>

inherit LIB_DAEMON;



mixed cmd(string d) {
  if (!d) { 
    return "Purge which domain?";
  }

  foreach(object u in users()) {
    if (!u) continue;
    if (!environment(u)) continue;
    if (creatorp(u)) continue;
    if (environment(u)->GetDomain() == d) {
      return "Cannot purge " + d + " while " + u->GetKeyName() + " is present.";
    }
  }
  foreach(object o in objects()) {
    if (!o) continue;
    if (o->GetDomain() == d) {
      o->eventDestruct();
    }
  }
  return "Purged " + d;
}

string GetHelp(string fd) {
  return "Don't ever, ever use this command.";
}
  