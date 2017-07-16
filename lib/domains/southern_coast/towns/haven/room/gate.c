//
// Filename: gate.c
// The new and improved Haven Town Gate
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include "../haven.h"

inherit LIB_ROOM;

int AcceptableCheck();

static void create() {
   room::create();
   SetClimate("temperate");
   SetShort("Haven Town Gate");
  SetExits( ([
    "west" : H_ROOM "out_rd1",
    ]) );
/*
  AddExit("east", H_ROOM "imperial_road/ir1", (: AcceptableCheck :) );
*/
  AddExit("east", H_ROOM "imperial_road/ir1");
   SetLong("The Haven Town Gate has grown in recent times. Once "
           "the welcoming arms of a central and important city, it is now "
           "the forward defenses of a xenophobic city ruled by a paranoid "
           "Church. To the east, the road leads into the city. To the west, "
           "the road leads outward into safety. There is a guardhouse "
           "here which is runed with the Dragon and Scales symbol of "
           "Kylin.");
   SetItems( ([
      ({ "gate", "entrance" }) :
         (: GetLong :),
      ({ "city" }) :
         "With the gate in the way, the city cannot be seen.",
      ({ "guardhouse" }) :
         "The guardhouse is perfectly normal for a town gate, except that "
         "this one is covered with a gigantic rune marking it without "
         "doubt as a religious outpost.",
      ({ "symbol", "rune" }):
         "The symbol of Kylin is a Dragon wrapped around a set of Scales, "
         "representing the Balance of Law with the strength of religious "
         "force behind it.",
      ({ "church" }) :
         "The church cannot be seen due to the massive gate blocking the "
         "entrance to the city.",
      ({ "road" }) :
         "The road here leads east into city and west into the wilderness.",
      ({ "wilderness" }) :
         "The wilderness to the west seems to act as a place of safety.",
   ]) );
   SetItemAdjectives( ([
      "gate" : ({ "town", "city", "haven town", "haven", "massive" }),
      "city" : ({ "central", "important" }),
      "symbol" : ({ "dragon", "scales", "dragon and scales" }),
      "church" : ({ "paranoid" }),
   ]) );
   SetEnters( ([
      "guardhouse" : H_ROOM + "misc_buildings/guardhouse",
   ]) );
   SetInventory( ([
  H_NPC + "templar_guard" : 2,
   ]) );
}

int AcceptableCheck() {
   object who = this_player();
   object *templars = ({ });
   object templar;
  
  if (creatorp(who)) return 1;
  foreach(object ob in all_inventory(this_object())) {
    if (ob->id("templar")) { templars += ({ ob }); }
  }
  templars = filter(templars, (: living($1) :) );
  templars = filter(templars, (: !$1->GetParalyzed() :) );
  templars = filter(templars, (: !$1->GetSleeping() :) );
  if (!sizeof(templars)) return 1;
  templar = templars[0];
  
  if(who->GetRace() != "half-elf" && who->GetRace() != "elf") {
    if(who->GetTown() == "Haven" || who->GetInvis() || who->GetReligion() == "Kylin") return 1;
      send_messages( "try",
        "$agent_name $agent_verb to enter Haven Town.",
        this_player(), 0, this_object() );
      templar->eventForce("say You can't enter our town, " + capitalize(who->GetKeyName()) + ".");
      return 0;
   }
   return 1;
 }


/* Approved by Duuktsaryth on Thu Apr 22 21:44:16 1999. */
