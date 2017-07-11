//mahkefel '11: kobold helper for goden warship
#include <lib.h>
#include <std.h>
#include <damage_types.h>
#include <domains.h>
inherit LIB_PIRATE;

static void create() {
  ::create();
  SetRace("kobold");
  SetGender("male");
  SetClass("fighter");
  SetClass("sailor");
  SetSkill("dirty tricks",1); // just for hock
  SetLevel(1);
  SetKeyName("pirate");
  SetId( ({ "kobold","boy" }) );
  SetShort("a tiny kobold cabin boy");
  SetAdjectives( ({ "tiny","kobold","cabin","boy" }) );
  SetLong(
    "This diminuitive furry creature seems hell bent on causing as much "
    "mayhem and destruction as possible, which given his small stature likely "
    "isn't very much."
  );
  SetAction(10, ({
    "!emote whistles out of tune.",
    "!emote carefully swabs the deck.",
  }) );
  SetCombatAction(10, ({
    "!emote frantically careens into you with his mop.",
    "!emote swings his mop in a wide arc, missing everything.",
    "!snarl",
  }) );
  SetInventory( ([
    INNERSEA_ENCOUNTERS + "obj/mop" : "wield mop",
  ]) );
  SetCaptainAggressiveness(80);
  SetResistance(ALL_PHYSICAL, "low");
  SetResistance(ALL_ELEMENTS|MAGIC,"medium");
  SetProperty("pirate", "goden");
  SetShipWander(1);
  SetCurrency("senones",5000);

  SetTown("Keryth");
  SetMinLevel(1);
  SetMaxLevel(180);

  SetCombatStartVerb("hock");
}

