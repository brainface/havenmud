//Alex@Haven
//2006
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create(){
  armour::create();
  SetKeyName( "dress" );
  SetId ( ({ "dress" }) );
  SetAdjectives( ({ "stained" }) );
  SetShort( "a stained dress" );
  SetArmourClass(ARMOUR_CLOTH);
  SetMaterials( ({ "textile" }) );
  SetLong(
    "this rudely woven dress has seen quite a bit "
    "of use. It is stained and patched in places. Grubby "
    "handprints mar the skirts.");
  SetMass(30);
  SetValue(30);
  SetWarmth(10);
  SetDamagePoints(850);
  SetMaterial("textile");
  SetRepairDifficulty(5);
  SetArmourType(A_BODY_ARMOUR);
}
