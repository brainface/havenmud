//mahkefel '12: dark dwarf boarder
#include <lib.h>
#include <std.h>
#include <damage_types.h>
#include <domains.h>
inherit LIB_PIRATE;

static void create() {
  string gender;
  string possessive;
  string pronoun;
  mapping inventory = ([]);

  ::create();

  // base statistics
  SetRace("dark-dwarf");
  SetClass("fighter");
  SetClass("sailor");
  AddSkill("berserking",1);
  SetLevel(1);

  SetKeyName("mercenary");
  SetShort("a dark-dwarf mercenary");

  // random gender
  gender = random(2) ? "male" : "female";
  possessive = "his";
  pronoun = "he";
  if (gender == "female") {
    possessive = "her";
    pronoun = "she";
  }

  // descriptive text
  SetGender(gender);
  SetLong(
    "This mercenary looks like " + pronoun + " has a job "
    "to do that " + pronoun + " intends to do well. "
    "What they're doing on an averath naval ship isn't clear, "
    "but the Duke is known to possess large coffers, and "
    "the dwarves of Dalnairn's loyalty to coin is infamous."
  );
  SetId( ({ "mercenary","dwarf", "dark-dwarf" }) );
  SetAdjectives( ({ "dark-dwarf" }) );

  SetInventory( ([
    INNERSEA_ENCOUNTERS "obj/broad_axe" : "wield axe",
  ]) );

  // misc stuff
  SetCombatAction(25, ({
    "!cleave",
  }) );
  SetFirstCommands( ({
    "shout It's time to earn our pay!",
  }) );

  SetProperty("pirate","averath");

  SetMorality(-50);
}

