// Coded by Zeratul 11-27-99
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include "../lake.h"
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("rock");
  SetId( ({ "rock","small rock" }) );
  SetAdjectives( ({ "small" }) );
  SetShort("a small rock");
  SetLong("This rock is small and heavy. It is dark "
     "in color and well rounded. This rock looks to have been made from "
     "silt deposits from a lake. "
     );
  SetMass(80);
  SetValue(3);
  SetVendorType(VT_WEAPON);
  SetClass(3);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetDamagePoints(300);
  SetDestroyOnSell(1);
  SetMaterial( ({ "natural" }) );
  SetRepairDifficulty(4);
  SetRepairSkills( ([
     "natural working" : 0,
     ]) );
  SetProperty("history","This rock is from the Estergrym "
     "Mountains. It has been formed by years and years of "
     "silt deposits building on one of another. ");
}
