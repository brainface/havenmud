/*  Spell failure lib */
#include <lib.h>
inherit LIB_DAEMON;

static void create() {
 ::create();
 SetNoClean(1);
}


int eventFail(object who, object spell) {
  error("**No defined failure in eventFail()**");
  return 1;
  }