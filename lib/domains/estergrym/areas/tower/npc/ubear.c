#include <lib.h>
inherit LIB_NPC;

static void create(){
  ::create();
  SetKeyName("bear");
  SetId( ({ "bear" }) );
  SetAdjectives( ({ "gray", "large" }) );
  SetShort("a gray bear");
  SetLong(
    "This bear is covered in a long hair skin with patches "
    "removed from it. Through the holes the insides of this "
    "undead being can be seen. Large paws protrude from his "
    "torso revealing his sharp and deadly claws."
  );
  SetUndead(1);
  SetRace("bear");
  SetGender("male");
  SetClass("animal");
  SetLevel(47 + random(3));
  SetMorality(-20);
}
