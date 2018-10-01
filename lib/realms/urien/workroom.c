/* This is a basic workroom object that connects
 * your workroom to Haven, the home of the Immortals of Kailie.
 * Please make sure to read that board at least once per
 * day, as it is the prime means of communication.
 * Created by Duuktsaryth@Haven
 *  Minor editing by Laoise@Haven
 *   Made my workroom Urien@Haven
 *    Attached files are in ~urien/workroom/
 */

#define WORKROOM "/realms/urien/workroom/"

#include <lib.h>
#include <std.h>
#include <dirs.h>

inherit LIB_ROOM;

string SearchDesk();
int SearchComplete;       

static void create() {
  ::create();
  SetClimate("arctic");
  SetDomain("Planes");
  SetShort("inside a castle of ice");
  SetLong(
  "The entire castle is composed of frost, mist, and "
  "solid blue ice. Pillars disappear into the high "
  "ceiling and blue pyre-flies dance about. Light "
  "fluffy snow blankets the entire floor in its wake. "
  "A metal platform hovers over containing a throne, a "
  "desk, a clock and an ancient floating lantern. Large "
  "windows cascade over the walls letting in natural "
  "lighting inside this eerie and ancient foyer. A frozen "
  "door leads north and a black door directs south deeper "
  "into this structure."
  );
  SetExits( ([
    "north" : WORKROOM "moncreate",
    "south" : WORKROOM "arearoom",
    "east"  : DIR_STANDARD_DOMAIN "/staffroom",
  ]) );
  SetInventory( ([ 
              WORKROOM "clock"  : 1,
              WORKROOM "throne" : 1,
            ]) );
  SetItems( ([ 
    ({ "castle","inside","structure" }) : (: GetLong :),
     "walls" : "The walls are blue in color and have "
               "been created by solid ice. They are "
               "covered by a serious frost. The eastern "
               "wall looks different than the rest.",
     "eastern wall" : "The eastern wall ripples slightly "
                      "but maintains its frozen durability.",
     "wall" : "The wall is made of solid ice. Due to its "
              "thickness and the additions of water, it "
              "contains a light blue sensation.",
    ({ "frost" }) : "The frost itself rests on numerous "
      "things inside this castle. It has adhered itself "
      "to the pillars, throne, walls and the platform "
      "that hovers above the floor.",
    ({ "mist" }) : "Numerous beads of mist fall from the "
      "ceiling in tandem with the snow. It lands on anything "
      "horizontal.",
    ({ "ice" }) : "Instead of stone like traditional "
      "fortresses, this castle has been created out "
      "of pure ice. It has manifested a relaxing shade "
      "of blue throughout this realm.",
    ({ "pillars" }) : "Four identical cylindrical pillars "
      "reach up high into this castle covered in frost. "
      "They are massive in size and contain an etched spiral "
      "along its surface that ascends upward.",
    ({ "pyre flies", "pyreflies", "flies" }) : "Bright blue "
      "pyre flies dance about the castle with disdain to "
      "pattern or style. Their bodies appear to be round "
      "in shape with a misty wake that disappears behind "
      "them. They also seem to be made of pure fire.",
    ({ "ground", "floor", "snow" }) : "The floor is blanketed "
      "in a soft fluffy snow. It is relatively deep, almost "
      "knee high to any normal adult human. It appears to "
      "be undisturbed with more snow from the ceiling falling "
      "on it.",
    ({ "platform" }) : "This platform hovers above the ground "
      "roughly two feet from the surface of the snow. It has "
      "been made of metal and has intricate designs which show "
      "signs of craftsmanship. It is very large in size, about "
      "an entire foot thick and provides ample room to hold "
      "a desk, a chair and a frozen throne. It seems to be "
      "solid material; not hollow or cheap.",
     "desk" : "This desk is made of solid ice. On its "
      "surface rests a clock and an icicle with frozen "
      "ink inside. Above the surface of the desk is a glowing "
      "floating lantern. The craftsmanship looks as though "
      "it was chipped from a solid block of ice.",
    ({ "lantern" }) : "This ancient lanterns design matches "
      "the platform. It is square in shape with a metal roof "
      "and base. Four pieces of glass protect the orb on the "
      "inside which glows in darkness. ",
    ({ "windows" }) : "The windows are triangular in shape "
      "and allow light to enter from the outside world. The "
      "windows line the north and south walls evenly. They "
      "are out of reach and serve only practical function than "
      "use.",
    ({ "window" }) : "The window is triangular in shape and "
      "serves only to let the outside light in.",
    ({ "light" }) : "The light from the windows outside is "
      "blinding from the reflection off the snow. The ancient "
      "lantern glows in pure darkness. ",
    ({ "ceiling" }) : "The ceiling to this castle reaches "
      "high upward to blackness. It is difficult to make "
      "what the blue pillars are supporting.",
    ]) );
  SetItemAdjectives( ([
    "ice" : ({ "blue" }),
    "pillars" : ({ "ice" }),
    "ceiling" : ({ "high" }),
    "flies" : ({ "pyre","blue" }),
    "snow" : ({ "fluffy","white" }),
    "platform" : ({ "thick","ancient","metal" }),
    "mist" : ({ "beads" }),
  ]) );
  SetSmell( ([
     "default" : "The fresh smell of falling snow "
                 "is about.",
  ]) );
  SetListen( ([
     "default" : "Snow hitting the floor chimes " 
                 "softly.",
           ]) );
  SetSearch("desk", (: SearchDesk :) );
  SearchComplete = 0;  
  SetDoor( "north", WORKROOM "door1");
  SetDoor( "south", WORKROOM "door2");
  SetTouch( ([
     "default" : "It is freezing, the cold crisps breathing.",
     ]) );
}

string SearchDesk(object who) {
   object item = new(WORKROOM + "bong");
   send_messages("search", "$agent_name $agent_verb around "+
   "the frozen desk.", who, 0, this_object());
   if (SearchComplete) {
    return "The desk reveals nothing but doodles of a Goblin city.";
   }
   if (!item->eventMove(who)) item->eventMove(this_object());
   SearchComplete = 1;
   return "You discover a hidden bong in Urien's Desk!";
}