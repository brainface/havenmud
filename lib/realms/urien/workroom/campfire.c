
#include <lib.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("campfire");
  SetId( ({ "pit" }) );
  SetAdjectives( ({  "small" , "campfire"}) );
  SetShort( "a small campfire pit" );
  SetLong( "The pit ia circular stones shaped in a circle that "
           "lies on the ground. Inside the pit some burning "
           "thick wood has been placed inside and set ablaze. "
           "The fire in the pit burns sporadically and seems "
           "to have been built to keep this old section warm. Hot "
           "embers also inside the pit burn with a cherry color "
           "that radiates heat.");
  SetPreventGet("The very idea repels you.");
}