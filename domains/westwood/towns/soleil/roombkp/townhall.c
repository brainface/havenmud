#include <lib.h>
inherit LIB_ROOM;
#include "../soleil.h"

static void create() {
   room::create();
   SetTown("Soleil");
   SetClimate("indoors");
   SetAmbientLight(45);
   SetShort("townhall, bank, and post office");
   
   SetDayLong("Towards the back of the townhall is a safe for the bank.  "
              "However, nearest the door are a few filing cabinets that "
              "are used to keep track of all the citizens of Soleil, and "
              "muezzins that have become traitors to their home town.  "
              "Another area in the townhall is towards the back, between "
              "the bank and the filing cabinets:  It is a learning area "
              "for those wishing to learn Oiseau, the language of Soleil.  "
              "Out is the only exit, other than heading up by the "
              "staircase so one can go to the post office.");
   SetNightLong("This room is normally a hive of activity, with muezzins "
                "studying Oiseau with Miserum or talking to the mayor or "
                "depositing more cuicui with Aegri.  However, at night, "
                "the speed of work slows down and less it going on.  "
                "Other than that, the room looks the same.  There is a "
                "spot at the back for the bank's safe, and some filing "
                "cabinets around the working space of the mayor.  Between "
                "the filing cabinets and the safe is an area where "
                "Miserum teaches.  Out is the only exit, unless one wants "
                "to go to the post office upstairs.  A staircase gives "
                "access to it.");
   SetItems( ([
                ({ "learning area","area" }) :
                   "The learning area is set up to be comfortable and "
                   "welcoming.  Oiseau is the language taught there, "
                   "by Miserum.",
                ({ "room" }) : (: GetLong :),
                ({ "soleil townhall","townhall","town hall","hall",
                   "filing cabinet","filing cabinets","cabinet",
                   "cabinets" }) :
                   "The mayor of Soleil usually stands around the filing "
                   "cabinets, so he has quick and easy access to all "
                   "information about various muezzins and the citizens "
                   "of Soleil.  If someone wants to become a citizen "
                   "of Soleil, they should take to him.  His name is "
                   "Fossis.",
                ({ "first bank of soleil","bank","safe" }) :
                   "The safe is securely locked from all tampering, "
                   "so trying would be pointless.  Only the banker, "
                   "Aegri Portare, can open it.  Ask her questions to "
                   "deal with the First Bank of Soleil.",
                ({ "post office area","area","spot","post office",
                   "office","staircase","stairs","stair" }) :
                   "The post office is upstairs, and a staircase leads "
                   "up to it from this room.",
           ]) );
   SetObviousExits("out, up");
   SetExits( ([
                "up"  : S_ROOM + "post_office",
                "out" : S_ROOM + "tree_a",
           ]) );
   SetInventory( ([
                    S_NPC + "mayor_fossis" : 1,
                    S_NPC + "banker_aegri" : 1,
                    S_NPC + "knight" : 1,
                    S_NPC + "sage_miserum" : 1,
                    S_OBJ + "town_board" : 1,
                    S_NPC + "bard" : 1,
               ]) );
}
