#include <lib.h>
#include <vendor_types.h>
inherit LIB_CHAPEL;
#include "../soleil.h"

int PreExit();
int PreEnter();

static void create() 
{
  chapel::create();
  SetDomain("WestWood");
  SetTown("Soleil");
  SetClimate("indoors");
  SetAmbientLight(33);
  SetShort("Eclatish Temple");
  SetLong("Plain boards form the paneling of the Eclatish Temple, but "
    "all are adorned with fresh branches from the spruce and "
    "hemlock trees.  Moss has been carefully harvested to be "
    "clean, and is then lain along the corners of the Temple.  "
    "An altar is up against the east wall, and candles burn "
    "upon it.  In the northeast is a staircase leading up, but "
    "it seems to be protected somehow to keep intruders out.  "
    "The only other exit is out into Soleil.",);
  SetItems( ([
    ({ "upward staircase","stairs","stair","staircase" }) :
      "The staircase leads up to the room of faith "
      "for all belonging to the Eclat religion.",
    ({ "eclatish altar","altar","burning candles","candles",
      "burning candle","candle" }) :
      "The candles flicker on the Eclatish altar, where "
      "praises to the Goddess of Joy, Amelia, are "
      "offered.",
    ({ "eclatish temple","temple" }) : (: GetLong :),
    ({ "plain boards","plain board","board","boards",
      "paneling","fresh branches","walls","wall",
      "fresh branch","braches","branch","spruce",
      "hemlock","moss","corners","corner" }) :
      "The various adornments from the forest all seem "
      "to be immune from the dropping and dying that is "
      "normally associated with plucking parts of a plant "
      "off.",
    ]) );
  SetExits( ([
    "out" : S_ROOM + "tree_c",
  ]) );
  AddExit("up",S_ROOM + "cl_hall",(:PreExit:));
  SetInventory( ([
      S_NPC + "priest_kiee" : 1,
      S_NPC + "druid_acclima" : 1,
      S_NPC + "knight" : 1,
      S_NPC + "chorist" : 1,
  ]) );
  SetProperty("no bump",1);
  SetReligion("Eclat","Eclat");
  SetClasses( ({ "cleric" }) );
}

int PreExit() 
{
  if(this_player()->GetReligion()!="Eclat") 
  {
    if(creatorp(this_player())) return 1;
    this_player()->AddStaminaPoints(-50);
    message("other_action","A ward suddenly pushes you back as "
      "you try to go up the staircase.",this_player());
     return 0;
  }
  message("other_action","%^BLUE%^Welcome.%^RESET%^",this_player());
  return 1;
}

int PreEnter() {
 object npc;
 if(present("guard")) {
  if(this_player()->GetMorality() < -350) {
    message("system","The guards block your exit.",this_player());
    if(this_player()->GetLevel() > 20) {
      foreach(npc in environment()) {
        if(npc->GetTown() == "Soleil") { 
      	npc->eventForce("attack " + this_player()->GetKeyName());
        }
      }
    }
    return 0;
  }
 }
 return 1;
}