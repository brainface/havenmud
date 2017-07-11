//Selket@Haven
//2006

#include <lib.h>
#include "../ungkh.h"
#include <domains.h>
inherit LIB_ROOM;

static void create() {

  room::create();
  SetShort("inside a dark tent");
  SetClimate("indoors");
  SetLong(
    "The inside of this tent is smokey and smells like rancid animal fat, "
    "because the hides strung together to build it were never cured. Furs "
    "and makeshift beds lie on the floor, strewn with bits of gnawed meat "
    "and half-eaten animal carcasses. The only exit is back out the tent flap."
  );
  SetSmell( ([
    "default" :
    "The noxious smell of smoke and decaying meat drifts through the tent.",
    ]) );
  SetListen("The noise of Ungkh is greatly reduced inside the tent.");
  SetItems( ([
    ({"hides", "tent", "walls"}) :
    "The hides that make this tent are the skins of wolves. The veins and "
    "insulating bits of fat still cling to the hides.",
    ({"furs", "fur", "beds"}) : "The furs are smelly, but probably comfortable "
    "enough for even the most discriminating ogre.",
    ({"meat","animals","carcasses"}) : "It looks grimy and unfit for eating.",
  ]) );
  SetItemAdjectives( ([
    "beds" : ({ "makeshift" }),
    "meat" : ({ "gnawed"}),
    "carcasses" : ({ "half-eaten" }),
  ]) );
  SetExits( ([
    "out" : U_ROOM + "road02",
    ]) );
  SetInventory( ([
    U_NPC "slashogre" : 3,
  ]) );
  }
