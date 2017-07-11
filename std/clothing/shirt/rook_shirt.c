  /* warrior_shirt
  Luna 12/14/98
*/
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create(); 
  SetArmourClass(ARMOUR_CLOTH);
  SetMaterials( ({ "textile" }) ); 
  SetKeyName("shirt");
  SetShort("a blood red shirt");
  SetId( ({"shirt"}) );
  SetAdjectives( ({ "red", "blood", }) );
  SetLong("This blood red shirt is made to be worn under armour. "
          "It bears a large symbol of a silver dragon with scorched, "
          "burned wings and the red seems to have smeared all over "
          "the dragon."
          );
  SetMass(25);
  SetValue(40);
  SetDamagePoints(25);
  SetItems( ([
    "dragon" : "The dragon appears to be Rook. Some words appear to be stitched "
    	         "under the dragon.",
    "words"  : "The words, while pretty, should probably be read.",
    ]) );
  SetRead( ([
    "default" : "The words say, \"I killed Rook and all I got was this shirt.\"",
    "words"   : "The words say, \"I killed Rook and all I got was this shirt.\"",
    ]) );
  SetWarmth(10);
  SetArmourType(A_SHIRT);
  SetProtectionBonus(SHOCK, 100);
  SetProperty("magic", "This shirt protects very well against electrical damage.");
}
