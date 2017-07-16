/* air elemental rags
 * cuz there's clotheslines in the upperplanes, right?
 */
// Mahkefel 10/2010: increased droprate, so people will
//  actually notice the damned items I made.                                                 
#include <lib.h>                                    
#include <armour_types.h>                           
#include <armour_class.h>                           
#include <damage_types.h>                           
#include <size.h>                                   
#include "../planes.h"                              
inherit LIB_ARMOUR;                                 

int RandomTreasure();

static void create() {
  ::create();         
  SetId( ({ "rags" }) );
  SetKeyName("frozen bundle of rags");
  SetShort("a frozen bundle of rags");
  SetLong(                            
    "This is a frozen bundle of rags of various colours and "
    "texture, evidently trapped and frozen by the air elemental's "
    "whirlwind as it wandered."                                    
  );                                                               
  SetAdjectives( ({ "bundle","of","frozen"}) );                    
  SetArmourClass(ARMOUR_CLOTH);                                    
  SetArmourType(A_BODY_ARMOUR);                                    
  SetDamagePoints(4000);                                           
  SetMaterials( ({ "textile"}) );                                  
  SetPreventGet( (: RandomTreasure :) );                           
  SetSize(SIZE_MEDIUM);                                            
  SetValue(0);                                                     
}                                                                  

// destory self and reward picker upper with random treasure
int RandomTreasure(object who) {                            
  int pro;                                                  
  int con;                                                  
  object robe,coins;                                        
  object env;                                               
  pro = random(who->GetStatLevel("luck"));                  
  con = random(100);                                        

  env = environment();
  if (!env) {         
    return 0;         
  }                   

  // player gets a goodie
  if (pro > con * 2) {   
    // pick a robe       
    switch (random(3)) { 
      case 0:            
        robe = new (PLANE_OBJ "robe_fire");
        robe->eventMove(env);              
      break;                               
      case 1:                              
        robe = new (PLANE_OBJ "robe_cold");
        robe->eventMove(env);              
      break;                               
      case 2:                              
        robe = new (PLANE_OBJ "robe_shock");
        robe->eventMove(env);               
    }                                       
    // send a message
    env->eventPrint("The rags fall apart as " + who->GetName() +
      " grabs them; however, something of worth seems to remain" +
      " in the lint and frost.", ({who}) );
    who->eventPrint("The rags fall apart as you grab them; however,"
      " something of worth seems to remain in the lint and frost.");
    this_object()->eventDestruct();
    return 0;
  }

  if (pro >= con) {
    env->eventPrint("The rags fall apart as " + who->GetName() +
      " grabs them. A handful of coins fall to the ground with the"
      " lint and frost.", ({who}) );
    who->eventPrint("The rags fall apart as you grab them. A handful"
      " of coins fall to the ground with the lint and frost.");
    coins = new(LIB_PILE);
    coins->SetPile("imperials", 200 + random(600));
    coins->eventMove(env);
    this_object()->eventDestruct();
    return 0;
  }

  // dude was unlucky.
  env->eventPrint("The rags fall apart as " + who->GetName() +
    " grabs them. Nothing but lint and frost remain.", ({who}) );
  who->eventPrint("The rags fall apart as you grab them. Nothing "
    "but lint and frost remain.");
  this_object()->eventDestruct();
  return 0;
}

