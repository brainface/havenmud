#include <lib.h>
#include "../copse.h"
inherit LIB_ROOM;

string DirtSearch();
int BeenSearch;

static void create() {
  room::create();
  SetShort("a thick concentration of cherry blossoms");
  SetLong("The thickness of the tress here makes it"
          " difficult for one to see very far. The"
          " ground is covered by a blanket of cherry"
          " blossom petals and broken branches. There"
          " is a small clearing on the ground where"
          " fresh dirt appears to have been hastily"
          " covered up. It is hard to tell through all"
          " the trees, but the west appears to be"
          " very similar to here.");
  SetItems( ([
      ({ "blossom", "cherry blossom", "tree", "trees" }) :
      "These trees are responsible for the myriad of flower"
      " petals found upon the path and surrounding area.",
      ({ "petal", "petals" }) :
      "These petals are of a light pink hue. Because there"
      " are so many petals, it is hard to see the ground"
      " beneath them.",
      ({ "path", "ground" }) :
      "The path seemingly winds between the cherry blossoms"
      " but it is hard to tell because of the large number"
      " of petals on the ground.",
      ({ "branch", "branches" }) :
      "The broken branches littering the ground look"
      " as though they were forcibly removed from the trees"
      " rather than falling off due to decay.",
      ({ "dirt", "clearing" }) :
      "This small dirt pile looks as though it had"
      " been recently exhumed and then hastily covered"
      " again."
    ]) );
  SetItemAdjectives( ([
      "petals" : ({ "pink", "blossom", "cherry blossom" }),
      "tree" : ({ "blossom", "cherry blossom" }),
      "branch" : ({ "broken" }),
    ]) );
  SetListen( ([
      "default" : "Light rustling noises sooth the copse.",
    ]) );
  SetSmell( ([
      "default" :"The sweet aroma of cherry blossoms in bloom lingers here.",
    ]) );
  SetInventory( ([
    COPSE_NPC + "caterpillar" : 1,
    COPSE_NPC + "butterfly" : 3,
    ]) );
  SetExits( ([
      "west" : COPSE_ROOM "room6",
    ]) );
/*  SetSearch( ([
      "dirt" : (: DirtSearch :),
    ]) );
*/
}
/*
varargs void reset(int count) {
   room::reset();
  BeenSearch = 0;
  }
void DirtSearch() {
  if (BeenSearch) {
      message("action", "You find a bunch of dirt.", this_player());
      return;
         }
    new(COPSE_OBJ + "bag")->eventMove(this_player());
  BeenSearch = 1;
  message("action", "You find a leather bag!", this_player());
   }
*/
