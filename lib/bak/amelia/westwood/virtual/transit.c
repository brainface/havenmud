#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

void eventAssault();
int chance1 = (10 + random(15));

static void create(int x, int y) 
{
  string w, e, ne, sw;
  ::create(x, y);
  switch(x) 
  {
    case 0:
      w = "/domains/frostmarches/virtual/frostmarchrd/0,18";
      e = "/domains/westwood/virtual/transit/" + (x + 1) + "," + (y);
      SetShort("a path leading though the mountains");
      SetLong("This appears to be a road that cuts through a pass "
        "in the mountains of the Frostmarches.  It is mostly used "
        "used to transport goods and as a means of a shortcut "
        "across Kailie.  The road here intercepts with the road "
        "leading to Durgoroth.");
      SetClimate("sub-arctic");
      SetSmell( ([
        "default" : "The scent of the mountains carries on the wind here."
      ]) );
      SetListen( ([
        "default" : "The wind howls through the pass here.",
      ]) );
      break;
    case 1..24:
      SetShort("a path leading though the mountains");
      SetLong("This appears to be a road that cuts through a pass "
        "in the mountains of the Frostmarches.  It is mostly used "
        "used to transport goods and as a means of a shortcut "
        "across Kailie.  It looks to be travelled very little "
        "and is nothing more than a small path cutting though "
        "a valley in the mountains.  The road here intercepts with "
        "the road leading to Durgoroth to the west and the "
        "WestWood to the east.");
      SetClimate("sub-arctic");
      e = "/domains/westwood/virtual/transit/" + (x + 1) + "," + (y);
      w = "/domains/westwood/virtual/transit/" + (x - 1) + "," + (y);
      SetSmell( ([
        "default" : "The scent of the mountains carries on the wind here."
      ]) );
      SetListen( ([
        "default" : "The wind howls through the pass here.",
      ]) );
      break;
    case 26..45:
      SetShort("a path leading though the mountains");
      SetLong("This appears to be a road that cuts through a pass "
        "in the mountains of the Frostmarches.  It is mostly used "
        "used to transport goods and as a means of a shortcut "
        "across Kailie.  It looks to be travelled very little "
        "and is nothing more than a small path cutting though "
        "a valley in the mountains.  The road here intercepts with "
        "the road leading to Durgoroth to the west and the "
        "WestWood to the east.");
      SetClimate("temperate");
      e = "/domains/westwood/virtual/transit/" + (x + 1) + "," + (y);
      w = "/domains/westwood/virtual/transit/" + (x - 1) + "," + (y);
      SetSmell( ([
        "default" : "The light scent of fenfir trees seems to waft about."
      ]) );
      SetListen( ([
        "default" : "The wind howls through the pass here.",
      ]) );
      break;
    case 46..90:
      SetShort("a path leading though the mountains");
      SetLong("This appears to be a road that cuts through a pass "
        "in the mountains of the Frostmarches.  It is mostly used "
        "used to transport goods and as a means of a shortcut "
        "across Kailie.  It looks to be travelled very little "
        "and is nothing more than a small path cutting though "
        "a valley in the mountains.  The road here intercepts with "
        "the road leading to Durgoroth to the west and the "
        "WestWood to the east.");
      SetClimate("temperate");
      e = "/domains/westwood/virtual/transit/" + (x + 1) + "," + (y);
      w = "/domains/westwood/virtual/transit/" + (x - 1) + "," + (y);
      SetSmell( ([
        "default" : "The light scent of fenfir trees seems to waft about."
      ]) );
      SetListen( ([
        "default" : "The wind howls through the pass here.",
      ]) );
      break;
    case 91:
      SetClimate("temperate");
      SetShort("a path leading down into a forest");
      SetLong("This appears to be a road that cuts through a pass "
        "in the mountains of the Frostmarches.  It is mostly used "
        "used to transport goods and as a means of a shortcut "
        "across Kailie.  It looks to be travelled very little "
        "and is nothing more than a small path cutting though "
        "a valley in the mountains.  The road here begins to "
        "descend down into a forest deep in a valley.");
       w = "/domains/westwood/virtual/transit/" + (x - 1) + "," + (y);
       ne = "/domains/westwood/virtual/transit/" + (x + 1) + "," + (y + 1);
      SetSmell( ([
        "default" : "The light scent of fenfir trees seems to waft about."
      ]) );
      SetListen( ([
        "default" : "The wind here whispers though the mountain pass.",
      ]) );
       break;
    case 92..96:
      SetClimate("temperate");
      SetShort("a path leading down into a forest");
      SetLong("This appears to be a road that cuts through a pass "
        "in the mountains of the Frostmarches.  It is mostly used "
        "used to transport goods and as a means of a shortcut "
        "across Kailie.  It looks to be travelled very little "
        "and is nothing more than a small path cutting though "
        "a valley in the mountains.  The road here begins to "
        "descend down into a forest deep in a valley.");
       ne = "/domains/westwood/virtual/transit/" + (x + 1) + "," + (y + 1);
       sw = "/domains/westwood/virtual/transit/" + (x - 1) + "," + (y - 1);
      SetSmell( ([
        "default" : "The light scent of fenfir trees seems to waft about."
      ]) );
      SetListen( ([
        "default" : "The wind here whispers though the mountain pass.",
      ]) );
       break;
     case 97:
       SetClimate("temperate");
       SetShort("a path leading down into a forest");
       SetLong("This appears to be a road that cuts through a pass "
         "in the mountains of the Frostmarches.  It is mostly used "
         "used to transport goods and as a means of a shortcut "
         "across Kailie.  It looks to be travelled very little "
         "and is nothing more than a small path cutting though "
         "a valley in the mountains.  The road here begins to "
         "descend down into a forest deep in a valley.");
       e = "/domains/westwood/virtual/westwood/0,29";
       sw = "/domains/westwood/virtual/transit/" + (x - 1) + "," + (y - 1);
      SetSmell( ([
        "default" : "The light scent of fenfir trees seems to waft about."
      ]) );
      SetListen( ([
        "default" : "The wind here whispers though the mountain pass.",
      ]) );
       break;
    }
  if (w) AddExit("west", w);
  if (e) AddExit("east", e);
  if (ne) AddExit("northeast", ne);
  if (sw) AddExit("southwest", sw);
  call_out( (: eventAssault :), chance1 );
}

void eventAssault() {
  int chance2 = (20 + random(30));
  int rand = random(3);

  if (rand == 0)
  {
    message("other_action","A small rock sails through the air, "
      "striking a tree and bouncing harmlessly to the ground.",
      this_object());
    call_out( (: eventAssault :), chance2);
    return;
  }
  else if (rand == 1)
  {
    message("other_action","A rock just barely misses your head.",
      this_object());
    call_out( (: eventAssault :), chance2);
    return;
  }
  else
  {
    message("other_action","The sounds of a madman howling off in "
      "depths of the woods can be heard.",this_object());
    call_out( (: eventAssault :), chance2);
    return;
  }    
}
