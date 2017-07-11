  /* brocade gown
  Luna 12/14/98
*/
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
  inherit LIB_ARMOUR;

static void create() {
  armour::create(); SetArmourClass(ARMOUR_CLOTH); SetMaterials( ({ "textile" }) ); 
  SetKeyName("gown");
  SetShort("a brocade gown");
  SetId( ({"gown"}) );
  SetAdjectives( ({"brocade","elegant",}) );
  SetLong("This elegant brocade gown has a low cut rounded "            
          "neckline. It has a drop waist and the skirt flares "
          "gently to the floor. It is a floral brocade with "
          "deep rose, burgandy and blues. Gold threads accent "
          "the neckling, waist, and wrists.");
  SetMass(70);
  SetValue(500);
  SetDamagePoints(50);
  SetMaterial("textile");
  SetWarmth(15);
  SetArmourType(A_BODY_ARMOUR);
}
