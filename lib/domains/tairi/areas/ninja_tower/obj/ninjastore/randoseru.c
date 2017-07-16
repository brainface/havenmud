/* changed big bulky pack to a smaller sized pack
    Zalbar 10/30/07
 */

#include <lib.h>
#include <armour_class.h>
inherit LIB_STORAGE;
#include <armour_types.h>
#include <size.h>
#include <vendor_types.h>
static void create() 
  {
  ::create();
  SetKeyName("randoseru");
  SetId( ({ "randoseru", "pack", "backpack" }) );
  SetAdjectives( ({ "small","black" }) );
  SetShort("a randoseru");
  SetLong("This randoseru is a small black backpack made from durable "
  				"and heavy cloth. This pack can carry a small amount of equipment. "
          "It can be worn on one's torso, or slung over an arm.");
  SetMass(100);
  SetValue(150);
  SetVendorType(VT_CLOTHING);
  SetDamagePoints(1500);
  SetMaterial( ({ "textile" }) );
  SetWarmth(10);
  SetRepairSkills( ([ "textile" : 1,]) );
  SetRepairDifficulty(30);
  SetCanClose(1);
  SetClosed(1);
  SetMaxCarry(500);
  }
