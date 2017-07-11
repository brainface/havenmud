// Coded by Zeratul
// 2-23-2000

#include <lib.h>
#include <std.h>
#include "../vacazar.h"
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("vegosh");
  SetTown("Vacazar");
  SetReligion("Skadar");
  SetId( ({"vegosh","figure","shadowy figure","dark shadowy figure"}) );
  SetShort("a dark shadowy figure");
  SetLong(
     "This dark shadowy figure stands around the town, remaining unnoticed "
     "by the average traveller to this town. His hooded robe covers his "
     "entire body, except for his long snout that sticks out slightly from "
     "under his hood. "
  );
  SetRace("skaven");
  SetClass("rogue");
  SetClass("fighter");
  SetLevel(85);
  SetCurrency("vacari",random(6000));
  SetGender("male");

  SetInventory( ([
     V_OBJ + "hooded_robe" : "wear robe",
     V_OBJ + "double_knife" : "wield knife",
  ]) );
  SetCombatStyle("blade dancing");
  SetCombatStyleLevel("blade dancing", 100);
  SetFriends( ({
     "skaven","barzurar","sarakar","healer","vegor",
  }) );
  SetAction(1, ({
     "The shadowy figure walks around quietly.",
  }) );
  SetCombatAction(10, ({
     "!yell Enemies! Kill them all!",
     "!growl violently",
     "!say Die!",
  }) );
  }
