#include <lib.h>
inherit LIB_NPC;
#include "../castle.h"

static void create() {
   npc::create();
   SetKeyName("Lord guard");
   SetShort("a guard of the Castle's Lord");
   SetId( ({ "guard","guard of castle lord","guard of lord",
             "guard of the castle lord","guard of the lord" }) );
   SetAdjectives( ({ "castle","dwarven","lord" }) );
   SetLong("With a glazed look to his face, the dwarven guard gazes about "
           "warily, in stern attention to the surrounding space, paying "
           "close attention in particular to the Lord of the Castle.");
   SetGender("male");
   
   SetRace("dwarf");
   SetClass("fighter");
   SetLevel(28);
   SetCurrency("nuggets",random(20)+50);
   SetMorality(110);
   SetInventory( ([
                    VC_OBJ + "/axe" : "wield axe",
                    VC_OBJ + "/axe" : "wield axe",
                    "/std/armour/helmet/helm_open" : "wear helmet",
               ]) );
   SetFriends( ({ "Vale Lord","castle guard","Vale Castle soldier",
                  "human guest","dwarf guest","halfling guest",
                  "elf guest","Lord guard" }) );
}
