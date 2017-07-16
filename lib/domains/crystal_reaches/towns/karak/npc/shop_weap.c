// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include <vendor_types.h>
#include "../karak.h"
inherit LIB_VENDOR;

static void create() {
  vendor::create();
  SetKeyName("garret");
  SetId( ({ "forger", "orc" }) );
  SetShort("Garret the Forger");
  SetLong(
    "Garret is a large bulky half-orc with only one eye. Because of this "
    "disability, he was deemed unfit to serve as a footsoldier in the orcish "
    "Hordes, and instead opened up a weapon shop. Like many half-orcs, the "
    "fact that he is not in the army has not deterred him from practicing his "
    "fighting skills and he looks as if he would be handy with most of the "
    "weapons he creates, as he takes it upon himself to test each of them."
  );
  SetRace("half-orc");
  SetClass("fighter");
  SetGender("male");
  SetSkill("melee combat",1,1);
  SetLevel(50);
  SetReligion("Saahagoth", "Saahagoth");
  SetMorality(-300);
  SetLocalCurrency("orcteef");
  SetVendorType(VT_WEAPON);
  SetStorageRoom(KARAK_ROOM + "str_wpn");
}
