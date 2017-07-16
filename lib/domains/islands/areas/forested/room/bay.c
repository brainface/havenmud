#include <lib.h>
#include <std.h>
#include <daemons.h>
#include <domains.h>
#include "../island.h"
inherit LIB_ROOM;
inherit LIB_DIG;
int eventTreasure(object who, object shovel);

static void create() {
  room::create();
  
  SetShort("a small beach near a forest");
  SetExits( ([
    "south"  : INNERSEA_VIRTUAL "ocean/250,147",
    ]) );
  SetLong(
    "The forest appears impassable from here. To the south, the beach opens into a passable "
    "bay on the Endless Sea. While the sands are pristine, near the forest are evidence of "
    "small animal inhabitation. Some twigs seem randomly placed on the beach."
    );
  SetItems( ([
    ({ "beach", "sand", "sands" }) : "The sands of the beach are smooth and clear. Small twigs lie scattered on the beach.",
    ({ "twig", "twigs" }) : "The twigs seem to form an 'X' near the treeline.",
    ({ "tree", "trees", "treeline" }) : "The treeline is a near-impassable wall of green set away from the beach.",
    ({ "evidence" }) : "The evidence looks like spoor.",
    ({ "spoor" }) : "The spoor looks like... well... um... droppings.",
    ]) );
  SetSmell( ([
    "default" : "The forested island has a clean pine scent.",
    "evidence" : "The evidence smells like spoor.",
    "spoor"    : "Ugh!  You smell... poop.",
    ]) );
  if (!random(60)) AddInventory(STD_NPC "deer", 1);
  SetProperty("coastal", 1);
  SetDig( (: eventTreasure :) );
}

int eventTreasure(object who, object shovel) {
  object chest = new(ISLAND_OBJ "chest");
  if (!chest) {
    CHAT_D->eventSendChannel("Forest Island", "error", "Error loading chest");
    return 1;
  }
  if (who->GetQuestCompleted("Buried Treasure")) {
    send_messages( ({ "dig", }), "$agent_name $agent_verb up nothing new of value.", who, 0, this_object());
    return 1;
  }
  who->AddQuest("the Treasure Seeker", "Buried Treasure");
  who->AddDevelopmentPoints(10);
  who->AddExperience(100000);
  send_messages( ({ "dig", }), "$agent_name $agent_verb up a chest!", who, 0, this_object());
  chest->eventMove(this_object());
  return 1;
}