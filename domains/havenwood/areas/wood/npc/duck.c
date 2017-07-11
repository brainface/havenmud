/*  This is a basic duck object coded by Lynna on January 18, 1998
 */
#include <lib.h>
#include "../beach.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("duck");
  SetShort("a small, white duck");
  SetId( ({ "duck" }) );
  SetAdjectives( ({ "white", "small" }) );
  SetLong("This is a small, white duck that spends its time "
          "swimming in the water.");
 SetInventory( ([
	BEACH_OBJ + "feather" : 2,
	]) );
  SetRace("bird");
  SetClass("animal");
  SetLevel(2);
 
  SetGender("male");
  SetAction(5, ({ 
  "!emote quacks.", "!emote waddles." }) );
  }
