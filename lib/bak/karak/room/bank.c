#include <lib.h>
#include "../karak.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(50);
  SetTown("Karak");
  SetShort("Karak-Varn Treasury");
  SetObviousExits("north");
  SetExits( ([ "north" : K_ROOM "/mayor", ]) );
  SetLong("The cramped and heavily fortified room that serves as a bank "
          "is bisected by a long counter.  A large Orc is here to take "
           "care of transactions as well as defend this place.");
  SetInventory( ([ K_NPC "/kurgan" : 1 ]) );
}
