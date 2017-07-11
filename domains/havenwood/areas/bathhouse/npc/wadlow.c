
#include <lib.h>
#include "../bathhouse.h"
inherit LIB_BARKEEP;

static void create() {
 ::create();
 SetKeyName("wadlow");
 SetShort("Wadlow, the proprietor");
 SetId( ({ "wadlow", "proprietor", "man" }) );
 SetAdjectives( ({ "proprietor", "bald", "fat", "old", "bath",
    "bathhouse" }) );
 SetRace("human");
 SetGender("male");
 SetClass("merchant");
 SetLimit(1);
 SetLevel(10);
 SetLong(
    "Old Wadlow is a bald, fat, old man. Years of stress and hard work "
    "have hardened his once soft face. Cleanshaven and otherwise neat, "
    "Wadlow does not reflect the current condition of his establishment. "
    "Wadlow is the calm of the storm, and looks very stoic, yet his "
    "hardened muscles, hidden under layers of fat, would not be "
    "something to test."
  );
 SetInventory( ([
    BH_OBJ + "tunic" : "Wear tunic",
    BH_OBJ + "pants" : "wear pants",
    BH_OBJ + "shoes" : "Wear boots",
  ]) );
 SetAction(3, ({
    "!say Can I interest you in a towel? Soap perhaps?",
    "!say Oi, do you people smell! Come buy some soap!",
    "!smile",
    "!grunt",
    "!say Oh... I'm getting a bit old, sorry, but can you hurry it up?",
  }) );
 SetMenuItems( ([
    "towel" : BH_OBJ + "towel",
    "loincloth" : BH_OBJ + "loincloth",
//    "soap" : BH_OBJ + "soap",
    ]) );
 SetLocalCurrency("oros");
 SetCurrency("oros",50);
 }

/** Approved by Laoise at Wed Jul 14 22:11:32 2004. **/