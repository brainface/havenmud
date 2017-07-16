// Peat Bog
// Francis
// January 2005

#include <lib.h>
#include <domains.h>
#include "../bog.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(40);
  SetShort("West of the Ruins");
  SetLong(
   "A long dead black spruce tree leans against one of its cousins,"
   " its roots protrude from the ground.  The cavity which the"
   " uprooted tree has left in the ground is filled with stagnent black"
   " water.  Peat moss covers the ground and runs up the trunks of"
   " the black spruce trees.  Thick swamp grasses sprout out of"
   " the soft soil, everything from tall saw grasses to ankle height blue"
   " crab grass.  Large ferns with thick green fronds grow in small"
   " patches where the peat moss has not yet dominated."
);
  SetItems( ([
   ({"tree","trees"}) : "This large tree looks it has been struck by" 
   " lightning, it now leans on its cousin.",
   ({"roots"}) : "The roots protrude from the ground, they have" 
   " left a large cavity which gathers black water.",
   ({"cavity"}) : "Filled with stagnent black water and leaf litter" 
   " this cavity reeks of decay.",
   ({"water"}) : "It is stagnent and filled with leaf litter, it reeks" 
   " of decay.",
  ({"moss"}) : "Large patches of peat moss blanket the soft soil" 
   " and even grow on the trunks of the spruces.",
   ({"grasses","grass"}) : "Thick patches of saw grass cover the" 
   " area as does blue crab grass.",
   ({"ferns","fern"}) : "Large ferns with thick green fronds grow were the" 
   " peat moss and grasses have not annexed.",
   ({"litter"}) : "Rotting leaves mostly, along with twigs and mixed"
   " with mud and stagnent water.",
   ({"log","logs"}) : "A log which is covered in bog turtle dung lies half"
   " submerged in a stagnent cavity.",
   ({"mud","soil"}) : "The mud is soft and covered in leaf litter.",
   ({"dung"}) : "This is obviously reptilian, it is white and very thick.",
]) );
  SetItemAdjectives( ([
   "tree" : ({"long","dead","black","spruce"}),
   "water" : ({"stagnent","black"}),
   "moss" : ({"peat"}),
   "grasses" : ({"swamp","thick","blue","crab","saw"}),
   "ferns" : ({"large"}),
   "litter" : ({"leaf"}),
]) );
  SetListen( ([
   "default" : "The sound of insects and the whistle of a" 
   " cool wind is all that is audible.",
]) );
  SetSmell( ([
   "default" : "The smell of decay is so thick it could be cut with" 
   " a knife.",
]) );
  SetInventory( ([
   BOG_NPC "bogturtle" : 1,
   BOG_NPC "bogcrane" : 2,
]) );
  SetExits( ([
   "east" : BOG_ROOM "bog2",
]) );
}
