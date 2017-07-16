// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include <std.h>
#include "../karak.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("impus");
  SetShort("Impus the Broken");
  SetId( ({ "impus", "impus the broken", "broken", "orc" }) );
  SetLong(
    "Impus is the smallest, weakest, most pathetic-looking orc in "
    "all of Karak. He stands hunched over with his knees bent, and his "
    "eyes dash back and forth periodically. Despite his weak appearance, "
    "there is something hidden in his visage that seems to indicate he "
    "has a few tricks up his sleeve."
  );
  SetRace("orc");
  SetClass("rogue");
  SetGender("male");
  SetLevel(18);
  SetTown("Karak");
  SetReligion("Saahagoth");
  SetMorality(-500);
  SetInventory( ([
    KARAK_OBJ + "rknife" : "wield knife",
  	]) );
  SetPlayerTitles( ([
    "newbie" : "the Kleptomanic",
    "mortal" : "the Silent Hand",
    "hm"     : "the Shadow Master",
    "legend" : "the Midnight Mirage",
    "avatar" : "the Black Hand of Midnight",
  ]) );  
}
