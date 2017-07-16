#include <lib.h>
inherit LIB_NPC;
#include "../castle.h"

static void create() {
   npc::create();
   SetKeyName("castle guard");
   SetShort("a castle guard");
   SetId( ({ "guard" }) );
   SetAdjectives( ({ "castle","dwarven" }) );
   SetLong("With a glazed look to his face, the dwarven guard gazed about "
           "warily, in stern attention to the surrounding space.");
   SetGender("male");
   SetRace("dwarf");
   SetClass("fighter");
   SetLevel(28);
   SetCurrency("nuggets",random(20)+50);
   SetMorality(80);
   SetInventory( ([
                    VC_OBJ + "/axe" : "wield axe",
                    VC_OBJ + "/axe" : "wield axe",
                    "/std/armour/helmet/helm_open" : "wear helmet",
               ]) );
   SetFriends( ({ "Vale Lord","castle guard","Vale Castle soldier",
                  "human guest","dwarf guest","halfling guest",
                  "elf guest","Lord guard" }) );
}
