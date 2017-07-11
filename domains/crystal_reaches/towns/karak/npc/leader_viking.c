// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include <std.h>
#include "../karak.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("ormzpol");
  SetId( ({ "ormzpol", "orc", "pirate" }) );
  SetAdjectives( ({ "orc", "pirate" }) );
  SetShort("Ormzpol the Reaver of Karak");
  SetLong(
    "Ormzpol is an orc who appears to have spent many years at sea, judging "
    "by the bleached color of all visible skin, contrasting with the "
    "still-dark skin of his underarms and inner forearms. His eyes seem to "
    "have a permanent squint and are surrounded by deep furrows and lines. "
    "He has also grown all of his nails long and filed them to resemble claws, "
    "likely to increase his gripping ability while aboard ship."
  );
  SetRace("orc");
  SetTown("Karak");
  SetClass("viking");
  SetGender("male");
  SetLevel(25);
  SetReligion("Saahagoth");
  SetMorality(-450);
  SetPlayerTitles( ([
    "newbie"  : "the Bilge Rat",
    "mortal"  : "the Orcish Reaver",
    "hm"      : "$N the Ocean-faring Entrepreneur",
    "legend"  : "Brigand $N the Legendary Rear Admiral of the Orcish Reavers",
    "avatar"  : "Pirate $N the Bloody-Eyed Raider",
 	 	]) );
}
