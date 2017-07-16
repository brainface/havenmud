//-- Torak@Haven --//
#include <lib.h>
#include <std.h>
inherit LIB_LEADER;
static void create() {
  leader::create();
  SetKeyName("mmk");
  SetId( ({ "mmk", "shaman" }) );
  SetShort("mmk the Wise");
  SetLong("Mmk is one of the oldest ogres still alive, well past the "
          "age of 40.  He is a venerable and wise old man who knows "
          "many ways of his faith and his people.  The only thing "
          "that seems to keep him on Kailie is his wisdom and faith "
          "to the Kuthar religion.");
  SetReligion("Kuthar");
  SetRace("ogre");
  SetClass("shaman");
  SetTown("Ungkh");
  SetGender("male");
  SetLevel(100);
  SetNoJoin(1);
  SetCurrency("skins", random(100) + 100);
  SetTaughtSpheres( ({ 
    "clerical necromancy", "clerical",
    "clerical evokation", "magical", "magical evokation",
    "magical necromancy",
    }) );
  SetUniqueSkills( ([
    "necromancy" : 2,
    "planar magic" : 2,
    ]) );
  SetInventory( ([
    "/std/weapon/blunt/mace.c" : "wield mace",
    ]) );
 }
