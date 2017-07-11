//
// Filename: sanctuary.c
// The Main Temple Sanctuary
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//
// Modified by Gaby to eliminate
// a bug allowing people to sneak
// and not cost no sp
// Gabriel@Haven 10/18/99


#include <lib.h>
#include <vendor_types.h>
#include "../haven.h"

inherit LIB_CHAPEL;

int Kylin(string);
 
static void create() {
   chapel::create();
   SetShort("the Sanctuary of Kylin");
   SetClimate("indoors");
   SetAmbientLight(45);
   SetExits( ([
      "west" : "entrance",
   ]) );
   AddExit("north", "kylin_hall", (: Kylin :));
   SetProperty("no bump",1);
   SetInventory( ([
      H_NPC + "ulan" : 1,
      H_NPC + "dalahalus" : 1,
   ]) );
   SetTown("Haven");
   SetReligion("Kylin", "Desert Kylin");
   SetClasses( ({ "cleric" }) );
   SetAllowSacrifice(1);
   SetSacrificeType(VT_ALL);
   SetDeities( ({  "Duuktsaryth" }) );
   SetLong("The main sanctuary of Kylin is a monument to power and faith. "
           "Rising from floor to ceiling are pillars of marble which have "
           "runes spiraled from top to bottom. Huge and ornate tapestries "
           "hang from the walls depicting the glory of the Greatest Immortal "
           "of Kailie. Supported from the ceiling is a massive tapestry "
           "emblazened with the symbol of Kylin, the Balance entwined with "
           "a red Dragon. To the west is the entrance to the church.");
   SetItems( ([
      ({ "sanctuary", "monument" }) :
         (: GetLong :),
      ({ "tapestry", "tapestries" }) :
         "The material for these tapestries is rich, and the designs "
         "are meant to show the power of the Kylin faith. The sheer "
         "size of many of these tapestries shows the expense to which "
         "the Church went to show its power.",
      ({ "rune", "runes" }) :
         "These runes are completely surrounding the pillars that rise "
         "from the floor.",
      ({ "pillar", "pillars" }) :
         "The pillars of marble rise from floor to ceiling, spiraling "
         "with rune encrusted glory to the sky.",
      ({ "symbol", "symbol of kylin" }) : 
         "The symbol of Kylin is a set of ancient scales, called a "
         "balance, surrounded and protected by a huge red dragon.",
      ({ "dragon" }) :
         "This huge, red dragon is protecting the ancient scales of "
         "Kylin.",
      ({ "entrance" }) :
         "To the west lies the entrance to the church",
   ]) );
   SetItemAdjectives( ([
      "sanctuary" : ({ "main" }), 
      "tapestry" : ({ "huge", "ornate", "massive" }),
      "pillar" : ({ "marble" }),
      "dragon" : ({ "huge", "red" }),
   ]) );
   SetSmell( ([
      "default" : "The smell of burnt incense rises into the air.",
   ]) );
   SetListen( ([
      "default" : "The faint echoes of chanted prayers can be heard.",
   ]) );
}

int Kylin(string dir) {
   if(this_player()->GetReligion() == "Kylin" ||
      this_player()->GetReligion() == "Desert Kylin" ||
      creatorp(this_player())) {
      return 1;
   }
   this_player()->AddStaminaPoints(-50);
   message("system", "A gust of wind blows you away from there.",
           this_player());
   return 0;
 }


/* Approved by Duuktsaryth on Sun Apr 25 18:43:14 1999. */
