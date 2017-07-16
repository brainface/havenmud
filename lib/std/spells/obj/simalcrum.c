#include <lib.h>
#include <daemons.h>
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("simalcrum");
  SetShort("a simalcrum");
  SetNoCorpse(1);
}

