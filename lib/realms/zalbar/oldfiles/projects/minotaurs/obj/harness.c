#include <lib.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("harness");
  SetId( ({ "harness"}) );
  SetAdjectives( ({ "leather" }) );
  SetShort("a leather harness");
  SetLong("This leather harness does not provide much protection to the "
          "wearer but does give them the flexibility to kill their "
          "oppenents. The harness wraps around the stomache and lower "
          "back with two long leather straps holding up the harness over "
          "the wearer's shoulders. There are pteriges, leather straps "
          "reinforced with metal studs, hanging below the waist protecting "
          "the upper legs.");
  SetVendorType(VT_ARMOUR);
  SetMass(50);
  SetValue(1000);
  SetDamagePoints(1500);
  SetArmourClass(ARMOUR_REINFORCED);
  SetArmourType(A_BODY_ARMOUR);
  SetRestrictLimbs( ({"torso","left leg","right leg"}) );
  SetMaterial( ({"leather","metal"}) );
  SetWarmth(10);
  SetSize(SIZE_LARGE);
  SetRepairSkills( ([
     "armour smithing" : 25,
     "leather working" : 25,
     "metal working"   : 25,
     ]) );
  SetRepairDifficulty(25);
}