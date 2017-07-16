#include <lib.h>
#include "../karak.h"
#include <std.h>
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("Rommel");
  SetFriends( ({ "dealer" }) );
  SetTown("Karak");
  SetRace("orc");
  SetGender("male");
  SetClass("fighter");
  SetLevel(30+random(7));
  SetShort("Rommel, Field Marshal of Karak-Varn");
  SetLong("Rommel is a big and tough orc, and although not as massive or ugly "
          "as Dealer, he seems incredibly quick and highly skilled. "
          "Those wishing to join Karak-Varn's Fighter Battalion should "
          "speak with him.");
  SetInventory( ([
                       K_OBJ + "/runes" : "wield sword",
                   K_OBJ + "/runea" : "wear armor"  ]) );
  SetFreeEquipment( ([
    STD_WEAPON "slash/shortsword" : 1,
    STD_WEAPON "hack/hand-axe" : 1,
    ]) );
}
