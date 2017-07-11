/* A simple peasant of Tairi */
#include <lib.h>
#include "../tairi.h"
#include <std.h>
inherit LIB_SENTIENT;

static void create() {
  ::create();
  SetKeyName("citizen");
  SetRace("human");
  RemoveLanguage("Enlan");
  SetLanguage("Tai", 100, 1);
  SetClass("merchant");
  SetLevel(1);
  SetGender( (random(2) ? "male" : "female") );
  SetShort("a peasant citizen of Tairi");
  SetId( ({ "peasant", "citizen" }) );
  SetAdjectives( ({ GetGender(), "of", "tairi", "peasant" }) );
  SetLong("This is a simple peasant citizen of Tairi. The quick "
          "motions of " + possessive(this_object()) + " body "
          "suggest someone used to moving quickly and with purpose.");
  SetCurrency("koken", random(20));
  if (GetGender() == "male") {
  SetInventory( ([
     STD_CLOTHING "body/loin" : "wear loincloth",
    ]) );
  } else {
  SetInventory( ([
     STD_CLOTHING "body/gray_robe" : "wear robe",
    ]) );
  }
  SetMorality(400);
  SetFriends( ({ "samurai warrior" }) );
  SetWanderSpeed(3);
}
