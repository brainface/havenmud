#include <lib.h>
#include <size.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("gauntlet");
  SetId( ({ "gauntlet" }) );
  SetArmourType(A_GLOVE);
  SetShort("an elemental gauntlet");
  SetLong("This particular gauntlet came from the Master Craftsmen, "
          "and given to the Gnomish Centurions, of Underland. Truly a prize "
          "worthy of the deed to reft one from a Centurion. The fingers "
          "are spun of mithril springs that allow any range of motion; "
          "while the shell is made of loricated mithril mail to offer "
          "splended protection. The knuckles are covered in interwoven "
          "runic inscriptions which the meaning of has long been lost. "
          "On the palm is a small jewel surrounded in a gold frame that "
          "wraps back around to form the wrist protection.");
  SetValue(50000);
  SetMass(200);
  SetArmourClass(ARMOUR_HEAVY_PLATE);
  SetSize(SIZE_MEDIUM);
  SetWarmth(25);
  SetDamagePoints(25000);
  SetMaterial( ({ "mithril" }) );
  SetRepairSkills( ([ "armour smithing" : 250,
        "metal working" : 250 ]) );
  SetRepairDifficulty(75);
 }
