/* Zeratul@Haven */

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("axe");
  SetShort("a sleek axe");
  SetId( ({ "axe" }) );
  SetAdjectives( ({ "sleek" }) );
  SetLong(
     "Despite the age of this axe, it still looks as if it has been recently "
     "forged as new. The wooden handle has an engraved symbol on it, which "
     "resembles a sword standing upright with flames behind it. "
  );
  SetMass(50);
  SetValue(500);
  SetVendorType(VT_WEAPON);
  SetWeaponType("hack");
  SetDamageType(SLASH);
  SetClass(18);
  SetDamagePoints(550);
  SetProperty(
     "history","This weapon was an issued axe to a soldier long ago. "
  );
  SetProperty(
     "magic","This weapon has been magically preserved from aging. "
  );
//  SetMaterial( ({ "metal" }) );
//  SetRepairDifficulty(25);
//  SetRepairSkills( ([
//     "metal working" : 1,
//     "weapon smithing" : 1,
//  ]) );
  }

