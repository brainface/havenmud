// modified by Dahaka
// Aug 2004

#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("breastplate");
  SetId( ({ "breastplate" }) );
  SetShort("a blackened breastplate");
  SetAdjectives( ({"blackened"}) );
  SetLong(
    "This blackened breastplate has two symbols engraved "
    "in red on each breast. The larger symbol is the an "
    "equilateral triangle, consisting of three overlapping "
    "lines, with one of the points facing down, which "
    "represents the Soirin faith. The smaller symbol is "
    "a giant rat head with horns inside a pentagram. "
    "This piece of armour is only given to those that call "
    "themselves Agents of the Council of Thirteen."
    );
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([
    "metal working"   : 10,
    "armour smithing" : 10,
    ]) );
  SetVendorType(VT_ARMOUR);
  SetValue(1000);
  SetMass(750);
  SetDamagePoints(1800);
  SetArmourClass(ARMOUR_PLATE);
  SetArmourType(A_VEST);
  SetRestrictLimbs( ({ "torso" }) );
  SetSize(SIZE_MEDIUM);
}
