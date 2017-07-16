#include <lib.h>
#include <std.h>
#include "../keryth.h"

inherit LIB_LEADER;

void DoSomething();

static void create() {
  ::create();
  SetKeyName("golann");
  SetId( ({ "golann" }) );
  SetRace("goden");
  SetClass("rogue");
  SetTown("Keryth");
  SetGender("male");
  SetLevel(25);
  SetCurrency("senones", 5);
  SetShort("Golann the Beggar");
  SetLong("The fellow here is clothed in a ragged, torn cloak.  His odor "
          "suggests that he hasnt bathed in weeks and filth covers his "
          "face.  He walks with a limp and holds a cup suggesting he is in "
          "need of some money.  Old and wrinkly as he may look, he has a "
          "peculiar twinkle in his eye.");
  SetAction(15, (: DoSomething :) );
  SetMorality(-30);
  SetId( ({ "beggar", "golann" }) );
  SetFreeEquip( ([
     STD_KNIFE + "freeknife" : 1,
    ]) );
}

void DoSomething() {
  object *victims;
  object ob;
  if (!random(4)) {
    eventForce("beg pitifully");
    return;
  }
  victims = filter(all_inventory(environment()), (: living :));
  victims -= filter(victims, (: GetInvis :));
  victims -= filter(victims, (: creatorp :));
  ob = victims[random(sizeof(victims))];
  eventForce("steal money from " + ob->GetKeyName());
}
