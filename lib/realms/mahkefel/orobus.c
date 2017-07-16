#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
#include <armour_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create()
{
  armour::create();
  SetKeyName("orobus ring");
  SetId(( { "ring","orobus ring"} ));
  SetShort("an orobus ring");
  SetLong("A black metal snake swallows its own tail to form this ring, its " 
    "eyes set with tiny polished bloodstones. Fine scales carved into its "
    "body seem to spiral and twist about, tiny shimmers of obvious mithril "
    "catching your eye as it does."
  );
  SetMass(1);
  SetValue(6000);
  SetDamagePoints(100);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);

  SetArmourType(A_RING);
  SetVendorType(VT_TREASURE | VT_ARMOUR);

  SetWear("The ring slowly spins around your finger, chasing its own tail "
    "endlessly in such a way to ruin anyone's appetite.");

  set_heart_beat(60);    
}

void heart_beat() {
  int satiate = 25;
  int fedme = 0;
  object wearer;
  
  if (!GetWorn()) return;  

  if (!environment()) return;

  wearer = environment();

  if(!playerp(wearer)) return;

  if ( wearer->GetFood() < 500 ) {
    wearer->AddFood(satiate);
    fedme = 1;
  }
  
  if (wearer->GetDrink() < 500 ) {
    wearer->AddDrink(satiate);
    fedme = 1;
  }
  
  if (fedme) {
    wearer->eventPrint("Your snakey ring wiggles around your finger in an oddly "
      "comforting way you can feel all the way in your gut.");
  }
    
  return;
  
};




