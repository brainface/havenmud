/*
 * I'm bored and mean.
 
 * Seriously this should probably be deleted.
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
  SetKeyName("blastrock");
  SetId( ({"blastrock",}) );
  SetAdjectives( ({"smoking","chunk","of",}) );
  SetShort("a smoking chunk of blastrock");
  SetLong(
    "This pitted black rock smokes, sparks, and stinks. It's "
    "deliriously unstable, and constantly vibrating and bouncing "
    "like some sort of caffeinated sprite."
  );
  SetMass(1);
  SetValue(5000);
  SetDamagePoints(5);
  set_heart_beat(1);
  SetCountDown(30);
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
  object ofMyBoredom;
  if (!environment()) return;


  
  if(!living(environment())) {
  critters = filter(all_inventory(environment(this_object())), (: living :));

  if (environment()->GetProperty("no attack")) {
  environment()->eventPrint("The blastrock dissolves into sticky goo.");
  eventDestruct();
  return;
  }
  message("my_message", "The blastrock %^RED%^explodes!%^RESET%^", environment());
  if (sizeof(critters))
  critters->eventReceiveDamage(this_object(), HEAT|SOUND, 50 + random(50), 0);
  eventDestruct();
  } else {
  ofMyBoredom = environment();
  if (!environment(ofMyBoredom)) return;
  if (environment(ofMyBoredom)->GetProperty("no attack")) {
  environment(ofMyBoredom)->eventPrint("The blastrock dissolves into sticky goo.");
  eventDestruct();
  return;
  }
  message("my_message", "The blastrock %^RED%^explodes!%^RESET%^", environment(ofMyBoredom));
  
  ofMyBoredom->eventReceiveDamage(this_object(), HEAT|SOUND, 50 + random(50), 0);
  eventDestruct();
  }
}

