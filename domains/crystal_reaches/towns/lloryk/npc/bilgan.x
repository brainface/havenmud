
#include <lib.h>
#include <daemons.h>
#include "../path.h"
#define SHOP_OBJ   LLORYK "obj/smoke/"
inherit LIB_BARKEEP;

static void create() {
 ::create();
 SetKeyName("Bilgan");
 SetShort("Bilgan, a halfling Shopkeep");
 SetId( ({ "bilgan", "shopkeep", "halfling" }) );
 SetAdjectives( ({ "halfling"}) );
 SetRace("halfling");
 SetGender("male");
 SetClass("merchant");
 SetMorality(-50);
 SetLimit(1);
 SetLevel(20);
 SetLong(
    "Bilgan the shopkeep has a very shady look to him. His "
    "wild black hair stands up in patches near the crown of "
    "his head as if he just woke up from rest. His eyes are "
    "dark brown, which compliment his generic face. "
    "His body appears quite frail but strong enough to last a "
    "bit against violent attackers in his shop."
  );
 SetAction(25, ({
    "!say Welcome to my shop!",
    "!say Check out my fine selection of refreshment!",
    "!say Try our \"special\" dark vodka. Heh heh...",
    "!smile warmly",
    "!say Our druid customers love the chai leaf roll.",
  }) );
 SetInventory( ([
   LLORYK "obj/smoke/bvest"   : "wear leather vest",
   ]) );
 SetMenuItems( ([
    "cigar"           : SHOP_OBJ  "cigar",
    "chai leaf roll"  : SHOP_OBJ  "chaileaf",
    "wooden pipe"     : SHOP_OBJ  "lpipe",
    "vodka"           : SHOP_OBJ  "vodka",
    ]) );
 SetLocalCurrency("rounds");
 SetCurrency("rounds", random(10));
}
