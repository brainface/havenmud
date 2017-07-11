#include <lib.h>
inherit LIB_SENTIENT;
#include "../hospital.h"

static void create() {
   sentient::create();
   SetProperty("noleavehospital",1);
   SetKeyName("doctor");
   SetShort("a travelling Kylin doctor");
   SetId( ({ "doctor" }) );
   SetAdjectives( ({ "wandering","travelling","kylin" }) );
   SetLong("The Kylin doctor was called to the Eclat hospital "
           "for the purpose of healing the diseased patients.  "
           "He is in charge of searching out those ill from the "
           "wasting sickness and curing them, and the young elf "
           "is arrogant and haughty.  He has little training and "
           "is not very skilled, but as a Kylin cleric, he has "
           "mastery in curing diseases, something the very skilled "
           "Eclat healers have yet to master.");
   SetRace("elf");
   SetGender("male");
   SetReligion("Kylin","Kylin");
   SetClass("priest");
   SetSkill("melee combat",1,1);
   
   SetLevel(13+random(5));
   SetSpellBook( ([
                    "mend" : 100,
                    "cure disease" : 100,
               ]) );
   SetAction(1, ({ "!cast cure disease on first patient of sickness",
                   "!emote examines nearby patients for signs "
                   "of the wasting sickness.","!emote strokes "
                   "his chin thoughtfully.","!emote calls to "
                   "another doctor to attend an especially "
                   "sick patient.","!emote looks curiously at "
                   "the walls." }) );
   SetWander(30);
}

