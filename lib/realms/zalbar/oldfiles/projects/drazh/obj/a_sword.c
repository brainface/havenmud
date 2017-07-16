// by Dahaka
// Aug 2004


#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("sword");
  SetId( ({"sword","shortsword"}) );
  SetAdjectives( ({"short","serrated","blackened"}) );
  SetShort("a shortsword");
  SetLong(
     "This serrated shortsword is one of the standard weapons of the Agents "
     "of the Council of Thirteen. This shortsword is small enough to hide "
     "under the agent's robes. The blackened blade also makes it harder to "
     "see when the agent will strike."
     );
  SetDamagePoints(1400);
  SetValue(250);
  SetMass(100);
  SetClass(20);
  SetVendorType(VT_WEAPON);
  SetDamageType(SLASH);
  SetWeaponType("slash");
  SetRepairDifficulty(25);
  SetRepairSkills( ([
     "metal working"   : 15,
     "weapon smithing" : 15,
     ]) );
  SetMaterial( ({"metal"}) );
}
