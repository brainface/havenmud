#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
item::create();
  SetKeyName("sceptre");
  SetId( ({ "sceptre", "pole" }) );
  SetAdjectives( ({ "fool's", "long", "thick" }) );
  SetShort("a fool's sceptre");
  SetLong(
    "This is a short, thick sceptre made from a strong and durable wood. The"
    " top has a small painted face on it with a series of bells danging off of it."
    " Down the legnth of the sceptre, a checker pattern of red and white has been"
    " painted on it."
  );
  SetMass(20); 
  SetValue(100);
  SetDamagePoints(1150);
  SetWeaponType("pole");
  SetDamageType(BLUNT);
  SetClass(14);
  SetHands(1);
  SetVendorType(VT_WEAPON);
  SetMaterial( ({ "wood" }) );
  SetRepairSkills( ([
    "wood working" : 5,
    "weapon smithing" : 5,
    ]) );
  SetRepairDifficulty(5);
}
