//
// Brak the keeper of the swing
// Created by Athalie
//
#include <lib.h>
#include "../bazaar.h"
inherit LIB_NPC;

static void create() {
  npc::create();
   SetKeyName("brak");
   SetId( ({ "brak", "keeper of the swing" }) );
   SetShort("Brak, Keeper of the Swing");
   SetLong("This massive man stands guard over the swing. Although "
     "a fierce looking creature, he is often caught grinning or giving "
     "pieces of candy to children.");
   
   SetMorality(500);
   SetRace("giant");
   SetGender("male");
   SetClass("fighter");
   SetSkill("melee combat",1,1);
   SetLevel(15);
   
   RemoveLanguage("Loyavenku");
   SetLanguage("Sprith", 100, 1);
   SetAction(5, ({
     "!emote grins stupidly.",
     "!speak no ticket, no swing!",
   }) );
   SetCombatAction(5, ({
     "!speak Brak no want to fight! Leave Brak alone!",
     "!emote frowns at you.",
   }) );
}
