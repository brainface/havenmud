// mahkefel 2011:
// harpy flute
#include <lib.h>       
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;        

static void create() {
   item::create();    
   SetKeyName("flute");
   SetShort("a bone flute");
   SetId( ({ "flute","bard_instrument" }) );
   SetAdjectives( ({ "bone" }) );           
   SetLong(
     "it's a me, setlong!"
   );                                                             
   SetMass(20);                                                  
   SetVendorType(VT_INSTRUMENT);                                  
   SetValue(1000);                                                
   SetDamagePoints(500);                                         
   SetMaterial( ({ "natural" }) );
   SetRepairDifficulty(30);
   SetClass(10);
   SetHands(1);
   SetWeaponType("pole");
   SetDamageType(BLUNT|SOUND);
   SetProperty("history",
     "bird... bone?");
   SetProperty("magic",
     "Something fun i can do on hit."
   );
}

// do elemental damage if player deserves it.
int eventStrike(object who) {
  int amount = 0;

  if ( !random(7) && this_player()->GetSkillLevel("instrumental music") ) {
      amount = random(20);
      send_messages( ({"hold","sound"}), "$agent_name $agent_verb the trumpet to $agent_possessive "
        "lips and%^BOLD%^WHITE%^ $agent_verb%^RESET%^ an echoing challenge "
        "that rattles $target_name!",
        this_player(), who, environment(who) );
      who->AddRecoveryTime(random(25));
      return (item::eventStrike(who) + amount);
  }
      return (item::eventStrike(who));
}

