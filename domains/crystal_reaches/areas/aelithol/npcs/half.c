#include <lib.h>
#include "../aelithol.h"
inherit LIB_NPC;
    static void create() {
    npc::create();
    SetKeyName("farmer");
    SetId( ({ "farmer", "halfling", "halfling farmer"}));
    SetAdjectives( ({"happy"}) );
    SetShort("a halfling farmer");
    SetLong("Just as his father before him, this farmer has "
      "made a living from the land.  Along with other farmers, "
      "he has collaberated to form the village.  The village "
      "gives all the halflings in the valley theoretical protection "
      "as well as much needed comfort in an uncertain world.");
    
    SetRace("halfling");
    SetClass("rogue");
    SetGender("male");
    SetLevel(7);
    SetMorality(300);
    SetInventory( ([
      OBJS + "/s_blue" : "wear pants",
      OBJS + "/s_tunic" : "wear tunic",
    ]) );    
    SetAction(3, ({ "The halfling smiles happily." })); 
    SetFriends( "halfling" );
}
