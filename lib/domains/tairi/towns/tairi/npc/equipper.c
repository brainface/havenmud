// Tairi Equipper
// Aerelus

#include <lib.h>
#include <std.h>
#include "../tairi.h"
inherit LIB_EQUIPPER;

static void create() {
  ::create();
  SetKeyName("eri");
  SetShort("Tanaka Eri the Charitable");
  SetLong("Tanaka Eri is a very generous woman. She spends most of her "
    "time collecting various items, mostly weapons, to give to less "
    "fortunate people in Tairi. One could attract her attention by "
    "requesting assistance.");  
  SetRace("human");
  RemoveLanguage("Enlan");
  SetLanguage("Tai", 100, 1);
  SetGender("female");
  SetId( ({ "tanaka", "eri", "charitable" }) );
  SetTown("Tairi");
  SetClass("fighter");
  SetLevel(20);
  SetMorality(300);
  SetLimit(1);
  SetLevelLimit(10);
  SetFreeEquipment( ([
    "oyoroi" : TAI_RI_OBJ "newbie_oyoroi",
    "katana" : TAI_RI_OBJ "katana",
    "wakasashi" : TAI_RI_OBJ "wakasashi",
    "fishing pole"  : STD_FISHING "pole",
    "club"  : STD_WEAPON "newbie_club",
    "knife" : STD_WEAPON "small_knife",
    "epee" : STD_WEAPON "pierce/epee",
    "bow"   : STD_WEAPON "projectile/bow_long_newbie",
    ]) );
  SetInventory( ([    
      TAI_RI_OBJ "oyoroi" : "wear oyoroi",      
  ]) );
  SetCurrency("koken", random(30) );
  SetAction(1, ({
      "!say Allow me to help you!",      
    }) );  
  SetFriends( ({ "samurai" }) );
}
