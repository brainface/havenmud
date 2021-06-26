/*  Mahk 2021 come at me
   A vampire Leader.
*/

#include <lib.h>
#include <std.h>
#include "../parva.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("claret");
  SetShort("Claret the Thirsty (undead)");
  SetLong(
    "Most tales of vampires involve dreary castles, well-dressed ominous "
    "nobles, perhaps even seductively dressed pale-faced ladies possessing "
    "otherworldly grace. A drunken beggar surrounded in fleas and "
    "stinking like pickled death is what this particular story involves "
    "instead."
  );
  SetRace("half-elf");
  SetUndead(1);
  SetUndeadType("vampire");
  SetTown("Parva");
  SetBaseLanguage("Enlan");
  SetMorality(-200);
  SetGender("female");
  SetClass("vampire");
  SetLevel(80);
  SetCurrency("oros",random(600) + 40);
  SetInventory( ([
    PARVA_OBJ "vamp_robe" : "wear robe",
  ]) );

  SetAction(3, ({
     "!say Care for a drink?",
     "!say Can I have your liver once you're... done with it?",
     "!emote hiccups loudly and a small cloud of gnats fly out.",
     "!say You should drink a lot and pass out. No reason.",
  }) );

  SetFreeEquip( ([
    STD_MELEE "brass_knuckles" : 1,
  ]) );

  SetPlayerTitles( ([
      "newbie"      : "the Newborn Gnat",
      "mortal"      : "the Wee Flea",
      "hm"          : "the Monstrous Mite",
      "legend"      : "the Lich-borne Lice",
      "avatar"      : "the Motley Mosquito",
      "rogue"       : "the Larcenous Leech",
      "fighter"     : "the Drinker of Drunks",
      "necromancer" : "the Liver-Gnawer",
      ]) );
  }

