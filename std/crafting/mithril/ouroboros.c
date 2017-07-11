// item as requested by pat
// implemented as he didn't say unghk a single time in the discussion

// feeds/hydrates the wearer

// craft recipe: 1 mithril ingot, 2 bloodstones, 1 bit of sandworm spice


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
  SetKeyName("ouroboros ring");
  SetId(( { "ring","ouroboros ring"} ));
  SetShort("an ouroboros ring");
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

  SetProperty("history",
    "Rings such as these are often found on secluded mages--it's thought they "
    "were first developed in Lisht, but similiar designs have been seen "
    "throughout Kaille since the last Godswar."
    );
  SetProperty("magic",
    "This ring satiates the wearers hunger and thirst by transposing their "
    "existing, hungry vitals with a potential semi-real alternate version of "
    "their innards in a quasi-reality where they weren't too lazy to eat."
    );
  
  set_heart_beat(60);
}

void heart_beat() {
  int satiate = 25;
  int fedme = 0;
  object wearer;
  
  // do nothing if not worn
  if (!GetWorn()) return;  

  // 
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




