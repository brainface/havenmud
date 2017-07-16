#include <lib.h>
#include <std.h>
#include "../keryth.h"

inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("elkanah");
  SetId( ({ "elkanah", "necromancer" }) );
  SetRace("goden");
  SetClass("necromancer");
  SetTown("Keryth");
  SetGender("female");
  SetStat("intelligence", 40, 1);
  SetLevel(35 + random(6));
  SetCurrency("senones", 700);
  SetTaughtSpheres( ({
    "magical necromancy"
  }) );
  SetShort("Elkanah the Expert in Necromancy");
  SetPlayerTitles( ([
    "newbie"   : "the Student Necromancer of Keryth",
    "mortal"   : "the Proficient Necromancer",
    "hm"       : "the Manipulator of Undeath",
    "legend"   : "the Superior Manipulator of Undeath",
    "avatar"   : "the All Powerful Commander of the Undead",
    "rogue"    : "the Pilferer of the Decaying"
  ]) );
  SetFreeEquip( ([
    STD_POLE + "staff" : 1
  ]) );
  SetLong("Tall and imposing, Elkanah's eyes burn with evil fervor and keen "
          "intelligence.  Mystical energy crackles in the air around her, "
          "creating an eerie cloak of sorts.");
  SetInventory( ([ K_OBJ + "/decorated_staff" : "wield staff" ]) );
  SetMorality(-900);
}
