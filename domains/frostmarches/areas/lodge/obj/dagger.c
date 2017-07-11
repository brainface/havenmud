#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include "../lodge.h"
inherit LIB_ITEM;
static void create() {
  item::create();
  SetKeyName("dagger");
  SetId( ({"dagger"}) );
  SetShort("a glazed dagger");
  SetLong("This dagger is very unique.  The handle is glazed, made "
  "of pure glass.  A gold rim has been applied at the end of the "
  "handle.  The blade itself, is so amazing it seems unrealistic.  "
  "It is thick near the wield of the dagger and gradually thins "
  "near the point.  Embelished in gold on the sides, is a symbol that "
  "resembles flames reaching for an undying soul.  The dagger itself "
  "is long and painfully sharp.  It is deadly promising and should not "
  "fall into the wrong hands.");
  SetClass(12);
  SetAdjectives( ({"glazed"}) );
  SetValue(500);
  SetDamageType(SLASH);
  SetVendorType(VT_WEAPON);
  SetWeaponType("knife");
  SetDamagePoints(500);
  SetMaterial( ({ "mithril", "natural"}) );
  SetRepairSkills( ([
  "mithril working" : 10,
  "weapon smithing" : 10,
  ]) );
  SetRepairDifficulty(11);
}


/* Approved by Duuktsaryth on Sat Feb 19 17:26:09 2000. */
