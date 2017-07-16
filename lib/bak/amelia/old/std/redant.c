#include <lib.h>
inherit LIB_NPC;

static void create() {
   npc::create();
   SetKeyName("red ant");
   SetShort("a red ant");
   SetId( ({ "ant","bug" }) );
   SetAdjectives( ({ "red" }) );
   SetLong("Three segments make up the body of the red ant,  with "
           "six little legs poking out the ends and two little "
           "antennas waving around out of the head.");
   SetGender("neuter");
   SetRace("insect");
   SetLevel(2);
   SetClass("animal");
   AddLimb("third segment","torso",2, ({ }) );
   AddLimb("right antenna","head",5, ({ }) );
   AddLimb("left antenna","head",5, ({ }) );
}
