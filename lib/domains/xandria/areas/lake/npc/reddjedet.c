//Selket@Haven
//2006
#include <lib.h>
#include "../lake.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("reddjedet");
  SetShort("Master Craftsman Reddjedet");
  SetId( ({ "master", "craftsman", "man", "reddjedet" }) );
  SetAdjectives( ({ "craft" }) );
  SetLong(
    "This strong gnoll is the overseer for all industry near "
    "Lake Rantera. He looks as though he has things firmly in "
    "hand, and they will stay that way. "
  );
  SetClass("fighter");
  SetLevel(30);
  SetGender("male");
  SetRace("gnoll");
  SetBaseLanguage("Rehshai");
  SetCurrency("deben",random(5000));
  SetInventory( ([
    LAKE_OBJ "sword" : "wield sword",
    LAKE_OBJ "tunic" : "wear tunic",
    LAKE_OBJ "sandals" : "wear sandals",
         ]) );
  SetAction(6, ({
    "!tap",
    "!say You're not getting work done just by standing there. ",
    "!say Don't make me cut your pay.",
    "!say As Master Craftsman, my duty is to make sure that all "
    "crafts made here at the Rantera Complex are up to snuff.",
  }) );
}
