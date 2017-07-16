// mahkefel 2010 
//  narwhale horn (a lance) for one of my seaguys.

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;        

static void create() {
  item::create();     
  SetKeyName("horn"); 
  SetId( ({ "horn" }) );
  SetAdjectives( ({ "narwhale","scrimshawed","horn" }) );
  SetShort("a scrimshawed horn");                        
  SetLong(                                               
    "This long, spiraling horn was likely harvested from a marine animal. "
    "Delicate scrimshaw drawings cover every inch of the horn in imagines "
    "of storms, drowning sailors, and giant sea serpents. Foxfires dancing "
    "along the needle thin point illuminate the entirety of the weapon."    
  );                                                                        
  SetHands(2);                                                              
  SetClass(35);                                                             
  SetWeaponType("pierce");                                                  
  SetDamageType(PIERCE | SHOCK);                                            
  SetVendorType(VT_WEAPON);                                                 
  SetDamagePoints(2000);                                                    
  SetValue(1600);
  SetMass(300);
  SetMaterials( ({ "natural" }) );
  SetRepairDifficulty(75);
  SetProperty("history",
    "This is the horn of a narwhale, a rather large whale that roams the "
    "waters of the endless sea. The scribings along it seem similiar to "
    "those used by clerics of Damhair, and are obviously potent."
  );
  SetProperty("magic",
    "This narwhale's horn is enchanted to call down the "
    "divine wrath of Damhair upon those it strikes."
  );
  SetRadiantLight(15);
  SetWield("You feel your hair start to stand on end.");
}

int eventStrike(object who) {
  int amount = random(60);
  if (!random(5)) {
    if (who->GetReligion() != "Damhair") {
        send_messages("action", "Violent lightning "
          "%^BOLD%^%^YELLOW%^crackles%^RESET%^ from the horn as it "
          "pierces $target_possessive_noun flesh!",
        environment(),who,environment(who) );
        return (item::eventStrike(who) + amount);
    }
  }
  return (item::eventStrike(who));
}

