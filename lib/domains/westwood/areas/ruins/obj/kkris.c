//Kris blade. Usually the lucs dont pass lucky 13
//this one shows eight.
//Urien@Haven 12.24.12

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  ::create();
  SetId( ({"kris"}) );
  SetAdjectives( ({ "ivory","wavy" }) );
  SetShort("a wavy ivory kris");
  SetLong(
    "This kris sword appears to be crafted with extreme "
    "detail. The handle appears to have been carved to "
    "fit an artists rendition of a beautiful woman with "
    "long hair holding a flower. The design of the grip "
    "is very functional, allowing the wielders hand to "
    "surround the figure without much interference from "
    "design. The wilah blade has been forged to be wavy "
    "and provide a more devastating defence against "
    "harm. The wavy lucs are odd, this kris blade shows "
    "eight complete bends from tip to hilt."
  );
  SetClass(28);
  SetDamagePoints(1400);
  SetValue(random(100)+400);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetKeyName("kris");
  SetMass(75);
  SetMaterial( ({ "natural" }) );
  SetVendorType(VT_WEAPON);
  SetRepairDifficulty(25);
  SetProperty("history",
  "This blade was a collaboration of many who participated in "
  "the overall design. The hilt was whittled from a soldier "
  "who believed to have been blessed by Amelia herself. The "
  "blade was recycled from a dead elephant tusk that was "
  "found in the Westwood. This blade was forged as a prototype "
  "for the muezzins after the first GodsWar. It was passed "
  "down from the deemed King of the castle, which was more "
  "of senior guard than tyrant."
   ); 
}