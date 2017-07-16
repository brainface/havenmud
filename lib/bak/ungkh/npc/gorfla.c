//-- TORAK --//

#include <damage_types.h>
#include <lib.h>
#include "../ungkh.h"

inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("gorfla");
  SetRace("goblin");
  SetClass("necromancer");
  SetUniqueSkills( ([
    "planar magic" : 0,
    "projectile attack" : 1,
    "pole attack" : 0,
    "stealth" : 1,
    "projectile defense" : 3,
    ]) );
  SetLevel(58);
  SetGender("male");
  SetTown("Ungkh");
  SetReligion("Kuthar");
  SetMorality(0);
  SetId( ({
    "gorfla",
    }) );
  SetAdjectives( ({
    }) );
  SetShort("gorfla");
  SetLong("A dark figure, this goblin seems to embody the form "
          "and fear of death itself, enjoyably.  Gorfla is the "
          "town necromancer.");
  SetCurrency("skins", 170 + random(200));
  SetTaughtSpheres( ({
    "magical", "magical necromancy",
    "magical enchantment",
/*
    "magical divination",
*/
    }) );
  SetFreeEquip( ([
    "/std/weapon/projectile/bow_long_newbie" : 1,
    ]) );
  SetPlayerTitles( ([
    "newbie"     :  "the Neophyte Necromancer",
    "mortal"     :  "the Summoner of Ancients",
    "hm"         :  "the Voice of the Dead",
    "legend"     :  "the One Whom All Dead Cherish",
    ]) );
  }

