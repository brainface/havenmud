#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("dirk");
  SetId( ({ "dirk" }) );
  SetAdjectives( ({ "stone" }) );
  SetShort("a stone dirk");
  SetLong(
    "This dirk has been crafted from a gray stone. A rather "
    "small double-sided blade rests in a stone hilt which has "
    "been tied to a wooden handle. The components of this "
    "dirk have been secured together by a thin wax twine. A "
    "leaf design has been burned into the handle."
  );
  SetClass(10);
  SetDamagePoints(700);
  SetValue(350);
  SetWeaponType("knife");
  SetDamageType(PIERCE);  
  SetMass(40);
  SetMaterial( ({ "natural" }) );
  SetRepairSkills( ([
     "natural working" : 15,
     "weapon smithing" : 15,
  ]) );
  SetRepairDifficulty(5);
  SetVendorType(VT_WEAPON);
}

