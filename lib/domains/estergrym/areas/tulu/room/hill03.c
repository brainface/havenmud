/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include "../tulu.h"
inherit LIB_ROOM;

int PreExit();

static void create() {
  ::create();
  SetShort("in the center of a Stone Henge");
  SetLong(
    "Within the center of the perfect circle sits a massive stone altar. "
    "From here it is obvious that the altar has a discoloration of blood and gore. "
    "All around the altar the massive stone "
    "monuments rise to the sky like an evil omen, blackened soil giving "
    "the appearance of winter and death."
    );
  SetItems( ([
    "altar" : "The altar sits in the center of the henge.",
    ({ "stone", "stones", "henge", "circle" }) : "The stones surround the altar, forming a perfect circle.",
    "stairway" : "The stairway leads deep into the depths of the hill.",
    ({ "stone", "stones", "monument", "monuments" }) : "The stones form a perfect circle around the altar.",
    ]) );
  SetExits( ([
    "west"  : TULU_ROOM "hill02",
    "east"  : TULU_ROOM "hill04",
    "north" : TULU_ROOM "hill06",
    "south" : TULU_ROOM "hill01",  
    ]) );
  AddEnter("altar", TULU_ROOM "under01", (: PreExit :) );
  SetSmell("The smell of death and decay seems centered on the altar.");
  SetInventory( ([
    TULU_NPC "cultist_fighter" : 3,
    TULU_NPC "cultist_priest"  : 3,
    ]) );
}

int PreExit(string dir) {
  send_messages("are", "$agent_name $agent_verb repelled by the stench of the altar.", this_player(), 0, this_object() );
  return 1;
}
