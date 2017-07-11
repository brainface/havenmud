#include <lib.h>
#include <daemons.h>
inherit LIB_DAEMON;

mixed cmd(string useless) {
  foreach(object u in users()) { 
    foreach(object i in all_inventory(u)) { 
      if (i->GetClass() > 20) debug(identify(i) + " @ " + u->GetKeyName() + " is " + i->GetClass()); 
    } 
  }
  return 1;
}