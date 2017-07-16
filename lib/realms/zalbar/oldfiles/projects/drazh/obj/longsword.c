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
  SetAdjectives( ({"long","blackened"}) );
  SetShort("a blackened longsword");
  SetLong(
     "This blackened serrated longsword is the standard weapon of the watchmen "
     "fighters. The long, metal blade is fitted with a sturdy handle. This sword "
     "looks to be very durable. "
     );
  SetDamagePoints(1200);
  SetValue(200);
  SetMass(180);
  SetClass(20);
  SetVendorType(VT_WEAPON);
  SetDamageType(SLASH);
  SetWeaponType("slash");
  SetRepairDifficulty(23);
  SetRepairSkills( ([
     "metal working"   : 10,
     "weapon smithing" : 10,
     ]) );
  SetMaterial( ({"metal"}) );
  }