// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include <std.h>
#include "../karak.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetNightLight(20);
  SetShort("the Karak Cemetery");
  SetLong(
    "The Karak cemetery is set back in to the trees and rocks of "
    "the wilderness surrounding Karak. No markers exist for the dead "
    "and the only evidence that it is a place of burial are patchs of "
    "recently-turned earth. To the northeast is an open clearing used "
    "for training by residents of Karak. Off to the south and east "
    "the wooden structures of Karak can be seen, lining the main road "
    "through the town."
  );
  SetItems( ([
    ({ "cemetery", "graveyard" }) : (: GetLong :),
    ({ "graves", "grave", "earth", "patch", "patches" }) : "The only "
    "sign that this is a cemetery are the large patches of newly-turned "
    "earth and the older graves where the dirt has sunk down into the "
    "ground. No markers exist to identify the dead.",
    ({ "clearing" }) : "An open area is visible to the northeast.",
    ({ "buildings", "structures", "karak" }) : "Groups of buildings "
    "are visible to the east and south of here, lining the main road. "
    "None of them can be entered from here.",
  ]) );
  SetItemAdjectives( ([
    "graves" : ({ "fresh", "newly", "recently", "turned", "sunken" }),
    "clearing" : ({ "open" }),
    "buildings" : ({ "wooden", "town", "karak", "groups" }),
  ]) );
  SetSmell( ([
    "default" : "A faint scent of pine comes from the trees.",
  ]) );
  SetListen( ([
    "default" : "An eerie silence hangs over this place.",
  ]) );
  SetProperty("NoAttack",1);
  SetInventory( ([
    STD_OBJ "reztotem" : 1,
  ]) );
  SetExits( ([
    "northeast" : KARAK_ROOM + "clearing",
  ]) );
}
