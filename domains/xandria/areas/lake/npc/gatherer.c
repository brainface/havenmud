//Selket@Haven
//2006
#include <lib.h>
#include "../lake.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("gatherer");
  SetShort("a papyrus gatherer");
  SetId( ({ "gatherer" }) );
  SetAdjectives( ({ "papyrus" }) );
  SetLong(
    "This is a young papyrus gatherer, who often wades out "
    "into the shallows of Lake Rantera to pick the tall plants "
    "used in making scrolls. She seems quite able to take care "
    "of herself, probably because of all the hiking she has to "
    "do each day.");
  SetClass("fighter");
  SetLevel(10);
  SetGender("female");
  SetRace("gnoll");
  SetBaseLanguage("Rehshai");
  SetCurrency("deben",random(1000));
  SetInventory( ([
       LAKE_OBJ + "scythe" : "wield scythe",
       LAKE_OBJ + "dress" : "wear dress",
       LAKE_OBJ + "basket" : 1,
         ]) );
  SetAction(6, ({
    "!say The dunes are alive...with the sound of music...",
    "!emote skips casually from place to place.",
  }) );
}
