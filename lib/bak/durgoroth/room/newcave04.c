// Title: Durgoroth Town
// File: cave04.c
// Author: Timothy Morris aka Morgoth@Haven
// Date: March 1998
//
// Abstract: Shrine of Saa'HaGoth in the cave of Durgoroth
//
// Revision History: 
//   Womble added 27th Jan 1999 by Ranquest
//

#include <lib.h>
inherit LIB_CHAPEL;
#include "../durgoroth.h"

int Womble();

static void create() {
        chapel::create();
    SetTown("Durgoroth");
        SetShort("shrine of Saa'HaGoth");
        SetLong("This large circular chamber seems to be carved "
                "straight out of the living rock of the mountain. "
                "The room is dominated by a massive edifice in the center "
                "of the room that seems to be a %^BOLD%^BLUE%^"
                "portal%^RESET%^ of some sort. "
                "In front of the portal is a large altar carved from the "
                "same stone. And on the wall behind the shimmering portal "
                "is a large tapestry of the goddess Arika.");
        SetObviousExits("south");
        SetClimate("indoors");
        SetDomain("FrostMarches");
        SetAmbientLight(35);
        SetReligion("Saahagoth","Saahagoth");
        SetClasses("cleric");
        SetItems( ([
                ({"large circular chamber","large chamber","circular chamber",
                "room","chamber","shrine","cave"}) : (: GetLong :),
                ({"living rock","rock","mountain","walls"}) : "The entire "
                        "chamber seems to have been carved straight out of the "
                        "living rock of the mountain. The walls are perfectly "
                        "smooth and the dark gray rock has been polished to a "
                        "shine.",
                ({"massive edifice","edifice","portal"}) : "The massive "
                        "edifice in the center of the room seems to be a portal "
                        "of some sort. In the center is a large oval of "
                        "glassy smooth, transparent, cold blue energy. The portal "
                        "itself is supported on both sides by massive sculptures "
                        "of various hidious demons. Through the center of the "
                        "portal the tapestry of Morgoth can be seen on the far "
                        "wall.",
                ({"massive sculptures","sculptured demons","demons"}) : "The "
                        "sculptures are extremely lifelike depictions of various "
                        "types of demons entiwined around the portal.",
                ({"large altar","altar"}) : "The large altar seems to "
                        "have been carved out of the stone of the mountain "
                        "when the chamber was made. It is a plain, smooth "
                        "rectangle of stone. Its surface slightly stained "
                        "with what appears to be blood.",
                ({"altar surface","surface","blood"}) : "The surface of the "
                        "altar seems to be stained with blood.",
                ({"large tapestry","tapestry"}) : "The large tapestry on the "
                        "wall of the chamber behind the portal depicts the ancient "
                        "and mighty goddess Arika standing amidst roaring flames atop "
                        "a mound of the skulls of his slain enemies, while in the "
                        "background hideous demons and underworld creatures cavort "
                        "amidst the ruins of a town.",
                ]) );
        SetExits( ([
                "south" : D_ROOM + "/cave03",
                ]) );
        AddEnter("portal", "/domains/grymxoria/room/church1d",(:Womble:));
        }

  int Womble() {
  object who = this_player();
  if (who->GetReligion("Saahagoth")) return 1;
  message("system",who->GetName() + " tries to go through the "
    "portal.",this_object() );
  message("system","A mystical force repels you.",who);
  return 0;
  }
