#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <size.h>
#include <vendor_types.h>
#include <armour_class.h>
 
inherit LIB_ARMOUR;
 
static void create()
{
  ::create();
  SetKeyName("cloak");
  SetId( ({ "cloak" }) );
  SetAdjectives( ({ "flesh","human" }) );
  SetShort("a cloak of human flesh");
  SetLong("This cloak is made of numerous patches of skin. Square pieces of "
          "skin have been sewn together with braided strands of hair. Along "
          "the top of the cloak is a thick rope in which its user can don "
          "the cloak properly. It is triangular in shape, and appears "
          "unusually delicate due to the components of its craft.");
  SetMass(20);
  SetMaterial("textile");
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
  SetWarmth(10);
  SetValue(300);
  SetDamagePoints(1400);
  SetArmourType(A_CLOAK);
  SetVendorType(VT_TREASURE | VT_ARMOUR);
  SetProtectionBonus(HEAT, 20);
  SetWear("A loud scream runs through you as you don the cloak.");
  SetRepairDifficulty(60);
  SetProperty("history",
  "Crafted from the skill of a talented tailor with the skin "
  "of fallen foes. Human hair used as a stitching and then "
  "preserved with black enchanments. "
   );
  SetProperty("magic",                                             
  "Crafted from the experiments of evil magic, the cloak writhes "
  "in living pain. An aura of preservation has been cast to prevent "
  "the cloak from rotting, along with another aura which offers "
  "the skin itself from being charred. "
   ); 
}