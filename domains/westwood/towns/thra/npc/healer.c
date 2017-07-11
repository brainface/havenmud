#include <lib.h>
#include "../thra.h"
inherit LIB_HEALER;

static void create() {
  ::create();
  SetKeyName("Jen Ursu");
  SetShort("Jen Ursu the Healer");
  SetId( ({ "jen", "healer", "ursu","gelfling" }) );
  SetAdjectives( ({ "jen", }) );
  SetRace("gelfling");
  SetFriends( ({ "gelfling" }) );
  SetGender("female");
  SetClass("druid");
  SetLevel(40);
  SetCurrency("cuicui", 70);
  SetMorality(1200);
  SetLong(
    "Jen Ursu is the wisest healer of all Thra. Her chipper attitude brings the most solemn occassions "
    "into the realm of the normal, and her belief in the will of nature is a fine example for all gelflings."
    );
  SetLocalCurrency("cuicui");
  SetFees( ([
    "resurrect" : 5,
    "stamina" : 1,
    "health" : 3,
    "restore" : 6,
    ]) );
  SetTown("Thra");
  SetLimit(1);
  SetSpellBook( ([
    "vermin horde" : 100,
    "wall of wood" : 100,
    "ice storm"    : 100,
    ]) );
  SetCombatAction(75, ({
  	"!cast wall of wood",
  	"!cast ice storm",
  	"!cast vermin horde",
  	}) );
}
