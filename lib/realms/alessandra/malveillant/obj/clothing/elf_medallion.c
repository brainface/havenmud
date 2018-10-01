/* Portia  Ruins  10-7-98
   A medallion for the dark elves.
*/

#include <armour_class.h>
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <armour_types.h>
inherit LIB_ARMOUR;
int CheckReligion();

static void create() {
  armour::create();
  SetKeyName("medallion");
  SetShort("a shimmering medallion");
  SetId( ({"medallion"}) );
  SetAdjectives( ({"shimmering"}) );
  SetLong("This shimmering medallion is round and disk-like. "
          "There appears to be an inscription on it as well as a "
         "symbol of some sort, but it is unlike anything else on Kailie.");
  SetWear( (:CheckReligion:) );
  SetMass(5);
  SetWarmth(0);
  SetArmourClass(ARMOUR_CHAIN);
  SetRead("default", "The inscription says that this medallion is "
                     "only to be worn by members of the Soirin faith.");
  SetValue(800);
  SetMaterials(({"mithril"}));
  SetDamagePoints(1000);
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_AMULET);
  /* I want to make the medallion magical later, with special protections.*/
  }

int CheckReligion() {
  if (this_player()->GetReligion() == "Soirin" ) {
    send_messages("wear", 
      "$agent_name $agent_verb a medallion.",
      this_player(), 0, environment(this_player()) );
    return 1;
  }
  message("system", 
    "The medallion can only be worn by members of the Soirin faith.",
    this_player() );
  return 0;
  }
