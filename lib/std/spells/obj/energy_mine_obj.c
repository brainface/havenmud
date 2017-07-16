/* 
 * 5/99
 * Adapted from the alarm spells
 * Vanyel@haven
 * fixed all the bugs
 * 5/5/05 Duuk
 */
 

#include <lib.h>
#include <damage_types.h>
inherit LIB_ITEM;

// Prototypes
int  SetCountDown(int timeLimit);
int  GetCountDown();
void DoFade();

// Global Variables
int countDown;

static void create() {
  item::create();
  SetKeyName("energy mine");
  SetId( ({"mine",}) );
  SetAdjectives( ({"energy",}) );
  SetShort("an energy mine");
  SetLong(
    "This spherical object is a surging ball of magical energy. "
  );
  SetMass(1);
  SetValue(0);
  SetDamagePoints(5);
  SetPreventGet("A mystical force has fused the mine to the surroundings.");
  set_heart_beat(1);
}

void heart_beat() {
   countDown--;
   if(!countDown) { DoFade(); }
}

int SetCountDown(int timeLimit) {
    return (countDown = timeLimit);
}

int GetCountDown() {
    return countDown;
}

void DoFade() {
  object *critters;
  if(environment())
  critters = filter(all_inventory(environment(this_object())), (: living :));
  if (environment()->GetProperty("no attack")) {
    environment()->eventPrint("The energymine fizzles.");
    eventDestruct();
    return;
    }
  message("my_message", "The energy mine %^RED%^explodes!%^RESET%^", environment());
  if (sizeof(critters))
     critters->eventReceiveDamage(this_object(), HEAT|MAGIC|SHOCK, 150 + random(150), 0);
  eventDestruct();
}
