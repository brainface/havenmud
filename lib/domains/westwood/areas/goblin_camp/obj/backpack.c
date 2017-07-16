#include <lib.h>
#include <size.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>

inherit LIB_STORAGE;

static void create()
{
::create();
SetKeyName("backpack");
SetId( ({ "backpack", "pack" }) );
SetAdjectives( ({ "large", "canvas" }) );
SetShort("a large canvas pack");
SetLong(
  "This pack is made of a burlap canvas that is very strong.  It "
  "has buckles and straps all over it making look almost scary, but "
  "when worn the pack seems very comfortable.  It is dark brown "
  "color with dull brass buckles everywhere.");
SetMass(45);
SetValue(100);
SetCanClose(1);
SetClosed(1);
SetMaxCarry(2000);
//SetRestrictLimbs( ({"torso"}) );
SetMaterial( ({ "textile" }) );
SetRepairSkills( ([ "textile working" : 1 ]) );
SetRepairDifficulty(2);
SetVendorType(VT_CLOTHING);
}                 
