#include <lib.h>
#include <std.h>
#include "../keryth.h"

inherit LIB_EQUIPPER;

static void create() {
  ::create();
  SetKeyName("oluf"); 
  SetShort("Oluf the Helpful");
  SetId( ({ "oluf", "aider", "equipper" }) );
  SetAdjectives( ({"helpful"}) );
  SetLong("This fragile and weak looking Goden is Oluf the Helpful.  "
          "Pharez, mayor of Keryth, has commanded Oluf to assist any "
          "and all young citizens of Keryth whom may need help before "
          "exploring the world outside of Keryth.");
  SetRace("goden");
  SetClass("merchant");
  SetTown("Keryth");
  SetGender("male");
  SetLevel(10);
  SetCurrency("senones", 900);
  SetLevelLimit(10);
  SetFreeEquipment( ([
    "shirt" : STD_CLOTHING "shirt",
    "shoes" : STD_CLOTHING "shoes",
    "pants" : STD_CLOTHING "pants",
    "coat"  : STD_CLOTHING "coat",
    "fishing pole"  : STD_FISHING "newbie_pole",
    "sword" : K_OBJ "/newbiesword",
    "club"  : STD_WEAPON "newbie_club",
    "knife" : STD_WEAPON "small_knife",
    "staff" : STD_WEAPON "staff",
    "axe"   : STD_WEAPON "hatchet",
    ]) );
  SetAction(5, ({
        "!say ask me for help and you may be surprised.",
    }) );
  SetInventory( ([
    "/std/armour/pants/leggings" : "wear leggings"
    ]) );
  SetMorality(-250);

}
