#include <lib.h>
#include "../bathhouse.h"
inherit LIB_BARKEEP;

static void create() {
 ::create();
 SetKeyName("george");
 SetShort("a young towel boy");
 SetId( ({ "george", "boy", "towelboy" }) );
 SetAdjectives( ({ "dirty", "towel", "young" }) );
 SetRace("human");
 SetGender("male");
 SetClass("rogue");
 SetLevel(15);
 SetLimit(1);
 SetLong(
    "George looks to be a poor boy of about fifteen. His physique "
    "reflects a life spent without much food or luxury. Although meek "
    "looking, George's posture suggests that he may be a bit more dangerous "
    "with the knife in his hand than the standard street urchin."
  );
 SetInventory( ([
    BH_OBJ + "tunic" : "wear tunic",
    BH_OBJ + "knife" : "wield knife",
    BH_OBJ + "shoes" : "wear boots",
    BH_OBJ + "pants" : "wear pants",
  ]) );
 SetMenuItems( ([
    "towel" : BH_OBJ + "towel",
    ]) );
 SetAction(2, ({
    "!grin",
    "!say Can I offer you a towel?",
  }) );
 SetCurrency("oros",30);
 SetLocalCurrency("oros");
 }

/** Approved by Laoise at Wed Jul 14 22:11:24 2004. **/