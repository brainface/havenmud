/*  The grove inheritable */
#include <lib.h>
#include "mage_tower.h"
inherit LIB_ROOM;
inherit LIB_FEAR;

static void create() {
  room::create();
  SetFearType("chilling dread of the grove");
  SetResistLevel(50);
  SetFearLength(50);
}

void init() {
  room::init();
  fear::init();
}


varargs int CheckResistFear(object who, int level, string type) {
  if (who->GetUndead()) return 0;
  return ::CheckResistFear(who, level, type);
}

