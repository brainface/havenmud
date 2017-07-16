//Selket@Haven
//2006
#include <lib.h>
#include "../lake.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("woolcarder");
  SetShort("an aged carder of wool");
  SetId( ({ "carder", "woolcarder" }) );
  SetAdjectives( ({ "aged", "old", "wool" }) );
  SetLong(
    "This old fossil cards wool sheared from the sheep outside "
    "her workplace while gossiping with her friends. She smells "
    "a little unwashed, as the elderly sometimes do. "
  );
  SetClass("fighter");
  SetLevel(10);
  SetGender("female");
  SetRace("gnoll");
  SetBaseLanguage("Rehshai");
  SetCurrency("deben",random(1000));
  SetInventory( ([
    LAKE_OBJ "card" : "wield card",
    LAKE_OBJ "dress" : "wear dress",
    LAKE_OBJ "sandals" : "wear sandals",
         ]) );
  SetAction(6, ({
    "!cackle",
    "!say I heard that Nisedjerkai is having ANOTHER baby. Can "
    "you believe it?",
    "!say That son of mine won't listen to me, but only an idiot "
    "would marry THAT piece of trash...",
    "!say Aai, my arthritis is acting up again.",
  }) );
}
