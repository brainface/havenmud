//Samah@Haven
//20040911
#include "../clearing.h"
#include <lib.h>
#include <std.h>

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a gap in the brambles");
  SetDayLong(
     "The brambles here are pushed aside to form a small "
     "gap, barely large enough to pass through.  The path "
     "continues on to the south, where an opening in the brambles "
     "reveals a small clearing.  To the west, the main road can be seen, "
     "barely visible through the dense maze of thorns."  
  );
  SetNightLong(
     "Moonlight shines down through the dense brambles that "
     "surround the area.  The light filters through the "
     "foliage, creating long shadows to stretch out across "
     "the small gap in the dense briar field. To the south, "
     "an open clearing is visible in the gloom."
  );
  SetItems( ([ 
     ({ "bramble", "brambles", "thorns", "thorn", "barrier","foliage" }):
     "The brambles surround the area, creating an impassable "
     "barrier.",
     ({ "gap" }):
     (: GetLong :),
     ({ "path", "trail" }):
     "The small grassy path continues on to the south through the "
     "brambles.",
     ({ "clearing" }):
     "The view of the clearing is obscured by brambles and thorns.",
     ({ "shadow","shadows" }):
     "The long shadows stretch eerily out across the area, as the "
     "light filters through the dense brambles.",
     ({ "opening" }):
     "The brambles seem to part slightly here, creating a natural "
     "opening into the clearing just to the south.",
     ({ "road" }):
     "The main road can be seen just barely through the "
     "maze of dense brambles that block passage to it."
  ]) );
  SetItemAdjectives( ([
     "bramble" : ({ "thorny","dense","maze" }),
     "gap" : ({ "small" }),
     "path" : ({ "grassy","small" }),
     "clearing" : ({ "small","open" }),
     "shadow" : ({ "long" }),
     "opening" : ({ "natural" }),
     "road" : ({ "main" })
  ]) );
  SetInventory( ([ 
     CLEAR_NPC "female_muezzin" : 1,
     CLEAR_NPC "male_muezzin" : 1,
  ]) );
  SetSmell( ([
     "default" : "The scent of crushed leaves fills the air",
  ]) );
  SetListen( ([
     "default" : "The sounds of small voices can be heard in "
     "the distance",
  ]) );
  SetExits( ([
     "west" : CLEAR_ROOM "trail",
     "south" : CLEAR_ROOM "clearing2",
  ]) );
}


/** Approved by Laoise at Sat Sep 11 20:23:20 2004. **/