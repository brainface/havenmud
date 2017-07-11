#include <lib.h>
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("bored mule");
  SetId( ({ "mule", "arcanith_pack_mule" }) );
  SetAdjectives( ({ "bored", "pack" }) );
  SetShort("a bored pack mule");
  SetLong("This mule seems to do little more than follow "
          "his owner around doing not much.");
  SetRace("horse", "mule");
  SetClass("animal");
  SetLevel(8);
  SetMorality(10);
  SetOwner("presmyr");
  SetLimit(1);
  SetAction(1, ({
    "The mule leans over and nuzzles the ground looking for grasses.",
    "The mule gives a look that shows how amazingly bored he is.",
    "The mule raises his head to look around.",
  }) );
  SetFirstCommands("follow presmyr");
}

int eventReceive(object ob) {
  eventForce("emote receives " + ob->GetShort() + " with little regard.");
  ob->eventDestruct();
  return 1;
}

void heart_beat() {
  object *inv = all_inventory();
  inv->eventDestruct();
  ::heart_beat();
}
