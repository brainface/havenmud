//
// Summary: a cemetary for baria
// Created by Rhakz - Angel Cazares
// For Baria
// Date: 11/01/98
//
#include <lib.h>
#include <std.h>
#include "../jungle.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("the cemetery of Baria");
  SetTown("Baria");
  SetDomain("Baria");
  SetLong(
     "This place is where the remains of the fallen citizens of Baria "
     "even though rumor has it that some of them have gotten a second "
     "chance and revived. There are stone crosses and tombstones where "
     "the remains are buried, so the relatives can have a place where "
     "to honor the beloved ones. "
  );
  SetClimate("tropical");
  SetItems( ([
              ({"crosses","tombstones"}) : "These are monuments to the "
                                           "dead citizens of Baria.",
          ]) );
  SetItemAdjectives( ([
                       "crosses" : ({"stone"}),
                   ]) );
  SetExits( ([
              "north" : BARIA_ROOM + "shrine_1",
          ]) );
  SetSmell( ([ "default" : "The smell of rotten corpses and decay "
                           "is unbearable." ]) );
  SetListen( ([ "default" : "Silence seems unbreakable in this "
                            "part. " ]) );
  SetProperty("NoAttack",1);;SetInventory( ([
    STD_OBJ "reztotem" : 1,
  ]) );
}


