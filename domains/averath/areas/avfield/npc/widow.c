#include <lib.h>
#include "../avb.h"

inherit LIB_NPC;


static void create() {
   npc::create();
   SetProperty("widow",1);
   SetKeyName("widow");
   SetShort("a huge black widow");
   SetId( ({"spider"}) );
   SetAdjectives( ({ "huge","black" }) );
   SetMorality(-100);
   SetLong("The spider is huge, Its body is the size of an average person. "
           "Her legs are easily the height of a small tree. They are covered "
           "in a thick black fur green spots throughout them. She also has "
           "two small legs that she seems to use as arms in front of her. "
           "Her head is very large. It has eight eyes, two which are much "
           "larger then the others. They are all a light brown in color and "
           "very veiny. Her mouth has two large fangs that appear to be "
           "covered in some kind of substance.");
   SetRace("arachnid");
   SetGender("female");
   SetClass("animal");
   SetLevel(35);
   AddLimb("first right leg","first segment",5,({ }) );
   AddLimb("first left leg","first segment",5,({ }) );
   AddLimb("second right leg","first segment",5,({ }) );
   AddLimb("second left leg","first segment",5,({ }) );
   AddLimb("second segment","second segment",3,({ }) );
   AddLimb("third right leg","second segment",5,({ }) );
   AddLimb("third left leg","second segment",5,({ }) );
   AddLimb("fourth right leg", "second segment",5,({ }) );
   AddLimb("fourth left leg", "second segment",5,({ }) );
}
