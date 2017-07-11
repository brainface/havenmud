//Selket@Haven
//2006
#include <lib.h>
#include "../newbie.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("potter");
  SetShort("a portly apprentice potter");
  SetId( ({ "apprentice", "potter" }) );
  SetAdjectives( ({ "portly", "apprentice" }) );
  SetLong(
    "This jovial little fellow spends most of his time down "
    "by the mud forming pots and staying away from his master, "
    "who would surely give him harsher chores.");
  SetClass("fighter");
  SetMorality(200);
  SetLevel(5);
  SetGender("male");
  SetRace("elf");
  SetBaseLanguage("Alatherian");
  SetCurrency("deben",random(100));
  SetInventory( ([
       NEWBIE_OBJ + "pot" : "wield pot",
         ]) );
  SetAction(6, ({
    "!say Oh, it's the potter's life for me.",
    "!say I love the feel of mud squishing between my toes.",
    "!say Don't tell my master I'm here, okay?",
  }) );
}
