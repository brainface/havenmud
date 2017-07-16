#include <lib.h>
inherit LIB_NPC;

static void create(){
  ::create();
  SetKeyName("rabbit");
  SetId( ({ "rabbit" }) );
  SetAdjectives( ({ "gray" }) );
  SetShort("a gray rabbit");
  SetLong(
    "This gray rabbit is larger and more mutated than any of "
    "his regular bloodline. Large black eyes stand out of his "
    "gray head and his razor sharp teeth stick out of his "
    "foaming mouth. His nails have been unattended or treated "
    "mainly because of the curls and splits at the ends."
  );
  SetUndead(1);
  SetClass("animal");
  SetRace("rodent");
  SetGender("male");
  SetLevel(35 + random(3));
  SetMorality(-25);
}
