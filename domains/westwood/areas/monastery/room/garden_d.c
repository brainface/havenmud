#include <lib.h>
inherit LIB_ROOM;
#include "../monastery.h"

static void create() {
   room::create();
   SetShort("in a garden");
   
   SetLong("The prominent feature of the garden in this area is an "
           "expansive lilac bush in the corner formed by the stone walls "
           "in the north and east.  The soft grass that grows everywhere, "
           "even under the lilac bush, is littered with little blooms "
           "that have fallen from the tree.  It is possible to go "
           "west and south from here.");
   SetItems( ([
                ({ "lilac bush","bush","corner","tree","lilacs",
                   "lilac" }) :
                   "The lilac bush is covered with pastel violet "
                   "blooms, gathered together in clusters on the "
                   "bush.  Many of the clusters have sent blooms to "
                   "the ground.  It looks like, beneath the bush, there "
                   "is enough space to slip through and hide.",
                ({ "pastel violet blooms","pastel violet bloom","blooms",
                   "pastel blooms","pastel bloom","violet bloom","bloom",
                   "violet blooms","little blooms","little bloom",
                   "clusters","cluster","lilacs","lilac" }) :
                   "The lilac tree has bloomed, and it is covered with "
                   "the clusters of the pastel violet blooms.  Almost "
                   "a hundred gather in each cluster, and at least fifty "
                   "of such clusters are on the lilac bush.  The ground "
                   "beneath is full of shaken lilacs.",
                ({ "soft grass","grass","ground" }) :
                   "The soft grass grows everywhere, beneath the bush "
                   "and over the ground, thickening the world with "
                   "life and hiding the dirt.  The grass itself is "
                   "covered with another layer:  Lilacs have fallen "
                   "from the lilac bush, decorating the grass.",
                ({ "stone walls","stone","stone wall","walls",
                   "wall" }) :
                   "The stone walls are to the north and east, extending "
                   "off to the south and west.  Where they meet and "
                   "form a corner, a lilac bush grows.",
           ]) );
   SetListen( ([
                 "default" : "A breeze shakes the lilac bush some, "
                    "causing the blooms to rustle in all softness and "
                    "silence, some falling.",
            ]) );
   SetSmell( ([
                "default" : "The delicate scent of lilacs fills the "
                   "air.",
           ]) );
   SetExits( ([
                "west"  : M_ROOM + "garden_c",
                "south" : M_ROOM + "garden_b",
           ]) );
   SetEnters( ([
                 "lilac bush" : M_ROOM + "lilac",
            ]) );
   SetInventory( ([
                    M_NPC + "gardener" : 2,
                    M_NPC + "monk_c" : 3,
                    M_NPC + "monk_h" : 2,
               ]) );
}