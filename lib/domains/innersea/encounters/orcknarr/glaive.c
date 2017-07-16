// skull glaive
// two handed staff-like axe for shamans
// provides a minor stacking bonus to int/wis,
//  higher if necromancy skill present
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;        

int DoWield();
int CheckWield();

static void create() {
  item::create();     
  SetKeyName("bone glaive");
  SetId( ({ "glaive" }) );   
  SetAdjectives( ({ "bone" }) );
  SetShort("a bone glaive");    
  SetLong(
    "A jagged and blood stained steel axe-head sits at the end of this glaive,"
    "where humanoid skulls with chattering teeth hang as a fetish. The deadly "
    "blade is attached to a haft is formed from some leviathan's bone. "            
  );                                                         
  SetHands(2);                                               
  SetClass(35);                                              
  SetWeaponType("hack");                                     
  SetDamageType(SLASH);                                      
  SetVendorType(VT_WEAPON);                                  
  SetDamagePoints(2000);                                      
  SetValue(3200);                                            
  SetMass(200);                                              
  SetMaterials( ({ "natural" }) );                           
  SetRepairDifficulty(100);
  SetProperty("history", "The haft of the glaive is carved from some large "
    "marine mammal, possible a blue whale. Shamans use fetishes such as this "
    "to enhance their power."
  );
  SetProperty("magic", "Spirits of cunning are entrapped within "
    "this staff. They may occassionally offer advice of wisdom "
    "and intelligence."
  );
  SetWield( (:DoWield:) );
}

int DoWield() {
  this_player()->AddStatBonus("intelligence", (: CheckWield :) );
  this_player()->AddStatBonus("wisdom", (: CheckWield :) );
  send_messages( "wield",
    "Spirits of cunning %^YELLOW%^envelop%^RESET%^ to $agent_name as "
    "$agent_nominative $agent_verb a $target_name.",
    this_player(),
    this_object(),
    environment(this_player())
  );
  return 1;
}

int CheckWield() {
  /*if( !GetWorn() || previous_object()->GetStatBonus("intelligence")
    + previous_object()->GetStatBonus("wisdom")   ) {
    previous_object()->RemoveStatBonus("intelligence", this_object());
    previous_object()->RemoveStatBonus("wisdom", this_object());
    send_messages("spark",
      "$agent_possessive bone glaive%^YELLOW%^ $agent_verb%^RESET%^ ineffectively.",
      previous_object(),0,environment(previous_object()) );
    previous_object()->eventPrint("You are already affected by magic that "
      "increases your wisdom and intelligence, and the effects will not stack!"); 
    return 0;
  } else*/
  if (previous_object()->GetSkillLevel("necromancy")) {
    return 10;
  } else {
    return 5;
  }
}

mixed eventUnequip(object who) {
  who->RemoveStatBonus("intelligence", this_object());
  who->RemoveStatBonus("wisdom", this_object());
  send_messages("unwield",
    "The spirits surrounding $agent_name %^YELLOW%^depart%^RESET%^ as "
    "$agent_nominative $agent_verb $target_name.",
    who, this_object(), environment(who) );
  item::eventUnequip(who);
}

