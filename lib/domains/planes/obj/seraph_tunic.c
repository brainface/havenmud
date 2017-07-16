/* Robe of cold resistance
 *  simply doesn't deteriorate to cold
 *                                    
 */                                   
#include <lib.h>                      
#include <armour_types.h>             
#include <armour_class.h>             
#include <damage_types.h>             
#include <size.h>                     
inherit LIB_ARMOUR;                   

int checkAlignment() {
  if (this_player()->GetMorality() < 1000) {
    send_messages("verb",
     "The proud dragon sewn into $agent_possessive_noun "
     "tunic seems to wither and fray until only a skeletal "
     "remnant remains, grinning evily.",
     this_player(),0,environment(this_player()) );
  } else if (this_player()->GetMorality() > 1000) {
  }
  return 1;
}


static void create() {
  ::create();         
  SetId( ({ "tunic" }) );
  SetKeyName("flowing tunic");
  SetShort("a flowing white tunic");
  SetLong(
    "This sharply cut is sewn of simple white linen, hanging to just below the "
    "knee. Wide sleeves drape all "
    "the way to the hands and could conceal any number of knives or weapons, and "
    "a roaring dragon is embroidered into the chest in delicate silver threads."
  );                                                                 
  SetAdjectives( ({ "fluffy", "white"  }) );                         
  SetArmourClass(ARMOUR_CLOTH);                                      
  SetArmourType(A_BODY_ARMOUR);                                      
  SetDamagePoints(2000);                                             
  SetMaterials( ({ "textile" }) );                                   
  SetProperty("history",                                             
    "Holy creatures are often given garmets befitting their station "
    "with some minor protective enchantment to aid them in their "
    "duties. The precise enchantment varies by rank and role of "
    "the celestial."
  );                                                                 
  SetProperty("magic",                                               
    "This garment has been enchanted to provide protection from "    
    "the frigid air and ice encountered by flying creatures at high "
    "altitudes."
  );                                                                 
  SetSize(SIZE_LARGE);                                              
  SetValue(1000);                                                    
  SetWarmth(10);                                                     
  SetWear("The robe feels extremely warm, almost stiffling.");       
}                                                                    

// magical robe ignores electrical deterioration
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
  if(!(DamageType & COLD)) {
    armour::eventDeteriorate(DamageType);
    return;
  }

  // shield is held, send message to room and wielder
  if (room) {
    room->eventPrint(possessive_noun(env) + " " + GetKeyName() +
      " %^BOLD%^WHITE%^resists%^RESET%^ the frost.", ({env}) );
    env->eventPrint("Your " + GetKeyName() +
      " %^BOLD%^WHITE%^resists%^RESET%^ the frost.");
  } else {
    // shield is not held. send message to room
    env->eventPrint(capitalize(GetShort()) +
      " %^BOLD%^WHITE%^resists%^RESET%^ the frost.");
  }
}

