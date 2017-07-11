#include <lib.h>
inherit LIB_NPC;

static void create(){
  ::create();
  SetKeyName("deer");
  SetId( ({ "deer" }) );
  SetAdjectives( ({ "gray" }) );
  SetShort("a gray spotted deer");
  SetLong(
    "This deer contains white spots which cover its gray colored "
    "tight pelt. Dark black hooves stand out of its malnourished "
    "body and limbs. Some patches of his skin is missing, exposing "
    "some of his oozing internal organs. His antlers are white as "
    "snow and have been sharpened to a fine point."
  );
  SetUndead(1);
  SetRace("deer");
  SetGender("male");
  SetClass("animal");
  SetLevel(40 + random(3));
  SetMorality(-25);
}
