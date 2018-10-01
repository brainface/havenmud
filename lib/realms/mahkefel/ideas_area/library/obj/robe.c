/*               
 * A nifty for daemon mages
*                                       
 * Well, not really. just cloth body armour
 */                                            
#include <lib.h>                               
#include <vendor_types.h>                      
#include <size.h>                              
#include <armour_class.h>                      
#include <armour_types.h>                      

inherit LIB_ARMOUR;

static void create() {
  armour::create();   
  SetKeyName("robe");
  SetId(( {"robe"} ));
  SetShort("a descecrated robe");
  SetAdjectives( ({"desecrated"}) );
  SetLong(
    "This silk robe is torn and stained with blood and ichor. Tarnished "
    "silver inlays and a weathered heraldic symbol of a shining tree hint "
    "at some proud past for this garment, but it has been reduced to a sick "
    "parody of itself by someone's ill-omened use."
    
  );
  SetArmourType(A_BODY_ARMOUR);
  SetArmourClass(ARMOUR_CLOTH);
  SetDamagePoints(4000);
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
  SetWear("The robe stinks of sulfur and dried blood.");
}

