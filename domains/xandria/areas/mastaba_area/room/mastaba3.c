//Selket@Haven
//2006
#include <lib.h>
#include "../mastaba.h"
inherit LIB_ROOM;
int BeenDone;
void DoSearch();

static void create() {
  room::create();
  SetClimate("underground");
  SetWarmth(10);
  SetAmbientLight(5);
  SetShort("within the coffin room");
  SetLong(
    "Although the walls and floor are richly painted, the only thing "
    "that stands here is a large wooden sarcophagus, inlaid with "
    "gemstones and precious metals. The coffin is disturbed, open "
    "to reveal contents that should have been closed off for eternity. "
    "There is nothing else here but the choking scent of death. The "
    "way out is through the hole in the shallow ceiling. "
    );
  SetSmell( ([
    "default" : "The scent of decay here is overwhelming.",
    ]) );
  SetListen( ([
    "default" : "Deep underground, there is no noise.",
    ]) );
  SetProperty("no teleport",1);
  SetItems( ([
    ({ "sarcophagus", "coffin" }) :
      "It is open, revealing emptiness except for a few dried rushes "
      "and moldering bits of corpse. ",
    ({ "gemstones", "gems", "stones", "metal", "metals" }) :
    "The stones and inlaid metals are priceless, truly a pharaoh's "
    "ransom.",
    "room" : " It is the coffin room of a very rich, very dead person's "
    "tomb. A huge coffin stands here in the center.",
    ({ "wall", "walls", "floor" }) :
      "These too, are painted with religious scenes and those from "
      "the life of a man one can only guess is the owner of this "
      "enormous tomb.",
    ]) );
  SetItemAdjectives( ([
    "coffin"    : ({ "disturbed", "open" }),
    "room" : ({ "coffin" }),
    ]) );
  SetExits( ([
    "up" : MASTABA_ROOM "mastaba2",
    ]) );
  SetInventory( ([
    MASTABA_NPC "mummy" : 1,
  ]) );
}

varargs void reset(int count) {
   room::reset();
  BeenDone = 0;
  }
  
void DoSearch() {
  if (BeenDone) {
      message("blah", "You don't find a thing.", this_player());
      return;
         }
    new(MASTABA_OBJ + "scroll1")->eventMove(this_player());
  BeenDone = 1;
  message("blah", "You find a scroll!", this_player());
   }
