#include <lib.h>
#include "../rome.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("Cerasys");
  SetShort("Cerasys, a retired merchant");
  SetId( ({ "cerasys", "merchant" }) );
  SetAdjectives( ({ "retired" }) );
  SetRace("human");
  SetTown("Sanctum");
  RemoveLanguage("Enlan");
  SetLanguage("Imperial", 100, 1);
  SetClass("merchant");
  SetGender("male");
  SetLevel(22);
  SetLong("Cerasys is an old man, though in his youth he was the "
          "reknowned for being the best merchant from Sanctum. His knowledge of the roads "
          "is only surpassed by his knowledge of coins. Though he is "
          "long retired he still teaches anyone who would ask the ways "
          "of the merchant.");
 SetPlayerTitles( ([
      "newbie"  : "the Seeker of Fortunes",
      "mortal"  : "the Merchant of Via Imperials",
      "hm"      : "the High Merchant of the Peninsula",
      "avatar"  : "the Merchant Prince of Sanctum",
      "fighter" : "the Caravaner of Sanctum",
      "sailor"  : "the Merchant of the South Seas",
    ]) );
  SetFreeEquip( ([
    "/std/obj/fishing/pole" : 1,
    "/std/weapon/knife/small_knife" : 1,
     ]) );
  SetInventory( ([
    ROME_OBJ "toga_rich" : "wear toga",
  ]) );
  }
