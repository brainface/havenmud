/* Portia  Ruins  10-7-98
   A medallion for the dark elves.
*/

#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
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
  SetRead("default", "The inscription says that this medallion is "
          "only to be worn by clerics of Soirin.");
  SetMass(5);
  SetMaterials( ({"metal"}) );
  SetWarmth(0);
  SetArmourClass(ARMOUR_CHAIN);
  SetValue(100);
  SetDamagePoints(1000);
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_AMULET);
  // SetProtection(MAGIC, 15);
  // SetProtection(HEAT, 6);
  // SetProtection(COLD, 6);
  /* I want to make the medallion magical later, with special protections.*/
  }

int CheckReligion() {
  if (this_player()->GetReligion() == "Soirin" &&
      this_player()->ClassMember("priest") ) {
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


/* Approved by Duuktsaryth on Mon Nov 16 23:27:55 1998. */
