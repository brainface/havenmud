#include <lib.h>
#include <domains.h>
#include <std.h>
#include <damage_types.h>
inherit LIB_PIRATE;

static void create() {
  ::create();
  SetKeyName("nereid");
  SetShort("a nereid guardian");
  SetId( ({ "nereid","nymph","guardian" }) );
  SetAdjectives( ({ "sea", "nereid", "guardian" }) );
  SetRace("nymph");
  SetReligion("Damhair");
  SetTown("Parva"); // You lose rep in parva for killing an instrument of the drowned god.
  SetClass("priest");
  SetSkill("sailing",1,1);
  SetSkill("navigation",1,1);
  SetSkill("pierce combat",1,1);
  SetSkill("swimming",1,1);
  SetLevel(200);
  SetLong("This is a nereid, or sea nymph. She resembles a beautiful"
    " elven maiden, but her skin is covered with blue scales, and"
    " gill slits pulse on her neck. Unlike her more gregarious"
    " land bound cousins, she is quite violent, and is tasked by"
    " the god Damhair with cleansing the seas of corruption."
  );
  SetGender("female");
  SetCaptainAggressiveness(110);
  SetInventory( ([
    INNERSEA_ENCOUNTERS "obj/narwhale" : "wield horn",
  ]) );
  SetProperty("pirate", "nereid");
  SetShipWander(1);
  SetCurrency("imperials", 40000);
  SetResistance(SHOCK|HEAT, "weakness");
  SetResistance(MAGIC, "medium");
  SetResistance(COLD, "high");
  SetResistance(WATER, "immune");
  SetFirstCommands("cast imbue weapon on horn");
  SetCombatAction(15, ({
    "!cast immersion",
    "!cast serenity",
  }) );
  SetMinLevel(100);
  SetMaxLevel(300);
  SetBoarder(INNERSEA_ENCOUNTERS "elemental_water/brine");
  SetFirstMate(INNERSEA_ENCOUNTERS "elemental_water/squid");
  SetPassengerAttacker(INNERSEA_ENCOUNTERS "squid");
  SetEncounterDifficulty(5); // Might be a little hard. Screw it!
}

// spell up
void heart_beat() {
  ::heart_beat();
  if (sizeof(GetMagicProtectionNames()) < 5) {
    eventForce("cast protective storm");
  }
}


