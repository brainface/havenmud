#include <lib.h>
inherit LIB_NPC;
#include "../hospital.h"

static void create() {
   npc::create();
   SetProperty("noleavehospital",1);
   SetKeyName("doctor");
   SetShort("a dark doctor");
   SetMorality(700);
   SetId( ({ "doctor" }) );
   SetAdjectives( ({ "dark","eclat" }) );
   SetLong("The doctor is for the underground section of the "
           "Eclatish hospital.  She has had special training "
           "to prepare her for the intense work of dealing "
           "with nosferatu and other night-loving creatures.  "
           "Her extra training has made her more proficient than "
           "the average doctor.");
   SetRace("muezzin");
   SetGender("female");
   SetReligion("Eclat","Eclatish");
   SetClass("cleric");
   SetSkill("healing",1,1);
   SetSkill("enchantment",1,1);
   SetSkill("melee attack",1,1);
   SetSkill("melee defense",1,1);
   SetLevel(47+random(5));
   SetSpellBook( ([
                    "mend" : 100,
                    "dispel poison" : 100,
                    "resurrect" : 100,
                    "mend heavy" : 100,
               ]) );
   SetAction(5, ({ "!emote puts her hands on a nearby patient.",
                   "!cast mend on first patient","!cast mend on "
                   "second patient","!cast mend on third "
                   "patient","!emote glances around, wishing "
                   "she could see better.","!cast dispel poison "
                   "on first patient","!cast dispel poison "
                   "on second patient","!cast dispel poison on "
                   "third patient","!cast mend on fourth patient",
                   "!cast dispel poison on fourth patient" }) );
   SetFriends( ({ "doctor","Zoa","patient","receptionist" }) );
}

