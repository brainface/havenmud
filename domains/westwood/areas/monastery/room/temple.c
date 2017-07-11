#include <lib.h>
inherit LIB_CHAPEL;
#include "../monastery.h"

static void create() {
   chapel::create();
   SetClimate("indoors");
   SetAmbientLight(50);
   SetShort("inside an Eclatish Temple");
   SetLong("Plain walls decorated with evergreen boughs form the "
           "sides of this Eclatish Temple.  An altar is against "
           "the wall to the north, but as the walls curve and make "
           "a circle, it is not really against it.  To the south "
           "are some simple, but beautiful doors that lead out.  Many "
           "candles fill the temple, providing light, but somehow "
           "it seems more lighted in here than those candles can "
           "provide.");
   SetItems( ([
                ({ "beautiful candles","beautiful candle","candles",
                   "candle" }) :
                   "Candles have been spread all over the temple, "
                   "filling the room with cheery little glows.",
                ({ "eclatish temple","eclat temple","temple","room",
                   "plain temple" }) :
                   (: GetLong :),
                ({ "plain walls","plain wall","walls","wall" }) :
                   "Branches from evergreen trees are rolled into "
                   "wreaths and then hung on the walls, which "
                   "are very sturdy and well-made with the purpose of "
                   "lasting.  The walls curve, making the room a "
                   "circle.",
                ({ "eclatish altar","eclat altar","altar" }) :
                   "The altar is plain for the most part, but some "
                   "candles are on top of it and it shines slightly.  "
                   "An embroidered cloth rests on top of the altar, "
                   "smoothed out carefully.",
                ({ "evergreen boughs","evergreen bough","wreath",
                   "wreaths","branches","branch","boughs","bough" }) :
                   "The evergreen boughs were made into wreaths and "
                   "hung on the walls, adding some decoration to the "
                   "otherwise plain temple.  They must have been brought "
                   "from another part of the West Wood, since only "
                   "deciduous trees grow here.",
                ({ "embroidered cloth","cloth" }) :
                   "A cloth has been smoothed out gently on top of the "
                   "altar.  It was delicately embroidered.",
           ]) );
   SetListen( ([
                 "default" : "Joyous noises echo through the temple.",
            ]) );
   SetSmell( ([
                "default" : "The room is full of the scents of "
                   "the evergreen boughs.",
           ]) );
   SetExits( ([
                "out" : M_ROOM + "plat_b",
           ]) );
   SetDoor("out",M_ROOM + "templedoors");
   SetReligion("Eclat","Eclatish");
   SetInventory( ([
                    M_NPC + "priest_p" : 1,
                    M_NPC + "monk_j" : 2,
                    M_NPC + "monk_h" : 1+random(2),
                    M_NPC + "monk_c" : 1,
                    M_NPC + "trav_wor" : 2,
               ]) );
   SetClasses( ({ "cleric" }) );
}
