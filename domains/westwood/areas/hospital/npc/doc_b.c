#include <lib.h>
inherit LIB_NPC;
#include "../hospital.h"

static void create() {
   npc::create();
   SetProperty("noleavehospital",1);
   SetKeyName("doctor");
   SetShort("a doctor of poison");
   SetMorality(700);
   SetId( ({ "doctor","doctor of poison","muezzin" }) );
   SetAdjectives( ({ "female","stationary","calm" }) );
   SetLong("This calm muezzin has been put in the stationary assignment "
           "of the poisoned patients at this hospital.  She is calm "
           "despite the ailing people surrounding her, confident in "
           "her abilities to dispel the poison.  Her eyes are kind but "
           "her face is sad, as if she has lost a few too many patients "
           "in the past, and as if there are a few too many to try and "
           "heal here.");
   SetGender("female");
   SetRace("muezzin");
   SetReligion("Eclat","Eclat");
   SetClass("priest");
   SetSkill("melee combat",1,1);
   
   
   SetLevel(30+random(5));
   SetSpellBook( ([
                    "dispel poison" : 100,
                    "mend" : 100,
                    "resurrect" : 100,
               ]) );
   SetAction(5, ({ "!cast dispel poison on first poisoned patient",
                   "!cast dispel poison on second poisoned patient",
                   "!cast dispel poison on third poisoned patient",
                   "!cast mend on fourth patient",
                   "!emote smiles at a patient.",
                   "!emote pauses for a moment, looking sad and "
                   "discouraged, but quickly resumes her smiling "
                   "expression of laughter and joy.", }) );
   SetInventory( ([
                    H_OBJ + "vial_f" : random(2),
               ]) );
   SetFriends( ({ "doctor","Zoa","patient","receptionist" }) );
}
