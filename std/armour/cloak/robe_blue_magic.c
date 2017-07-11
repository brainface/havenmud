#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <size.h>
#include <vendor_types.h>
#include <armour_class.h>
 
inherit LIB_ARMOUR;
 
static void create()
{
  armour::create();
  SetKeyName("robe");
  SetId( ({ "robe","robe of magician","robe of a magician" }) );
  SetAdjectives( ({ "blue" }) );
  SetShort("a blue robe");
  SetLong("This is a blue robe of a magician with many magical symbols "
          "printed on it.");
  SetMass(20);
  SetMaterial("textile");
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
  SetWarmth(25);
  SetValue(35);
  SetDamagePoints(250);
  SetArmourType(A_CLOAK);
  SetVendorType(VT_TREASURE | VT_ARMOUR);
  SetWear("A small wave of magic passes over you as you wear the robe.");
  SetProperty("magic","An old spell of ancient origin has been cast "
              "upon the robe, adding some small protection from magical "
              "attacks and raising slightly a couple of the robe's "
              "other defenses.");
}
