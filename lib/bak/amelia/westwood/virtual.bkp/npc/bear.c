#include <lib.h>
inherit LIB_NPC;
static void create(){
    npc::create();
    SetShort("a brown bear");
  SetLong("This large mound of brown fur is a forest bear, one that "
         "seems to have an unpleasant disposition on top of it.");
    SetLevel(6);
  SetId( ({ "bear" }) );
    SetKeyName("bear");
    SetRace("bear");
    SetGender("male");
  SetClass("animal");
}
