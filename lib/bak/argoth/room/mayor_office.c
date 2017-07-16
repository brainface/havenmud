#include <lib.h>
#include "../argoth.h"
inherit LIB_ROOM;
  static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(45);
  SetShort("The Mayor's Office");
  SetLong(
    "The office is decorated with what appear to be relics from the "
    "ruins of Karak Varn.  One item of note is the sign from the front door "
    "of the General Store, which is badly burned but still legible."
  );
  SetDomain("Crystal Reaches");
  SetItems( ([
    ({ "relics" }) :
    "These are bits and pieces from the ruins of Karak Varn.",
    ({ "sign" }) :
    "The sign is from the Karak Varn General Store.",
  ]) );
  SetNewsgroups( ({ "town.karak" }) );
  SetInventory( ([
    ARGOTH_NPC + "grond.c" : 1,
  ]) );
  SetExits( ([
    "west" : ARGOTH_ROOM + "hall.c",
  ]) );
}
