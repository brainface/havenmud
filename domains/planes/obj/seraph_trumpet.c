#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("trumpet");
   SetShort("a golden trumpet");
   SetId( ({ "trumpet","bard_instrument" }) );
   SetAdjectives( ({ "golden" }) );
   SetLong(
     "This elegant instrument was smithed from solid "
     "gold. Rather oversized for a human, the bell is wider "
     "than your outstretched hand, decorated with etching of "
     "all manner of winged creatures. Three finely engineered "
     "valves slide with ease, and the mouthpiece is even shinier "
     "than mouthpieces tend to be."
   );
   SetMass(100);
   SetVendorType(VT_INSTRUMENT);
   SetValue(3000);
   SetDamagePoints(1000);
   SetMaterial( ({ "metal" }) );
   SetRepairDifficulty(50);
   SetClass(30);
   SetHands(2);
   SetDamageType(BLUNT|SOUND);
   SetProperty("history",
     "This instrument was made by no mortal hands, and some celestial "
     "of the upper planes is probably very upset at its loss.");
   SetProperty("magic",
     "Crafted by celestial magic, this instrument could likely deal quite "
     "some damage wielded bluntly, and a trained musician could likely "
     "work some additional violence with it."
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
