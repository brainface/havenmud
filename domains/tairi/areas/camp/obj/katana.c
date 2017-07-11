/* A graceful katana */
#include <damage_types.h>
#include <vendor_types.h>
#include <lib.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("aged katana");
  SetId( ({ "katana" }) );
  SetAdjectives( ({ "aged" }) );
  SetShort("an aged katana");
  SetClass(13);
  SetDamagePoints(2500);
  SetMass(180);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetVendorType(VT_WEAPON);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([
     "metal working" : 6,
     "weapon smithing" : 6,
    ]) );
  SetRepairDifficulty(50);
  SetLong(
     "This blade has a long thin blade with a gentle curve to it. Rust"
     " marks are speckled along the length of the blade. Once a very"
     " formidable weapon, it now is just a memory of what deadly"
     " potential it once had."
  );
  SetValue(450);
}
