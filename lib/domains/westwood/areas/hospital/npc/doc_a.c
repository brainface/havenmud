#include <lib.h>
inherit LIB_SENTIENT;
#include "../hospital.h"

static void create() {
   sentient::create();
   SetProperty("noleavehospital",1);
   SetKeyName("doctor");
   SetShort("a wandering doctor");
   SetMorality(700);
   SetId( ({ "doctor" }) );
   SetAdjectives( ({ "wandering","eclat" }) );
   SetLong("The doctor has been given general training, and has "
           "yet to choose a specific path to follow.  Usually "
           "it is the females who specialize themselves in areas, "
           "and the males wander about the hospitals or the world "
           "itself to heal patients.  He is tired and stressed "
           "out, but he has spent years in training with the "
           "hope that he would be able to work someplace like this, "
           "and would never leave.");
   SetRace("muezzin");
   SetGender("male");
   SetReligion("Eclat","Eclath");
   SetClass("priest");
   
   SetSkill("melee combat",1,1);
   SetLevel(43+random(5));
   SetSpellBook( ([
                    "mend" : 100,
                    "dispel poison" : 100,
                    "resurrect" : 100,
                    "mend heavy" : 100,
               ]) );
   SetAction(5, ({ "!cast mend on first patient","!cast mend on "
                   "second patient","!cast mend on third patient",
                   "!cast mend on fourth patient","!emote looks "
                   "around and sighs at all the work ahead of "
                   "him.","!speak in oiseau Why can't we have more "
                   "workers?","!speak in oiseau I wish more would "
                   "come to help us.","!sigh","!look" }) );
   SetInventory( ([
               ]) );
   SetFriends( ({ "doctor","Zoa","patient","receptionist" }) );
}

