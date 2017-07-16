//Alex@Haven
//2006
#include <lib.h>
#include <vendor_types.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create(){
  armour::create();
  SetKeyName("loincloth");
  SetId( ({ "cloth", "loincloth"}) );
  SetShort( "a loincloth" );
  SetArmourClass(ARMOUR_CLOTH);
  SetMaterials( ({ "textile" }) );
  SetLong(
    "This bit of cloth conceals and protects only "
    "the most vital of a brave hunter's appendages.");
  SetValue(5);
  SetMaterial( ({"natural"}) );
  SetWarmth(8);
  SetVendorType(VT_CLOTHING);
  SetDamagePoints(1000);
  SetMass(10);
  SetArmourType(A_PANTS);
  SetRepairDifficulty(8);
  SetSmell( "It smells like other loincloths.");
}
