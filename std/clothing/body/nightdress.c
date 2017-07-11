 /*nightdress
  Luna 12/16/98
*/
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create(); SetArmourClass(ARMOUR_CLOTH); SetMaterials( ({ "textile" }) ); 
  SetKeyName("nightdress");
  SetShort("a blue nightdress");
  SetId( ({"nightdress"}) );
  SetAdjectives( ({"blue","soft","cotton"}) );
  SetLong("This soft blue nightdress is brushed cotton "
          "for warmth and comfort. It has long sleeves "
          "and the neckline is softly rounded.");
  SetMass(20);
  SetValue(40);
  SetDamagePoints(30);
  SetMaterial("textile");
  SetWarmth(15);
  SetArmourType(A_BODY_ARMOUR);
}
