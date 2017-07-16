// mahkefel 2012: cheap copy of dark elf caravel dude
#include <lib.h>
#include <domains.h>
#include <std.h>
#include <size.h>
inherit LIB_PIRATE;

static void create() {
  mapping inventory = ([]);

  ::create();
  SetKeyName("deck hand");
  switch(random(3)) {
    case 0:
      SetRace("human");
      break;
    case 1:
      SetRace("half-elf");
      break;
    case 2:
      SetRace("half-orc");
      break;
  }
  
  SetBaseLanguage("Enlan");

  SetShort("a parvan deck hand ("+GetRace()+")");
  SetId( ({ "hand",GetRace() }) );
  SetAdjectives( ({ "parvan","deck" }) );

  SetTown("Parva");
  SetReligion("Damhair");
  SetProperty("pirate","parva");

  SetClass("sailor");
  SetGender("male");
  if (random(2)) SetGender("female");

  SetLevel(75);
  SetLong(
    "This scurvy looking sailor seems a little on the "
    "disreputable and dishonest side. "+capitalize(possessive()) +
    " breath reeks of an unholy mixture of grog and onions."
  );

  SetCaptainAggressiveness(50);
  SetCurrency("oros", 500);

  if (GetSize() == SIZE_LARGE){
    inventory[INNERSEA_ENCOUNTERS "obj/motley_breeches_l"] = "wear breeches";
    inventory[INNERSEA_ENCOUNTERS "obj/motley_vest_l"] = "wear vest";
  } else {
    inventory[INNERSEA_ENCOUNTERS "obj/motley_breeches"] = "wear breeches";
    inventory[INNERSEA_ENCOUNTERS "obj/motley_vest"] = "wear vest";
  }
  inventory[INNERSEA_ENCOUNTERS "obj/cutlass"] = "wield cutlass",
  SetInventory( inventory );

  SetMinLevel(75);
  SetMaxLevel(125);
  SetEncounterDifficulty(0); // easier on nubs

  SetAction(5, ({
    "!say Yo ho ho!",
    "!say Where's yer rum?",
  }) );

  SetCombatAction(25, ({
    "!run through",
    "!cackle",
    "!sneer",
  }) );
}

