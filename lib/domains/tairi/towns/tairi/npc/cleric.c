/* The cleric of Tai-so-ka */
#include <lib.h>
#include <std.h>
#include "../tairi.h"
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("loa");
  SetShort("Huang Loa, the Contemplator of Taisoka");
  SetId( ({ "huang", "loa", "contemplator" }) );
  SetAdjectives( ({ "huang", "contemplator" }) );
  SetRace("human");
  SetBaseLanguage("Tai");
  SetClass("contemplator");
  SetLevel(40);
  SetGender("male");
  SetCurrency("koken", random(50) );
  SetLong("Huang Loa is a spiritual guide of the Path, "
          "the local religion. He has a look of peace and personal "
          "harmony that only the truly faithful can achieve.");
  SetReligion("Taisoka");
  SetTown("Tairi");
  SetFreeEquip( ([
     STD_CLOTHING "body/loin" : 1,
     STD_POLE     "staff" : 1,
    ]) );
  SetPlayerTitles( ([
     "newbie" : "the Seeker of Harmonious Existance",
     "mortal" : "the Spirtual Path Seeker",
     "hm"     : "the Peaceful and Harmonious",
     "legend" : "the One with Self",
     "avatar" : "the Pure Instrument of the Heavens",
    ]) );
  SetInventory( ([
      STD_CLOTHING "body/loin" : "wear loincloth",
      STD_POLE     "staff" : "wield staff",
    ]) );
}
