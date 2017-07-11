#include <lib.h>
inherit LIB_NPC;
static void create(){
  npc::create();
  SetKeyName("bear");
  SetId( ({ "bear" }) );
  SetAdjectives( ({ "brown", "large" }) );
  SetShort("a brown bear");
  SetLong(
    "This large mound of brown fur is a large forest bear. On "
    "top of his size, something about his demeanor hints at "
    "a particularly unpleasant disposition. A circle of worn "
    "fur surround his neck suggests that he used to wear "
    "a collar."
  );
  SetRace("bear");
  SetGender("male");
  SetClass("animal");
  SetLevel(6 + random(3));
}
