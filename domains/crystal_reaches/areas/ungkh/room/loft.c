//Selket@Haven
//2006
#include <lib.h>
#include "../ungkh.h"
#include <domains.h>
inherit LIB_ROOM;

static void create() {

  room::create();
  SetShort("inside a hut");
  SetClimate("indoors");
  SetAmbientLight(25);
  SetLong(
    "This is a small hayloft, little more than a space between "
    "the rafters of the hut and the roof, but Big Snow makes "
    "the best of it by storing unused and old items up here. "
    "There is also an enormous pile of sweet smelling straw "
    "here, imprinted with the shapes of two large bodies, giving "
    "the suggestion that the bed isn't the only place the "
    "giants sleep. "
    );
  SetSmell("The loft smells of hay.");
  SetListen("It is very quiet here.");
  SetItems( ([
    ({ "loft", "hayloft" }) :
       (: GetLong :),
    ({ "hay", "pile", "straw", "shapes" }) :
    "The crinkling straw has been matted by two bodies. ",
    ({ "rafters", "roof" }) : 
    "There is plenty of attic space between the rafters and roof.",
    ({ "item", "items" }) :
    "A variety of old things have come here to die. ",
    ]) );
  SetItemAdjectives( ([
    "items" : ({ "old", "unused" }),
    "pile" : ({ "enormous", "sweet", "smelling" }),
  ]) );
  SetExits( ([
    "down" : U_ROOM + "hut",
    ]) );
  SetInventory( ([
    U_NPC "wife" : 1,
    ]) );
  }
