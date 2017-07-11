/*                                                                                                                                           
 * A cloth wingguard for little seraphs                                                                                                      
 *                                                                                                                                           
 *                                                                                                                                           
 */                                                                                                                                          
#include <lib.h>                                                                                                                             
#include <vendor_types.h>                                                                                                                    
#include <size.h>                                                                                                                            
#include <armour_class.h>                                                                                                                    
#include <armour_types.h>                                                                                                                    

inherit LIB_ARMOUR;

int checkAlignment() {
  if (this_player()->GetMorality() < 1000) {
    send_messages("verb",                   
     "Crimson lines %^RED%^bleed%^RESET%^ from the painted eye.",
     this_player(),0,environment(this_player()) );               
  }else if (this_player()->GetMorality() > 1000) {               
   /* send_messages("verb",
     "The shining tabard %^BOLD%^WHITE%^gleams%^RESET%^ as it billows in the wind",
     this_player(),0,environment(this_player()) );*/
  }
  return 1;
}

static void create() {
  armour::create();
  SetKeyName("wing tabard");
  SetId(( {"tabard"} ));
  SetShort("a billowing wing tabard");
  SetAdjectives( ({"billowing","wing"}) );
  SetLong(
    "A flowing garment made of white linen, this tabard is shaped "
    "for the rather exotic purpose of hanging from an angel's wing. "
    "A huge stylized eye has been dyed into the front and back of "
    "the billowing cloth in stark black lines."
  );
  SetArmourType(A_WING);
  SetArmourClass(ARMOUR_CLOTH);
  SetDamagePoints(2000);
  SetMass(500);
  SetMaterial("textile");
  SetRepairDifficulty(50);
  SetSize(SIZE_LARGE);
  SetValue(1000);
  SetVendorType(VT_ARMOUR);
  SetWarmth(0);
  SetWear( (:checkAlignment:) );
}

