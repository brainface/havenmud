
#include <lib.h>
inherit LIB_SENTIENT;


static void create() {
   sentient::create();
   SetKeyName("butterfly");
   SetShort("a large beautiful butterfly");
   SetId( ({ "butterfly" }) );
   SetAdjectives( ({ "beautiful", "large" }) );
   SetLong("This butterfly is very big. Her wings"
           " are covered in a dizzying pattern.");
   SetRace("butterfly",1);
   SetGender("female");
   SetClass("animal");
   SetLevel(3);
   AddLimb("torso",0,1,({ }) );
   AddLimb("head","torso",1,({ }) );
   AddLimb("left feeler","head",4,({ }) );
   AddLimb("right feeler","head",4,({ }) );
   AddLimb("left wing","torso",3,({ }) );
   AddLimb("right wing","torso",3,({ }) );
}
