/* Horseyard.c for Black Horse Inn
   20MAY2013
   Atrus@Haven
*/

#include "../bhi.h"
#include <lib.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("outside the Black Horse Inn");
  SetClimate("temperate");
  SetExits( ([
    "west" : "/realms/atrus/workroom.c",
    ]) );
  SetDayLong(
         "The horseyard of the Black Horse Inn is well kept. Large gardens line "
         "both sides of the yard. New dried pine wood chips make a soft surface "
         "for horses' travel beaten hooves. Fresh oats are in feed bags hung off "
         "tall cinch poles. A small bucket in near each pole for the horses to drink. "
         "Large iron lanterns, blued from over heating, hang from each "
         "pillar on the front of the inn. A long porch lines the front "
         "of the building. The inn itself is whitewashed log construction with "
         "black trim. The second floor windows and black shutters are "
         "open allowing the drapes inside to flow in the breeze. A large "
         "awning stretches out into the yard in case of rain."
         );
  SetNightLong(
         "The horseyard of the Black Horse Inn is well kept. Clear of obstructions "
         "to even horse cince poles. New dried pine wood chips make a soft surface "
         "for horses' travel beaten hooves. Fresh oats are hung in feed bags off "
         "the cinch poles and a water bucket is near each pole. The horse area is "
         "well lit with a soft orange glow from large lanterns which also light "
         "up the porch that stretches along the front of the inn. The second "
         "windows are closed and shuttered against any weather. Slim lines of "
         "light shine through the closed windows. "
         );
  SetItems( ([
  "inn" : "The large white, black trimmed inn stands stark against the green "
          "backdrop of the woods around it. Windows line the second floor while "
          "a few small windows adorn the first. Above the second floor is a "
          "highly pitched roof that reaches nearly another two stories above the "
          "second floor.",
  ({ "garden", "gardens" }) : "Beautiful gardens line both side of the yard "
          "acting as a wide barrier to the woods around the property. A great "
          "number of flowers and herbs overflow from the garden beds. Tulips, "
          "roses, orchids of every color explode from the center while "
          "the borders along the front are backed with peppers and spices, "
          "and herbs of almost every kind. Obviously impecable cared for, "
          "the yield must be what sustains the eatery inside the inn.",
  ({ "yard", "horseyard", "" }) : (: GetLong :),
  ({ "lanterns", "lantern" }) : "Five large lanterns are placed in rings on the "
          "pillars that support the large overhang on the front of the inn. "
          "The wrought iron casings that keep the glass in place around the small "
          "fire contained have been blued with age and heat. The top of the glass "
          "on each side has been soot stained black and a gutteral smoke flickers "
          "from the vents on the top. A small sconce of naptha burns within like "
          "an eternal flame.",
  ({ "poles", "pole", "bags", "bag" }) : "A number of horse cinch poles have been "
          "evenly placed along the front of the inn. Large bags, hung on nails from the "
          "poles, hold oats for the numerous mounts which may be parked here waiting for "
          "their owners.",
  ({ "chip", "chips", "woodchips", "woodchip", "ground"}) : 
          "Having been shredded and crushed the bright tan woodchips laying "
          "about make a wonderful surface for the horses' "
          "hooves. As you walk on the surace you can feel why. There is a soft bounce "
          "to your step. And it seems to clean your feet as you walk.",
  ({ "pillar", "pillars" }) : "Large black pillars, freshly painted, hold up a vast "
          "overhang from the front of the inn. They are thick, seemingly turned on some "
          "vast lathe. Large lanterns are hanging rings placed in each about head high "
          "to a human. They tower over any horse in the yard holding the roof above "
          "the second floor allowing the entry way of the inn to be well shielded in "
          "all but the strongest of winds.",
  ({ "overhang", "porch" }) : "An enormous overhang has been built over "
          "an equally large porch housed underneath. The structure was clearly built "
          "by a master carpenter. The beams have been hewn from large logs and "
          "would support vast weight, as if the inn had been built with deep snow "
          "in mind. The porch has been sanded and lightly stained offering a warm "
          "welcome sight to many weary traveller. The entryway for the inn is just "
          "off center and is heavily framed itself, the double-doors very thick",
  ({ "entryway", "door", "doors" }) : "A tall set of thick oaken doors hang from "
          "wrought iron barrel pin hinges. This nails secure them in place and "
          "look for all the world they would hold back a troll, which they could "
          "easily accommodate for entry. It stands open and ready for visitors.",
  ({ "awning", "overhang" }) : "A large white awning hangs from the front of the "
          "building, overhanging where the horses would stand while cinched to "
          "their poles. The awning is made of thick cotton fabric and appears to "
          "be able to stand up to any weather.",
  ({ "drapes", "windows", "window", "shutters" }) : "The second floor windows are "
          "protected by stout shutters which can be closed to protect the glass. "
          "The shutters are painted black like much of the trim around the "
          "building. They have been made of thick cuts of wood and slats tightly "
          "collected in neat stacks which allow them to be adjusted for light.",
    ]) );
  SetItemAdjectives( ([
    "bag" : ({ "feed", "oat" }),
    "pole" : ({ "cinch", "horse", "tie" }),
    "inn" : ({ "large", "white", "black" }),
    "woodchip" : ({ "soft", "tan", "shredded", "pine", "crushed" }),
    "awning" : ({ "large", "white", "cotton" }),
    "door" : ({ "heavy", "thick", "oaken", "double" }),
    ]) );
  SetInventory( ([
  ]) );
  SetEnters( ([
    "inn" : BHI_ROOM "entryway",
  ]) );
}
