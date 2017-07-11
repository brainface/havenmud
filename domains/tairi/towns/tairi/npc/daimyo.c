/* the daimyo of clan minamoto */
#include <lib.h>
#include <position.h>
#include "../tairi.h"
inherit LIB_MAYOR;

static void create() {
  ::create();
  SetKeyName("yori");
  SetShort("Minamoto Yori, Daimyo of Tai province");
  SetLong("Minamoto Yori is the Daimyo of this province, meaning he "
          "is the local warlord that rules here. His brow is furled "
          "by years of arrogance looking down upon the workers that "
          "fill his needs in the town.");
  SetRace("human");
  RemoveLanguage("Enlan");
  SetLanguage("Tai", 100, 1);
  SetGender("male");
  SetId( ({ "minamoto", "yori", "daimyo" }) );
  SetTown("Tairi");
  SetTax(200);
  SetLocalCurrency("koken");
  SetClass("cavalier");
  SetLevel(75);
  SetMorality(250);
  SetInventory( ([
      TAI_RI_OBJ "kabuto" : "wear helmet",
      TAI_RI_OBJ "oyoroi" : "wear oyoroi",
      TAI_RI_OBJ "katana" : "wield katana",
  ]) );
  SetCurrency("koken", random(5000) );
  SetAction(1, ({
      "!say Become my vassal!",
      "!emote looks around the room haughtily.",
    }) );
  SetPosition(POSITION_SITTING);
  SetFriends( ({ "samurai" }) );
  SetTownRanks( ({
    ({ "Slave", "Slave" }),
    ({ "Citizen", "Citizen" }),
    ({ "Danshaku", "Danshaku" }),
    ({ "Sishaku", "Sishaku" }),
    ({ "Hakushaku", "Hakushaku" }),
    ({ "Koshaku", "Koshaku" }),
    ({ "Taikoshaku", "Taikoshaku" }),
    }) );
}
