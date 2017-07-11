// Coded by Zeratul
// 3-24-2000

#include <lib.h>
#include "../vacazar.h"
inherit LIB_NPC;

int type = random(2);
string CheckSetShort();


static void create() {
  npc::create();
  SetKeyName("watchman");
  SetId( ({"watchman","skaven watchman","skaven"}) );
  SetRace("skaven");
  SetClass("fighter");
  SetLevel(35 + random(10));
  
  SetAction(3, ({
     "!yawn",
     "!emote stands at attention.",
  }) );
  SetCombatAction(4, ({
     "!say Die!",
     "!yell Die!!",
  }) );

  if (type == 0) {
  SetGender("male");
  SetAdjectives( ({"watchman","male"}) );

  SetShort("a strong skaven watchman");
  SetLong(
     "This strong looking skaven is one of the watchmen of the city. He partols "
     "the streets, enforcing the law to all of those who live in and visit "
     "the town. "
  );
  SetInventory( ([
     V_OBJ + "guard_knife" : "wield knife",
     V_OBJ + "hooded_robe" : "wear robe",
  ]) );
  }

  else if (type == 1) {
  SetGender("female");
  SetAdjectives( ({"watchman","female"}) );

  SetShort("an agile watchman");
  SetLong(
     "This agile looking skaven is one of the watchmen of the city. She partols "
     "the streets, enforcing the law to all of those who live in and visit "
     "the town. "
  );
  SetInventory( ([
     V_OBJ + "axe" : "wield axe",
     V_OBJ + "hooded_robe" : "wear robe",
  ]) );
  }
  }
