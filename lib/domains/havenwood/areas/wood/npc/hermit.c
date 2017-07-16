/*  This is a hermit crab coded by Lynna on January 20, 1998
 * Set race to arachnid and commented out extra limbs - Laoise
*/
#include <lib.h>
#include "../beach.h"
#include <armour_types.h>
inherit LIB_NPC;

  static void create()  {
        npc::create();
        SetKeyName("crab");
        SetShort("a small, red hermit crab");
        SetId( ({"crab"}) );
        SetAdjectives( ({"red", "small", "hermit"}) );
        SetLong("This is a small, red hermit crab that spends"                
                " its time swimming through the water and "
                "exploring the sands of the beach.");
  SetRace("arachnid", "crab");
/*
        AddLimb("upper torso", 0, 1);
        AddLimb("lower torso", "upper torso", 1);
        AddLimb("right claw", "upper torso", 2);
        AddLimb("torso", 0, 1, ( { A_BODY_ARMOUR }) );
        AddLimb("left claw", "upper torso", 2);
        AddLimb("first leg", "lower torso", 2);
        AddLimb("second leg", "lower torso", 2);
        AddLimb("third leg", "lower torso", 2);
        AddLimb("fourth leg", "lower torso", 2);
        AddLimb("fifth leg", "lower torso", 2);
        AddLimb("sixth leg", "lower torso", 2);
*/

        SetCorpseItems( ([
            "/domains/havenwood/areas/wood/obj/shell.c" : 1,
          ]) );
        SetClass("animal");
        SetLevel(1);
        SetGender("male");
        SetAction(4,({
        "!emote crawls.", "!emote peeps out from his shell."}) );
        }
