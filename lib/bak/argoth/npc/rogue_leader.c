#include <lib.h>
#include "../argoth.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
    SetKeyName("impus");
    SetShort("Impus the Broken");
    SetId( ({ "impus", "impus the broken", "broken" }) );
    SetTown("Karak");
    SetLong("Impus is the smallest, weakest, most pathetic-looking orc in "
    "all of Argoth.  He stands hunched over with his knees bent, and his "
    "eyes dash back and forth periodically.  Despite his weak appearance, "
    "there is something hidden in his visage that seems to indicate he "
    "has a few tricks up his sleeve.");
    SetRace("orc");
  SetClass("rogue");
  SetGender("male");
    SetLevel(18);
  SetInventory( ([
    ARGOTH_OBJ + "good_knife.c" : "wield knife",
      ]) );
  SetFreeEquip( ([
    ARGOTH_OBJ + "r_knife.c" : 1,
       ]) );
    SetStat("strength", 15, 1);
 }
