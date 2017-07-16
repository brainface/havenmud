#include <lib.h>
inherit LIB_NPC;
#include "../hiker.h"

static void create() {
   npc::create();
   SetProperty("hikernoleave",1);
   SetKeyName("young fisherman");
   SetShort("a young fisherman");
   SetId( ({ "fisherman","man","boy","fisher" }) );
   SetAdjectives( ({ "young" }) );
   SetLong("The young man whistles happily, chewing in an absentminded "
           "way on a piece of grass stuck in his mouth.  It seems like "
           "he spends a lot of time fishing, and he has calluses in "
           "all the right places to prove it.  Being young and strong, "
           "he probably doesn't have much difficulty pulling fiesty "
           "little fish out of the water.");
   SetGender("male");
   SetRace("human");
   SetMorality(-50);
   SetClass("rogue");
   SetSkill("fishing",1,1);
   SetLevel(30);
   SetAction(2, ({ "!fish with pole","!emote whistles.", }) );
   SetInventory( ([
                    H_OBJ + "fpole" : "fish with pole",
                    H_OBJ + "fknife" : "wield knife in right hand",
                    H_OBJ + "boot1" : "wear boot on left foot",
                    H_OBJ + "boot2" : "wear boot on right foot",
               ]) );
}
