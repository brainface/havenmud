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
    "The inside of this tent is hazy with the overpowering scent of urine, "
    "because the ogres that make their home here are too lazy to go outside "
    "for that task. Scraps of soiled leather and furs reek in every corner "
    "of the tent, and the only exit is out."
  );
  SetSmell("The noxious scent of urine fills the tent.");
  SetListen("The noise of Ungkh is greatly reduced inside the tent.");
  SetItems( ([
    ({"hides", "tent", "walls"}) :
    "The hides that make this tent are the skins of wolves. The veins and "
    "insulating bits of fat still cling to the hides.",
    ({"scrap", "scraps", "leather", "fur", "furs", "corner"}) : 
    "The scraps are everywhere, smelly and covered in mouldering ogre pee.",
  ]) );
  SetItemAdjectives( ([
    "leather" : ({ "soiled" }),
  ]) );
  SetExits( ([
    "out" : U_ROOM + "road09",
    ]) );
  SetInventory( ([
    U_NPC "poleogre" : 3,
  ]) );
  }
