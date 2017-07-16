/*  shield for abashai */
#include <lib.h>         
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>        
#include <damage_types.h>
inherit LIB_ARMOUR;      

static void create() {
  armour::create();   
  SetKeyName("leggings");
  SetShort("a pair of sharkhide leggings");
  SetLong("These crude leggings were crafted from the preserved "
    "skin of a shark. Water slides right off of the rubbery hide."
  );            
  SetId( ({ "leggings", "sharkhide" }) );
  SetAdjectives( ({ "sharkhide","pair","of" }) );
  SetArmourClass(ARMOUR_NATURAL);                                  
  SetArmourType(A_PANTS);                                         
  SetDamagePoints(15000);                                           
  SetMass(600);                                                    
  SetMaterial( ({ "natural" }) );                                  
  SetProperty("history",
    "Sewn from the skin of a mako shark, these leggings should "
    "be resistant to water."
  );
  SetProperty("magic",                                             
    "Crafted from the hide of the deadly shark, these leggings "
    "are impervious to the cold depths that form that "
    "creature's haunt."
  );                                                               
  SetRepairDifficulty(100);                                         
  SetSize(SIZE_LARGE);                                             
  SetValue(1500);                                                         
}                                                                         

// sharkskin will not erode from cold/water
// this effectively affected limb near immune to cold/water,
// without me figured out immunities.
void eventDeteriorate(int DamageType) {
  object env = environment();
  object room;

  if (!env) {
    // there really should be an environment, but
    // torch code has this
    return;
  }
  room = environment(env);
  //deteroirate normally and ignore my bullcrap.
  if( !(DamageType & COLD + DamageType & WATER) ) {
    armour::eventDeteriorate(DamageType);
    return;
  }

  // shield is held, send message to room and wielder
  if (room) {
    send_messages("form",
      "A fine sheen of %^BOLD%^WHITE%^rime%^RESET%^ forms on
      $target_possessive $agent_name, to no effect!",
      this_object(),env,room);
  } else {
    // shield is not held. send message to room
    send_messages("form",
      "A fine sheen of %^BOLD%^WHITE%^rime%^RESET%^ forms on
      a $agent_name, to no effect!",
      this_object(),0,env);
  }
}
