#include <lib.h>
#include "../gurthlad.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  
  SetShort("center of the human camp");
  SetLong("The center of the human forward exploration base. There is a "
          "large fire in a hastily constructed stone fire pit. Roasting "
          "over the fire is what looks like a squealer minus the shell. "
          "There is a large pile of dead branches near the fire. There "
          "are four large tents circled around the fire. The largest one "
          "is to the west.");
          SetObviousExits("east");
  SetExits( ([
          "east" : G_ROOMS+"/room39"]) );
  SetSmell( ([
          "default" : "There is a very strong smell of wood smoke."]) );
  SetItems( ([
          ({ "camp", "base", "expedition" }) : "This is the forward base for "
          "one of the human exploration armies. It is layed out in a typical "
          "pattern, with a central fire and tents circling it.",
          ({ "fire","fire pit", "area", "fire area", "camp fire", "pit", 
          "stone pit" }) : 
          "A large camp fire made out of fallen branches in a hastilly constructed "
          "stone fire pit.",
          "squealer" : "A large squealer, shelled and roasting on a spit over "
          "the fire.",
          ({ "branches", "pile", "branch pile", "fallen branches", "pile of branches",  
          "large pile" }) : 
          "A large pile of dead branches from one of the dead trees nearby.",
          ({ "large tents", "tents", "large tent", "tent" }) : "Large cabin "
          "style tents arranged around the central fire area. The largest one, "
          "a gray tent, is to the west. There is also a brown tent to the north, "
          "a green tent to the south, and another brown tent off a ways to the "
          "northeast.",
          ({ "iron spit","spit" }) : "An iron spit set on two forked branches over the fire.",
          ({ "gray tent" }) : "A large grey cabin style tent off to the west. It "
          "is the largest one in the camp. it is very worn, faded and patched. "
          "It looks like you can enter it.",
          ({ "brown tent" }) : "The large brown cabin style tent if off to the north. "
          "It is faded, worn, and patched. It looks like you can enter it.",
          ({ "green tent" }) : "The large green cabin style tent is off to the south. "
          "It is worn, faded, and patched. It looks like you can enter it."]) );
  SetEnters( ([
          "gray tent" : G_ROOMS + "/room37",
          "brown tent" : G_ROOMS + "/room29",
          "green tent" : G_ROOMS + "/room44"]) );

  SetInventory( ([ G_NPC + "/human_explr" : 5 ]) );
  call_out( "RoomAction", 20);
}

void RoomAction() {
  tell_object(this_object(), "A human walks in, and pokes at the squealer "
                             "with a knife. Seeing that it is not done "
                             "yet, he wanders off.");
}
