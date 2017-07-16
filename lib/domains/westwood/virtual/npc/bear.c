#include <lib.h>
inherit LIB_NPC;
static void create(){
  npc::create();
  SetKeyName("bear");
  SetId( ({ "bear" }) );
  SetShort("a brown bear");
  SetLong("This large mound of brown fur is a forest bear, one that "
         "seems to have an unpleasant disposition on top of it.");
   
  SetRace("bear");
  SetGender("male");
  SetClass("animal");
  SetLevel(6);
}
