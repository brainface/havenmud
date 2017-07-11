// Proxy

#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("bird");
  SetId( ({ "bird", "animal_wander" }) );
  SetShort("a blue bird");
  SetLong(
     "This feathery flyer is covered in a deep shade of blue. This small bird "
     "flies from place to place, searching for food. "
  	 );
  SetInventory( ([
  	]) );
  SetGender(random(2) ? "male" : "female");
  SetRace("bird");
  SetClass("animal");
  SetWander(3);
  SetLimit(2);
  SetLevel(1);
  SetAction(1, ({
    "!emote chirps. ",
    "!emote sings happily. ",
    "!emote sings loudly. ",
    "!emote chirps happily. ",
  	}) );
}
