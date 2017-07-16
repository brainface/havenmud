//Illura@haven
//Nov 2010
#include <lib.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <armour_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  
  SetKeyName("boots");
  SetShort("knee-high leather boots");
  SetId( ({"boots"}) );
  SetAdjectives( ({"knee-high", "leather"}) );
  SetLong(
    "These boots are well made of burnished leather. They "
    "are quite scuffed."
    );
  SetMass(60);
  SetArmourClass(ARMOUR_LEATHER);
  SetWarmth(5);
  SetProperty("multiples", 1);
  SetValue(70);
  SetSize(SIZE_MEDIUM);
  SetDamagePoints(400);
  SetMaterial( ({"leather"}) );
  SetRepairSkills( ([
     "leather working" : 8,
     ]) );
  SetRepairDifficulty(40);
  SetArmourType(A_BOOT);
  SetVendorType(VT_ARMOUR);

  }

