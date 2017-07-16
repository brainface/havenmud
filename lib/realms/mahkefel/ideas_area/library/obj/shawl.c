/*               
 * A nifty for daemon mages
 *                                       
 * Well, not really. just cloth wing armour
 */                                            
#include <lib.h>                               
#include <vendor_types.h>                      
#include <size.h>                              
#include <armour_class.h>                      
#include <armour_types.h>                      

inherit LIB_ARMOUR;

static void create() {
  armour::create();   
  SetKeyName("tattered shawl");
  SetId(( {"shawl"} ));
  SetShort("a tattered crimson shawl");
  SetAdjectives( ({"tattered", "crimson"}) );
  SetLong(
    "This is a worn and weathered shawl, its original color lost "
    "to scarlet stains of vicious origin and unknown age. The fit "
    "is odd, and holes and hooks are attached in all the wrong places. "
    "Impossible to fit over the shoulders, it might cover the wings of "
    "some large creature."
  );
  SetArmourType(A_WING);
  SetArmourClass(ARMOUR_CLOTH);
  SetDamagePoints(2000);
  SetMass(100);
  SetMaterial("textile");
  SetProperty( "history",
    "This is a garment worn by Mepheus, a daemon long residing in "
    "the ruins of Arcanith. Legends say he was once a human, who "
    "bargained for infernal power at the cost of his native city; "
    "but the true story is lost to time."
  );
  SetRepairDifficulty(25);
  SetSize(SIZE_LARGE);
  SetValue(1000);
  SetVendorType(VT_ARMOUR);
  SetWarmth(0);
  SetWear("The shawl drapes losely over your wing.");
}

