/* Drab grey newbie shirt */
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>
#include <lib.h>
inherit LIB_ARMOUR;

static void create() {
  ::create(); SetArmourClass(ARMOUR_CLOTH); SetMaterials( ({ "textile" }) ); 
  SetValue(0);
  SetArmourType(A_SHIRT);
  SetVendorType(VT_CLOTHING);
  SetKeyName("drab shirt");
  SetDamagePoints(250);
  SetRepairSkills( ([
    "textile working" : 1,
    ]) );
  SetRepairDifficulty(2);
  SetShort("a drab grey shirt");
  SetSize(SIZE_SMALL);
  SetId( ({ "shirt" }) );
  SetAdjectives( ({ "drab", "grey" }) );
  SetMaterial( ({ "textile" }) );
  SetWarmth(10);
  SetLong("This is a drab grey shirt. It is very dull, but does cover "
          "the flesh.");
  SetMass(40);
  }
