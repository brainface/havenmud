// A Projectile weapon for Walking corpse
// Used Bandit camp hcross as reference 
// made it terrible-er than that, and heavier.
// Urien@Haven 25JUN2023

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>

inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("hand crossbow");
  SetRepairDifficulty(25);
  SetRepairSkills( ([
   "weapon smithing" : 5,
   "wood working" : 5,
    ]) );
  SetMaterial("wood");
  SetShort("a hand-held wooden crossbow");
  SetId( ({ "crossbow", "bow" }) );
  SetAdjectives( ({ "hand", "held", "cross" , "wooden" }) );
  SetLong("Wood worms or some wood consuming creature has infiltrated "
          "the surface of the dark brown crossbow leaving perfect tiny "
          "holes along the handle and body. The bending portion which "
          "charges the blade looks flimsy and aged from dry rot or "
          "weather exposure. The string that charges arrows is composed "
          "of a finely woven wooden twine. The twine itself looks stained "
          "and weak as if it would look to be a liability in combat. The "
          "creation looks mass produced and simple in design. The water "
          "logged trigger to the hand-held wooden crossbow juts from the "
          "handle slightly amazingly intact.");
  SetValue(5);
  SetClass(6);
  SetMass(85);
  SetDamageType(PIERCE);
  SetWeaponType("projectile");
  SetDamagePoints(500);
  SetVendorType(VT_WEAPON);
  SetProperty("history",
  "It reveals origins from the Gurovian Principality and "
  "was used primarily in the Estergrym Mountain range."
   );   
  SetProperty("magic",
  "A very faint hint of necromantic magic ebbs from the crossbow. The "
  "weapon wielder, not the woodworker who created it."
   ); 
 }
