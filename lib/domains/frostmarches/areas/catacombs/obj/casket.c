#include <lib.h>
#include <damage_types.h>
#include "../cata.h"

inherit LIB_STORAGE;

static void create() {
object cash = new(LIB_PILE);
  ::create();
  SetKeyName("casket");
  SetDamagePoints(25000);
  SetShort("a large wooden casket");
  SetMass(10000);
  SetId( ({ "casket" }) );
  SetAdjectives( ({ "large", "wooden" }) );
  SetClosed(1);
  SetCanClose(1);
  SetPreventGet("You cannot pick that up!");
  SetLockStrength(600);  
  SetMaxCarry(7500);
  SetCanLock(1);
  SetLocked(1);
  SetKeys( ({ "casket_key" }) );
  SetLong("This large wooden casket is about seven"
          " feet in length and two and a half feet"
          " in height. It has been nailed shut and"
          " latched with a lock to prevent would"
          " be graverobbers from opening it.");
   
  switch(random(7)) {
    case 0:
    SetInventory( ([
       CATA_TREASURE "coin" : (1 + random(10)),
       ]) );
       break;
    case 1:
    SetInventory( ([
       CATA_TREASURE "pendant" : 1,
       ]) );
       break;
    case 2:
    SetInventory( ([
       CATA_TREASURE "chalice" : 1,
       ]) );
       break;
    case 3:
    SetInventory( ([
       CATA_TREASURE "ring" : random(2),
       ]) );
       break;
    case 4:
    SetInventory( ([
       CATA_TREASURE "elixir" : 1,
       ]) );
       break;
    case 5:
     cash->SetPile("imperials", (1500 + random(2000)));
     cash->eventMove(this_object());
     break;
      }
}


mixed eventUnlock(object who, object key) {
  mixed res = ::eventUnlock(who, key);
  if (res == 1) { key->eventDestruct(); }
  return res;
}
varargs mixed eventOpen(object who, string id, object tool) {
  int chance;
  int damage = (random(250) + 55);
  chance = ((who->GetStatLevel("luck")) / 2) + random(100);
  
  if (chance <= (random(35)+65)) {
  switch(random(3)) {
   case 0:
    message("bite","A snake erupts from the casket and bites " +
                  who->GetCapName() + ".", environment() );
    who->eventReceiveDamage(this_object(), PIERCE, damage, 0);

    who->AddPoison(15);
    new(CATA_NPC "asp1")->eventMove(environment(this_object()));
      ::eventOpen(who, id, tool);
    return;
    break;
   case 1:
    message("burn","A large fireball spews forth from the casket and burns " +
                  who->GetCapName() + ".", environment() );
    who->eventReceiveDamage(this_object(), HEAT, damage, 0);
      ::eventOpen(who, id, tool);
    return;
    break;
   case 2:
   message("gas", "A billowing cloud of gas comes out of the casket.",
                   environment() );
   environment()->AddPoisonGas(15);
   ::eventOpen(who, id, tool); 
     return;
     break;
   }
 }
 ::eventOpen(who, id, tool);
}
