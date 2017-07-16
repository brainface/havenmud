//Selket@Haven
//2006
#include <lib.h>
#include "../lake.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("beadmaker");
  SetShort("a meticulous beadmaker");
  SetId( ({ "beadmaker", "maker" }) );
  SetAdjectives( ({ "meticulous", "bead" }) );
  SetLong(
    "The beadmaker is a nervous female gnoll who seems very "
    "absorbed in her task of making tiny beads of clay and "
    "other materials.");
  SetClass("fighter");
  SetLevel(15);
  SetGender("female");
  SetRace("gnoll");
  SetBaseLanguage("Rehshai");
  SetCurrency("deben",random(1000));
  SetInventory( ([
       LAKE_OBJ + "awl" : "wield awl",
       LAKE_OBJ + "dress" : "wear dress",
       LAKE_OBJ + "sandals" : "wear sandals",
         ]) );
  SetAction(6, ({
    "!tongue",
    "!emote spills beads on the floor without noticing.",
    "!say I'll be right with you....",
  }) );
}
