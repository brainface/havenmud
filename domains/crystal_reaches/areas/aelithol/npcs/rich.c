#include <lib.h>
#include "../aelithol.h"
inherit LIB_NPC;
    static void create() {
    npc::create();
    SetKeyName("halfling");
    SetId( ({ "halfling", "wealthy halfling", "a wealthy halfling" }) );
    SetAdjectives( ({"rich", "wealthy"}) );
    SetShort("a wealthy halfling");
    SetLong("This is Ohen Twiddletoe, the current owner of the "
      "Twiddletoe family estate.  He is dressed in light leather "
      "armour, which is a commodity in the valley as well as an "
      "extravagance.");                
    
    SetRace("halfling");
    SetClass("rogue");
    SetLevel(7);
    SetGender("male");
    SetMorality(200);
    SetAction(4, ({ "The halfling stares at the ground." }));
    SetCurrency( ([
      "rounds" : 200,
    ]) );
    SetInventory( ([
      OBJS + "/s_leather" : "wear leathers",
    ]) );
}
