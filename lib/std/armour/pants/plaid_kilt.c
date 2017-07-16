#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

int DoWear();

static void create()
{
  armour::create();
  SetKeyName("plaid kilt");
  SetId(( { "kilt","plaid kilt"} ));
  SetShort("a plaid kilt");
  SetLong("This kilt is made of a sturdy wool with a bright plaid pattern");
  SetMass(30);
  SetMaterial("textile");
  SetWarmth(15);
  SetValue(80);
  SetDamagePoints(500);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_CLOTH);
  
  
  SetArmourType(A_PANTS);
  SetVendorType(VT_TREASURE | VT_ARMOUR);
  
  SetWear((:DoWear:));
}

int DoWear()
{
  if(environment()->GetGender() == "male")
    write("You feel kind of funny wearing this.");
  else
    write("The wool is kind of scratchy.");
  
  say(this_player()->GetName() + " wears a plaid kilt.");
  return 1;
}
