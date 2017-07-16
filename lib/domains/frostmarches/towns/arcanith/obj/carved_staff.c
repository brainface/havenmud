/* Druid staff - Made by Sardonas */

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("carved staff");
  SetShort("a carefully carved staff");
  SetId( ({ "staff" }) );
  SetAdjectives( ({ "carved", "oak", "carefully" }) );
  SetProperty( "history", "This staff was carefully carved by the druid "
                          "Kara.  As she began her travels to the ruins she "
                          "came upon a long branch which was destined to "
                          "become this staff.  She carved into the staff "
                          "pictures of all the different types of life she "
                          "she saw on her long trek.");
  SetLong("Intricate carvings of nature cover every inch of this staff.  "
          "Wolves, bears, hawks, flowers, leaves, and other nature symbols "
          "are carved bas-relief into the wood.  The carving of a large oak "
          "tops the staff.  The leaves of the oak almost seem to sway.");
  SetMass(100);
  SetValue(150);
  SetVendorType(VT_WEAPON | VT_TREASURE);
  SetDamagePoints(500);
  SetWeaponType("pole");
  SetDamageType(BLUNT);
  SetClass(8);
  SetMaterial( ({ "wood" }) );
  SetRepairSkills( ([ "wood working" : 2,
                      "weapon smithing" : 1,
                 ]) );
  SetRepairDifficulty(7);
}
