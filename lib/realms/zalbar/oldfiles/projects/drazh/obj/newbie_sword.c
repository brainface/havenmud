// by Dahaka
// Aug 2004


#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
#include "../drazh.h"
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("sword");
  SetId( ({"sword","longsword"}) );
  SetAdjectives( ({"long","blackened","serrated"}) );
  SetShort("a serrated longsword");
  SetLong(
     "This blackened serrated longsword is the standard weapon of the watchmen "
     "fighters. The long, metal blade is fitted with a sturdy handle. This sword "
     "looks to battle tested and very durable. "
     );
  SetDamagePoints(800);
  SetValue(20);
  SetMass(120);
  SetClass(6);
  SetVendorType(VT_WEAPON);
  SetDamageType(SLASH);
  SetWeaponType("slash");
  SetRepairDifficulty(10);
  SetRepairSkills( ([
     "metal working"   : 5,
     "weapon smithing" : 5
     ]) );
  SetMaterial( ({"metal"}) );
  }