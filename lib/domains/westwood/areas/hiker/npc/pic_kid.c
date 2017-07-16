#include <lib.h>
#include <damage_types.h>
inherit LIB_NPC;
#include "../hiker.h"

static void create() {
   mapping inv;
   npc::create();
   SetProperty("hikernoleave",1);
   SetMorality(50);
   SetKeyName("child picnicker");
   SetShort("a child picnicker");
   SetId( ({ "picnicker","child" }) );
   SetAdjectives( ({ "child" }) );
   SetLong("The child looks young and happy, unblemished by years of "
           "hard labor.  It appears that " + nominative(this_object()) +
           " has spent a lot of time playing actively outside, running "
           "around and climbing trees and enjoying " + 
           reflexive(this_object()) + " at picnics.");
   switch(random(2)) {
      case 0:
      SetGender("male");
      break;
      case 1:
      SetGender("female");
      break;
   }
   SetRace("muezzin");
   SetClass("rogue");
   SetAction(2, ({ "!emote plays with some grass, weaving it into a "
                   "little mat.","!emote digs a hole with " 
                   + possessive(this_object()) + " hands.",
                   "!emote gathers together some worms.",
                   "!emote finds some stray strawberries and "
                   "eats them.","!emote smiles happily.",
                   "!emote finds a stick and waves it around "
                   "expirementally before discarding it." }) );
   SetMeleeAttackString("fists");
   SetMeleeDamageType(BLUNT);
   inv = ([
            H_OBJ + "juice" : 1,
            H_OBJ + "fruit" : 1,
         ]);
   switch(random(2)) {
      case 0:
      inv += ([ H_OBJ + "stick" : "wield stick" ]);
      SetSkill("blunt combat",1,1);
      break;
      case 1:
      inv += ([ H_OBJ + "mat" : "wear mat on head" ]);
      break;
   }
   SetInventory(inv);
   SetLevel(5+random(3));
   SetMorality(500);
}