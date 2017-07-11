#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <armour_class.h>

inherit LIB_ARMOUR;

int DoWear();
int CheckWorn();

static void create()
{
  armour::create();
  SetKeyName("dark cloak");
  SetId( ({"cloak","dark cloak","shadowy cloak","dark shadowy cloak"}) );
  SetShort("a dark shadowy cloak");
  SetLong("This cloak is black and appears to waver in and out of the "
    "shadows.  The inside is lined with a quilted liner and the outside "
    "is made of a slick material of an unknown type.");
  SetAdjectives( ({"shadowy","dark"}) );
  SetMass(500);
  SetValue(25000);
  SetArmourClass(ARMOUR_CLOTH);
  SetDamagePoints(1000);
  SetArmourType(A_CLOAK);
  SetVendorType(VT_CLOTHING | VT_MAGIC);
  SetProperty("magic", "The cloak feels almost insubstantial, like a "
    "shadow filtering in and out of existance.");
  SetProperty("history", "The history of this item is almost lost in "
    "time.  The only known fact is that it is made from the skin of "
    "a pit fiend who was skinned alive by a powerful warrior of old.");
  SetWear( (: DoWear :) );
  // SetProtection(SLASH, 10);
  // SetProtection(PIERCE, 10);
  // SetProtection(BLUNT, 10);
  // SetProtection(MAGIC, 50);
  // SetProtection(HEAT, 35);
  // SetProtection(COLD, 35);
  SetMaterial( ({"leather","textile"}) );
  SetWarmth(25);
  SetRepairSkills( ([ 
  			"leather working" : 35,
        "textile working" : 15,
        ]) );
  SetRepairDifficulty(75);
}

int DoWear()
{
  write("You shimmer and waver as you fade from view.");
  say((string)this_player()->GetName() + " shimmers for a second and "
    "seems to disappear from existance.");
  this_player()->SetInvis(1);
  return 1;
}

mixed eventUnequip(object who) {
  who->SetInvis(0);
  ::eventUnequip(who);
}  
