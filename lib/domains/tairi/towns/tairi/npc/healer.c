/* a healer for tairi */
#include <lib.h>
#include "../tairi.h"
inherit LIB_HEALER;

static void create() {
  ::create();
  SetKeyName("tsai");
  SetShort("Huang Tsai, an Taisoka healer");
  SetId( ({ "huang", "tsai", "healer" }) );
  SetAdjectives( ({ "tai", "so", "ka", "haung" }) );
  SetRace("human");
  SetTown("Tairi");
 RemoveLanguage("Enlan");
  SetLanguage("Tai", 100, 1);
  SetLocalCurrency("koken");
  SetClass("priest");
  SetSkill("evokation", 1, 1);
  SetSkill("healing", 1, 1);
  SetSkill("melee combat", 1, 1);
  SetLevel(15);
  SetGender("male");
  SetCurrency("koken", random(200));
  SetLong("Huang Tsai is the best healer that Tairi has to "
          "offer. He will gladly tend to your wounds, or "
          "even resurrect you, if you but make a small "
          "donation to the Temple.");
  SetFees( ([
    "resurrect" : 100,
    "magic" : 10,
    "stamina" : 1,
    "health" : 3,
    "restore" : 50,
  ]) );
}
