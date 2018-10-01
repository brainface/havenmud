// by Dahaka
// Aug 2004

#include <lib.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("scale mail");
  SetId( ({"armour","mail"}) );
  SetAdjectives( ({"scale","suit","of","mail"}) );
  SetShort("a suit of scale mail armour");
  SetLong(
     "This dark suit of scale mail looks to be quiet strong. The scales appear "
     "to be strong and closely hung together, offering good protection against "
     "physical attacks. "
	   );
  SetArmourType(A_BODY_ARMOUR);
  SetValue(370);
  SetMass(400);
  SetClass(21);
  SetDamagePoints(2100);
  SetArmourClass(ARMOUR_CHAIN);
  SetVendorType(VT_ARMOUR);
  SetRepairDifficulty(38);
  SetRepairSkills( ([
     "armour smithing" : 22,
     "metal working"   : 22,
	   ]) );
  SetMaterial( ({"metal"}) );
}
