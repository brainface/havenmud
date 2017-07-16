//The stream, outside of the Ranger Guildhall
//Davantalus 20040721

#include <lib.h>
#include "../ranger_hall.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("temperate");
  SetShort("the bank of a stream within dense forest");
  SetDayLong(
      "A small stream runs southward, out from several crevices "
      "in a mound of boulders into the deep forest. The lively, "
      "light blue water reflects the green foliage above like a "
      "turquoise watercolor. Small, moss covered boulders litter "
      "the streambed and forest floor. The dense surrounding forest "
      "of branch, vine, and bush is much too thick to continue in "
      "any direction but north towards the clearing."
  );
  SetNightLong(
      "A small dark stream runs southward, out from small crevices "
      "in a mound of boulders into the deep forest. The lively water "
      "reflects a few stars visible to the north. Small, dark "
      "boulders litter the streambed and forest floor like dark "
      "creatures lying in wait. The dark surrounding forest is "
      "much too thick to continue in any direction but north towards "
      "the clearing."
  );
  SetItems( ([ 
      ({ "clearing"})        : "A small clearing is visible to the north.",
      ({ "foliage" })        : "The foliage above is thick, obscuring the sky.",
      ({"forest" , "woods", "glen"}) : "The surrounding forest is comprised "
                               "of plants and trees of all varieties.",
      ({"boulder","boulders"}):"The boulders are medium sized, and equally "
                               "dispersed. They are green, grey, and slightly "
                               "yellow from moss and lichen.",
      ({"tree", "trees"})    : "The trees have almost sentient qualities.",
      ({"moon", "stars"})    : "The moon and stars are visible "
                               "in the clearing to the north.",
      ({"branches", "vine", "bush"}) : "The foliage, thick to the south, thins "
                               "out to the north. It moves a lively way.",
      ({"stream", "water"})  : "The stream emerges from under the ground here. "
                               "It emerges at the boulders and runs southward.",
      ({"stream-bed"})       : "The stream-bed is home to medium sized boulders "
                               "which are circled by the stream as it continues "
                               "southward into the forest.",
      ({"moss", "lichen"})   : "The lichen lives in a symbiotic relationship "
                               "of fungus and plant. This lichen is very old "
                               "because of its size. The moss glistens wetly.",
      ({"creatures"})        : "The rocks look like squat dark-green creatures.",
      ({"crevices"})         : "The small holes in the rock emit water from "
                               "some underground aquifer."  ]) );
SetItemAdjectives( ([ 
      "stream"   : ({"small", "dark"}),
      "boulders" : ({"mound", "of", "moss", "covered"}),
      "forest"   : ({"deep", "dense", "surrounding"}),
      "water"    : ({"lively", "light", "blue"}),
      "foliage"  : ({"green"}),
      "crevices" : ({"several"}),
  ]) );
  SetListen( ([ 
      "default" : "The stream babbles as it leaves the crevices, "
                  "but quickly quiets."
  ]) );
  SetSmell( ([ 
      "default" : "There is a thick smell of forest and wet soil."
  ]) );
  SetInventory( ([ 
      RH_OBJ + "waterlily_blue" : 1+random(2)
  ]) );
  SetExits( ([
      "north" : RH_ROOM + "entrance", 
  ]) );
}