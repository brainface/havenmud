//coded by Syra@haven 6/98
#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;
inherit LIB_TOUCH;

static void create()
{
  armour::create();
  SetKeyName("dress");
  SetId(( { "dress"} ));
  SetAdjectives( ({"well-worn","cotton","mottled","sea","green"}) );
  SetShort("a green cotton dress");
  SetLong("The mottled sea green dress has a close-fitting top, with "
          "thin straps that let it gently hang from the wearer's "
          "shoulders. The skirt of it hangs down ankle-length and "
          "falls into gentle pleats because there's so much material." 
          "The well-worn cotton feels comfortable to the "
          "touch but is not very practical for battle. It looks "
          "good for little more than prancing around in.");
  SetTouch("The softness of the dress seems reminiscent of a motherly "
           "touch.");
  SetMass(5);
  SetSize(SIZE_MEDIUM);
  SetMaterial("textile");
  SetRepairDifficulty(5);
  SetWarmth(15);
  SetArmourClass(ARMOUR_CLOTH);
  SetValue(50);
  SetDamagePoints(100);
  
  // SetProtection(PIERCE,2);
  // SetProtection(SLASH,2);
  // SetProtection(COLD,2);
  // SetProtection(BLUNT,2);
  SetArmourType(A_BODY_ARMOUR);
  SetVendorType(VT_TREASURE | VT_CLOTHING);
  
  SetWear("The dress feels cold and silky as you slip it over your head.");
  
}
