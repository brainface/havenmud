#include <lib.h>
inherit LIB_NPC;
static void create(){
    npc::create();
    SetKeyName("mule");
    SetId( ({ "mule" }) );
    SetAdjectives( ({ "gentle" }) );
    SetShort("a gentle mule");
    SetLong(
      "This gentle mule serves the smith in Parva. His bent ears lean forward "
      "in simple acceptance of his lot."
      );
    SetRace("horse", "mule");
    SetGender("male");
    SetClass("animal");
    SetLevel(8);
    SetLimit(1);
}
