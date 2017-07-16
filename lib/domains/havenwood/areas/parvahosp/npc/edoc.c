#include <lib.h>
#include <damage_types.h>
#include "../ph.h"
inherit LIB_NPC;

int HealEm();

static void create() {
   ::create();
   SetKeyName("doctor");
   SetShort("an exhausted doctor");
   SetId( ({ "doctor" }) );
   SetAdjectives( ({ "exhausted","young","eclat","eclatish" }) );
   SetGender(({ "male","female" })[random(2)]);
   SetLong(
     "Pushed beyond all limits, this exhausted young doctor "
     "has sought sanctuary in the storage room, searching for "
     "a slim moment of peace and rest. Dark circles create "
     "odd shadow effects under " + possessive(this_object()) +
     " eyes.  Despite the obvious signs of wear and tear, "
     "the cleric seems resilient."
   );
   
   SetRace(({ "muezzin","halfling","gelfling"})[random(3)]);
   SetClass("priest");
   SetLevel(6+random(3));
   SetReligion("Eclat","Eclat");
   SetCurrency("cuicui",10);
   SetCurrency("oros",20);
   SetMorality(1000);
   SetMeleeAttackString("fists");
   SetMeleeDamageType(BLUNT);
   SetSpellBook( ([
     "fortify" : 100,
   ]) );
   SetAction(5, ({ 
     "!emote closes " + possessive(this_object()) + " eyes "
     "for a moment and breaths deeply.",
     "!emote sighs.",
     "!emote 's head droops." 
   }) );
   SetCombatAction(15, ({ 
     "!cast fortify",
   }) );
}
