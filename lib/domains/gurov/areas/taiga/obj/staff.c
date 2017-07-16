//Illura@Haven
//Sept 2009
//staff of ancients
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("staff of ancients");
  SetId( ({ "staff" }) );
  SetAdjectives( ({ "ancients", "ancient", "of" }) );
  SetShort("a staff of ancients");
  SetLong(
    "This two-handed staff is made entirely of metal imbued "
    "with an icy blue color. The top is surmounted by a piece "
    "of skymetal the size of a human hand."
  );
  SetVendorType(VT_WEAPON);
  SetDamagePoints(2500);
  SetClass(35);
  SetValue(2000);
  SetMass(100);
  SetWeaponType("pole");
  SetHands(2);
  SetMaterial( ({"metal"}) );
  SetRepairSkills( ([
     "metal working" : 50,
  ]) );
  SetRepairDifficulty(50);
  SetDamageType(BLUNT|COLD);
}
