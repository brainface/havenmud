// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include <std.h>
#include "../karak.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("alai");
  SetId( ({ "alai", "alai the cheater", "cheater", "orc" }) );
  SetAdjectives( ({ "cheater" }) );
  SetShort("Alai the Cheater");
  SetLong(
    "Alai the Cheater is the greatest merchant in Karak. His exploits "
    "of deceit and trickery are well known, but even though his enemies "
    "are forewarned, he has never been defeated in a test of skills "
    "involving money. In appearance he is of average size and build for "
    "a half-orc, with green skin of a spongy appearance and only a moderate "
    "amount of muscle beneath. His eyes are canny and assessing, but not "
    "in the least bit shifty."
  );
  SetRace("half-orc");
  SetTown("Karak");
  SetClass("merchant");
  SetGender("male");
  SetLevel(25);
  SetMorality(-150);
  SetPlayerTitles( ([
    "newbie"  : "the moneygrubber",
    "mortal"  : "the Peddler of Karak",
    "hm"      : "the Swindler",
    "legend"  : "the Thrifty Procurer of Goods",
    "avatar"  : "The Master Cheater",
    "fighter" : "the Economist of War",
  ]) );
}
