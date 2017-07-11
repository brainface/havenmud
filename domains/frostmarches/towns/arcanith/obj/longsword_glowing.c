/* A glowing Longsword - by Sardonas */

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("longsword");
  SetId( ({ "longsword" }) );
  SetAdjectives( ({ "ancient", "old", "glowing" }) );
  SetProperty( "magic", "The runes on the blade of the sword cause the sword "
                        "to glow with a pale light.");
  SetProperty( "history", "This sword of magic was given to the Captain of "
                          "the Arcanith Blades as a symbol of his status.  "
                          "The sword of light represents mankind's struggle "
                          "to fight back against the darkness.  The sword "
                          "was true to the captain until he was betrayed by "
                          "a necromancer he counted as an ally.");
                          
  SetShort("an ancient longsword");
  SetLong("This sword is very old and has seen many battles.  It is fairly "
          "simple in design.  The only exception is some runes etched into "
          "the base of the blade, and the pale light which comes from the "
          "blade.");
  SetVendorType(VT_WEAPON | VT_MAGIC);
  SetDamagePoints(700);
  SetClass(10);
  SetValue(100);
  SetMass(175);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetRadiantLight(25);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([ "metal working" : 2,
                     "weapon smithing" : 2,
                ]) );
  SetRepairDifficulty(10);

}
