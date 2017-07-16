//mahkefel '10: gave unique description
#include <lib.h>
#include <std.h>
#include <damage_types.h>
#include <domains.h>
inherit LIB_PIRATE;

static void create() {
  ::create();
  SetRace("goden");
  SetGender("male");
  SetClass("rogue");
  SetClass("sailor");
  SetSkill("dirty tricks",1);
  SetLevel(1);
  SetKeyName("pirate");
  SetId( ({ "pirate" }) );
  SetShort("a small goden pirate");
  SetAdjectives( ({ "goden", "small" }) );
  SetLong(
    "This goden sailor is of relatively short stature, but he possesses "
    "a nervous agility and lithe build that suggest him a dangerous combatant "
    "in close quarters."
  );
  SetAction(1, ({
    "!emote stares around confidently.",
    "!emote eyes your purse.",
  }) );
  SetCombatAction(10, ({
    "!bumrush",
  }) );
  SetInventory( ([
    INNERSEA_ENCOUNTERS + "obj/rigging_knife" : "wield knife",
    INNERSEA_ENCOUNTERS + "obj/motley_breeches" : "wear breeches",
  ]) );
  SetCaptainAggressiveness(80);
  SetResistance(ALL_PHYSICAL, "medium");
  SetResistance(ALL_ELEMENTS|MAGIC,"high");
  SetProperty("pirate", "goden");
  SetShipWander(1);
  SetCurrency("senones", 20000);

  SetTown("Keryth");
  SetMinLevel(80);
  SetMaxLevel(180);
  SetBoarder(INNERSEA_ENCOUNTERS "pirate/smallboarder");
  SetCombatStartVerb("bumrush");
}

