// by Dahaka
// Aug 2004


#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("sword");
  SetId( ({"sword","longsword"}) );
  SetAdjectives( ({"long","serrated","blackened"}) );
  SetShort("a serrated longsword");
  SetLong(
     "This serrated longsword is one of the standard weapons of the Agents "
     "of the Council of Thirteen. This longsword has a blackened blade which "
     "makes it harder to see when the this sword will strike."
     );
  SetDamagePoints(1800);
  SetValue(250);
  SetMass(100);
  SetClass(23);
  SetVendorType(VT_WEAPON);
  SetDamageType(SLASH);
  SetWeaponType("slash");
  SetRepairDifficulty(30);
  SetRepairSkills( ([
     "metal working"   : 15,
     "weapon smithing" : 15,
     ]) );
  SetMaterial( ({"metal"}) );
}
