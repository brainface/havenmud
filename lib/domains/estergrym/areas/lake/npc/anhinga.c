//  coded by Tassadar 11-27-99

#include <lib.h>
#include "../lake.h"
inherit LIB_SENTIENT;

static void create() {
  ::create();
  SetKeyName("anhinga");
  SetRace("human");
  SetShort("anhinga the Husband");
  SetId( ({ "anhinga","husband" }) );
  SetAdjectives( ({ "large", "human" }) );
  
  SetGender("male");
  SetLong("This rather large human is rather stocky in build. "
          "He has large muscles flowing beneath his pale skin. "
          "His face is lean and brisk topped with flowing hair "
          "of brown. He is truly a great looking man as he cuts "
          "wood for his wife's oven.");
  SetClass("fighter");
  SetLevel(19);
  SetAction(20, ({
    "!whistle happily",
    "!say oh my wife will be happy, I have wood for her oven!",
    "!emote hacks at a log, splitting it in two.",
     "!say oh i wonder when my son, Anakin, will return...",
   }) );
  SetCombatAction(15, ({
        "!yell Garion! Come quick!",
        "!say You will not be happy about this.",
      }) );
  SetInventory( ([
        LAKE_OBJ + "/axe" : "wield first axe",
        LAKE_OBJ + "/boots" : "wear boots", 
        LAKE_OBJ + "/cape" : "wear cape",
        LAKE_OBJ + "/f_pants" : "wear pants",
   ]) );

  }
