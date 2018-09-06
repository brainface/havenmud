// illusory gold, part of illusion summons
//

#include <lib.h>
inherit LIB_ITEM;
int Life;
void destme();
static void create() {
  int amount = random(1000) + 1;

  item::create();

  SetKeyName("pile");
  SetProperty("magic", "This is a functional figment of someone's greedy imagination.");
  SetId( ({ "pile", "money", "coin", "imperials" }) );
  SetAdjectives( ({"pile of"}) );
  SetShort("a pile of " + amount + " imperials");
  SetLong("It is " + GetShort() + ".");
  SetClass(0);
  SetMaterial( ({ "metal" }) );
  SetMass(0);
  SetValue(0);
  SetRadiantLight(30);
  SetPreventGet("The imperials slide effortlessly between your greedy fingers.");
  set_heart_beat(1);
  Life = 480;
}

void heart_beat() {
  Life--;
  if (!Life) destme();
  }

void destme() {
  if (environment(this_object())) {
    message("system","A pile of imperials fades into memory.",
    environment(this_object()) );
  }
  eventDestruct();
}

