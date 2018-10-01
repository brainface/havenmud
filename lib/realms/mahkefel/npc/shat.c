#include <lib.h>
#include <std.h>
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("shatner");
  SetShort("a pot bellied canadian");
  SetShort("a pot bellied canadian");
  SetId( ({ "canadian","shatner" }) );
  SetAdjectives( ({ "pot", "bellied", "canadian" }) );
  SetRace("human");
  SetClass("sailor");
  SetLevel(5);
  SetGender("male");
  SetLong("This balding man seems to be deeply troubled by some horrible tragedy.");
  SetCurrency("imperials", random(2)+1 );
  SetAction(10, ({"!yell KHAAAAAANNNNNNNNN!"}));
}
