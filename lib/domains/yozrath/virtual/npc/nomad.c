#include <lib.h>
#include <domains.h>
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("desert nomad");
  SetRace("human");
  RemoveLanguage("Enlan");
  SetLanguage("Padashi", 100, 1);
  SetGender("male");
  SetClass("fighter");
  SetLevel(20);
  SetMorality(-20);
  SetShort("a desert nomad");
  SetId( ({ "nomad" }) );
  SetAdjectives( ({ "desert" }) );
  SetInventory( ([
    YOZRATH_VIRTUAL "obj/kopesh" : "wield sword",
    YOZRATH_VIRTUAL "obj/waterskin" : 1,
    ]) );
}

void eventGreet(object who) {
  int x, y;
  string ns, ew;
  string directions = "";
  object env = environment(this_object());
  if (!sizeof(env->GetCoordinates())) {
    who->eventPrint("The nomad ignores your greeting.");
    return;
  }
  x = env->GetCoordinates()[0]; y = env->GetCoordinates()[1];
  if (x > 0) { ew = "west"; } else { ew = "east"; } 
  if (y > 0) { ns = "south"; } else { ns = "north"; }
  
  eventForce("speak Hail traveller!");
  if (x) { directions += absolute_value(x) + " leagues " + ew; }
  if (x && y) directions += " and ";
  if (y) { directions += absolute_value(y) + " leagues " + ns; }
  eventForce("speak if you seek the City of Yozrath, it lies " + directions + ".");
  directions = "";
  if (x) { directions += ew; }
  if (x && y) directions += " and ";
  if (y) { directions += ns; }
  eventForce("emote points " + directions + ".");
  return;
}