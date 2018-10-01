// Zalbar Aug 08


#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <size.h>
#include <armour_types.h>
#include <armour_class.h>

inherit LIB_ARMOUR;

static void create(){
  ::create();
  SetKeyName("manica");
  SetId( ({ "arm guard","manica"}) );
  SetShort("a manica");
  SetLong(
    "The manica is an arm guard made of curved and overlapping iron "
    "plates. Each plate is held together by a leather backing. The "
    "manica is held in place by a couple of leather straps going over "
    "the wearer's opposite shoulder."); 
  SetDamagePoints(2000);
  SetValue(1000);
  SetMass(100);
  SetMaterial( ({"metal","leather"}) );
  SetWarmth(5);
  SetSize(SIZE_LARGE);
  SetRepairSkills( ([
     "armour smithing" : 25,
     "leather working" : 25,
     "metal working"   : 25,
     ]) );
  SetRepairDifficulty(25);
  SetVendorType(VT_ARMOUR);
  SetSize(SIZE_LARGE);
  SetArmourType(A_LONG_GLOVE);
  SetArmourClass(ARMOUR_PLATE);
  SetRestrictLimbs(({"left arm"}));
}
